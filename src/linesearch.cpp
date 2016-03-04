#include "../libs/common.h"
#include "PythonInterface.h"
using namespace std;

/*
x is the vector with the current solution
n is the size of the vector //can be accessed via size of x
h is the size of step on the grid
l is the lower bound vector
u is the upper bound vector
k is the index of the element being iterated
*/
double lineSearch(struct graspData *data,int k){
	//copy of x
	//vector<double> t(x);


	mpfr_t functionResult,minFunctionResult;
	mpfr_init2 (functionResult, 200);
	mpfr_init2 (minFunctionResult, 200);

	//variable used to hold the function execution result
	//double functionResult;
	//save the initial value of x[k]

	double zk = data->x[k];
	

	mpfr_set_d (minFunctionResult,ackley(data->x) , MPFR_RNDZ);
	data->x[k] = data->l[k];
	double res;

	while(data->x[k] <= data->u[k]){
		res = ackley(data->x);
		mpfr_set_d (functionResult,res , MPFR_RNDZ);
		if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
			mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
			zk = data->x[k];
		}

		data->x[k] = data->x[k] + data->hs;
	}

	data->x[k] = data->u[k];

	res = ackley(data->x);
	mpfr_set_d (functionResult,res , MPFR_RNDZ);
	if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
		mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
		zk = data->x[k];

	}
	
	mpfr_clear(functionResult);
	mpfr_clear(minFunctionResult);
	return zk;
}


