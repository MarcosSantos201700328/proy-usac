/**
@file tablespace.h
@brief Definicion del struct tablespace.
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
#ifndef TABLESPACE_H
#define TABLESPACE_H
#ifdef __cplusplus
extern "C"{
#endif
/**
Definicion de la estructura tablespace a almacenar en base de datos, contiene las direcciones logicas de inicio de cada tabla dentro del archivo data.db.

	@author Erik Giron <erik_giron@yahoo.com>
*/
typedef struct tablespace{
/*public:
    tablespace();

    ~tablespace();
    private:*/
	unsigned long tam_tb_autor;
	unsigned long tam_tb_contenido;
	unsigned long tam_tb_libro;	
	unsigned long tam_tb_prestamo;
	unsigned long tam_tb_tipousuario;
	unsigned long tam_tb_titulo;
	unsigned long tam_tb_usuario;
} tablespace;
#ifdef __cplusplus
}
#endif
#endif
