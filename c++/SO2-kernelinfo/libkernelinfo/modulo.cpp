/***************************************************************************
 *   Copyright (C) 2008 by Erik Giron, Marlon Manzo, Juan Carlos Lopez, Pedro Domingo   *
 *   erik_giron@yahoo.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "modulo.h"
#include <qprocess.h>
#include <qfile.h>
#include <qptrlist.h>
#include <qstring.h>
#include <qdir.h>
#include <qregexp.h>

namespace libkernelinfo
{

modulo::modulo()
{
}


modulo::~modulo()
{
}


int libkernelinfo::modulo::cargarAlKernel(void )
{
    QString spid = "modprobe -v " + this->getNombre();                
    return system(spid.latin1());
}

int libkernelinfo::modulo::descargarDelKernel(void )
{
    QString spid = "modprobe -v -r " + this->getNombre();                
    return system(spid.latin1());
}

QPtrList< modulo > * libkernelinfo::modulo::obtenerLista()
{
    //Obtenemos nombres de todos los modulos disponibles en /proc/modules
    QPtrList<modulo>* listado = new QPtrList<modulo>();
    modulo *actual = NULL;
    QStringList lines;
    QFile file("/proc/modules" );
    if ( file.open( IO_ReadOnly ) ) {
        QTextStream stream( &file );
        QString line;
        QRegExp separator("\\s+");
        int i = 1;
        while ( !stream.atEnd() ) {
            line = stream.readLine(); // line of text excluding '\n'
            actual = new modulo();
            //Obtenemos campo nombres
            actual->setNombre(line.section(separator,0,0));
            actual->setTam(line.section(separator,1,1).toInt());
            actual->setDependencia(line.section(separator,3,3));                       
            listado->append(actual);
            //lines += line;
        }
        file.close();
    }
    return listado;
    //
}


}

/**Main*/
using namespace libkernelinfo;
// int main(int argc,char* argv[]){
//     modulo *m = new modulo();
//     QPtrList<modulo> *modulos;
//     modulos = m->obtenerLista();
//     QPtrListIterator<modulo> it(*modulos);
//     delete m;
//     while((m = it.current())!=0){
//         printf("Modulo (%s,%d,%s)\n",m->getNombre().ascii(), m->getTam(), m->getDependencia().ascii());
//         ++it;
//     }
//     
//     delete m;
//     m = new modulo();
//     m->setNombre("a");
//     m->agregarAlInicio();
//     
//             
//     
// }

int libkernelinfo::modulo::agregarAlInicio( )
{
    QFile file("/etc/rc.init" );
    //QFile file("/home/kreig/rc.init" );
    if (file.exists()){
        if ( file.open( IO_WriteOnly | IO_Append ) ) {
            QTextStream stream(&file);
            stream << "modprobe " + this->getNombre() + "\n";
        // escribimos a segunda linea
            file.close();
            return EXIT_SUCCESS;
        }
    }
    else{
        file.setName("/etc/rc.d/rc.init" );
        //QFile file("/home/kreig/rc.init" );
        if (file.exists()){
            if ( file.open( IO_WriteOnly | IO_Append ) ) {
                QTextStream stream(&file);
                stream << "modprobe " + this->getNombre();
        // escribimos a segunda linea
                file.close();
                return EXIT_SUCCESS;
            }
        }
    }
    return EXIT_FAILURE;
    
}

