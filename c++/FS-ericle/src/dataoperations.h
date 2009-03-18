/**
@file dataoperations.h
@brief Coleccion de funciones para manipulacion de datos en los archivos
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
#ifndef DATAOPERATIONS_H
#define DATAOPERATIONS_H
#ifdef __cplusplus
extern "C"{
#endif
#include "linkedlist.h"
#include "tipos.h"
#include "registro.h"
#include "indice.h"
#include "metadata.h"
#include "tablespace.h"


#include "r_autor.h"
#include "r_contenido.h"
#include "r_libro.h"
#include "r_prestamo.h"
#include "r_tipousuario.h"
#include "r_usuario.h"
#include "r_titulo.h"


void setMetadata(metadata* d);/**Asigna metadata a utilizar en la aplicacion*/
void setTablespace(tablespace* t);/**Asigna tablespace a utilizar en la aplicacion*/

int insertarTupla(linkedlist * datos,int tabla);/**Inserta datos en tabla
						 * dada*/
int insertarAutor(r_autor * dato);
int insertarLibro(r_libro* dato);
int insertarContenido(r_contenido* dato);
int insertarPrestamo(r_prestamo* dato);
int insertarTipoUsuario(r_tipousuario* dato);
int insertarTitulo(r_titulo* dato);
int insertarUsuario(r_usuario* dato);

registro* leerRegistro(int numregistro, int tipo);
#ifdef __cplusplus
}
#endif
#endif

