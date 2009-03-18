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


#include "pacmanthread.h"
#include "fantasmathread.h"
pacmanThread::pacmanThread(QWidget* parent, const char* name, WFlags fl)
: Pacman(parent,name,fl)
{
}

pacmanThread::~pacmanThread()
{
}

/*$SPECIALIZATION$*/

void pacmanThread::run()
{
    while(true){
        //mueve el widget hacia arriba
        for(int i = 0;
            i < this->parentWidget(true)->geometry().height();
            i++){                
                
                this->move(this->geometry().x(),i);        
                this->parentWidget(true)->update();
                msleep(10);
                //si se intersectan
                if(this->geometry().intersects(this->enemigo->geometry()) || this->geometry().intersects(this->enemigo2->geometry()) )
                    ((fantasmaThread*)enemigo)->comer(this);                
            }
        //mueve hacia abajo
            for(int i = this->parentWidget(true)->geometry().height();
            i > 0;
            i--){            
                this->move(this->geometry().x(),i);
                this->parentWidget(true)->update();
                msleep(10);
                if(this->geometry().intersects(this->enemigo->geometry()) || this->geometry().intersects(this->enemigo2->geometry()))
                    ((fantasmaThread*)enemigo)->comer(this);
            }
    }
}




