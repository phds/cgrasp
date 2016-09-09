from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def ex1223a((x1, x2, x3, b4, b5, b6, b7, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7, slacking_8)):
	restriction_0=((x1+x2+x3+b4+b5+b6+slacking_0)-5)**2
	restriction_1=((sqr(x1)+sqr(x2)+sqr(x3)+b6+slacking_1)-5.5)**2
	restriction_2=((x1+b4+slacking_2)-1.2)**2
	restriction_3=((x2+b5+slacking_3)-1.8)**2
	restriction_4=((x3+b6+slacking_4)-2.5)**2
	restriction_5=((x1+b7+slacking_5)-1.2)**2
	restriction_6=((sqr(x2)+b5+slacking_6)-1.64)**2
	restriction_7=((sqr(x3)+b6+slacking_7)-4.25)**2
	restriction_8=((sqr(x3)+b5+slacking_8)-4.64)**2
	objective_function=-(-(sqr(x1-1)+sqr(x2-2)+sqr(x3-3))+b4+3*b5+b6+0.693147180559945*b7+0)
	return (objective_function - (4.579582))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8