from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def synthes1((x1, x2, x3, b4, b5, b6, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5)):
	restriction_0=((0.8*log(1+x2)+0.96*log(1+x1-x2)-0.8*x3-slacking_0)-0)**2
	restriction_1=((log(1+x2)+1.2*log(1+x1-x2)-x3-2*b6-slacking_1)+2)**2
	restriction_2=((-x1+x2+slacking_2)-0)**2
	restriction_3=((x2-2*b4+slacking_3)-0)**2
	restriction_4=((x1-x2-2*b5+slacking_4)-0)**2
	restriction_5=((b4+b5+slacking_5)-1)**2
	objective_function=-(-(-18*log(1+x2)-19.2*log(1+x1-x2)+10*x1)+7*x3-5*b4-6*b5-8*b6+0)
	return (objective_function - (6.0098))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5