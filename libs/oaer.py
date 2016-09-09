from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def oaer((x1, x2, x3, x4, x5, x6, b7, b8, b9, slacking_0, slacking_1, slacking_2, slacking_3)):
	restriction_0=(-log(1+x1)+x4-0)**2
	restriction_1=(-1.2*log(1+x2)+x5-0)**2
	restriction_2=(-0.9*x3-0.9*x4-0.9*x5+x6-0)**2
	restriction_3=((x6-b7+slacking_0)-0)**2
	restriction_4=((x4-1.111111*b8+slacking_1)-0)**2
	restriction_5=((x5-1.111111*b9+slacking_2)-0)**2
	restriction_6=((b8+b9+slacking_3)-1)**2
	objective_function=-(-1.8*x1-1.8*x2-7*x3-x4-1.2*x5+11*x6-3.5*b7-b8-1.5*b9+0)
	return (objective_function - (-1.9231))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6