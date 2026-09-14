#include "PedalEngine.h"
#include <cassert>
#include <cmath>

int main() {
    PedalEngine pedal;
    pedal.Init(48000.0f);
    pedal.SetDrive(4.0f);
    pedal.SetTone(0.5f);
    pedal.SetLevel(0.0f);

    const float muted = pedal.Process(0.5f);
    assert(muted == 0.0f);

    pedal.SetLevel(1.0f);
    for (float input : {-1.0f, -0.5f, 0.0f, 0.5f, 1.0f}) {
        const float output = pedal.Process(input);
        assert(std::isfinite(output));
        assert(output >= -1.1f && output <= 1.1f);
    }
}
