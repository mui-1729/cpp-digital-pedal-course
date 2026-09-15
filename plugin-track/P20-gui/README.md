# P20 — 4ノブGUIとBypass

## 今日作るもの

P18で使ったGeneric Editorを、自分の4ノブGUIへ置き換えます。

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

1. P18で一時的に返していた`GenericAudioProcessorEditor`をやめ、`MiniDigitalDriveAudioProcessorEditor`を返す形へ戻す。
2. Editorへrotary Sliderを4個作る。
3. `DRIVE / SAT / TONE / LEVEL`のlabelを付ける。
4. `SliderAttachment`で各SliderをAPVTS parameterへ接続。
5. `ButtonAttachment`でBYPASSをparameterへ接続。
6. `resized()`で固定gridへ配置。
7. buildしてStandaloneで操作する。
8. GUIを閉じて再度開き、parameter値がProcessor側に残っていることを確認。
9. window sizeを一度変えて配置の崩れ方を見て、`resized()`の役割を確認する。

## Attachmentが重要な理由

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

これなら、GUIから触ってもHost automationから触っても**同じParameterがsource of truth**になります。

## GUIはDSPではない

確認として、Editorを閉じたまま音声処理が継続することを見る。

```text
Processor / DSP = 音を処理する
Editor          = 状態を表示・操作する
```

この分離は後のHardware Trackで「POT/LED」と「PedalEngine」を分ける考え方にも繋がります。

## Challenge

- SATノブだけ一時的に`setVisible(false)`相当で隠してもDSPが壊れないことを確認する。
- Labelの文字だけ変え、Parameter IDは変えない。
- GUIを極端に横長にして、固定配置の弱点を観察する。

## よくあるエラー

### ノブは動くがParameterが変わらない

Attachment objectをlocal変数にしてすぐ破棄していないか確認する。AttachmentはEditorのmemberとして生存させます。

### GUIを開くと値が初期値へ戻る

Slider自身をsource of truthにしていないか確認。APVTS parameterへAttachmentする。

## 合格条件

- Generic Editorから自作Editorへ置き換えられた
- Attachmentの役割を説明できる
- GUIを消してもDSPが動く設計
- ParameterがHostとGUIの両方から操作可能
- EditorとProcessorの寿命/責務が違うことを説明できる

## Git checkpoint

```bash
git status
git diff
git add .
git commit -m "plugin p20: build four-knob gui"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
