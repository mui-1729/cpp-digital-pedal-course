# Lesson 12 — 状態を持つ1-pole Low-passでToneを作る

**Phase:** 2: DSP基礎

## 今日作るもの

前回出力を覚えるLow-pass filterをclassで実装する。

## 必要なもの

PCのみ。

## 新しく使う知識

filter / cutoff / state / exponential coefficient

## なぜ必要？

歪み後の高域量を調整する簡単なToneの土台です。同時に「現在sampleだけで決まらないDSP」を初めて作ります。

## Hands-on

1. `LowPass` classを作る。
2. `SetCutoff(cutoff, sampleRate)`で係数を計算。
3. `Process(input)`で`state_`を更新する。
4. inputにstep signalを入れて出力を見る。
5. cutoffを500Hzと5000Hzで比較する。

## Challenge

- `state_`を毎回0に戻すとfilterにならない理由を説明する。
- cutoffが高いほど変化を速く追従することを確認する。

## 合格条件

- filterがstateful DSPだと説明できる
- `state_`が前回までの情報を持つことを理解する
- cutoffとsampleRateの両方が係数に必要だと分かる



## 解説

### Filterは過去を覚える

今回の式は

```cpp
state_ += alpha_ * (input - state_);
```

です。`state_`が前回までの出力を保持するため、現在inputだけではoutputが決まりません。

### cutoff

低いcutoffでは急な変化をゆっくり追います。高いcutoffではinputへ速く追従します。Distortion後に置けば、高域harmonicsの量をある程度調整できます。

### sample rate依存

同じ係数を44.1kHzと192kHzで使えば時間的挙動が変わります。そこでsample rateを使って係数を計算します。

## よくあるミス

- `state_`をlocal variableにして毎回0へ戻す
- cutoffをNyquistを大きく超えて無制限にする
- tone knobとcutoff Hzを同じものだと思う。knob 0〜1をHzへmappingしている

## 確認問題

1. なぜfilter classはstateを持つ？
2. sample rateが変わると係数再計算が必要なのはなぜ？
3. Distortion前後でfilterの音が変わるのはなぜ？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 12: build one pole tone filter"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
