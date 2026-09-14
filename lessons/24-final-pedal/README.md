# Lesson 24 — MINI DIGITAL DRIVEをケースへ完成させる

**Phase:** 3-6: 実機

## 今日作るもの

GAIN / TONE / LEVEL / BYPASS / LEDを備えたケース入りデジタルドライブを完成させる。

## 必要なもの

完成済みbreadboard回路 / enclosure / jacks / pots / knobs / footswitch / LED / DC jack / wire / soldering tools（借用可）。

## 新しく使う知識

mechanical layout / soldering / strain relief / final validation / documentation

## なぜ必要？

最終工程は「工作」だけではなく、再現可能なBOM・wiring・firmware・test結果を残すところまで含めます。

## Hands-on

1. 紙でtop panel配置を決める。
2. 基板/Seed/jack干渉をケース内寸で確認。
3. drill位置をcenter punch。
4. 金属切粉を完全に除去。
5. power→I/O→controlsの順に配線。
6. continuity check後に通電。
7. passthroughで確認。
8. DSP ON。
9. guitarでA/B。
10. `FINAL-REPORT.md`へBOM, firmware commit, measured voltages, known issuesを残す。

## Challenge

- 30分以上の連続使用で異常発熱/不安定がないか確認（監視下）。
- ノブ全域、bypass連打、power cycleをテスト。
- 最後に自分の音作りpresetを記録する。

## 合格条件

- ケース入りで安定動作
- GAIN/TONE/LEVELが意図通り
- bypass/LEDが安定
- no-effect passthroughとprocessedを比較できる
- firmware/BOM/wiringを第三者が追える
- troubleshooting手順を自分で使える

## 修了

完成後は「もっと高度なDistortion」「Delay/Reverb」「MIDI」「PCB」「JUCE plugin」のどれへ進むか選べます。

## 解説

### ケース化は最後の「移植」

breadboard上で動く回路を、短い配線・mechanical constraints・metal enclosureへ移します。ここでも一気に全部配線せず、power→audio→controlsの順で段階確認します。

### Documentationも完成物

半年後の自分が直せないペダルは、学習成果として弱いです。

最低限残すもの:

- schematic / wiring
- BOM
- firmware commit
- libDaisy/board versions
- measured voltages
- known issues

### v1を完成させる

初号機でPCB、OLED、preset、MIDI、stereo、relay bypassを全部入れません。「安定した3ノブdrive」を完成させてからv2へ進みます。

## よくあるミス

- case drill前に内部干渉を測らない
- metal chipsを残したまま通電
- breadboard→case移植後にpassthrough testを飛ばしていきなりeffect ON

## 確認問題

1. ケース化後、最初に動かすfirmwareはなぜpassthroughが良い？
2. 最終レポートへcommit hashを残す利点は？
3. v2候補を3つ挙げる。

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 24: finish mini digital drive"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
