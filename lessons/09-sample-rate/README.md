# Lesson 09 — Sample Rateと「音＝大量の数値」を体感する

**Phase:** 2: DSP基礎

## 今日作るもの

48kHzで440Hzのsine waveを生成し、CSVへ書き出す。

## 必要なもの

PCのみ。CSVを表計算ソフトやPython等で可視化してもよい。

## 新しく使う知識

周波数 / sample rate / sine / `std::sin` / file output

## なぜ必要？

実音声を処理する前に、1秒の音が「48000個のfloat」になる感覚を作ります。

## Hands-on

1. sample rateを48000Hzにする。
2. 440Hzのsineを100 samplesだけ生成する。
3. `wave.csv`へ`index,value`を書き出す。
4. sample rateを24000に変えると式の何が変わるか見る。
5. 1 sampleの時間が`1 / sampleRate`秒だと理解する。

## Challenge

- 48000Hzで1秒ならsample数はいくつか。
- 48 samplesのblockなら理論上何秒分か計算してみる。

## 合格条件

- sample / sample rate / frequencyを混同しない
- 1秒のaudioが多数の数値列だと説明できる
- sine生成式の`i / sampleRate`部分の意味を言える



## 解説

### 48kHzとは

48kHzなら、1秒間を48000個のsampleで表します。

```text
0s                1s
|------------------|
48000 samples
```

440Hzのsineなら1秒に440周期です。各sample時刻`t`に対し`sine(2πft)`を計算すれば波形になります。

### sample rateとblock sizeは別

sample rateは「1秒あたりのsample数」。block sizeは「1回のcallbackでまとめて処理するsample数」。この区別はLesson 18で重要です。

## よくあるミス

- 48kHz=48 samplesだと思う
- 440Hzをsample rateだと思う
- integer divisionでtimeが0になり続けるため`float`へcastする

## 確認問題

1. 48kHzで0.5秒は何samples？
2. 48 samples/blockなら1 blockは何ms？
3. 440Hzは何を表す？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 09: generate sampled sine wave"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
