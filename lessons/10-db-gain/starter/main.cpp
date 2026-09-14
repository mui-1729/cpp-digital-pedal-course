#include <cmath>
#include <iostream>

float DbToLinear(float db) {
    // TODO
    return 0.0f;
}

float LinearToDb(float linear) {
    // TODO: linear <= 0 の扱いにも注意
    return 0.0f;
}

int main() {
    for (float db : {-6.0f, 0.0f, 6.0f, 12.0f}) {
        const float linear = DbToLinear(db);
        std::cout << db << " dB -> " << linear << " -> " << LinearToDb(linear) << " dB\n";
    }
}
