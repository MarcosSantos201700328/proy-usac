#include "prodcon.h"
#include <cmath>
#include <cstdlib>
#include <cstdio>


//#include <iostream>

//using ios;

Consumidor::Consumidor(){
}

void Consumidor::run(){
  while(true){
    
    qDebug("Iniciando Consumidor");
    sem_wait(&llenos);
    sem_wait(&mutex);
    
    sigc = buffer.last();
    buffer.pop_back();
    sleep(1);
     
    //wait(1000);
    sem_post(&mutex);
    sem_post(&vacios);
    qDebug("Se saco el entero: %d, buffer: %d\n",sigc, buffer.count());
  }
  
}

Productor::Productor(){
}

void Productor::run(){
  while(true){
    qDebug("Iniciando productor");
    sigp = rand() % 10;
    sem_wait(&vacios);
    sem_wait(&mutex);
    //agregamos a buffer		
    buffer.push_front(sigp);
    qDebug("Se sambutio el entero: %d, buffer:%d\n",sigp, buffer.count());
     sleep(1);
//    wait(1000);
    sem_post(&mutex);
    sem_post(&llenos);
  }
  
}

int main(int argc, char* argv[]){
	qDebug("Iniciando");
	sem_init(&vacios,1,10);
	sem_init(&llenos,1,0);
	sem_init(&mutex,1,1);
		QThread * p = new Productor();
		QThread * c = new Consumidor();	
	//mutex = new QSemaphore(1);
	//	mutex = new QMutex();
	//	vacio = new QSemaphore(10);
	//lleno = new QSemaphore(0);
	c->start(QThread::NormalPriority);
	p->start(QThread::HighPriority);
	p->wait();
	c->wait();
}	
