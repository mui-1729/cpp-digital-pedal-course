# 確認問題 — 解答ガイド

**先に各Lessonを自力で考えてから開くこと。** 表現が完全一致する必要はありません。

## 00

1. source変更はbinaryへ反映されないため再compileが必要。
2. compiler warningを増やして、怪しいcodeを早く見つけるため。
3. DSP codeと、ADC/DAC/GPIO/analog circuitなど実世界I/Oの境界。

## 01

1. 0.5。
2. unity、値を変えない。
3. mute、0倍。
4. 再利用・名前付け・テスト・mainの整理がしやすい。

## 02

1. 7。
2. `i==kSize`は範囲外だから。
3. blockごとに同じ処理を繰り返せるから。

## 03

1. 戻り値なし。
2. 参照が元変数そのものへ作用するため。
3. `const` reference等、変更不可にするinterfaceを考える。

## 04

1. memory address。
2. pointer単独では要素数を通常保持しないため。
3. contiguousなsample memoryを効率よく渡せるため。

## 05

1. class=型/設計、object=その実体。
2. parameter/stateと処理をeffect単位でまとめやすい。

## 06

1. objectが呼び出し間で覚える値。
2. 2.0。
3. 1.0。

## 07

1. 意味が名前で読め、誤用しにくい。
2. どちらもnonlinear。
3. 0。

## 08

1. interface/declaration。
2. implementation分離・再利用・テスト・依存整理。
3. できる。Makefileは再現可能に自動化するだけ。

## 09

1. 24000 samples。
2. 1ms。
3. 1秒あたりの波の周期数。

## 10

1. 1倍。
2. linear 0 / 無音へ近づく。
3. amplitudeが増えheadroomを消費する。

## 11

1. 単純waveshaperはmemory不要。
2. Nyquist超過成分がaliasingする可能性。
3. loudness差で評価が偏るのを減らす。

## 12

1. 過去の出力/状態が次sampleに必要だから。
2. 同じ係数でも1 sampleの時間が変わるから。
3. nonlinear stageとの順序で生成/削減する周波数成分が変わるから。

## 13

1. 12000 samples。
2. 固定memoryで長時間streamを処理できる。
3. deadlineが読めなくなりunderrunやfragmentation要因になるため。

## 14

1. PC test可能、hardware変更からDSPを分離できる。
2. 一般には変わる。effectは可換ではない。
3. 自動: finite/範囲/mute。耳: tone/feel/好み。

## 15

1. target CPU/ABIが異なるため。
2. board revision、libDaisy commit、toolchain versionなど。

## 16

1. floating inputを避けdefault stateを作る。
2. mechanical contactが短時間に複数回変化するため。
3. footswitch/LED。

## 17

1. `1 + 0.5*9 = 5.5`。
2. control voltageを読むADCとaudio waveformを高rateで扱うcodec ADC。

## 18

1. 約83.3μs (`4 / 48000`)。
2. 1channelあたりのblock sample数。
3. blocking/slow operationでaudio deadlineを超え得るため。

## 19

1. desktopでも同じDSPをtestできる。
2. 人間の操作速度はaudio sample rateより遥かに遅いため。

## 20

1. DSP確認とanalog guitar input回路学習を分離できる。
2. connector形状が同じでもsignal level/impedance設計は異なるため。

## 21

1. pickupを過度にloadせずfrequency response/levelを保つため。
2. いいえ。unity gain bufferも代表例。
3. single-supply回路内でAC signalを扱えるoperating pointを作るため。

## 22

1. 誤配線から高価なboardを守り、原因を段階切り分けするため。
2. analog input→codec→output pathの基本動作をかなり切り分けられる。

## 23

1. power/firmware/audio pathを順に確認。LED動作なら少なくとも一部power/MCUは生きている。
2. input/output analog pathはraw audioで動いているため、DSP/bypass/parameter側へ疑いを絞れる。

## 24

1. analog wiring/hardware pathだけを先に検証できるため。
2. 後から同一firmwareを再現・比較できるため。
3. 例: PCB化、MIDI、preset、better oversampling、delay/reverb、relay bypass。
