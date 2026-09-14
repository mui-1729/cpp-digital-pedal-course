# Lesson 03 — 参照でsampleを直接書き換える

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

`ApplyGainInPlace(float& sample, float gain)`を作る。

## 必要なもの

PCのみ。

## 新しく使う知識

参照 `&` / `void` / in-place processing

## なぜ必要？

「値を返して代入」以外に、元の変数そのものを変更する書き方を理解します。C++のAPIを読む力にもつながります。

## Hands-on

1. `float sample = 0.25f;`を用意。
2. `void ApplyGainInPlace(float& sample, float gain)`を書く。
3. 関数内で`sample *= gain;`する。
4. 呼び出し前後の値を表示する。
5. `&`が「この変数への別名」として働くことを確認する。

## Challenge

- 戻り値を返すLesson 01版と、参照で変更する版の違いを文章で書く。
- どちらが常に優れているわけではない理由を考える。

## 合格条件

- `void`の意味を言える
- `float&`と`float`の違いをざっくり説明できる
- 関数を呼ぶだけで元のsampleが変わる理由が分かる



## 解説

### 値渡し

```cpp
void F(float x)
```

では、関数側の`x`は呼び出し元の値のcopyです。`x`を書き換えても元変数は変わりません。

### 参照渡し

```cpp
void F(float& x)
```

では`x`が呼び出し元変数の別名のように働きます。

```text
sample ─────┐
            ├─ 同じ値を指して扱う
x      ─────┘
```

`&`にはaddress取得など別の使い方もありますが、今は「関数引数の型に付いたら参照」という理解で十分です。

## よくあるミス

- `float&`をpointerと同じものだと思う
- `void`だから何も処理しない関数だと思う。`void`は「戻り値がない」だけ

## 確認問題

1. `void`は何を意味する？
2. 参照版はなぜ`sample = Apply...`という代入が不要？
3. 元の値を変更したくない関数に参照を使うなら何を考えるべき？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 03: process sample by reference"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
