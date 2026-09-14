#include <algorithm>
#include <cmath>
#include <iostream>

// TODO: enum class ClipMode

class Distortion {
public:
    void SetDrive(float drive) { drive_ = drive; }
    // TODO: SetMode

    float Process(float input) {
        const float driven = input * drive_;
        // TODO: modeでHard/Softを切り替える
        return driven;
    }

private:
    float drive_ = 1.0f;
    // TODO: mode_
};

int main() {
    Distortion distortion;
    distortion.SetDrive(5.0f);
    std::cout << distortion.Process(0.4f) << '\n';
}
