from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def batchdes((b1, b2, b3, b4, b5, b6, b7, b8, b9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7, slacking_8, slacking_9, slacking_10, slacking_11, slacking_12)):
	restriction_0=((x10-x13-slacking_0)-0.693147180559945)**2
	restriction_1=((x11-x13-slacking_1)-1.09861228866811)**2
	restriction_2=((x12-x13-slacking_2)-1.38629436111989)**2
	restriction_3=((x10-x14-slacking_3)-1.38629436111989)**2
	restriction_4=((x11-x14-slacking_4)-1.79175946922805)**2
	restriction_5=((x12-x14-slacking_5)-1.09861228866811)**2
	restriction_6=((x15+x17-slacking_6)-2.07944154167984)**2
	restriction_7=((x15+x18-slacking_7)-2.99573227355399)**2
	restriction_8=((x15+x19-slacking_8)-1.38629436111989)**2
	restriction_9=((x16+x17-slacking_9)-2.30258509299405)**2
	restriction_10=((x16+x18-slacking_10)-2.484906649788)**2
	restriction_11=((x16+x19-slacking_11)-1.09861228866811)**2
	restriction_12=((200000*exp(x15-x13)+150000*exp(x16-x14)+slacking_12)-6000)**2
	restriction_13=(-0.693147180559945*b4-1.09861228866811*b7+x17-0)**2
	restriction_14=(-0.693147180559945*b5-1.09861228866811*b8+x18-0)**2
	restriction_15=(-0.693147180559945*b6-1.09861228866811*b9+x19-0)**2
	restriction_16=(b1+b4+b7-1)**2
	restriction_17=(b2+b5+b8-1)**2
	restriction_18=(b3+b6+b9-1)**2
	objective_function=-(-(250*exp(0.6*x10+x17)+500*exp(0.6*x11+x18)+340*exp(0.6*x12+x19))+0)
	return (objective_function - (167427.6571))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17+restriction_18