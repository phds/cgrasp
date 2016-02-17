from math import cos
from math import pi

def bohachevsky(x):
	return (x[0]**2) + 2*(x[1]**2) - 0.3*cos(3*pi*x[0]) - 0.4*cos(4*pi*x[1]) + 0.7