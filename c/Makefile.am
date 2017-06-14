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

EXTRA_DIST=modpython.sym

