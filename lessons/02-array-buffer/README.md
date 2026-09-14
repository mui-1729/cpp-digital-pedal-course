# Lesson 02 — 配列とforでAudio Bufferを処理する

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

1個のsampleではなく、8個のsampleをまとめてGain処理する。

## 必要なもの

PCのみ。

## 新しく使う知識

配列 / index / `size_t` / for loop

## なぜ必要？

実際のリアルタイムaudioは1 sampleずつではなくblock/bufferで渡されることが多く、Daisyのcallbackもbufferをforで処理します。

## Hands-on

1. 配列`buffer`の8個の値を確認する。
2. `for`で0〜7を順に処理する。
3. Lesson 01の`ApplyGain()`を各sampleへ適用する。
4. before / afterを表示する。
5. `std::size_t`が「要素数やindexに使う符号なし整数型」だと把握する。

## Challenge

- gainを0.5fに変更する。
- `buffer`へ値を2つ追加し、`kSize`も合わせる。
- indexを1から始めると何が起きるか、実行前に考える（危険なアクセスはsolutionでは行わない）。

## 合格条件

- `buffer[i]`がi番目の要素だと説明できる
- forで全要素を処理できる
- なぜaudio処理でforが頻出するか説明できる



## 解説

### 1 sampleからbufferへ

Lesson 01では一瞬の値だけを処理しました。しかしデジタル音声はsampleの連続です。

```text
0.10, 0.20, 0.40, -0.30, ...
```

配列はこの「並んだ値」を扱う最初の道具です。

### indexは0から

```cpp
buffer[0]  // 最初
buffer[1]  // 2番目
```

8要素なら有効なのは0〜7です。`buffer[8]`は範囲外です。C++は常に安全確認してくれるわけではないので、自分で境界を守る必要があります。

### `size_t`

要素数やindexには`std::size_t`がよく使われます。後のDaisy callbackにも`size_t size`がそのまま登場します。

## よくあるミス

- `i <= kSize`として1回多く回す
- 0始まりを忘れる
- gain処理を1要素だけに行う

## 確認問題

1. 8要素の最後のindexは？
2. `i < kSize`にする理由は？
3. 実音声でbufferが1000回以上繰り返し渡されても、同じfor構造が使えるのはなぜ？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 02: process audio buffer"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
