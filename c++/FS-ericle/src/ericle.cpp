/**
 * @file ericle.cpp
 * @brief Punto de entrada de la app.
 * @author Erik Giron (C#200313492)
 * @todo Crear Clases de Almacenamiento
 *  -[] Metadata
 *  -[] Bloque_db
 * *  -[] Indice_dir
 *  -[] Indice_inder
 *  -[] Autor
 *  -[] Titulo
 *  -[] Linea_Titulo
 *  -[] Tipo_Usuario
 *  -[] Usuario
 *  -[] Prestamo
 *  - DB_CONFIG
 *  - database  
 *  - Resultset
 *  - Bloque_reg 
 *  - Registro
 * @todo Configuracion
 *  - Cuadros de Dialogo de Configuracion
 *  - Persistencia en DB
 *  - Presistencia en archivo de usuario
 * @todo Crear rutinas de persistencia
 *  - Rutina de manejo de archivos de base de datos en la clase database
 *  - Hashing en Archivos
 *  - Arbol B
 * @todo Busquedas simples
 *  - Libros Por Titulo
 *  - Libros Por Autor * 
 * @todo Parser de sentencias SQL
 *  - Lexer
 *  - Parser
 *  - Clase Resultset
 *  - Rutinas de recuperacion
 * @todo Muestreo de datos en GUI
 *  - Widget para muestreo de Resultsets
 *  - Widget para muestreo de XML en reportes
 * @todo Defragmentacion
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


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <qapplication.h>
#include "ericlemainwindow.h"
int main(int argc, char *argv[])
{
    
    QApplication app(argc,argv);
    EricleMainWindow* er = new EricleMainWindow();
    er->show();
    app.connect( &app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()) );
    app.connect( &app, SIGNAL(lastWindowClosed()), er, SLOT(finalize()) );
    //app.connect( &app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()) );
//    app.connect( &app, SIGNAL(aboutToQuit()), &app, SLOT(quit()) );
//  printf("Hello, world!\n");
    return app.exec();
    //return EXIT_SUCCESS;
}
