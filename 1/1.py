import numpy as np
import matplotlib.pyplot as plt

N, rN = np.genfromtxt('build/output.txt', unpack=True)
plt.plot(N, np.sqrt(rN), 'x')
plt.xlabel("$N$")
plt.ylabel("$R_N$")
plt.savefig('build/1.pdf')
