/***************************************************************************
 *   Copyright (C) 2007 by Erik Giron   *
 *   erik_giron@yahoo.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "testw.h"
#include <qlayout.h>
#include <cstdio>
#include <qgroupbox.h>
#include <fantasmathread.h>
#include <qapplication.h>
#include <qpushbutton.h>
testW::testW(QWidget* parent, const char* name, WFlags fl)
: TestWindow(parent,name,fl)
{   
    //m.lock();
    //iniciamos semaforos
    sem_init(&vacios,1,10);
    sem_init(&llenos,1,0);
    sem_init(&mutex,1,1);   
    p = new Productor(&vacios,&llenos,&mutex,this);
    con = new Consumidor(&vacios,&llenos,&mutex,this);	
    fantasma1 = new fantasmaThread(mainPanel,"enemigo1");
    fantasma1->move(0,this->geometry().height()*1 / 2);
    fantasma1->show();    
    fantasma1->start();
    fantasma1->wait(1000);
    fantasma2 = new fantasmaThread(mainPanel,"enemigo2");
    fantasma2->move(0,this->geometry().height()*1 / 4);
    fantasma2->show();        
    fantasma2->start();    
   // btnStart->setEnabled(true);
   // btnStop->setEnabled(false);
    //autostart();
    //m.unlock();
}

testW::~testW()
{
    //m.lock();
    this->grpbuffer->setColumns(10);
    //m.unlock();
}

/*$SPECIALIZATION$*/
/**interfaz para Sacar pacman del buffer y comienza ejecucion*/
pacmanThread* testW::remove()
{
    //m.lock();
    pacmanThread * tmp;
//    fantasmaThread * fantasma = new fantasmaThread(mainPanel,"enemigo");
    //printf("remove");
    tmp = this->sacar();//sacamos del buffer    
    tmp->setEnemigos(fantasma1,fantasma2); //asignamos enemgio
            //inicamos threads
    //fantasma->show();
    //fantasma->start();
    tmp->start();
    //m.unlock();
    return tmp;
}
/**Interfaz para agregar nuevo pacman*/
void testW::add()
{
    //printf("add");
    //m.lock();
    qDebug("entrando en testw::add()\n");
    this->meter(new pacmanThread());
    qDebug("saliendo en testw::add()\n");
    //m.unlock();
}


/**ingresa un nuevo hilo de pacman*/
void testW::meter(pacmanThread * p)
{
    //m.lock();
    if(p!=NULL){
        qDebug("entrando en testw::meter()\n");
        listaPacmans.append(p);        
        
        p->reparent(grpbuffer,QPoint(listaPacmans.count()*32,5),true);
        qDebug("medio en testw::meter()\n");
        this->update();
        qDebug("saliendo en testw::meter()\n");
    }
    //m.unlock();
    
}
/**quita un hilo de pacman*/
pacmanThread* testW::sacar(){
    //m.lock();
    if(!listaPacmans.isEmpty()){
        
        pacmanThread* tmp = listaPacmans.getLast();
        listaPacmans.removeLast(); //quiteamos pacman de la lista
        
        tmp->reparent(mainPanel,QPoint(0,0),true);//le asignamos nuevo padre
        this->update();        
        //m.unlock();
        return tmp;
    }
    //m.unlock();
    return NULL;
    
    
                                            
}
/**Inicia el juego*/
void testW::end()
{
    //m.lock();
    btnStart->setEnabled(true);
    btnStop->setEnabled(false);
    p->terminate();
    con->terminate();
    //m.unlock();
    
}

/**Finaliza la generacion de pacmans*/
void testW::begin()
{
    //m.lock();
    btnStart->setEnabled(false);
    btnStop->setEnabled(true);
    //con->start();
    p->start();
    //m.unlock();
   // p->wait();
    //con->wait();
}

int main(int argc, char* argv[]){
    QApplication* a;
    int ret;
    //MainWindow * mw;    
    testW * mw;
    a = new QApplication(argc,argv);
    //mw = new Main();
    mw = new testW();
    /*mw->setCaption( "GodZilla" );*/
    mw->show();
    a->connect( a, SIGNAL(lastWindowClosed()), a, SLOT(quit()) );
    ret = a->exec();
    mw->autostart();
    return ret;
                
}

int testW::getCantidad()
{
    this->listaPacmans.count();
}

void testW::autostart(){
    this->start();
    
}

void testW::run(){
/*   //while(true){
        while(listaPacmans.count() < 10){
            sleep(1);
            add();
        }
        while(listaPacmans.count() > 0){
            sleep(1);
            remove();
        }
        
    //}*/
}

