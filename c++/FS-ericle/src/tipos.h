/**
@file tipos.h
@brief Definicion de tipos y constantes
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
#ifndef TIPOS_H
#define TIPOS_H

#include <unistd.h>
	
#ifdef __cplusplus
extern "C"{
#endif
    
#define T_AUTOR 100
#define T_CONTENIDO 101
#define T_LIBRO 102
#define T_PRESTAMO 103
#define T_TIPOUSUARIO 104
#define T_TITULO 105
#define T_USUARIO 106
#define T_IMAGEN 107

#define T_RESULT 200
#define T_INDICE 201
#define T_METADATA 202
#define T_TABLESPACE 203
#define T_INDICE_DIR 204
#define T_INDICE_INDIR 205

//SUCCESSFUL MESSAGES
#define MSGS_INSERCION 1000
//ERROR MESSAGES
#define MSGE_NOTENOUGHROOM 2000
#define MSGE_DUPLICADO 2001

	//Archivos	
#define DIR_HOME "/home/" 
	
#define FILE_DIRIDX "/tmp/diridxdat"
#define FILE_INDIRIDX "/tmp/indiridxdat"
#define FILE_TBAUTOR "/tmp/tbautordat"
#define FILE_TBCONTENIDO "/tmp/tbcontenidodat"
#define FILE_TBLIBRO "/tmp/tblibrodat"
#define FILE_TBPRESTAMO "/tmp/tbprestamodat"
#define FILE_TBTIPOUSUARIO "/tmp/tbtipousuariodat"
#define FILE_TBTITULO "/tmp/tbtitulodat"
#define FILE_TBUSUARIO "/tmp/tbusuariodat"
#define FILE_TBIMAGEN "/tmp/tbimagendat"

#define FILE_CONFIG "biblio.conf" // para usarse en c++ con QT
#define FILE_HEADER "biblioteca.db" 
#define FILE_DATA "datafile.db"
	//Errores
#define ERR_NULLPTR (-1)
#define ERR_NODATATYPE (-100)
#define ERR_NOEXIST (-101)
#define ERR_NOFILE (-102)

#define OFFSET_METADATA 0
#define OFFSET_DIRIDX OFFSET_METADATA + sizeof(metadata)
#define OFFSET_INDIRIDX(m) OFFSET_DIRIDX + (sizeof(indice)*((m)->num_bloques_indice_dir))
#define OFFSET_TABLESPACE(m) OFFSET_INDIRIDX(m) + (sizeof(indice)*((m)->num_bloques_indice_indir))

#define OFFSET_TBAUTOR 0
#define OFFSET_TBCONTENIDO(r) OFFSET_TBAUTOR + (sizeof(registro)*((r)->tam_tb_autor))
#define OFFSET_TBLIBRO(r) OFFSET_TBCONTENIDO(r) + (sizeof(registro)*((r)->tam_tb_contenido))
#define OFFSET_TBPRESTAMO(r) OFFSET_TBLIBRO(r) + (sizeof(registro)*((r)->tam_tb_libro))
#define OFFSET_TBTIPOUSUARIO(r)  OFFSET_TBPRESTAMO(r) + (sizeof(registro)*((r)->tam_tb_prestamo))
#define OFFSET_TBTITULO(r) OFFSET_TBTIPOUSUARIO(r) + (sizeof(registro)*((r)->tam_tb_tipousuario)) 
#define OFFSET_TBUSUARIO(r) OFFSET_TBTITULO(r) + (sizeof(registro)*((r)->tam_tb_titulo))
#define OFFSET_TBEND(r) OFFSET_TBUSUARIO(r) + (sizeof(registro)*((r)->tam_tb_usuario))
#ifdef __cplusplus
}
#endif
#endif
