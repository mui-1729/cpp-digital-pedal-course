# Lesson 13 — Circular BufferでDelayを作る

**Phase:** 2: DSP基礎

## 今日作るもの

過去のsampleを保存し、少し後で読み出すDelayを作る。

## 必要なもの

PCのみ。

## 新しく使う知識

`std::vector` / circular buffer / write index / feedback

## なぜ必要？

Delayは「メモリに音を保存する」effectです。配列・index・stateが一気につながります。

## Hands-on

1. `Delay` classを作る。
2. constructorで必要sample数だけbufferを確保する。
3. 現在の`writeIndex_`にinputを書く。
4. 同じ場所に残っていた古い値をdelay sampleとして使う。
5. indexが末尾へ来たら0へ戻す。
6. feedbackを0.3程度で追加する。

## Challenge

- delay 100msを48kHzでは何samples保存するか計算する。
- feedbackを1以上にすると何が起こり得るか考える。
- Daisy callback内で`vector`をresizeしてはいけない理由を後のLesson 18に備えて考える。

## 合格条件

- circular bufferのindexが周回する理由を説明できる
- delay timeをsample数へ変換できる
- dynamic allocationを初期化時だけにする発想を持てる



## 解説

### Delayの本体はmemory

100ms前の音を出したければ、その分のsampleを保存しておく必要があります。

48kHzなら

```text
48000 × 0.1 = 4800 samples
```

### Circular Buffer

bufferの終端まで行ったら先頭へ戻り、古いsampleを上書きします。無限にmemoryを増やす必要がありません。

### Real-timeでのallocation

`std::vector`は学習しやすいためPC版で使いますが、Daisyのaudio callback中にresize/newを行うのは避けます。必要memoryは初期化時に確保します。

## よくあるミス

- delaySeconds→samplesの変換を忘れる
- indexを戻さず範囲外アクセス
- feedback 1以上で増幅し続ける可能性を無視する

## 確認問題

1. 250ms @ 48kHzは何samples？
2. circular bufferの利点は？
3. callback中のdynamic allocationを避けたい理由は？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 13: build circular buffer delay"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
