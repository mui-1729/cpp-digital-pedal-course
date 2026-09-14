# Safety Rules

この教材で扱うのは主に低電圧回路ですが、誤配線で機材を壊したり、大音量で耳を傷める可能性があります。

## 絶対にやらない

- **ギターアンプのSPEAKER OUTをDaisy / HX Stomp / PC / audio interfaceへ接続しない**
- DaisyのGPIO/ADC/audio pinへ、仕様を確認せず9Vを直接入れない
- 電源極性を未確認のまま通電しない
- breadboard配線を大きく変更しながら通電し続けない
- 最初からヘッドホン/アンプを大音量にしない

## 通電前チェック

1. 電源OFF
2. 9V / 5V / 3.3V / GNDの線を目視
3. multimeterでGND短絡がないか確認
4. supply voltageと極性を確認
5. ICの向きを確認
6. まずSeedや高価な機材を外した状態で電源確認
7. 問題なければ接続

## Daisy ADC

Daisy公式ADC tutorialでは通常のADC入力は0〜3.3Vを想定しています。
POTは3.3VとGNDの間に接続し、wiperをADCへ入れます。

## Audio level

- 最初は小さなlevelから
- clippingが起きたら「音が歪んで面白い」で済ませず、どの段でclipしているか切り分ける
- digital full scaleとanalog headroomは別物

## Hearing safety

DSPのバグで突然大きなDC/ノイズ/feedbackが出ることがあります。

- 最初はvolumeを下げる
- headphonesを耳から少し離して初回起動
- feedback系effectは特に慎重に

## はんだ・加工

- 換気
- 保護メガネ
- 熱いこて先をケーブルや筐体に置かない
- ドリル加工時は筐体を固定
- 金属切粉を基板上に残さない

## 困ったら

「たぶん大丈夫」で通電しない。
写真、回路図、電圧測定値を揃えてから原因を切り分ける。
