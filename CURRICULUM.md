# カリキュラム

## 設計思想

「C++を全部勉強してからエフェクターを作る」方式にはしません。

```text
関数 → Gain
配列 → Audio Buffer
参照 → in-place処理
ポインタ → 実際のaudio callbackのbuffer
class → Effectを部品化
状態 → Filter / Delay
リアルタイム制約 → Daisy
電子回路 → Guitar I/O
```

必要な概念を、必要になった瞬間に導入します。

## Phase 0 — 準備

| 回 | テーマ | 完成物 | 追加購入 |
|---|---|---|---|
| 00 | 開発環境・Git・信号経路 | C++がローカルで動く | なし |

## Phase 1 — C++基礎 × エフェクター

| 回 | C++ | エフェクター題材 | 完成物 |
|---|---|---|---|
| 01 | 関数・引数・戻り値 | Gain | `ApplyGain()` |
| 02 | 配列・for・`size_t` | Audio Buffer | 複数sample処理 |
| 03 | 参照 | in-place処理 | sampleを直接変更 |
| 04 | ポインタ | Buffer API | `float*`を処理 |
| 05 | class | Effect | `Gain` class |
| 06 | 状態・setter | Distortion | DRIVEを保持 |
| 07 | `const` / `constexpr` / `enum class` | Clip mode | Hard/Soft切替 |
| 08 | `.h` / `.cpp` / Makefile | 部品化 | 小規模プロジェクト |

## Phase 2 — DSP基礎

| 回 | テーマ | 完成物 |
|---|---|---|
| 09 | sample / sample rate / 周波数 | 440HzのCSV波形 |
| 10 | dBとlinear gain | dB↔倍率変換 |
| 11 | clipping / waveshaping / headroom | Hard/Soft clip比較 |
| 12 | 1-pole low-pass | Toneフィルター |
| 13 | circular buffer | Delay |
| 14 | LFO + Effect chain + テスト | PC版Mini Pedal Engine |

**ここまで追加購入なし。**

## Purchase Gate A — 第15回直前

この時点で続けたいと判断したら初めて実機を買います。

- Daisy Seed3
- 大きめbreadboard
- jumper wire
- LED
- 抵抗セット
- tactile switch
- 10kΩ linear pot ×3
- USB-C data cable
- multimeter（借りられるなら購入不要）

## Phase 3 — Daisy / 物理世界

| 回 | テーマ | 完成物 |
|---|---|---|
| 15 | Toolchain / Flash / onboard LED | Seed3でBlink |
| 16 | GPIO / Switch / debounce | ボタンでLED制御 |
| 17 | ADC / Pot / smoothing | 物理ノブ→0〜1 |
| 18 | Audio callback / latency | Stereo passthrough |
| 19 | PCコードの移植 | Daisy Distortion |

## Phase 4 — 実ギター

| 回 | テーマ | 完成物 |
|---|---|---|
| 20 | HX Stomp FX Loop / gain staging / A-B | ギターで自作DSPを演奏 |

ここではHX Stompを使って、まずDSPに集中します。

## Phase 5 — ギター用電子回路

| 回 | テーマ | 完成物 |
|---|---|---|
| 21 | 電圧・GND・impedance・bias | 入力回路を読める |
| 22 | Input / Output stage | breadboard I/O |
| 23 | Power / noise / bypass / fault finding | HX Stompなしで単体動作 |

> **重要**: Seed3は新しく資料更新も続いています。Lesson 21開始時に公式datasheet / typical application circuitsを再確認し、その時点で回路BOMをfreezeします。

## Phase 6 — 最終制作

| 回 | テーマ | 完成物 |
|---|---|---|
| 24 | Enclosure / solder / final validation | MINI DIGITAL DRIVE |

## 最終合格条件

完成しただけでは終了ではありません。以下を説明できれば修了です。

- sample rateとは何か
- audio callbackが何をしているか
- `float*` がなぜ出てくるか
- `class`にする意味
- callback内で避けるべき処理
- guitar signalとline levelの違い
- high impedance inputが必要な理由
- GND / bias / AC couplingの役割
- ノイズ・無音・clipが起きた際の切り分け手順
- 自分のDistortion/Toneコードの信号経路
