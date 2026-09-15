#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class MiniDigitalDriveAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    explicit MiniDigitalDriveAudioProcessorEditor(MiniDigitalDriveAudioProcessor&);
    ~MiniDigitalDriveAudioProcessorEditor() override = default;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    MiniDigitalDriveAudioProcessor& processor_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MiniDigitalDriveAudioProcessorEditor)
};
