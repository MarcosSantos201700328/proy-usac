/**
@file tupla.h
@brief Representa una tupla
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
#ifndef TUPLA_H
#define TUPLA_H

/**
Representa una lista de tupla o un registro cualquiera como un conjunto de datos en arreglo.

	@author Erik Giron <erik_giron@yahoo.com>
*/
class tupla{
public:
    tupla();

    ~tupla();
private:
    struct tupla *next;		/* list of rows */
    char** data;
    unsigned long length;
};

#endif
