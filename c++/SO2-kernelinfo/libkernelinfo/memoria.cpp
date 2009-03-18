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
#include "memoria.h"
#include <qfile.h>
#include <qstring.h>
#include <qptrlist.h>
#include <qregexp.h>
namespace libkernelinfo {

memoria::memoria()
{
}


memoria::~memoria()
{
}

memoria * memoria::obtenerEstado()
{
    memoria *m = new memoria();    
    // leemos linea por linea el archivo
    QStringList lines;
    QFile file("/proc/meminfo" );
    if ( file.open( IO_ReadOnly ) ) {
        QTextStream stream( &file );
        QString line;
        int i = 1;
        while ( !stream.atEnd() ) {
            line = stream.readLine(); // line of text excluding '\n'
            //Asignamos total
            if((line.contains(QRegExp("MemTotal",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setTotal(line.toInt());
            }
            if((line.contains(QRegExp("MemFree",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setFree(line.toInt());
            }
            if((line.contains(QRegExp("Buffers",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setBuffers(line.toInt());
            }
            if((line.contains(QRegExp("Cached",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setCached(line.toInt());
            }
            if((line.contains(QRegExp("SwapCached",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setSwapcached(line.toInt());
            }
            if((line.contains(QRegExp("Active",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setActive(line.toInt());
            }
            if((line.contains(QRegExp("Inactive",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setInactive(line.toInt());
            }
            if((line.contains(QRegExp("SwapTotal",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setSwaptotal(line.toInt());
            }
            if((line.contains(QRegExp("SwapFree",FALSE,FALSE))) >=1){
                line.replace(QRegExp("[^0-9]+",FALSE,FALSE),"");
                m->setSwapfree(line.toInt());
            }
        }
        file.close();
    }
    return m;
}

}



// using namespace libkernelinfo;
// int main(int argc, char* argv[]){
//     memoria* m = new memoria();
//     m = m->obtenerEstado();            
//     printf("Memoria(Total:%d, Activo: %d)",m->getTotal(),m->getActive());
//     
//     return EXIT_SUCCESS;
// }