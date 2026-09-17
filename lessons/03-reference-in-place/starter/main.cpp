#include <iostream>

// TODO: ApplyGainInPlace(float& sample, float gain)
void ApplyGainInPlace(float &sample, float gain)
{
    sample *= gain;
}

int main()
{
    float sample = 0.25f;
    std::cout << "before: " << sample << '\n';

    // TODO: gain=2.0fで呼ぶ
    ApplyGainInPlace(sample, 2.0f);

    std::cout << "after : " << sample << '\n';
}
