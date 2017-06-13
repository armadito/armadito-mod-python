AC_INIT(armadito-mod-python, 0.0.1, fdechelle@teclib.com)
AM_INIT_AUTOMAKE([foreign])

# check for needed programs
AC_PROG_CC([gcc])
AC_PROG_LIBTOOL

PKG_PROG_PKG_CONFIG

# check for libarmadito
PKG_CHECK_MODULES(LIBARMADITO, libarmadito, [HAVE_LIBARMADITO=yes], [HAVE_LIBARMADITO=no])
# check for libarmadito/armadito.h in source tree
if test "$HAVE_LIBARMADITO" = "no"; then
   OLD_CPPFLAGS="$CPPFLAGS"
   CPPFLAGS=-I$srcdir/../../armadito-core/libmodule/include
   AC_CHECK_HEADER([libarmadito/armadito.h], [], [AC_MSG_ERROR([cannot find Armadito module library])], [])
   CPPFLAGS="$OLD_CPPFLAGS"
   LIBARMADITO_CFLAGS='-I$(top_srcdir)/../../armadito-core/libmodule/include'
   AC_SUBST([LIBARMADITO_CFLAGS])
fi

# check for python
AX_PYTHON_DEVEL(>= '3.5')

# Output files
AC_CONFIG_FILES([
Makefile
src/Makefile
])
AC_OUTPUT
