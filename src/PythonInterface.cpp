#include "PythonInterface.h"


char* PythonInterface::moduleName;
PyObject* pyModuleName;
PyObject* pyModule;
PythonInterface::PythonInterface(char* name){
  setenv("PYTHONPATH","../libs",1);
  Py_Initialize();
  moduleName = name;
  pyModuleName = PyString_FromString(moduleName);
  //pyModule = PyImport_Import(pyModuleName);
  //PyRun_SimpleString("import ackley");
}

PythonInterface::~PythonInterface(){
  Py_Finalize();
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


  pyModule = PyImport_Import(pyModuleName);
  PyObject* result = PyObject_CallMethod(pyModule, moduleName,"O",pyList);
  
  //PyObject_Print(pyModuleName, stdout, 0);
  //PyObject_Print(pyModule, stdout, 0);
  return PyFloat_AsDouble(result);
}
