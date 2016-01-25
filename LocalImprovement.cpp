#include "libs/common.h"
#include <vector>
#include <algorithm>
using namespace std;

bool feasible(vector<double> x,int n,vector<double> l, vector<double> u){
	bool feas = true;
	int i;
	for(i = 0; i < n; i++){
		if(x[i] <= l[i] || x[i] >= u[i]){
			feas = false;
		}
	}
	return feas;
}

vector< vector<double> > buildSh(vector<double> x, int n, double h, vector<double> l, vector<double> u){

	vector< vector <double> > sh(0);
	bool finish = false;
	int tau = 1;

	while(!finish){

		vector<double> x_temp(n);

		for(int i = 0; i < n; i++){
			x_temp[i] = x[i] + (tau*h);
			if(x_temp[i] < l[i] || x_temp[i] > u[i]){
				finish = true;
				break;
			}
		}

		if(!finish){
			sh.push_back(x_temp);
			tau++;
		}
	}

	return sh;
}

double calculateNorm(vector<double> x, vector<double> y, int n){

	double result;
	for(int i = 0; i < n; i++){
		result += pow(x[i] - y[i], 2);
	}

	return sqrt(result);
}

vector< vector<double> > buildBh (vector<double> x, int n, double h, vector<double> l, vector<double> u){


	vector< vector<double> > sh = buildSh(x, n, h, l, u);
	vector< vector <double> > bh(0);

	for (int i = 0; i < sh.size(); i++){

		vector<double> x_temp(n);
		double norm = calculateNorm(sh[i], x, n);

		for (int j = 0; j < n; j++){
			x_temp[j] = x[j] + h*( (sh[i][j] - x[j]) / norm);
		}

		bh.push_back(x_temp);
	}

	return bh;
}


vector<double> localImprovement(vector<double> x,int n,double h,vector<double> l,vector<double> u,double ro,bool *improvL){
	vector<double> xStar(x);
	
	float fStar = PythonInterface::objectiveFunction(x);

	double numGridPoints = 1;
	for(int i = 0; i < n; i++){
		numGridPoints *= ceil((u[i]-l[i])/h);
	}

	int maxPointsToExamine = ceil(ro*numGridPoints);
	int numPointsExamined = 0;

	vector< vector<double> > bh;
	
	while(numPointsExamined <= maxPointsToExamine){
		
		printf("localImprovement %d %d\n", numPointsExamined, maxPointsToExamine);
		numPointsExamined += 1;

		bh = buildBh(xStar, n, h, l, u);
		double k = rand() % bh.size();
		vector<double> x_bh = bh[k];

		double f = PythonInterface::objectiveFunction(x_bh);
		if(feasible(x_bh,n,l,u) && f<fStar){
			xStar = x_bh;
			fStar = f;
			*improvL = true;
			numPointsExamined = 0;
		}
	}

	return xStar;
}
