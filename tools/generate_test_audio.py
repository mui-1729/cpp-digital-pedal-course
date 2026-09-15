from __future__ import annotations

import math
import struct
import wave
from pathlib import Path

SAMPLE_RATE = 48_000
DURATION = 5.0
AMP = 0.25
OUT_DIR = Path(__file__).resolve().parents[1] / "test-audio" / "generated"


def write_wav(path: Path, samples: list[float]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)

    with wave.open(str(path), "wb") as wav:
        wav.setnchannels(1)
        wav.setsampwidth(2)
        wav.setframerate(SAMPLE_RATE)

        frames = bytearray()
        for sample in samples:
            sample = max(-1.0, min(1.0, sample))
            frames.extend(struct.pack("<h", round(sample * 32767.0)))

        wav.writeframes(frames)


def sine(freq: float, duration: float = DURATION) -> list[float]:
    count = int(SAMPLE_RATE * duration)
    return [
        AMP * math.sin(2.0 * math.pi * freq * n / SAMPLE_RATE)
        for n in range(count)
    ]


def two_tone() -> list[float]:
    count = int(SAMPLE_RATE * DURATION)
    return [
        0.16 * math.sin(2.0 * math.pi * 110.0 * n / SAMPLE_RATE)
        + 0.12 * math.sin(2.0 * math.pi * 1760.0 * n / SAMPLE_RATE)
        for n in range(count)
    ]


def logarithmic_sweep() -> list[float]:
    count = int(SAMPLE_RATE * DURATION)
    f0 = 80.0
    f1 = 8_000.0
    ratio = f1 / f0
    samples: list[float] = []

    for n in range(count):
        t = n / SAMPLE_RATE
        phase = (
            2.0
            * math.pi
            * f0
            * DURATION
            / math.log(ratio)
            * (ratio ** (t / DURATION) - 1.0)
        )
        samples.append(AMP * math.sin(phase))

    return samples


def transient_train() -> list[float]:
    count = int(SAMPLE_RATE * DURATION)
    samples = [0.0] * count
    interval = SAMPLE_RATE // 2

    for start in range(0, count, interval):
        length = min(400, count - start)
        for i in range(length):
            envelope = math.exp(-i / 70.0)
            samples[start + i] = 0.8 * envelope

    return samples


def main() -> None:
    write_wav(OUT_DIR / "sine-440.wav", sine(440.0))
    write_wav(OUT_DIR / "two-tone.wav", two_tone())
    write_wav(OUT_DIR / "sweep.wav", logarithmic_sweep())
    write_wav(OUT_DIR / "transient-train.wav", transient_train())

    print(f"generated test audio in: {OUT_DIR}")


if __name__ == "__main__":
    main()
