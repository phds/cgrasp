#include "PythonInterface.h"


char* PythonInterface::moduleName;

PythonInterface::PythonInterface(char* name){
  setenv("PYTHONPATH","../libs",1);
  Py_Initialize();
  moduleName = name;
  
}

PythonInterface::~PythonInterface(){

}

double PythonInterface::objectiveFunction(std::vector<double> x){

  int n = x.size();
  PyObject *pyList = PyList_New(n);
  PyObject *value;

  for (int i = 0; i < n; i++){
    //printf("values %f\n", x[i]);
    value = PyFloat_FromDouble(x[i]);
    PyList_SetItem(pyList, i, value);

  }


  PyObject* pyModuleName = PyString_FromString(moduleName);
  PyObject* pyModule = PyImport_Import(pyModuleName);
  PyObject* result = PyObject_CallMethod(pyModule, moduleName,"O",pyList);

  return PyFloat_AsDouble(result);
}
