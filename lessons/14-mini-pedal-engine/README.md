# Lesson 14 — PC版Mini Pedal Engineを完成させる

**Phase:** 2: DSP基礎

## 今日作るもの

`Distortion → Tone → Level`を1つの`PedalEngine`としてまとめる。

## 必要なもの

PCのみ。**ここまでは買い物不要。**

## 新しく使う知識

effect chain / LFO / parameter smoothingの入口 / `assert`による簡単なテスト

## なぜ必要？

Lesson 19で、このDSP部分をほぼそのままDaisyのaudio callbackへ持っていきます。Hardware依存コードとDSPを分離するのが重要です。

## Hands-on

1. starterの`PedalEngine`を完成させる。
2. `SetDrive`, `SetTone`, `SetLevel`を実装。
3. `Process(sample)`の順序を`Distortion→Tone→Level`にする。
4. `main.cpp`でsample列を処理する。
5. `tests.cpp`をbuildし、outputがfiniteか、level=0で0になるかを確認する。

```bash
cd solution
make
./app
make test
```

## Challenge

- effect順をTone→Distortionへ変えて数値差を確認する。
- なぜhardware pinやGPIO codeを`PedalEngine`内へ入れない方がよいか説明する。

## 合格条件

- DSPとhardware層を分離する理由が分かる
- 自分でeffect chainを追える
- テストで最低限の壊れ方を検出できる
- **ここまで終えたらPurchase Gate Aへ進んでよい**



## 解説

### Architecture

ここまで作ったDSPを1つにまとめます。

```text
input
  ↓
Distortion
  ↓
Tone
  ↓
Level
  ↓
output
```

`PedalEngine`はaudio hardwareを知りません。`float`を受け、`float`を返すだけです。この純粋さがLesson 19の移植を簡単にします。

### Parameter mapping

物理POTは0〜1ですが、driveは1〜10、toneは300〜8000Hzなど、意味のあるrangeへ変換します。

### Test

音を聴くだけでは毎回の変更が壊れていないか判断しづらいため、最低限の数値testを残します。将来「音は好み」でも、「NaNが出ない」「muteなら0」は自動確認できます。

## よくあるミス

- GPIOやDaisy APIを`PedalEngine`へ入れてPCテスト不能にする
- effect順序を無意識に変える
- parameter rangeを無制限にして不安定化する

## 確認問題

1. hardware-independent DSPにする利点は？
2. `Process()`内のeffect順序を変えると同じ音になる？
3. 自動testできる性質と、耳で判断する性質を1つずつ挙げる。

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 14: complete desktop pedal engine"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
