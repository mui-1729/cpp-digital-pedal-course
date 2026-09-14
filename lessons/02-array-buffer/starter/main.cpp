#include <cstddef>
#include <iostream>

float ApplyGain(float input, float gain) {
    return input * gain;
}

int main() {
    constexpr std::size_t kSize = 8;
    float buffer[kSize] = {0.1f, 0.2f, 0.4f, -0.3f, -0.5f, 0.7f, -0.8f, 0.0f};
    float gain = 2.0f;

    // TODO: forでbufferの全要素にApplyGainを適用する

    for (std::size_t i = 0; i < kSize; ++i) {
        std::cout << buffer[i] << '\n';
    }
}
