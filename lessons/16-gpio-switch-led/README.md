# Lesson 16 — GPIOでボタンとLEDをつなぐ

**Phase:** 3-6: 実機

## 今日作るもの

物理ボタンを押したらLEDが点灯する。

## 必要なもの

Seed3 / breadboard / tactile switch / LED / resistor / jumper wire。

## 新しく使う知識

GPIO input/output / pull-up / active-low / debounceの考え方

## なぜ必要？

フットスイッチとLEDの原型です。Daisy公式GPIO tutorialもswitchをGNDへ落とし、internal pull-upを使う構成です。

## Hands-on

1. 電源OFFで配線。
2. switch: D0↔GND。
3. LED: D1→resistor→LED→GND（LED極性に注意）。
4. GPIOをINPUT/PULLUPとOUTPUTで初期化。
5. `Read()`結果が押下時falseになるため`!`で反転。
6. 連打/チャタリングの存在を観察。

## Challenge

- buttonを押すたびON/OFFがtoggleする状態変数を追加する。
- 後で`Switch` classのDebounceへ置き換える。

## 合格条件

- pull-upの意味を説明できる
- active-lowを理解した
- 電源OFFで配線変更する習慣がある

## Safety

LEDには電流制限抵抗を入れる。GPIOへ9Vを入れない。

## 解説

### Pull-up

input pinを何も接続しないと電圧が不定になります。internal pull-upで通常HIGHにし、switch押下時だけGNDへ落とします。

```text
not pressed → HIGH
pressed     → LOW
```

そのため人間の意味として`pressed=true`にしたければ`!Read()`で反転します。

### Chattering

mechanical switchは1回押しても短時間にON/OFFが揺れます。フットスイッチで1回押したのに2回toggleする原因になるため、debounceが必要です。

## よくあるミス

- LEDを抵抗なしでGPIOへ直結
- switchの4脚構造を誤解し同じ側だけ繋ぐ
- active-lowをbugだと思う

## 確認問題

1. pull-upの目的は？
2. debounceはなぜ必要？
3. 最終ペダルのどの部品に対応する？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 16: wire gpio switch and led"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
