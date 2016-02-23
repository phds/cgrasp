ACLOCAL_AMFLAG= -I m4 install
EXTRA_DIST = m4/NOTES

# Always set this so that we can just '#include "cgrasp.h"' from anywhere,
# including our tests directory.
#AM_CPPFLAGS = -I$(top_srcdir)/src

AM_CPPFLAGS = -I/usr/include/python2.7 -lpython2.7 -lmpfr -lgmp -lm -std=c++11 -lboost_program_options



# This is the top-level Makefile.am for a non-recursive Autotools setup. In
# fact, in non-recursive structures, this is the only Makefile.am that is
# needed. The programs (just foo.exe in this case) will be left in the top-level
# directory.
bin_PROGRAMS = cgrasp

cgrasp_SOURCES = src/cgraspInterface.cpp src/cgraspInterface.h src/PythonInterface.cpp src/cgrasp.cpp src/ConstructGreedyRandomized.cpp src/linesearch.cpp src/localImprovement.cpp

# To specify extra flags for each target you can do this.
# But it is better to pass them on the command line (using a custom script to
# make the process easier; see the example in the debug folder). Doing it that
# way ensures the core build system stays free of cruft that may not port to
# other machines or compilers.
#foo_CXXFLAGS = -pedantic

LIBS = -lboost_program_options -I/usr/include/python2.7 -lpython2.7 -lmpfr -lgmp -lm -std=c++11
