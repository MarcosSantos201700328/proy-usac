/**
@file database.h
@brief Objeto de base de datos
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
#ifndef DATABASE_H
#define DATABASE_H

#include <cstring>

#include <qmap.h>
#include <qvaluelist.h>
#include <qstring.h>
#include "indicewrapper.h"	
#include "ericleresultsetwidget.h"
	
#include "tipos.h"
#include "dataoperations.h"
#include "metadata.h"



#include "bloque_db.h"
#include "indice.h"
#include "tablespace.h"
//#include "tupla.h"
#include "result.h"
#include "searchtree.h"

#include "registro.h"
	
#include "r_usuario.h"

/**
 * Clase principal que contiene el motor de la base de datos
	@author Erik Giron <erik_giron@yahoo.com>
*/
typedef QMap<unsigned int, IndiceWrapper> IndexMap;
typedef QMap<QString, r_usuario> UserMap;
class database{
    
public:
    database();
    
    database(metadata*);

    ~database();
    bool inicializar();///< Inicializa la base de datos con datos leidos
    void finalizar();///< finaliza y almacena datos en medio
    bool apagar();///<Cierra correctamente la base de datos
    bool defragmentar();///<defragmenta la base de datos
    
    //bool guardarConfigDb();///<Almacena configuracion de la base de datos
    
    //int guardarIndices();///<Escribe archivo de metadata
    //int guardarTablespace();///<Escribe archivo de metadata
    /*
    int insertar(tupla * data,int tabla);///<Inserta tupla
    int actualizar(tupla * data,int tabla);///<actualiza tupla
    result* buscar(SearchTree * st, int tablas[], int numtablase);///<Busqueda
        */    
    int parse(char* filename);///<Parsea archivo de entrada..
    int insertarRegistro(registro* r);///<Agrega un nuevo registro
    int eliminar(int indice, int tabla);///<Elimina dato identificado con indice de la tabla dada
    int buscarLibro(indice ); ///<busca un libro dado el indice con el indice dado y lo escribe a la salida
    int buscarLibroIsbn(int);///<busca un libro especifico y lo muestra al widget
    
    void mostrarLibros();///<Enlista todas los libros en el widget
    void setResultWidget(QWidget* w); ///<Linkea el widget a utilizar
    void setConfigFilename(QString filename); ///<Asigna nombre de archivo de config
    void setConfigFilename(char* filename); ///<Asigna nombre de archivo de config
    QString& getConfigFilename();///<Obtiene nombre de archivo de config
    metadata* getConfig(); ///devuelve registro de configuracion
    void setConfig(metadata* data); ///Actualiza registro de configuracion
    bool leerConfig();///<lee archivo de configuracion
    bool guardarConfig();///<guarda archivo de configuracion
    
    
private:
    IndexMap idxDirAutor;
    IndexMap idxDirTitulo;
    IndexMap idxDirContenido;
    IndexMap idxDirPrestamo;
    IndexMap idxDirTipoUsuario;
    IndexMap idxDirUsuario;
    IndexMap idxDirLibro;
    IndexMap idxDirImagene;
    UserMap indiceUsuarios;
    QValueList<indice>* listaLibrosPorAutor;
    QValueList<indice>* listaLibrosPorTitulo;
    QString ConfigFilename;///<path hacia archivo de configuracion
    
    metadata* config;///<configuracion actual
    tablespace* config_tb;
    
    EricleResultWidget* erw;
    
    void setDefaults();
    /*
    void setResultWidget(EricleResultWidget* rw){
	erw = rw;
    }*/
    int cargarIndices();///<Lee archivo de indices a tabla hash en memoria
    int cargarUsuarios();///<Lee registros de usuarios a tabla hash en memoria
    int leerMetadata();/**Lee metadata del archivo biblio.conf*/
    //void leerIndices();
    int leerTablespace();
    
    int guardarMetadata();///<Escribe archivo de metadata
    int guardarIndices();
    int guardarTablespace();
    
    int fusionar();///<Integra archivo datafile.db desde 0 hasta infinito...
    
    int separar();///<Separa archivo datafile.db
    
    void ertmp();
    
    
};

#endif
