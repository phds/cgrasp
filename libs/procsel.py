from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def procsel((x1, x2, x3, x4, x5, x6, x7, b8, b9, b10, slacking_0, slacking_1, slacking_2)):
	restriction_0=(-0.9*x6+x7-0)**2
	restriction_1=(exp(x3)-x1-1)**2
	restriction_2=(exp(0.833333333333333*x4)-x2-1)**2
	restriction_3=(-x3-x4-x5+x6-0)**2
	restriction_4=((x7-2*b8+slacking_0)-0)**2
	restriction_5=((x3-4*b9+slacking_1)-0)**2
	restriction_6=((x4-5*b10+slacking_2)-0)**2
	objective_function=1.8*x1+1.8*x2+x3+1.2*x4+7*x5-11*x7+3.5*b8+b9+1.5*b10-0
	return (objective_function - (-1.9231))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6