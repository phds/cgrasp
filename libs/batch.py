from __future__ import division
from math import exp, log, log10, sqrt, sin, cos, tan, acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr(x):
	return x**2

def batch((x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20,x21,x22,b23,b24,b25,b26,b27,b28,b29,b30,b31,b32,b33,b34,b35,b36,b37,b38,b39,b40,b41,b42,b43,b44,b45,b46,slacking_0,slacking_1,slacking_2,slacking_3,slacking_4,slacking_5,slacking_6,slacking_7,slacking_8,slacking_9,slacking_10,slacking_11,slacking_12,slacking_13,slacking_14,slacking_15,slacking_16,slacking_17,slacking_18,slacking_19,slacking_20,slacking_21,slacking_22,slacking_23,slacking_24,slacking_25,slacking_26,slacking_27,slacking_28,slacking_29,slacking_30,slacking_31,slacking_32,slacking_33,slacking_34,slacking_35,slacking_36,slacking_37,slacking_38,slacking_39,slacking_40,slacking_41,slacking_42,slacking_43,slacking_44,slacking_45,slacking_46,slacking_47,slacking_48,slacking_49,slacking_50,slacking_51,slacking_52,slacking_53,slacking_54,slacking_55,slacking_56,slacking_57,slacking_58,slacking_59,slacking_60)):
	restriction_0=((x7-x13-slacking_0)-2.06686275947298)**2
	restriction_1=((x8-x13-slacking_1)-0.693147180559945)**2
	restriction_2=((x9-x13-slacking_2)-1.64865862558738)**2
	restriction_3=((x10-x13-slacking_3)-1.58923520511658)**2
	restriction_4=((x11-x13-slacking_4)-1.80828877117927)**2
	restriction_5=((x12-x13-slacking_5)-1.43508452528932)**2
	restriction_6=((x7-x14-slacking_6)+0.356674943938732)**2
	restriction_7=((x8-x14-slacking_7)+0.22314355131421)**2
	restriction_8=((x9-x14-slacking_8)+0.105360515657826)**2
	restriction_9=((x10-x14-slacking_9)-1.22377543162212)**2
	restriction_10=((x11-x14-slacking_10)-0.741937344729377)**2
	restriction_11=((x12-x14-slacking_11)-0.916290731874155)**2
	restriction_12=((x7-x15-slacking_12)+0.356674943938732)**2
	restriction_13=((x8-x15-slacking_13)-0.955511445027436)**2
	restriction_14=((x9-x15-slacking_14)-0.470003629245736)**2
	restriction_15=((x10-x15-slacking_15)-1.28093384546206)**2
	restriction_16=((x11-x15-slacking_16)-1.16315080980568)**2
	restriction_17=((x12-x15-slacking_17)-1.06471073699243)**2
	restriction_18=((x7-x16-slacking_18)-1.54756250871601)**2
	restriction_19=((x8-x16-slacking_19)-0.832909122935104)**2
	restriction_20=((x9-x16-slacking_20)-0.470003629245736)**2
	restriction_21=((x10-x16-slacking_21)-0.993251773010283)**2
	restriction_22=((x11-x16-slacking_22)-0.182321556793955)**2
	restriction_23=((x12-x16-slacking_23)-0.916290731874155)**2
	restriction_24=((x7-x17-slacking_24)-0.182321556793955)**2
	restriction_25=((x8-x17-slacking_25)-1.28093384546206)**2
	restriction_26=((x9-x17-slacking_26)-0.8754687373539)**2
	restriction_27=((x10-x17-slacking_27)-1.50407739677627)**2
	restriction_28=((x11-x17-slacking_28)-0.470003629245736)**2
	restriction_29=((x12-x17-slacking_29)-0.741937344729377)**2
	restriction_30=((x1+x18-slacking_30)-1.85629799036563)**2
	restriction_31=((x2+x18-slacking_31)-1.54756250871601)**2
	restriction_32=((x3+x18-slacking_32)-2.11625551480255)**2
	restriction_33=((x4+x18-slacking_33)-1.3609765531356)**2
	restriction_34=((x5+x18-slacking_34)-0.741937344729377)**2
	restriction_35=((x6+x18-slacking_35)-0.182321556793955)**2
	restriction_36=((x1+x19-slacking_36)-1.91692261218206)**2
	restriction_37=((x2+x19-slacking_37)-1.85629799036563)**2
	restriction_38=((x3+x19-slacking_38)-1.87180217690159)**2
	restriction_39=((x4+x19-slacking_39)-1.48160454092422)**2
	restriction_40=((x5+x19-slacking_40)-0.832909122935104)**2
	restriction_41=((x6+x19-slacking_41)-1.16315080980568)**2
	restriction_42=((x1+x20-slacking_42)-0)**2
	restriction_43=((x2+x20-slacking_43)-1.84054963339749)**2
	restriction_44=((x3+x20-slacking_44)-1.68639895357023)**2
	restriction_45=((x4+x20-slacking_45)-2.47653840011748)**2
	restriction_46=((x5+x20-slacking_46)-1.7404661748405)**2
	restriction_47=((x6+x20-slacking_47)-1.82454929205105)**2
	restriction_48=((x1+x21-slacking_48)-1.16315080980568)**2
	restriction_49=((x2+x21-slacking_49)-1.09861228866811)**2
	restriction_50=((x3+x21-slacking_50)-1.25276296849537)**2
	restriction_51=((x4+x21-slacking_51)-1.19392246847243)**2
	restriction_52=((x5+x21-slacking_52)-1.02961941718116)**2
	restriction_53=((x6+x21-slacking_53)-1.22377543162212)**2
	restriction_54=((x1+x22-slacking_54)-0.741937344729377)**2
	restriction_55=((x2+x22-slacking_55)-0.916290731874155)**2
	restriction_56=((x3+x22-slacking_56)-1.43508452528932)**2
	restriction_57=((x4+x22-slacking_57)-1.28093384546206)**2
	restriction_58=((x5+x22-slacking_58)-1.30833281965018)**2
	restriction_59=((x6+x22-slacking_59)-0.78845736036427)**2
	restriction_60=((250000*exp(x18-x13)+150000*exp(x19-x14)+180000*exp(x20-x15)+160000*exp(x21-x16)+120000*exp(x22-x17)+slacking_60)-6000)**2
	restriction_61=(x1-0.693147180559945*b29-1.09861228866811*b35-1.38629436111989*b41-0)**2
	restriction_62=(x2-0.693147180559945*b30-1.09861228866811*b36-1.38629436111989*b42-0)**2
	restriction_63=(x3-0.693147180559945*b31-1.09861228866811*b37-1.38629436111989*b43-0)**2
	restriction_64=(x4-0.693147180559945*b32-1.09861228866811*b38-1.38629436111989*b44-0)**2
	restriction_65=(x5-0.693147180559945*b33-1.09861228866811*b39-1.38629436111989*b45-0)**2
	restriction_66=(x6-0.693147180559945*b34-1.09861228866811*b40-1.38629436111989*b46-0)**2
	restriction_67=(b23+b29+b35+b41-1)**2
	restriction_68=(b24+b30+b36+b42-1)**2
	restriction_69=(b25+b31+b37+b43-1)**2
	restriction_70=(b26+b32+b38+b44-1)**2
	restriction_71=(b27+b33+b39+b45-1)**2
	restriction_72=(b28+b34+b40+b46-1)**2
	objective_function=-(-(250*exp(x1+0.6*x7)+250*exp(x2+0.6*x8)+250*exp(x3+0.6*x9)+250*exp(x4+0.6*x10)+250*exp(x5+0.6*x11)+250*exp(x6+0.6*x12))+0)
	return objective_function+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17+restriction_18+restriction_19+restriction_20+restriction_21+restriction_22+restriction_23+restriction_24+restriction_25+restriction_26+restriction_27+restriction_28+restriction_29+restriction_30+restriction_31+restriction_32+restriction_33+restriction_34+restriction_35+restriction_36+restriction_37+restriction_38+restriction_39+restriction_40+restriction_41+restriction_42+restriction_43+restriction_44+restriction_45+restriction_46+restriction_47+restriction_48+restriction_49+restriction_50+restriction_51+restriction_52+restriction_53+restriction_54+restriction_55+restriction_56+restriction_57+restriction_58+restriction_59+restriction_60+restriction_61+restriction_62+restriction_63+restriction_64+restriction_65+restriction_66+restriction_67+restriction_68+restriction_69+restriction_70+restriction_71+restriction_72