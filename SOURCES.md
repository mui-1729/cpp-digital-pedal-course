# 一次資料

この教材では、ハードウェア/APIが変わる部分は一次資料をsource of truthにします。

確認日: 2026-09-15

## Daisy

- Daisy current site / Seed3: https://daisy.audio/
- Daisy hardware docs: https://docs.daisy.audio/hardware/
- GPIO tutorial: https://docs.daisy.audio/tutorials/_a1_Getting-Started-GPIO/
- Audio tutorial: https://docs.daisy.audio/tutorials/_a3_Getting-Started-Audio/
- ADC tutorial: https://docs.daisy.audio/tutorials/_a4_Getting-Started-ADCs/
- Create new project: https://docs.daisy.audio/tutorials/create-new-project/
- libDaisy source/docs: https://docs.daisy.audio/libDaisy/

### Seed3について

Seed3は従来Seedとpin-to-pin compatibility、firmware compatibilityが公式に案内されています。
一方でTypical Application Circuitやdatasheetには2026年夏にも更新・訂正があったため、Lesson 21開始時に最新版を再確認します。

## Line 6 HX Stomp

- HX Stomp 3.80 Owner's Manual:
  https://line6.com/data/6/0a00051afdda673cccdb61c9c/application/pdf/HX%20Stomp%203.80%20Owner%27s%20Manual%20-%20English%20.pdf

Send/ReturnはGlobal SettingsでInstrument / Lineを切り替えられるため、Lesson 20でDaisyとのgain stagingに利用します。

## C++ reference

- https://en.cppreference.com/

必要な項目だけ参照します。C++標準ライブラリを網羅する教材ではありません。
