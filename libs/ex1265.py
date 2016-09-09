from __future__ import division
from math import *
from math import acos as arccos, asin as arcsin, atan as arctan, erf as errorf

def sqr (x): return x**2

def ex1265((x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44, b45, b46, b47, b48, b49, b50, b51, b52, b53, b54, b55, b56, b57, b58, b59, b60, b61, b62, b63, b64, b65, b66, b67, b68, b69, b70, b71, b72, b73, b74, b75, b76, b77, b78, b79, b80, b81, b82, b83, b84, b85, b86, b87, b88, b89, b90, b91, b92, b93, b94, b95, b96, b97, b98, b99, b100, b101, b102, b103, b104, b105, x106, x107, x108, x109, x110, b111, b112, b113, b114, b115, b116, b117, b118, b119, b120, b121, b122, b123, b124, b125, b126, b127, b128, b129, b130, slacking_0, slacking_1, slacking_2, slacking_3, slacking_4, slacking_5, slacking_6, slacking_7, slacking_8, slacking_9, slacking_10, slacking_11, slacking_12, slacking_13, slacking_14, slacking_15, slacking_16, slacking_17, slacking_18, slacking_19, slacking_20, slacking_21, slacking_22, slacking_23, slacking_24, slacking_25, slacking_26, slacking_27, slacking_28, slacking_29, slacking_30, slacking_31, slacking_32, slacking_33, slacking_34, slacking_35, slacking_36, slacking_37, slacking_38, slacking_39, slacking_40, slacking_41, slacking_42, slacking_43)):
	restriction_0=((x106*x1+x107*x2+x108*x3+x109*x4+x110*x5-slacking_0)-12)**2
	restriction_1=((x106*x6+x107*x7+x108*x8+x109*x9+x110*x10-slacking_1)-6)**2
	restriction_2=((x106*x11+x107*x12+x108*x13+x109*x14+x110*x15-slacking_2)-15)**2
	restriction_3=((x106*x16+x107*x17+x108*x18+x109*x19+x110*x20-slacking_3)-6)**2
	restriction_4=((x106*x21+x107*x22+x108*x23+x109*x24+x110*x25-slacking_4)-9)**2
	restriction_5=((-330*x1-360*x6-370*x11-415*x16-435*x21+1800*b101+slacking_5)-0)**2
	restriction_6=((-330*x2-360*x7-370*x12-415*x17-435*x22+1800*b102+slacking_6)-0)**2
	restriction_7=((-330*x3-360*x8-370*x13-415*x18-435*x23+1800*b103+slacking_7)-0)**2
	restriction_8=((-330*x4-360*x9-370*x14-415*x19-435*x24+1800*b104+slacking_8)-0)**2
	restriction_9=((-330*x5-360*x10-370*x15-415*x20-435*x25+1800*b105+slacking_9)-0)**2
	restriction_10=((330*x1+360*x6+370*x11+415*x16+435*x21-2000*b101+slacking_10)-0)**2
	restriction_11=((330*x2+360*x7+370*x12+415*x17+435*x22-2000*b102+slacking_11)-0)**2
	restriction_12=((330*x3+360*x8+370*x13+415*x18+435*x23-2000*b103+slacking_12)-0)**2
	restriction_13=((330*x4+360*x9+370*x14+415*x19+435*x24-2000*b104+slacking_13)-0)**2
	restriction_14=((330*x5+360*x10+370*x15+415*x20+435*x25-2000*b105+slacking_14)-0)**2
	restriction_15=((-x1-x6-x11-x16-x21+b101+slacking_15)-0)**2
	restriction_16=((-x2-x7-x12-x17-x22+b102+slacking_16)-0)**2
	restriction_17=((-x3-x8-x13-x18-x23+b103+slacking_17)-0)**2
	restriction_18=((-x4-x9-x14-x19-x24+b104+slacking_18)-0)**2
	restriction_19=((-x5-x10-x15-x20-x25+b105+slacking_19)-0)**2
	restriction_20=((x1+x6+x11+x16+x21-5*b101+slacking_20)-0)**2
	restriction_21=((x2+x7+x12+x17+x22-5*b102+slacking_21)-0)**2
	restriction_22=((x3+x8+x13+x18+x23-5*b103+slacking_22)-0)**2
	restriction_23=((x4+x9+x14+x19+x24-5*b104+slacking_23)-0)**2
	restriction_24=((x5+x10+x15+x20+x25-5*b105+slacking_24)-0)**2
	restriction_25=((b101-x106+slacking_25)-0)**2
	restriction_26=((b102-x107+slacking_26)-0)**2
	restriction_27=((b103-x108+slacking_27)-0)**2
	restriction_28=((b104-x109+slacking_28)-0)**2
	restriction_29=((b105-x110+slacking_29)-0)**2
	restriction_30=((-15*b101+x106+slacking_30)-0)**2
	restriction_31=((-12*b102+x107+slacking_31)-0)**2
	restriction_32=((-9*b103+x108+slacking_32)-0)**2
	restriction_33=((-6*b104+x109+slacking_33)-0)**2
	restriction_34=((-6*b105+x110+slacking_34)-0)**2
	restriction_35=((x106+x107+x108+x109+x110-slacking_35)-10)**2
	restriction_36=((-b101+b102+slacking_36)-0)**2
	restriction_37=((-b102+b103+slacking_37)-0)**2
	restriction_38=((-b103+b104+slacking_38)-0)**2
	restriction_39=((-b104+b105+slacking_39)-0)**2
	restriction_40=((-x106+x107+slacking_40)-0)**2
	restriction_41=((-x107+x108+slacking_41)-0)**2
	restriction_42=((-x108+x109+slacking_42)-0)**2
	restriction_43=((-x109+x110+slacking_43)-0)**2
	restriction_44=(x1-b26-2*b27-4*b28-0)**2
	restriction_45=(x2-b29-2*b30-4*b31-0)**2
	restriction_46=(x3-b32-2*b33-4*b34-0)**2
	restriction_47=(x4-b35-2*b36-4*b37-0)**2
	restriction_48=(x5-b38-2*b39-4*b40-0)**2
	restriction_49=(x6-b41-2*b42-4*b43-0)**2
	restriction_50=(x7-b44-2*b45-4*b46-0)**2
	restriction_51=(x8-b47-2*b48-4*b49-0)**2
	restriction_52=(x9-b50-2*b51-4*b52-0)**2
	restriction_53=(x10-b53-2*b54-4*b55-0)**2
	restriction_54=(x11-b56-2*b57-4*b58-0)**2
	restriction_55=(x12-b59-2*b60-4*b61-0)**2
	restriction_56=(x13-b62-2*b63-4*b64-0)**2
	restriction_57=(x14-b65-2*b66-4*b67-0)**2
	restriction_58=(x15-b68-2*b69-4*b70-0)**2
	restriction_59=(x16-b71-2*b72-4*b73-0)**2
	restriction_60=(x17-b74-2*b75-4*b76-0)**2
	restriction_61=(x18-b77-2*b78-4*b79-0)**2
	restriction_62=(x19-b80-2*b81-4*b82-0)**2
	restriction_63=(x20-b83-2*b84-4*b85-0)**2
	restriction_64=(x21-b86-2*b87-4*b88-0)**2
	restriction_65=(x22-b89-2*b90-4*b91-0)**2
	restriction_66=(x23-b92-2*b93-4*b94-0)**2
	restriction_67=(x24-b95-2*b96-4*b97-0)**2
	restriction_68=(x25-b98-2*b99-4*b100-0)**2
	restriction_69=(x106-b111-2*b112-4*b113-8*b114-0)**2
	restriction_70=(x107-b115-2*b116-4*b117-8*b118-0)**2
	restriction_71=(x108-b119-2*b120-4*b121-8*b122-0)**2
	restriction_72=(x109-b123-2*b124-4*b125-8*b126-0)**2
	restriction_73=(x110-b127-2*b128-4*b129-8*b130-0)**2
	objective_function=-(-0.1*b101-0.2*b102-0.3*b103-0.4*b104-0.5*b105-x106-x107-x108-x109-x110+0)
	return (objective_function - (10.3))**2+restriction_0+restriction_1+restriction_2+restriction_3+restriction_4+restriction_5+restriction_6+restriction_7+restriction_8+restriction_9+restriction_10+restriction_11+restriction_12+restriction_13+restriction_14+restriction_15+restriction_16+restriction_17+restriction_18+restriction_19+restriction_20+restriction_21+restriction_22+restriction_23+restriction_24+restriction_25+restriction_26+restriction_27+restriction_28+restriction_29+restriction_30+restriction_31+restriction_32+restriction_33+restriction_34+restriction_35+restriction_36+restriction_37+restriction_38+restriction_39+restriction_40+restriction_41+restriction_42+restriction_43+restriction_44+restriction_45+restriction_46+restriction_47+restriction_48+restriction_49+restriction_50+restriction_51+restriction_52+restriction_53+restriction_54+restriction_55+restriction_56+restriction_57+restriction_58+restriction_59+restriction_60+restriction_61+restriction_62+restriction_63+restriction_64+restriction_65+restriction_66+restriction_67+restriction_68+restriction_69+restriction_70+restriction_71+restriction_72+restriction_73