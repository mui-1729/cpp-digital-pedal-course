# P16 — `processBlock()`とAudio Buffer

## 今日作るもの

入力された音を変更せず、そのまま出力するpassthrough plugin。

## 新しい知識

- `prepareToPlay()`
- `processBlock()`
- `juce::AudioBuffer<float>`
- sample rate
- block size
- mono / stereo
- real-time deadline

## Hands-on

1. `PluginProcessor.cpp`の`prepareToPlay()`へbreakpointまたは一時的なdebug確認を入れる。
2. `processBlock()`が繰り返し呼ばれることを理解する。
3. bufferの`getNumSamples()`と`getNumChannels()`が「固定とは限らない」ことを確認。
4. 音声を変更するコードがない状態ではinput≈outputになることを確認。
5. extra output channelをclearする処理の意味を読む。

## 音の流れ

```text
Host
 ↓
AudioBuffer<float>
 ↓
processBlock()
 ↓
AudioBuffer<float>
 ↓
Host
```

Daisyのaudio callbackと後でほぼ同じ役割になります。

## Real-time rule

`processBlock()`内では原則:

- `new`しない
- fileを開かない
- networkへ行かない
- `std::cout`を連打しない
- UIを直接触らない
- 長時間lock待ちしない

## Challenge

bufferの全sampleへ`0.5f`を掛けて、音量が下がることを確認。その後passthroughへ戻す。

## 合格条件

- `prepareToPlay()`と`processBlock()`の違いを説明できる
- block sizeとsample rateを混同しない
- mono/stereoでchannel数が変わり得ることを理解
- audio threadで重いI/Oを避ける理由を説明できる

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p16: understand processBlock and buffers"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
