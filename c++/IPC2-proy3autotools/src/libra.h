/* Proyecto Libra
   Erik Vladimir Giron Marquez
   C#200313492
   4/nov/2005
 */

/* TODO List:
 -[HECHO] Arreglar Makefile
 -[HECHO] Implementar TDAs
   -[HECHO] componer bug del template en Lista::crearCategoria
 -[HECHO] Crear_Categoria
 -[HECHO] Crear_Editora
 -[HECHO] Crear_Autor
 -[HECHO] Crear_Libro
   -[] componer destructor para resolver errores de compilacion
 -[HECHO] autor_libro
 -[HECHO] tema_libro
 -[HECHO-CON CLAVOS] solicitud_libro
   -[HECHO]> verificar que solicitud se agregue a la cola si no hay ejemplares disponibles
   -> Arreglar destructor de Ejemplar para que borre solicitud cuando
     no este prestado
   -> Validar para que libro pertenezca a categoria
 -[HECHO-CON CLAVOS] devolucion_libro
   -> componer referencias perdidas relacionadas 
      con punteros erroneos a libros en lista de ejemplaresPrestados
   -> eliminar las instancias dinamicas de solicitudes en Ejemplar sacado   
 -[HECHO] Consulta_Estructura
   -[HECHO] componer el puntero a ListaAutor para que nodos no referencien a nulo
   -> Componer numero de autores y de libros (siempre saca n+1)
 -[HECHO] Libros_Editora
 -[HECHO] Ejemplares Libro
 -[HECHO] Autores Libro
 -[HECHO] Temas Por Autor
 -[HECHO] Autores por Tema
   -> Validar para el tema se encuentre en la categoria dada.
 -[HECHO] Prestamos Libro
 -[HECHO] Solicitudes Libro


-BUGS
 -[FIXED] Referencia a autores en Libros siempre es la misma
 */

// Definiciones Iniciales
#ifndef LIBRA_H
#define LIBRA_H

#ifndef debug
#define debug
//#undef debug
#endif
#define STRDELIM '\"' // Delimitardor para cadenas de caracteres a leer


// Inclusion de librerias C estandar

//PARA COMPILAR EN BC... (DEFINIR bc)
#ifdef bc
//incluye librerias viejas de C++
//#include <iostream.h>
//#include <fstream.h>
#define bool unsigned short int
#define true 1
#define false 0
//algunas funciones que en borland C tienen otro nombre
#define strcasecmp(x,y) strcmpi(x,y)
#define round(x) ceil(x)
//#define endl "\n"
#include "d:\progra\ipc2\proy3\src\scanner.cpp"
#include "d:\progra\ipc2\proy3\src\lista.cpp" // TDA lista
#include "d:\progra\ipc2\proy3\src\pila.cpp"  // TDA pila
#include "d:\progra\ipc2\proy3\src\cola.cpp"  // TDA cola
#else

//PARA COMPILAR EN GCC ...
//INCLUSION DE LIBRERIAS ESTANDAR ISO C++ 1999
#include <iostream>
#include <fstream>
#include "scanner.cpp" // Scanner
using namespace std;
//namespace libra{      //Definicion de Espacio de nombre
#include "lista.cpp" // TDA lista
#include "pila.cpp"  // TDA pila
#include "cola.cpp"  // TDA cola
#endif

extern "C"{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef bc
#include <iostream.h>
#include <fstream.h>
#endif
};
// Inclusion de archivos del proyecto




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

// Clase base para los datos
class Dato{
 private:
  long id;
  char nombre[64];
 public:
  Dato();
  virtual ~Dato(){};
  void setNombre(char[]);
  char* getNombre();
  void setId(long);
  long getId();
  virtual bool operator<(Dato); //operador < para orden de lista
  virtual bool operator==(Dato); // operador == para busqueda en lista
  virtual bool operator!=(Dato); // operador != para busqueda en lista
};

//prototipo de clases
class Autor; 
class Libro;
class Prestamo;
class Solicitud;
class Tema;
class Categoria : public Dato{
 private:
  Lista<Autor*> listaAutor; // lista de referencias a autores dentro de la categoria
  Lista<Libro*> listaLibros; // lista de referencias a libros dentro de la categoria
  Lista<Tema*> listaTemas;
  int numLibros;
  int numAutores;
 public:
  Categoria();
  virtual ~Categoria(){
#ifdef debug 
    printf("Liberando categoria\n");
#endif
  };
  Categoria(long);
  void setPtrAutor(Autor*); // agrega puntero de Autor a lista de autores
  void setPtrLibro(Libro*); // agrega puntero de Libro a lista de libros
  void agregarTema(Tema*);
  int getNumAutores(); // retorna numero de autores
  int getNumLibros(); // retorna numero de libros
  Lista<Libro*>* getListaLibros(); //retorna referencia a lista de referencias de libros
  Lista<Autor*>* getListaAutor(); // retorna referencia a lista de autores
};

