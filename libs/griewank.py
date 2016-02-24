from __future__ import division
import numpy as np
from math import cos,sqrt


def griewank(x):
	sum1 = sum( [(x[i]**2)/4000 for i in range(len(x))] )
	prod1 = np.prod( [cos(x[i]/sqrt(i+1)) for i in range(len(x))] )
	return sum1 - prod1 + 1

