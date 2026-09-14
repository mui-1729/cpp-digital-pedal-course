# Lesson 04 — ポインタでBufferを関数へ渡す

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

`ProcessBuffer(float* buffer, size_t size, float gain)`で配列全体を処理する。

## 必要なもの

PCのみ。

## 新しく使う知識

pointer `*` / address / array decay / buffer + size API

## なぜ必要？

DaisyのAudio callbackではbufferがpointer系の型として渡されます。ここで「*を暗記」せず、bufferの先頭位置を渡している感覚を作ります。

## Hands-on

1. `ProcessBuffer(float* buffer, std::size_t size, float gain)`を作る。
2. 関数内で`buffer[i]`を更新する。
3. `main`の配列を関数へ渡す。
4. `&buffer[0]`と`buffer`がこの場面でほぼ同じ先頭位置を表すことを確認する。
5. sizeを一緒に渡す必要性を理解する。

## Challenge

- `size`を関数へ渡さなかった場合、関数は何個処理すべきか分かるか考える。
- 読み取り専用bufferなら`const float*`にできる理由を調べて一言で説明する。

## 合格条件

- pointerを「アドレスを持つ変数」と説明できる
- `float* buffer`を見て完全に怖くなくなる
- pointerだけでは配列長が分からないことを理解する



## 解説

### pointerを最小限で理解する

pointerは「memory上の位置(address)を持つ値」です。

```cpp
float* buffer
```

は「floatが置かれている場所を指すpointer」。配列を関数へ渡すと、その先頭要素を指すpointerとして扱われる場面が多くあります。

```cpp
buffer[i]
```

と書けば、pointer演算を直接書かなくてもi番目へアクセスできます。

### pointerだけでは長さが分からない

`float*`から「何個のfloatがあるか」は原則分かりません。そのため、audio APIでは

```cpp
(float* buffer, size_t size)
```

のようにpointerと要素数をセットで扱う設計が頻出します。

## よくあるミス

- `*`を「掛け算」としか認識できなくなる。型の位置ではpointer宣言
- sizeより先へアクセスする
- null pointerや寿命切れなど高度な話へ一気に広げすぎる。今はbufferを読むために必要な範囲でよい

## 確認問題

1. `float* buffer`は何を持つ？
2. `size`を別に渡す理由は？
3. Daisy callbackでpointer系bufferが自然な理由を一言で説明すると？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 04: process pointer buffer"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
