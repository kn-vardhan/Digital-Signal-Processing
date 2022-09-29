from matplotlib import pyplot as plt
import numpy as np

x = [1, 1]
for i in range(25): x.append(x[-1] + x[-2])
y = np.add(x[:25], x[2:])
plt.stem(range(25), y)
plt.grid()
plt.xlabel('$n$')
plt.ylabel('$y(n)$')
plt.tight_layout()
plt.savefig('../figs/2_2.png')

