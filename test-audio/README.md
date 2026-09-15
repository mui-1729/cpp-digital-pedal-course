# Test audio

Git repositoryには著作権のある曲や第三者のguitar stemを入れません。

## 自動生成

repo rootで:

```bash
python tools/generate_test_audio.py
```

`test-audio/generated/`へ以下を生成します。

- `sine-440.wav`
- `two-tone.wav`
- `sweep.wav`
- `transient-train.wav`

DSPの動作・clip・filter・meter検証用です。

## ギターなしでbefore / afterを聴く

`tools/process_wav.cpp`は、16-bit PCMのmono/stereo WAVを`shared/dsp/PedalEngine.h`へ通して新しいWAVを書き出す小さなoffline runnerです。

WSL/Linuxでbuild:

```bash
mkdir -p build/tools
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror \
  -Ishared tools/process_wav.cpp -o build/tools/process_wav
```

例:

```bash
./build/tools/process_wav \
  test-audio/generated/two-tone.wav \
  test-audio/generated/two-tone-processed.wav \
  5.0 0.7 0.55 0.7
```

引数は:

```text
INPUT OUTPUT [DRIVE] [SAT] [TONE] [LEVEL]
```

出力WAVを普通の音楽プレイヤーで聞き比べれば、ギターもDAWもなくDSPのbefore/afterを確認できます。

このtoolは**Plugin wrapperそのものの検証ではありません**。P23では役割を分けます。

```text
process_wav.cpp → shared DSPの音/数値を確認
pluginval       → VST3 wrapper/APIの妥当性を確認
Standalone      → device/GUI/parameterの統合を確認
```

## ギターを一度使える日に録る

clean / effect OFFで自分の演奏を録っておくと、ギターが手元にない日でも開発できます。

推奨:

| file | 内容 |
|---|---|
| `guitar-silence.wav` | 10秒、弾かない。noise確認 |
| `guitar-low-note.wav` | 低音単音 |
| `guitar-high-note.wav` | 高音単音 |
| `guitar-open-chord.wav` | 開放コード |
| `guitar-palm-mute.wav` | palm mute |
| `guitar-dynamics.wav` | 弱く→強く弾く |

録音レベルをclipさせず、できれば同じinput gainで揃えます。

`process_wav`の教育用readerは**PCM 16-bit / monoまたはstereo**に限定しています。別formatの録音はDAW等で16-bit PCM WAVへexportしてから使います。

## 目的

「良い音か」だけでなく、

- silenceで異常がないか
- transientが壊れないか
- low/highでtone挙動が違うか
- picking強度でdistortionがどう変わるか

を再現可能に確認するためです。
