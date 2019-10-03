#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np

x, y = [], []
with open('results.txt', 'r') as f:
  for L in f:
    (x1, y1) = L.rstrip().split('\t') 
    x.append(int(x1)) 
    y.append(float(y1))

plt.scatter(x, y, alpha=0.3)
plt.show()
