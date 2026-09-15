# P23 — Pluginを壊して検証する

## 今日作るもの

「自分のPCでは鳴った」から「条件を変えても壊れにくい」へ進めます。

このLessonでは検証対象を分けます。

```text
shared DSP      → offline WAV runner
Standalone統合 → device / GUI / parameter / state
VST3 wrapper    → pluginval
主観的な音      → test WAV / 後日ギター
```

1個のテストだけで全部を証明しようとしないのが重要です。

## Test matrix

最低限:

| Test | Cases |
|---|---|
| sample rate | 44.1 / 48 / 96 kHz |
| channel | mono / stereo |
| block size | host/validatorで選べる複数値 |
| input | silence / sine / sweep / transient |
| parameter | min / max / rapid movement |
| state | save / reload |
| bypass | repeated toggle |
| output | NaN / Inf / unexpected clippingがない |

## Hands-on A — guitar/DAWなしでDSP確認

1. test WAVを生成。

```bash
python tools/generate_test_audio.py
```

2. offline runnerをbuild。

```bash
mkdir -p build/tools
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror \
  -Ishared tools/process_wav.cpp -o build/tools/process_wav
```

3. まず`sine-440.wav`を処理する。

```bash
./build/tools/process_wav \
  test-audio/generated/sine-440.wav \
  test-audio/generated/sine-440-processed.wav
```

4. `sweep.wav`と`transient-train.wav`も処理する。
5. input/output WAVを普通のプレイヤーで聴く。
6. DRIVE/SAT/TONE/LEVELをコマンド引数で変えて結果を比較する。

> `process_wav`はshared DSPの検証用で、VST3 wrapperそのものではありません。

## Hands-on B — Standalone統合

1. Standaloneを44.1 / 48 / 96 kHzで可能な範囲で切り替える。
2. mono/stereo device configurationを確認する。
3. DRIVE/SAT/TONE/LEVELを最小/最大へ振る。
4. BYPASSを連打し、click/crashがないか確認する。
5. windowを閉じて再起動しstate復元を確認する。
6. 音声入力が手元にある日は、microphone/HX Stomp等の安全なinputを使って統合確認してよい。ギターは必須ではない。

## Hands-on C — VST3 validation

1. pluginvalの**current official release**を確認する。
2. P15で生成したVST3へpluginvalを実行する。
3. validation levelを段階的に上げる。
4. errorが出た場合は「DSP音質」ではなく、lifecycle / bus layout / parameter / state / wrapper周辺から切り分ける。
5. 結果を`plugin/VALIDATION.md`へ記録する。

pluginvalはexternal binaryとして使います。教材projectへsource統合はしません。

## DAWがある場合の追加確認

DAW/Hostを持っている場合だけ追加で:

- VST3 scan
- play / stop / seek
- automation
- project save / reload
- block size変更

を行います。

**DAWがないことをPlugin Track修了の失格条件にはしません。** P24までStandalone + offline DSP + pluginvalで技術的な確認を進められます。

## Challenge

- LEVEL上限を一時的に大きくしてclipを発生させ、meter/testで発見して元へ戻す。
- BYPASS crossfadeを一時的に0ms相当にしてclick差を確認し、元へ戻す。
- TONEの係数計算をsample loopへ戻す変更は実施せず、「なぜ避けるか」をコードレビューだけで説明する。

## 合格条件

- offline WAVでshared DSPのbefore/afterを確認した
- Standaloneのparameter/state/bypassを確認した
- pluginvalをVST3へ実行した
- crash/無音/clipの再現条件を記録できる
- validatorを「音が良いか判定するもの」と誤解していない
- DSP・Standalone・VST3 wrapperの検証を分けて説明できる

## Git checkpoint

```bash
git status
git diff
git add .
git commit -m "plugin p23: validate plugin across conditions"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
