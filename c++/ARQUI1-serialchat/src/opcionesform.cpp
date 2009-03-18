#include "opcionesform.h"

OpcionesForm::OpcionesForm(QWidget *parent, const char *name)
    :Opciones(parent, name)
{
}
/*
void OpcionesForm::reject()
{
	this->close();
}
*/
/**Almacena opciones en objeto settings*/
void OpcionesForm::guardarCambios()
{
	settings.setVelocidad( (baudSel->currentText()).toInt());
	settings.setPuerto(  (this->puertoSel->currentText()).toInt());
	settings.setFlowcontrol( (  (flowSel->currentItem())));
	settings.setParidad( ( (  (paritySel->currentItem()))));
	settings.setVelocidad( (baudSel->currentText()).toInt());
	close();
	
}
/**Retorna el objeto settings*/
Settings& OpcionesForm::getSettings(){
	return settings;
}
