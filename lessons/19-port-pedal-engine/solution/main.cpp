#include "daisy_seed.h"
#include "dsp/PedalEngine.h"

using namespace daisy;
using namespace daisy::seed;

DaisySeed hw;
pedal::PedalEngine pedalEngine;

float MapDrive(float normalized) {
    return 1.0f + normalized * 9.0f;
}

void AudioCallback(AudioHandle::InputBuffer in,
                   AudioHandle::OutputBuffer out,
                   size_t size) {
    // ADC peripheral scans in the background; GetFloat reads the latest value.
    // Control-rate update: once per audio block, not once per sample.
    const float drive = MapDrive(hw.adc.GetFloat(0));
    pedalEngine.SetDrive(drive);

    for (size_t i = 0; i < size; ++i) {
        const float processed = pedalEngine.Process(in[0][i]);
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

    pedalEngine.Prepare(hw.AudioSampleRate());
    pedalEngine.SetDrive(4.0f);
    pedalEngine.SetSaturation(0.6f);
    pedalEngine.SetTone(0.6f);
    pedalEngine.SetLevel(0.5f);

    hw.StartAudio(AudioCallback);
    while (true) {}
}
