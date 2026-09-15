# P17 — 共通`PedalEngine`をPluginへ接続する

## 今日作るもの

Lesson 14までに学んだDSPを、JUCEの`processBlock()`から呼びます。

## 新しい知識

- framework-independent DSP
- adapter / bridge
- CMakeのinclude path
- channelごとのstate

## 重要な設計

```text
JUCE AudioBuffer
      ↓
PluginProcessor
      ↓
shared/dsp/PedalEngine.h
```

`PedalEngine.h`はJUCEをincludeしません。

## Hands-on

1. `shared/dsp/PedalEngine.h`を読む。
2. `plugin/work/CMakeLists.txt`へ共通DSPのinclude rootを追加する。

```cmake
target_include_directories(MiniDigitalDrive
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../../shared
)
```

3. `PluginProcessor.h`から共通DSPをincludeする。

```cpp
#include "dsp/PedalEngine.h"
```

4. stereo用にchannelごとのinstanceを持つ。

```cpp
static constexpr std::size_t kMaxChannels = 2;
std::array<pedal::PedalEngine, kMaxChannels> pedals_;
```

`<array>`もincludeする。

5. `prepareToPlay()`で全instanceへsample rateを渡す。

```cpp
for (auto& pedal : pedals_) {
    pedal.Prepare(static_cast<float>(sampleRate));
    pedal.Reset();
}
```

6. `processBlock()`で、処理するchannel数を2以下へ制限してから1sampleずつ`Process()`する。
7. まずparameterは固定値でよい。例: DRIVE 4 / SAT 0.6 / TONE 0.6 / LEVEL 0.7。
8. Standaloneでmono/stereoを確認する。
9. P16のpassthroughへすぐ戻せるよう、変更をcommit前に`git diff`で確認する。

## なぜCMakeにも設定が必要？

C++の

```cpp
#include "dsp/PedalEngine.h"
```

だけではcompilerは`shared/`がどこにあるか知りません。`target_include_directories()`で探索開始地点を教えることで、

```text
shared/
└── dsp/
    └── PedalEngine.h
```

を見つけられるようになります。

## なぜPedalEngineをchannelごとに持つ？

Tone filterは「前回のsample」というstateを持ちます。左と右で同じinstanceを共有すると、channel間でstateが混ざります。

```text
L → PedalEngine L
R → PedalEngine R
```

Distortionだけならstateを持たない部分もありますが、**Effect chain全体はstatefulになり得る**のでchannelごとに分けます。

## Challenge

- DSP ON/OFF用の一時的な`bool`を作りA/Bする。
- Distortionを外してToneだけにした場合の差を確認する。
- `target_include_directories()`を一度コメントアウトし、compiler errorを読んでから戻す。

## よくあるエラー

### `dsp/PedalEngine.h: No such file or directory`

CMakeのinclude path追加後に再configureする。

```powershell
cmake -S plugin/work -B build/plugin
cmake --build build/plugin --config Debug
```

それでも別generatorを選びたい場合だけ`cmake --help`で利用可能なgeneratorを確認する。

### stereoの左右で挙動がおかしい

1個のstateful `PedalEngine`を左右で共有していないか確認する。

## 合格条件

- JUCE依存コードとDSPコードを分離できる
- CMakeのinclude pathが何をしているか説明できる
- stateful effectをstereo channel間で共有してはいけない理由を説明できる
- `PedalEngine`をDaisyにも持っていける理由を説明できる

## Git checkpoint

```bash
git status
git diff
git add .
git commit -m "plugin p17: connect shared pedal engine"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
