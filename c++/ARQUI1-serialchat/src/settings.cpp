#include "settings.h"

Settings::Settings()
{
	paridad = 0;
	puerto = 1;
	velocidad = 57600;
	flowcontrol = 0;
}

Settings::Settings(int port,int baud,int par,int fc){
	setPuerto(port);
	setVelocidad(baud);
	setParidad(par);
	setFlowcontrol(fc);
}
Settings::~Settings()
{
}








