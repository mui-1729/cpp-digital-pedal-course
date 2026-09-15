# P24 — Mini Digital Drive完成

## 最終成果物

- VST3
- Standalone
- DRIVE
- SAT
- TONE
- LEVEL
- BYPASS
- state restore
- input/output meter
- validation log
- reproducible test audio workflow

## Release candidate checklist

### Build

- [ ] Release build
- [ ] Standalone起動
- [ ] VST3 binary生成
- [ ] pluginvalでVST3をload/validate
- [ ] debug専用codeなし
- [ ] version番号確認

DAW/別Hostを持っている場合はVST3 scan/loadも追加で確認しますが、**Plugin Track修了の必須条件にはしません**。

### DSP

- [ ] generated WAVをoffline runnerで処理
- [ ] silenceで安定
- [ ] parameter min/maxで安定
- [ ] output clipを意図的に管理
- [ ] 44.1/48/96kHzを可能な範囲で確認
- [ ] mono/stereo確認

### State

- [ ] Standalone normal quit → restartでstate restore
- [ ] bypass restore
- [ ] Parameter ID互換性の方針を記録

### Real-time design

- [ ] audio sample loopでallocationしない
- [ ] audio sample loopでlog/GUI更新しない
- [ ] Toneの`pow/exp`係数計算をsampleごとに行っていない
- [ ] bypassは短いcrossfadeで不連続を避ける
- [ ] meterはatomic経由でGUIへ渡す

### Docs

- [ ] `PLUGIN-VERSIONS.md`記録
- [ ] `plugin/VALIDATION.md`記録
- [ ] `plugin/PRESETS.md`へ最低2設定
- [ ] known issues
- [ ] controls説明

### Licence gate

binaryを他人へ配布する前に**その日の公式情報**を再確認:

- JUCE EULA / AGPL option
- 自分が使うJUCE tierの条件
- VST3 SDK licence
- VST trademark/logo rules
- third-party assets/code

教材作成時点ではJUCE 9.0.2をpinし、VST3 SDK 3.8以降はMITですが、配布日には再確認します。

## 最後のChallenge — ギターなしでも可能

同じtest sourceを最低5設定で処理します。

例:

1. low drive
2. high drive
3. hard寄りSAT
4. soft寄りSAT
5. dark / bright tone

入力は`two-tone.wav`や`sweep.wav`で構いません。before/afterを普通の音楽プレイヤーで聞き、自分の言葉で違いを記録します。

後日ギターを使える日に、同じ5設定をclean guitar clipまたは実演でも確認すると主観評価がさらに良くなります。

## Plugin Track修了条件

- 自分でJUCE projectをconfigure/buildできる
- StandaloneとVST3の違いを説明できる
- `processBlock()`から`shared/dsp/PedalEngine.h`まで処理を追える
- parameter / state / GUI / audio thread / message threadの役割を説明できる
- guitar/DAWなしでもoffline WAV + Standalone + pluginvalで検証できる
- 「次にSATをどう改造したいか」を1つ設計できる

## ここで得られるもの

この時点でPCルートは独立して修了です。

```text
C++
 ↓
shared DSP
 ↓
JUCE AudioProcessor
 ↓
VST3 / Standalone
```

実機化したい場合だけHardware 15へ進み、**同じDSP coreをDaisyへ移植**します。

## Git checkpoint

```bash
git status
git diff
git add .
git commit -m "plugin p24: finish mini digital drive"
```

このcommitをPlugin Track v1の基準点として残します。
