/**
@file modifylibro.cpp
@brief Implementacion de modifylibro.cpp
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


#include "modifylibro.h"

modifyLibro::modifyLibro(QWidget* parent, const char* name, bool modal, WFlags fl)
: insertLibro(parent,name, modal,fl)
{
    this->setCaption(tr("Modificar Libro..."));
}

modifyLibro::~modifyLibro()
{
}

/*$SPECIALIZATION$*/
void modifyLibro::reject()
{
  QDialog::reject();
}

void modifyLibro::accept()
{
  QDialog::accept();
}



