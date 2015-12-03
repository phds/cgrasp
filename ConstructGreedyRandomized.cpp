#include "libs/common.h"
#include <vector>
#include <algorithm>
#include "linesearch.cpp"
#define infinity 1000000000000.0

using namespace std;

float callUnifRandPythonFunction(const char* moduleName,int l,int u,int s){

	PyObject* pyModuleName = PyString_FromString((char*)moduleName);
	
	PyObject* pyModule = PyImport_Import(pyModuleName);
	
	PyObject* result = PyObject_CallMethod(pyModule, "unifrand","iii",l,u,s);
	
	return PyFloat_AsDouble(result);

}

float callPythonObjectiveFunction(vector<double> x,const char* moduleName){
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
	PyObject* result = PyObject_CallMethod(pyModule, "ackley","O",pyList);

	
	return PyFloat_AsDouble(result);

}

float callPythonRandomElement(vector<double> x,const char* moduleName){
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
	PyObject* result = PyObject_CallMethod(pyModule, "randomselect","O",pyList);

	
	return PyFloat_AsDouble(result);

}

void ConstructGreedyRandomized(vector<double> x,int n,double h,vector<double> l,vector<double> u,bool improvc){

	float alfa=callUnifRandPythonFunction("unifrand",0,1,1);
	int m = x.size();
	vector<double> s;
	int i;
	for (i = 0; i < m; i++){
		s.push_back(i);
	}
	bool reuse=false;
	double min;
	double max;
	int size=s.size();
	double gi;
	vector<double> zi;
	while(size!=0){
		min=infinity;
		max=-infinity;
		for(i=0;i<n;i++){
			if(find(s.begin(), s.end(), i)!=s.end()){
				if(reuse==false){
					zi=lineSearch(x,n,h,l,u,i);
					gi=callPythonObjectiveFunction(zi,"ackley");
				}
				if (min>gi){
					min=gi;
				}
				if(max<gi){
					max=gi;
				}
				vector<double> rcl;
				double threshold=min+alfa*(max-min);
				for(i=0;i<size;i++){
					if(find(s.begin(), s.end(), i)!=s.end() && gi<=threshold){
						rcl.push_back(i);
					}
				}
				int j=callPythonRandomElement(rcl,"randomselect");
				if(x[j]==zi[j]){
					reuse=true;
				}else{
					x[j]=zi[j];
					reuse=false;
					improvc=true;
				}
				s.erase(remove(s.begin(),s.end(), j), s.end());
				//s.erase(s.begin()+j);
				size--;	
			}
		}

	}
	
}
int main(){
	setenv("PYTHONPATH",".",1);
	Py_Initialize();
	
	//sample n
	int n=2;

	//sample x
	double temp[2] = {20, 0.2};
	vector<double> x(0);
	x.insert(x.begin(), temp, temp + n);

	//sample l
	double temp2[2] = {0, 0.15};
	vector<double> l(0);
	l.insert(l.begin(), temp2, temp2 + n);

	//sample u
	double temp3[2] = {300, 0.3};
	vector<double> u(0);
	u.insert(u.begin(), temp3, temp3 + n);

	//sample h and k
	double h=0.02;
	bool improvc=false;

	ConstructGreedyRandomized(x,n,h,l,u,improvc);
	
	
	return 0;
}

