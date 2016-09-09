from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def fac1((x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, b17, b18, b19, b20, b21, b22, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7)):
	restriction_0=((x1+x3+x5+x7+slacking_0)-100)**2
	restriction_1=((x2+x4+x6+x8+slacking_1)-200)**2
	restriction_2=((x9+x11+x13+x15+slacking_2)-150)**2
	restriction_3=((x10+x12+x14+x16+slacking_3)-120)**2
	restriction_4=(x1+x9-120*b17-0)**2
	restriction_5=(x2+x10-140*b17-0)**2
	restriction_6=(x3+x11-130*b18-0)**2
	restriction_7=(x4+x12-180*b18-0)**2
	restriction_8=(x5+x13-120*b19-0)**2
	restriction_9=(x6+x14-140*b19-0)**2
	restriction_10=(x7+x15-130*b20-0)**2
	restriction_11=(x8+x16-180*b20-0)**2
	restriction_12=((260*b17+310*b18-2500*b21+slacking_4)-0)**2
	restriction_13=((260*b19+310*b20-3200*b22+slacking_5)-0)**2
	restriction_14=((260*b17+310*b18-50*b21-slacking_6)-0)**2
	restriction_15=((260*b19+310*b20-50*b22-slacking_7)-0)**2
	restriction_16=(b17+b19-1)**2
	restriction_17=(b18+b20-1)**2
	objective_function=-(-(50*(x1+x2+x3+x4+x9+x10+x11+x12)**2.5+70*(x5+x6+x7+x8+x13+x14+x15+x16)**2.5+10*x1+15*x2+20*x3+10*x4+5*x5+5*x6+30*x7+10*x8+25*x9+20*x10+15*x11+20*x12+30*x13+10*x14+10*x15+30*x16)-2000*b21-2500*b22+0)
	return (objective_function - (1.6091261E+8))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17