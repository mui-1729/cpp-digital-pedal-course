import csv
import matplotlib.pyplot as plt

with open("wave.csv") as f:
    rows = list(csv.DictReader(f))

x = [int(row["index"]) for row in rows]
y = [float(row["value"]) for row in rows]

plt.plot(x, y)
plt.xlabel("Sample Index")
plt.ylabel("Amplitude")
plt.title("440 Hz Sine Wave")
plt.grid()
plt.savefig("wave.png")