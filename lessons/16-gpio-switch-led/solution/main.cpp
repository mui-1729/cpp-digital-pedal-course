#include "daisy_seed.h"

using namespace daisy;
using namespace daisy::seed;

DaisySeed hw;
GPIO button;
GPIO led;

int main() {
    hw.Init();
    button.Init(D0, GPIO::Mode::INPUT, GPIO::Pull::PULLUP);
    led.Init(D1, GPIO::Mode::OUTPUT);

    while (true) {
        const bool pressed = !button.Read();
        led.Write(pressed);
    }
}
