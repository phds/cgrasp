from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def gear4((i1, i2, i3, i4, x6, x7)):
	restriction_0=(-1000000*i1*i2/(i3*i4)-x6+x7+144279.32477276)**2
	objective_function=-(0-x6-x7)
	return (objective_function - (1.643428))**2+restriction_0