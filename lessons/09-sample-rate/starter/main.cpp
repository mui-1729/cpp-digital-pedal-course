#include <cmath>
#include <fstream>

int main() {
    constexpr float kSampleRate = 48000.0f;
    constexpr float kFrequency = 440.0f;
    constexpr float kPi = 3.14159265358979323846f;

    std::ofstream file("wave.csv");
    file << "index,value\n";

    for (int i = 0; i < 100; ++i) {
        // TODO: timeとsampleを計算
        float sample = 0.0f;
        file << i << ',' << sample << '\n';
    }
}
