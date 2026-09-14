# Lesson 07 — const・constexpr・enum classでモードを安全に表す

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

Hard ClipとSoft Clipを切り替えられるDistortionを作る。

## 必要なもの

PCのみ。

## 新しく使う知識

`const` / `constexpr` / `enum class` / `<cmath>`

## なぜ必要？

「0ならhard、1ならsoft」のようなmagic numberを減らし、読めるコードにします。固定値と変更可能なparameterも区別します。

## Hands-on

1. `enum class ClipMode { Hard, Soft };`を作る。
2. `SetMode()`でmodeを保持する。
3. Hardは`std::clamp`、Softは`std::tanh`。
4. `const float driven`の意味を確認。
5. `constexpr float kMinDrive`などを作る。

## Challenge

- `mode_ == ClipMode::Hard`を読めるようにする。
- `const`と`constexpr`の違いを「実行中に変えない」「compile時に確定できる値」という粒度で説明する。

## 合格条件

- magic numberをenumへ置き換える理由が分かる
- `const`を見て「変更しない値」と読める
- HardとSoftの数値的な違いを確認できる



## 解説

### `const`

その変数を以後変更しない意図をcompilerにも伝えます。

```cpp
const float driven = input * drive_;
```

### `constexpr`

compile時に値を確定できる定数に使います。固定のπや最大値などに向いています。

### `enum class`

```cpp
enum class ClipMode { Hard, Soft };
```

`0`, `1`の意味を覚えるより、名前で意図を表せます。

### Soft Clip

`tanh`は入力が大きくなるほど滑らかに±1へ近づきます。hard clipより角が丸いtransfer curveです。

## よくあるミス

- `ClipMode::Hard`の`::`を忘れる
- `const`を「絶対どこでも変わらない」と一般化しすぎる。対象の変数/関数文脈を見る

## 確認問題

1. magic numberをenumへ変える利点は？
2. hardとsoftはどちらもnonlinearか？
3. `tanh(0)`はおよそいくつ？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 07: add clipping modes"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
