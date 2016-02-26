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
double lineSearch(vector<double> x, int n, double h, vector<double> l, vector<double> u, int k){
	//copy of x
	//vector<double> t(x);

	//variable used to hold the function execution result
	double functionResult;
	//save the initial value of x[k]
	double zk = x[k];
	
	double minFunctionResult = PythonInterface::objectiveFunction(x);
	
	x[k] = l[k];

	while(x[k] <= u[k]){
		functionResult = PythonInterface::objectiveFunction(x);
		if(functionResult < minFunctionResult){
			minFunctionResult = functionResult;
			zk = x[k];
		}
		x[k] = x[k] + h;
	}

	x[k] = u[k];
	functionResult = PythonInterface::objectiveFunction(x);
	if(functionResult < minFunctionResult){
		minFunctionResult = functionResult;
			zk = x[k];
	}
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