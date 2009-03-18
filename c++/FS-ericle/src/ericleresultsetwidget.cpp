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
#include "ericleresultsetwidget.h"
#include <qstring.h>
#include <qtable.h>
#include <qpixmap.h>
EricleResultWidget::EricleResultWidget(QWidget *parent, const char *name)
    :ResultSetWidget(parent, name)
{
    initTableResultHeaders();
    /*tableResults->insertRows(tableResults->numRows());
    tableResults->setText ( tableResults->numRows()-1, 0, "0" );
    tableResults->setText ( tableResults->numRows()-1, 1, "1" );
    tableResults->setText ( tableResults->numRows()-1, 2, "2" );
    tableResults->setText ( tableResults->numRows()-1, 3, "3" );*/
//    tableResults->setPixmap ( tableResults->numRows(), 4, "f");    
}

void EricleResultWidget::initTableResultHeaders(){
    tableResults->horizontalHeader()->setLabel(0,tr("ID"));
    tableResults->horizontalHeader()->setLabel(1,tr("Autor"));
    tableResults->horizontalHeader()->setLabel(2,tr("Titulo"));
    tableResults->horizontalHeader()->setLabel(3,tr("Edicion"));
    tableResults->horizontalHeader()->setLabel(4,tr("Cantidad"));
    tableResults->horizontalHeader()->setLabel(5,tr("Portada"));
}
void EricleResultWidget::addLibro(QString id,QString autor, QString titulo,QString edicion,QString cantidad, QString path_portada){
    //tableResults->setNumRows(tableResults->numRows()+1);
    tableResults->insertRows(tableResults->numRows());
    tableResults->setText ( tableResults->numRows()-1, 0, id );
    tableResults->setText ( tableResults->numRows()-1, 1, tr(autor) );
    tableResults->setText ( tableResults->numRows()-1, 2, tr(titulo) );
    tableResults->setText ( tableResults->numRows()-1, 3, tr(edicion) );
    tableResults->setText ( tableResults->numRows()-1, 4, tr(cantidad) );
    tableResults->setPixmap ( tableResults->numRows()-1, 5, QPixmap(tr(path_portada)));    
}

void EricleResultWidget::clearTable(){
    for (int i = 0; i< (tableResults->numRows()); i++){
	tableResults->removeRow(i);
    }
}