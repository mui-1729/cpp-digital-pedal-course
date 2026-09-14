# Fault tree

## Power LEDすら点かない

power source → polarity → regulator → 3.3/5V rail → Seed

## LEDは動く、音がない

passthrough firmware → input stage → Seed audio in → Seed audio out → output stage → jack

## 音は出る、effectだけ効かない

POT ADC → parameter mapping → bypass bool → PedalEngine

## ノイズ

power source → reference/bias → grounding → callback underrun → analog layout → cable/routing
