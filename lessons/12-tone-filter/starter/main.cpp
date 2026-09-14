#include <cmath>
#include <iostream>

class LowPass {
public:
    void SetCutoff(float cutoff, float sampleRate) {
        // TODO: alpha_を計算
    }

    float Process(float input) {
        // TODO: state_を更新
        return input;
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
