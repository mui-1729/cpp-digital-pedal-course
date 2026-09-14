# P17 — 共通`PedalEngine`をPluginへ接続する

## 今日作るもの

Lesson 14までに学んだDSPを、JUCEの`processBlock()`から呼びます。

## 新しい知識

- framework-independent DSP
- adapter / bridge
- channelごとのstate

## 重要な設計

```text
JUCE AudioBuffer
      ↓
PluginProcessor
      ↓
shared/dsp/PedalEngine.h
```

`PedalEngine.h`はJUCEをincludeしません。

## Hands-on

1. `shared/dsp/PedalEngine.h`を読む。
2. Processorへ`PedalEngine`を追加。
3. `prepareToPlay()`でsample rateを渡す。
4. `processBlock()`で1sampleずつ`Process()`する。
5. mono/stereoそれぞれで確認。

### なぜPedalEngineをchannelごとに持つ？

Tone filterは「前回のsample」というstateを持ちます。左と右で同じinstanceを共有すると、channel間でstateが混ざります。

```text
L → PedalEngine L
R → PedalEngine R
```

## Challenge

- DSP ON/OFF用の一時的な`bool`を作りA/Bする。
- Distortionを外してToneだけにした場合の差を確認する。

## 合格条件

- JUCE依存コードとDSPコードを分離できる
- stateful effectをstereo channel間で共有してはいけない理由を説明できる
- `PedalEngine`をDaisyにも持っていける理由を説明できる

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p17: connect shared pedal engine"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
