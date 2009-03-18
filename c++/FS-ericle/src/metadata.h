/**
@file metadata.h
@brief clase de almacenamiento de metadata
@author Erik Giron (C#200313492)
@todo accesores

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
#ifndef METADATA_H
#define METADATA_H
#ifdef __cplusplus
extern "C"{
#endif
/**
Clase de almacenamiento de Metadata, el cual contiene información inicial acerca de los inicio, y cantidad de bloques usados por cada registro en el archivo biblioteca.db

	@author Erik Giron <erik_giron@yahoo.com>
*/

typedef struct metadata{
    int estaGuardado;
    unsigned long inicio_bloque_indice_dir;
    unsigned long inicio_bloque_indice_indir;
    unsigned long inicio_bloque_tablespace;
    unsigned long num_bloques_indice_dir;
    unsigned long num_bloques_indice_indir;
    unsigned long num_bloques_tablespace;
    unsigned int tam_crecimiento;///< Tamano de superbloques
    char path_logfile[255];
    char path_history[255];
    char path_datafile[255];
    char path_tmpdir[255];
    unsigned int num_macrobloques;///<numero actual de macrobloques
} metadata;
#ifdef __cplusplus
}
#endif
#endif
