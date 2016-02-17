from __future__ import division
from math import pi
from math import cos


def branin(x):
	sum1 = (x[1] - ( 5*(x[0]**2) )/( 4*(pi**2) ) + (5*x[0])/pi - 6 )**2
	sum2 = (10 * (1 - 1/(8*pi) ) ) * cos(x[0]) + 10
	result = sum1 + sum2
	return result
