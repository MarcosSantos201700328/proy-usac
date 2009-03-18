/****************************************************************************
** Form interface generated from reading ui file 'fantasma.ui'
**
** Created: Sun Nov 11 12:04:38 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FANTASMA_H
#define FANTASMA_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;

class Fantasma : public QWidget
{
    Q_OBJECT

public:
    Fantasma( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Fantasma();

    QLabel* lblFantasma;

protected:

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // FANTASMA_H
