#include "daisy_seed.h"
// TODO: PedalEngine.hをLesson 14から持ってくる

using namespace daisy;

DaisySeed hw;

void AudioCallback(AudioHandle::InputBuffer in,
                   AudioHandle::OutputBuffer out,
                   size_t size) {
    for (size_t i = 0; i < size; ++i) {
        // TODO: pedal.Process
        out[0][i] = in[0][i];
        out[1][i] = in[1][i];
    }
}

int main() {
    hw.Init();
    // TODO: pedal init / ADC init
    hw.StartAudio(AudioCallback);
    while (true) {}
}
