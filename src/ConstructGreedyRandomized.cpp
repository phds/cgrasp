#include "../libs/common.h"
#include "linesearch.h"
#include "PythonInterface.h"
#include <algorithm>
#define infinity 1000000000000.0
using namespace std;

vector<double> constructGreedyRandomizedCgrasp(struct cgraspData *data,bool* improvc,vector<bool> cgraspMarks,std::mt19937 &generator){


	vector<double> s;
	for (int i = 0; i < data->n; i++){
		if(cgraspMarks[i] == 1){
			s.push_back(i);
		}
	}
	bool reuse = false;

	mpfr_t min,max,gIndex,threshold,thresholdTemp,alfa;
	mpfr_init2 (min, 200);
	mpfr_init2 (max, 200);
	mpfr_init2 (gIndex, 200);
	mpfr_init2 (threshold, 200);
	mpfr_init2 (thresholdTemp, 200);
	mpfr_init2 (alfa, 200);
	
	uniform_real_distribution<double> dis_alfa (0,1);
	mpfr_set_d (alfa, dis_alfa(generator), MPFR_RNDZ);


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
				if(cgraspMarks[i] == 1){
					if(reuse == false){
						z[i] = lineSearchCgrasp(data,i,generator);
						g[i] = PythonInterface::objectiveFunction(z);
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
		}


		mpfr_sub(thresholdTemp,max,min,MPFR_RNDZ);
		mpfr_mul(thresholdTemp,alfa,thresholdTemp,MPFR_RNDZ);
		mpfr_add(threshold,min,thresholdTemp,MPFR_RNDZ);

		for(int i=0; i< data->n; i++){
			if(find(s.begin(), s.end(), i) != s.end() && mpfr_cmp(gIndex,threshold) <= 0 && cgraspMarks[i] == 1){
				rcl.push_back(i);
			}
		}
		//Check if RCL size = 0
		
		

		if(rcl.size() == 0){
			break;
		}else{
			uniform_int_distribution<int> dis_index (0,rcl.size()-1);
			random_index = dis_index(generator);
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
	s.clear();
	vector<double>(g).swap(g);
	vector<double>(z).swap(z);
	vector<double>(rcl).swap(rcl);
	vector<double>(s).swap(s);
	return data->x;
}
