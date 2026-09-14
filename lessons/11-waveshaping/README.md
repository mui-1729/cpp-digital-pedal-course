# Lesson 11 — Hard ClipとSoft Clipを波形で比較する

**Phase:** 2: DSP基礎

## 今日作るもの

同じinput sineをHard/Soft Clipし、CSVで比較する。

## 必要なもの

PCのみ。

## 新しく使う知識

waveshaping / headroom / harmonic generationの入口

## なぜ必要？

Distortionは「歪みという名前の魔法」ではなく、sample値を非線形に変換する処理だと理解します。

## Hands-on

1. sineを生成する。
2. driveを掛ける。
3. Hard: `clamp`。
4. Soft: `tanh`。
5. `input,hard,soft`をCSVへ出す。
6. graphで頂点の形を見る。

## Challenge

- drive 1, 2, 10を比較する。
- output volumeを後段に置く理由を考える。
- digital clippingと「意図したwaveshaper」を区別して説明する。

## 合格条件

- hard/soft clipの違いを波形で説明できる
- driveの位置がwaveshaper前だと分かる
- headroomという言葉の意味をざっくり言える



## 解説

### Waveshaper

input sampleを別の値へ写像する関数です。

```text
input → f(x) → output
```

Distortionの最小モデルはこれだけです。

### 意図した歪み vs 事故のclip

algorithm内のclipは設計した音色。一方ADCやDAC、後段機器で許容levelを超えて起こるclipは、制御できないことがあります。後者を「歪んだから成功」と扱わないことが重要です。

### aliasingの予告

nonlinear processingは高いharmonicsを作ります。sample rateの上限を超える成分はaliasingとして折り返します。oversamplingは発展編で扱いますが、存在はここで覚えます。

## よくあるミス

- driveを掛けずinputそのままclipして変化が少ない
- clip後のlevel補正を忘れ、単に大きい方を「良い音」と判断する

## 確認問題

1. waveshaperはmemoryを必ず必要とする？
2. nonlinear processingでharmonicsが増えると何が起こり得る？
3. A/B比較でoutput levelを揃える意味は？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 11: compare hard and soft clipping"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
