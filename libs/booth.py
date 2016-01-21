
'''
Booth Function:
	Definition: BO(x) = (x 1 + 2x^2 − 7)^2 + (2x 1 + x 2 − 5)^2
	Domain: [−10, 10]^2
	Global Minimum: x ∗ = (1, 3);
	BO(xStar) = 0
	DIMENSION = 2
'''
def booth(x):
	sum1 = sum ( (x[0] + 2*x[1] - 7)**2 )
	sum2 = sum ( (2*x[0] + x[1] - 5 )**2 )
	result = sum1 + sum2
	return result