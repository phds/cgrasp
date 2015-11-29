#include "libs/common.h"
#include <vector>

using namespace std;

double callAckley(std::vector<double> x){
	
	setenv("PYTHONPATH",".",1);
	Py_Initialize();

	int n = x.size();

	PyObject *list;
	list = PyList_New(n);

	PyObject *value;
	for (int i = 0; i < n; i++){
		value = PyFloat_FromDouble(x[i]);
		PyList_SetItem(list, i, value);
	}
	// double v1, v2;
	// PyArg_Parse(PyList_GetItem(list, 0), "d", &v1);
	// PyArg_Parse(PyList_GetItem(list, 1), "d", &v2);
	// printf("%f %f\n", v1, v2);

	printf("%f\n", PyFloat_AsDouble(PyList_GetItem(list, 0)));

	PyObject* myModuleString = PyString_FromString("ackley");
	PyObject* myModule = PyImport_Import(myModuleString);
	if (myModule==NULL) printf("pModule null\n");
	
	PyObject* string = PyString_FromString((char*)"ackley");
	PyObject *result = PyObject_CallMethodObjArgs(myModule, string,list);
	//PyObject_Print(result, stdout, 0);
	//printf("\n");

	return PyFloat_AsDouble(result);
}

/*
x eh o vetor de solucao
n eh a dimensao
h eh o grid
l eh o lower bound
u eh o upper bound
k eh o indice
*/
// double lineSearch(std::vector<double> x,int n,int h,double *l,double *u,int k){

// 	//copy of x
// 	std::vector<double> t(x);

// 	double zk = x[k];

// 	float minF= callAckley(x);



// 	*(t+k)=(l+k);
// 	double *tk;
// 	tk=*(t+k);
// 	int uk;
// 	uk=*(u+k);
// 	int j;
	
// 	while (*tk<=uk){
// 		list1 = PyList_New(0);
// 		for(j=0;j<n;j++){
// 			//cout<<(*t[j])<<endl<<j<<endl;
// 			PyObject* thePair = Py_BuildValue( "d", *t[j]);
// 			Py_INCREF(thePair);
// 			PyList_Append(list1,thePair);
// 		}
// 		PyObject *result1 = PyObject_CallMethod(myModule, "ackley","O",list1);
// 		//PyObject_Print(result1, stdout, 0);
// 		//printf("\n");
// 		float minF_t= PyFloat_AsDouble(result1);
// 		if (minF_t<minF){
// 			minF=minF_t;
// 			zk=*tk;
// 		}
// 		tk+=h;
		
// 	}

// return zk;	
// }

int main(){

	double temp[2] = {15, 222};

	int n=2;
	std::vector<double> x(0);
	x.insert(x.begin(), temp, temp + n);
	
	printf("%lf\n", callAckley(x));
	// int h=5;
	// double l[2]={-10,-10};
	// double u[2]={10,10};
	// int k=0;
	// double r=lineSearch(x,n,h,l,u,k);
	// printf("%lf\n",r );
	return 0;
}