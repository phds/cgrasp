from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def nvs04((i1, i2)):
	objective_function=-(-(100*sqr(0.5+i2-sqr(0.6+i1))+sqr(0.4-i1))+0)
	return (objective_function - 0.7200)**2