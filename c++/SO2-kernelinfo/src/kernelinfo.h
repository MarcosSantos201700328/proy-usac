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


#ifndef KERNELINFO_H
#define KERNELINFO_H

#include <qmainwindow.h>

class QTextEdit;

class kernelinfo: public QMainWindow
{
    Q_OBJECT

public:
    kernelinfo();
    ~kernelinfo();

protected:
    void closeEvent( QCloseEvent* );

private slots:
    void newDoc();
    void choose();
    void load( const QString &fileName );
    void save();
    void saveAs();
    void print();

    void about();
    void aboutQt();

private:
    QPrinter *printer;
    QTextEdit *e;
    QString filename;
};


#endif
