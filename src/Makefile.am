AUTOMAKE_OPTIONS=subdir-objects

modulesdir=$(libdir)/armadito/modules
modules_LTLIBRARIES=modpython.la

modpython_la_SOURCES=modpython.c libpython.h libpython.c

modpython_la_LDFLAGS= -module -avoid-version -export-symbols "$(srcdir)/modpython.sym" $(PYTHON_CPPFLAGS)œ
modpython_la_CFLAGS= @LIBARMADITO_CFLAGS@ $(PYTHON_CPPFLAGS)
modpython_la_LIBADD= $(PYTHON_LIBS)

install-exec-hook:
	-rm -f "$(DESTDIR)$(modulesdir)"/modpython.la "$(DESTDIR)$(modulesdir)"/modpython.a

install-data-hook:
	-rm -f "$(DESTDIR)$(modulesdir)"/modpython.la "$(DESTDIR)$(modulesdir)"/modpython.a

xoEXTRA_DIST=modpython.sym

noinst_PROGRAMS=test1

test1_SOURCES= test1.c
test1_CFLAGS= $(PYTHON_CPPFLAGS)
test1_LDFLAGS= $(PYTHON_CPPFLAGS)œ
test1_LDADD= $(PYTHON_LIBS)


