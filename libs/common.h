//for general libraries

#include <iostream>
//for platform-specific libraries
#ifdef __APPLE__
    #include <Python/Python.h>
#elif __linux__
    #include <Python.h>
#endif