# Troubleshooting

## 原則

実機では「音が出ない」だけでは原因が広すぎます。
上流から一つずつ確認します。

```text
電源
 ↓
USB / Flash
 ↓
GPIO
 ↓
ADC / control
 ↓
Audio passthrough
 ↓
DSP
 ↓
Analog input/output circuit
 ↓
HX / amp routing
```

## PC C++

### compile error

1. 一番上のerrorから読む
2. 行番号を見る
3. `;`, `{}`, `}` を確認
4. 型を見る
5. warningも残さない

### 値がおかしい

`std::cout`で途中値を出す。

```cpp
std::cout << "input=" << input << " output=" << output << '\n';
```

## Daisy

### Flashできない

- data対応USB cableか
- boot modeに入っているか
- PCがdeviceを認識しているか
- target / boardが正しいか

### LEDは動くがPOTが読めない

- 3.3V / GND / wiperの3本を確認
- ADC pinを確認
- common groundを確認
- multimeterでwiper voltageを測る

### Audio passthroughで無音

DSPを全て外して、まず

```cpp
out[0][i] = in[0][i];
```

だけに戻す。

それでも無音ならDSPロジックではない。

### ノイズ/途切れ

- callback内でprintしていないか
- dynamic allocationしていないか
- blocking I/Oしていないか
- block size / sample rateを確認
- CPU負荷の高い処理を一旦外す

## Analog circuit

### 完全に無音

- power
- GND
- jack wiring
- op-amp orientation
- bias/reference
- AC coupling capacitor orientation（極性部品の場合）

### 音量が小さい

- guitar→bufferのimpedance
- divider / gain
- HX Stomp Send/Return level
- Daisy input/output level

### ひどく歪む

「Distortion algorithmが効いている」と決めつけない。

1. analog input stage
2. ADC full scale
3. DSP
4. DAC/output stage
5. HX return

のどこでclipしたか切り分ける。
