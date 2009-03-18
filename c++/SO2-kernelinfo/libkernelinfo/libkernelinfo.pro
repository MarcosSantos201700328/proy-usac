TEMPLATE = lib

CONFIG += staticlib \
debug
CONFIG -= release

MAKEFILE = /home/kreig/projects/kernelinfo/libkernelinfo/Makefile

SOURCES += device.cpp \
memoria.cpp \
modulo.cpp \
proceso.cpp
HEADERS += device.h \
memoria.h \
modulo.h \
proceso.h

