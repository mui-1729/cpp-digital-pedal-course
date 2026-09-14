#pragma once

#include <algorithm>
#include <cmath>

class Distortion {
public:
    void SetDrive(float drive) { drive_ = std::max(1.0f, drive); }
    float Process(float input) const { return std::tanh(input * drive_); }
private:
    float drive_ = 1.0f;
};

class LowPass {
public:
    void Init(float sampleRate) { sampleRate_ = sampleRate; SetCutoff(5000.0f); }
    void SetCutoff(float cutoff) {
        constexpr float kPi = 3.14159265358979323846f;
        cutoff = std::clamp(cutoff, 20.0f, sampleRate_ * 0.45f);
        alpha_ = 1.0f - std::exp(-2.0f * kPi * cutoff / sampleRate_);
    }
    float Process(float input) {
        state_ += alpha_ * (input - state_);
        return state_;
    }
private:
    float sampleRate_ = 48000.0f;
    float alpha_ = 1.0f;
    float state_ = 0.0f;
};

class PedalEngine {
public:
    void Init(float sampleRate) { tone_.Init(sampleRate); }
    void SetDrive(float drive) { /* TODO */ }
    void SetTone(float normalized) { /* TODO */ }
    void SetLevel(float level) { /* TODO */ }
    float Process(float input) {
        // TODO: Distortion -> Tone -> Level
        return input;
    }
private:
    Distortion distortion_;
    LowPass tone_;
    float level_ = 0.8f;
};
