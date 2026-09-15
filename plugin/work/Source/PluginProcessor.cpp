#include "PluginProcessor.h"
#include "PluginEditor.h"

MiniDigitalDriveAudioProcessor::MiniDigitalDriveAudioProcessor()
    : AudioProcessor(BusesProperties()
                         .withInput("Input", juce::AudioChannelSet::stereo(), true)
                         .withOutput("Output", juce::AudioChannelSet::stereo(), true)) {}

void MiniDigitalDriveAudioProcessor::prepareToPlay(double, int) {}

void MiniDigitalDriveAudioProcessor::releaseResources() {}

bool MiniDigitalDriveAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const {
    const auto output = layouts.getMainOutputChannelSet();
    if (output != juce::AudioChannelSet::mono()
        && output != juce::AudioChannelSet::stereo()) {
        return false;
    }

    return output == layouts.getMainInputChannelSet();
}

void MiniDigitalDriveAudioProcessor::processBlock(
    juce::AudioBuffer<float>& buffer,
    juce::MidiBuffer&) {
    juce::ScopedNoDenormals noDenormals;

    const auto totalInputChannels = getTotalNumInputChannels();
    const auto totalOutputChannels = getTotalNumOutputChannels();

    for (auto channel = totalInputChannels; channel < totalOutputChannels; ++channel) {
        buffer.clear(channel, 0, buffer.getNumSamples());
    }

    // P15: passthrough. P16以降でこのbufferを処理していく。
}

juce::AudioProcessorEditor* MiniDigitalDriveAudioProcessor::createEditor() {
    return new MiniDigitalDriveAudioProcessorEditor(*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new MiniDigitalDriveAudioProcessor();
}
