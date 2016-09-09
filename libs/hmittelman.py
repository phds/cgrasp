from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def hmittelman((b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6)):
	restriction_0=((3*b5*b7*b9*b10*b14*b15*b16-12*b1*b2*b3*b4*b8*b11-8*b3*b4*b6*b7*b8+b3*b4*b8*b11-7*b1*b2*b11*b12+2*b13*b14*b15*b16+slacking_0)+2)**2
	restriction_1=((b1*b2*b3*b4*b8*b11-10*b3*b4*b6*b7*b8-5*b6*b7*b8*b12+b6*b7*b9*b14*b16+7*b9*b10*b14*b16+b5*b10*b14*b15*b16+slacking_1)+1)**2
	restriction_2=((5*b5*b7*b9*b10*b14*b15*b16-3*b1*b2*b3*b4*b8*b11-b3*b4*b6*b7*b8-2*b5*b10*b14*b15*b16+b13*b14*b15*b16+slacking_2)+1)**2
	restriction_3=((3*b1*b2*b3*b4*b8*b11-5*b5*b7*b9*b10*b14*b15*b16+b3*b4*b6*b7*b8+2*b5*b10*b14*b15*b16-b13*b14*b15*b16+slacking_3)-1)**2
	restriction_4=(((-4*b3*b4*b6*b7*b8)-2*b3*b4*b8*b11-5*b6*b7*b9*b14*b16+b9*b10*b14*b16-9*b5*b10*b14*b15*b16-2*b1*b2*b11*b12+slacking_4)+3)**2
	restriction_5=((9*b1*b2*b3*b4*b8*b11-12*b3*b4*b8*b11-7*b6*b7*b8*b12+6*b6*b7*b9*b14*b16+2*b5*b10*b14*b15*b16-15*b1*b2*b11*b12+3*b13*b14*b15*b16+slacking_5)+7)**2
	restriction_6=((5*b1*b2*b3*b4*b8*b11-8*b5*b7*b9*b10*b14*b15*b16+2*b3*b4*b6*b7*b8-7*b3*b4*b8*b11-b6*b7*b8*b12-5*b9*b10*b14*b16-10*b1*b2*b11*b12+slacking_6)+1)**2
	objective_function=-(-(10*b5*b7*b9*b10*b14*b15*b16+7*b1*b2*b3*b4*b8*b11+b3*b4*b6*b7*b8+12*b3*b4*b8*b11+8*b6*b7*b8*b12+3*b6*b7*b9*b14*b16+b9*b10*b14*b16+5*b5*b10*b14*b15*b16+3*b1*b2*b11*b12)+0)
	return (objective_function - (13))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6