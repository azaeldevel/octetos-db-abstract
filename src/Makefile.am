AUTOMAKE_OPTIONS=foreign 1.4


lib_LTLIBRARIES = liboctetos-db-abstract.la

DEFINITIONS = 
if WITH_MEDIUMWORD
DEFINITIONS += -DOCTETOS_DB_MEDIUMWORD
endif
if WITH_HIGHWORD
DEFINITIONS += -DOCTETOS_DB_MEDIUMWORD
endif
if WITH_LOWWORD
DEFINITIONS += -DOCTETOS_DB_MEDIUMWORD
endif

liboctetos_db_abstract_la_CXXFLAGS = $(OCTETOS_CORE_CGLAGS) $(DEFINITIONS)
liboctetos_db_abstract_la_LIBADD = $(OCTETOS_CORE_LIBS)
liboctetos_db_abstract_la_SOURCES = clientdb.cc

octetos_db_includedir = $(includedir)/octetos/db
pkgconfigdir = $(libdir)/pkgconfig
octetos_db_include_HEADERS = clientdb.hh
pkgconfig_DATA = octetos-db-abstract.pc
EXTRA_DIST = octetos-db-abstract.pc.in