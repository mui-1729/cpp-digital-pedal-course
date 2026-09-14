# Lesson 17 — ADCで物理ノブを読む

**Phase:** 3-6: 実機

## 今日作るもの

POTを回すと0.0〜1.0の値が変化し、LED blink速度または仮parameterが変わる。

## 必要なもの

Seed3 / breadboard / 10kΩ linear pot / jumper wire / multimeter推奨。

## 新しく使う知識

ADC / 0〜3.3V / `GetFloat()` / parameter mapping / smoothing

## なぜ必要？

最終ペダルのGAIN/TONE/LEVELは全て「物理電圧→ADC→float parameter」になります。

## Hands-on

1. POT端子を3.3V_A / GND / A0(wiper)へ接続。
2. 通電前にwiperがrailへ短絡していないか確認。
3. `AdcChannelConfig`をA0へ。
4. `hw.adc.GetFloat(0)`で0〜1を読む。
5. serial/logまたはLEDの挙動へmapping。
6. 値が細かく揺れることを観察し、1-pole smoothingを追加する。

## Challenge

- normalized 0〜1をdrive 1〜10へmapする式を作る。
- 3個のPOTへ増やす際に`enum`でchannel名を付ける。

## 合格条件

- ADCとaudio ADCを混同しない
- 0〜3.3V範囲を守れる
- 0〜1を任意parameter rangeへmapできる

## Safety

通常のDaisy ADC inputは0〜3.3Vを想定。9VをPOT railへ使わない。

## 解説

### POTは可変の分圧器

両端を3.3V/GNDへ、中点(wiper)をADCへ繋ぐと、回した位置に応じて0〜3.3Vが得られます。ADCがこれを数値へ変えます。

### Normalized parameter

`GetFloat()`の0〜1を、そのままDSPへ入れるのではなく目的rangeへmappingします。

```text
pot 0.0 → drive 1
pot 1.0 → drive 10
```

例: `drive = 1 + pot * 9`。

### Smoothing

POT/ADC値は微小に揺れます。parameterを急に変更するとzipper noise等につながるため、滑らかに追従させます。

## よくあるミス

- POTへ9Vを接続
- wiperと端子を間違える
- smoothingをaudio sampleへ過剰に適用し別のfilterにしてしまう

## 確認問題

1. 0.5のPOTをdrive 1〜10へlinear mappingするといくつ？
2. ADCとaudio codecのADCは用途がどう違う？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 17: read potentiometer with adc"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
