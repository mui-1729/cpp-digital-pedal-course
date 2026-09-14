#include <cstddef>
#include <iostream>

// TODO: ProcessBuffer を書く

int main() {
    constexpr std::size_t kSize = 6;
    float buffer[kSize] = {0.1f, 0.2f, -0.3f, 0.4f, -0.5f, 0.6f};

    // TODO: gain=2.0fでbuffer全体を処理する

    for (std::size_t i = 0; i < kSize; ++i) {
        std::cout << buffer[i] << '\n';
    }
}
