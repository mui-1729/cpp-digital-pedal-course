#include <iostream>

// TODO: class Gain を作る
class Gain
{
public:
    float Process(float input, float gain)
    {
        return input * gain;
    };
};

int main()
{
    Gain gainEffect;
    // TODO: Gain objectを作り、Processを呼ぶ
    float output = gainEffect.Process(0.25f, 2.0f);
    std::cout << output << '\n';
}
