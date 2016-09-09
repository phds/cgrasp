from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def st_e13((b1, x2, slacking_0, slacking_1)):
	restriction_0=((-sqr(x2)-b1+slacking_0)+1.25)**2
	restriction_1=((b1+x2+slacking_1)-1.6)**2
	objective_function=-(-b1-2*x2+0)
	return (objective_function - (2))**2+restriction_0+restriction_1