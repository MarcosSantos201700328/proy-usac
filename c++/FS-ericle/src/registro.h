/**
@file registro.h
@brief clase de almacenamiento de un registro, el cual es un bloque de referencia para el archivo datafile.db
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
#ifndef REGISTRO_H
#define REGISTRO_H
#include "r_autor.h"
#include "r_contenido.h"
#include "r_libro.h"
#include "r_prestamo.h"
#include "r_tipousuario.h"
#include "r_titulo.h"
#include "r_usuario.h"

#include "linkedlist.h"
typedef struct registro{
    union{
	r_autor rAutor;
	r_contenido rContenido;	
	r_libro rLibro;
	r_prestamo rPrestamo;
	r_tipousuario rTipoUsuario;
	r_usuario rUsuario;
	r_titulo rTitulo;	
    } dato;
    int tipo;
    char borrado; ///< es 1 si el registro esta borrado, esto es para defragmentacion
} registro;

registro* crearRegistro(void* datos,int tabla);

#endif
