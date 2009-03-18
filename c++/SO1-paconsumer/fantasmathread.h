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

#ifndef FANTASMATHREAD_H
#define FANTASMATHREAD_H

#include "fantasma.h"
#include <qthread.h>
#include <pacmanthread.h>
/** @class fantasmaThread @brief Hilo que maneja el widget fantasma donde se encuentra el pixmap, en este se maneja los movimientos del fantasma dentro del widget*/
class fantasmaThread : public Fantasma, public QThread
{
  Q_OBJECT

public:
  fantasmaThread(QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
  ~fantasmaThread();
  
  /*$PUBLIC_FUNCTIONS$*/

public slots:
  /*$PUBLIC_SLOTS$*/
    void comer(pacmanThread *p);///<Metodo de comer @param pacmanThread Pacman a comer.
    void setVelocidad(int ms);///<slot para manejar la velocidad del fantasma @param ms periodo en milisegundos entre un frame y otro
protected:
  /*$PROTECTED_FUNCTIONS$*/
    virtual void run();///<Rutina de movimiento del fantasma en el escenario
    bool terminar;///<bandera para terminar la ejecucion del movimiento
    int velocidad;///<Entero que represente la velocidad
protected slots:
  /*$PROTECTED_SLOTS$*/

};

#endif

