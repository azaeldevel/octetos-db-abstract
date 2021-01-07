
AC_INIT(octetos-db-abstract, 0.6.0-alpha,azael.devel@gmail.com)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CXX
AC_PROG_LIBTOOL


LT_INIT


PKG_CHECK_MODULES(OCTETOS_CORE, octetos-core)

AM_CONDITIONAL(WITH_MEDIUMWORD, test x"$with_mediumword" = "xyes")
AC_ARG_WITH([mediumword], AS_HELP_STRING([--with-mediumword], [Define el tamno de los datos usados.]))

AM_CONDITIONAL(WITH_HIGHWORD, test x"$with_highword" = "xyes")
AC_ARG_WITH([mediumword], AS_HELP_STRING([--with-highword], [Define el tamno de los datos usados.]))

AM_CONDITIONAL(WITH_LOWWORD, test x"$with_lowword" = "xyes")
AC_ARG_WITH([mediumword], AS_HELP_STRING([--with-lowword], [Define el tamno de los datos usados.]))



AC_OUTPUT([
Makefile
src/Makefile
src/octetos-db-abstract.pc
])
