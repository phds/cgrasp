import numpy as np
import random
def unifrand(l,h,s):
	random.seed(123456789)
	t = np.random.uniform(low=0, high=1,size=s)
	return t

