# P23 — Pluginを壊して検証する

## 今日作るもの

「自分のPCでは鳴った」から「条件を変えても壊れにくい」へ進めます。

## Test matrix

最低限:

| Test | Cases |
|---|---|
| sample rate | 44.1 / 48 / 96 kHz |
| channel | mono / stereo |
| block size | hostで選べる複数値 |
| input | silence / sine / sweep / transient |
| parameter | min / max / rapid movement |
| transport | play / stop / seek |
| state | save / reload |
| bypass | repeated toggle |

## Hands-on

1. `tools/generate_test_audio.py`でtest WAVを生成。
2. Standalone/hostで異なるsample rateを試す。
3. mono/stereoを試す。
4. parameterを端まで振る。
5. silence入力でNaN/異常値が出ないか確認。
6. pluginvalのcurrent binary/releaseを確認。
7. VST3へvalidatorを実行。
8. 結果を`plugin/VALIDATION.md`へ記録。

## pluginvalについて

external binaryとして使います。教材projectへsource統合はしません。pluginval側のJUCE versionと教材側JUCE versionを無理に一致させる必要がないためです。

## Challenge

意図的にLEVEL上限を大きくしてclipを発生させ、meter/testで発見して戻す。

## 合格条件

- validation matrixを一通り実行
- crash/無音/clipの再現条件を記録できる
- validatorを「音が良いか判定するもの」と誤解しない

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p23: validate plugin across host conditions"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
