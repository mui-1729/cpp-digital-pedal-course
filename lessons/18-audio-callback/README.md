# Lesson 18 — Audio CallbackでPassthroughする

**Phase:** 3-6: 実機

## 今日作るもの

入力をそのまま出力へコピーするStereo Passthrough。

## 必要なもの

Seed3 / 安全なline-level audio source & destination。最初は公式推奨接続を使用。

## 新しく使う知識

audio callback / input buffer / output buffer / block size / sample rate / latency / real-time safety

## なぜ必要？

ここでLesson 02/04の配列・pointer・forが、実際のaudio codeとして再登場します。

## Hands-on

1. まず無音を出力するcallbackを書く。
2. `out[0][i] = in[0][i]`へ変更。
3. L/R両方をcopy。
4. block sizeを確認。
5. 48kHz / block 48なら約1msという締切の意味を計算。
6. callback内の`malloc`, heavy print, blocking I/Oを禁止する理由を確認。

## Challenge

- 左channelだけ0.5倍して違いを確認。
- callbackに故意に長いdelayを入れない。なぜ危険か文章で説明する。

## 合格条件

- callbackの3引数の意味を読める
- `in[ch][i]` / `out[ch][i]`が理解できる
- real-time codeにはdeadlineがあると説明できる
- callback内でdynamic allocationを避ける理由が分かる

## Real-time rule

callbackは次のbuffer deadlineまでに必ず終える。時間の読めない処理はmain loop側へ逃がす。

## 解説

### Audio callback

hardwareが「次のaudio blockを処理して」と決めたタイミングで呼びます。

```cpp
void AudioCallback(InputBuffer in, OutputBuffer out, size_t size)
```

- `in`: 入力sample群
- `out`: 出力を書き込む場所
- `size`: 1channelあたりのsample数

### Deadline

48kHzで48 samplesならblockは約1ms。callbackがそれ以上かかれば次のaudioに間に合わずunderrun/artifactの原因になります。

### 禁止寄りの処理

callback内では

- `malloc/new`
- file I/O
- heavy logging
- blocking peripheral transfer

など時間が読めない処理を避けます。

## よくあるミス

- `in`を書き換えようとする
- channelとsample indexを逆にする
- callback内で`DelayMs`

## 確認問題

1. 48kHz / block=4ならdeadlineは約何μs？
2. `size`はchannel数？sample数？
3. なぜprintを大量に入れない？

## 学習ルール

分からない用語が出ても、その場でC++全体を勉強し直しません。**このLessonの合格条件に必要な範囲だけ**理解して先へ進み、後の実例で再登場したときに理解を深めます。

## Git checkpoint

```bash
git add .
git commit -m "lesson 18: audio passthrough callback"
```

答え合わせは `solution/` を見てください。最初からsolutionを開かないことを推奨します。
