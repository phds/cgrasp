#include <Python.h>
#include <iostream>

using namespace std;
double lineSearch(double *x,int n,int h,double *l,double *u,int k);

/*
int main(){
	double x[2]= {2,2};
	int n=2;
	int h=5;
	double l[2]={-10,-10};
	double u[2]={10,10};
	int k=0;
	lineSearch(x,n,h,l,u,k);
	return 0;
}
*/
/*
x eh o vetor de solucao
n eh a dimensao
h eh o grid
l eh o lower bound
u eh o upper bound
k eh o indice
*/
double lineSearch(double *x,int n,int h,double *l,double *u,int k){
	double *t[n];

	for(int z=0;z<n;z++){
		*(t+z) = x+z;
	}

	double * z;
	z=x;
	double zk=*(x+k);

	setenv("PYTHONPATH",".",1);
	Py_Initialize();
	PyObject* myModuleString = PyString_FromString((char*)"ackley");
	PyObject* myModule = PyImport_Import(myModuleString);
	
	PyObject *list,*list1;
	int i;
	list = PyList_New(0);
	Py_INCREF(list);
	for(i=0;i<n;i++){
		PyObject* thePair = Py_BuildValue( "d", *(x+i));
		Py_INCREF(thePair);
		PyList_Append(list,thePair);
	}
	Py_INCREF(list);
	PyObject *result = PyObject_CallMethod(myModule, "ackley","O",list);
	//PyObject_Print(result, stdout, 0);
	//printf("\n");

	float minF= PyFloat_AsDouble(result);
	*(t+k)=(l+k);
	double *tk;
	tk=*(t+k);
	int uk;
	uk=*(u+k);
	int j;
	
	while (*tk<=uk){
		list1 = PyList_New(0);
		for(j=0;j<n;j++){
			//cout<<(*t[j])<<endl<<j<<endl;
			PyObject* thePair = Py_BuildValue( "d", *t[j]);
			Py_INCREF(thePair);
			PyList_Append(list1,thePair);
		}
		PyObject *result1 = PyObject_CallMethod(myModule, "ackley","O",list1);
		//PyObject_Print(result1, stdout, 0);
		//printf("\n");
		float minF_t= PyFloat_AsDouble(result1);
		if (minF_t<minF){
			minF=minF_t;
			zk=*tk;
		}
		tk+=h;
		
	}

return zk;	
}