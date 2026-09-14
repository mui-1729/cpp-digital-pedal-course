#include <iostream>

void ApplyGainInPlace(float& sample, float gain) {
    sample *= gain;
}

int main() {
    float sample = 0.25f;
    std::cout << "before: " << sample << '\n';

    ApplyGainInPlace(sample, 2.0f);

    std::cout << "after : " << sample << '\n';
}
