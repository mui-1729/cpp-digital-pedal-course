#include <cstddef>
#include <iostream>
#include <vector>

class Delay {
public:
    Delay(float sampleRate, float delaySeconds)
        : buffer_(static_cast<std::size_t>(sampleRate * delaySeconds), 0.0f) {}

    float Process(float input, float feedback) {
        // TODO
        return input;
    }

private:
    std::vector<float> buffer_;
    std::size_t writeIndex_ = 0;
};

int main() {
    Delay delay(10.0f, 0.3f); // 教材用: 10Hz sample rate, 3 samples delay
    for (int i = 0; i < 12; ++i) {
        const float input = (i == 0) ? 1.0f : 0.0f;
        std::cout << delay.Process(input, 0.5f) << '\n';
    }
}
