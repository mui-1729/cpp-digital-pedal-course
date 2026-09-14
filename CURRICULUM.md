# カリキュラム

## 設計思想

「C++を全部勉強してから作る」方式にはしません。

```text
関数       → Gain
配列       → Audio Buffer
ポインタ   → Buffer API
class      → Effectを部品化
状態       → Filter / Delay
DSP        → PedalEngine
Audio Host → Plugin
Callback   → Daisy
電子回路   → Guitar I/O
```

必要な概念を、必要になった瞬間に導入します。

---

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

ここまでが**共通編**です。追加購入はありません。

---

# Plugin Track — PCだけで完成させる

識別子は既存Hardware Lesson番号と衝突しないよう`P15〜P24`にします。

| 回 | テーマ | 主な知識 | 完成物 |
|---|---|---|---|
| P15 | JUCE/CMake/Standalone | native Windows build / host | 初めて起動するPlugin |
| P16 | `processBlock()` | AudioBuffer / mono-stereo / real-time | passthrough |
| P17 | 共通DSPを接続 | framework separation | PedalEngine入りPlugin |
| P18 | Parameter | APVTS / automation / ranges | DRIVE/TONE/LEVEL |
| P19 | Saturation + smoothing | SAT / zipper noise / smoothing | 4ノブDSP |
| P20 | GUI | Slider/Button/Attachment/layout | 4ノブ + Bypass UI |
| P21 | State / preset | save/restore / DAW state / A-B | 設定保存 |
| P22 | Meter / threading | audio thread vs message thread / atomics | input/output meter |
| P23 | Validation | sample rate / block size / mono-stereo / pluginval | 安定性チェック |
| P24 | Release | version / artifact / licence gate / docs | Mini Digital Drive VST3 + Standalone |

### Plugin Trackの修了条件

- `processBlock()`の役割を説明できる
- audio threadで避ける処理を説明できる
- parameterとDSPを分離できる
- stateを保存・復元できる
- GUI threadとaudio threadを直接危険に共有しない
- 44.1/48/96kHz、複数block size、mono/stereoを確認できる
- StandaloneとVST3の両方をbuildできる
- pluginvalまたは同等のvalidationを実行できる
- JUCE/VST3のライセンスを「配布時に再確認する項目」として扱える

Plugin Trackの詳しい設計は [PLUGIN-TRACK.md](PLUGIN-TRACK.md)。

---

# Hardware Track — 同じDSPを物理世界へ

Plugin Trackを先に終えることを推奨しますが、Lesson 14から直接進んでも構いません。

## Purchase Gate A — Hardware 15直前

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
| 19 | 共通DSPの移植 | Daisy Distortion |

## Phase 4 — 実ギター

| 回 | テーマ | 完成物 |
|---|---|---|
| 20 | HX Stomp FX Loop / gain staging / A-B | ギターで自作DSPを演奏 |

## Phase 5 — ギター用電子回路

| 回 | テーマ | 完成物 |
|---|---|---|
| 21 | 電圧・GND・impedance・bias | 入力回路を読める |
| 22 | Input / Output stage | breadboard I/O |
| 23 | Power / noise / bypass / fault finding | HX Stompなしで単体動作 |

> Seed3のhardware資料は更新されるため、Lesson 21開始時に公式datasheet / typical application circuitを再確認し、その時点で回路BOMをfreezeします。

## Phase 6 — 最終制作

| 回 | テーマ | 完成物 |
|---|---|---|
| 24 | Enclosure / solder / final validation | MINI DIGITAL DRIVE |

---

## 推奨順と分岐

### 推奨

```text
00〜14
  ↓
P15〜P24 Plugin Track
  ↓
Hardware 15〜24
```

メリット:

- お金を使う前に完成品を1つ得られる
- PCでDSPのbugを潰してから実機へ行ける
- 同じDSPが2つのplatformで動くことを体験できる

### 実機優先

```text
00〜14
  ↓
Hardware 15〜24
```

後からPlugin Trackへ戻れます。

### PCだけで完結

```text
00〜14
  ↓
P15〜P24
  ↓
修了
```

実機を買わなくても、C++ / DSP / real-time audio / plugin開発の成果物が残ります。

---

## コース全体の最終合格条件

- sample rate / block size / latencyを説明できる
- `float*` / AudioBufferがなぜ出てくるか説明できる
- `class`にする意味を説明できる
- audio callback / `processBlock()`内で避ける処理を説明できる
- 共通DSPをframework非依存で保てる
- 無音・clip・noise・crashを段階的に切り分けられる
- Plugin Trackを選んだ場合、parameter/state/threading/validationを説明できる
- Hardware Trackを選んだ場合、guitar signal / impedance / bias / GNDを説明できる
