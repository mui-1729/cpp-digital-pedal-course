# P18 — Plugin ParameterとAutomation

## 今日作るもの

Hostから操作できる`DRIVE / TONE / LEVEL / BYPASS` parameter。

## 新しい知識

- parameter ID
- `AudioProcessorValueTreeState` (APVTS)
- parameter range / default
- host automation
- raw parameter value

## Hands-on

1. `createParameterLayout()`を作る。
2. `drive`, `tone`, `level`, `bypass`を登録。
3. Processorでparameter値を読み、`PedalEngine`へ渡す。
4. Generic host/DAWからparameterが見えることを確認。
5. parameterを動かしながら音が変わることを確認。
6. 可能ならautomation laneでDRIVEを動かす。

## Parameter rangeを適当に決めない

例:

- DRIVE: `1.0 ... 12.0`
- TONE: `0.0 ... 1.0`
- LEVEL: `0.0 ... 1.0`
- BYPASS: bool

DSP内部の意味とUI表示用の意味を混ぜない。

## Challenge

DRIVEのrangeを極端に広くして問題点を体験し、元へ戻す。

## 合格条件

- parameterと普通のmember変数の違いを説明できる
- IDを後から軽率に変更しない理由を理解
- host automationがDSPへ届く流れを説明できる

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p18: add automatable parameters"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
