SOURCES += kernelinfo.cpp \
           main.cpp \
 f_main.cpp
HEADERS += kernelinfo.h \
 f_main.h
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt \
 debug
TARGET = ../bin/kernelinfo
LIBS += ../libkernelinfo/liblibkernelinfo.a

TARGETDEPS += ../libkernelinfo/liblibkernelinfo.a

FORMS += mainWindow.ui \
wdg_procesos.ui
CONFIG -= release

