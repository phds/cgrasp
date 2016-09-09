from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def csched1((x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60, b61, b62, b63, b64, b65, b66, b67, b68, b69, b70, b71, b72, b73, b74, b75, b76, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7, slacking_8, slacking_9)):
	restriction_0=(-1300*x1+x7+350*x13-0)**2
	restriction_1=(-1000*x2+x8+300*x13-0)**2
	restriction_2=(-1100*x3+x9+300*x13-0)**2
	restriction_3=((x7-300*x13+slacking_0)-0)**2
	restriction_4=((x8-300*x13+slacking_1)-0)**2
	restriction_5=((x9-300*x13+slacking_2)-0)**2
	restriction_6=(x4-0.01*b14-b15-2*b16-3*b17-4*b18-5*b19-6*b20-7*b21-8*b22-9*b23-10*b24-11*b25-12*b26-13*b27-14*b28-15*b29-16*b30-17*b31-18*b32-19*b33-20*b34-0)**2
	restriction_7=(x5-0.01*b35-b36-2*b37-3*b38-4*b39-5*b40-6*b41-7*b42-8*b43-9*b44-10*b45-11*b46-12*b47-13*b48-14*b49-15*b50-16*b51-17*b52-18*b53-19*b54-20*b55-0)**2
	restriction_8=(x6-0.01*b56-b57-2*b58-3*b59-4*b60-5*b61-6*b62-7*b63-8*b64-9*b65-10*b66-11*b67-12*b68-13*b69-14*b70-15*b71-16*b72-17*b73-18*b74-19*b75-20*b76-0)**2
	restriction_9=(-b14-b15-b16-b17-b18-b19-b20-b21-b22-b23-b24-b25-b26-b27-b28-b29-b30-b31-b32-b33-b34+1)**2
	restriction_10=(-b35-b36-b37-b38-b39-b40-b41-b42-b43-b44-b45-b46-b47-b48-b49-b50-b51-b52-b53-b54-b55+1)**2
	restriction_11=(-b56-b57-b58-b59-b60-b61-b62-b63-b64-b65-b66-b67-b68-b69-b70-b71-b72-b73-b74-b75-b76+1)**2
	restriction_12=(-x1-2*x4+x10-0)**2
	restriction_13=(-x2-3*x5+x11-0)**2
	restriction_14=(-x3-3*x6+x12-0)**2
	restriction_15=((x10+x11+x12-x13+slacking_3)-0)**2
	restriction_16=((x1+150*b14+slacking_4)-150)**2
	restriction_17=((x2+150*b35+slacking_5)-150)**2
	restriction_18=((x3+150*b56+slacking_6)-150)**2
	restriction_19=((x4-slacking_7)-1)**2
	restriction_20=((x5-slacking_8)-1)**2
	restriction_21=((x6-slacking_9)-1)**2
	objective_function=-((-x13*0)-(416000*x4*(1-exp(-0.1*x1/x4))+37440*x1-100*x4+124615.384615385*x5*(1-exp(-0.13*x2/x5))+9000*x2-90*x5+278666.666666667*x6*(1-exp(-0.09*x3/x6))+15840*x3-80*x6))
	return (objective_function - (-30639.2578))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17+restriction_18+restriction_19+restriction_20+restriction_21