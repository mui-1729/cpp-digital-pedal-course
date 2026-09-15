# C++で作るデジタル・ギターエフェクター入門

paiza C++体験編とDランク問題を終えた人が、**C++ → DSP → PCプラグイン → マイコン → ギター用電子回路 → 実機ペダル**まで一本の流れで学ぶハンズオン教材です。

## この教材の前提

- C++で `cout` / `cin` / 変数 / `if` / `for` / `while` を一度は使ったことがある
- 完璧な文法暗記は不要
- 「必要になったC++を、その場で音の処理に使う」方式で進む
- Lesson 14まではPCだけ
- 推奨ルートでは、その後もPlugin Trackを終えるまで追加ハードウェア購入0円
- ギターが手元にない日でも、生成したテスト信号や録音済みWAVで進められる

## 2つの最終成果物

Lesson 00〜14で共通のDSPエンジンを作った後、2つのTrackへ分岐します。

```text
Lesson 00〜14
C++ + DSP 共通編
      │
      ▼
  PedalEngine
   /      \
  /        \
Plugin     Hardware
Track      Track
  │          │
  ▼          ▼
VST3 /      Daisy Seed3
Standalone  実機ペダル
```

### Plugin Track

PCだけで **Mini Digital Drive** を作ります。

- VST3
- Standalone app
- DRIVE / SAT / TONE / LEVEL / BYPASS
- GUI
- parameter automation
- state / preset
- meter
- plugin validation
- release checklist

### Hardware Track

同じDSPをDaisy Seed3へ移植します。

- GPIO / LED / switch
- ADC / POT
- real-time audio callback
- HX Stomp経由の実ギター確認
- guitar input / output circuit
- enclosure
- 最終的にケース入りデジタルペダル

## 推奨ルート

```text
00〜14 共通編
   ↓
P15〜P24 Plugin Track
   ↓
「このDSPを実物にしたい」と思ったら
   ↓
15〜24 Hardware Track
```

先に実機へ行きたい場合は、Lesson 14からHardware 15へ直接進んでも構いません。

## 教材の進め方

各Lessonは原則として次の順で進みます。

1. **今日作るものを見る**
2. 既存コードを動かす
3. 新しい概念を必要な分だけ学ぶ
4. 自分で変更する
5. Challengeを解く
6. 合格条件を満たす
7. Gitでcheckpointを残す

Plugin Trackは複数ファイルの実プロジェクトを育てるため、`starter/solution`を毎回丸ごと複製せず、`plugin/work/`をLessonごとに更新していきます。最終形は`plugin/reference-final/`で確認できます。

## 全体構成

詳しくは [CURRICULUM.md](CURRICULUM.md) を参照してください。

- Phase 0: 開発環境
- Phase 1: C++基礎 × エフェクター
- Phase 2: DSP基礎
- Plugin Track: JUCE / VST3 / Standalone
- Hardware Track Phase 3: Daisy Seed3
- Hardware Track Phase 4: 実ギター
- Hardware Track Phase 5: ギター用電子回路
- Hardware Track Phase 6: ケース入りペダル

## 最初に読むファイル

1. [SETUP.md](SETUP.md)
2. [CURRICULUM.md](CURRICULUM.md)
3. [MATERIALS.md](MATERIALS.md)
4. [BUDGET.md](BUDGET.md)
5. [SAFETY.md](SAFETY.md)
6. [PROGRESS.md](PROGRESS.md)
7. [lessons/00-course-setup/README.md](lessons/00-course-setup/README.md)

Plugin Track開始時は [PLUGIN-TRACK.md](PLUGIN-TRACK.md) と [PLUGIN-VERSIONS.md](PLUGIN-VERSIONS.md) も読みます。

## 買い物ルール

**推奨ルートならPlugin Track修了まで追加ハードウェア0円**です。

- Lesson 00〜14: PCのみ
- P15〜P24: PCのみ。DAWは必須ではなくStandaloneで進められる
- Hardware 15直前: Daisy Seed3 + breadboard + 基本電子部品
- Hardware 20: 手持ちのHX Stompとギターを活用可能
- Hardware 21以降: ギター入出力回路用部品
- Hardware 24: ケース、ジャック、フットスイッチなど

詳細は [MATERIALS.md](MATERIALS.md)。

## コードの中心

共通DSPはJUCEにもDaisyにも依存させません。

```text
shared/dsp/
└── PedalEngine.h
       ↑
       ├── plugin/
       └── hardware/
```

「音を変えるロジック」と「PC/実機の入出力」を分離すること自体が、この教材の重要な学習目標です。

## Source of truth

API・framework・hardwareは更新されるため、[SOURCES.md](SOURCES.md) に一次資料をまとめています。

- Plugin Track: JUCE / Steinberg VST3 / pluginval の公式情報
- Hardware Track: Daisy / libDaisy の公式情報
- Lesson 21以降の回路値: **作業時点のSeed3公式資料を再確認してから確定**

## 安全

Hardware Trackでは [SAFETY.md](SAFETY.md) を必ず読んでください。特にアンプの **SPEAKER OUTをDaisy / HX Stomp / PCへ接続しない**こと。
