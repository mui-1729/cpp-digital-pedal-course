# 一次資料

framework / SDK / hardwareが変わる部分は一次資料をsource of truthにします。

確認日: 2026-09-15

## JUCE / Plugin Track

- JUCE Learn: https://juce.com/learn/
- Free Audio Plug-in Development Course: https://juce.com/learn/course/
- JUCE GitHub releases: https://github.com/juce-framework/JUCE/releases
- JUCE official CMake example: https://github.com/juce-framework/JUCE/tree/master/examples/CMake/AudioPlugin
- JUCE CMake API: https://github.com/juce-framework/JUCE/blob/master/docs/CMake%20API.md
- GenericAudioProcessorEditor: https://docs.juce.com/master/classjuce_1_1GenericAudioProcessorEditor.html
- Adding plug-in parameters: https://juce.com/tutorials/tutorial_audio_parameter/
- APVTS / state: https://docs.juce.com/master/classjuce_1_1AudioProcessorValueTreeState.html
- JUCE licensing / Get JUCE: https://juce.com/get-juce/
- JUCE legal: https://juce.com/category/legal/

### Version policy

Plugin Track開始時点では再現性のためJUCE versionを [PLUGIN-VERSIONS.md](PLUGIN-VERSIONS.md) にpinします。最新版へ上げるのは「学習中のついで」ではなく明示的なupgrade作業として行います。

教材のbuild方式はCMakeをsource of truthにし、古いProjucer前提のtutorialをそのまま手順としてコピーしません。

## Windows C++ toolchain

- Visual Studio 2026 release notes: https://learn.microsoft.com/en-us/visualstudio/releases/2026/release-notes
- CMake Visual Studio 18 2026 generator docs: https://cmake.org/cmake/help/latest/generator/Visual%20Studio%2018%202026.html

2026-09-15時点ではVisual Studio 2026が現行です。ただし教材ではCMake commandへ特定世代名を固定せず、P15開始日にcurrent toolchainを記録します。

## VST3

- VST3 Developer Portal: https://steinbergmedia.github.io/vst3_dev_portal/
- VST3 Licensing: https://steinbergmedia.github.io/vst3_dev_portal/pages/VST%2B3%2BLicensing/Index.html

VST3 SDK 3.8以降はMIT license。VST trademark/logo利用は別途usage guideline確認。

## Plugin validation

- pluginval: https://github.com/Tracktion/pluginval

P23ではbinary validatorとして使います。projectへ直接組み込む必要はありません。

## Daisy

- Daisy current site / Seed3: https://daisy.audio/
- Daisy hardware docs: https://docs.daisy.audio/hardware/
- GPIO tutorial: https://docs.daisy.audio/tutorials/_a1_Getting-Started-GPIO/
- Audio tutorial: https://docs.daisy.audio/tutorials/_a3_Getting-Started-Audio/
- ADC tutorial: https://docs.daisy.audio/tutorials/_a4_Getting-Started-ADCs/
- Create new project: https://docs.daisy.audio/tutorials/create-new-project/
- libDaisy source/docs: https://docs.daisy.audio/libDaisy/

Seed3は従来Seedとpin/firmware compatibilityが案内されています。一方、回路資料は更新されるためHardware 21開始時に最新版を再確認します。

## Line 6 HX Stomp

- HX Stomp Owner's Manual:
  https://line6.com/data/6/0a00051afdda673cccdb61c9c/application/pdf/HX%20Stomp%203.80%20Owner%27s%20Manual%20-%20English%20.pdf

Hardware 20でgain stagingに利用します。

## C++ reference

- https://en.cppreference.com/

必要な項目だけ参照します。
