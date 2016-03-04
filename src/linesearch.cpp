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
double lineSearch(struct graspData *data,int k){//vector<double> x, int n, double h, vector<double> l, vector<double> u, int k){
	//copy of x
	//vector<double> t(x);
	//outfile << "Step : Line Search\n";
	//outfile.flush();

	mpfr_t functionResult,minFunctionResult;
	mpfr_init2 (functionResult, 200);
	mpfr_init2 (minFunctionResult, 200);

	//variable used to hold the function execution result
	//double functionResult;
	//save the initial value of x[k]

	double zk = data->x[k];
	
	//double minFunctionResult = PythonInterface::objectiveFunction(data->x);
	//mpfr_set_d (minFunctionResult,PythonInterface::objectiveFunction(data->x) , MPFR_RNDZ);
	mpfr_set_d (minFunctionResult,ackley(data->x) , MPFR_RNDZ);
	data->x[k] = data->l[k];
	double res;

	while(data->x[k] <= data->u[k]){
		//functionResult = PythonInterface::objectiveFunction(data->x);
		//res = PythonInterface::objectiveFunction(data->x);
		res = ackley(data->x);
		mpfr_set_d (functionResult,res , MPFR_RNDZ);
		if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
			//minFunctionResult = functionResult;
			mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
			zk = data->x[k];
		}

		data->x[k] = data->x[k] + data->hs;
	}

	data->x[k] = data->u[k];
	//functionResult = PythonInterface::objectiveFunction(data->x);
	//res = PythonInterface::objectiveFunction(data->x);
	res = ackley(data->x);
	mpfr_set_d (functionResult,res , MPFR_RNDZ);
	if(mpfr_cmp(functionResult,minFunctionResult) < 0 ){
		//minFunctionResult = functionResult;
		mpfr_set_d (minFunctionResult,res , MPFR_RNDZ);
		zk = data->x[k];

	}
	
	mpfr_clear(functionResult);
	mpfr_clear(minFunctionResult);
	return zk;
}

/*
int main(){

// 	//initialise python
 	setenv("PYTHONPATH","./libs/",1);
 	Py_Initialize();

 	//sample n
 	int n=2;

 	//sample x
 	double temp[2] = {20, 0.2};
 	std::vector<double> x(0);
 	x.insert(x.begin(), temp, temp + n);

 	//sample l
 	double temp2[2] = {0, 0.15};
 	std::vector<double> l(0);
 	l.insert(l.begin(), temp2, temp2 + n);

 	//sample u
 	double temp3[2] = {300, 0.3};
 	std::vector<double> u(0);
 	u.insert(u.begin(), temp3, temp3 + n);

 	//sample h and k
 	double h=0.02;
 	int k=1;

 	printf("%f\n", lineSearch(x,n,h,l,u,k));

 	return 0;
 }
 */
