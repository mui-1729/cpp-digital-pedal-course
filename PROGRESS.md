# Progress

## Phase 0

- [ ] 00 開発環境と信号経路

## Phase 1 — C++

- [ ] 01 関数 × Gain
- [ ] 02 配列 × Buffer
- [ ] 03 参照 × in-place
- [ ] 04 pointer × Buffer API
- [ ] 05 class × Gain
- [ ] 06 state × Distortion
- [ ] 07 const / enum × clip mode
- [ ] 08 header / cpp分割

## Phase 2 — DSP

- [ ] 09 sample rate
- [ ] 10 dB / linear
- [ ] 11 waveshaping
- [ ] 12 Tone filter
- [ ] 13 Delay
- [ ] 14 Mini Pedal Engine

### Branch Point

- [ ] PCだけで完成品を作りたい → Plugin Track
- [ ] 実機を先に触りたい → Hardware Track
- [ ] 推奨: Plugin Track → Hardware Track

---

## Plugin Track

- [ ] P15 JUCE / CMake / first Standalone
- [ ] P16 processBlock / passthrough
- [ ] P17 shared PedalEngine
- [ ] P18 parameters / automation
- [ ] P19 saturation / smoothing
- [ ] P20 GUI / attachments
- [ ] P21 state / preset / A-B
- [ ] P22 meters / threading
- [ ] P23 validation / sample rates / block sizes
- [ ] P24 VST3 + Standalone release candidate

### Plugin Finish Gate

- [ ] Standaloneが起動
- [ ] VST3がhostで読み込める
- [ ] state restore確認
- [ ] mono/stereo確認
- [ ] 44.1/48/96kHz確認
- [ ] 複数block size確認
- [ ] validation実行
- [ ] licence/release checklist確認

---

## Hardware Track Phase 3 — Daisy

### Gate A

- [ ] 実機へ進みたい
- [ ] Daisy Seed3購入内容を最新資料で確認

- [ ] 15 first flash
- [ ] 16 GPIO
- [ ] 17 ADC/POT
- [ ] 18 audio callback
- [ ] 19 shared PedalEngine port

## Phase 4 — Guitar

- [ ] 20 HX Stomp経由で実ギター

### Gate B

- [ ] DSPが実ギターで安定動作
- [ ] 最新Seed3 datasheet/typical circuit確認
- [ ] Audio circuit BOM freeze

## Phase 5 — Electronics

- [ ] 21 electronics foundation
- [ ] 22 breadboard audio I/O
- [ ] 23 power/noise/bypass

### Gate C

- [ ] breadboard版安定
- [ ] enclosure internal layout確認

## Phase 6

- [ ] 24 final pedal
