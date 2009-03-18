/**
@file logger.h
@brief definicion de las funciones de bitacora
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
#ifndef LOGGER_H
#define LOGGER_H
#ifdef __cplusplus
extern "C"{
#endif
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "registro.h"
		 
    void iniciarLogFile(const char* path);///Inicializa y abre archivo de log en el path dado
    void mensajeLog(const char*);///<escribe mensaje estandar
    void finalizarLogFile();   ///<Cierra el archivo		 
    void agregarMsgLog(int ,int , struct registro*);///<Escribe un mensaje predeterminado
    void agregarErrorLog(int  ,struct registro*);///<Escribe un mensaje de error predeterminado
#ifdef __cplusplus
};
#endif
#endif
