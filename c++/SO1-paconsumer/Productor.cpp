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
#include "Productor.h"
#include "pacmanthread.h"

#include <testw.h>
Productor::Productor(){
}

/**Metodo run del thread*/
void Productor::run(){
    while(true){
        qDebug("Iniciando productor");
        //sigp = rand() % 10;
        //pacmanThread * nuevo = new pacmanThread();
        sem_wait(vacios);
        sem_wait(mutex);
    //agregamos a buffer		
        //buffer.push_front(sigp);
        sleep(1);
        qDebug("llamando add");
        ventana->add();//(nuevo);
  //      qDebug("Se sambutio el entero: %d, buffer:%d\n",sigp, buffer.count());
        qDebug("agregado: cantidad: %d\n",ventana->getCantidad());
        
//    wait(1000);
        sem_post(mutex);
        sem_post(llenos);
    }
  
}

Productor::Productor(sem_t * pVacios, sem_t * pLlenos, sem_t * pMutex,testW * pVentana)
{
    vacios = pVacios;
    llenos = pLlenos;
    mutex = pMutex;
    ventana = pVentana;
            
}

Productor::~Productor()
{
    if(sigp != NULL){
        delete sigp;
    }
}