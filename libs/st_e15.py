from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def st_e15((x1, x2, b3, b4, b5, slacking_0, slacking_1, slacking_2)):
	restriction_0=(pow(x1,2)+b3-1.25)**2
	restriction_1=(x2**1.5+1.5*b4-3)**2
	restriction_2=((x1+b3+slacking_0)-1.6)**2
	restriction_3=((1.333*x2+b4+slacking_1)-3)**2
	restriction_4=((-b3-b4+b5+slacking_2)-0)**2
	objective_function=-(-2*x1-3*x2-1.5*b3-2*b4+0.5*b5+0)
	return (objective_function - (7.66718))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4