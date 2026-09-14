#include <algorithm>
#include <iostream>

class Distortion {
public:
    void SetDrive(float drive) {
        drive_ = drive;
    }

    float Process(float input) {
        const float driven = input * drive_;
        return std::clamp(driven, -1.0f, 1.0f);
    }

private:
    float drive_ = 1.0f;
};

int main() {
    Distortion distortion;
    distortion.SetDrive(5.0f);
    std::cout << distortion.Process(0.4f) << '\n';
}
