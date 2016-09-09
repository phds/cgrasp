from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def alan((x1, x2, x3, x4, b6, b7, b8, b9, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4)):
	restriction_0=(x1+x2+x3+x4-1)**2
	restriction_1=(8*x1+9*x2+12*x3+7*x4-10)**2
	restriction_2=((x1-b6+slacking_0)-0)**2
	restriction_3=((x2-b7+slacking_1)-0)**2
	restriction_4=((x3-b8+slacking_2)-0)**2
	restriction_5=((x4-b9+slacking_3)-0)**2
	restriction_6=((b6+b7+b8+b9+slacking_4)-3)**2
	objective_function=x1*(4*x1+3*x2-x3)+x2*(3*x1+6*x2+x3)+x3*(x2-x1+10*x3)-0
	return (objective_function - 2.9250)**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6