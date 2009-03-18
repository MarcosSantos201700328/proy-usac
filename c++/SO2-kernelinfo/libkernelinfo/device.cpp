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
#include "device.h"
#include <cstdlib>

namespace libkernelinfo {

device::device()
{
}


device::~device()
{
}




QString * libkernelinfo::device::obtenerLista()
{
    QString *ret = new QString(" ");
    bool leido = false;
            
    //abrimos pipe del comando
    FILE* input = popen("lshw -html -C memory -C processor -C bridge -C display -C network -C multimedia -C input -C communication -C bridge -C storage -C bus", "r");
    
    
    //obtenemos salida del comando
    if(!input){
        printf("Error: imposible leer hardware");
        
    }
    else        
    {
        char actual;
        while(!feof(input)){
            fread(&actual,sizeof(char),1,input);
            if(actual == '<'){
                leido = true;
            } 
            if(leido){
                ret->append(actual);
            }
                
        }
        pclose(input);

        return ret;
        
    }
       
    return NULL;
}
}

// using namespace libkernelinfo;
// int main(int argc, char argv){
//   device * dev = new device();
//   QString html;
//   html = *(dev->obtenerLista());
//   printf(html.ascii());
//   dev->exportar(new QString("/tmp/devinfo.txt"));
//   return EXIT_SUCCESS;
// }

int libkernelinfo::device::exportar(QString * path)
{
    QString spid = "./lshw -quiet > " + *path;                
//    delete path;
    return system(spid.latin1());
}
