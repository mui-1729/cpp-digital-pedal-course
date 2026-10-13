#include "Distortion.h"
#include <algorithm>
#include <cmath>

// TODO: member functions を実装する
void Distortion::SetDrive(float drive)
{
    drive_ = drive;
}

void Distortion::SetMode(ClipMode mode)
{
    mode_ = mode;
}

float Distortion::Process(float input) const
{
    const float driven = input * drive_;

    if (mode_ == ClipMode::Hard)
    {
        return std::clamp(driven, -1.0f, 1.0f);
    }

    return std::tanh(driven);
}