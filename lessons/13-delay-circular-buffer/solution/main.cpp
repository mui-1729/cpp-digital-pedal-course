#include <cstddef>
#include <iostream>
#include <vector>

class Delay {
public:
    Delay(float sampleRate, float delaySeconds)
        : buffer_(static_cast<std::size_t>(sampleRate * delaySeconds), 0.0f) {}

    float Process(float input, float feedback) {
        if (buffer_.empty()) {
            return input;
        }

        const float delayed = buffer_[writeIndex_];
        buffer_[writeIndex_] = input + delayed * feedback;
        writeIndex_ = (writeIndex_ + 1) % buffer_.size();
        return delayed;
    }

private:
    std::vector<float> buffer_;
    std::size_t writeIndex_ = 0;
};

int main() {
    Delay delay(10.0f, 0.3f);
    for (int i = 0; i < 12; ++i) {
        const float input = (i == 0) ? 1.0f : 0.0f;
        std::cout << delay.Process(input, 0.5f) << '\n';
    }
}
