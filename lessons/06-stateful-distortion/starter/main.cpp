#include <algorithm>
#include <iostream>

class Distortion {
public:
    void SetDrive(float drive) {
        // TODO
    }

    float Process(float input) {
        // TODO
        return input;
    }

private:
    float drive_ = 1.0f;
};

int main() {
    Distortion distortion;
    distortion.SetDrive(5.0f);
    std::cout << distortion.Process(0.4f) << '\n';
}
