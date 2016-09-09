from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def nous1((x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, b50, b51, slacking_0, slacking_1)):
	restriction_0=(x2+x3+x20+x21-300)**2
	restriction_1=(x6-x12-x13-0)**2
	restriction_2=(x7-x11-x14-x15-0)**2
	restriction_3=(x8-x10-x16-x17-0)**2
	restriction_4=(x9-x18-x19-0)**2
	restriction_5=(-x10*x40-0.333333333333333*x2+x22-0)**2
	restriction_6=(-x10*x41-0.333333333333333*x2+x23-0)**2
	restriction_7=(-x10*x42-0.333333333333333*x2+x24-0)**2
	restriction_8=(-x11*x37-0.333333333333333*x3+x25-0)**2
	restriction_9=(-x11*x38-0.333333333333333*x3+x26-0)**2
	restriction_10=(-x11*x39-0.333333333333333*x3+x27-0)**2
	restriction_11=(-(x6*x34+x7*x37)+x22-0)**2
	restriction_12=(-(x6*x35+x7*x38)+x23-0)**2
	restriction_13=(-(x6*x36+x7*x39)+x24-0)**2
	restriction_14=(-(x8*x40+x9*x43)+x25-0)**2
	restriction_15=(-(x8*x41+x9*x44)+x26-0)**2
	restriction_16=(-(x8*x42+x9*x45)+x27-0)**2
	restriction_17=(x22*x46-x6*x34-0)**2
	restriction_18=(x23*x47-x7*x38-0)**2
	restriction_19=(x26*x48-x8*x41-0)**2
	restriction_20=(x27*x49-x9*x45-0)**2
	restriction_21=(x12*x34+x14*x37+x16*x40+x18*x43+0.333333333333333*x20-30)**2
	restriction_22=(x12*x35+x14*x38+x16*x41+x18*x44+0.333333333333333*x20-50)**2
	restriction_23=(x12*x36+x14*x39+x16*x42+x18*x45+0.333333333333333*x20-30)**2
	restriction_24=(x13*x34+x15*x37+x17*x40+x19*x43+0.333333333333333*x21-70)**2
	restriction_25=(x13*x35+x15*x38+x17*x41+x19*x44+0.333333333333333*x21-50)**2
	restriction_26=(x13*x36+x15*x39+x17*x42+x19*x45+0.333333333333333*x21-70)**2
	restriction_27=(x4*x28-x22-0)**2
	restriction_28=(x4*x29-x23-0)**2
	restriction_29=(x4*x30-x24-0)**2
	restriction_30=(x5*x31-x25-0)**2
	restriction_31=(x5*x32-x26-0)**2
	restriction_32=(x5*x33-x27-0)**2
	restriction_33=(x34+x35+x36-1)**2
	restriction_34=(x37+x38+x39-1)**2
	restriction_35=(x40+x41+x42-1)**2
	restriction_36=(x43+x44+x45-1)**2
	restriction_37=(x28+x29+x30-1)**2
	restriction_38=(x31+x32+x33-1)**2
	restriction_39=(x36-0)**2
	restriction_40=(x43-0)**2
	restriction_41=((x4-300*b50+slacking_0)-0)**2
	restriction_42=((x5-300*b51+slacking_1)-0)**2
	objective_function=-(-((0.0042656*x29-0.0005719*x28+0.0093514*x46+0.0077308*x47-0.0139904)*x4+(0.0016371*x31+0.0288996*x32+0.0338147*x48+0.0373349*x49-0.0661588)*x5)+0-0.23947*b50-0.75835*b51)
	return (objective_function - (1.5671))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17+restriction_18+restriction_19+restriction_20+restriction_21+restriction_22+restriction_23+restriction_24+restriction_25+restriction_26+restriction_27+restriction_28+restriction_29+restriction_30+restriction_31+restriction_32+restriction_33+restriction_34+restriction_35+restriction_36+restriction_37+restriction_38+restriction_39+restriction_40+restriction_41+restriction_42