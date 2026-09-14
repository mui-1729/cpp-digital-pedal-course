#include <cmath>
#include <iostream>

class LowPass {
public:
    void SetCutoff(float cutoff, float sampleRate) {
        constexpr float kPi = 3.14159265358979323846f;
        alpha_ = 1.0f - std::exp(-2.0f * kPi * cutoff / sampleRate);
    }

    float Process(float input) {
        state_ += alpha_ * (input - state_);
        return state_;
    }

private:
    float alpha_ = 1.0f;
    float state_ = 0.0f;
};

int main() {
    LowPass filter;
    filter.SetCutoff(500.0f, 48000.0f);

    for (int i = 0; i < 20; ++i) {
        const float input = (i < 5) ? 0.0f : 1.0f;
        std::cout << filter.Process(input) << '\n';
    }
}
