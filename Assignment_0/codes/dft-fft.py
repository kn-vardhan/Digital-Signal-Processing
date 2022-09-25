import numpy as np
from numpy.fft import fft, ifft
import matplotlib.pyplot as plt


x = np.array([1.0, 2.0, 3.0, 4.0, 2.0, 1.0])
dftmatrix = fft(np.eye(len(x))
X = x@dftmatrix
print(X)

