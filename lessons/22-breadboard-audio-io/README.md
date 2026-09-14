# Lesson 22 — 自前のInput/Output Stageをbreadboardで組む

**Phase:** 3-6: 実機

## 今日作るもの

HX Stompに頼っていたinstrument↔Daisy間のanalog I/Oを自分の回路へ置き換える。

## 必要なもの

Lesson 21でfreezeしたBOM / breadboard / multimeter / audio source / Seed3 / HX Stompをmonitorとして利用可。

## 新しく使う知識

input buffer / attenuation-gain / output buffer / reference voltage / decoupling / grounding

## なぜ必要？

DSPが動くことはLesson 20で証明済みなので、ここではanalog circuitだけを検証できます。問題を一度に1層へ限定します。

## Hands-on

1. Seed3を外した状態でpower rail確認。
2. reference/bias voltage確認。
3. input stageだけ組み、DC operating pointを測る。
4. Seed3 inputへ接続する前にexpected rangeを確認。
5. output stageも同様に測る。
6. passthrough firmwareで音を通す。
7. 最後にDSPをON。
8. ノイズ/levelをHX経由構成と比較する。

## Challenge

- input stageをbypassした場合の違いを安全なsourceで比較する。
- measured voltageをREADMEへ記録する。

## 合格条件

- 回路をblock単位で検証できる
- bias/supplyをmultimeterで確認できる
- passthrough→DSPの順で検証した
- HX Stompなしのguitar inputへ近づいた

## Safety

配線変更は電源OFF。Seedへ接続する前にsupply/bias/rangeを測る。

## 解説

### Build by blocks

回路全体を一気に組まないことが重要です。

```text
Power/Reference
  ↓
Input stage
  ↓
Daisy
  ↓
Output stage
```

各blockのDC voltageを測り、期待値と合ってから次へ進みます。

### Passthrough first

DSPをOFFにしたpassthroughでanalog pathだけ確認します。ここで音が出なければDistortion codeは原因ではありません。

## よくあるミス

- 全部組んでから初めて通電
- voltage測定点のGND基準を間違える
- audio jackのtip/sleeve配線を混同

## 確認問題

1. なぜSeedを外してpower railから確認する？
2. passthroughが成功すると何を証明できる？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 22: build breadboard audio io"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
