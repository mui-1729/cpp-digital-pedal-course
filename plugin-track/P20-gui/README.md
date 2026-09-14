# P20 — 4ノブGUIとBypass

## 今日作るもの

```text
┌──────────────────────────┐
│    MINI DIGITAL DRIVE    │
│                          │
│ DRIVE   SAT    TONE      │
│   ◯      ◯      ◯       │
│                          │
│       LEVEL  ◯           │
│        [BYPASS]          │
└──────────────────────────┘
```

## 新しい知識

- `AudioProcessorEditor`
- Slider / ToggleButton / Label
- APVTS Attachment
- `resized()`
- GUIとDSPの分離

## Hands-on

1. rotary Sliderを4個作る。
2. labelを付ける。
3. `SliderAttachment`でparameterへ接続。
4. `ButtonAttachment`でBypassへ接続。
5. `resized()`で固定gridへ配置。
6. window resizeを一度試し、崩れ方を見る。

## 重要

GUIのSlider callbackから直接:

```cpp
pedal.SetDrive(...)
```

とはしません。

```text
Slider
 ↓ Attachment
Parameter
 ↓ audio thread
PedalEngine
```

にする。

## Challenge

SATノブだけ一時的に隠してもDSPが壊れないことを確認。

## 合格条件

- Attachmentの役割を説明できる
- GUIを消してもDSPが動く設計
- parameterがhostとGUIの両方から操作可能

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p20: build four-knob gui"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
