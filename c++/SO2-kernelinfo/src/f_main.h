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
#ifndef F_MAIN_H
#define F_MAIN_H

#include "mainWindow.h"

class f_main: public frm_main {
Q_OBJECT
    private:
     void   fillProcessTab();///< Rellena tabla de procesos
     void updateProcessTab();
     void clearProcessTab();///< limpia tabla de procesos
     void fillModuleTab();///<Rellena lista de modulos
     void updateModuleTab();///<actualiza tabla de modulos
     void clearModuleTab();///<limpia tabla de modulos
     void fillDeviceTxt();///<llena el text de dispositivos
     void fillMemoryTxt();///<llena el text de dispositivos          
     
     
     
public:
    f_main(QWidget *parent = 0, const char *name = 0);
    
    public slots:
        virtual void kill();///mata el proceso seleccionado en la tabla
        virtual void cargarModulo();///<carga el modulo dado al kernel
        virtual void descargarModulo(); ///<descarga el modulo seleccionado del kernel
        virtual void exportdev();///<exporta el listado de dispositivos a un txt
        virtual void fileExit();///<salida
        virtual void helpAbout();///<mensaje de acerca de...
        virtual void helpContents();///<abre la ayuda
};

#endif
