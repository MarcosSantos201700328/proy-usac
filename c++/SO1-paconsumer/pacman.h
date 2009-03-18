/****************************************************************************
** Form interface generated from reading ui file 'pacman.ui'
**
** Created: Sun Nov 11 12:04:38 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PACMAN_H
#define PACMAN_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <qsemaphore.h>
#include <qptrqueue.h>
#include <qthread.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;

class Pacman : public QWidget
{
    Q_OBJECT

public:
    Pacman( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Pacman();

    QLabel* txtPac;

protected:
    Pacman* sigp;
    QPtrQueue<Pacman>* buffer;
    QSemaphore* mutex;
    QSemaphore* llenos;
    QSemaphore* vacios;


protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // PACMAN_H
