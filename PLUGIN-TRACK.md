# Plugin Track 設計

## 目的

Lesson 14で完成した`PedalEngine`を、PC上で実際に使えるaudio pluginへする。

最終成果物:

- **Mini Digital Drive**
- VST3
- Standalone
- DRIVE / SAT / TONE / LEVEL / BYPASS
- state save/restore
- simple preset/A-B
- input/output meter
- validation log

## なぜPluginを実機より先に推奨するか

1. 追加ハードウェア費0円
2. DSPのbugを配線から切り離して検証できる
3. real-time audioの基本をPCで学べる
4. 同じ`PedalEngine`を後でDaisyへ移せる
5. ギターが手元にない日もWAV/test signalで進められる

## Architecture

```text
Host / Standalone
      │
      ▼
PluginProcessor
  ├─ parameter/state
  ├─ audio buffer bridge
  └─ meter bridge
      │
      ▼
shared/dsp/PedalEngine
  ├─ Distortion
  ├─ Saturation
  ├─ Tone
  └─ Level
```

GUIはDSPへ直接触りません。

```text
GUI
 ↓
Parameter
 ↓
Audio thread
 ↓
PedalEngine
```

これにより、GUI threadとaudio threadの責務を分けます。

## 開発方式

Plugin Trackは`plugin/work/`を1つの実プロジェクトとして育てます。

- P15で最小project作成
- 各Lessonで同じprojectを変更
- Lesson終了ごとにGit commit
- 困った時だけ`plugin/reference-final/`を見る

複数ファイルprojectを毎Lesson丸ごとコピーするより、実際の開発に近く、Git diffも学習材料になります。

## DAWは必須ではない

P15〜P17はStandaloneだけで進行できます。

VST3 host確認はP18以降。手持ちDAWがあれば使用し、なければJUCE AudioPluginHost等を選べます。教材の本題はDAW選びではありません。

## ギターは常時不要

### 自動生成

`tools/generate_test_audio.py`:

- sine
- sweep
- transient
- two-tone

### 一度ギターが使える時に録っておくと良いclip

- silence/noise 10秒
- single note low 10秒
- single note high 10秒
- open chord 10秒
- palm mute 10秒
- soft→hard picking 15秒

権利問題を避けるため、自分の演奏をcleanで録音するのを推奨。

## Version strategy

- framework: [PLUGIN-VERSIONS.md](PLUGIN-VERSIONS.md)
- updateはLesson途中で行わない
- P24でversionを記録
- future upgradeは別commit/branchで行う

## Real-time rules

Audio callback / `processBlock()`では原則として:

- heap allocationしない
- file I/Oしない
- network I/Oしない
- console loggingを連打しない
- mutex待ちを作らない
- UIを直接操作しない
- 処理時間がblock deadlineを超えない

## Validation matrix

P23で最低限確認:

| 項目 | 値 |
|---|---|
| sample rate | 44.1 / 48 / 96 kHz |
| layout | mono / stereo |
| block size | 小 / 中 / 大の複数 |
| input | silence / sine / transient / music-like |
| parameter | min / max / rapid move |
| transport | stop / play / reload |
| state | save / close / reopen |
| bypass | repeated toggle |

## Distribution gate

P24でbinaryを他人へ渡す前に:

1. current JUCE licence確認
2. current VST3 licence確認
3. trademark/logo rules確認
4. third-party code/assets確認
5. version番号固定
6. validation log保存
7. README/known issues作成

この教材は法的助言ではなく、**配布前に一次資料を確認する習慣**をつける。
