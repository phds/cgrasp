#include "../libs/common.h"
#include "linesearch.h"
#include "PythonInterface.h"
#include <algorithm>
#define infinity 1000000000000.0
using namespace std;

vector<double> constructGreedyRandomized(struct graspData *data,bool* improvc){


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


	vector<double> g(data->n);
	vector<double> z(data->x);
	vector<double> rcl(0);
	int j;
	int random_index;
	while (s.size() != 0){
		mpfr_set_d (min, infinity, MPFR_RNDZ);
		mpfr_set_d (max, -infinity, MPFR_RNDZ);


		double res;
		for(int i = 0; i < data->n; i++){
			if(find(s.begin(), s.end(), i) != s.end()){
				if(reuse == false){
					z[i] = lineSearch(data,i);
					g[i] = ackley(z);
					mpfr_set_d (gIndex,g[i], MPFR_RNDZ);
				}

				if (mpfr_cmp(min,gIndex) > 0){
					mpfr_set_d (min,g[i], MPFR_RNDZ);
				}
				if(mpfr_cmp(max,gIndex) < 0){
					mpfr_set_d (max,g[i], MPFR_RNDZ);
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

		if(rcl.size() == 0){
			break;
		}else{
			random_index = rand() % rcl.size();
		}

		j = rcl[random_index];
		if(data->x[j] == z[j]){ // >= ?
			reuse = true;
		}else{
			data->x[j] = z[j];
			reuse = false;
			*improvc = true;
		}


		s.erase(remove(s.begin(),s.end(), j), s.end());
		
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
