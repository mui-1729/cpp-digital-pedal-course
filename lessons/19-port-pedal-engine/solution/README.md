# Solution note

`main.cpp`は教材更新時点のlibDaisy公開APIを元にしたreference implementationです。

実際のLesson 19では、Lesson 15で記録したSeed3/libDaisy versionでcompileし、API差分があれば**その時点の公式docsを優先**して更新します。

## DSP source of truth

Lesson 19専用の`PedalEngine.h`コピーは持ちません。

```text
shared/dsp/PedalEngine.h
        ↑
        ├── JUCE Plugin
        └── Daisy Hardware
```

`main.cpp`は:

```cpp
#include "dsp/PedalEngine.h"
```

として同じDSP APIを使います。

実際のDaisy projectでこのincludeを解決する方法は、Lesson 19開始時のlibDaisy project templateに合わせて次のどちらかを選びます。

1. **推奨:** build設定へrepoの`shared/`をinclude pathとして追加する。
2. toolchain検証中の一時手段として、`shared/dsp/PedalEngine.h`をprojectへcopyする。ただしcopyを独自改変せず、source of truthは`shared/`とする。

最終的には1を使い、PluginとHardwareで同じファイルをbuild対象にするのが目標です。

## Lesson 19で再確認すること

- `pedal::PedalEngine`
- `Prepare(sampleRate)`
- `SetDrive / SetSaturation / SetTone / SetLevel`
- `Process(sample)`
- parameter更新はcontrol/block rate
- sample loopでは軽い`Process()`だけを呼ぶ

こうすることで、DSPのbug fixをPlugin版だけ、Hardware版だけへ入れて食い違う状態を防ぎます。
