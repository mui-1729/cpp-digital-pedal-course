# Lesson 23 — 電源・ノイズ・Bypass・故障切り分け

**Phase:** 3-6: 実機

## 今日作るもの

USBだけの実験から、ペダルとして独立するための電源・bypass・noise設計を確認する。

## 必要なもの

Lesson 22 circuit / footswitch prototype or tactile switch / LED / power parts / multimeter。

## 新しく使う知識

power filtering / ground / decoupling / bypass state / fail-safe thinking / noise debugging

## なぜ必要？

音が出るだけではstage-readyではありません。power noise、起動時挙動、bypass、配線故障時の切り分けが必要です。

## Hands-on

1. current power pathを図にする。
2. 9V→必要railへの変換/保護を最新版公式回路と照合。
3. analog/digital groundの接続方針を確認。
4. bypass方式を決める（mechanical true bypass / relay等は発展）。
5. footswitch inputはまずGPIO logicとして実装。
6. power on/offを繰り返し異常音がないか小音量で確認。
7. troubleshooting treeを使い、意図的に1本外したfaultを安全に切り分ける。

## Challenge

- noisy USB電源/別電源など条件差を記録する（安全範囲内）。
- LED switchingがaudioへnoiseを載せないか観察する。

## 合格条件

- power pathを説明できる
- bypassのsignal pathを説明できる
- 「音が出ない」を層別に切り分けられる
- enclosureへ移す前のbreadboard版が安定動作する

## Go/No-Go

Breadboard版が不安定なままケースへ移さない。ケース化はデバッグを難しくします。

## 解説

### Prototypeから製品らしい挙動へ

breadboardで一度音が出ても、power cycle、switch操作、LED、noiseなどで問題が出ます。ここで「安定動作」を定義します。

### Noise sourceを層で考える

- power supply
- reference/bias
- grounding/layout
- digital callback underrun
- external cable/routing

順に切り分ければ、闇雲にcapacitorを足す必要がありません。

### Bypass

初号機はまずsoftware/electrical controlの理解を優先し、true bypass方式の高度な設計は必要性に応じて選びます。方式を選ぶ前に、signal pathを図で説明できることを条件にします。

## よくあるミス

- noise原因を全部GNDのせいにする
- breadboardで不安定なのにケースへ入れて解決すると期待する

## 確認問題

1. LEDは動くが無音なら、最初にどの層を確認？
2. effect OFFでは音が出るがONだけ無音なら、analog I/Oはどこまで証明済み？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 23: validate power noise and bypass"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
