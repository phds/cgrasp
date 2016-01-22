#ifdef __APPLE__
    #include <Python/Python.h>
#elif __linux__
    #include <Python.h>
#endif

#include <iostream>
#include <vector>

#ifndef PYTHON_H
#define PYTHON_H

class PythonInterface
{
public:
  PythonInterface(char* name);
  ~PythonInterface();
  static double objectiveFunction(std::vector<double> x);
  
private:
  static char* moduleName;
};

#endif