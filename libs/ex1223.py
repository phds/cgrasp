from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def ex1223((x1, x2, x3, x4, x5, x6, x7, b8, b9, b10, b11, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7, slacking_8)):
	restriction_0=((x1+x2+x3+b8+b9+b10+slacking_0)-5)**2
	restriction_1=((sqr(x6)+sqr(x1)+sqr(x2)+sqr(x3)+slacking_1)-5.5)**2
	restriction_2=((x1+b8+slacking_2)-1.2)**2
	restriction_3=((x2+b9+slacking_3)-1.8)**2
	restriction_4=((x3+b10+slacking_4)-2.5)**2
	restriction_5=((x1+b11+slacking_5)-1.2)**2
	restriction_6=((sqr(x5)+sqr(x2)+slacking_6)-1.64)**2
	restriction_7=((sqr(x6)+sqr(x3)+slacking_7)-4.25)**2
	restriction_8=((sqr(x5)+sqr(x3)+slacking_8)-4.64)**2
	restriction_9=(x4-b8-0)**2
	restriction_10=(x5-b9-0)**2
	restriction_11=(x6-b10-0)**2
	restriction_12=(x7-b11-0)**2
	objective_function=-(-(sqr(x4-1)+sqr(x5-2)+sqr(x6-1)-log(1+x7)+sqr(x1-1)+sqr(x2-2)+sqr(x3-3))+0)
	return (objective_function - (4.5796))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12