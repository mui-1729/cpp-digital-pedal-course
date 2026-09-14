# Course Design Decisions

このファイルは「なぜこの順番なのか」を残すための設計メモです。

## 1. C++とエフェクターを並列で学ぶ

文法を網羅してから制作するのではなく、関数→Gain、配列→Bufferのように即適用する。

## 2. PC DSPを先に完成させる

実機で「音が出ない」ときにC++/DSP/配線の全部を同時に疑わなくて済む。

## 3. Daisy購入を遅らせる

Lesson 14までは0円。続ける意思が固まった時点でPurchase Gate A。

## 4. HX Stompを橋渡しにする

実ギター体験を早めつつ、high-Z input circuit学習は後へ分離する。

## 5. Electronicsは必要になってから

Ohmの法則を延々解いてから作るのではなく、「ギターを直接入れたい→なぜbufferが要る？」から学ぶ。

## 6. 回路BOMを未来へ固定しない

Seed3は新しいhardwareでdatasheet更新もある。Lesson 21時点でcurrent official circuitを確認してfreezeする。

## 7. Real-time safetyを正式項目にする

callback内でallocation / blocking I/O / heavy loggingを避ける。単に音が出れば良い教材にしない。

## 8. Debuggingを成果物に含める

最終目標は「作れる」だけでなく「壊れたとき切り分けられる」。

## 9. Cost control

借りられる工具は借りる。oscilloscopeやPCBは初号機に必須としない。

## 10. Version control

各LessonをGit commitにする。完成コードを失わず、変更の差分を学習材料にする。
