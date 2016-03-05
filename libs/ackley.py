#from math import cos,sqrt,exp,e,pi
import numpy as np
from numpy import abs, cos, exp, mean, pi, prod, sin, sqrt, sum
#Ackley 3 Function
def ackley(x):
	x = np.asarray_chkfinite(x)
	n = len(x)
	s1 = sum( x**2 )
	s2 = sum( cos( 2 * x * pi ))
	return -20*exp( -0.2*sqrt( float(s1) / n )) - exp( float(s2) / n ) + 20 + exp(1)
	#sum1 = sum( x[i]**2 for i in range(len(x)) )
	#sum2 = sum( cos(2*pi*x[i]) for i in range(len(x)) )
	#r = 1.0/len(x)
	#return -20.0*exp(-0.2*sqrt(r*sum1))-exp(r*sum2)+20.0+e
	