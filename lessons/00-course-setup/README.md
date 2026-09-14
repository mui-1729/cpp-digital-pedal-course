# Lesson 00 — 開発環境と「音の流れ」をつかむ

**Phase:** 0: 準備

## 今日作るもの

自分のPCでC++をcompileして実行し、最終ペダルの信号経路を紙かREADMEに書ける状態にする。

## 必要なもの

PC / WSL / VS Code / g++ / Git。追加購入なし。

## 新しく使う知識

compile / executable / source file / Git checkpoint

## なぜ必要？

paizaではcompile環境を隠してくれますが、実機開発では「source → compiler → binary → hardware」の流れを自分で扱います。

## Hands-on

1. `starter/main.cpp`を開く。
2. WSLで次を実行する。

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic starter/main.cpp -o app
./app
```

3. 出力が `mini pedal course start` ならOK。
4. `README.md`の最終信号経路を、自分の言葉でノートに書く。
5. `git status` を実行して何が変更されたか確認する。

## Challenge

`starter/main.cpp`の表示を自分の好きなペダル名に変える。

例: `MY DIGITAL DRIVE`。

## 合格条件

- `g++`でcompileできる
- `./app`で実行できる
- source codeと実行ファイルの違いを言える
- 「ギター→入力→DSP→出力→アンプ」の順を言える



## 解説

### compileとは

C++の`main.cpp`は、そのままCPUが実行するものではありません。`g++`がsource codeを読み、PCで実行できるbinaryへ変換します。

```text
main.cpp → g++ → app → 実行
```

Daisyでも考え方は同じですが、出力先がPCではなくARM microcontroller向けfirmwareになります。

### この教材でGitを使う理由

Gitを覚えること自体が目的ではありません。各Lesson終了時の「動く状態」を保存して、次の回で壊しても戻せるようにします。

## よくあるミス

- WSLではなくPowerShell側でLinux pathをそのまま使う
- compileした後にsourceを変更したのに、再compileせず古い`app`を実行する
- `app`と`main.cpp`を同じものだと思う

## 確認問題

1. `main.cpp`を変更した後、なぜ再compileが必要？
2. `-Wall -Wextra`は何のため？
3. 最終ペダルで「software」と「hardware」の境目はどこ？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 00: setup course"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
