AC_PREREQ([2.50])
AC_INIT([sortmedna],[1.0],[jenya DT kopylov AT gmail DT fr],[sortmedna],[http://bioinfo.lifl.fr/sortmedna])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([include/config.h])
AM_INIT_AUTOMAKE([subdir-objects])
# AM_SILENT_RULES([yes])
if test -z $CXXFLAGS; then
    CXXFLAGS='-O3'
fi
if test -z $CXXFLAGS; then
    CFLAGS='-O3'
fi
AC_PROG_CXX
AC_PROG_CC
AC_OPENMP
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_FUNC_MMAP
AC_SUBST(SSE2_EXTRA_CFLAGS)
CXXFLAGS="$CXXFLAGS -pipe -funroll-loops -Wall -msse2 $OPENMP_CFLAGS"
CFLAGS="$CFLAGS -pipe -funroll-loops -msse2 -Wall $OPENMP_CFLAGS"
LIBS="$LIBS -lm"
AC_SUBST(CXXFLAGS)
AC_SUBST(CFLAGS)
AC_SUBST(LIBS)
AC_CONFIG_FILES([Makefile])
AC_OUTPUT


