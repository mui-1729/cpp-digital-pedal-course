# P15 — JUCE / CMakeで最初のPluginを起動する

## 今日作るもの

音はまだ変えない **Mini Digital Drive** のStandalone appとVST3 binaryをbuildします。

## 必要なもの

追加ハードウェアなし。

Windows側:

- Git
- current CMake
- current Visual Studio + C++ toolchain
  - 2026-09-15時点ではVisual Studio 2026
  - `Desktop development with C++`
- Internet connection（初回CMake configureでpinしたJUCEを取得）

## 今日の重要概念

- framework
- native build
- CMake configure / build
- Plugin format
- StandaloneとVST3の違い
- version pin

## Hands-on

1. `PLUGIN-VERSIONS.md`を読む。
2. PowerShellで確認する。

```powershell
git --version
cmake --version
```

3. `plugin/work/CMakeLists.txt`を読む。全部理解しなくてよい。
4. 特に次を確認する。
   - JUCE versionが`GIT_TAG`でpinされている
   - `FORMATS VST3 Standalone`
   - `juce_generate_juce_header(MiniDigitalDrive)`がある
5. **Developer PowerShell for Visual Studio**を開き、repo rootへ移動。
6. configureする。Visual Studio世代名は固定しない。

```powershell
cmake -S plugin/work -B build/plugin
```

7. buildする。

```powershell
cmake --build build/plugin --config Debug
```

8. `Mini Digital Drive`のStandalone executableを探して起動。
9. ウィンドウに`P15: audio passes through unchanged`が表示されることを確認。
10. VST3 targetも生成されている場所を確認する。
11. 実際に使ったCMake / Visual Studio / MSVC versionを`PLUGIN-VERSIONS.md`のLocal recordへ記録する。

## Generatorで失敗した場合

まず利用可能なgeneratorを確認する。

```powershell
cmake --help
```

複数のVisual Studio世代が入っているなど、CMakeが意図しないものを選ぶ場合だけ`-G`を明示します。ネットの記事にある`Visual Studio 17 2022`を理由なく固定しないこと。

## ここで理解すること

StandaloneとVST3は**DSPが別物なのではありません**。外側のhost形式が違います。

```text
Standalone wrapper ─┐
                    ├→ shared plugin code
VST3 wrapper ───────┘
```

P15ではまだDSPを書きません。まず「frameworkをbuildできる」ことと「音声処理を書く」ことを分離します。

## Challenge

- `PRODUCT_NAME`を一時的に変更してbuildし、binary名との関係を見る。その後元へ戻す。
- DebugとReleaseをbuildして出力folderの違いを確認する。

## よくあるエラー

### CMakeがC++ compilerを見つけない

Visual Studio Installerで`Desktop development with C++`が入っているか確認し、通常のPowerShellではなくDeveloper PowerShellでも試す。

### JUCE downloadで失敗

初回configureはnetworkが必要。途中で失敗したら`build/plugin`を消す前にerror本文を読む。

### `JuceHeader.h`が見つからない

`CMakeLists.txt`に`juce_generate_juce_header(MiniDigitalDrive)`があるか確認し、configureからやり直す。

### VST3がDAWに出ない

このLessonではDAW scanをまだ合格条件にしない。Standaloneが起動し、VST3 binaryの生成場所を確認できれば先へ進める。

## 合格条件

- configureとbuildの違いを説明できる
- Standaloneを起動できる
- VST3 binaryの場所を確認できる
- JUCE versionがpinされている理由を説明できる
- 自分が使用したtoolchain versionを記録した

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p15: build first juce plugin"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
