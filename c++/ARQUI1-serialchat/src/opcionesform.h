#ifndef OPCIONESFORM_H
#define OPCIONESFORM_H

#include "portoptions.h"
#include "qcombobox.h"
class OpcionesForm: public Opciones {
Q_OBJECT
public:
    OpcionesForm(QWidget *parent = 0, const char *name = 0);
    Settings& getSettings();
public slots:
    //virtual void reject();
public slots:
    //virtual void accept();
    void guardarCambios();
};

#endif
