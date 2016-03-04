
#include "ackley.h"
#include <math.h>

#define _USE_MATH_DEFINES


double ackley(std::vector<double> x){
	double sum1 = 0;
	double sum2 = 0;
	int n = x.size();
	for(int i=0; i<n; i++){
		sum1 += pow(x[i],2); 
	}
	for(int i=0; i<n; i++){
		sum2 += cos(2*M_PI*x[i]);
	}
	double r = 1.0/n;


	return -20 * exp(-0.2*sqrt(r*sum1)) - exp(r*sum2) + 20.0+ exp(1);
}
