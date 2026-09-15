# P21 — State保存・復元・Preset

## 今日作るもの

Standaloneを閉じても設定が戻り、同じ入力で設定A/Bを比較できるPlugin。

DAWがある場合は、DAW projectの保存/再読込でも同じ仕組みを確認します。

## 新しい知識

- `copyState()`
- `replaceState()`
- `getStateInformation()`
- `setStateInformation()`
- serialize / deserialize
- presetとparameter state

## Hands-on

1. `getStateInformation()`でAPVTSの`copyState()`を取得する。
2. ValueTreeをXMLへ変換し、`MemoryBlock`へ保存する。
3. `setStateInformation()`でbinary→XML→ValueTreeへ戻し、`replaceState()`する。
4. buildしてStandaloneを起動する。
5. DRIVE/SAT/TONE/LEVELを初期値から大きく変更する。
6. **通常の終了操作**でStandaloneを閉じる。
7. 再起動し、値が復元することを確認する。
8. `Clean-ish`と`Heavy`の2設定を`PRESETS.md`などへ数値として記録し、同じ入力でA/Bする。
9. VST3 Host/DAWがある場合は、projectを保存→閉じる→再読込してparameter stateが戻ることも確認する。

JUCEのStandalone wrapperは正常終了時にplugin stateを保存するため、**このLessonの必須確認にDAWは不要**です。強制終了では保存されない可能性があるので、普通にウィンドウを閉じて確認します。

## Stateの流れ

```text
APVTS Parameters
      ↓ copyState()
ValueTree
      ↓ XML / binary
Host or Standalone storage
      ↓
setStateInformation()
      ↓ replaceState()
APVTS Parameters
```

DSP objectそのものを丸ごとファイルへ保存するわけではありません。

## Real-time注意

`copyState()`はthread-safeですがlockを使うため、audio sampleを処理する`processBlock()`から呼ぶ処理ではありません。Hostがstateを要求する`getStateInformation()`側で使います。

## Parameter IDの重要性

保存stateはIDへ依存します。公開後に`drive`を`gainKnob`へ変えるだけでも互換性問題になり得ます。

表示ラベルを変えることと、永続化に使うIDを変えることを区別します。

## Challenge

- `Clean-ish`と`Heavy`の2設定を記録し、同じtest audioで比較する。
- いったん表示名だけ変えてstateが戻ることを確認し、元に戻す。
- 「なぜfilterの内部state（前sample値など）までは通常presetに保存しないのか」を考える。

## よくあるエラー

### 再起動したら初期値へ戻る

- `getStateInformation()`が空のままではないか
- `setStateInformation()`で`replaceState()`しているか
- Standaloneを強制killせず通常終了したか

を確認する。

### XMLは読めたのに値が戻らない

APVTS stateのroot tag/typeが一致しているか確認する。

## 合格条件

- Standalone再起動後に値が復元する
- stateとDSP objectそのものを混同しない
- serialize / deserializeの流れを説明できる
- `copyState()`をaudio sample loopで呼ばない理由を説明できる
- Parameter IDが保存互換性に関係することを説明できる

## Git checkpoint

```bash
git status
git diff
git add .
git commit -m "plugin p21: persist state and compare presets"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
