/**
@file indice.h
@brief Contiene clase base de indice para archivo
@author Erik Giron (C#200313492)
@todo ALL

Copyright (C) 2006 Erik Giron

http://www.itforcegt.org/200313492

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#ifndef INDICE_H
#define INDICE_H
#include "tipos.h"
/**
Clase base para manejar los indices.

	@author Erik Giron <erik_giron@yahoo.com>
*/
typedef struct indice{
//public:
//    indice();

//    ~indice();
//    private:
	/*union {
	    unsigned int autor;
	    unsigned int titulo;
	    unsigned int libro;
	    unsigned int imagen;
	    
	}*/
	//unsigned int tipoindice;///<Define si es indice directo o indirecto
	/*Para uso de indices indirectos y directos*/
        unsigned int id;///< id de la clave
	unsigned int tipoclave;///<tipo de la clave 	
	unsigned int num_registro;	///<numero de registro para indice directo
	/*Para uso de indices indirectos**/
	unsigned int bloque_indice_indir;///<numero de bloque de inicio de lista para indice directo
	unsigned int siguiente;///<puntero a anterior
	unsigned int anterior;///<puntero a siguiente
	
	int borrado; /// es 1 si el indice esta borrado(usado como bandera de defrag)

	char esInicio;///<Define si es cabeza de lista1 true. 0 false
} indice;

#endif
