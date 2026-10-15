import csv
import matplotlib.pyplot as plt

with open("clip.csv") as f:
    rows = list(csv.DictReader(f))

x = list(range(len(rows)))
original = [float(r["input"]) for r in rows]
hard = [float(r["hard"]) for r in rows]
soft = [float(r["soft"]) for r in rows]

plt.plot(x, original, label="Original")
plt.plot(x, hard, label="Hard Clip")
plt.plot(x, soft, label="Soft Clip")

plt.xlabel("Sample Index")
plt.ylabel("Amplitude")
plt.legend()
plt.grid()
plt.savefig("clip.png")
plt.show()