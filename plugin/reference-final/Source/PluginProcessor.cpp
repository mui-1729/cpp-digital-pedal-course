#include "PluginProcessor.h"
#include "PluginEditor.h"

namespace {
constexpr double kSmoothingSeconds = 0.03;
}

MiniDigitalDriveAudioProcessor::MiniDigitalDriveAudioProcessor()
    : AudioProcessor(BusesProperties()
                         .withInput("Input", juce::AudioChannelSet::stereo(), true)
                         .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      apvts_(*this, nullptr, "PARAMETERS", CreateParameterLayout()) {}

void MiniDigitalDriveAudioProcessor::prepareToPlay(double sampleRate, int) {
    for (auto& pedal : pedals_) {
        pedal.Prepare(static_cast<float>(sampleRate));
        pedal.Reset();
    }

    drive_.reset(sampleRate, kSmoothingSeconds);
    saturation_.reset(sampleRate, kSmoothingSeconds);
    tone_.reset(sampleRate, kSmoothingSeconds);
    level_.reset(sampleRate, kSmoothingSeconds);

    drive_.setCurrentAndTargetValue(*apvts_.getRawParameterValue("drive"));
    saturation_.setCurrentAndTargetValue(*apvts_.getRawParameterValue("saturation"));
    tone_.setCurrentAndTargetValue(*apvts_.getRawParameterValue("tone"));
    level_.setCurrentAndTargetValue(*apvts_.getRawParameterValue("level"));
}

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

    const int inputChannels = getTotalNumInputChannels();
    const int outputChannels = getTotalNumOutputChannels();
    const int numSamples = buffer.getNumSamples();

    for (int channel = inputChannels; channel < outputChannels; ++channel) {
        buffer.clear(channel, 0, numSamples);
    }

    float inPeak = 0.0f;
    for (int channel = 0; channel < inputChannels; ++channel) {
        inPeak = std::max(inPeak, buffer.getMagnitude(channel, 0, numSamples));
    }
    inputPeak_.store(inPeak, std::memory_order_relaxed);

    const bool bypass = *apvts_.getRawParameterValue("bypass") >= 0.5f;

    drive_.setTargetValue(*apvts_.getRawParameterValue("drive"));
    saturation_.setTargetValue(*apvts_.getRawParameterValue("saturation"));
    tone_.setTargetValue(*apvts_.getRawParameterValue("tone"));
    level_.setTargetValue(*apvts_.getRawParameterValue("level"));

    if (!bypass) {
        const int channelsToProcess = std::min(inputChannels, static_cast<int>(kMaxChannels));

        for (int sample = 0; sample < numSamples; ++sample) {
            const float drive = drive_.getNextValue();
            const float saturation = saturation_.getNextValue();
            const float tone = tone_.getNextValue();
            const float level = level_.getNextValue();

            for (int channel = 0; channel < channelsToProcess; ++channel) {
                auto& pedal = pedals_[static_cast<std::size_t>(channel)];
                pedal.SetDrive(drive);
                pedal.SetSaturation(saturation);
                pedal.SetTone(tone);
                pedal.SetLevel(level);

                auto* data = buffer.getWritePointer(channel);
                data[sample] = pedal.Process(data[sample]);
            }
        }
    } else {
        drive_.skip(numSamples);
        saturation_.skip(numSamples);
        tone_.skip(numSamples);
        level_.skip(numSamples);
    }

    float outPeak = 0.0f;
    for (int channel = 0; channel < outputChannels; ++channel) {
        outPeak = std::max(outPeak, buffer.getMagnitude(channel, 0, numSamples));
    }
    outputPeak_.store(outPeak, std::memory_order_relaxed);
}

MiniDigitalDriveAudioProcessor::APVTS::ParameterLayout
MiniDigitalDriveAudioProcessor::CreateParameterLayout() {
    APVTS::ParameterLayout layout;

    layout.add(
        std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID{"drive", 1},
            "Drive",
            juce::NormalisableRange<float>{1.0f, 12.0f, 0.01f, 0.45f},
            4.0f),
        std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID{"saturation", 1},
            "Saturation",
            juce::NormalisableRange<float>{0.0f, 1.0f, 0.001f},
            0.6f),
        std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID{"tone", 1},
            "Tone",
            juce::NormalisableRange<float>{0.0f, 1.0f, 0.001f},
            0.6f),
        std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID{"level", 1},
            "Level",
            juce::NormalisableRange<float>{0.0f, 1.0f, 0.001f},
            0.7f),
        std::make_unique<juce::AudioParameterBool>(
            juce::ParameterID{"bypass", 1},
            "Bypass",
            false));

    return layout;
}

void MiniDigitalDriveAudioProcessor::getStateInformation(juce::MemoryBlock& destData) {
    auto state = apvts_.copyState();
    if (auto xml = state.createXml()) {
        copyXmlToBinary(*xml, destData);
    }
}

void MiniDigitalDriveAudioProcessor::setStateInformation(const void* data, int sizeInBytes) {
    if (auto xml = getXmlFromBinary(data, sizeInBytes)) {
        if (xml->hasTagName(apvts_.state.getType())) {
            apvts_.replaceState(juce::ValueTree::fromXml(*xml));
        }
    }
}

juce::AudioProcessorEditor* MiniDigitalDriveAudioProcessor::createEditor() {
    return new MiniDigitalDriveAudioProcessorEditor(*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new MiniDigitalDriveAudioProcessor();
}
