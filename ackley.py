from math import *

#Ackley 3 Function
def ackley(x):
	sum1 = sum( x[i]**2 for i in range(len(x)) )
	sum2 = sum( cos(2*pi*x[i]) for i in range(len(x)) )
	r = 1.0/len(x)
	return -20.0*exp(-0.2*sqrt(r*sum1))-exp(r*sum2)+20.0+e