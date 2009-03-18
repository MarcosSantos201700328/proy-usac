/****************************************************************************
** Form interface generated from reading ui file 'wdg_procesos.ui'
**
** Created: Wed Mar 26 22:06:06 2008
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRM_PROCESOS_H
#define FRM_PROCESOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QTable;
class QPushButton;

class frm_procesos : public QWidget
{
    Q_OBJECT

public:
    frm_procesos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frm_procesos();

    QGroupBox* groupBox1;
    QTable* table1;
    QPushButton* pushButton1;

protected:
    QVBoxLayout* frm_procesosLayout;
    QVBoxLayout* groupBox1Layout;

protected slots:
    virtual void languageChange();

};

#endif // FRM_PROCESOS_H
