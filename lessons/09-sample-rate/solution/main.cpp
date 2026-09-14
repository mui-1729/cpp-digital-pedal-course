#include <cmath>
#include <fstream>

int main() {
    constexpr float kSampleRate = 48000.0f;
    constexpr float kFrequency = 440.0f;
    constexpr float kPi = 3.14159265358979323846f;

    std::ofstream file("wave.csv");
    file << "index,value\n";

    for (int i = 0; i < 100; ++i) {
        const float time = static_cast<float>(i) / kSampleRate;
        const float sample = std::sin(2.0f * kPi * kFrequency * time);
        file << i << ',' << sample << '\n';
    }
}
