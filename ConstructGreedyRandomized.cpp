#include <Python.h>
#include <iostream>
#include <mpfr.h>
#include "lineserch.cpp"
#define infinity 1000000000000.0

void ConstructGreedyRandomized(double *x,int n,int h,double *l,double *u,bool improvc);

using namespace std;

int main(){
	double x[2]= {2,2};
	int n=2;
	int h=5;
	double l[2]={-10,-10};
	double u[2]={10,10};
	bool improvc=false;
	ConstructGreedyRandomized(x,n,h,l,u,improvc);

	return 0;
}

void ConstructGreedyRandomized(double *x,int n,int h,double *l,double *u,bool improvc){

	setenv("PYTHONPATH",".",1);
	Py_Initialize();

	PyObject* myModuleString = PyString_FromString((char*)"unifrand");
	PyObject* myModule = PyImport_Import(myModuleString);
	PyObject *result = PyObject_CallMethod(myModule, "unifrand","iii",0,1,1);
	PyObject_Print(result, stdout, 0);
	printf("\n");
	mpfr_t y;
	mpfr_init2(y,200);
	float alfa= PyFloat_AsDouble(result);
	/*
	mpfr_set_d (y,alfa, MPFR_RNDD);
	float f =mpfr_get_flt (y,MPFR_RNDN);
	cout<<alfa<<endl;
	cout<<f<<endl;
	mpfr_printf("%.60Rf\n",y);
	*/
	int s[2] = {0,1};
	bool reuse=false;
	int array_length  =sizeof(s)/sizeof(*s);
	
	//do{
		double min=infinity;
		double max=-infinity;
		int i;
		bool find=false;
		for(i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if (i==s[j]){
					find=true;
					break;
				}
			}
			if (reuse==false){
				double zi;
				zi=lineSearch(x,n,h,l,u,i);
			}
			
		}

		array_length  =sizeof(s)/sizeof(*s);
	//}while(array_length!=0);
}