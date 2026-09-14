#include <algorithm>
#include <cmath>
#include <iostream>

enum class ClipMode { Hard, Soft };

class Distortion {
public:
    void SetDrive(float drive) { drive_ = drive; }
    void SetMode(ClipMode mode) { mode_ = mode; }

    float Process(float input) {
        const float driven = input * drive_;
        if (mode_ == ClipMode::Hard) {
            return std::clamp(driven, -1.0f, 1.0f);
        }
        return std::tanh(driven);
    }

private:
    float drive_ = 1.0f;
    ClipMode mode_ = ClipMode::Hard;
};

int main() {
    Distortion distortion;
    distortion.SetDrive(5.0f);
    distortion.SetMode(ClipMode::Soft);
    std::cout << distortion.Process(0.4f) << '\n';
}
