/**
@file r_prestamo.h
@brief Clase de almacenamiento de prestamo en db
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
#ifndef R_PRESTAMO_H
#define R_PRESTAMO_H
typedef struct r_prestamo{
    	unsigned int libro;
	unsigned int usuario;
	char fecha_prestamo[40];
	char fecha_entrega[40];
} r_prestamo;
#endif
