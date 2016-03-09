//for general libraries
#include <stddef.h> 
#include <mpfr.h>
#include "../src/PythonInterface.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#include "../src/ackley.h"
#include <ctime>

#define infinity 1000000000000.0


#ifndef GRASPDATA_H

#define GRASPDATA_H

struct graspData{
  std::vector<double> x;
  int n;
  double hs;
  double he;
  std::vector<double> l;
  std::vector<double> u;
  double ro;
  int k;
};

struct seedData{
	int rd = time(NULL);
	//std::random_device rd;
};


#endif