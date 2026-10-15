#include <iostream>
#include <cmath>

float DbToLinear(float db)
{
    return std::pow(10.0f, db / 20.0f);
}

float LinearToDb(float linear)
{
    if (linear <= 0.0f)
    {
        return -120.0f;
    }

    return 20.0f * std::log10(linear);
}

int main()
{
    std::cout << LinearToDb(1.0f) << '\n';
    std::cout << LinearToDb(2.0f) << '\n';
    std::cout << LinearToDb(0.5f) << '\n';

    // dB → 振幅倍率 → dB
    float db = -12.0f;
    float linear = DbToLinear(db);

    std::cout << LinearToDb(linear) << '\n';

    return 0;
}
