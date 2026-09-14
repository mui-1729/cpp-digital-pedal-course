# Lesson 21 — ギター入力回路を読むための電子回路基礎

**Phase:** 3-6: 実機

## 今日作るもの

「なぜギターをそのまま何にでも挿せないか」を回路図で説明できる。

## 必要なもの

Breadboard / multimeter / Seed3はまだ接続しなくてもよい / resistor / capacitor / op-amp候補。

## 新しく使う知識

voltage / current / resistance / impedance / AC coupling / DC bias / op-amp / high-Z

## なぜ必要？

passive guitar pickupはsource impedanceを持ち、受け側のinput impedanceで音色・levelが変わります。またsingle-supply analog回路ではAC音声を扱うためbiasも必要になります。

## Hands-on

1. resistor dividerをbreadboardで作りmultimeterで電圧確認。
2. POTをdividerとして測る。
3. capacitorがDCを遮りACを通す役割を概念的に確認。
4. voltage follower / non-inverting op-ampの役割を読む。
5. high-Z input→buffer→level conditioning→Daisyというblock diagramを書く。
6. **最新版Seed3 datasheet / Typical Applicationを再確認してから**次Lessonの回路をfreezeする。

## Challenge

- 1MΩ inputと10kΩ inputの違いがギターpickupにどう影響しそうか説明する。
- bias電圧が「音量」ではないことを説明する。

## 合格条件

- voltageとcurrentを混同しない
- impedanceが周波数を含む概念だと理解する
- bufferの目的を説明できる
- 最新datasheetを確認した

## Hardware documentation gate

2026年のSeed3資料には更新・訂正事例があるため、ここで回路BOMを初めてfreezeします。古いblog図をsource of truthにしません。

## 解説

### ギターはただの「電圧源」ではない

passive pickupはcoilでありsource impedanceを持ちます。受け側input impedanceが低すぎるとpickupを強くloadし、levelだけでなくfrequency responseにも影響します。

### Buffer

high input impedanceでギターを受け、次段を駆動しやすいlow output impedanceへ変換する役割があります。

### AC couplingとbias

音声信号は0Vを中心に正負へ振れますが、single-supply op-amp回路は負電圧を扱えない場合があります。そこで中間電圧を仮想的な中心としてbiasし、必要な箇所をcapacitorでAC couplingします。

### なぜ最新資料を再確認？

Seed3は2026年登場直後で、Typical Application Circuitやdatasheetの訂正が実際に行われています。安全と再現性のため、回路値はこのLessonで最新公式資料からfreezeします。

## よくあるミス

- `1MΩ`を「常に1MΩの電流が流れる」など単位概念を混同
- biasとsignal amplitudeを同じものだと思う
- blog schematicだけを見てboard revisionを無視

## 確認問題

1. high-Z inputはなぜギターに重要？
2. bufferは必ず大きく増幅する回路？
3. biasの目的は？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 21: learn guitar input electronics"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
