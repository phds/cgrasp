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
	printf("%s\n","COMECOU" );
	//struct graspData * data = (graspData *) malloc (sizeof(struct graspData));
	struct graspData *data = new struct graspData();
	data->n = n;
	data->l = l;
	data->u = u;
	data->ro = ro;
	data->k = k;
	PythonInterface p(function);
	double h;

	double fStar = infinity;
	vector<double> xStar(data->n);
	vector<double> x(data->n);

	srand(time(NULL));
	for(int i=0;i<NumTimesToRun;i++){

		data->x = getRandomPoint(n, l, u);
		data->hs = hs;
		data->he = he;
		//h = hs;
		while (data->hs >= data->he){
		//while (h >= he){
			bool improvC = false;
			bool improvL = false;
			data->x = constructGreedyRandomized(data,&improvC);//x, n, h, l, u, &improvC);
			data->x = localImprovement(data,&improvL);//x, n, h, l, u, ro, &improvL,k);
			//printf("cgrasp: \n");
			//for(int j=0; j<n; j++){
			//	printf("%f ", x[j]);
			//}
			//printf("%d %d\n", improvC, improvL);
			double f = PythonInterface::objectiveFunction(data->x);
			if(f < fStar){
				xStar = data->x;
				fStar = f;
			}
			if(improvC == false && improvL == false){
				data->hs = data->hs/2;
				//h = h/2;
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
