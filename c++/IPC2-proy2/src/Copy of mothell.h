/* Proyecto Mothell
   Erik Vladimir Giron Marquez
   C#200313492
   28/sept/2005
 */

/* TODO List:
 -[HECHO] Crear esqueletos de las clases a utilizar
 -[HECHO] Crear e implementar Menu;
 -[] Implementacion de la Clase Parser con todos sus metodos
   * Parser de Enteros, cadenas, float, fecha...
->->*** [FIX] Componer lectura de Flotantes para evitar la coma
    [HECHO] Componer lectura de cadenas para concatenar espacios
   -[HECHO] Parser para CrearInstalacion
   -[HECHO] Parser para AgregarInstalacion
     -[HECHO] Crear funcion Miembro para extraer el tipo de instalacion correspondiente
   -[HECHO] Parser para Agregar Cliente
   -[HECHO] Parser para CrearPromocion
   -[HECHO] Parser para CrearTipoActividad
   -[HECHO] Parser para Hacer Reservacion;
   -[HECHO] Parser para extender reservacion
     -falta resolver ambiguedades del enunciado
   -[HECHO] Parser para Eliminar reservacion
   -[HECHO] Parser para asignar Consumo Ayb
   -[HECHO] parser para Cambiar Descuento
   -[HECHO] Parser para Consultar Descunto
   -[HECHO] Parser para Consultar Precio
   -[HECHO] Parser para Instalaciones Disponibles
   -[HECHO] Parser para Listar Clientes
   -[HECHO] parser para Listar Reservaciones
   -[HECHO] Parser para Calcular_Consumo_AB
 *[HECHO] Clase Datos:
   *[FIX]Componer destructor de clases derivadas...
 -[HECHO]Clase TipoInstalacion
   -[HECHO]Metodo virtual BuscarDato()
 -[HECHO]Clase Instalacion
 -[HECHO]Clase Cliente
 -[HECHO]Clase Promocion
   [HECHO] Validar para intervalos de fecha incorrectos
 -[HECHO] Clase crearTipoActividad
 -[] Clase Reservacion
    -[HECHO] Funcion aplicar descuento para cuando es fecha de promocion
    -[HECHO] falta resolver ambiguedades del enunciado
    - Funcion extender
 -[HECHO] Clase Consumo
 -[HECHO] Metodo en la clase Reservacion para Instalaciones Disponibles;
 -[HECHO] Componer el bug del destructor virtual

 ** Componer bug del parser para cuando sintaxis de la instruccion anterior es erronea
 ** Revisar bug de <delete> para punteros internos
 *** Modificar Dato::setNombreArchivo para que archivos binarios los almacene en C:/
 *** Componer el bug para que procese datos de nuevo al procesar por 1er vez
 */
#ifndef M0THELL_H
#define MOTHELL_H
#ifndef debug
#define debug
#undef debug
#endif
#define STRDELIM '\"' // Delimitardor para cadenas de caracteres a leer
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
/***************************Menu**************************/
/*Muestra menu de opciones*/
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
  void escribirNumLinea();
  void escribirError(char *);
  void escribir(char*); // escribe a pantalla y archivo con numero de linea
  void escribirReporte(char *); // escribe reporte sin verbosidad de numero de linea
};

//*************************Fecha************************
class Fecha {
 private:
  int dia;
  int mes;
  int anio;
  char fechaStr[20];
 public:
  Fecha();
  Fecha(int,int,int);
  void setDia(int );
  void setMes(int );
  void setAnio(int );
  int getDia();
  int getMes();
  int getAnio();
  void sumarAnio(); // suma 1 anio a la fecha actual
  void sumarMes(); // suma 1 mes a la fecha actual
  void sumarDia(); // suma 1 dia a la fecha actual
  bool esBisiesto(); //retorna verdadero si anio es bisiesto
  bool operator>(Fecha); // Compara Sobrecargados
  bool operator<(Fecha); // Compara fechas
  bool operator==(Fecha); // Compara fechas
  bool operator>=(Fecha);
  bool operator<=(Fecha);
  void operator+(int);  // Suma dias a la fecha
  void operator=(Fecha); // Operador de Asignacion
  char * toString(); //convierte fecha a cadena para ser escrite
};

