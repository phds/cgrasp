#include "libs/common.h"
#include <vector>
#include <algorithm>
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

float callPythonObjectiveFunction2(vector<double> x,const char* moduleName){
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
void LocalImprovement(vector<double> x,int n,double h,vector<double> l,vector<double> u,double ro,bool *improvl,int k){
	vector<double> xStar(x);
	
	float fStar = callPythonObjectiveFunction2(x, "ackley");
	int m = x.size();
	
	for(int i=0; i<k; i++){
		vector<double> vectorTemp(0);
		for(int j=0; j<m; j++){
			int random_index = rand() % x.size();
			vectorTemp.push_back(xStar[random_index]);
		}
		float fTemp=callPythonObjectiveFunction2(vectorTemp, "ackley");
		if(fTemp < fStar){
			xStar=vectorTemp;
			//vector<double> x_star(vectorTemp);
			fStar = fTemp;
		}
	}
	
	double numgridpoints = 1;
	int random_index = rand() % x.size();
	for(int i=0;i<m;i++){
		numgridpoints *= ceil((u[i]-l[i])/h);
	}

	double maxPointsToExamine=ceil(ro*numgridpoints);
	int numpointsexamined=0;
	
	vector<double> sh(0);
	double x_temp;
	int tal;
	for(int i=0;i<m;i++){
		double bound = u[i] - l[i];
		for(int j=0;j<bound;j++){
			tal = j;
			x_temp = x[i] + (tal*h);
			if(x_temp <= u[i] && x_temp >= l[i]){
				sh.push_back(x_temp);
			}
		}
	}

	vector<double> bh(0);
	double norm;
	for(int i=0 ;i<n ;i++){
		if(find(sh.begin(), sh.end(), x[i]) != sh.end()){
			norm=sqrt(pow(sh[i],2)+pow(x[i],2));
			x_temp=x[i] + h*( (sh[i])-(x[i]) /norm);
			bh.push_back(x_temp);
		}
		
	}
	while(numpointsexamined <= maxPointsToExamine){
		numpointsexamined += 1;
		vector<double> x_bh(0);
		for(int i=0 ;i<n; i++){
			double k = rand() % bh.size();//callPythonRandomElement(bh,"randomselect");
			x_bh.push_back(bh[k]);
		}

		float f = callPythonObjectiveFunction2(x_bh,"ackley");
		if(feasible(x_bh,n,l,u) && f<fStar){
			vector<double> x_star(x);
			fStar = f;
			*improvl= true;
			numpointsexamined = 0;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d\n",xStar[i] );
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

	double ro=0.001;
	//resampling
	int k=100;
	LocalImprovement(x,n,h,l,u,ro,&improvl,k);

	
	
	
	return 0;
}
