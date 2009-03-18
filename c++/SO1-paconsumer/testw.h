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

#ifndef TESTW_H
#define TESTW_H

#include "TestWindow.h"
#include <qptrlist.h>
#include "pacmanthread.h"
#include "Productor.h"
#include "consumidor.h"
extern "C" {
#include <semaphore.h>
};
#include "fantasmathread.h"
#include <qmutex.h>
#include <qthread.h>
class Consumidor;
class Productor;
/**Representa la ventana principal de la aplicacion*/
class testW : public TestWindow,public QThread
{
  Q_OBJECT

public:
  testW(QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
  ~testW();
  /*$PUBLIC_FUNCTIONS$*/
    QPtrList<pacmanThread> listaPacmans;///<Buffer limitado de pacmans
    //semaforos a utilizar
    sem_t vacios;///<Semaforo de vacios
    sem_t llenos;///<Semaforo de llenos
    sem_t mutex;///<Semaforo de exclusion mutua
    int getCantidad();///<@return cantidad de pacmans en el buffer
    QMutex m;///<Mutex de prueba
    void autostart();///<Metodo para autoiniciar la aplicacion
public slots:
  /*$PUBLIC_SLOTS$*/
  virtual pacmanThread*          remove();///<Elimina un pacman del buffer
  virtual void          add();///<Agrega un nuevo pacman al buffer
    virtual void end();///<Termina ejecucion del hilo
    virtual void begin();    ///<Inicia ejecucion del hilo.
    
protected:
  /*$PROTECTED_FUNCTIONS$*/    
    virtual void run();///<Metodo principal de ejecucion
protected slots:
  /*$PROTECTED_SLOTS$*/

    private:
        void meter(pacmanThread*);///<Inserta un nuevo pacman al buffer @param 1 pacman a insertar
        pacmanThread* sacar();///<Saca pacman del buffer, @return pacman sacado.
        Consumidor* con;///<Clase que controla el consumo de pacmans en este problema de buffer limitado.
        Productor* p;///<Clase que controla la generacion de pacmans hacia el buffer en eeste problema de buffer limitado.
        fantasmaThread * fantasma1, * fantasma2;///<Enemigos que se encuentran en el escenario.
        
};

#endif

