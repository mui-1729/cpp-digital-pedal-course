# Lesson 15 — Daisy Seed3へ初めてFlashする

**Phase:** 3-6: 実機

## 今日作るもの

Seed3のonboard LEDを点滅させる。

## 必要なもの

Daisy Seed3 / USB-C data cable / PC。ここがPurchase Gate Aです。

## 新しく使う知識

cross compile / firmware / bootloader / flash / `DaisySeed`

## なぜ必要？

PCではOS上で実行していましたが、ここからはARM向けfirmwareをbuildしてmicrocontrollerへ書き込みます。

## Hands-on

1. **作業開始日に**Daisy公式Development EnvironmentとCreate New Project手順を再確認する。
2. libDaisy/examplesをbuildして環境確認。
3. Seed targetの新規projectを作る。
4. `solution/main.cpp`相当のBlinkを書き込む。
5. LEDが点滅したら、delay値を変更する。
6. 実際に使ったtoolchain/libDaisy commitを`HARDWARE-VERSIONS.md`へ記録する。

## Challenge

- blink intervalを半分にする。
- 「PCのexe」と「Seed3 firmware」の違いを言葉で説明する。

## 合格条件

- 自分でbuild→flash→resetできる
- USB cableがdata対応か判断できる
- versionを記録した

## Version gate

Seed3/libDaisyは更新されるため、コマンドを教材だけで固定しません。作業日に公式手順をsource of truthとして確認します。

## 解説

### Cross compile

PCのx86-64向けではなく、DaisyのSTM32H7向けmachine codeを生成します。sourceがC++でも、target CPUが違えばbinaryは別です。

### Versionを記録する理由

embedded環境はtoolchain、library、board revisionの組み合わせで挙動が変わります。「昔の自分のPCでは動いた」を避けるため、最初にversion logを残します。

## よくあるミス

- 充電専用USB cableで認識されない
- BOOT/RESET手順を混同する
- 古いtutorialと現在のofficial setupを混ぜる

## 確認問題

1. なぜPC用`app`をSeed3へcopyするだけでは動かない？
2. version logに最低3つ何を残す？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 15: first seed3 flash"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
