cmake_minimum_required(VERSION 3.22)

project(MiniDigitalDrive VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 9.0.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(JUCE)

juce_add_plugin(MiniDigitalDrive
    COMPANY_NAME "mui-1729 learning"
    BUNDLE_ID "com.mui1729.learning.minidigitaldrive"
    PLUGIN_MANUFACTURER_CODE Mui1
    PLUGIN_CODE Mdd1
    PRODUCT_NAME "Mini Digital Drive"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    COPY_PLUGIN_AFTER_BUILD FALSE
    FORMATS VST3 Standalone
)

# The starter source uses <JuceHeader.h> too.
juce_generate_juce_header(MiniDigitalDrive)

target_sources(MiniDigitalDrive
    PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginProcessor.h
        Source/PluginEditor.cpp
        Source/PluginEditor.h
)

target_compile_features(MiniDigitalDrive PRIVATE cxx_std_20)

target_compile_definitions(MiniDigitalDrive
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(MiniDigitalDrive
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)
