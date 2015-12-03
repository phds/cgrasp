#include "common.h"
#include <vector>

using namespace std;

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

float callPythonObjectiveFunction(vector<double> x,const char* moduleName){
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

bool feasible(vector<double> x,int n,vector<double> l, vector<double> u){
	bool feas=true;
	int m=x.size();
	int i;
	for(i=0;i<m;i++){
		if(x[i]<=l[i] || x[i]>=u[i]){
			feas=false;
		}
	}
	return feas;
}
void LocalImprovement(vector<double> x,int n,double h,vector<double> l,vector<double> u,double ro,bool improvl,int maxpointstoexamine){
	vector<double> x_star(x);
	
	float f_star = callPythonObjectiveFunction(x, "ackley");
	int m=x.size();
	double numgridpoints=1;
	for(int i=0;i<m;i++){
		numgridpoints*=ceil((u[i]-l[i])/h);
	}
	double pointstoexamine=ceil(ro*numgridpoints);
	if(pointstoexamine>maxpointstoexamine){
		pointstoexamine=maxpointstoexamine;
	}
	int numpointsexamined=0;
	int tal=3;
	vector<double> sh;
	double x_temp;
	for(int i=0;i<m;i++){
		x_temp=x[i]+(tal*h);
		if(x_temp<=u[i] && x_temp>=l[i]){
			sh.push_back(x_temp);
		}
	}
	vector<double> bh;
	double norm;
	bool find=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(x[j]==sh[j]){
				find=true;
				break;
			}
		}
		if(!find){
			norm=sqrt(pow(sh[i],2)+pow(x[i],2));
			x_temp=x[i] + h*( (sh[i])-(x[i]) /norm);
			bh.push_back(x_temp);
		}
	}
	while(numpointsexamined<=pointstoexamine){
		numpointsexamined+=1;
		double k=callPythonRandomElement(bh,"randomselect");
		vector<double> x_bh;
		x_bh.push_back(k);
		float f=callPythonObjectiveFunction(x_bh,"ackley");
		if(feasible(x,n,l,u) && f<f_star){
			vector<double> x_star(x);
			f_star=f;
			improvl=true;
			numpointsexamined=0;
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
	bool improvl=false;

	int maxpointstoexamine=5000000000000;
	double ro=0.001;

	LocalImprovement(x,n,h,l,u,ro,improvl,maxpointstoexamine);

	
	
	
	return 0;
}