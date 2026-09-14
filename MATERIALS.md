# 必要物・買い物計画

## 基本方針

1. **必要になる前に買わない**
2. 借りられる工具は借りる
3. 消耗品・自分の制作物になる部品を優先して買う
4. ハードウェア回路部品は、最新公式回路を確認してから確定する
5. 値段は変動するので、教材内価格は目安に留める

## 今〜Lesson 14

追加購入: **0円**

必要:

- Windows PC
- WSL Ubuntu
- VS Code
- g++
- Git

すでに持っているギターやHX Stompは、まだ使わなくても進められます。

## Purchase Gate A — Lesson 15直前

### 購入推奨

| 品物 | 数 | 用途 | 備考 |
|---|---:|---|---|
| Daisy Seed3 | 1 | DSP本体 | その時点の公式在庫/価格を再確認 |
| Breadboard（大きめ） | 1 | 配線 | Seed3 + pot + switchを載せられるもの |
| Jumper wire | 1 set | 配線 | male-male中心 |
| LED | 3〜5 | 状態表示 | 色は任意 |
| 抵抗セット | 1 | LED/回路 | まず汎用セットでよい |
| Tactile switch | 2〜3 | GPIO | breadboard向け |
| 10kΩ linear pot | 3 | GAIN/TONE/LEVEL | Bカーブ相当 |
| USB-C data cable | 1 | 書込/電源 | 充電専用ケーブル不可 |

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

## Lesson 20

手持ち機材を活用します。

- Guitar
- HX Stomp
- 1/4 inch cable
- Daisy setup
- headphones / amp

HX Stompを一時的にinstrument↔lineの橋渡しとして使います。

## Purchase Gate B — Lesson 21〜23

ここで初めて「単体のギター用入出力回路」を作ります。

### 買う前に必ず行うこと

- Seed3の最新版datasheetを確認
- 公式Typical Application Circuitを確認
- errata / current community announcementを確認
- 使用するop-amp / supply voltage / bias circuitを決める
- BOMを`hardware/BOM-FROZEN.md`としてfreezeする

Seed3関連資料は2026年にも更新・訂正があったため、教材作成時に固定した値を未来まで盲信しない設計です。

### 想定カテゴリー

- dual op-amp
- resistors
- capacitors
- ferrite / filtering parts（必要に応じて）
- audio jack temporary breakout
- 9V supply related parts

## Purchase Gate C — Lesson 24

最終ペダル化。

- Enclosure（最初は余裕あるサイズ推奨）
- 1/4 inch TS jack ×2
- 3PDTまたは採用するbypass方式のswitch
- Pot ×3
- Knob ×3
- LED + bezel
- DC jack
- wire
- heat-shrink tubing
- perfboard / carrier PCB
- standoff / hardware

## 工具

### 借りられれば買わなくてよい

- temperature-controlled soldering iron
- solder
- solder wick / sucker
- drill / step drill
- multimeter
- vise

### 自分で持っていると便利

- cheap multimeter
- small nipper
- wire stripper

## 予算の考え方

総額を一括で考えません。

```text
Phase 0-2: 0円
    ↓ 続けたい
Phase 3: Daisy + 基本部品
    ↓ 実ギターで楽しい
Phase 5: Audio回路部品
    ↓ 単体化したい
Phase 6: ケース・switch・仕上げ
```

工具を借りられる場合、総コストをかなり下げられます。
