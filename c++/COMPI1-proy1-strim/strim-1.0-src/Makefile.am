#SUBDIRS = grammar
AUTOMAKE_OPTIONS = foreign 1.9 dist-bzip2 

bin_PROGRAMS = strim
strim_CFLAGS = -Wall -ggdb
strim_CXXFLAGS = -Wall -ggdb
strim_YFLAGS = -v -d -t
strim_LFLAGS = -v
strim_SOURCES =  lexer.l parser.y menu.hpp menu.cpp funciones.h \
strim.hpp funciones.c strim.cpp
INCLUDES = $(all_includes)
strim_LDFLAGS = $(all_libraries)