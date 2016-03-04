#include "PythonInterface.h"


char* PythonInterface::moduleName;
PyObject* PythonInterface::pyModuleName;
PyObject* PythonInterface::pyModule;
PyObject* PythonInterface::value;
PythonInterface::PythonInterface(char* name){
  setenv("PYTHONPATH","../libs",1);
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
  //printf ("PyList ref count: %zd\n",pyList->ob_refcnt);
  

  for (int i = 0; i < n; i++){
    //printf("values %f\n", x[i]);
    value = PyFloat_FromDouble(x[i]);
    //printf ("value ref count: %zd\n",value->ob_refcnt);
    PyList_SetItem(pyList, i, value);
    //printf("PyList INCREF for position %d\n",i);
  }
  
  
  
  //printf("pyList ref count after loop before xdecref %zd\n",pyList->ob_refcnt );
  
  //PyObject* pyModuleName = PyString_FromString(moduleName);
  //PyObject* pyModule = PyImport_Import(pyModuleName);
  
  
  PyObject* result = PyObject_CallMethod(pyModule, moduleName,"O",pyList);
  Py_XDECREF(pyList);
  //Py_DECREF(result);
  //printf("pyList after xdecref count after xdecref%zd\n",pyList->ob_refcnt );
  

  


  //printf ("result ref count: %zd\n",result->ob_refcnt);

  //PyObject_Print(pyModuleName, stdout, 0);
  //PyObject_Print(pyModule, stdout, 0);
  

  double retorno = PyFloat_AsDouble(result);
  Py_XDECREF(result);
  
  
  

  //printf("pymodule ref count after decref:%zd\n",pyModule->ob_refcnt );
  //printf ("result ref count after xdecref:  %zd\n",result->ob_refcnt);
  return retorno;
}
