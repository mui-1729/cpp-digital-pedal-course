#include "daisy_seed.h"

using namespace daisy;

DaisySeed hw;

int main() {
    hw.Init();
    bool led = false;

    while (true) {
        hw.SetLed(led);
        led = !led;
        System::Delay(500);
    }
}
