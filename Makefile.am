ACLOCAL_AMFLAG= -I m4 install
EXTRA_DIST = m4/NOTES


AM_CPPFLAGS = -I/usr/include/python2.7 -lpython2.7 -lmpfr -lgmp -lm -std=c++11 -lboost_program_options -lboost_system

include_HEADERS = ../src/cgrasp.h


# This is the top-level Makefile.am for a non-recursive Autotools setup. In
# fact, in non-recursive structures, this is the only Makefile.am that is
# needed. The programs (just foo.exe in this case) will be left in the top-level
# directory.

bin_PROGRAMS = cgrasp

cgrasp_SOURCES = ../src/cgraspInterface.cpp 


lib_LTLIBRARIES = libcgrasp.la

cgrasp_LDADD = libcgrasp.la

libcgrasp_la_SOURCES = ../src/PythonInterface.cpp ../src/cgrasp.cpp ../src/ConstructGreedyRandomized.cpp ../src/linesearch.cpp ../src/localImprovement.cpp ../libs/common.h

LIBS = -I/usr/include/python2.7 -lpython2.7 -lmpfr -lgmp -lm -std=c++11 -lboost_program_options -lboost_system

pkgdata_DATA = ../libs/ackley.py ../libs/alan.py ../libs/batch.py ../libs/bohachevsky.py ../libs/booth.py ../libs/branin.py ../libs/colville.py ../libs/griewank.py ../libs/levy.py ../libs/matyas.py ../libs/rastrigin.py ../libs/schwefel.py ../libs/waters.py ../libs/waterz.py ../libs/ex1221.py ../libs/nvs04.py ../libs/gear2.py ../libs/gear3.py ../libs/nous1.py ../libs/nuclear14a.py ../libs/ghg_1veh.py ../libs/st_e13.py ../libs/tls6.py ../libs/csched1.py ../libs/du-opt.py ../libs/fac1.py ../libs/ex1223.py ../libs/synheat.py ../libs/batchdes.py ../libs/ex1265.py ../libs/tloss.py ../libs/elf.py ../libs/gbd.py ../libs/hmittelman.py ../libs/oaer.py ../libs/procsel.py ../libs/synthes1.py ../libs/ex1223a.py ../libs/ex1223b.py ../libs/gear4.py ../libs/st_e15.py ../libs/st_e27.py ../libs/st_e38.py ../libs/st_miqp5.py