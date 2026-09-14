#include "daisy_seed.h"
#include "PedalEngine.h"

using namespace daisy;
using namespace daisy::seed;

DaisySeed hw;
PedalEngine pedal;

float MapDrive(float normalized) {
    return 1.0f + normalized * 9.0f;
}

void AudioCallback(AudioHandle::InputBuffer in,
                   AudioHandle::OutputBuffer out,
                   size_t size) {
    // ADC peripheral scans in the background; GetFloat reads the latest value.
    const float drive = MapDrive(hw.adc.GetFloat(0));
    pedal.SetDrive(drive);

    for (size_t i = 0; i < size; ++i) {
        const float processed = pedal.Process(in[0][i]);
        out[0][i] = processed;
        out[1][i] = processed;
    }
}

int main() {
    hw.Init();
    hw.SetAudioBlockSize(48);

    AdcChannelConfig adcConfig;
    adcConfig.InitSingle(A0);
    hw.adc.Init(&adcConfig, 1);
    hw.adc.Start();

    pedal.Init(hw.AudioSampleRate());
    pedal.SetTone(0.6f);
    pedal.SetLevel(0.5f);

    hw.StartAudio(AudioCallback);
    while (true) {}
}
