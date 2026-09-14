# P15 — JUCE / CMakeで最初のPluginを起動する

## 今日作るもの

音はまだ変えない **Mini Digital Drive** のStandalone appとVST3 binaryをbuildします。

## 必要なもの

追加ハードウェアなし。

Windows側:

- Git
- CMake 3.22+
- Visual Studio C++ toolchain
- Internet connection（初回CMake configureでpinしたJUCEを取得）

## 今日の重要概念

- framework
- native build
- CMake configure / build
- Plugin format
- StandaloneとVST3の違い

## Hands-on

1. `PLUGIN-VERSIONS.md`を読む。
2. `plugin/work/CMakeLists.txt`を読む。全部理解しなくてよい。
3. PowerShellでrepo rootへ移動。
4. configure:

```powershell
cmake -S plugin/work -B build/plugin -G "Visual Studio 17 2022" -A x64
```

5. build:

```powershell
cmake --build build/plugin --config Debug
```

6. `Mini Digital Drive`のStandalone executableを探して起動。
7. ウィンドウに`P15: audio passes through unchanged`が表示されることを確認。
8. VST3 targetも生成されている場所を確認する。

## ここで理解すること

StandaloneとVST3は**DSPが別物なのではありません**。外側のhost形式が違います。

```text
Standalone wrapper ─┐
                    ├→ shared plugin code
VST3 wrapper ───────┘
```

## Challenge

- `PRODUCT_NAME`を一時的に変更してbuildし、binary名との関係を見る。
- DebugとReleaseをbuildして出力folderの違いを確認する。

## よくあるエラー

### CMakeがVisual Studioを見つけない

Visual Studio Installerで`Desktop development with C++`が入っているか確認。

### JUCE downloadで失敗

初回configureはnetworkが必要。途中で失敗したら`build/plugin`を消す前にerror本文を読む。

### VST3がDAWに出ない

このLessonではDAW scanをまだ合格条件にしない。Standaloneが起動すれば先へ進める。

## 合格条件

- configureとbuildの違いを説明できる
- Standaloneを起動できる
- VST3 binaryの場所を確認できる
- JUCE versionがpinされている理由を説明できる

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p15: build first juce plugin"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