// Las categorias contienen los mismos atributos que las editoras,
// se decide entonces crear un alias para evitar ambiguedad conceptual
#define Editora Categoria 
/* 
class Editora : public Dato{
  Lista<Autor*> listaAutor;
  Lista<Libro*> listaLibros;
  int numLibros;
 public:
  void setPtrAutor(Autor*);
  void setPtrLibro(Libro*);
  int getNumAutores();
  int getNumLibros();
};
*/
class Autor : public Dato{
 private:
  long categoria;
  Categoria * cat; //puntero a la categoria a la que pertenece
  char nombre2[50]; // Nombre; apellido sera nombre heredado de Dato
  char nacionalidad[25];
  Lista<Libro*> listaLibros; // Lista de Libros que ha hecho el autor
 public:
  virtual ~Autor(){
#ifdef debug
    printf("Liberando autor\n");
#endif
  };
  void setCategoria(long); // establece la categoria del autor y su respectivo puntero
  long getCategoria(); // devuelve la categoria a la que pertenece el autor
  void setNombre2(char[]); // establece el nombre del autor (apellido dado por nombre heredado de clase dato)
  char* getNombre2(); //devuelve el nombre del autor
  void setNacionalidad(char[] ); // establece la nacionalidad del autor
  char* getNacionalidad();//returna la nacionalidad del autor
  void asociarLibro(Libro*);
  Lista<Libro*>* getListaLibros();
};

class Solicitud : public Dato{
  //id actua como num de solicitud
  //Carne actua como nombre
  char isbn[17]; // libro a solicitar;
  int numEjemplar;
 public:
  virtual ~Solicitud(){
#ifdef debug 
    printf("Liberando solicitud\n");
#endif
  };
  void setIsbn(char *);
  char * getIsbn();
  void setNumEjemplar(int);
 
};

//Dato a almacenar en pila de libros prestados
class Ejemplar{
  int id;
  int numEjemplar; //Numero de ejemplar
  Libro * libro; //referencia a libro a prestado
  //  Estudiante * estudiante; // referencia a estudiante
  unsigned int cantidad; // al prestar este numero dismunuye
  Solicitud * solicitud; // solicitud
  bool prestado;
 public:
  Ejemplar();
  ~Ejemplar();
  void setId(int);
  int getId();
  void setNumEjemplar(int);
  int getNumEjemplar();
  void setLibro(Libro *); //asigna referencia a libro prestado
  void insertarSolicitud(Solicitud);
  void insertarSolicitud(Solicitud*);
  void removerSolicitud();
  bool estaPrestado();
  void estaPrestado(bool);
  Solicitud * getSolicitud();
  Libro* getLibro();
  bool operator<(Ejemplar);
  bool operator!=(Ejemplar);
  //  int setEstudiante(Estudiante*);  
};

class Libro : public Dato{
  long categoria;
  char isbn[17];
  long editora;
  unsigned int numEdicion;
  unsigned int anioEdicion;
  char codUbicacion[16];
  unsigned int cantidad; // al prestar este numero dismunuye
  Lista<Tema*> listaTemas; // Lista de temas que trata el libro
  Lista<Autor*> listaAutores; //Lista de autores
  pila<Ejemplar> ejemplares; // pila de ejemplares disponibles
  Lista<Ejemplar> ejemplaresPrestados;
  cola<Solicitud> colaEspera; //Cola de espera de ejemplar 
 public:
  Libro();
  ~Libro();
  long getCategoria();
  void setCategoria(long);
  char* getIsbn();
  void setIsbn(char[]);
  long getEditora();
  void setEditora(long);
  unsigned int getNumEdicion();
  void setNumEdicion(int);
  unsigned int getAnioEdicion();
  void setAnioEdicion( int);
  char* getCodUbicacion();
  void setCodUbicacion(char[]);
  unsigned int getCantidad();
  void setCantidad(int);
  void agregarEjemplar(Ejemplar ej); //agrega ejemplares
  void agregarEjemplares(); // agrega ejemplares a la pila
  void asociarAutor(Autor*); // agrega un autor a lista de autores
  Ejemplar* prestar(Solicitud); // presta un ejemplar de la pila
  Ejemplar* devolver(Solicitud);// devuelve un ejemplar de la pila
  pila<Ejemplar>* getEjemplares(); //devuelve referencia a la pila de ejemplares
  void agregarTema(Tema*);
  void agregarColaEspera(Solicitud); //inserta a cola de espera
  Solicitud sacarColaEspera(); // saca de cola de espera la solicitud
  bool colaEsperaVacia(); // verdadero si la cola esta vacia
  Lista<Autor*>* getListaAutor(); // devuelve referencia a lista de referencias de autores
  Lista<Tema*>* getListaTemas();
  cola<Solicitud>* getColaEspera(); //retorna referencia a cola de espera
};


