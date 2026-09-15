#include "PluginEditor.h"

MiniDigitalDriveAudioProcessorEditor::MiniDigitalDriveAudioProcessorEditor(
    MiniDigitalDriveAudioProcessor& processor)
    : AudioProcessorEditor(&processor), processor_(processor) {
    setSize(520, 240);
}

void MiniDigitalDriveAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(24.0f);
    g.drawFittedText(
        "MINI DIGITAL DRIVE",
        getLocalBounds().reduced(20).removeFromTop(60),
        juce::Justification::centred,
        1);

    g.setFont(16.0f);
    g.drawFittedText(
        "P15: audio passes through unchanged",
        getLocalBounds().reduced(20),
        juce::Justification::centred,
        1);
}

void MiniDigitalDriveAudioProcessorEditor::resized() {}
