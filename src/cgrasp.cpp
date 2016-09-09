#include "../libs/common.h"
#include "ConstructGreedyRandomized.h"
#include "localImprovement.h"
#include "PythonInterface.h"
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> getRandomPointCgrasp(int n, struct cgraspData *data,std::mt19937 &generator){

	vector<double> x(n);
	for(int i = 0; i < n; i++){
		std::uniform_real_distribution<double> dis(data->l[i],data->u[i]);
		x[i] = (dis(generator));
	}

	return x;
}

void cgrasp(char* function,int n,double hs,double he,vector<double> l,vector<double> u, double ro,int k,int NumTimesToRun,double ep,double *fStarResult,vector<double> *storeResults,vector<double> userKnownVector,vector<bool> marks,int seedNumber,std::mt19937 &generator){
	
	
	struct cgraspData *data = new struct cgraspData();
	data->n = n;
	data->l = l;
	data->u = u;
	data->ro = ro;
	data->k = k;
	PythonInterface *p = new PythonInterface(function);
	vector<bool> cgraspMarks;
	if(marks.size() == 0){
		for(int i = 0;i < n;i++){
			cgraspMarks.push_back(1);
		}
	}else{
		cgraspMarks = vector<bool> (marks);
	}
	
	
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

	ofstream outfile ("trace_log.txt", ofstream::app);
	outfile << "****CGRASP log file***\n";
	outfile.flush();
	vector<double> xStar(data->n);
	
	bool stopCriteriaNum = false;
	bool stopCriteria1 = false;
	bool stopCriteria2 = false;
	int countIter = 0;
	while(stopCriteriaNum == false || stopCriteria1 == false || stopCriteria2){
	//for(int i=0;i<NumTimesToRun;i++){
		outfile << "\n\n\nIteration number = "<<countIter+1<<"\n";
		outfile.flush();
		if(userKnownVector.size() == 0){
			data->x = getRandomPointCgrasp(n,data,generator);
		}else{
			data->x = vector<double>(userKnownVector);
		}
		data->hs = hs;
		data->he = he;

		while (data->hs >= data->he){
			outfile << "Inicial h = "<<data->hs<<"\n";
			outfile.flush();
			bool improvC = false;
			bool improvL = false;
			
			
			outfile << "Step : Construct Greedy Randomized\n";
			outfile.flush();
			
			data->x = constructGreedyRandomizedCgrasp(data,&improvC,cgraspMarks,generator);
			
			if(improvC==true){
				outfile<<"\nBest solution found in Construct Greedy Randomized step\n";
				for(int i=0;i<data->x.size();i++){
					outfile<<setprecision(sizeof(data->x[i]))<<data->x[i]<<"\n";
					outfile.flush();
				}
			}else{
				outfile<<"\nNo best solution found in Construct Greedy Randomized step\n";
				outfile.flush();
			}

			outfile << "Step : Local Improvement\n";
			outfile.flush();

			data->x = localImprovementCgrasp(data,&improvL,cgraspMarks,generator);
			
			if(improvL==true){
				outfile<<"\nBest solution found in Local Improvement step\n";
				for(int i=0;i<data->x.size();i++){
					outfile<<setprecision(sizeof(data->x[i]))<<data->x[i]<<"\n";
					outfile.flush();
				}
			}else{
				outfile<<"\nNo best solution found in Local Improvement step\n";
				outfile.flush();
			} 
			
			double res = PythonInterface::objectiveFunction(data->x);

			mpfr_set_d (f, res, MPFR_RNDZ); 
			if(mpfr_cmp(f,fStar) < 0){
				xStar = data->x;
				mpfr_set(fStar,f,MPFR_RNDZ);
				*fStarResult = mpfr_get_d(fStar,MPFR_RNDZ);
				*storeResults = vector<double> (data->x);
				outfile << "\nFound a best solution after Construct Greedy Randomized and Local Improvement\n";
				for(int i=0;i<xStar.size();i++){
					outfile << setprecision(sizeof(data->x[i]))<< data->x[i]<<"\n";
					outfile.flush();
				}
				 
			}

			
			if(improvC == false && improvL == false){
				data->hs = data->hs/2;
				outfile << "\nDecreasing h to "<<data->hs<<"\n";
			}else{
			
				mpfr_sub(fminusfStar,f,fStar,MPFR_RNDZ);
				mpfr_abs(fminusfStar,fminusfStar,MPFR_RNDZ);
							
				if(mpfr_cmp(zero,fStar) == 0){
					if(mpfr_cmp(fminusfStar,e) <= 0){
						//outfile<<"\nStopping criteria met : |f (x) − f (x ∗ )| <= e\n";
						//outfile.flush();
						stopCriteria1 = true;
						//break;
					}
				}else{
					mpfr_abs(absfStar,fStar,MPFR_RNDZ);
					mpfr_mul(emultfStar,e,absfStar,MPFR_RNDZ);
					if(mpfr_cmp(fminusfStar,emultfStar) <= 0){
						//utfile<<"\nStopping criteria met : |f (x) − f (x ∗ )| <= e * |f (x ∗ )|\n";
						//outfile.flush();
						stopCriteria2 = true;
						//break;
					}
				}				
				
			}
			//if(stopCriteria == true){
				//break;
			//}
		}
		if(stopCriteria1 == true){
			outfile<<"\nStopping criteria met : |f (x) − f (x ∗ )| <= e\n";
			outfile.flush();
			break;
		}else if(stopCriteria2 == true){
			outfile<<"\nStopping criteria met : |f (x) − f (x ∗ )| <= e * |f (x ∗ )|\n";
			outfile.flush();
			break;
		}else{
			countIter++;
			if (countIter == NumTimesToRun){
				outfile<<"\nStopping criteria met : Max number of iterations\n";
				outfile.flush();
				stopCriteriaNum = true;
				break;
			}
		}
	
	}
	//if (stopCriteria == false){
	//	outfile<<"\nStopping criteria met : Max number of iterations\n";
	//	outfile.flush();
	//}
	//int m = xStar.size();
	
	
	//for(int j=0;j<m;j++){
	//	printf("x[%d] = %f\n",j,xStar[j]);
	//}
	//printf ("F Star value = ");
  	//mpfr_out_str (stdout, 10, 0, fStar, MPFR_RNDZ);
  	//printf ("\n");
	*fStarResult = mpfr_get_d(fStar,MPFR_RNDZ);
	*storeResults = vector<double> (data->x);

	mpfr_clear (fStar);
	mpfr_clear (f);
	mpfr_clear (zero);
	mpfr_clear (fminusfStar);
	mpfr_clear (e);
	mpfr_clear (emultfStar);
	mpfr_clear (absfStar);
	
	delete data;
	l.clear();
	u.clear();
	xStar.clear();
	vector<double>(l).swap(l);
	vector<double>(u).swap(u);
	vector<double>(xStar).swap(xStar);
	outfile.close();
	delete p;
	
}


