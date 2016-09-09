#include <mpfr.h>
#include "PythonInterface.h"


char* PythonInterface::moduleName;
PyObject* PythonInterface::pyModuleName;
PyObject* PythonInterface::pyModule;
PyObject* PythonInterface::value;
PythonInterface::PythonInterface(char* name){
  setenv("PYTHONPATH","/usr/share/cgrasp-package",1);
  Py_Initialize();
  moduleName = name;
  pyModuleName = PyString_FromString(moduleName);
  pyModule = PyImport_Import(pyModuleName);

}

PythonInterface::~PythonInterface(){
  Py_Finalize();
}

double PythonInterface::objectiveFunction(std::vector<double> x){

  int n = x.size();
  PyObject *pyList = PyList_New(n);

  for (int i = 0; i < n; i++){
    value = PyFloat_FromDouble(x[i]);
    PyList_SetItem(pyList, i, value);
  }
  
  
  PyObject* result = PyObject_CallMethod(pyModule, moduleName,"O",pyList);
  Py_XDECREF(pyList);
  
  double retorno = PyFloat_AsDouble(result);
  Py_XDECREF(result);
  
  return retorno;
}
