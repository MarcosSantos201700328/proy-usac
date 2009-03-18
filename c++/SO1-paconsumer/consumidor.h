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
 
#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include <qvariant.h>
#include <qwidget.h>
#include <qthread.h>
#include <qptrqueue.h>
#include "pacman.h"
#include <qsemaphore.h>
#include <qthread.h>
#include <cstdio>
#include <qvaluelist.h>
#include "testw.h"
#include "pacmanthread.h"
extern "C" {
#include <semaphore.h>
         //extern sem_t vacios;
         //extern sem_t llenos;
         //extern sem_t mutex;
};
class testW;
/** @class Consumidor @brief Representa como hilo a un consumidor para resolver problema de buffer limitado */
class Consumidor: public QThread{
    public:
        Consumidor();
        Consumidor(sem_t* pVacios, sem_t* pLlenos, sem_t* pMutex, testW* pVentana);
        ~Consumidor();
    private:
        pacmanThread* sigc;///< Hilo de la clase pacman que se consumira
        testW* ventana;///<Widget que se modificara
        sem_t* vacios;///<Semaforo de vacios
        sem_t* llenos;///<Semaforo de llenos
        sem_t* mutex;///<Semaforo de exclusion mutua
    protected:
        virtual void run();///<Metodo run, ahi tiene el algoritmo consumidor
};

#endif