
from math import cos,pi

def rastrigin(x):
	sum1 = 10*len(x)
	sum2 = sum( [(x[i]**2)-10*cos(2*pi*x[i]) for i in range(len(x))] )
	return sum1+sum2