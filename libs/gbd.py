from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def gbd((x2, b3, b4, b5, slacking_0, slacking_1, slacking_2, slacking_3)):
	restriction_0=((3*x2-b3-b4+slacking_0)-0)**2
	restriction_1=((-x2+0.1*b4+0.25*b5+slacking_1)-0)**2
	restriction_2=((b3+b4+b5-slacking_2)-2)**2
	restriction_3=((b3+b4+2*b5-slacking_3)-2)**2
	objective_function=-(-5*sqr(x2)+0-b3-b4-b5)
	return (objective_function - (2.2))**2+restriction_0+restriction_1+restriction_2+restriction_3