#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(practica1, 0.1, erik_giron@yahoo.com)
AM_INIT_AUTOMAKE(practica1,0.1)

# Checks for programs.
#AC_PROG_CXX
AC_PROG_CC
# para soporte de Flex
#AM_PROG_LEX 
# para soporte de Bison
#AC_PROG_YACC
#AC_PROG_MAKE_SET

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([inttypes.h stddef.h stdlib.h string.h unistd.h ext2fs/ext2fs.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT#([grammar/Makefile])
