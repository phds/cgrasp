from __future__ import division
from math import pi
from math import cos
'''
Branin Function:
	Definition: BR(x) = (x_2 − (5*x_1)/(4π^2) + 1/(4π^2) + (5x_1)/π − 6)^2 + 10(1 − 1/8π) cos(x_1 ) + 10
	Domain: [−5, 15]^2
	Global Minimum (one of several): xStar = (π, 2.275); BR(xStar) = 0.397887
	DIMENSION = 2
'''

def branin(x):
	sum1 = (x[1] - ( 5*(x[0]**2) )/( 4*(pi**2) ) + (5*x[0])/pi - 6 )**2
	sum2 = (10 * (1 - 1/(8*pi) ) ) * cos(x[0]) + 10
	result = sum1 + sum2
	return result
