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
#include "proceso.h"
#include <qprocess.h>
#include <qfile.h>
#include <qstring.h>
#include <qptrlist.h>
#include <qregexp.h>
#include <cstdlib>
namespace libkernelinfo{
proceso::proceso()
{

}

proceso::proceso(int ppid)
{

    this->pid = ppid;
}

proceso::~proceso()
{
}

const QStringList proceso::obtenerListaDirectorios()
{
    QDir d("/proc");
    //filtramos solo por directorios
//    d.setFilter(QDir::Dirs);
    // obtenemos todos los directorios de los procesos
    d.setNameFilter("[0-9]*");
    //ordenamos por nombre
    d.setSorting(QDir::Name);
    // obtenemos lista
    const QStringList fileinfo = d.entryList();    
    return fileinfo;
    
}

QPtrList< proceso > * proceso::obtenerLista()
{
    const QStringList listado = obtenerListaDirectorios();
    
    QPtrList<proceso> *nuevo = new QPtrList<proceso>();
    proceso *pactual;
    for ( QValueListConstIterator<QString> it = listado.begin(); it != listado.end(); ++it ) {
        pactual = obtenerProcesoFromFile(*it);
        nuevo->append(pactual);
    }

     return nuevo;

    
}


proceso * proceso::obtenerProcesoFromFile(QString filename)
{
    proceso *p = new proceso(filename.toInt());    
    // leemos linea por linea el archivo
    QStringList lines;
    QFile file("/proc/" + filename + "/status" );
    if ( file.open( IO_ReadOnly ) ) {
        QTextStream stream( &file );
        QString line;
        int i = 1;
        while ( !stream.atEnd() ) {
            line = stream.readLine(); // line of text excluding '\n'
            //Asignamos nombre
            if((line.contains(QRegExp("Name",FALSE,FALSE))) >=1){
                line.replace(QRegExp("Name:",FALSE,FALSE),"");
                line.replace(QRegExp("[\t\n\r ]+",FALSE,FALSE),"");
                p->setNombre(line);
            }
            //Asignamos status
            else if((line.contains(QRegExp("State",FALSE,FALSE))) >=1){
                line.replace(QRegExp("State:",FALSE,FALSE),"");
                line.replace(QRegExp("[\t\n\r ]+",FALSE,FALSE),"");                
                p->setStatus(line);
            }
            //Asignamos memoria
            else if((line.contains(QRegExp("VmHWM",FALSE,FALSE))) >=1){
                line.replace(QRegExp("VmHWM:",FALSE,FALSE),"");
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                p->setMemoria(line.toInt());
                        
            }
            //Asignamos cpu
            else if((line.contains(QRegExp("SleepAVG",FALSE,FALSE))) >=1){
                line.replace(QRegExp("SleepAVG:",FALSE,FALSE),"");
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                p->setProcesador(line.toInt());
            }
                
            //lines += line;
        }
        file.close();
    }
    
    
    return p;
}




int proceso::matar(int ppid)
{
    QString spid = "kill -KILL " + QString::number(ppid);    
            
    return system(spid.latin1());
    
    
}

}// end namespace


/**Main*/
// using namespace libkernelinfo;
// int main(int argc, char* argv[]){
//     proceso *p=new proceso();
//     QPtrList<proceso>* listaProcesos = p->obtenerLista();
//     QPtrListIterator<proceso> it(*listaProcesos);
//     
//     while((p = it.current()) != 0){
//         printf("Proceso( %d, %s, %s, %d, %d)\n", 
//                p->getPid(),
//                          (const char*) p->getNombre(),
//                           (const char*)p->getStatus(),
//                            p->getMemoria(),
//                                          p->getProcesador()
//               );
//         ++it;
//     }
//     delete listaProcesos;    
//     p->matar(9969);
//     return 0;
// }
