from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def gear2((x2, x3, x4, x5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29)):
	restriction_0=(x2-b6-2*b7-4*b8-8*b9-16*b10-32*b11-0)**2
	restriction_1=(x3-b12-2*b13-4*b14-8*b15-16*b16-32*b17-0)**2
	restriction_2=(x4-b18-2*b19-4*b20-8*b21-16*b22-32*b23-0)**2
	restriction_3=(x5-b24-2*b25-4*b26-8*b27-16*b28-32*b29-0)**2
	objective_function=-(-sqr(0.14427932477276-x2*x3/(x4*x5))+0)
	return (objective_function - (0))**2+restriction_0+restriction_1+restriction_2+restriction_3