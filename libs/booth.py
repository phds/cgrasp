
'''
Booth Function:
	Definition: BO(x) = (x_1 + 2x_2 − 7)^2 + (2x_1 + x_2 − 5)^2
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