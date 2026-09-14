#pragma once

#include <algorithm>
#include <cmath>

namespace pedal {

class Distortion {
public:
    void SetDrive(float drive) {
        drive_ = std::clamp(drive, 1.0f, 12.0f);
    }

    // 0.0 = harder clipping character, 1.0 = softer clipping character.
    // This is an educational "SAT" control, not a clone of any specific pedal.
    void SetSaturation(float saturation) {
        saturation_ = std::clamp(saturation, 0.0f, 1.0f);
    }

    float Process(float input) const {
        const float x = input * drive_;
        const float hard = std::clamp(x, -1.0f, 1.0f);
        const float soft = std::tanh(x);
        return hard + (soft - hard) * saturation_;
    }

private:
    float drive_ = 4.0f;
    float saturation_ = 0.6f;
};

class OnePoleTone {
public:
    void Prepare(float sampleRate) {
        sampleRate_ = std::max(sampleRate, 1.0f);
        SetTone(tone_);
        Reset();
    }

    void Reset() {
        state_ = 0.0f;
    }

    void SetTone(float normalized) {
        tone_ = std::clamp(normalized, 0.0f, 1.0f);

        // 500 Hz -> 8000 Hz on a logarithmic curve.
        const float cutoff = 500.0f * std::pow(16.0f, tone_);
        const float safeCutoff = std::min(cutoff, sampleRate_ * 0.45f);
        constexpr float kPi = 3.14159265358979323846f;
        alpha_ = 1.0f - std::exp(-2.0f * kPi * safeCutoff / sampleRate_);
    }

    float Process(float input) {
        state_ += alpha_ * (input - state_);
        return state_;
    }

private:
    float sampleRate_ = 48000.0f;
    float tone_ = 0.6f;
    float alpha_ = 1.0f;
    float state_ = 0.0f;
};

class PedalEngine {
public:
    void Prepare(float sampleRate) {
        tone_.Prepare(sampleRate);
    }

    void Reset() {
        tone_.Reset();
    }

    void SetDrive(float drive) {
        distortion_.SetDrive(drive);
    }

    void SetSaturation(float saturation) {
        distortion_.SetSaturation(saturation);
    }

    void SetTone(float normalized) {
        tone_.SetTone(normalized);
    }

    void SetLevel(float level) {
        level_ = std::clamp(level, 0.0f, 1.0f);
    }

    float Process(float input) {
        float x = distortion_.Process(input);
        x = tone_.Process(x);
        return x * level_;
    }

private:
    Distortion distortion_;
    OnePoleTone tone_;
    float level_ = 0.7f;
};

} // namespace pedal
