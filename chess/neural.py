import math
import numpy as np
from random import *

#inputs = [[1,0,0],[1,0,1],[0,0,1]]
#output = [0,1,1]
input = np.array([1,0,0])
w = np.random.random(3) # weights
b = 0  # bias


def sig(x):
    return 1/(1+math.exp(-x))

def dx(x):
    return sig(x)*(1-sig(x))

def optimization():
    nueron = sig(np.sum(np.multiply(input,w))-b)
    print nueron



print input
print w
print np.multiply(input,w)

optimization()
