# Lesson 20 — HX Stomp経由で本物のギターを通す

**Phase:** 3-6: 実機

## 今日作るもの

ギターを弾きながら自作Distortion/Toneを評価する。

## 必要なもの

Guitar / HX Stomp / Daisy setup / patch cables / headphones or amp。

## 新しく使う知識

gain staging / instrument level / line level / FX Loop / A-B test

## なぜ必要？

自前のhigh-Z input回路をまだ作らず、HX Stompを橋渡しとして使えばDSPの確認とanalog回路学習を分離できます。

## Hands-on

1. HX Stomp manualのGlobal Settings > Ins/Outsをその場で再確認。
2. Guitar→HX Input。
3. presetへFX Loop/Send-Return routeを作る。
4. HX Send→Daisy input、Daisy output→HX Return。
5. 最初はlevelを十分下げる。
6. Send/Return levelを接続対象に合わせてInstrument/Lineから選ぶ。
7. raw passthroughとDSPをA/B。
8. input clipping / digital clipping / output clippingを区別して記録する。

## Challenge

- drive/tone/levelを物理POTへ割り当てる。
- 自分の好みの音を探す前に、unity付近の安全な基準presetを1つ保存する。

## 合格条件

- HX loopを安全に接続できる
- Inst/Lineの違いを説明できる
- clip位置を切り分けられる
- 本物のギターで自作DSPが動いた

## 絶対禁止

Amp SPEAKER OUTは使わない。接続はHXのSend/Returnなどline/instrument level I/Oのみ。

## 解説

### なぜHX Stompを使う？

この段階ではDSPを本物のギターで確認したい一方、high-Z guitar input回路はまだ学んでいません。HX StompのSend/Returnを使えば、instrument/line levelの橋渡しを既存機材へ任せられます。

### Gain staging

各段のlevelを「大きければ良い」にせず、clipせず十分なS/Nを得られる範囲に置きます。

```text
Guitar → HX input → Send → Daisy → Return → HX output
```

HX manualではSend/Return pairをstompbox向けInstrumentまたはline processor向けLineへ設定できます。接続対象に合わせます。

### A/B

processed音が大きいだけで良く感じえるのを避けるため、できるだけlevelを揃えてrawと比較します。

## よくあるミス

- Amp Speaker Outを使う
- HX Return Type/FX Loop routingを確認しない
- Send/Return level mismatchのclipをDSP distortionと勘違いする

## 確認問題

1. HXを一旦使う教育的な利点は？
2. instrument levelとline levelが違うのに、なぜ同じ1/4inch jackでも注意が必要？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 20: test pedal with hx stomp"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
