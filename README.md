# C++で作るデジタル・ギターエフェクター入門

paiza C++体験編とDランク問題を終えた人が、**C++ → DSP → マイコン → ギター用電子回路 → 実機ペダル**まで一本の流れで学ぶためのハンズオン教材です。

## この教材の前提

- C++で `cout` / `cin` / 変数 / `if` / `for` / `while` を一度は使ったことがある
- 完璧な文法暗記は不要
- 「必要になったC++を、その場でエフェクターに使う」方式で進む
- 前半はPCだけ。Daisy Seed3などは購入タイミングまで買わない

## 最終ゴール

自分で以下を説明・実装・配線・デバッグできる状態を目指します。

```text
Guitar
  ↓
Instrument Input / Buffer
  ↓
Daisy Seed3
  ↓
C++ DSP
  ├─ Gain
  ├─ Distortion
  ├─ Tone
  └─ Output Level
  ↓
Output Stage
  ↓
Amp / HX Stomp / Audio Interface
```

最終制作は、GAIN / TONE / LEVEL、フットスイッチ、LEDを備えた小型デジタルドライブです。

## 教材の進め方

各回は次の順で進みます。

1. **今日作るものを見る**
2. `starter/` を自分で変更する
3. 動かして結果を確認する
4. READMEの解説を読む
5. Challengeを解く
6. `solution/` で答え合わせする
7. 合格条件を満たしたら次へ進む
8. Gitでcheckpointを残す

完成コードを最初から写すことは推奨しません。

## 25回の全体像

詳しくは [CURRICULUM.md](CURRICULUM.md) を参照してください。

- Phase 0: 準備
- Phase 1: C++基礎 × エフェクター
- Phase 2: DSP基礎
- Phase 3: Daisy Seed3 / 物理世界
- Phase 4: 実ギターをリアルタイム処理
- Phase 5: ギター用電子回路
- Phase 6: ケース入りペダル完成

## まず読むファイル

1. [SETUP.md](SETUP.md)
2. [MATERIALS.md](MATERIALS.md)
3. [SAFETY.md](SAFETY.md)
4. [BUDGET.md](BUDGET.md)
5. [PROGRESS.md](PROGRESS.md)
6. [lessons/00-course-setup/README.md](lessons/00-course-setup/README.md)

## 買い物ルール

**第14回までは追加購入0円で進める**設計です。

- 第15回直前: Daisy Seed3 + breadboard + 基本電子部品
- 第20回まではHX Stompを信号レベル調整の橋渡しに利用可能
- 第21回以降: ギター入力/出力回路用部品
- 第24回: ケース、ジャック、フットスイッチなど

詳細は [MATERIALS.md](MATERIALS.md)。

## 大事なルール

- アンプの **SPEAKER OUTを絶対にDaisy / HX Stomp / PCへ接続しない**
- DaisyのADCには規定範囲外の電圧を入れない
- 配線変更は原則として電源OFFで行う
- 最初はヘッドホン/アンプ音量を十分下げる
- 実機回路は、使用時点のSeed3公式資料を再確認する

安全については [SAFETY.md](SAFETY.md) を必ず読んでください。

## コードの方針

PC編は以下でビルドします。

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o app
./app
```

`-Wall -Wextra -Wpedantic` を最初から使い、警告を無視しない習慣を付けます。

Daisy編ではlibDaisy公式のプロジェクト構成に切り替えます。

## Source of truth

ハードウェアやAPIは更新されるため、[SOURCES.md](SOURCES.md) に一次資料をまとめています。
特にLesson 21以降の回路値は、教材作成時点の記憶ではなく**その時点のSeed3公式資料**を確認してから確定します。

## 補助資料

- [CHECK-ANSWERS.md](CHECK-ANSWERS.md) — 確認問題の解答
- [LEARNING-LOG.md](LEARNING-LOG.md) — 学習記録
- [HARDWARE-VERSIONS.md](HARDWARE-VERSIONS.md) — 実機version固定
- [IMPORT-TO-GITHUB.md](IMPORT-TO-GITHUB.md) — GitHubへ移す
- [TROUBLESHOOTING.md](TROUBLESHOOTING.md) — 切り分け
