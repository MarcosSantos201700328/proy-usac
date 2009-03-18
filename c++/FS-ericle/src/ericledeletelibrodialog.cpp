/**
@file archivo.cpp
@brief Implementacion de [archivo].h
@author Erik Giron (C#200313492)

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
#include "ericledeletelibrodialog.h"
#include "qlineedit.h"
	
EricleDeleteLibroDialog::EricleDeleteLibroDialog(QWidget *parent, const char *name)
    :deleteLibro(parent, name)
{
}

void EricleDeleteLibroDialog::accept()
{
    
    if(fieldId->text().length() > 0){
        id = fieldId->text().toInt(NULL);    
        if (id >= 0){            
	    this->close();
	}
    }
}

