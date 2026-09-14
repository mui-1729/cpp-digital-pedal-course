# Lesson 19 — PC版PedalEngineをDaisyへ移植する

**Phase:** 3-6: 実機

## 今日作るもの

Lesson 14のDistortion→Tone→Levelをリアルタイムに動かす。

## 必要なもの

Seed3 / Lesson 18で動作確認済みAudio I/O / POT最低1個。

## 新しく使う知識

hardware/DSP separation / parameter update rate / static allocation

## なぜ必要？

DSP本体はPCでテスト済み。Daisy側で新たに書くのはI/O bridgeだけ、という設計を体験します。

## Hands-on

1. `PedalEngine.h`をDaisy projectへcopy。
2. `pedal.Init(hw.AudioSampleRate())`相当を起動時に1回。
3. POTの値をdriveへmap。
4. callbackで`pedal.Process(in[0][i])`。
5. parameter更新はsampleごとに重い処理をしないよう整理。
6. passthroughとeffectをA/Bできるboolを用意する。

## Challenge

- bypass boolでprocessed/rawを切替。
- output levelを安全な値から開始。
- static/global objectを使う理由をmemory allocation観点で説明する。

## 合格条件

- PC DSPをhardware projectへ移植できた
- passthroughへ即戻せる
- callback内にallocation/printがない
- effectを切って問題切り分けできる

## Debug rule

音が出なければ最初にLesson 18のpassthroughへ戻す。DSPとhardwareを同時に疑わない。

## 解説

### 移植で新しくなるのは外側だけ

PC版:

```text
固定sample → PedalEngine → cout
```

Daisy版:

```text
ADC/audio input → PedalEngine → DAC/audio output
```

中心のDSPは同じです。この設計ができていれば、「組み込みC++」と「DSPアルゴリズム」を別々にdebugできます。

### Control rate

POTを48000回/秒読む必要はありません。human controlはaudio sampleより遥かに遅いため、parameter更新を適切なrateで行い、DSP側へsmooth値を渡します。

## よくあるミス

- PCで動いたcodeを丸ごとcallbackへ入れ、I/Oやallocationまで混ぜる
- effectが原因かhardwareが原因か切り分けず同時修正

## 確認問題

1. PedalEngineがDaisyをincludeしない利点は？
2. POTをaudio rateで読む必要がない理由は？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 19: port pedal engine to daisy"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
