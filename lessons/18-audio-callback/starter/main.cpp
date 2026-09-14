#include "daisy_seed.h"

using namespace daisy;

DaisySeed hw;

void AudioCallback(AudioHandle::InputBuffer in,
                   AudioHandle::OutputBuffer out,
                   size_t size) {
    // TODO: inをoutへcopy
}

int main() {
    hw.Init();
    hw.SetAudioBlockSize(48);
    hw.StartAudio(AudioCallback);
    while (true) {}
}
