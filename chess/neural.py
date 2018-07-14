import math
import numpy as np
from random import *

def sig(x):
    return 1/(1+math.exp(-x))

def dx(x):
    return sig(x)*(1-sig(x))

input = [[1,0,0],[1,0,1],[0,0,1]]
output = [0,1,1]
weights = np.zeros(3)
print input
print output
print weights


print dx(0)
