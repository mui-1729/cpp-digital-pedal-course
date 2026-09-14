#include <iostream>

class Gain {
public:
    float Process(float input, float gain) {
        return input * gain;
    }
};

int main() {
    Gain gainEffect;
    float output = gainEffect.Process(0.25f, 2.0f);
    std::cout << output << '\n';
}
