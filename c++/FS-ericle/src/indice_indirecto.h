/**
@file indice_indirecto.h
@brief Contiene la clase que describe el concepto de indice indirecto
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
#ifndef INDICE_INDIRECTO_H
#define INDICE_INDIRECTO_H

#include <indice.h>

/**
Clase para un indice indirecto en un archivo, el cual consiste en una lista enlazada de indices en disco, identificadas por el numero de bloque.

	@author Erik Giron <erik_giron@yahoo.com>
*/
class indice_indirecto : public indice
{
public:
    indice_indirecto();

    ~indice_indirecto();
    private:
	unsigned int siguiente;//numero de bloque que le sigue en la lista
	char esInicio;//1 true. 0 false
};

#endif
