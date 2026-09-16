#include <iostream>

// TODO: ApplyGain をここに書く
float ApplyGain(float input, float gain) {
    return input * gain;
}

int main() {
    float input = -0.25f;
    float gain = 3.0f;

    // TODO: ApplyGainを呼び出してoutputに入れる
    float output = ApplyGain(input, gain);

    std::cout << output << std::endl;
    return 0;
}
