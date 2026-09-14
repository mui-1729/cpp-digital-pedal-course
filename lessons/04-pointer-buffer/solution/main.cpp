#include <cstddef>
#include <iostream>

void ProcessBuffer(float* buffer, std::size_t size, float gain) {
    for (std::size_t i = 0; i < size; ++i) {
        buffer[i] *= gain;
    }
}

int main() {
    constexpr std::size_t kSize = 6;
    float buffer[kSize] = {0.1f, 0.2f, -0.3f, 0.4f, -0.5f, 0.6f};

    ProcessBuffer(buffer, kSize, 2.0f);

    for (std::size_t i = 0; i < kSize; ++i) {
        std::cout << buffer[i] << '\n';
    }
}
