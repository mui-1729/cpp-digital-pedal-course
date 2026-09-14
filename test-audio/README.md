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

## 目的

「良い音か」だけでなく、

- silenceで異常がないか
- transientが壊れないか
- low/highでtone挙動が違うか
- picking強度でdistortionがどう変わるか

を再現可能に確認するためです。
