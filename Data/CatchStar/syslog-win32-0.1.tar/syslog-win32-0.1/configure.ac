m4_include([version.m4]) dnl
AC_INIT(syslog-win32, [VERSION_NUMBER])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

AM_INIT_AUTOMAKE($PACKAGE_NAME, $PACKAGE_VERSION)

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

dnl *************************************************************************
dnl Check for native win32
dnl *************************************************************************

AC_MSG_CHECKING([if building for native Win32])
case "$host" in
	*-*-mingw*)
		native_win32="yes"
	;;
	*)
		native_win32="no"
	;;
esac
AC_MSG_RESULT($native_win32)
AM_CONDITIONAL(OS_WIN32, test x"${native_win32}" = xyes)

dnl *************************************************************************
dnl Parameters
dnl *************************************************************************

AC_ARG_ENABLE(relocatable,
              [AC_HELP_STRING([--enable-relocatable],
                              [build relocatable package [default=yes]])],
              relocatable=$enableval,
              relocatable=yes)

if test x"${relocatable}" = xyes ; then
	AC_DEFINE(ENABLE_RELOCATABLE)
fi
AM_CONDITIONAL(RELOCATABLE, test x"${relocatable}" = xyes)

AC_ARG_ENABLE([debug],
              AC_HELP_STRING([--enable-debug],
                             [enable use of debugging code (default=no)]),
  	      enable_debug=$enableval,
  	      enable_debug=no)

if test x"${enable_debug}" != xno ; then
	AC_DEFINE([HAVE_DEBUG])
fi
AM_CONDITIONAL(DEBUG, test x"${enable_debug}" = xyes)

dnl *************************************************************************
dnl Check for glib,
dnl leave CPPFLAGS, LDFLAGS and LIBS set
dnl *************************************************************************

AM_PATH_GLIB_2_0(2.0.0, ,AC_MSG_ERROR(Cannot find GLIB))
glib_cflags="$GLIB_CFLAGS"
glib_libs="$GLIB_LIBS"
AC_SUBST(glib_cflags)
AC_SUBST(glib_libs)

dnl *************************************************************************

AC_CONFIG_FILES([
	Makefile
	daemon/Makefile
	client/Makefile
	test/Makefile
	etc/Makefile
	extras/Makefile
])

AC_OUTPUT
