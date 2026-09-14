# P21 — State保存・復元・Preset

## 今日作るもの

DAW projectを閉じても設定が戻り、A/BできるPlugin。

## 新しい知識

- `copyState()`
- `replaceState()`
- `getStateInformation()`
- `setStateInformation()`
- presetとparameter state

## Hands-on

1. APVTS stateをbinaryへserialize。
2. binaryからstateをrestore。
3. DRIVE/SAT/TONE/LEVELを変更。
4. host projectを保存→閉じる→開く。
5. 値が戻ることを確認。
6. 2つの簡単なpreset値を手動で記録しA/B。

## Parameter IDの重要性

保存stateはIDへ依存します。公開後に`drive`を`gainKnob`へ変えるだけでも互換性問題になり得ます。

## Challenge

`Clean-ish`と`Heavy`の2設定をREADMEへ記録し、同じ入力で比較。

## 合格条件

- stateとDSP objectそのものを混同しない
- project再読込後に値が復元する
- parameter IDが保存互換性に関係することを説明できる

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p21: persist state and compare presets"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
