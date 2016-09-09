from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def synheat((b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7, slacking_8, slacking_9, slacking_10, slacking_11, slacking_12, slacking_13, slacking_14, slacking_15, slacking_16, slacking_17, slacking_18, slacking_19, slacking_20, slacking_21, slacking_22, slacking_23, slacking_24, slacking_25, slacking_26, slacking_27, slacking_28, slacking_29, slacking_30, slacking_31, slacking_32, slacking_33, slacking_34, slacking_35, slacking_36, slacking_37, slacking_38, slacking_39, slacking_40, slacking_41, slacking_42, slacking_43)):
	restriction_0=(10*x13-10*x14-x25-x28-0)**2
	restriction_1=(10*x14-10*x15-x26-x29-0)**2
	restriction_2=(20*x16-20*x17-x31-x34-0)**2
	restriction_3=(20*x17-20*x18-x32-x35-0)**2
	restriction_4=(10*x15-x37-3700)**2
	restriction_5=(20*x18-x38-7400)**2
	restriction_6=(-x25-x26-x28-x29-x37+2800)**2
	restriction_7=(-x31-x32-x34-x35-x38+4400)**2
	restriction_8=(15*x19-15*x20-x25-x31-0)**2
	restriction_9=(15*x20-15*x21-x26-x32-0)**2
	restriction_10=(13*x22-13*x23-x28-x34-0)**2
	restriction_11=(13*x23-13*x24-x29-x35-0)**2
	restriction_12=(-15*x19-x39+9750)**2
	restriction_13=(-13*x22-x40+6500)**2
	restriction_14=(-x25-x26-x31-x32-x39+3600)**2
	restriction_15=(-x28-x29-x34-x35-x40+1950)**2
	restriction_16=((x13-x14-slacking_0)-0)**2
	restriction_17=((x14-x15-slacking_1)-0)**2
	restriction_18=((x16-x17-slacking_2)-0)**2
	restriction_19=((x17-x18-slacking_3)-0)**2
	restriction_20=((x19-x20-slacking_4)-0)**2
	restriction_21=((x20-x21-slacking_5)-0)**2
	restriction_22=((x22-x23-slacking_6)-0)**2
	restriction_23=((x23-x24-slacking_7)-0)**2
	restriction_24=((x15-slacking_8)-370)**2
	restriction_25=((x18-slacking_9)-370)**2
	restriction_26=((-x19-slacking_10)+650)**2
	restriction_27=((-x22-slacking_11)+500)**2
	restriction_28=(-x13+650)**2
	restriction_29=(-x16+590)**2
	restriction_30=(-x21+410)**2
	restriction_31=(-x24+350)**2
	restriction_32=((-2800*b1+x25+slacking_12)-0)**2
	restriction_33=((-2800*b2+x26+slacking_13)-0)**2
	restriction_34=((-1950*b3+x28+slacking_14)-0)**2
	restriction_35=((-1950*b4+x29+slacking_15)-0)**2
	restriction_36=((-3600*b5+x31+slacking_16)-0)**2
	restriction_37=((-3600*b6+x32+slacking_17)-0)**2
	restriction_38=((-1950*b7+x34+slacking_18)-0)**2
	restriction_39=((-1950*b8+x35+slacking_19)-0)**2
	restriction_40=((-3600*b11+x39+slacking_20)-0)**2
	restriction_41=((-1950*b12+x40+slacking_21)-0)**2
	restriction_42=((-2800*b9+x37+slacking_22)-0)**2
	restriction_43=((-4400*b10+x38+slacking_23)-0)**2
	restriction_44=((280*b1-x13+x19+x41+slacking_24)-280)**2
	restriction_45=((280*b2-x14+x20+x42+slacking_25)-280)**2
	restriction_46=((130*b3-x13+x22+x44+slacking_26)-130)**2
	restriction_47=((130*b4-x14+x23+x45+slacking_27)-130)**2
	restriction_48=((280*b5-x16+x19+x47+slacking_28)-280)**2
	restriction_49=((280*b6-x17+x20+x48+slacking_29)-280)**2
	restriction_50=((130*b7-x16+x22+x50+slacking_30)-130)**2
	restriction_51=((130*b8-x17+x23+x51+slacking_31)-130)**2
	restriction_52=((280*b1-x14+x20+x42+slacking_32)-280)**2
	restriction_53=((280*b2-x15+x21+x43+slacking_33)-280)**2
	restriction_54=((130*b3-x14+x23+x45+slacking_34)-130)**2
	restriction_55=((130*b4-x15+x24+x46+slacking_35)-130)**2
	restriction_56=((280*b5-x17+x20+x48+slacking_36)-280)**2
	restriction_57=((280*b6-x18+x21+x49+slacking_37)-280)**2
	restriction_58=((130*b7-x17+x23+x51+slacking_38)-130)**2
	restriction_59=((130*b8-x18+x24+x52+slacking_39)-130)**2
	restriction_60=((-x15+x53+slacking_40)+320)**2
	restriction_61=((-x18+x54+slacking_41)+320)**2
	restriction_62=((x19+x55+slacking_42)-680)**2
	restriction_63=((x22+x56+slacking_43)-680)**2
	objective_function=-(-(150*(2*x25/(1e-6+(1e-6+0.5*x41*x42*(x41+x42))**0.33333)+2*x26/(1e-6+(1e-6+0.5*x42*x43*(x42+x43))**0.33333)+2*x28/(1e-6+(1e-6+0.5*x44*x45*(x44+x45))**0.33333)+2*x29/(1e-6+(1e-6+0.5*x45*x46*(x45+x46))**0.33333)+2*x31/(1e-6+(1e-6+0.5*x47*x48*(x47+x48))**0.33333)+2*x32/(1e-6+(1e-6+0.5*x48*x49*(x48+x49))**0.33333)+2*x34/(1e-6+(1e-6+0.5*x50*x51*(x50+x51))**0.33333)+2*x35/(1e-6+(1e-6+0.5*x51*x52*(x51+x52))**0.33333))+150*(1.2*x39/(1e-6+30*x55*(15+0.5*x55))**0.33333+1.2*x40/(1e-6+180*x56*(90+0.5*x56))**0.33333)+150*(2*x37/(1e-6+35*x53*(70+x53))**0.33333+2*x38/(1e-6+35*x54*(70+x54))**0.33333)+80*x39+80*x40+15*x37+15*x38)-5500*b1-5500*b2-5500*b3-5500*b4-5500*b5-5500*b6-5500*b7-5500*b8-5500*b9-5500*b10-5500*b11-5500*b12-29995.6190569812*x27-29995.6190569812*x30-29995.6190569812*x33-29995.6190569812*x36+0)
	return (objective_function - (154997.3349))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17+restriction_18+restriction_19+restriction_20+restriction_21+restriction_22+restriction_23+restriction_24+restriction_25+restriction_26+restriction_27+restriction_28+restriction_29+restriction_30+restriction_31+restriction_32+restriction_33+restriction_34+restriction_35+restriction_36+restriction_37+restriction_38+restriction_39+restriction_40+restriction_41+restriction_42+restriction_43+restriction_44+restriction_45+restriction_46+restriction_47+restriction_48+restriction_49+restriction_50+restriction_51+restriction_52+restriction_53+restriction_54+restriction_55+restriction_56+restriction_57+restriction_58+restriction_59+restriction_60+restriction_61+restriction_62+restriction_63