# P22 — MeterとAudio Thread / Message Thread

## 今日作るもの

input/output level meter。

## 新しい知識

- audio thread
- message/UI thread
- `std::atomic`
- polling
- peak meter
- thread-safe data bridge

## やってはいけない構造

```text
audio thread
   ↓
GUI Componentを直接変更
```

代わりに:

```text
audio thread
   ↓
atomic<float>
   ↓
GUI Timer (30Hz程度)
   ↓
paint()
```

## Hands-on

1. Processorでinput peakを計算。
2. output peakを計算。
3. atomicへ保存。
4. Editor側Timerで値を読む。
5. `paint()`で簡単なbarを描く。
6. Plugin windowを閉じてもaudioが止まらないことを確認。

## Challenge

meter更新を5Hz / 30Hz / 120Hzで比較し、audio sample rateとの違いを説明。

## 合格条件

- audio threadとmessage threadを説明できる
- GUI更新を48000回/秒する必要がないと説明できる
- atomicを「何でもthread safeにする魔法」と誤解していない

## Git checkpoint

```bash
git status
git add .
git commit -m "plugin p22: add metering across threads"
```

合格条件を満たしてから次へ進みます。`plugin/reference-final/`は詰まった時か答え合わせ時だけ見ます。
