#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class MiniDigitalDriveAudioProcessorEditor
    : public juce::AudioProcessorEditor,
      private juce::Timer {
public:
    explicit MiniDigitalDriveAudioProcessorEditor(MiniDigitalDriveAudioProcessor&);
    ~MiniDigitalDriveAudioProcessorEditor() override = default;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using ButtonAttachment = juce::AudioProcessorValueTreeState::ButtonAttachment;

    void timerCallback() override;
    void ConfigureKnob(juce::Slider& slider, juce::Label& label, const juce::String& text);
    void DrawMeter(juce::Graphics&, juce::Rectangle<float> area, float value, const juce::String& label);

    MiniDigitalDriveAudioProcessor& processor_;

    juce::Slider drive_;
    juce::Slider saturation_;
    juce::Slider tone_;
    juce::Slider level_;
    juce::ToggleButton bypass_{"BYPASS"};

    juce::Label driveLabel_;
    juce::Label saturationLabel_;
    juce::Label toneLabel_;
    juce::Label levelLabel_;

    std::unique_ptr<SliderAttachment> driveAttachment_;
    std::unique_ptr<SliderAttachment> saturationAttachment_;
    std::unique_ptr<SliderAttachment> toneAttachment_;
    std::unique_ptr<SliderAttachment> levelAttachment_;
    std::unique_ptr<ButtonAttachment> bypassAttachment_;

    float inputPeak_ = 0.0f;
    float outputPeak_ = 0.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MiniDigitalDriveAudioProcessorEditor)
};
