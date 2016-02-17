UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  CCFLAGS = -I/usr/include/python2.7/  -lpython2.7 -lmpfr -lgmp -lm -std=c++11 -lboost_program_options
endif
ifeq ($(UNAME_S),Darwin)
  CCFLAGS = -framework Python
endif

cgrasp: src/cgraspInterface.cpp src/PythonInterface.cpp
	g++ src/cgraspInterface.cpp src/PythonInterface.cpp -o bin/cgrasp $(CCFLAGS)