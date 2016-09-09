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
double lineSearchCgrasp(struct cgraspData *data,int k,std::mt19937 &generator){


	mpfr_t functionResult,minFunctionResult;
	mpfr_init2 (functionResult, 200);
	mpfr_init2 (minFunctionResult, 200);


	double zk = data->x[k];
	double tk;
	
	mpfr_set_d (minFunctionResult,PythonInterface::objectiveFunction(data->x) , MPFR_RNDZ);
	
	
	double res;
	
	uniform_real_distribution<double> dis_real (0,1);
	double coin = dis_real (generator);
	if(coin >= 0.5){
		tk = data->l[k];
		while(tk <= data->u[k]){
			res = PythonInterface::objectiveFunction(data->x);
			mpfr_set_d (functionResult,res , MPFR_RNDZ);
			if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
				mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
				zk = data->x[k];
			}

			tk = tk + data->hs;
		}

		tk = data->u[k];
		res = PythonInterface::objectiveFunction(data->x);
		mpfr_set_d (functionResult,res , MPFR_RNDZ);
		if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
			mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
			zk = tk;

		}
	}else{
		
		tk = data->u[k];
		while(tk >= data->l[k]){
			res = PythonInterface::objectiveFunction(data->x);
			mpfr_set_d (functionResult,res , MPFR_RNDZ);
			if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
				mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
				zk = data->x[k];
			}

			tk = tk - data->hs;
		}

		tk = data->l[k];
		res = PythonInterface::objectiveFunction(data->x);
		mpfr_set_d (functionResult,res , MPFR_RNDZ);
		if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
			mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
			zk = tk;

		}
	}


	mpfr_clear(functionResult);
	mpfr_clear(minFunctionResult);
	return zk;
}

