/**
@file bloque_db.h
@brief Describe la clase bloque_db usada como unidad basica del archivo database.db
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
#ifndef BLOQUE_DB_H
#define BLOQUE_DB_H
#include "indice.h"
//#include "indice_directo.h"
//#include "indice_indirecto.h"
/**
Bloque (unidad atomica de almacenamiento fisico) a almacenar en archivo principal de indices de base de datos.

	@author Erik Giron <erik_giron@yahoo.com>
*/

typedef struct bloque_db{
/*public:
    bloque_db();

    ~bloque_db();
    protected:*/
    
    union {
	indice indice_indirecto;
	indice indice_directo;
//	tablespace ts;
    }data;///<dato	
    char tipo; ///<tipo de dato 0: idx_indir, 1 idx_dir, 2 tablespace
    bool borrado; ///< 0 : si no esta borrado, 1 : si esta borrado
    
}bloque_db;

#endif
