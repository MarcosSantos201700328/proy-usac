#include "menu.hpp"

/************************* Menu *************************/
int Menu::mostrar(){
  int eleccion = 0;
  cout //<< endl << endl 
  << "Bienvenido a Stream ver. 1.16" << endl;
  cout << "Proyecto 1: Org. de Compiladores 1 " << endl
       << "(c) 2006 Erik Vladimir Giron Marquez \
           \nCarnet # 200313492" << endl //<< endl << endl
       <<endl<<endl;
  cout << "\tMENU PRINCIPAL" << endl
       << "\t--------------" <<endl
       << "\tSeleccione lo que desea hacer" << endl
       << "\t\t1. Seleccionar archivo de entrada..." << endl
       << "\t\t2. Seleccionar directorio donde se desee\n\t\t   generar archivo de salida \"200313492.txt\"..." << endl
       << "\t\t3. Procesar datos y generar reporte..." << endl
       << "\t\t[cualquier otra tecla] SALIR..." << endl
    /*<<endl<<endl*/ <<endl<<endl <<"\t\tIngrese su opcion-> ";
  cin >> eleccion;
  //  eleccion = getchar();
  // codigo menu
  if ((eleccion > 0) && (eleccion < 4)){
    opcion = eleccion;
    return eleccion;
  }
  else
    return 0;
}

int Menu::ejecutar(){
  int comando = 0;
  while ( comando != 3 && comando!= -1
	 /*comando >= -1 && comando < 3*/){
    comando = mostrar();
    switch (comando){
    case 1:
      //codigo para cuando es opcion 1
      setPathEntrada();
      break;
    case 2:
      //codigo para cuando es opcion 2
      setPathSalida();
      break;
    case 3:
      break;
    default:
      opcion = -1;
      comando = -1;
      cout<<"Ingrese opcion correcta"<< endl;
      break;
    }
  }
  if (comando == 3)
    return 0;
  else
    return -1;
}

int Menu::setPathEntrada(){
  char path[255];
  cout << endl << endl
	   << "Escriba ruta hacia archivo de entrada" << endl;
  cin >> path;
  strcpy(entrada,path);
  return 0;

}

int Menu::setPathSalida(){
  char path[255];
  cout << endl << endl
	   << "Escriba el directorio donde desee guardar archivo de salida" << endl;
  cin >> path;
	
  strcpy(salida,path);
  strcat(salida,"200313492.txt");
  return 0;
}

int Menu::getOpcion(){
  return opcion;
}

char * Menu::getEntrada(){
  return entrada;
}

char * Menu::getSalida(){
  return salida;
}
/*************************Fin Menu*************************/
