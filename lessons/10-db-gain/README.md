# Lesson 10 — dBとLinear Gainをつなぐ

**Phase:** 2: DSP基礎

## 今日作るもの

+6dB、0dB、-6dBをlinear倍率へ変換する。

## 必要なもの

PCのみ。

## 新しく使う知識

`std::pow` / `std::log10` / dB / linear amplitude

## なぜ必要？

音響機材はdB表記、DSP内部はlinear floatで扱うことが多いため、両者を行き来する必要があります。

## Hands-on

1. `DbToLinear(float db)`を書く。
2. 0dBが1.0になることを確認。
3. +6dBがおよそ2倍、-6dBがおよそ0.5倍になることを確認。
4. `LinearToDb()`も作り、往復させる。
5. 0以下のlinear値はlogできないことに注意する。

## Challenge

- +12dBをlinearへ。
- linear 0.25をdBへ。
- 「6dB=厳密に2倍ではなく近似」である理由を確認する。

## 合格条件

- 0dB=unity gainだと説明できる
- dBとlinearを同じ数値だと思わない
- conversion functionを自力で呼べる



## 解説

### なぜdB？

人間の聴感やaudio機器のlevelは非常に広い範囲を扱うため、対数表記のdBが便利です。一方、DSPのsampleへgainを掛けるときはlinear倍率が必要です。

amplitudeの変換は

```text
linear = 10^(dB/20)
```

です。

### unity

0dB = 1.0倍。つまり「levelを変えない」。

+6.0206dB ≈ 2倍、-6.0206dB ≈ 0.5倍です。

## よくあるミス

- power ratioの`10 log10`とamplitude ratioの`20 log10`を混ぜる
- 0dBを無音だと思う。digital level文脈の`-inf dB`が無音に対応

## 確認問題

1. 0dBは何倍？
2. -∞dBは何に近づく？
3. +6dBを毎段重ねるとheadroomはどうなる？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 10: convert db and linear gain"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
