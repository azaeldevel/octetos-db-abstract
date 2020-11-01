AUTOMAKE_OPTIONS=foreign 1.4

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(OCTETOS_DB_ABSTRACT_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = liboctetos-db.la

liboctetos_db_la_LIBADD = $(OCTETOS_CORE_LIBS)
liboctetos_db_la_SOURCES = clientdb.cc

octetos_db_includedir = $(includedir)/octetos/db
pkgconfigdir = $(libdir)/pkgconfig
octetos_db_include_HEADERS = clientdb.hh
pkgconfig_DATA = octetos-db-abstract.pc
EXTRA_DIST = octetos-db-abstract.pc.in