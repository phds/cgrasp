#include "../libs/common.h"
#include "PythonInterface.h"
#include <random>
#include <vector>
using namespace std;


vector<double>  buildSh(struct cgraspData *data,std::mt19937 &generator){

	vector <double> points(data->n);
	for(int i = 0;i < data->n; i++){

		//how many hs are between the limits?
		int steps =  floor((data->u[i] - data->l[i])/data->hs);

		uniform_real_distribution<double> dis_real (0,1);
		double coin = dis_real (generator);

		
		uniform_int_distribution<int> dis_int (0,steps);
		
		double tal = dis_int (generator);
		
		if(coin >=0.5){
			double value = data->x[i] + ( tal *data->hs ) ;
			if(value >= data->l[i] && value <= data->u[i]){
				points[i] = value;
			}else{
				points[i] = data->x[i];
			}
		}else{
			double value = data->x[i] - ( tal *data->hs ) ;
			if(value >= data->l[i] && value <= data->u[i]){
				points[i] = value;
			}else{
				points[i] = data->x[i];
			}
		}
		

	}
	
	
	return points;
}

double calculateNorm(vector<double> x){

	double result;
	for(int i = 0; i < x.size(); i++){
		result += pow(x[i], 2);
	}

	return sqrt(result);
}

vector<double> subVector(vector<double> x, vector<double> y){
	vector<double> result(x.size());

	for(int i=0;i<y.size();i++){  // y is x current and x is x'
		result[i] = x[i] - y[i];
		 
	}
	return result;
}

double pickOnePointInSh(vector<double> x,std::mt19937 &generator){
	std::uniform_int_distribution<int> dis_int (0,x.size()-1);
	int index = dis_int (generator);
	return x[index];
}

vector<double> buildBh (struct cgraspData *data,std::mt19937 &generator){
	vector< double>  sh = buildSh(data,generator);
	
	vector<double> minus = subVector(sh,data->x);
	
	double norm = calculateNorm(minus);
	
	for(int i=0; i<minus.size(); i++){
		minus[i] = minus[i]/norm;
	}


	vector<double> bh(data->n);

	uniform_real_distribution<double> dis_real (0,1);
	for(int i=0;i<data->n;i++){
		double coin = dis_real (generator);
		double value;
		if(coin >= 0.5){
			value = data->x[i] + (data->hs * minus[i]);
			if(value >= data->l[i] && value <= data->u[i]){
				bh[i]=value;
			}

		}else{
			value = data->x[i] - (data->hs * minus[i]);
			if(value >= data->l[i] && value <= data->u[i]){
				bh[i]=value;
			}
		}
	}
	sh.clear();
	minus.clear();
	vector<double>(sh).swap(sh);
	vector<double>(minus).swap(minus);

	return bh;
}


vector<double> localImprovementCgrasp(struct cgraspData *data,bool *improvL,vector<bool> cgraspMarks,std::mt19937 &generator){//vector<double> x,int n,double h,vector<double> l,vector<double> u,double ro,bool *improvL,int k){
	
	mpfr_t fStar, f;
	mpfr_init2 (fStar, 200);
	mpfr_init2 (f, 200);
	mpfr_set_d (fStar,PythonInterface::objectiveFunction(data->x) , MPFR_RNDZ);
	vector<double> bh;

	int temp = 0;
	for(int i = 0; i < data->n; i++){
		if(cgraspMarks[i] == 0){
			temp++;
		}
	}
	for(int j = 0; j < data->k; j++){
		bh = buildBh(data,generator);
		int temp1 = 0;
		for(int i = 0; i < data->n; i++){
			if(cgraspMarks[i] == 0){
				if(data->x[i] == bh[i]){
					temp1++;
				}			
			}
		}
		if(temp == temp1){
			double res = PythonInterface::objectiveFunction(bh);
			mpfr_set_d (f,res , MPFR_RNDZ);
			if(mpfr_cmp(f,fStar) < 0){
				mpfr_set_d (fStar,res , MPFR_RNDZ);
				*improvL = true;
				j = 0;
				for(int p = 0;p < bh.size();p++){
					if(cgraspMarks[p] == 1){
						data->x[p] = bh[p];
					}
				}
				//xStar = data->x;		
			}
		}
		
	}
	
	bh.clear();
	vector<double>(bh).swap(bh);
	mpfr_clear(fStar);
	mpfr_clear(f);
	return data->x;
}
