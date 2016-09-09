//for general libraries
#include <stddef.h> 
#include <mpfr.h>
#include "../src/PythonInterface.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#include <ctime>

#define infinity 1000000000000.0


#ifndef CGRASPDATA_H

#define CGRASPDATA_H

struct cgraspData{
  std::vector<double> x;
  int n;
  double hs;
  double he;
  std::vector<double> l;
  std::vector<double> u;
  double ro;
  int k;
};
;


#endif