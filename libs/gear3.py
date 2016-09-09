from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def gear3((x2, x3, x4, x5, i6, i7, i8, i9)):
	restriction_0=(x2-i6-0)**2
	restriction_1=(x3-i7-0)**2
	restriction_2=(x4-i8-0)**2
	restriction_3=(x5-i9-0)**2
	objective_function=-(-sqr(0.14427932477276-x2*x3/(x4*x5))+0)
	return (objective_function - (0))**2+restriction_0+restriction_1+restriction_2+restriction_3