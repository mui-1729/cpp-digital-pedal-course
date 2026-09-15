# 必要物・買い物計画

## 基本方針

1. **必要になる前に買わない**
2. 借りられる工具は借りる
3. ソフトウェアだけで学べる区間を先に終える
4. ハードウェア回路部品は最新公式回路を確認してから確定する
5. 値段は変動するので教材内価格は目安に留める

---

## Lesson 00〜14

追加購入: **0円**

必要:

- Windows PC
- WSL Ubuntu
- VS Code
- g++
- Git

ギター/HX Stompはなくても進められます。

---

## Plugin Track P15〜P24

追加ハードウェア: **0円**

必要software:

- Windows native C++ toolchain
- CMake
- Git
- JUCE（CMakeでpinしたversionを取得）
- Standalone target

任意:

- DAW / VST3 host
- pluginval
- headphones
- HX StompをUSB audio interfaceとして使う
- ギター

### ギターがない日の代替

- `tools/generate_test_audio.py`で生成するsine/sweep/transient
- 自分で事前録音したclean guitar WAV
- DAW/hostに読み込める任意の権利クリアな音源

`test-audio/README.md`を参照。

---

# Hardware Track

## Purchase Gate A — Hardware 15直前

### 購入推奨

| 品物 | 数 | 用途 | 備考 |
|---|---:|---|---|
| Daisy Seed3 | 1 | DSP本体 | 購入日に公式在庫/価格を再確認 |
| Breadboard（大きめ） | 1 | 配線 | Seed3 + pot + switch |
| Jumper wire | 1 set | 配線 | male-male中心 |
| LED | 3〜5 | 状態表示 | 色任意 |
| 抵抗セット | 1 | LED/回路 | 汎用セット |
| Tactile switch | 2〜3 | GPIO | breadboard向け |
| 10kΩ linear pot | 3 | GAIN/TONE/LEVEL | Bカーブ相当 |
| USB-C data cable | 1 | 書込/電源 | 充電専用不可 |

### 借りられるなら購入不要

- Digital multimeter
- ニッパー
- ラジオペンチ
- ワイヤーストリッパー

### まだ不要

- オシロスコープ
- PCB
- ケース
- フットスイッチ
- はんだごて
- 高価なAudio Analyzer

## Hardware 20

手持ち機材を活用可能:

- Guitar
- HX Stomp
- 1/4 inch cable
- Daisy setup
- headphones / amp

HX Stompを一時的にinstrument↔lineの橋渡しとして使います。

## Purchase Gate B — Hardware 21〜23

単体のギター用入出力回路を作ります。

買う前に:

- Seed3最新版datasheet確認
- 公式Typical Application Circuit確認
- errata / current announcement確認
- op-amp / supply / bias決定
- `hardware/BOM-FROZEN.md`としてfreeze

想定カテゴリー:

- dual op-amp
- resistors
- capacitors
- filtering parts
- audio jack breakout
- power related parts

## Purchase Gate C — Hardware 24

- Enclosure
- 1/4 inch TS jack ×2
- bypass switch
- Pot / knob
- LED + bezel
- DC jack
- wire
- heat-shrink tubing
- perfboard / carrier PCB
- standoff / hardware

## 工具

借りられれば買わなくてよい:

- temperature-controlled soldering iron
- solder
- solder wick / sucker
- drill / step drill
- multimeter
- vise

## お金を使う順番

```text
00〜14                  0円
  ↓
P15〜P24 Plugin Track   0円（既存PC前提）
  ↓ 実物にしたい
Hardware 15〜20         Daisy + 基本部品
  ↓
Hardware 21〜23         Audio回路
  ↓
Hardware 24             ケース・仕上げ
```
