#include <algorithm>
#include <cmath>
#include <fstream>

float HardClip(float x) {
    // TODO
    return x;
}

float SoftClip(float x) {
    // TODO
    return x;
}

int main() {
    constexpr float kPi = 3.14159265358979323846f;
    constexpr float kDrive = 3.0f;
    std::ofstream file("clip.csv");
    file << "input,hard,soft\n";

    for (int i = 0; i < 200; ++i) {
        const float phase = static_cast<float>(i) / 200.0f;
        const float input = std::sin(2.0f * kPi * phase);
        const float driven = input * kDrive;
        file << input << ',' << HardClip(driven) << ',' << SoftClip(driven) << '\n';
    }
}
