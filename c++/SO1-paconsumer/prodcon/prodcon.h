#ifndef _PRODCON_H
#define _PRODCON_H

#include <qsemaphore.h>
#include <qthread.h>
#include <cstdio>
#include <qvaluelist.h>
#include <semaphore.h>


static QValueList <int> buffer;
//static QMutex mutex;
//static QSemaphore vacio(10);
//static QSemaphore lleno(0);
static sem_t vacios;
static sem_t llenos;
static sem_t mutex;

class Consumidor: public QThread{
public:
	Consumidor();
private:
	int sigc;
protected:
	virtual void run();
};

class Productor: public QThread{
public:
	Productor();
private:
	int sigp;
protected:
	virtual void run();
};



#endif
