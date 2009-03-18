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


#include "fantasmathread.h"

fantasmaThread::fantasmaThread(QWidget* parent, const char* name, WFlags fl)
: Fantasma(parent,name,fl)
{
    QMutex m;
    //m.lock();
    velocidad = 10;    
    terminar = false;
    //m.unlock();
}

fantasmaThread::~fantasmaThread()
{
}

/*$SPECIALIZATION$*/

void fantasmaThread::run()
{
    while(!terminar){
        for(int i = this->parentWidget(true)->geometry().width();
            i > 0;
            i--){            
                this->move(i, this->geometry().y());
                this->parentWidget(true)->update();
                msleep(velocidad);
            }
        for(int i = 0;            
            i < this->parentWidget(true)->geometry().width();
            i++){                
                    
                this->move(i, this->geometry().y());        
                this->parentWidget(true)->update();
                msleep(velocidad);
            }
            //mueve hacia abajo
            
    }
}

void fantasmaThread::comer(pacmanThread * p)
{    
    QMutex m;
    //m.lock();
    //p->wait();
    //p->terminate();
    p->hide();    
    //p->wait();
    p->terminate();
    delete(p);        
    //m.unlock();
    //terminar = true;
    //this->terminate();    
    //this->hide();
    //QThread::exit();
    //delete (this);
}

void fantasmaThread::setVelocidad(int ms)
{
    QMutex m;
    //m.lock();
    velocidad = ms;
    //m.unlock();

}




