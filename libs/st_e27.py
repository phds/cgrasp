from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def st_e27((b1, b2, x3, x4, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5)):
	restriction_0=((-x3+3*x4+slacking_0)-5)**2
	restriction_1=((2*x3-x4+slacking_1)-5)**2
	restriction_2=((-2*x3+x4+slacking_2)-0)**2
	restriction_3=((x3-3*x4+slacking_3)-0)**2
	restriction_4=((-6*b1+x3+slacking_4)-0)**2
	restriction_5=((-5*b2+x4+slacking_5)-0)**2
	objective_function=-(-(4*x3-sqr(x3)-sqr(x4)+2*x4)-2*b1-2*b2+0)
	return (objective_function - (2.0))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5