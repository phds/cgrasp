from math import sin,sqrt


def schwefel(x):
	sum1 = 418.9829 * len(x)
	sum2 = sum( [x[i]*sin(sqrt(abs(x[i])))  for i in range(len(x)) ] )
	return sum1-sum2