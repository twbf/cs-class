import math
import numpy as np
from random import *

#inputs = [[1,0,0],[1,0,1],[0,0,1]]
y = np.array([0,1,1])
x = np.array([[1,0,0],[1,0,1],[0,0,1]])
w = np.random.random(3) # weights
b = 0.5  # bias


def sig(x):
    return 1/(1+math.exp(-x))

def dx(x):
    return sig(x)*(1-sig(x))

def optimization():
    x0 = sig(np.sum(np.multiply(x[0],w))-b)
    x1 = sig(np.sum(np.multiply(x[1],w))-b)
    x2 = sig(np.sum(np.multiply(x[2],w))-b)
    nueron = (y[0]-x0)**2+(y[1]-x1)**2+(y[1]-x1)**2
    print nueron

print x
print w
#print np.multiply(x,w)

optimization()
