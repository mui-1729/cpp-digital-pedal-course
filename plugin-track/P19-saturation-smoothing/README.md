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
- parameter updateとaudio rate

## Hands-on

1. `saturation` parameterをAPVTSへ追加。
2. `PedalEngine::SetSaturation()`へ接続。
3. smoothingなしでparameterを急に動かして比較。
4. DRIVE / SAT / TONE / LEVELに短いrampを入れる。
5. smoothing値はsample rate変更時に再設定する。

## 注意

GUI threadから`PedalEngine`を直接変更しない。parameterを介してaudio thread側で反映します。

## Challenge

smoothing timeを5ms / 50ms / 500msで比較し、ノブとして自然な値を考える。

## 合格条件

- zipper noiseが起きる理由を説明できる
- target/currentの違いを説明できる
- SATを後から独自macroへ発展させられる構造になっている

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p19: add saturation and smoothing"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
