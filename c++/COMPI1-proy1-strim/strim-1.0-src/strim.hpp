/* Strim: String Manipulator
   Autor: Erik Vladimir Giron Marquez (200313492)
   Para el 1er proyecto de Compiladores 1
   Febrero-Marzo 2006
 */


#ifndef STRIM_H
#define STRIM_H

#include "./menu.hpp"
#include <iostream>
#include <fstream>


//extern 

extern "C"{
int yyparse(void);
#include <stdio.h>
#include <string.h>
#include "./strim-parser.h"
#include "./funciones.h"
  extern FILE* yyin, *yyout;
}



using namespace std;
//****************************Reporte*************************
/*Reporte de salida*/
class Reporte{
 private:
  char mensaje[255]; // mensaje a escribir
  ofstream out;//Archivo de salida
  //FILE * o;
  static char pathSalida[255]; // path + filename
  static char archivoSalida[24]; // filename
 public:  
  Reporte(){
    pathSalida[0] = 0;
    strcpy(archivoSalida,"salida.txt");
  };

  Reporte(char * p){
    strcpy(pathSalida,p);
  };
  int setPathSalida(char *);
  int limpiar();
  void escribirEnPantalla(char *);
  void escribirEnArchivo(char *);
  void escribirNumLinea(int);
  void escribirError(char *,int);
  void escribir(char*,int); // escribe a pantalla y archivo con numero de linea
  void escribirReporte(char *); // escribe reporte sin verbosidad de numero de linea
};


class Strim{
 private:
  char pathEntrada[255]; //Path y filename
  char pathSalida[255];  //Solo path
  int entero; // entero leido
  float flotante; //float leido
  char caracter; //caracter leido
  char cadena[512]; //cadena leida
  Reporte salida; // reporte de Salida
  //Objetos a utilizar

 public:
  Strim();
  ~Strim();
  // Libra(){pathEntrada[0] = 0; pathSalida[0] = 0;};
  //Metodos de Parser
  int validar();
  int setArchEntrada(char *); // asigna archivo de Entrada
  int setArchSalida(char *); // asigna archivo de Salida
  int parse(); // Funcion raiz del parser
};
#endif
