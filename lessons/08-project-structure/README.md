# Lesson 08 — ヘッダとcppへ分割して小さなプロジェクトにする

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

`Distortion.h`, `Distortion.cpp`, `main.cpp`へ分割し、`make`でbuildする。

## 必要なもの

PCのみ。

## 新しく使う知識

header / implementation / include guard (`#pragma once`) / multiple translation units / Makefile

## なぜ必要？

実機プロジェクトは1ファイルでは終わりません。effect codeとhardware codeを分けておくと、PCでテストしたDSPをDaisyへ移植しやすくなります。

## Hands-on

1. starterの3ファイルを見る。
2. `Distortion.h`に宣言を書く。
3. `Distortion.cpp`に実装を書く。
4. `main.cpp`からincludeして利用する。
5. `make`でbuildする。

```bash
cd starter
make
./app
make clean
```

## Challenge

- `main.cpp`からDistortionの内部実装が見えなくても使える理由を説明する。
- headerにprivate memberが必要な理由を考える。

## 合格条件

- `.h`と`.cpp`の役割を説明できる
- `#include "Distortion.h"`が読める
- `make`で複数ファイルをbuildできる



## 解説

### declarationとdefinition

headerでは「このclass/functionが存在する」というinterfaceを宣言し、cpp側へ実装を分けます。

```text
main.cpp
   ↓ include
Distortion.h  ← interface
   ↑
Distortion.cpp ← implementation
```

### なぜ分ける？

最終的にhardware codeとDSP codeを分離するためです。PCで`Distortion.cpp`をテストし、Daisy側から同じheaderを使う設計に繋がります。

### Makefile

compile commandを毎回手入力せず、同じbuildを再現するための簡単な仕組みです。CMake等は後で必要になったら学べばよく、今は依存関係の感覚を優先します。

## よくあるミス

- headerにfunction implementationを重複して書いてlink error
- `.cpp`をcompile対象へ入れ忘れる
- `#include` pathの間違い

## 確認問題

1. `.h`は主に何を公開する？
2. `.cpp`へ分ける最大の利点は？
3. Makefileなしでもcompileはできる？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 08: split effect into files"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
