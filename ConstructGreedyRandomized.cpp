#include "libs/common.h"
#include "linesearch.cpp"

using namespace std;

vector<double> constructGreedyRandomized(vector<double> x,int n,double h,vector<double> l,vector<double> u,bool* improvc){

	float alfa = ((double)rand() / ((double)RAND_MAX));

	vector<double> s;
	for (int i = 0; i < n; i++){
		s.push_back(i);
	}
	bool reuse = false;
	double min;
	double max;

	vector<double> g(n);
	vector<double> z(x);
	vector<double> rcl(0);
	int j;
	int random_index;
	while (s.size() != 0){

		min = infinity;
		max = -infinity;

		for(int i = 0; i < n; i++){
			if(find(s.begin(), s.end(), i) != s.end()){
				if(reuse == false){
					z[i] = lineSearch(x,n,h,l,u,i);
					g[i] = PythonInterface::objectiveFunction(z);
				}
				if (min > g[i]){
					min = g[i];
				}
				if(max < g[i]){
					max = g[i];
				}
			}
		}

		rcl.clear();
		double threshold = min + alfa*(max-min);
		for(int i=0; i<n; i++){
			if(find(s.begin(), s.end(), i) != s.end() && g[i] <= threshold){
				rcl.push_back(i);
			}
		}

		random_index = rand() % rcl.size();
		j = rcl[random_index];
		if(x[j] == z[j]){
			reuse = true;
		}else{
			x[j] = z[j];
			reuse = false;
			*improvc = true;
		}
		s.erase(remove(s.begin(),s.end(), j), s.end());
		//s.erase(s.begin()+j);
	}

	return x;
}
/*
int main(){
	setenv("PYTHONPATH","./libs",1);
	Py_Initialize();
	
	//sample n
	int n=5;

	//sample x
	double temp[n] = {20, 0.2,30,40,55};
	vector<double> x(0);
	x.insert(x.begin(), temp, temp + n);

	//sample l
	double temp2[n] = {-10,-5,-10,-13,-13};
	vector<double> l(0);
	l.insert(l.begin(), temp2, temp2 + n);

	//sample u
	double temp3[n] = {10,3,10,7,7};
	vector<double> u(0);
	u.insert(u.begin(), temp3, temp3 + n);

	//sample h and k
	double h=0.5;
	bool improvc = false;

	x = ConstructGreedyRandomized(x,n,h,l,u,&improvc);

	printf("\nimprovc: %d\n", improvc);
	for (int i = 0; i < n; ++i)
	{
		printf("%lf ", x[i]);
	}
  std::cout << '\n';
	
	return 0;
}

*/