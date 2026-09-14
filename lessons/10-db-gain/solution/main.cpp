#include <cmath>
#include <iostream>
#include <limits>

float DbToLinear(float db) {
    return std::pow(10.0f, db / 20.0f);
}

float LinearToDb(float linear) {
    if (linear <= 0.0f) {
        return -std::numeric_limits<float>::infinity();
    }
    return 20.0f * std::log10(linear);
}

int main() {
    for (float db : {-6.0f, 0.0f, 6.0f, 12.0f}) {
        const float linear = DbToLinear(db);
        std::cout << db << " dB -> " << linear << " -> " << LinearToDb(linear) << " dB\n";
    }
}
