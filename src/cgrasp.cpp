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

	//struct graspData * data = (graspData *) malloc (sizeof(struct graspData));
	struct graspData *data = new struct graspData();
	data->n = n;
	data->l = l;
	data->u = u;
	data->ro = ro;
	data->k = k;
	PythonInterface p(function);
	//double h;
	
	mpfr_t fStar, f,zero,fminusfStar,e,emultfStar,absfStar;
	mpfr_init2 (fStar, 200);
	mpfr_set_d (fStar, infinity, MPFR_RNDZ);
	mpfr_init2 (f, 200);
	mpfr_init2 (zero, 200);
	mpfr_set_d (zero, 0, MPFR_RNDZ);
	mpfr_init2 (fminusfStar, 200);

	mpfr_init2 (e, 200);
	mpfr_set_d (e, ep, MPFR_RNDZ);
	mpfr_init2 (emultfStar, 200);

	mpfr_init2 (absfStar, 200);


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
			double res = PythonInterface::objectiveFunction(data->x); 
			//double f = PythonInterface::objectiveFunction(data->x);
			mpfr_set_d (f, res, MPFR_RNDZ); 
			if(mpfr_cmp(f,fStar) <= 0){
			//if(f < fStar){
				xStar = data->x;
				//fStar = f;
				mpfr_set_d (fStar, res, MPFR_RNDZ); 
			}
			if(improvC == false && improvL == false){
				data->hs = data->hs/2;
				//h = h/2;
			//	printf("h: %lf\n",h );
			}
			
			if(mpfr_cmp(zero,fStar) == 0){
				mpfr_sub(fminusfStar,f,fStar,MPFR_RNDZ);
				mpfr_abs(fminusfStar,fminusfStar,MPFR_RNDZ);
				if(mpfr_cmp(fminusfStar,e) <= 0){
					break;
				}
			}else{
				mpfr_sub(fminusfStar,f,fStar,MPFR_RNDZ);
				mpfr_abs(fminusfStar,fminusfStar,MPFR_RNDZ);

				mpfr_abs(absfStar,fStar,MPFR_RNDZ);
				mpfr_mul(emultfStar,e,absfStar,MPFR_RNDZ);
				if(mpfr_cmp(fminusfStar,emultfStar) <= 0){
					break;
				}
			}
			
		}
	}

	int m = xStar.size();
	//printf("%d\n",m );
	
	for(int j=0;j<m;j++){
		printf("%f\n",xStar[j]);
	}
	mpfr_clear (fStar);
	mpfr_clear (f);
	mpfr_clear (zero);
	mpfr_clear (fminusfStar);
	mpfr_clear (e);
	mpfr_clear (emultfStar);
	mpfr_clear (absfStar);
	free(data);
	l.clear();
	u.clear();
	//return x_star;
}


