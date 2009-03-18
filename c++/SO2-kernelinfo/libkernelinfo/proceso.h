/***************************************************************************
 *   Copyright (C) 2008 by Erik Giron, Marlon Manzo, Juan Carlos Lopez, Pedro Domingo   *
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
#ifndef PROCESO_H
#define PROCESO_H
#include <qthread.h>
#include <qptrlist.h>
#include <qstring.h>
#include <qdir.h>
/** Clase que representa un proceso
	@author Erik Giron, Marlon Manzo, Juan Carlos Lopez, Pedro Domingo <erik_giron@yahoo.com>
*/
namespace libkernelinfo{
class proceso{
    private:
        int pid;
        int procesador;
        QString nombre;
        QString comando;
        QString status;
        int memoria;
        const QStringList obtenerListaDirectorios();///<Obtiene la lista de directorios
        proceso* obtenerProcesoFromFile(QString);///<Lee del proc el directorio del proceso especificado por QFileInfo y retorna un objeto proceso
        
    public:    
        proceso();///<Crea un nuevo descriptor de proceso
        proceso(int pid);///<Crea un nuevo descriptor de proceso @param pid define el pid
        ~proceso();        
        QPtrList<proceso>* obtenerLista();///<Devuelve la lista de procesos
        static int matar(int ppid); ///Mata el proceso seleccionado si se tienen los permisos, @param ppid proceso a eliminar
        
        /**Accesores*/
	void setNombre(const QString& theValue)
	{
	        nombre = theValue;
	}
	

	QString getNombre() const
	{
	        return nombre;
	}

	void setPid(int theValue)
	{
	        pid = theValue;
	}
	

        int getPid() const
	{
	        return pid;
	}

	void setProcesador(int theValue)
	{
	        procesador = theValue;
	}
	

        int getProcesador() const
	{
	        return procesador;
	}

	void setComando(const QString& theValue)
	{
	        comando = theValue;
	}
	

        QString getComando() const
	{
	        return comando;
	}

	void setStatus(const QString& theValue)
	{
	        status = theValue;
	}
	

        QString getStatus() const
	{
	        return status;
	}

	void setMemoria(int theValue)
	{
	        memoria = theValue;
	}
	

        int getMemoria() const
	{
	        return memoria;
	}
	
	
	
	
	
	
};
}
#endif


