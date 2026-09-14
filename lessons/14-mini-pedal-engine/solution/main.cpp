#include "PedalEngine.h"
#include <iostream>

int main() {
    PedalEngine pedal;
    pedal.Init(48000.0f);
    pedal.SetDrive(4.0f);
    pedal.SetTone(0.6f);
    pedal.SetLevel(0.8f);

    for (float sample : {0.0f, 0.1f, 0.3f, 0.8f, -0.8f, -0.3f, -0.1f, 0.0f}) {
        std::cout << pedal.Process(sample) << '\n';
    }
}
