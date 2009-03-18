FORMS += MainWindow.ui \
 pacman.ui \
 buffer.ui \
 TestWindow.ui \
 fantasma.ui

HEADERS += main.h \
 consumidor.h \
 Productor.h \
 testw.h \
 pacmanthread.h \
 fantasmathread.h

SOURCES += main.cpp \
 consumidor.cpp \
 Productor.cpp \
 testw.cpp \
 pacmanthread.cpp \
 fantasmathread.cpp

TEMPLATE = app

CONFIG -= release

CONFIG += debug

