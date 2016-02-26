//for general libraries
#include "../src/PythonInterface.h"
#include <stddef.h> 
#include <mpfr.h>
#include <vector>
#include <algorithm>
#include <string.h>


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
#endif