#include "libs/common.h"
#include "ConstructGreedyRandomized.cpp"
#include "LocalImprovment.cpp"


#define infinity 1000000000000.0
#define NumTimesToRun 20
using namespace std;


float callPythonObjectiveFunction1(vector<double> x,const char* moduleName){
	int n = x.size();
	PyObject *pyList = PyList_New(n);
	PyObject *value;
	for (int i = 0; i < n; i++){
		//printf("values %f\n", x[i]);
		value = PyFloat_FromDouble(x[i]);
		PyList_SetItem(pyList, i, value);
	}

	PyObject* pyModuleName = PyString_FromString(moduleName);
	PyObject* pyModule = PyImport_Import(pyModuleName);
	PyObject* result = PyObject_CallMethod(pyModule, "ackley","O",pyList);

	
	return PyFloat_AsDouble(result);

}
double callUnifRandVectorPythonFunction(const char* moduleName,vector<double>l,vector<double> u,int i,int k){

	PyObject* pyModuleName = PyString_FromString((char*)moduleName);
	PyObject* pyModule = PyImport_Import(pyModuleName);
	
	PyObject* result;
	float value;
	result = PyObject_CallMethod(pyModule, "unifrand","ddi",l[k],u[k],i);
	return PyFloat_AsDouble(result);

}

void cgrasp(int n,double hs,double he,vector<double> l,vector<double> u){
	
	double f_star=infinity;
	vector<double> x_star;
	double h;
	int maxpointstoexamine=500000;
	double ro=0.001;
	vector<double> x;
	for(int i=0;i<NumTimesToRun;i++){
		printf("%d\n",i);
		for(int k=0;k<n;k++){
			x.push_back(callUnifRandVectorPythonFunction("unifrand",l,u,1,k));
			//printf("%f\n",x[k] );
		}
		h=hs;
		while(h>=he){
			bool improvc=false;
			bool improvl=false;
			ConstructGreedyRandomized(x,n,h,l,u,&improvc);
			//LocalImprovement(x,n,h,l,u,ro,&improvl);
			float f=callPythonObjectiveFunction1(x,"ackley");
			if(f<f_star){
				vector<double> x_star(x);
				f_star=f;
			}
			if(improvc==false && improvl==false){
				h=h/2;
				printf("%f\n",h );
			}

		}
	}
	int m=x_star.size();
	printf("%d\n",m );
	for(int j=0;j<m;j++){
		printf("%f\n",x_star[j]);
	}
	//return x_star;
}
int main(){

	setenv("PYTHONPATH","./libs",1);
	Py_Initialize();
	
	//sample n
	int n=5;

	//sample x
	double temp[n] = {20, 0.2,30,40,55};
	vector<double> x(0);
	x.insert(x.begin(), temp, temp + n);

	//sample l
	double temp2[n] = {-10,-5,-10,-13,-13};
	vector<double> l(0);
	l.insert(l.begin(), temp2, temp2 + n);

	//sample u
	double temp3[n] = {10,3,10,7,7};
	vector<double> u(0);
	u.insert(u.begin(), temp3, temp3 + n);

	//hs needs to be greater than he
	double hs=0.5;
	double he=0.0001;
	cgrasp(n,hs,he,l,u);
	
	return 0;
}