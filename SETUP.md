# PC開発環境

## Phase 0〜2: WSLでC++

確認:

```bash
g++ --version
git --version
```

サンプル:

```bash
mkdir hello-cpp
cd hello-cpp
code .
```

`main.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "hello pedal" << std::endl;
    return 0;
}
```

実行:

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

Git操作そのものを主目的にはしませんが、壊したら戻せる状態を維持します。

## Phase 3以降: Daisy

Daisy側はLesson 15到達時に最新版公式toolchain手順を確認して導入します。

Windows環境では、DaisyのUSB書き込み部分を無理にWSLへ寄せず、公式手順に沿ってWindows側toolchainを使う方針です。

この時点でREADMEを更新し、実際に導入したtoolchain / libDaisy versionを記録します。
