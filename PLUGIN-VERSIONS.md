# Plugin Track Version Log

確認日: 2026-09-15

## Course baseline

| Item | Baseline |
|---|---|
| JUCE | **9.0.2** |
| C++ | C++20 |
| CMake | current stableをP15開始時に確認 |
| Windows toolchain | **Visual Studio 2026 / MSVC**（2026-09-15時点の現行） |
| Plugin formats | VST3 + Standalone |
| VST3 SDK | JUCEが利用するcurrent SDK。3.8以降MIT |
| pluginval | external validatorとして使用。実行時にcurrent release確認 |

JUCE 9.0.2は教材更新時点のcurrent releaseとしてpinします。学習途中でJUCEを無条件にlatestへ上げません。

Visual Studioについては世代名をCMake commandへ固定しません。2026-09-15時点ではVisual Studio 2026が現行ですが、P15では`cmake -S ... -B ...`で利用可能なtoolchainをCMakeに選ばせ、必要なときだけ`cmake --help`でgeneratorを確認します。

## ルール

- P15開始時にこの表とJUCE公式releaseを確認
- Visual Studio / CMakeのcurrent stableを確認
- Course途中で勝手にJUCE `master`/latestへ変更しない
- upgradeする場合は専用branchを作る
- P24で実際にbuildしたversion/commitを追記する

## Local record

開始時に埋める:

```text
JUCE:
CMake:
Visual Studio / MSVC:
Windows:
Plugin host:
pluginval:
```

## Licence note

VST3とJUCEは別ライセンスです。binary配布時はP24でその時点の公式条件を再確認します。
