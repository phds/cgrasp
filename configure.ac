AC_INIT([cgrasp-package], [1.0], [phds@cin.ufpe.br rmf4@cin.ufpe.br])


# Force autoconf to be at least this version number.
AC_PREREQ([2.68])

# Put autotools auxiliary files in a subdir, so they don't clutter top dir.
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT
# Enable "automake" to simplify creating makefiles. foreign relaxes some GNU
# checks. -Wall and -Werror are instructions to Automake, not gcc.
# Because this is a non-recursive automake, we use subdir-objects to tell
# automake to create objects such as .o in sub-directories rather than placing
# all artifacts in the top level directory.
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])

# These are the files to be generated.
AC_CONFIG_FILES([Makefile])

# Safety check - list a source file that wouldn't be in other directories.
AC_CONFIG_SRCDIR([src/cgraspInterface.cpp])

# Put configuration results in this file for us to #include in our program.

AC_CONFIG_HEADERS([config.h])

# Check for a C++ compiler.
#: ${CXXFLAGS="-g3 -O3"}
AC_PROG_CXX

AC_PROG_LIBTOOL




# Last line: actually generate all required output files.
AC_OUTPUT