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

		//printf("constructGreedyRandomized\n");

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
