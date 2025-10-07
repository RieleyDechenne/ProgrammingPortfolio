import matplotlib.pyplot as plt
import numpy as np

weights = np.random.normal(loc=15, scale=5, size=30)
weights = np.clip(weights, 0, 30)

plt.xlabel("Tournament Weight")
plt.ylabel("# of Anglers")
plt.hist(weights, bins=5,
                  color="cyan",
                  edgecolor="black")

plt.show()