#ifndef SETTINGS_H
#define SETTINGS_H

/**
	@author Erik Giron (200313492) <erik_giron@yahoo.com>
*/
class Settings{
private:
	int puerto;
	int velocidad;
	int paridad;
	int flowcontrol;

public:
	/**Constructor por Defecto*/
    	Settings();
	/**Constructor de Oficio*/
	Settings(int,int,int,int);
	
	~Settings();
	/**Asigna velocidad*/
	void setVelocidad(const int& theValue)
	{
	  velocidad = theValue;
	}
	
	/**Obtiene velocidad*/
	int getVelocidad() const
	{
	  return velocidad;
	}
	/**Asigna paridad*/
	void setParidad(const int& theValue)
	{
	  paridad = theValue;
	}
	

	int getParidad() const
	{
	  return paridad;
	}
	/**Asigna puerto*/
	void setPuerto(const int& theValue)
	{
	  puerto = theValue;
	}
	

	int getPuerto() const
	{
	  return puerto;
	}
	/**Asigna flujo de control*/
	void setFlowcontrol(const int& theValue)
	{
	  flowcontrol = theValue;
	}
	

	int getFlowcontrol() const
	{
	  return flowcontrol;
	}
	
	
	
	

};

#endif
