#include "../libs/common.h"
#include "PythonInterface.h"
#include <random>
#include <vector>
using namespace std;

bool feasible(struct graspData *data){//vector<double> x,int n,vector<double> l, vector<double> u){
	bool feas = true;
	int i;
	for(i = 0; i < data->n; i++){
		if(data->x[i] <= data->l[i] || data->x[i] >= data->u[i]){
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


vector<double> localImprovement(struct graspData *data,bool *improvL){//vector<double> x,int n,double h,vector<double> l,vector<double> u,double ro,bool *improvL,int k){
	vector<double> xStar(data->x);
	
	float fStar = PythonInterface::objectiveFunction(data->x);

	std::random_device rd;
	std::mt19937 generator (rd());
	for(int j = 0; j < data->k; j++){
			vector<double> sample;
			for(int i=0; i< data->n; i++){
				std::uniform_real_distribution<double> dis(data->l[i],data->u[i]);
				sample.push_back(dis(generator));
			}
			double f = PythonInterface::objectiveFunction(sample);
			if(feasible(data) && f<fStar){
				xStar = sample;
				fStar = f;
				data->k = 0;
				*improvL = true;
			}

		}
	return xStar;
}
