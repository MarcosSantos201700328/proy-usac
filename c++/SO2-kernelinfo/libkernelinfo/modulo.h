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
#ifndef LIBKERNELINFOMODULO_H
#define LIBKERNELINFOMODULO_H

#include <qstring.h>
#include <qptrlist.h>
namespace libkernelinfo
{

/** Clase que representa a una entrada de modulo del kernel
	@author Erik Giron, Marlon Manzo, Juan Carlos Lopez, Pedro Domingo <erik_giron@yahoo.com>
*/
class modulo
{
    private:
        QString nombre;
        QString dependencia;
        QString filepath;
        bool cargaInicio;
        QString descripcion;
        QString autor;
        uint tam;

    public:

        //Constructores
        modulo();

        ~modulo();


        //Operaciones
        int cargarAlKernel(void); ///< Carga el modulo actual al kernel de linux
        int descargarDelKernel(void); ///< descarga el modulo actual del kernel de linux
        QPtrList<modulo>* obtenerLista(); ///< Devuelve listado de descriptores de modulos disponibles en el sistema
        static int agregarAlInicio(int modulo); ///< Agrega modulo  para que sea cargado al inicio del sistema @param modulo modulo a cargar
        int agregarAlInicio(void);///< Agrega modulo actual para que sea cargado al inicio del sistema
        
        
        //Accesores
	void setNombre(const QString& theValue)
	{
	        nombre = theValue;
	}
	

	QString getNombre() const
	{
	        return nombre;
	}

	void setDependencia(const QString& theValue)
	{
	        dependencia = theValue;
	}
	

	QString getDependencia() const
	{
	        return dependencia;
	}

	void setFilepath(const QString& theValue)
	{
	        filepath = theValue;
	}
	

	QString getFilepath() const
	{
	        return filepath;
	}

	void setCargaInicio(bool theValue)
	{
	        cargaInicio = theValue;
	}
	

	bool getCargaInicio() const
	{
	        return cargaInicio;
	}

	void setDescripcion(const QString& theValue)
	{
	        descripcion = theValue;
	}
	

	QString getDescripcion() const
	{
	        return descripcion;
	}

	void setAutor(const QString& theValue)
	{
	        autor = theValue;
	}
	

	QString getAutor() const
	{
	        return autor;
	}

	void setTam(const uint& theValue)
	{
	        tam = theValue;
	}
	

	uint getTam() const
	{
	        return tam;
	}
	
	
	
	
	
	
	

};

}

#endif
