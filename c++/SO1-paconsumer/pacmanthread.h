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

#ifndef PACMANTHREAD_H
#define PACMANTHREAD_H

#include "pacman.h"
#include <qthread.h>
#include "fantasma.h"
/**Clase que representa un hilo de un widget pacman.*/
class pacmanThread : public Pacman, public QThread
{
  Q_OBJECT

public:
  pacmanThread(QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
  ~pacmanThread();
  /*$PUBLIC_FUNCTIONS$*/

public slots:
  /*$PUBLIC_SLOTS$*/
    virtual void run();///<Metodo para iniciar la ejecucion del movimiento del pacman actual en el escenario.

	//void setEnemigo ( Fantasma* pValue )
	//{
//		enemigo = pValue;
//	}
        /**Asigna enemigos en escenario*/
        void setEnemigos ( Fantasma* pValue1, Fantasma* pValue2 )
        {
            enemigo = pValue1;
            enemigo2 = pValue2;
        }
        /**Devuelve enemigos del escenario*/
	Fantasma* getEnemigo() const
	{
		return enemigo;
	}
	
protected:
  /*$PROTECTED_FUNCTIONS$*/
    Fantasma* enemigo;///<puntero a Enemigo 1
    Fantasma* enemigo2;///<puntero a Enemigo 2
protected slots:
  /*$PROTECTED_SLOTS$*/

};

#endif

