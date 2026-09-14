#include <iostream>

float ApplyGain(float input, float gain) {
    return input * gain;
}

int main() {
    float input = 0.25f;
    float gain = 2.0f;
    float output = ApplyGain(input, gain);

    std::cout << output << std::endl;
    return 0;
}
