from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def tloss((i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, b37, b38, b39, b40, b41, b42, i43, i44, i45, i46, i47, i48, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7, slacking_8, slacking_9, slacking_10, slacking_11, slacking_12, slacking_13, slacking_14, slacking_15, slacking_16, slacking_17, slacking_18, slacking_19, slacking_20, slacking_21, slacking_22, slacking_23, slacking_24, slacking_25, slacking_26, slacking_27, slacking_28, slacking_29, slacking_30, slacking_31, slacking_32, slacking_33, slacking_34, slacking_35, slacking_36, slacking_37, slacking_38, slacking_39, slacking_40, slacking_41, slacking_42, slacking_43, slacking_44, slacking_45, slacking_46, slacking_47, slacking_48, slacking_49, slacking_50, slacking_51, slacking_52)):
	restriction_0=((i43*i1+i44*i2+i45*i3+i46*i4+i47*i5+i48*i6-slacking_0)-8)**2
	restriction_1=((i43*i7+i44*i8+i45*i9+i46*i10+i47*i11+i48*i12-slacking_1)-16)**2
	restriction_2=((i43*i13+i44*i14+i45*i15+i46*i16+i47*i17+i48*i18-slacking_2)-12)**2
	restriction_3=((i43*i19+i44*i20+i45*i21+i46*i22+i47*i23+i48*i24-slacking_3)-7)**2
	restriction_4=((i43*i25+i44*i26+i45*i27+i46*i28+i47*i29+i48*i30-slacking_4)-14)**2
	restriction_5=((i43*i31+i44*i32+i45*i33+i46*i34+i47*i35+i48*i36-slacking_5)-16)**2
	restriction_6=((330*i1+360*i7+380*i13+430*i19+490*i25+530*i31-2100*b37-slacking_6)-0)**2
	restriction_7=((330*i2+360*i8+380*i14+430*i20+490*i26+530*i32-2100*b38-slacking_7)-0)**2
	restriction_8=((330*i3+360*i9+380*i15+430*i21+490*i27+530*i33-2100*b39-slacking_8)-0)**2
	restriction_9=((330*i4+360*i10+380*i16+430*i22+490*i28+530*i34-2100*b40-slacking_9)-0)**2
	restriction_10=((330*i5+360*i11+380*i17+430*i23+490*i29+530*i35-2100*b41-slacking_10)-0)**2
	restriction_11=((330*i6+360*i12+380*i18+430*i24+490*i30+530*i36-2100*b42-slacking_11)-0)**2
	restriction_12=((330*i1+360*i7+380*i13+430*i19+490*i25+530*i31-2200*b37+slacking_12)-0)**2
	restriction_13=((330*i2+360*i8+380*i14+430*i20+490*i26+530*i32-2200*b38+slacking_13)-0)**2
	restriction_14=((330*i3+360*i9+380*i15+430*i21+490*i27+530*i33-2200*b39+slacking_14)-0)**2
	restriction_15=((330*i4+360*i10+380*i16+430*i22+490*i28+530*i34-2200*b40+slacking_15)-0)**2
	restriction_16=((330*i5+360*i11+380*i17+430*i23+490*i29+530*i35-2200*b41+slacking_16)-0)**2
	restriction_17=((330*i6+360*i12+380*i18+430*i24+490*i30+530*i36-2200*b42+slacking_17)-0)**2
	restriction_18=((-i1-i7-i13-i19-i25-i31+b37+slacking_18)-0)**2
	restriction_19=((-i2-i8-i14-i20-i26-i32+b38+slacking_19)-0)**2
	restriction_20=((-i3-i9-i15-i21-i27-i33+b39+slacking_20)-0)**2
	restriction_21=((-i4-i10-i16-i22-i28-i34+b40+slacking_21)-0)**2
	restriction_22=((-i5-i11-i17-i23-i29-i35+b41+slacking_22)-0)**2
	restriction_23=((-i6-i12-i18-i24-i30-i36+b42+slacking_23)-0)**2
	restriction_24=((i1+i7+i13+i19+i25+i31-5*b37+slacking_24)-0)**2
	restriction_25=((i2+i8+i14+i20+i26+i32-5*b38+slacking_25)-0)**2
	restriction_26=((i3+i9+i15+i21+i27+i33-5*b39+slacking_26)-0)**2
	restriction_27=((i4+i10+i16+i22+i28+i34-5*b40+slacking_27)-0)**2
	restriction_28=((i5+i11+i17+i23+i29+i35-5*b41+slacking_28)-0)**2
	restriction_29=((i6+i12+i18+i24+i30+i36-5*b42+slacking_29)-0)**2
	restriction_30=((b37-i43+slacking_30)-0)**2
	restriction_31=((b38-i44+slacking_31)-0)**2
	restriction_32=((b39-i45+slacking_32)-0)**2
	restriction_33=((b40-i46+slacking_33)-0)**2
	restriction_34=((b41-i47+slacking_34)-0)**2
	restriction_35=((b42-i48+slacking_35)-0)**2
	restriction_36=((-15*b37+i43+slacking_36)-0)**2
	restriction_37=((-12*b38+i44+slacking_37)-0)**2
	restriction_38=((-8*b39+i45+slacking_38)-0)**2
	restriction_39=((-7*b40+i46+slacking_39)-0)**2
	restriction_40=((-4*b41+i47+slacking_40)-0)**2
	restriction_41=((-2*b42+i48+slacking_41)-0)**2
	restriction_42=((i43+i44+i45+i46+i47+i48-slacking_42)-16)**2
	restriction_43=((-b37+b38+slacking_43)-0)**2
	restriction_44=((-b38+b39+slacking_44)-0)**2
	restriction_45=((-b39+b40+slacking_45)-0)**2
	restriction_46=((-b40+b41+slacking_46)-0)**2
	restriction_47=((-b41+b42+slacking_47)-0)**2
	restriction_48=((-i43+i44+slacking_48)-0)**2
	restriction_49=((-i44+i45+slacking_49)-0)**2
	restriction_50=((-i45+i46+slacking_50)-0)**2
	restriction_51=((-i46+i47+slacking_51)-0)**2
	restriction_52=((-i47+i48+slacking_52)-0)**2
	objective_function=-(-0.1*b37-0.2*b38-0.3*b39-0.4*b40-0.5*b41-0.6*b42-i43-i44-i45-i46-i47-i48+0)
	return (objective_function - (16.3))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17+restriction_18+restriction_19+restriction_20+restriction_21+restriction_22+restriction_23+restriction_24+restriction_25+restriction_26+restriction_27+restriction_28+restriction_29+restriction_30+restriction_31+restriction_32+restriction_33+restriction_34+restriction_35+restriction_36+restriction_37+restriction_38+restriction_39+restriction_40+restriction_41+restriction_42+restriction_43+restriction_44+restriction_45+restriction_46+restriction_47+restriction_48+restriction_49+restriction_50+restriction_51+restriction_52