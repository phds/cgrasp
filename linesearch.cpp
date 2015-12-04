#include "libs/common.h"

using namespace std;
/*
Function that calculates a function named moduleName on x and
returns a double value
*/
double callPythonFunction(std::vector<double> x, const char* moduleName){

	int n = x.size();

	PyObject *pyList = PyList_New(n);

	PyObject *value;
	for (int i = 0; i < n; i++){
		printf("values %f\n", x[i]);
		value = PyFloat_FromDouble(x[i]);
		PyList_SetItem(pyList, i, value);
	}
  
	PyObject* pyModuleName = PyString_FromString(moduleName);
	PyObject* pyModule = PyImport_Import(pyModuleName);
	if (pyModule==NULL) printf("Module null\n");
	
	PyObject* pyFunction = PyObject_GetAttrString(pyModule, moduleName);
	if (pyFunction==NULL) printf("function null\n");

	PyObject* result = PyObject_CallFunctionObjArgs(pyFunction, pyList, NULL);

	printf("result %f\n\n", PyFloat_AsDouble(result));
	return PyFloat_AsDouble(result);
	
}

/*
x is the vector with the current solution
n is the size of the vector //can be accessed via size of x
h is the size of step on the grid
l is the lower bound vector
u is the upper bound vector
k is the index of the element being iterated
*/
double lineSearch(std::vector<double> x, int n, double h, std::vector<double> l, std::vector<double> u,int k){

	//copy of x
	std::vector<double> t(x);
	
	//variable used to hold the function execution result
	double functionResult;
	//save the initial value of x[k]
	double zk = x[k];

	float minFunctionResult = callPythonFunction(x, "ackley");

	t[k] = l[k];

	while(t[k] <= u[k]){
		functionResult = callPythonFunction(t, "ackley");
		if(functionResult < minFunctionResult){
			minFunctionResult = functionResult;
			zk = t[k];
		}
		t[k] = t[k] + h;
	}

	t[k] = u[k];
	functionResult = callPythonFunction(t, "ackley");
	if(functionResult < minFunctionResult){
		minFunctionResult = functionResult;
			zk = t[k];
	}

	return zk;
}

// int main(){

// 	//initialise python
// 	setenv("PYTHONPATH","./libs/",1);
// 	Py_Initialize();

// 	//sample n
// 	int n=2;

// 	//sample x
// 	double temp[2] = {20, 0.2};
// 	std::vector<double> x(0);
// 	x.insert(x.begin(), temp, temp + n);

// 	//sample l
// 	double temp2[2] = {0, 0.15};
// 	std::vector<double> l(0);
// 	l.insert(l.begin(), temp2, temp2 + n);

// 	//sample u
// 	double temp3[2] = {300, 0.3};
// 	std::vector<double> u(0);
// 	u.insert(u.begin(), temp3, temp3 + n);

// 	//sample h and k
// 	double h=0.02;
// 	int k=1;

// 	printf("%f\n", lineSearch(x,n,h,l,u,k));

// 	return 0;
// }