#include "daisy_seed.h"

using namespace daisy;
using namespace daisy::seed;

DaisySeed hw;

int main() {
    hw.Init();
    hw.StartLog();

    AdcChannelConfig adcConfig;
    adcConfig.InitSingle(A0);
    hw.adc.Init(&adcConfig, 1);
    hw.adc.Start();

    float smooth = 0.0f;
    while (true) {
        const float raw = hw.adc.GetFloat(0);
        smooth += 0.05f * (raw - smooth);
        const int milli = static_cast<int>(smooth * 1000.0f);
        hw.PrintLine("pot x1000: %d", milli);
        System::Delay(50);
    }
}
