# Lesson 01 — 関数でGainを作る

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

`ApplyGain(input, gain)`を作り、1つのsampleの音量を変える。

## 必要なもの

PCのみ。

## 新しく使う知識

関数 / 引数 / 戻り値 / `return` / `float`

## なぜ必要？

エフェクターの処理をmainから切り離し、「処理に名前を付ける」最初の一歩です。後の`Distortion::Process()`へ直結します。

## Hands-on

1. `starter/main.cpp`をcompileして現在の出力を見る。
2. TODO部分に次の仕様の関数を書く。
   - 関数名: `ApplyGain`
   - `float`を2つ受け取る
   - 掛け算した`float`を返す
3. `input=0.25f`, `gain=2.0f`で`0.5`になることを確認。
4. `gain`を3.0、0.5にも変えて結果を予想してから実行。

## Challenge

1. `input=-0.25f`ではどうなるか予想して確認する。
2. `ApplyGain()`を一度消して、見ずに書き直す。
3. `gain=0.0f`の意味を音量として説明する。

## 合格条件

- 関数を「処理をまとめて名前を付けたもの」と説明できる
- 引数と戻り値の役割を説明できる
- `float ApplyGain(float input, float gain)`を読める
- 自力で関数を一度書ける



## 解説

### 関数の4要素

```cpp
float ApplyGain(float input, float gain) {
    return input * gain;
}
```

- 最初の`float`: 戻り値の型
- `ApplyGain`: 関数名
- `(float input, float gain)`: 引数
- `return`: 呼び出し元へ結果を返す

`main()`も関数です。特別なのはprogram開始地点として使われる点です。

### なぜ`float`？

音声DSPではsampleを`-1.0〜1.0`付近の小数として扱うことが多いため、整数ではなくfloating pointが自然です。Daisyのaudio engineも32-bit floatを使います。

## よくあるミス

- `return`を書き忘れる
- 関数を`main()`の中に書こうとする
- `ApplyGain(input, gain);`を呼んだだけで結果を変数へ保存しない
- `0.25`と`0.25f`の違いを必要以上に怖がる。ここでは`f`を付けてfloat literalに統一する

## 確認問題

1. `ApplyGain(0.25f, 2.0f)`の戻り値は？
2. gain=1は音量として何を意味する？
3. gain=0は？
4. 関数にすると、main内へ直書きするより何が良い？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 01: add gain function"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