//*************************clase Dato*************************
//Clase base que define 
//la estructura de los datos a guardar
class Dato{
 private:
  int id; // ID del objeto
  char nombre[256]; //Nombre del objeto
  //FILE * in, *out; 
  bool datoValido; //Validador que definira si se va a guardar o no el dato
 public:
  /*CONSTRUCTORES*/
  Dato();
  Dato(bool);
  /*DESTRUCTOR*/
  virtual ~Dato() = 0;
  /*FUNCIONES MIEMBRO*/
  //  virtual int leerDato() = 0;
  int setNombre(char *);
  char * getNombre();
  int setID(int i); // Establece ID del objeto
  int getID();
  int setNombreArchivo(char*); // Asigna nombre a archivo binario
  bool esValido(); // returna estado de validez
  void esValido(bool); // asigna estado de validez
  void setTipoInstalacion(int); // asinga tipo de Instalacion para clases que lo implementen
  int getTipoInstalacion();
  char * getNombreArchivo(); // Devuelve el nombre del Archivo binario
  void esObjetoInterno(bool);
 protected:
  FILE * in;
  bool objetoInterno; /*new*/
  fstream file;// Archivos binarios leer y escribir
  char nombreArchivo[17]; // Nombre de Archivo binario
  virtual int guardarDato() = 0; // Guarda o actualiza dato
  virtual long buscarDato() = 0; // Busca datos de su tipo en archivo binario y devuelve posicion
  int nuevoDato(void *, int); // Crea nuevo registro en archivo de salida
  int actualizarDato(void*,int,long); // Actualiza registro encontrado en archivo de salida
  int tipoInstalacion;//Busca tipo de instalacion para las clases que asocien este TDA

};

/**********************clase TipoInstalacion*************************/
//Define un tipo de instalacion
class TipoInstalacion : public Dato{
 private:
  TipoInstalacion * tmp;
 public:
  TipoInstalacion(); //constructor que inicializa puntero
  TipoInstalacion(bool); //constructor de oficio no inicializa puntero
  /**virtuales**/
  ~TipoInstalacion();
  int guardarDato();
  long buscarDato();
  int leerDato();
};

class Instalacion : public Dato{
 private:
  Instalacion * tmp;
  int capacidad;
  float precio;
  long ubicacion;
  
 public:
  Instalacion();
  Instalacion(bool);
  /**virtuales**/
  ~Instalacion();
  int guardarDato();
  long buscarDato();
  int leerDato(int);
  /**metodos**/
  void setCapacidad(int);
  int getCapacidad();
  void setPrecio(float);
  float getPrecio();
  void setUbicacion(int);
  long getUbicacion();
  int getNivel();
  char * getStrNivel();
  int consultarPrecio();
  //  int reservar(Reservacion);
  //  Reservacion getReservacion();
 
};

class Cliente : public Dato{
 private:
  char nit[16];
  Cliente * tmp;
  char direccion[255];
  char telefono[20];
  char fechaNac[255];
  bool habitual;
  static int descuento;
  float saldo; // saldo que lleva el cliente
 public:
  Cliente();
  Cliente(bool);
  /**virtuales**/
  ~Cliente();
  int guardarDato();
  long buscarDato();
  int leerDato(char *);
  /**metodos**/
  void setNit(char *);
  char* getNit();
  void setDireccion(char *);
  void setTel(char *);
  void setFechaN(char*);
  void esHabitual(bool);
  void setHabitual(char *);
  char* getDireccion();
  char* getTel();
  char* getFechaN();
  bool esHabitual();
  int setDescuento(int);
  int getDescuento();
  int listarClientes(Reporte& );
};

class Promo : public Dato{
 private:
  Fecha fechaInicio;
  Fecha fechaFin;
  int descuento;
  Promo * tmp;
 public:
  Promo();
  Promo(bool);
  /**virtuales**/
  ~Promo();
  int guardarDato();
  long buscarDato();
  int leerDato();
  /**metodos**/
  long buscarDatoFecha();
  void setFechaInicio(Fecha);
  void setFechaFin(Fecha);
  void setDescuento(int);
  Fecha getFechaInicio();
  Fecha getFechaFin();
  int getDescuento();
};
class Actividad : public Dato{
 private:
  Actividad * tmp;
 public:
  Actividad();
  Actividad(bool);
  /**virtuales**/
  ~Actividad();
  int guardarDato();
  long buscarDato();
  int leerDato();
};

