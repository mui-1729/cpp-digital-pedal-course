# 開発環境

## 0〜14 共通編: WSLでC++

今までの環境をそのまま使います。

```bash
g++ --version
git --version
```

ビルド例:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o app
./app
```

## Git

各Lessonを終えたらcheckpointを作ります。

```bash
git status
git add .
git commit -m "lesson 01: gain function"
```

壊したら戻れる状態を維持することが目的です。

---

# Plugin Track: Windows native

Plugin Trackは**WSLではなくWindows側**で進めます。

理由:

- Standalone appをそのままWindows audio deviceへ接続しやすい
- Windows DAW/VST3 hostと同じ環境でbuild/debugできる
- WSLのaudio/device bridgeを教材の本題にしない

## 必要software

P15開始日に公式要件を再確認したうえで、基本は以下。

- Git for Windows
- CMake 3.22以上
- Visual Studio 2022以降のC++ toolchain
  - `Desktop development with C++`
- VS Codeは編集用として使用可
- JUCEはprojectのCMakeが指定versionを取得する方式
- DAWはP15時点では不要

教材作成時点のpinは [PLUGIN-VERSIONS.md](PLUGIN-VERSIONS.md) を参照。

## 推奨ディレクトリ

Windows側の短いpathを使います。

```text
C:\dev\cpp-digital-pedal-course
```

WSLの`/mnt/c/...`からPluginをbuildする運用は、path/permission/build速度の問題を増やすため推奨しません。

## Buildの基本形

PowerShell Developer環境またはVisual StudioのCMake supportから:

```powershell
cmake -S plugin/work -B build/plugin -G "Visual Studio 17 2022" -A x64
cmake --build build/plugin --config Debug
```

Standaloneを先に起動し、その後VST3 hostで確認します。

---

# Hardware Track: Daisy

Hardware 15到達時に最新版公式toolchain手順を再確認して導入します。

WindowsではDaisyのUSB書き込み部分を無理にWSLへ寄せず、公式手順に沿ってWindows側toolchainを使う方針です。

実際に使用したtoolchain / libDaisy / board revisionは [HARDWARE-VERSIONS.md](HARDWARE-VERSIONS.md) へ記録します。
