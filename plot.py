import numpy as np
import matplotlib.pyplot as plt

lcg_data = np.loadtxt("LCG_data.csv", skiprows=1)
mt_data = np.loadtxt("MT19937_data.csv", skiprows=1)
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

ax1.hist(lcg_data, bins=50, color='blue')
ax1.set_title("Histogram LCG")
ax1.set_xlabel("Value")
ax1.set_ylabel("Frequency")

ax2.hist(mt_data, bins=50, color='green')
ax2.set_title("Histogram MT19937")
ax2.set_xlabel("Value")

plt.tight_layout()
plt.show()


