from __future__ import division
from math import sin,pi


def levy(x):
	sum1 = sin(pi* (1+( (x[0]-1)/4)) )**2
	sum2 = sum( [ (( ( (1+ ((x[i]-1)/4) )) -1)**2) * (1+10* (sin(pi*( (1+((x[i]-1)/4) )+1))**2)) for i in range(len(x)-1)] )
	sum3 = (( (1+((x[len(x)-1]-1)/4) )-1)**2)*(1+10*(sin(2*pi*( (1+((x[len(x)-1]-1)/4) )))**2 ) )
	return sum1+sum2+sum3