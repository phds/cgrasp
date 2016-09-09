from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def st_e38((i1, i2, x3, x4, slacking_0, slacking_1, slacking_2)):
	restriction_0=((-0.0625*i1+0.0193*x3+slacking_0)-0)**2
	restriction_1=((-0.0625*i2+0.00954*x3+slacking_1)-0)**2
	restriction_2=((3.1415927*(sqr(x3)*x4+1.33333333333333*pow(x3,3))-slacking_2)-1296000)**2
	objective_function=-(-(0.0389*i1*x3*x4+0.1111312*i2*sqr(x3)+0.012348046875*sqr(i1)*x4+0.0775*sqr(i1)*x3)+0)
	return (objective_function - (7.197727))**2+restriction_0+restriction_1+restriction_2