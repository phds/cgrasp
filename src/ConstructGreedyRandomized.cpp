#include "../libs/common.h"
#include "linesearch.h"
#include "PythonInterface.h"
#include <algorithm>
#define infinity 1000000000000.0
using namespace std;

vector<double> constructGreedyRandomized(struct graspData *data,bool* improvc){//vector<double> x,int n,double h,vector<double> l,vector<double> u,bool* improvc){


	vector<double> s;
	for (int i = 0; i < data->n; i++){
		s.push_back(i);
	}
	bool reuse = false;

	mpfr_t min,max,gIndex,threshold,thresholdTemp,alfa;
	mpfr_init2 (min, 200);
	mpfr_init2 (max, 200);
	mpfr_init2 (gIndex, 200);
	mpfr_init2 (threshold, 200);
	mpfr_init2 (thresholdTemp, 200);
	mpfr_init2 (alfa, 200);
	mpfr_set_d (alfa, ((double)rand() / ((double)RAND_MAX)), MPFR_RNDZ);
	//float alfa = ((double)rand() / ((double)RAND_MAX));
	//double min;
	//double max;

	vector<double> g(data->n);
	vector<double> z(data->x);
	vector<double> rcl(0);
	int j;
	int random_index;
	while (s.size() != 0){
		mpfr_set_d (min, infinity, MPFR_RNDZ);
		mpfr_set_d (max, infinity, MPFR_RNDZ);

		//outfile<<"RCL SIZE = "<<rcl.size()<<"\n";
		//printf("constructGreedyRandomized\n");
		double res;
		for(int i = 0; i < data->n; i++){
			if(find(s.begin(), s.end(), i) != s.end()){
				if(reuse == false){
					z[i] = lineSearch(data,i);//x,n,h,l,u,i);
					res = PythonInterface::objectiveFunction(z);
					mpfr_set_d (gIndex,res, MPFR_RNDZ);
				}

				if (mpfr_cmp(min,gIndex) >= 0){
					mpfr_set_d (min,res, MPFR_RNDZ);
					//min = g[i];
				}
				if(mpfr_cmp(max,gIndex) >= 0){
					//max = g[i];
					mpfr_set_d (max,res, MPFR_RNDZ);
				}
			}
		}


		mpfr_sub(thresholdTemp,max,min,MPFR_RNDZ);
		mpfr_mul(thresholdTemp,alfa,thresholdTemp,MPFR_RNDZ);
		mpfr_add(threshold,min,thresholdTemp,MPFR_RNDZ);
		//double threshold = min + alfa*(max-min);
		for(int i=0; i< data->n; i++){
			if(find(s.begin(), s.end(), i) != s.end() && mpfr_cmp(gIndex,threshold) <= 0){
				rcl.push_back(i);
			}
		}
		//printf("%d\n",rcl.size() );
		//Check if RCL size = 0
		if(rcl.size() == 0){
			//outfile<<"RCL SIZE = "<<0<<"\n";
			break;
		}else{
			//outfile<<"RCL SIZE = "<<rcl.size()<<"\n";
			random_index = rand() % rcl.size();
		}

		j = rcl[random_index];
		if(data->x[j] == z[j]){
			reuse = true;
		}else{
			data->x[j] = z[j];
			reuse = false;
			*improvc = true;
		}


		s.erase(remove(s.begin(),s.end(), j), s.end());
		//s.erase(s.begin()+j);
		
	}
	
	mpfr_clear(min);
	mpfr_clear(max);
	mpfr_clear(gIndex);
	mpfr_clear(threshold);
	mpfr_clear(thresholdTemp);
	mpfr_clear(alfa);
	g.clear();
	z.clear();
	rcl.clear();
	return data->x;
}
