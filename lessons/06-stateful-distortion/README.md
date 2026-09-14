# Lesson 06 — 状態を持つDistortion class

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

DRIVE値をclass内部に保持するDistortionを作る。

## 必要なもの

PCのみ。

## 新しく使う知識

private member / setter / state / `std::clamp`

## なぜ必要？

物理ノブは毎sample引数で渡すより、effectのparameterとして保持する設計が自然です。Filter/Delayではさらに「前回のsample」もstateになります。

## Hands-on

1. `drive_`をprivate memberとして持つ。
2. `SetDrive(float)`で値を設定する。
3. `Process(float)`で`input * drive_`を計算する。
4. -1〜1にhard clipする。
5. drive 1, 2, 5で出力を比較する。

## Challenge

- `input=0.4f`のときdrive=1,2,5の出力を予想する。
- `input=-0.4f`でも対称になるか確認。

## 合格条件

- stateという言葉を「objectが覚えている値」と説明できる
- privateにする理由を説明できる
- hard clippingが何をしているか数値で説明できる



## 解説

### state

`drive_`は呼び出しが終わってもobject内に残ります。これがstateです。

```cpp
Distortion d;
d.SetDrive(5.0f);
d.Process(...);  // drive=5を覚えている
```

### private

`drive_`を外部から好き勝手に変更させず、`SetDrive()`という入口を通すと、後で範囲制限や変換を追加しやすくなります。

### Hard Clip

```text
1.4 → 1.0
0.7 → 0.7
-1.3 → -1.0
```

一定範囲を超えた値を切ります。これは意図したnonlinear processingです。

## よくあるミス

- driveを毎Process呼び出しで初期値へ戻す
- clip後ではなくclip前を出力してしまう
- `private`は「触れないから邪魔」と思う。interfaceを明確にするためのもの

## 確認問題

1. stateとは？
2. drive=5, input=0.4のclip前の値は？
3. hard clip後は？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 06: add stateful distortion"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
