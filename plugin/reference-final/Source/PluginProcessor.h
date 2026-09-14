#pragma once

#include <JuceHeader.h>
#include <array>
#include <atomic>
#include "dsp/PedalEngine.h"

class MiniDigitalDriveAudioProcessor : public juce::AudioProcessor {
public:
    using APVTS = juce::AudioProcessorValueTreeState;

    MiniDigitalDriveAudioProcessor();
    ~MiniDigitalDriveAudioProcessor() override = default;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return JucePlugin_Name; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}

    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(const void*, int) override;

    APVTS& Parameters() { return apvts_; }
    float GetInputPeak() const { return inputPeak_.load(std::memory_order_relaxed); }
    float GetOutputPeak() const { return outputPeak_.load(std::memory_order_relaxed); }

    static APVTS::ParameterLayout CreateParameterLayout();

private:
    static constexpr std::size_t kMaxChannels = 2;

    APVTS apvts_;
    std::array<pedal::PedalEngine, kMaxChannels> pedals_;

    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> drive_;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> saturation_;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> tone_;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> level_;

    std::atomic<float> inputPeak_{0.0f};
    std::atomic<float> outputPeak_{0.0f};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MiniDigitalDriveAudioProcessor)
};
