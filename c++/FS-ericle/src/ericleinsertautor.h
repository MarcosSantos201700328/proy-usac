/**
@file archivo.h
@desc Enter description Here
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
#ifndef ERICLEINSERTAUTOR_H
#define ERICLEINSERTAUTOR_H

#include "insertAutor.h"

class ericleInsertAutor: public InsertAutor {
Q_OBJECT
public:
    ericleInsertAutor(QWidget *parent = 0, const char *name = 0);
    virtual registro* getRegistro();
public slots:
    virtual void accept();
    virtual void newSlot();
};

#endif
