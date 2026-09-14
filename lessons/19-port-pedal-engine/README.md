# Lesson 19 — 共通PedalEngineをDaisyへ移植する

**Phase:** Hardware Track

## 今日作るもの

PC/Pluginで使った`shared/dsp/PedalEngine.h`をDaisy上でリアルタイムに動かす。

## 必要なもの

Seed3 / Lesson 18で動作確認済みAudio I/O / POT最低1個。

## 新しく使う知識

hardware/DSP separation / parameter update rate / static allocation / platform adapter

## なぜ必要？

DSP本体はPCでテスト済みです。Daisy側で新たに書くのはI/O bridgeだけ、という設計を体験します。

Plugin Trackを先に終えている場合は、**VST3で使ったものと同じ`shared/dsp/PedalEngine.h`**を使います。Plugin Trackを飛ばしてHardwareへ来た場合も、このshared版をLesson 14の発展版として使えます。

## Hands-on

1. `shared/dsp/PedalEngine.h`をDaisy projectから参照またはcopy。
2. 起動時に`pedal.Prepare(hw.AudioSampleRate())`相当を1回実行。
3. POT値をdrive/tone/levelへmap。
4. callbackで`pedal.Process(in[0][i])`。
5. stereoならchannelごとにstateful `PedalEngine` instanceを分ける。
6. parameter更新はsampleごとに重い処理をしないよう整理。
7. passthroughとeffectをA/Bできるboolを用意する。

## Pluginとの対応

```text
PluginProcessor::processBlock()
        ↓
  PedalEngine::Process()
```

```text
Daisy AudioCallback()
        ↓
  PedalEngine::Process()
```

**真ん中は同じ。外側だけ違う**のがこの教材の狙いです。

## Challenge

- bypass boolでprocessed/rawを切替。
- SAT parameterもPOTまたは固定値で試す。
- output levelを安全な値から開始。
- static/global objectを使う理由をmemory allocation観点で説明する。

## 合格条件

- 共通DSPをhardware projectへ移植できた
- passthroughへ即戻せる
- callback内にallocation/printがない
- stateful DSPをchannelごとに分けられる
- effectを切って問題切り分けできる

## Debug rule

音が出なければ最初にLesson 18のpassthroughへ戻す。DSPとhardwareを同時に疑わない。

## Control rate

POTを48000回/秒読む必要はありません。human controlはaudio sampleより遥かに遅いため、parameter更新を適切なrateで行い、必要ならsmooth値をDSP側へ渡します。

## よくあるミス

- PCで動いたcodeを丸ごとcallbackへ入れ、I/Oやallocationまで混ぜる
- left/rightで同じfilter stateを共有する
- effectが原因かhardwareが原因か切り分けず同時修正

## 確認問題

1. PedalEngineがJUCE/Daisyをincludeしない利点は？
2. PluginとDaisyで共通化できない部分はどこ？
3. POTをaudio rateで読む必要がない理由は？

## Git checkpoint

```bash
git add .
git commit -m "lesson 19: port shared pedal engine to daisy"
```
