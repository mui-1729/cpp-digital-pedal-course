# P18 — Plugin ParameterとAutomation

## 今日作るもの

Host/Standaloneから操作できる`DRIVE / TONE / LEVEL / BYPASS` parameter。

まだ自作4ノブGUIは作りません。P18ではJUCE標準の**GenericAudioProcessorEditor**を一時的に使い、Parameterの仕組みだけに集中します。

## 新しい知識

- parameter ID
- `AudioProcessorValueTreeState` (APVTS)
- parameter range / default
- host automation
- raw parameter value
- Generic Editor

## Hands-on

1. `PluginProcessor`へAPVTSを追加する。
2. `CreateParameterLayout()`をstatic関数として用意する。
3. `drive`, `tone`, `level`, `bypass`を登録する。

最初のrange例:

```text
DRIVE  1.0 ... 12.0
TONE   0.0 ... 1.0
LEVEL  0.0 ... 1.0
BYPASS bool
```

4. constructorでAPVTSを初期化する。
5. `processBlock()`で`getRawParameterValue()`から値を読み、各`PedalEngine`へ渡す。
6. P20までは`createEditor()`を一時的に次のようにする。

```cpp
juce::AudioProcessorEditor* MiniDigitalDriveAudioProcessor::createEditor() {
    return new juce::GenericAudioProcessorEditor(*this);
}
```

JUCEのGeneric Editorは、登録済みAudioProcessor parameterをslider/switchとして自動表示します。

7. Standaloneをbuildして起動。
8. Generic EditorにDRIVE / TONE / LEVEL / BYPASSが出ることを確認。
9. 値を動かし、音声入力がある場合はDSPへ反映されることを確認する。
10. VST3 host/DAWを使える場合だけautomation laneも試す。**DAWはP18の必須条件ではない**。

## なぜ普通のmember変数ではだめ？

例えば、

```cpp
float drive = 4.0f;
```

だけではPlugin Hostからその値の存在が見えません。

Parameterとして公開すると、

```text
Host / Standalone Generic Editor
          ↓
      Parameter
          ↓
     audio thread
          ↓
     PedalEngine
```

という経路を作れます。

## Parameter IDを軽く変えない

表示名`Drive`と内部ID`drive`は役割が違います。後のstate保存やhost automationはIDへ依存するため、公開後にIDを気軽に変更すると互換性を壊す可能性があります。

## P19への布石

P18では理解を優先し、Parameter値をそのままDSPへ反映して構いません。急な値変更でclick/zipper noiseが起きる可能性は、**P19でsmoothingを入れて解決**します。

## Challenge

- DRIVEのrangeを一時的に`1 ... 100`へ広げ、操作性と音の変化を確認してから戻す。
- 表示名だけ`Drive`→`Gain`へ変えた場合と、ID`drive`を変える場合の違いを説明する。
- Generic Editorを使うことで「GUIの見た目」と「Parameterの機能」を分けて学べる理由を考える。

## よくあるエラー

### Generic Editorにparameterが出ない

- `CreateParameterLayout()`へ追加したか
- APVTS constructorへlayoutを渡したか
- `createEditor()`が`GenericAudioProcessorEditor`を返しているか

を確認する。

### Parameterは動くのに音が変わらない

`processBlock()`でParameter値を読んだだけで、`PedalEngine`へ渡し忘れていないか確認する。

## 合格条件

- Parameterと普通のmember変数の違いを説明できる
- Standaloneだけで4 Parameterを操作できる
- IDを後から軽率に変更しない理由を理解している
- host automationがParameterを介してDSPへ届く流れを説明できる

## Git checkpoint

```bash
git status
git diff
git add .
git commit -m "plugin p18: add automatable parameters"
```

合格条件を満たしてから次へ進みます。P20でGeneric Editorを自作4ノブGUIへ置き換えます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
