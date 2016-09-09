//for general libraries
#include <stddef.h> 
#include <mpfr.h>
<<<<<<< HEAD
#include "../src/PythonInterface.h"
=======
#include <iostream>
>>>>>>> 8b3e02c1ed9b31823e04ea06603b22a0c29bda3a
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#include <ctime>

#define infinity 1000000000000.0

<<<<<<< HEAD

#ifndef CGRASPDATA_H

#define CGRASPDATA_H

struct cgraspData{
=======
#ifndef GRASPDATA_H
#define GRASPDATA_H
struct graspData{
>>>>>>> 8b3e02c1ed9b31823e04ea06603b22a0c29bda3a
  std::vector<double> x;
  int n;
  double hs;
  double he;
  std::vector<double> l;
  std::vector<double> u;
  double ro;
  int k;
};
<<<<<<< HEAD
;


=======
>>>>>>> 8b3e02c1ed9b31823e04ea06603b22a0c29bda3a
#endif