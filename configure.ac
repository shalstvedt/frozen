AC_PREREQ(2.5)
AC_INIT([frozen], [1.0.0], [x86mail@gmail.com])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build])

AM_INIT_AUTOMAKE(1.11)

AC_PROG_CC
AC_PROG_LIBTOOL
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h])
AC_FUNC_MALLOC
AC_CHECK_FUNCS([floor])
AC_CHECK_FUNCS([ftruncate])
AC_CHECK_FUNCS([gettimeofday])
AC_CHECK_FUNCS([memmove])
AC_CHECK_FUNCS([memset])
AC_CHECK_FUNCS([strcasecmp])
AC_CHECK_FUNCS([strchr])
AC_CHECK_FUNCS([strdup])
AC_CHECK_FUNCS([strrchr])
AC_CHECK_FUNCS([strtoul])
AC_CHECK_FUNCS([strerror])
AC_CHECK_FUNCS([snprintf])
AC_CHECK_HEADERS([fcntl.h])
AC_CHECK_HEADERS([float.h])
AC_CHECK_HEADERS([limits.h])
AC_CHECK_HEADERS([malloc.h])
AC_CHECK_HEADERS([sys/param.h])
AC_CHECK_HEADERS([sys/time.h])
AC_C_INLINE
AM_PROG_CC_C_O
AC_FUNC_ALLOCA
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_HEADER_STDBOOL
AC_PROG_CXX
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

AC_CHECK_LIB(pthreads, pthread_create, [],
[AC_CHECK_LIB(pthread, pthread_create)])

AC_CHECK_LIB(dl, dlopen, [DL=1], [DL=0])
AM_CONDITIONAL([HAVE_DL], [test "$DL" = 1])

AC_ARG_WITH([fuse],
  [AS_HELP_STRING([--with-fuse],
    [support fuse filesystem @<:@default=check@:>@])],
  [],
  [with_fuse=check])
AS_CASE(["$with_fuse"],
  [yes], [PKG_CHECK_MODULES([FUSE], [fuse >= 2.6.0], [HAVE_FUSE=1], [HAVE_FUSE=0])],
  [no], [HAVE_FUSE=0],
  [PKG_CHECK_MODULES([FUSE], [fuse >= 2.6.0], [HAVE_FUSE=1], [HAVE_FUSE=0])]
)

AC_PATH_PROGS(M4, [gm4 m4], no)
AC_PATH_PROGS(LS, [ls], no)
AC_PATH_PROGS(AWK, [gawk awk], no)
AC_PATH_PROGS(SED, [sed], no)
AC_PATH_PROGS(BISON, [bison], no)
AC_PATH_PROGS(FLEX, [flex], no)
AC_PATH_PROGS(PERL, [perl perl5], no)

AC_DEFINE_UNQUOTED([M4PATH], "${M4}", [Define m4 path])

sinclude(./build/libfrozen_machines.m4)
sinclude(./build/libfrozen_data.m4)
sinclude(./build/libfrozen_modules.m4)
esyscmd(./build/configs-find)
FROZEN_MACHINE_END
FROZEN_DATA_END
FROZEN_MODULE_END

esyscmd(./build/libfrozen_errors.pl)
esyscmd(./build/libfrozen_hashkeys.sh)

AC_ARG_ENABLE(coverage, AS_HELP_STRING([--enable-coverage], [enable coverage testing]))
if test "x${enable_coverage}" = "xyes"; then
	CFLAGS="$CFLAGS --coverage"
fi

AC_ARG_ENABLE(debug,  AS_HELP_STRING([--enable-debug],  [compile with debug symbols]))
if test "x$enable_debug" == "xyes"; then
	HAVE_DEBUG="-DDEBUG=1"
        CFLAGS="$CFLAGS -g3 -O0 -Wall -Werror ${HAVE_DEBUG}"
	AC_SUBST([HAVE_DEBUG])
fi

AC_ARG_ENABLE(profile,  AS_HELP_STRING([--enable-profile],  [enable code profiling]))
if test "x$enable_profile" == "xyes"; then
        CFLAGS="$CFLAGS -pg"
        LDFLAGS="$LDFLAGS -pg"
fi

AC_ARG_ENABLE(resolve-dynamic-keys,   AS_HELP_STRING([--disable-resolve-dynamic-keys],  [disable dynamic hashkeys resolve (from value to name)] ))
if test "x$enable_resolve-dynamic-keys" != "xyes"; then
	AC_DEFINE([RESOLVE_DYNAMIC_KEYS], [1], [Define if dynamic resolve enabled])
fi
AC_ARG_ENABLE(collision-check,  AS_HELP_STRING([--disable-collision-check],  [disable hashkeys collision checks (dangerous!)]))
if test "x$enable_collision-check" != "xyes"; then
	AC_DEFINE([COLLISION_CHECK], [1], [Define if collision check enabled])
fi
AC_ARG_ENABLE(collision-stat-check,  AS_HELP_STRING([--disable-collision-stat-check],  [disable static hashkeys collision checks (dangerous!)]))
if test "x$enable_collision-stat-check" != "xyes"; then
	AC_DEFINE([STATIC_KEY_CHECK], [1], [Define if static collision check enabled])
fi
AC_ARG_ENABLE(collision-dyn-check,   AS_HELP_STRING([--disable-collision-dyn-check],  [disable dynamic hashkeys collision checks (dangerous!)]))
if test "x$enable_collision-dyn-check" != "xyes"; then
	AC_DEFINE([DYNAMIC_KEY_CHECK], [1], [Define if dynamic collision check enabled])
fi

modulesdir=${libexecdir}/frozen/
headersdir=${includedir}/frozen/
m4sdir=${libexecdir}/frozen/m4/
AC_SUBST(modulesdir)
AC_SUBST(headersdir)
AC_SUBST(m4sdir)

AC_CONFIG_FILES([Makefile
		doc/Makefile
		src/Makefile
		src/libfrozen/Makefile
		src/libfrozen/core/Makefile
		src/libfrozen/machines/Makefile
		src/libfrozen/data/Makefile
		src/frozend/Makefile
		src/m4/Makefile
		src/modules/Makefile
		test/Makefile
		$GEN_MAKEFILES
])
AC_OUTPUT
