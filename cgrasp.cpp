#include "libs/common.h"
#include "ConstructGreedyRandomized.cpp"
#include "localImprovement.cpp"

#define NumTimesToRun 2
using namespace std;

vector<double> getRandomPoint(int n, vector<double> l, vector<double> u){

	vector<double> x(n);
	for(int i = 0; i < n; i++){
		x[i] = (u[i] - l[i]) * ( (double)rand() / (double)RAND_MAX ) + l[i];
	}

	return x;
}

void cgrasp(int n,double hs,double he,vector<double> l,vector<double> u, double ro){

	double h;

	double fStar = infinity;
	vector<double> xStar(n);
	vector<double> x(n);

	srand(time(NULL));

	for(int i=0;i<NumTimesToRun;i++){

		x = getRandomPoint(n, l, u);

		h = hs;

		while (h >= he){

			bool improvC = false;
			bool improvL = false;
			x = constructGreedyRandomized(x, n, h, l, u, &improvC);
			x = localImprovement(x, n, h, l, u, ro, &improvL);
			printf("cgrasp: \n");
			for(int j=0; j<n; j++){
				printf("%f ", x[j]);
			}
			printf("%d %d\n", improvC, improvL);
			double f = PythonInterface::objectiveFunction(x);
			if(f < fStar){
				xStar = x;
				fStar = f;
			}
			if(improvC == false && improvL == false){
				h = h/2;
				printf("h: %lf\n",h );
			}
		}
	}

	int m=xStar.size();
	printf("%d\n",m );
	
	for(int j=0;j<m;j++){
		printf("%f\n",xStar[j]);
	}
	//return x_star;
}
int main(){

	PythonInterface p("ackley");

	//dimension of problem
	int n = 5;

	//sample x
	double temp[5] = {20, 0.2, 30, 40, 55};
	vector<double> x(0);
	x.insert(x.begin(), temp, temp + n);

	//sample l
	double temp2[5] = {-10, -5, -10, -13, -13};
	vector<double> l(0);
	l.insert(l.begin(), temp2, temp2 + n);

	//sample u
	double temp3[5] = {10, 3, 10, 7, 7};
	vector<double> u(0);
	u.insert(u.begin(), temp3, temp3 + n);

	//hs needs to be greater than he
	double hs = 0.5;
	// double he = 0.0001;
	double he = 0.25;

	double ro = 0.001;
	cgrasp(n, hs, he, l, u, ro);
	
	return 0;
}