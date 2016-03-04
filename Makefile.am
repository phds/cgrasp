ACLOCAL_AMFLAG= -I m4 install
EXTRA_DIST = m4/NOTES


AM_CPPFLAGS = -I/usr/include/python2.7 -lpython2.7 -lmpfr -lgmp -lm -std=c++11 -lboost_program_options

include_HEADERS = ../src/cgrasp.h

# This is the top-level Makefile.am for a non-recursive Autotools setup. In
# fact, in non-recursive structures, this is the only Makefile.am that is
# needed. The programs (just foo.exe in this case) will be left in the top-level
# directory.

bin_PROGRAMS = cgrasp

cgrasp_SOURCES = ../src/cgraspInterface.cpp 

#cgrasp_SOURCES = ../src/cgraspInterface.cpp ../src/PythonInterface.cpp ../src/ackley.cpp ../src/cgrasp.cpp  ../src/ConstructGreedyRandomized.cpp ../src/linesearch.cpp ../src/localImprovement.cpp ../libs/common.h


lib_LTLIBRARIES = libcgrasp.la

cgrasp_LDADD = libcgrasp.la

libcgrasp_la_SOURCES = ../src/PythonInterface.cpp ../src/cgrasp.cpp ../src/ConstructGreedyRandomized.cpp ../src/linesearch.cpp ../src/localImprovement.cpp ../libs/common.h




LIBS = -lboost_program_options -I/usr/include/python2.7 -lpython2.7 -lmpfr -lgmp -lm -std=c++11




