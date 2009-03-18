#ifndef __FIRST_H
#define __FIRST_H

// TODO:
// - seguir armando el esqueleto;
// [HECHO]- crear codigo para menu;
// [HECHO]- implantar codigo parse;
// [HECHO]- Codigo Inicializar
// [HECHO]- codigo para instruccion CreaConfed
// [HECHO]- Crear seleccion
// [HECHO]- Crear Torneos (probar modificar torneosXo)
// [HECHO]- Crear Juegos
//   [HECHO] - Implementar Funcion de Calculo puntos acumulados para Juegos
// [*HECHO]- Mostrar Puntos
//   [HECHO] - Parserar y Validar Fechas
//   [HECHO] - Implementar Puntos Ac y Index Puntos AC
//   [HECHO] - Hacer funcion de Calculo PuntosAc
//   [HECHO] - hacer algoritm de Guardar y Actualizar PuntosAc
//   [*HACER FUNCIONAR*] - Hacer Indice e  implementar QuickSort[fix]
//   [HECHO] - Volcar Indices Ordenados a disco para uso posterior
//   [HECHO*] - Imprimir datos ordenados basados en indice
//    
//   [HECHO] Arreglar la salida de meses
// -[HECHO] Mejor Equipo
// -[HECHO] Mejor Desempeno
// -[HECHO*] Clasificacion
//  --[HECHO] Arreglar orden de muestreo en GenerarReporteClasif
// -** Borrar archivos temporales de calculo despues de usarlos
// -[HECHO]** Cambiar path de entrada y salida a ser elegidos por el usuario
// [HECHO] - Arreglar para volver a procesar con opcion 3 en menu
// [HECHO] - Bug extrano para salida
// [BUG] - Cuando se intenta procesar datos por segunda vez
// [FIX] - Arreglar salida de datos en pantalla
// [HECHO] - Arreglar salida para mes();
// 
// - definiciones para cuando se compile en borland C
extern "C"{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

};


#ifdef bc
#include <iostream.h>
#include <fstream.h>
#include "d:\progra\ipc2\proy1\src\scanner.cpp"
#define bool unsigned short int
#define true 1
#define false 0
#define strcasecmp(x,y) strcmpi(x,y)
#define round(x) ceil(x)

#else
#include <iostream>
#include <fstream>
#include "scanner.cpp" // Scanner

using namespace std;
#endif

#define debug



typedef struct confederacion{ // Registro de Confederacion
  char id[11];
  char nombre[255];
  float factor;
};

typedef struct torneo{ // Registro de Torneo
  char id[11];
  char nombre[255];
  bool esoficial;
  unsigned int bonif_vis;
  float factor;
};

typedef struct seleccion{ // Estructura para seleccion
  char id[6];
  char nombre[255];
  char id_conf[11];
};

typedef struct juego{ // Estructura para juego
  char local[11];
  char id_eqA[11];
  char id_eqB[11];
  char id_torneo[11];
  unsigned int golA;
  unsigned int golB;
  unsigned int penA;
  unsigned int penB;
  unsigned int duracion;
  unsigned int d, m, a;
  int punteoA; // Puntos actuales al juego de equipo A
  int punteoB; // Puntos actuales al juego de equipo B
  int puntosacA; // puntos acumulados a la fecha por equipo A
  int puntosacB; // puntos acumulados a la fecha por equipo B
};

typedef struct idx{ // Indice general
  char id[11];
  int pos;
};
typedef struct idxclasif{ // Indice clasificacion
  //  char id[11];
  int puntos;
  int pos;
  
};

typedef struct indexJ{ // Indice de Juego
  char pos;
  char local[11];
  char id_eqA[11];
  char id_eqB[11];
  char id_torneo[11];
};

typedef struct intervfecha{ // Estructura de fechas
  unsigned int m0,a0,m1,a1;
};

typedef struct puntosac{ // Puntos acumulados
  char id[11];
  char id_conf[11];
  float punto1;
  float punto2;
};

typedef struct idxpuntosac{ // Indice de puntos acumulados
  unsigned int indice;
  float diffpuntos;
};

typedef struct eq_year{ // Para equipo del year
  char id[11]; // Seleccion
  char nombre[255];
  int punteo;
  unsigned int aa; // year
};

typedef struct desemp{
  char id[11];
  char nombre[255];
  long puntos;
  unsigned int aa;
};

typedef struct clasif{
  char id[11];
  char nombre[255];
  int puntos, diffpuntos;
  unsigned int aa, mm;
};

char entrada[255]; // path de entrada
char salida[255]; // path de salida


const char ArchConfed[20] = "c:\\confed.bin";
const char ArchIdxConfed[20] = "c:\\idx_cnfd.bin";
const char ArchSelec[20] = "c:\\selec.bin";
const char ArchIdxSelec[20] = "c:\\idx_sel.bin";
const char ArchTorneo[20] = "c:\\torneo.bin";
const char ArchJuegos[20] = "c:\\juegos.bin";
const char ArchPuntosac[20] = "c:\\puntosac.bin";
const char ArchIdxPuntosac[20] = "c:\\ipunac.bin";
const char ArchEqYear[20] = "c:\\eqyear.bin";
const char ArchDesemp[20] = "c:\\desemp.bin";
const char ArchClasif[20] = "c:\\clasif.bin";
//strcpy(ArchConfed,"confed.bin");
//strcpy(ArchIdxConfed,"idx_cnfd.bin");


int pos_confed = 0; //contador para posicion de indice

/***************PROTOTIPOS**********************/
extern void setInput(char *);
extern void setOutput(char *);
extern void msgerr(char*,int);
extern int ActualizaConfed(confederacion);
extern int ActualizaTorneo(torneo);
extern int ActualizaSeleccion(seleccion);
extern int GeneraReporteClasif(idxclasif *,int);
extern int GuardarClasif(clasif);
extern int AcumularPuntosMes(clasif &,idxclasif &);
extern void InicializarIndice(idxclasif *,int);
extern int Clasificacion(clasif &c);
extern int buscaDesemp(desemp&);
extern int calcularPuntosGanados(desemp &);
extern int prem_desemp(desemp &d);
extern int premioME(eq_year &);
extern int guardarEqA(eq_year &);
extern int leerPunteoPME(eq_year &);
extern int eqA(eq_year &);
extern int ValidarJuego(juego);
extern int ValidaFecha(intervfecha);
extern int sizeoffile(FILE *);
extern char * mes(int);
extern int printPuntosAc(intervfecha);
extern int CrearIndicePuntos(void);
extern int GuardarPuntos(char*, float);
extern int PuntosAC(intervfecha);
extern int PClasif(char*,unsigned int,int &);
extern float FNR(char* idsel);
extern int CalculaPuntosJuego(juego &);
extern int CreaJuego(juego &);
extern int menu(void);
extern void inicializar(void);
extern int cmd_creaconfed(confederacion &);
extern int cmd_creaselec(seleccion &);
extern int cmd_creatorneo(torneo &);
extern int cmd_juego(juego &);
extern int cmd_puntosac(intervfecha &);
extern int cmd_premio_me(eq_year &);
extern int cmd_mejor_desemp(desemp &);
extern int cmd_clasif(clasif &);
extern int parse(char *);
extern void QuickSort(idxpuntosac *, int, int);
extern void QuickSort(int *,int,int);
extern void QuickSort(idxclasif *, int, int);
extern char * mes(int);


#endif