class Reservacion : public Dato{
 private:
  int instalacion;
  char nit[16];
  Fecha fechaInicial;
  Fecha fechaFinal;
  int actividad;
  Reservacion * tmp;
  Instalacion * tmpInst;
  Cliente * tmpCliente;
  Actividad * tmpActividad;
  Instalacion instal; //objeto agregado
  Cliente cliente; // objeto agregado
  //int tipoInstalacion; // tipo instalacion para instruccion Listar_Reservaciones
  bool aplicaDescuento; // si aplica descuento es verdadero
  int diasExt;
  char archTmpInst[16];
 public:
  Reservacion();
  Reservacion(bool);
  /**virtuales**/
  ~Reservacion();
  int guardarDato();
  long buscarDato();
  int leerDato(char *, int, Fecha);
  /**metodos**/
  void setInstalacion(int); // valida y asigna instalacion
  void setNit(char *); // valida y asigna nit
  void setFechaInicial(Fecha); // valida y asigna fecha inicial
  void setNumDias(int); // interfaz para el parser del numero de dias
  void setFechaFinal(Fecha); // valida y asigna fecha final
  void setTipoActividad(int); // valida y asigna tipo de actividad
  //  void setTipoInstalacion(int); // asigna un tipo de instalacion para listar
  //  int getTipoInstalacion(); // devuelve el tipo de instalacion
  char * getNombreCliente(); // devuelve el nombre del objeto cliente
  void setDiasExt(int);
  int getDiasExt();
  int getInstalacion(); // devuelve el id de la instalacion
  char* getNit(); // devuelve el id del cliente
  Fecha getFechaInicial(); // devuelve la fecha incial
  Fecha getFechaFinal(); // devuelve la fecha final
  int extender(); // extiende los dias de la reservacion
  long buscarDatoFecha(); // busca si la instalacion no esta reservada en el intervalo de dias
  int eliminar(); // Elimina registro de archivo binario
  void asignarDescuento(); // pone la bandera de Descuento en true si aplica descuento por dias festivos
  long buscarDatoId(); // Busca por id en archivo de reservacion
  int disponibilidad(Reporte& ); // Chequea y genera reporte de instalaciones disponibles
  void generarListaReservacion(Reporte& ); // Genera lista de reservaciones segun el tipo instalacion
 private:
  int abrirArchivoInst(); // lee y genera un archivo temporal de instalaciones no reservadas
  void generarReporteDisp(Reporte& ); // Genera reporte de instalaciones disponibles
  void borrarTmpFiles(); //borra archivos temporales
};

class Consumo : public Dato{
 private:
  Consumo * tmp;
  int instalacionR;
  int instalacionC;
  int nit;
  float monto;
  float precioInst;
  Cliente cliente;
  Instalacion instalC;
  Instalacion instalR;
  Reservacion reservacion;
  Fecha fecha;
 public:
  Consumo();
  Consumo(bool);
  /**virtuales**/
  ~Consumo();
  int guardarDato();
  long buscarDato();
  int leerDato();
  /*metodos*/
  void setInstalacionR(int); //instalacion reservada
  void setInstalacionC(int); //instalacion consumo
  void setNit(char *);
  void setMonto(float); // asigna el monto del consumo
  void setFecha(Fecha);
  int getInstalacionR(); //devuelve id de instalacion reservada
  int getInstalacionC(); //devuelve id de instalacion de consumo
  Fecha getFecha();
  int asignarReservacion(); //asigna reservacion si existe y su respectivo monto de habitacion
  char * getNombreInstalR();
  char * getNombreInstalC();
  char * getNombreCliente();
  char * getNit(); //retorna el nit del cliente
  int getIDinstalR();
  float getPrecioInstalR();
  float getMonto();
  void setDiasExt(int);
  int calcularGastoReservacion(Reporte& );
  float getDescuento(Fecha);
  //Fecha getFecha();
  //  int validar();
};


/*Parser: Clase que analiza sintactica y semanticamente el archiv
 de entrada*/
class Parser{
 private:
  char pathEntrada[255]; //Path y filename
  char pathSalida[255];  //Solo path
  int entero; // entero leido
  float flotante; //float leido
  char caracter; //caracter leido
  char cadena[255]; //cadena leida
  Fecha fecha; // Fecha leida
  Reporte salida; // reporte de Salida
  //Objetos a utilizar
  TipoInstalacion tipoInst;
  Instalacion inst;
  Cliente cliente;
  Promo promo;
  Actividad actividad;
  Reservacion reservacion;
  Consumo consumo;

  /*
  */
  //struct eliminiar_reservacion{
  //  int nit;
  //  Fecha fecha;
  // elimres;

 public:
  Parser();
  // Parser(){pathEntrada[0] = 0; pathSalida[0] = 0;};
  int validar();
  int crearInstalacion(); // Crea tipo de Instalacion
  int agregarInstalacion(); //Agrega una instalacion nueva
  int agregarCliente(); // Agrega nuevo cliente
  int crearPromo(); // Crea Promocion
  int crearActividad(); // Crea Actividad 
  int reservar(); // Reserva
  int extenderReservacion(); //Extiende reservacion
  int eliminarReservacion(); //Elimina reservacion
  int asignarConsumo(); // Asigna consumo a clientes
  int cambiarDescuento(); // Cambia el descuento a clientes H
  int consultarDescuento(); // Consulta el descuento de clientes H
  int consultarPrecio(); // Consulta precio
  int instalacionesDisp(); // Consulta instalaciones disponibles
  int listarClientes(); //Lista clientes
  int listarReservaciones(); // Lista reservaciones
  int calcularGastoReservacion(); // Calcula gasto de Reservacion
  int setArchEntrada(char *); // asigna archivo de Entrada
  int setArchSalida(char *); // asigna archivo de Salida
  int leerEntero(); // Parsea enteros
  char * leerCadena(); // Parsea Cadenas de caracteres
  float leerFloat(); // Parsea numeros de punto flotante
  char leerCaracter(); // Parsea caracteres
  int leerFecha(Fecha&); // Parsea Fecha
  int parse(); // Funcion raiz del parser
};

#endif
