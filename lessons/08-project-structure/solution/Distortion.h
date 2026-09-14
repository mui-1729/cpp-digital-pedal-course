#pragma once

enum class ClipMode { Hard, Soft };

class Distortion {
public:
    void SetDrive(float drive);
    void SetMode(ClipMode mode);
    float Process(float input) const;

private:
    float drive_ = 1.0f;
    ClipMode mode_ = ClipMode::Hard;
};
