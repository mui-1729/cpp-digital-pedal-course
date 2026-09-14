#include "PluginEditor.h"

MiniDigitalDriveAudioProcessorEditor::MiniDigitalDriveAudioProcessorEditor(
    MiniDigitalDriveAudioProcessor& processor)
    : AudioProcessorEditor(&processor), processor_(processor) {
    ConfigureKnob(drive_, driveLabel_, "DRIVE");
    ConfigureKnob(saturation_, saturationLabel_, "SAT");
    ConfigureKnob(tone_, toneLabel_, "TONE");
    ConfigureKnob(level_, levelLabel_, "LEVEL");

    addAndMakeVisible(bypass_);

    auto& params = processor_.Parameters();
    driveAttachment_ = std::make_unique<SliderAttachment>(params, "drive", drive_);
    saturationAttachment_ = std::make_unique<SliderAttachment>(params, "saturation", saturation_);
    toneAttachment_ = std::make_unique<SliderAttachment>(params, "tone", tone_);
    levelAttachment_ = std::make_unique<SliderAttachment>(params, "level", level_);
    bypassAttachment_ = std::make_unique<ButtonAttachment>(params, "bypass", bypass_);

    setSize(620, 360);
    startTimerHz(30);
}

void MiniDigitalDriveAudioProcessorEditor::ConfigureKnob(
    juce::Slider& slider,
    juce::Label& label,
    const juce::String& text) {
    slider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 20);

    label.setText(text, juce::dontSendNotification);
    label.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(slider);
    addAndMakeVisible(label);
}

void MiniDigitalDriveAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colour::fromRGB(24, 24, 28));

    g.setColour(juce::Colours::white);
    g.setFont(26.0f);
    g.drawFittedText(
        "MINI DIGITAL DRIVE",
        0,
        16,
        getWidth(),
        36,
        juce::Justification::centred,
        1);

    DrawMeter(g, {30.0f, 305.0f, 240.0f, 18.0f}, inputPeak_, "IN");
    DrawMeter(g, {350.0f, 305.0f, 240.0f, 18.0f}, outputPeak_, "OUT");
}

void MiniDigitalDriveAudioProcessorEditor::resized() {
    const int top = 78;
    const int knobSize = 120;
    const int labelHeight = 24;
    const int gap = 18;
    const int totalWidth = knobSize * 4 + gap * 3;
    int x = (getWidth() - totalWidth) / 2;

    auto place = [&](juce::Slider& slider, juce::Label& label) {
        label.setBounds(x, top, knobSize, labelHeight);
        slider.setBounds(x, top + labelHeight, knobSize, knobSize);
        x += knobSize + gap;
    };

    place(drive_, driveLabel_);
    place(saturation_, saturationLabel_);
    place(tone_, toneLabel_);
    place(level_, levelLabel_);

    bypass_.setBounds(getWidth() / 2 - 55, 250, 110, 30);
}

void MiniDigitalDriveAudioProcessorEditor::timerCallback() {
    inputPeak_ = processor_.GetInputPeak();
    outputPeak_ = processor_.GetOutputPeak();
    repaint();
}

void MiniDigitalDriveAudioProcessorEditor::DrawMeter(
    juce::Graphics& g,
    juce::Rectangle<float> area,
    float value,
    const juce::String& label) {
    value = juce::jlimit(0.0f, 1.0f, value);

    g.setColour(juce::Colours::darkgrey);
    g.fillRect(area);

    auto fill = area;
    fill.setWidth(area.getWidth() * value);
    g.setColour(juce::Colours::white);
    g.fillRect(fill);

    g.setColour(juce::Colours::lightgrey);
    g.setFont(12.0f);
    g.drawText(label, area.translated(0.0f, -18.0f), juce::Justification::left);
}
