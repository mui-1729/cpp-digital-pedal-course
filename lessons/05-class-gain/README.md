# Lesson 05 — classでGainを「部品」にする

**Phase:** 1: C++基礎 × エフェクター

## 今日作るもの

`Gain gain; gain.Process(sample);`という形にする。

## 必要なもの

PCのみ。

## 新しく使う知識

class / object / public / member function

## なぜ必要？

今後Distortion/Tone/Delayを並べるため、処理を「部品」として扱える形にします。

## Hands-on

1. `class Gain`を作る。
2. publicに`float Process(float input, float gain)`を作る。
3. `main`で`Gain gainEffect;`というobjectを作る。
4. `gainEffect.Process(0.25f, 2.0f)`を呼ぶ。
5. 関数だけの書き方と比較する。

## Challenge

- objectを2個作っても同じ結果になることを確認する。
- classは「データと処理をまとめられる設計図」と説明してみる。

## 合格条件

- classとobjectの違いをざっくり言える
- `.`でmember functionを呼べる
- なぜeffectをclassにするのか説明できる



## 解説

### classは「機能のまとまり」

関数だけでもGainは作れます。classを使う価値が出るのは、effectがparameterやstateを持ち始めるときです。

```cpp
Gain effect;
effect.Process(sample, 2.0f);
```

この`effect`がobjectです。

### classとobject

- class: 設計図
- object: その設計図から作られた実体

この比喩は完全ではありませんが、初学段階では十分です。

## よくあるミス

- classを書いただけでobjectが自動生成されると思う
- `Gain.Process()`と書く。通常はobjectの`gain.Process()`

## 確認問題

1. classとobjectの違いは？
2. `Distortion`, `Tone`, `Delay`をclassにすると何が整理しやすい？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 05: introduce gain class"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
