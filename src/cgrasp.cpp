#include "../libs/common.h"
#include "ConstructGreedyRandomized.h"
#include "localImprovement.h"
#include "PythonInterface.h"
#include <cmath>
#define infinity 1000000000000.0
using namespace std;

vector<double> getRandomPoint(int n, vector<double> l, vector<double> u){

	vector<double> x(n);
	for(int i = 0; i < n; i++){
		x[i] = (u[i] - l[i]) * ( (double)rand() / (double)RAND_MAX ) + l[i];
	}

	return x;
}

void cgrasp(char* function,int n,double hs,double he,vector<double> l,vector<double> u, double ro,int k,int NumTimesToRun,double ep){
	PythonInterface p(function);
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
			x = localImprovement(x, n, h, l, u, ro, &improvL,k);
			//printf("cgrasp: \n");
			//for(int j=0; j<n; j++){
			//	printf("%f ", x[j]);
			//}
			//printf("%d %d\n", improvC, improvL);
			double f = PythonInterface::objectiveFunction(x);
			if(f < fStar){
				xStar = x;
				fStar = f;
			}
			if(improvC == false && improvL == false){
				h = h/2;
			//	printf("h: %lf\n",h );
			}
			if(fStar == 0 && abs(f - fStar) <= ep){
				break;
			}else if(fStar != 0 && abs(f - fStar) <= ep * abs(fStar)){
				break;
			}
		}
	}

	int m = xStar.size();
	//printf("%d\n",m );
	
	for(int j=0;j<m;j++){
		printf("%f\n",xStar[j]);
	}
	//return x_star;
}
