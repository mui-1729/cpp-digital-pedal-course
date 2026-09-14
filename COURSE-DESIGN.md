# Course Design Decisions

このファイルは「なぜこの順番なのか」を残す設計メモです。

## 1. C++とエフェクターを並列で学ぶ

文法を網羅してから制作するのではなく、関数→Gain、配列→Bufferのように即適用する。

## 2. 共通DSPをplatformから分離する

音を変えるコードはJUCEにもDaisyにも依存させない。

```text
shared/dsp/PedalEngine
      ↑          ↑
   Plugin      Daisy
```

これにより、DSPのbugとplatform I/Oのbugを分けてdebugできる。

## 3. PC DSPを先に完成させる

実機で「音が出ない」ときにC++ / DSP / 配線の全部を同時に疑わなくて済む。

## 4. Plugin Trackを推奨先行ルートにする

Lesson 14の後、追加ハードウェア0円で「使える完成品」を得られる。Plugin Trackでreal-time audio、parameter、state、threading、validationを経験してからDaisyへ行くと、組み込み側の理解も深くなる。

## 5. Hardware Trackは独立して開始可能にする

実機を早く触りたい場合、Lesson 14からHardware 15へ直接進める。Plugin Trackを必須依存にはしない。

## 6. DAWを必須にしない

最初はJUCE Standalone targetで動作確認する。VST3は後でDAW/hostへ読み込む。DAW選びで学習を止めない。

## 7. ギターを常時必須にしない

生成テスト信号と録音済みWAVで開発可能にする。実ギターは音作り・gain staging・最終A/Bで使う。

## 8. Plugin開発はWindows nativeで行う

共通C++はWSL、Plugin TrackはWindows native + MSVC + CMake。Windows上のVST3 host/Standaloneとの距離を短くし、WSL↔Windows audio/device問題を教材の本題にしない。

## 9. Framework versionを固定する

教材の再現性のためPlugin Track開始時点ではJUCE 9.0.2をpinする。最新版追従は別作業にし、学習中にframework更新で壊さない。

## 10. Licenceは「配布Gate」で確認する

VST3 SDKとJUCEは別のライセンス。学習中に法律の暗記はしないが、P24でその時点の公式EULA/SDK licenceを確認してからbinaryを公開する。

## 11. HX Stompを橋渡しにする

Hardware Trackでは実ギター体験を早めつつ、high-Z input circuit学習を後へ分離する。

## 12. Electronicsは必要になってから

Ohmの法則を延々解いてから作るのではなく、「ギターを直接入れたい→なぜbufferが要る？」から学ぶ。

## 13. 回路BOMを未来へ固定しない

Seed3はhardware資料更新がある。Lesson 21時点でcurrent official circuitを確認してfreezeする。

## 14. Real-time safetyを正式項目にする

audio thread/callback内でallocation / blocking I/O / heavy logging / lock待ちを避ける。単に音が出れば良い教材にしない。

## 15. Debuggingを成果物に含める

最終目標は「作れる」だけでなく「壊れたとき切り分けられる」。

## 16. Cost control

借りられる工具は借りる。oscilloscopeやPCBは初号機に必須としない。Plugin Trackは既存PCがあれば追加ハードウェア0円。

## 17. Version control

各LessonをGit commitにする。Plugin Trackは1つの実プロジェクトを育て、commit diffそのものを教材にする。
