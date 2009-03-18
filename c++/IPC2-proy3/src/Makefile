CDEBUG = -ggdb
WARN = -Wall
CFLAGS = $(WARN) -O2
CFLAGSD =$(CDEBUG) $(CFLAGS)
CC = g++

OBJS = libra.o #cola.o lista.o pila.o libra.o
LIBS = 
# Objetivo principal
libra : $(OBJS)
	$(CC) $(CFLAGSD) -o main $(OBJS) $(LIBS)
# Salida para linux
libralinuxrelease : $(OBJS)
	$(CC) $(CFLAGSD) $(CFLAGS) -O2 -o $@ \
	$(OBJS) $(LIBS)
# Salida para Win32
librawin32release.exe: $(OBJS)
	$(CC) $(CFLAGSD) $(CFLAGS) -O2 -o $@ \
	$(OBJS) $(LIBS)
clean:
	rm -f *.o libra

#dependencias
cola.o : cola.cpp
	g++ $(WARN) $(CDEBUG) -c cola.cpp
lista.o : lista.cpp
	g++ $(WARN) $(CDEBUG) -c lista.cpp
pila.o : pila.cpp
	g++ $(WARN) $(CDEBUG) -c pila.cpp
libra.o : libra.cpp
	g++ $(WARN) $(CDEBUG) -c libra.cpp
libra.cpp :
	rm libra.o

