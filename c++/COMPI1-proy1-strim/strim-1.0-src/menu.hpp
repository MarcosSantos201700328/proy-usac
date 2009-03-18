#ifndef MENU_H
#define MENU_H
#define STRDELIM '\"' // Delimitardor para cadenas de caracteres a leer
#include <iostream>
#include <fstream>
extern "C" {
  #include "stdlib.h"
  //  #include "includes.h"
  
};

using namespace std;

class Menu{
 private:
  char entrada[255]; //path y filename
  char salida[255];  //solo path
  int opcion;
  //  bool ejecutar;
 public:
  Menu(){
    entrada[0] = 0; salida[0] = 0; opcion = 0;
    //ejecutar = 
  };
  //int setEntrada();
  //int setSalida();
  int getOpcion();
  char * getEntrada();
  char * getSalida();
  int setPathEntrada();
  int setPathSalida();
  int mostrar();
  int ejecutar();
};
#endif
