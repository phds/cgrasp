#include <grasp.h>
#include <cgrasp.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <limits>
#include <random>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include <algorithm> 
#include <time.h> 

using namespace std;
using namespace boost;

int extractDimension (char* function){
	int dimension;
	string line;
	vector <string> line_split;
	ifstream file (function);
	
	if (file.is_open()) {
    		while (getline (file,line)) {
			if (line[0] == 'd'){
				split(line_split,line,is_any_of(" "));
				dimension = atoi(line_split[1].c_str());
				break;
			}
    		}
		file.close();
    	}
  	else cout << "Unable to open file\n"; 

  	return dimension;
}

vector <double> changeLVector (vector <string> v,int multiple){
	vector <double> vector_aux;
	vector <double> l;
	
	for (int i=0; i < v.size (); i++) {
		if (v[i]!="-infinity"){
			vector_aux.push_back(atof(v[i].c_str()));
		}
	}

	auto min = min_element (vector_aux.begin(), vector_aux.end());

	for (int j=0; j < v.size ();j++) {
		if (v[j]=="-infinity"){
			//if (*min > -100) {
						
			//}
			//else {
			//	l.push_back(*min);
			//}
			l.push_back ((*min)*multiple );
		}
		else {
			l.push_back(atof(v[j].c_str()));
		}
	}

	return l;

}

vector <double> changeUVector (vector <string> v,int multiple){
	vector <double> vector_aux;
	vector <double> u;
	
	for (int i=0; i < v.size (); i++) {
		if (v[i]!="+infinity"){
			vector_aux.push_back(atof(v[i].c_str()));
		}
	}

	auto max = max_element (vector_aux.begin(), vector_aux.end());

	for (int j=0; j < v.size ();j++) {
		if (v[j]=="+infinity"){
			//if (*max < 100) {
			//	u.push_back ((*max)*multiple);			
			//}
			//else {
			//	u.push_back(*max);
			//}
			u.push_back ((*max)*multiple);
		}
		else {
			u.push_back(atof(v[j].c_str()));
		}
	}

	return u;

}

vector <double> extractBounds (char* function, char arg,int multiple){

	vector <double> bounds;
	string line;
	vector <string> line_split;
	ifstream file (function);
	
	if (file.is_open()) {
    		while (getline (file,line)) {
			if (line[0] == arg){
				split(line_split,line,is_any_of(" "));
				line_split.erase (line_split.begin());
				break;
			}
    		}
		file.close();
    	}
  	else cout << "Unable to open file\n";

	if (arg == 'u'){
		bounds = changeUVector (line_split,multiple);
	}
	else {		
		bounds = changeLVector (line_split,multiple);
	}

  	return bounds;
}

vector <bool> extractMarks (char* function){
	vector <bool> marks;
	string line;
	vector <string> line_split;
	ifstream file (function);
	
	if (file.is_open()) {
    		while (getline (file,line)) {
			if (line[0] == 'm'){
				split(line_split,line,is_any_of(" "));
				line_split.erase (line_split.begin());
				for (int i=0; i < line_split.size (); i++) {
     					double num = atoi(line_split[i].c_str());
     					marks.push_back(num);
				}
				break;
			}
    		}
		file.close();
    	}
  	else cout << "Unable to open file\n";

  	return marks;
}

double generatesRandomNumber (double l, double u,std::mt19937 &generator){
	double x;
	random_device rd;
	//mt19937 generator (rd());
	uniform_real_distribution<double> dis(l,u);
	x = (dis(generator));
	return x;
}

vector <double>  generatesRandomVector (int n, vector <double> u, vector <double> l,vector <bool> marks, int seed,std::mt19937 &generator){	
	vector<double> x(n);
	//std::mt19937 generator (seed);
	for(int i = 0; i < n; i++){
		if (marks[i] == 1){
			uniform_real_distribution<double> dis_real (l[i],u[i]);
			x[i] = (dis_real (generator));
		}
		else{
			uniform_int_distribution<int> dis_int (l[i],u[i]);
			x[i] = (dis_int (generator));
		}
	}

	return x;
}

void solveminlp (string functionName, double bestKnownValue,double hs, double he, double ro, int k, int iter, double ep, int seed,int multiple){
	char *f = new char [functionName.length() + 1];
    	strcpy (f, functionName.c_str());
	char *f_info = new char [functionName.length() + 1];
	char extension [6] = ".info";
	strcat (f_info, f);
	strcat (f_info, extension);
	int dimension = extractDimension (f_info);
	int mult = multiple; 
	vector <double> u = extractBounds (f_info, 'u',multiple);
	vector <double> l = extractBounds (f_info, 'l',multiple);
	vector<bool> marks = extractMarks (f_info);
	std::mt19937 generator(seed);
	vector<double> userKnownVector = generatesRandomVector (dimension,u,l,marks, seed,generator);
	double bestSolution;
	vector <double> vectorSolution;
	double currentSolution;
	vector <double> vectorCurrentSolution;
	
	bool stoppingCriteria_1 = 1;

	double op = generatesRandomNumber (0.0,1.0,generator);
	
	while (stoppingCriteria_1 == 1){
		if (op >= 0.5) {
			cgrasp (f, dimension, hs, he, l, u, ro, k, iter, 0.00001, &currentSolution, &vectorCurrentSolution, userKnownVector, marks,seed,generator);
			op = 0;
		} 
		else {
			grasp (f, dimension, l, u, k, iter, 0.00001, &currentSolution, &vectorCurrentSolution, userKnownVector, marks,seed,generator);
			op = 1;
		}

		if (vectorSolution.size () == 0) {
			userKnownVector = vector <double> (vectorCurrentSolution);
			bestSolution = currentSolution;
			vectorSolution = vector <double> (vectorCurrentSolution);
			for (int i=0; i<vectorSolution.size(); i++) {
				printf ("%f\n",vectorSolution[i]);
			}
			printf ("Best Solution Found: = %f\n", bestSolution);

			time_t rawtime;
  			struct tm * timeinfo;
			time (&rawtime);
  			timeinfo = localtime (&rawtime);
  			printf ("Current DATE/TIME: %s\n", asctime(timeinfo));
		}
		else {
			if (currentSolution >= bestSolution) {
				userKnownVector = vector <double> (vectorSolution);
			}
			else {
				userKnownVector = vector <double> (vectorCurrentSolution);
				bestSolution = currentSolution;
				vectorSolution = vector <double> (vectorCurrentSolution);

				for (int i=0; i<vectorSolution.size(); i++) {
					printf ("%f\n",vectorSolution[i]);
				}
				printf ("Best Solution Found: = %f\n", bestSolution);

				time_t rawtime;
  				struct tm * timeinfo;
				time (&rawtime);
  				timeinfo = localtime (&rawtime);
  				printf ("Current DATE/TIME: %s\n", asctime(timeinfo));
				
			}
		}
		
		if (bestKnownValue == 0) {
			if (abs (bestSolution-bestKnownValue) <= ep) {
					cout << bestSolution<<endl;
				stoppingCriteria_1 = 0;
			}
		}
		else {
			if (abs (bestSolution-bestKnownValue) <= ep * bestKnownValue){
				stoppingCriteria_1 = 0;
			}
		}
	}
}

int main (int argc, char *argv[ ]) {
	solveminlp (argv[1], 0, atof(argv[2]), atof(argv[3]), 0.7, 100, 10, atof(argv[4]), atoi(argv[5]),atoi(argv[6])  );
}
