#include <vector>
#include <random>
using namespace std;

void cgrasp(char* function,int n,double hs,double he,vector<double> l,vector<double> u, double ro,int k,int NumTimesToRun,double ep,double *fStarResult,vector<double> *storeResults,vector<double> userKnownVector,vector<bool> marks,int seed,std::mt19937 &generator);