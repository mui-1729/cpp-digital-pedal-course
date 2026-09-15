# P19 — SATURATIONとParameter Smoothing

## 今日作るもの

`SAT`ノブを追加し、急なparameter変化を滑らかにします。

## SATの意味

この教材の初期SATは「歪みカーブのhard↔soft character」を連続的に変える教育用実装です。市販ペダルの特定回路をコピーするものではありません。

将来は1つのSATノブで:

- waveshaper curve
- pre/post EQ
- compression感
- output compensation

を同時に動かすmacro parameterへ発展できます。

## 新しい知識

- zipper noise
- `juce::SmoothedValue`
- target valueとcurrent value
- parameter update rateとaudio rate
- 重い係数計算をaudio sample pathから外す考え方
- bypass crossfade

## Hands-on

1. `saturation` parameterをAPVTSへ追加。
2. `PedalEngine::SetSaturation()`へ接続。
3. smoothingなしでDRIVE / SAT / LEVELを急に動かして比較。
4. `juce::SmoothedValue`で短いrampを入れる。
5. smoothing timeはsample rate変更時に再設定する。
6. TONEは別扱いにする。`pow` / `exp`を含むfilter係数計算をサンプルごとに呼ばず、**parameter/control更新時にtarget係数だけ計算**する。
7. `OnePoleTone::Process()`ではtarget係数へ軽く補間しながらaudio sampleを処理する。
8. BYPASSもdry/wetを瞬時に切り替えず、短いcrossfadeで切り替える。

## なぜTONEだけ少し違う？

DRIVEやLEVELのsetterはほぼ代入と`clamp`だけですが、TONEのcutoff→filter係数変換には`pow`や`exp`が入ります。

```text
悪い例
sampleごとにTone setter
  ↓
pow / expを48000回/秒 × channel数

教材の最終形
block/control rateでtarget係数を計算
  ↓
audio rateでは係数を軽く補間
```

「parameter smoothingを入れたから全部sampleごとにsetterを呼べばよい」ではありません。**音声スレッドで何を何回実行しているか**まで考えます。

## Bypass crossfade

処理音から原音へ1sampleで飛ぶと、波形に不連続ができてclickになることがあります。

最終参考実装では、短時間だけ

```text
wet 100% → wet/dry mix → dry 100%
```

と遷移させます。bypass中もDSP stateを進めておくため、effectへ戻ったときにも状態が飛びにくくなります。

## 注意

GUI threadから`PedalEngine`を直接変更しない。parameterを介してaudio thread側で反映します。

## Challenge

- smoothing timeを5ms / 50ms / 500msで比較し、ノブとして自然な値を考える。
- TONEの係数計算をsample loop内へ戻した場合、何が無駄になるか説明する。
- bypass crossfadeを0msと10msで比較する。

## 合格条件

- zipper noiseが起きる理由を説明できる
- target/currentの違いを説明できる
- parameter update rateとaudio rateを区別できる
- 重いparameter→coefficient変換をaudio sampleごとに実行しない理由を説明できる
- bypass crossfadeの目的を説明できる
- SATを後から独自macroへ発展させられる構造になっている

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p19: add saturation and smoothing"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
