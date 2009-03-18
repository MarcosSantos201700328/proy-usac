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
#include "consumidor.h"


Consumidor::Consumidor(){
}

void Consumidor::run(){
    while(true){
    
        qDebug("Iniciando Consumidor");
        sem_wait(llenos);
        sem_wait(mutex);
        sleep(1);
        //sigc = buffer.last();
        //buffer.pop_back();
        qDebug("llamando remove");
        sigc = ventana->remove();
        
        //sigc->start();
        qDebug("sacado, cantidad: %d\n",ventana->getCantidad());
        //
     
        //wait(1000);
        sem_post(mutex);
        sem_post(vacios);
        //delete sigc;
        
    }
  
}

Consumidor::Consumidor(sem_t* pVacios, sem_t* pLlenos, sem_t* pMutex, testW* pVentana)
{
    vacios = pVacios;
    llenos = pLlenos;
    mutex = pMutex;
    ventana = pVentana;
}

Consumidor::~ Consumidor()
{
    if(sigc!=NULL)
        delete sigc;
}

