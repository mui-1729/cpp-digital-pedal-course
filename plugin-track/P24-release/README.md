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

## Release candidate checklist

### Build

- [ ] Release build
- [ ] Standalone起動
- [ ] VST3 host load
- [ ] debug専用codeなし
- [ ] version番号確認

### DSP

- [ ] silenceで安定
- [ ] parameter min/maxで安定
- [ ] output clipを意図的に管理
- [ ] 44.1/48/96kHz確認
- [ ] mono/stereo確認

### State

- [ ] save/reload
- [ ] bypass restore
- [ ] old state compatibility方針を記録

### Docs

- [ ] `PLUGIN-VERSIONS.md`記録
- [ ] `plugin/VALIDATION.md`
- [ ] known issues
- [ ] controls説明

### Licence gate

binaryを他人へ配布する前に**その日の公式情報**を再確認:

- JUCE EULA / AGPL option
- 自分が使うJUCE tierの条件
- VST3 SDK licence
- VST trademark/logo rules
- third-party assets/code

教材作成時点ではJUCE 9.0.2がcurrent、VST3 SDK 3.8以降はMITですが、配布日には再確認します。

## 最後のChallenge

同じclean guitar clipを:

1. bypass
2. low drive
3. high drive
4. high SAT
5. dark tone

で書き出し、自分の言葉で音の違いを記録する。

## Plugin Track修了条件

- 自分でbuildできる
- `processBlock()`からPedalEngineまで追える
- parameter/state/GUI/threadの役割を説明できる
- validationできる
- 「次にSATをどう改造したいか」を1つ設計できる

## 次へ

ここでPCだけで修了してもよい。

実機化したい場合はHardware 15へ進み、**同じDSPをDaisyへ移植**する。

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p24: finish mini digital drive"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