class Tema : public Dato{
  Lista<Libro*> listaLibro; // Lista de punteros de libros que tienen el tema
  Lista<Autor*> *listaAutor; // puntero hacia lista de autores
  Categoria* categoria;
 public:
  virtual ~Tema(){
#ifdef debug 
		    printf("Liberando temas\n");
#endif
  };
  void agregarLibro(Libro*);
  void agregarAutor(Lista<Autor*>);
  void agregarCategoria(Categoria*);
  Lista<Libro*>* getListaLibros();
  Lista<Autor*>* getListaAutor();
  Categoria* getPtrCategoria();
};

/*Libra: Clase que analiza sintactica y semanticamente el archivo
 de entrada*/
class Libra{
 private:
  char pathEntrada[255]; //Path y filename
  char pathSalida[255];  //Solo path
  int entero; // entero leido
  float flotante; //float leido
  char caracter; //caracter leido
  char cadena[512]; //cadena leida
  Reporte salida; // reporte de Salida
  //Objetos a utilizar
  Categoria categoria;
  Editora editora;
  Autor autor;
  Libro libro;
  Tema tema;
  Solicitud solicitud;
  //TDAs a utilizar
  Lista<Categoria> listaCat; // Lista de Categorias
  Lista<Editora> listaEd; // Lista de editoras
  Lista<Autor> listaAut; // Lista de Autores
  Lista<Libro> listaLibros; // lista de libros
  Lista<Tema> listaTemas; //lista de temas
  Lista<Ejemplar* > listaPrestamos; // Lista de ejemplares prestados
  //  cola<Solicitud> colaEspera; //Cola de espera de ejemplar

  /*
  */

 public:
  Libra();
  ~Libra();
  // Libra(){pathEntrada[0] = 0; pathSalida[0] = 0;};
  //Metodos de Parser
  int validar();
  int setArchEntrada(char *); // asigna archivo de Entrada
  int setArchSalida(char *); // asigna archivo de Salida
  int leerEntero(); // Parsea enteros
  char * leerCadena(int&); // Parsea Cadenas de caracteres
  float leerFloat(); // Parsea numeros de punto flotante
  char leerCaracter(); // Parsea caracteres
  int parse(); // Funcion raiz del parser
  int parse_crearCategoria(); // parser para Crear Categoria
  int parse_crearEditora(); // parser para crear Editora
  int parse_crearAutor(); // parser para crear Autor
  int parse_crearLibro(); // parser para crear libro
  int parse_AutorLibro();
  int parse_TemaLibro();
  int parse_SolicitudLibro();
  int parse_DevolucionLibro();
  int parse_LibrosPorTema();
  int parse_LibrosPorEditora();
  int parse_ejemplaresLibros();
  int parse_autoresLibro();
  int parse_temasPorAutor();
  int parse_autoresPorTema();
  int parse_autoresEditora();
  int parse_prestamosLibro();
  //Metodos de control
  int crearCategoria(); // agrega categoria a la lista de categorias
  int crearEditora(); // agrega editora a la lista de editoras
  int crearAutor(); //Agrega autor a lista de autores y asocia a editora
  int crearLibro(); //Agrega libro a lista de libros y asocia a editora
  int asociarAutorLibro();
  int asociarTemaLibro();
  int obtenerUltimoIDTema();
  int solicitarLibro(); // solicita un libro y presta si hay disponibles
  char * devolucionLibro();
  void escribirAutoresLibro(Libro *);
  void escribirLibrosPorCategoria(Categoria *);
  void escribirLibrosPorEditora(Editora*);
  void escribirTemasPorLibro(Libro*);
  void escribirLibrosPorTema(Tema *);
  // REPORTES
  void consulta_Estructura(); // rutina de salida de datos de la estructura actual de libros
  int LibrosPorTema(char*);         // Todas las rutinas siguientes tienen
  int LibrosPorEditora(long);       // la misma logica,  por lo que
  int ejemplaresLibros(long,char[]);// comentarlas es en vano.
  int autoresLibro(char[]);
  int temasPorAutor(long);
  int autoresPorTema(long, char*);
  int autoresEditora(long);
  int prestamosLibro(long,char*);
  int solicitudesLibro(long,char*);
  Categoria* buscarCategoria(long );
  Libro* buscarLibroISBN(char *); // Busca un libro segun el ISBN dado y devuelve puntero
  Autor* buscarAutor(long ); //busca autor segun ID y devuelve puntero
  Tema* buscarTemaNombre(char *); 
  Editora* buscarEditora(long);
};
#ifndef bc
//} //cierra el bloque namespace
#endif
#endif
