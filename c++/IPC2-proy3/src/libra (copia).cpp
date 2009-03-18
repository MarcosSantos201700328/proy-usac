/* Proyecto Libra
   Erik Vladimir Giron Marquez
   C#200313492
   4/nov/2005
 */

#ifndef LIBRA_CPP
#define LIBRA_CPP
#ifdef bc
#include "progra\ipc2\proy3\src\libra.h"
// Con esto se evita problemas de ligadura de endl en ios
#define endl "\n"
#else
#include "libra.h"
#endif
//using namespace libra;

/***********************Metodos*********************************/
/***************************************************************/
/************************* Menu *************************/
int Menu::mostrar(){
  int eleccion = 0;
  cout //<< endl << endl 
    << "Bienvenido a Libra" << endl;
  cout << "Proyecto 3: IPC 2 " << endl
       << "(c) 2005 Erik Vladimir Giron Marquez" << endl //<< endl << endl
       <<endl<<endl;
  cout << "\tMENU PRINCIPAL" << endl
       << "\t--------------" <<endl
       << "\tSeleccione lo que desea hacer" << endl
       << "\t\t1. Seleccionar Archivo de Entrada..." << endl
       << "\t\t2. Seleccionar Directorio para Archivo de Salida..." << endl
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
  if (path[strlen(path)] != '\\' || path[strlen(path)] != '/')
  	strcat(path,"\\");
  	
  	
  strcpy(salida,path);
  strcat(salida,"salida.txt");
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
/************************* Reporte *************************/
char Reporte::pathSalida[255];
char Reporte::archivoSalida[24];
int Reporte::setPathSalida(char * path){
  pathSalida[0] = 0;
  if (path!=NULL){
    strcat(pathSalida,path);
    //    if (path[strlen(path)] != '\\' || path[strlen(path)] != '/' 
    //      strcat(pathSalida,"\\")
    //    strcat(pathSalida,archivoSalida);
    return 0;
  }
  else
    return -1;
}

int Reporte::limpiar(){
  out.open(pathSalida,ofstream::out | ofstream::trunc);
  if (!out){
    return 1;
  }
  else{
    out.write("",0);
    out.close();
    return 0;
  }
}

void Reporte::escribirNumLinea(){
  char linea[32];
  linea[0] = 0;
  sprintf(linea,"Linea # %d:",numlinea);
  escribirEnPantalla(linea);
  escribirEnArchivo(linea);
}
void Reporte::escribirEnPantalla(char * msg){
  cout << msg << endl;
}

void Reporte::escribirEnArchivo(char * msg){
  out.open(pathSalida,ofstream::out | ofstream::app);
  out << msg << endl;
  out.close();
  
}

void Reporte::escribir(char * msg){
  escribirNumLinea();
  escribirEnPantalla(msg);
  escribirEnArchivo(msg);
}

void Reporte::escribirError(char * msg){
  //escribirNumLinea();
  escribirEnPantalla("Error: ");
  escribirEnArchivo("Error: ");
  escribir(msg);
}
void Reporte::escribirReporte(char* msg){
  escribirEnPantalla(msg);
  escribirEnArchivo(msg);
}
/*************************Fin Reporte*************************/
/*************************Dato*************************/
Dato::Dato(){
  id = 0;
  nombre[0] = 0;
}
void Dato::setId(long pId){
  id = pId;
}
long Dato::getId(){
  return id;
}
void Dato::setNombre(char pnombre[]){
  strncpy(nombre,pnombre,63);
}
char * Dato::getNombre(){
  return nombre;
}
bool Dato::operator<(Dato pDato){
  return (pDato.getId() < getId());
}
bool Dato::operator==(Dato pDato){
  return(getId() == pDato.getId());
}
bool Dato::operator!=(Dato pDato){
  return(getId() != pDato.getId());
}
/*************************Fin Dato*************************/
/*************************Categoria*************************/
Categoria::Categoria() : Dato(){
  numLibros = 0;
  numAutores = 0;
  //ptrAutor=NULL;
}
Categoria::Categoria(long Id) : Dato(){
  Categoria();
  setId(Id);
}

void Categoria::setPtrAutor(Autor *pAut){
  //  if(  listaAutor.BorrarPrimerValor())
  listaAutor.Insertar(pAut);
  numAutores++;
  //ptrAutor = pAut;
}
void Categoria::setPtrLibro(Libro *pLibro){
  listaLibros.Insertar(pLibro);
  numLibros++;
}
int Categoria::getNumAutores(){
  return numAutores;
}
int Categoria::getNumLibros(){
  return numLibros;
}
void Categoria::agregarTema(Tema* ptrTema){
  listaTemas.Insertar(ptrTema);
}
Lista<Libro*> * Categoria::getListaLibros(){
  return(&listaLibros);
}/*
Lista<Autor*> * Categoria::getListaAutor(){
  return(&listaAutor);
  }*/
/*************************fin Categoria*************************/
/*************************Autor*************************/
void Autor::setCategoria(long pId){
  categoria = pId;
}
void Autor::setNombre2(char pNombre[]){
  strncpy(nombre2,pNombre,49);
}
void Autor::setNacionalidad(char pnacionalidad[]){
  strncpy(nacionalidad,pnacionalidad,24);
}
long Autor::getCategoria(){
  return categoria;
}
char* Autor::getNombre2(){
  return nombre2;
}
char* Autor::getNacionalidad(){
  return nacionalidad;
}
void Autor::asociarLibro(Libro* ptrLib){
  listaLibros.Insertar(ptrLib);
}
Lista<Libro*>* Autor::getListaLibros(){
  return &(listaLibros);
}
/*************************fin Autor*************************/
/*************************Libro*************************/
Libro::Libro() : Dato(){
  categoria = editora = 0;
  isbn[0] = codUbicacion[0] = 0;
  numEdicion = anioEdicion = cantidad = 0;
  //ejemplares = new pila<Ejemplar>();
}
Libro::~Libro(){
  
  //  delete(ejemplares);
  //  delete(estudiantes);
}
long Libro::getCategoria(){
  return categoria;
}
void Libro::setCategoria(long pCat){
  categoria = pCat;
}
char* Libro::getIsbn(){
  return isbn;
}
void Libro::setIsbn(char pisbn[]){
  if(strlen(pisbn)<17){
    strcpy(isbn,pisbn);
  }
  else
    strcpy(isbn,"isbn invalido");
}
long Libro::getEditora(){
  return editora;
}
void Libro::setEditora(long pe){
  editora = pe;
}
unsigned int Libro::getNumEdicion(){
  return numEdicion;
}
void Libro::setNumEdicion( int pnum){
  numEdicion = pnum;
}
unsigned int Libro::getAnioEdicion(){
  return anioEdicion;
}
void Libro::setAnioEdicion(int pAnio){
  anioEdicion = pAnio;
}
char* Libro::getCodUbicacion(){
  return codUbicacion;
}
void Libro::setCodUbicacion(char pcod[]){
  if (strlen(pcod) < 16)
    strcpy(codUbicacion,pcod);
  else
    strcpy(codUbicacion,"pcod inval");
}
unsigned int Libro::getCantidad(){
  return cantidad;
}
void Libro::setCantidad( int q){
  cantidad = q;
}
//deprecado
void Libro::agregarEjemplares(){
  Ejemplar tmp;
  for (unsigned int i = 1;i<=cantidad;i++){
    tmp.setNumEjemplar(i);//    tmp.setNumEjemplar(id);
    tmp.setLibro(this);
    //ejemplares->Push(tmp);
    ejemplares.Push(tmp);
  }
}
//fin deprecado
void Libro::agregarEjemplar(Ejemplar e){
  //  int num = e.getNumEjemplar();
  cantidad += 1;
  //  for (int i=1; i<=num; i++){
  //    e.setNumEjemplar(i);
  //ejemplares->Push(e);
  ejemplares.Push(e);
    //  }
}
void Libro::asociarAutor(Autor* ptrAutor){
  listaAutores.Insertar(ptrAutor);
}
void Libro::agregarTema(Tema* ptrTema){
  listaTemas.Insertar(ptrTema);
}
/*
Ejemplar* Libro::prestar(Solicitud solicitud){
  Ejemplar tmpEjemplar;
  if (cantidad){
    cantidad--; // reduce
    tmpEjemplar = (ejemplares->Pop()); //saca de pila
    ejemplaresPrestados.Insertar(tmpEjemplar); //inserta en lista
    ejemplaresPrestados.BuscarPrimerValor(tmpEjemplar);
    return (&ejemplaresPrestados.ValorActual());
  }
  else
    return NULL;
}
*/

Ejemplar* Libro::prestar(Solicitud solicitud){
  Ejemplar tmpEjemplar;
  if (cantidad && !(ejemplares/*->*/.estaVacia())){ //si hay ejemplares disponibles
    cantidad--; // reduce cantidad de libros disponibles
    tmpEjemplar = ejemplares./*->*/Pop();
    tmpEjemplar.estaPrestado(true);
    tmpEjemplar.insertarSolicitud(solicitud); //adjunta datos del solicitante
    ejemplaresPrestados.Insertar(tmpEjemplar); //inserta en lista
    ejemplaresPrestados.BuscarPrimerValor(tmpEjemplar);
    return (&ejemplaresPrestados.ValorActual());
  }
  else
    return NULL;
}
Ejemplar* Libro::devolver(Solicitud solicitud){
  Ejemplar tmpEjemplar;
  Ejemplar* ptrEjemplar;
  tmpEjemplar.setNumEjemplar(cantidad + 1);
  //  if (cantidad){
    cantidad++; // aumenta
    ejemplaresPrestados.Primero();
    if(ejemplaresPrestados.BuscarPrimerValor(tmpEjemplar)){
      //      ptrEjemplar = ejemplaresPrestados.ValorActual();
      //      ptrEjemplar->estaPrestado(false);
      tmpEjemplar =  ejemplaresPrestados.ValorActual(); //inserta en lista
      ejemplaresPrestados.BorrarPrimerValor(tmpEjemplar);
      //ejemplares->Push(tmpEjemplar);
      ejemplares.Push(tmpEjemplar);
      ptrEjemplar = ejemplares/*->*/.cima();
      ptrEjemplar->estaPrestado(false);
      ptrEjemplar->removerSolicitud();
    }
    return (ejemplares/*->*/.cima());
    //}
    //  else
    //    return NULL;
}
void Libro::agregarColaEspera(Solicitud s){
  colaEspera.Anadir(s);
}
Solicitud Libro::sacarColaEspera(){
  return(colaEspera.Leer());
}
bool Libro::colaEsperaVacia(){
  return colaEspera.estaVacia();
}
Lista<Autor*>* Libro::getListaAutor(){
  return (&listaAutores);
}
pila<Ejemplar>* Libro::getEjemplares(){
  return (&ejemplares);
}

Lista<Tema*>* Libro::getListaTemas(){
  return &(listaTemas);
}
cola<Solicitud> * Libro::getColaEspera(){
  return &colaEspera;
}
/*************************fin Libro*************************/
/*************************Ejemplar*************************/
Ejemplar::Ejemplar(){
  libro = NULL;
  numEjemplar = 0;
  solicitud = NULL;
  cantidad = 1;
  prestado = false;
}
Ejemplar::~Ejemplar(){
  //  if (!estaPrestado())
  //    delete( solicitud);
}
void Ejemplar::setId(int pid){
  id = pid;
}

int Ejemplar::getId(){
  return id;
}
void Ejemplar::setNumEjemplar(int pNum){
  numEjemplar = pNum;
}
int Ejemplar::getNumEjemplar(){
  return numEjemplar;
}
void Ejemplar::setLibro(Libro* pLibro){
  libro = pLibro;
}
Libro * Ejemplar::getLibro(){
  return libro;
}
bool Ejemplar::operator<(Ejemplar e){
  return (numEjemplar < (e.getNumEjemplar()));
}

bool Ejemplar::operator!=(Ejemplar e){
  return (numEjemplar != (e.getNumEjemplar() ));
}
void Ejemplar::insertarSolicitud(Solicitud s){
  solicitud = new Solicitud();
  *solicitud = s;
}
void Ejemplar::insertarSolicitud(Solicitud* s){
  solicitud = s;
}
void Ejemplar::removerSolicitud(){
  delete(solicitud);
}
Solicitud* Ejemplar::getSolicitud(){
  return (solicitud);
}
bool Ejemplar::estaPrestado(){
  return prestado;
}
void Ejemplar::estaPrestado(bool v){
  prestado = v;
}
/*************************fin Ejemplar*************************/
/*************************Tema*************************/
void Tema::agregarLibro(Libro* l){
  listaLibro.Insertar(l);
}
void Tema::agregarCategoria(Categoria* c){
  categoria = c;;
}
Lista<Libro*>* Tema::getListaLibros(){
  return &listaLibro;
}
Lista<Autor*>* Tema::getListaAutor(){
  return listaAutor;
}
Categoria* Tema::getPtrCategoria(){
  return categoria;
}
/*************************fin Tema*************************/
/*************************Solicitud*************************/
void Solicitud::setIsbn(char* pisbn){
  strncpy(isbn,pisbn,16);
}
char* Solicitud::getIsbn(){
  return isbn;
}
void Solicitud::setNumEjemplar(int pint){
  numEjemplar = pint;
}
/*************************fin Ejemplar**************************/
/*************************Libra*************************/
Libra::Libra(){
  //  inst.
  //  listaCat = new Lista<Categoria>();
}
Libra::~Libra(){
}
int Libra::setArchSalida(char * path){
  if (path!=NULL){
    strcpy(pathSalida,path);
    salida.setPathSalida(pathSalida);
    return 0;
  }
  else
    return -1;
}

int Libra::setArchEntrada(char * path){
  if (path!=NULL){
    strcpy(pathEntrada,path);
    return 0;
  }
  else
    return -1;
}
int Libra::leerEntero(){
  if (estado == E_num)
    if ((isdigit(lexema[0]))!=0){
      return atoi(lexema);
    }
    else
      return -1;
  else
    return -1; // si no es caracter devuelve tamano int negativo
}
float Libra::leerFloat(){
  int entero, mantisa;
  if((entero=leerEntero())>-1){
    Token(1);
    if (estado == E_punto){
      Token(1);
      if((mantisa=leerEntero())>-1)
	return entero + (mantisa * 0.1);
      else{
	ReturnFile2();
	lexema[strlen(lexema)-1] = 0;
	return -1;
      }
    }
    else{
      ReturnFile2();
      lexema[strlen(lexema)-1] = 0;
      return entero;
    }
  }
  else
    return -3;
}


char * Libra::leerCadena(int &i){
  cadena[0] = 0;
  int contador = 0;
  //while((estado!=E_coma || estado!=E_parC) && contador < 255){
  //if (lexema[0] == STRDELIM){
  //  Token(1);
    while(estado !=E_coma && estado !=E_parC && estado!=E_FinArchivo && contador < 240){
      contador+=strlen(lexema);
      if (contador < 512){
	strcat(cadena,lexema);
	strcat(cadena," ");
       }
      if(estado!=E_coma || estado !=E_parC)
	Token(1);
      
    }
    //    if(estado!=E_coma || estado !=E_parC)
      i++;
    //      Token(1);
    //  }
  return cadena;
}
/*char * Libra::leerCadena(){
  cadena[0] = 0;
  int contador = 0;
  //while((estado!=E_coma || estado!=E_parC) && contador < 255){
  if (lexema[0] == STRDELIM){
    Token(1);
    while(lexema[0] !=STRDELIM && estado!=E_FinArchivo && contador < 240){
      contador+=strlen(lexema);
      if (contador < 255){
	strcat(cadena,lexema);
	strcat(cadena," ");
       }
      Token(1);
      
    }
    //      Token(1);
  }
  return cadena;
  }*/
int Libra::parse_crearCategoria(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    categoria.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_crearEditora(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    editora.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    editora.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}

int Libra::parse_crearAutor(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    autor.setCategoria(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if ((entero = leerEntero())!=-1){
	    autor.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==2){
	  if( leerCadena(i)!=NULL){
	    autor.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==3){
	  if( leerCadena(i)!=NULL){
	    autor.setNombre2(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==4){
	  if( leerCadena(i)!=NULL){
	    autor.setNacionalidad(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_crearLibro(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    libro.setCategoria(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    libro.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==2){
	  if ((entero = leerEntero())!=-1){
	    libro.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==3){
	  if( leerCadena(i)!=NULL){
	    libro.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==4){
	  if ((entero = leerEntero())!=-1){
	    libro.setEditora(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==5){
	  if ((entero = leerEntero())!=-1){
	    libro.setNumEdicion(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==6){
	  if ((entero = leerEntero())!=-1){
	    libro.setAnioEdicion(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==7){
	  if( leerCadena(i)!=NULL){
	    libro.setCodUbicacion(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==8){
	  if ((entero = leerEntero())!=-1){
	    libro.setCantidad(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_AutorLibro(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    libro.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==2){
	  if ((entero = leerEntero())!=-1){
	    autor.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_TemaLibro(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    libro.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==2){
	  if( leerCadena(i)!=NULL){
	    tema.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}

int Libra::parse_SolicitudLibro(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    solicitud.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    solicitud.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==2){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==3){
	  if( leerCadena(i)!=NULL){
	    solicitud.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}

int Libra::parse_DevolucionLibro(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    solicitud.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    solicitud.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==2){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==3){
	  if( leerCadena(i)!=NULL){
	    solicitud.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==4){
	  if ((entero = leerEntero())!=-1){
	    solicitud.setNumEjemplar(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_LibrosPorTema(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if( leerCadena(i)!=NULL){
	    tema.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}

int Libra::parse_LibrosPorEditora(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    editora.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}

int Libra::parse_ejemplaresLibros(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    libro.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_autoresLibro(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if( leerCadena(i)!=NULL){
	    libro.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_temasPorAutor(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    autor.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_autoresPorTema(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    tema.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}

int Libra::parse_prestamosLibro(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    categoria.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena(i)!=NULL){
	    libro.setIsbn(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
int Libra::parse_autoresEditora(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    editora.setId(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}

/*
int Libra::agregarCliente(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){ // mientras no se llegue a ';'
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
      }
      else{
	if (i==0){
	  if( leerCadena()!=NULL){
	    cliente.setNit(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==1){
	  if( leerCadena()!=NULL){
	    cliente.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i == 2){
	  if( leerCadena()!=NULL){
	    cliente.setDireccion(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==3){
	  if( leerCadena()!=NULL){
	    cliente.setTel(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i== 4){
	  if( leerCadena()!=NULL){
	    cliente.setFechaN(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==5){
	  if(leerCadena()!=NULL){
	    cliente.setHabitual(cadena);
	  }
	  else 
	    errnum++;
	}
      }
    }
    if (errnum>0)
      salida.escribirError("Esta instruccion sera ignorada");
  }
  else {
    salida.escribirError("Sintaxis incorrecta!!");
    errnum++;
  }
  return errnum;
}
*/

int Libra::parse(){
  char mensaje[255]; // temporal
  int salir = 0;
  int ret = 0;
  char * retstr;
  salida.limpiar(); // limpia archivo de salida
  if(!abre_arch(pathEntrada)) {
    return -1;
  }
  else {
    while(!feof(file_in) && salir<32000){
      Token(1);
      switch(estado){
      case 101:
	Token(1);
	if(parse_crearCategoria() == 0){
	  ret = crearCategoria();
	  if(ret == 0)
	    sprintf(mensaje,"(+) Categoria: %s CREADA ",
		    categoria.getNombre());//tipoInst.getNombre(),tipoInst.getID());
	  else if(ret == 1)
	    sprintf(mensaje,"(*) Categoria: %s ACTUALIZADA ",
		    categoria.getNombre());
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 102:
	Token(1);
	if(parse_crearEditora() == 0){
	  ret = crearEditora();
	  if(ret == 0)
	    sprintf(mensaje,"(+) Editora: %s CREADA ",
		    editora.getNombre());//tipoInst.getNombre(),tipoInst.getID());
	  else if(ret == 1)
	    sprintf(mensaje,"(*) Editora: %s ACTUALIZADA ",
		    editora.getNombre());
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 103:
	Token(1);
	if(parse_crearAutor() == 0){
	  ret = crearAutor();
	  if(ret == 0)
	    sprintf(mensaje,"(+) Autor: %ld - %s,%s,%s CREADO ",
		    autor.getId(),autor.getNombre(),autor.getNombre2(),autor.getNacionalidad());//tipoInst.getNombre(),tipoInst.getID());
	  else if(ret == 1)
	    sprintf(mensaje,"(*) Autor: %ld - %s,%s,%s ACTUALIZADO ",
		    autor.getId(),autor.getNombre(),autor.getNombre2(),autor.getNacionalidad());//tipoInst.getNombre(),tipoInst.getID());
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
	//	break;
      case 104:
	Token(1);
	if(parse_crearLibro() == 0){
	  ret = crearLibro();
	  if(ret == 0)
	    sprintf(mensaje,"(+) Libro : %s - %s CREADO ",
		    libro.getIsbn(),libro.getNombre());//tipoInst.getNombre(),tipoInst.getID());
	  else if(ret == 1)
	    sprintf(mensaje,"(*) Libro : %s - %s ACTUALIZADO ",
		    libro.getIsbn(),libro.getNombre());//tipoInst.getNombre(),tipoInst.getID());
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
	//	break;
      case 105:
	Token(1);
	if(parse_AutorLibro() == 0){
	  ret = asociarAutorLibro();
	  if(ret == -1){
	    sprintf(mensaje,"(!) Imposible asociar, los parametros no son logicamente validos");
	    salida.escribir(mensaje);}
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
	//	break;
      case 106:
	Token(1);
	if(parse_TemaLibro() == 0){
	  ret = asociarTemaLibro();
	  if(ret == -1){
	    sprintf(mensaje,"(!) Imposible asociar, los parametros no son logicamente validos");
	    salida.escribir(mensaje);}
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
	//	break;
      case 107:
	Token(1);
	if(parse_SolicitudLibro() == 0){
	  ret = solicitarLibro();
	  if(ret == 0)
	    sprintf(mensaje,"(+) Libro : %s prestado por %s",
		    solicitud.getIsbn(),solicitud.getNombre());//tipoInst.getNombre(),tipoInst.getID());
	  else if(ret == 1)
	    sprintf(mensaje,"(*) Libro : %s solicitado por %s",
		    solicitud.getIsbn(),solicitud.getNombre());//tipoInst.getNombre(),tipoInst.getID());
	  else
	    sprintf(mensaje,"(!) Los parametros no son logicamente validos");
	salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 108:
	Token(1);
	if(parse_DevolucionLibro() == 0){
	  retstr = devolucionLibro();
	  if (retstr){
	    if(strcmp(retstr,solicitud.getNombre()) == 0)
	      // si se devolvio sin prestarlo
	      sprintf(mensaje,"(*) Libro : %s devuelto por %s",
		      solicitud.getIsbn(),solicitud.getNombre());//tipoInst.getNombre(),tipoInst.getID());
	    else
	      // si se presto luego de devolverlo
	      sprintf(mensaje,"(*) Libro : %s devuelto por %s\n(*) Libro : %s prestado a %s",
		      solicitud.getIsbn(),solicitud.getNombre(),solicitud.getIsbn(),retstr);//tipoInst.getNombre(),tipoInst.getID());
	  }
	  else
	    sprintf(mensaje,"(!) Los parametros no son logicamente validos");
	  salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 109:
	Token(1);
	if ( estado == E_parA){
	  Token(1);
	  if( estado == E_parC){
	    Token(1);
	    if (estado == E_puncoma)
	      ret = 0;
	    else
	      ret = -1;
	  }
	  else
	    ret = -2;
	}
	else
	  ret = -3;
	if (ret == 0){
	  mensaje[0] = 0;
	  consulta_Estructura();
	}
	else{
	  sprintf(mensaje,"(!) Los parametros no son logicamente validos");
	  salida.escribir(mensaje);
	}
	break;
      case 110:
	Token(1);
	if(parse_LibrosPorTema() == 0){
	  ret = LibrosPorTema(tema.getNombre());
	  if (ret){
	    sprintf(mensaje,"(!) Tema no existe");
	    salida.escribir(mensaje);
 	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 111:
	Token(1);
	if(parse_LibrosPorEditora() == 0){
	  ret = LibrosPorEditora(editora.getId());
	  if (ret){
	    sprintf(mensaje,"(!) Editora no existe");
	    salida.escribir(mensaje);
 	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 112:
	Token(1);
	if(parse_ejemplaresLibros() == 0){
	  ret = ejemplaresLibros(categoria.getId(),libro.getIsbn());
	  if (ret){
	    sprintf(mensaje,"(!) Categoria o libro no existe");
	    salida.escribir(mensaje);
 	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 113:
	Token(1);
	if(parse_autoresLibro() == 0){
	  ret = autoresLibro(libro.getIsbn());
	  if (ret){
	    sprintf(mensaje,"(!) Libro no existe");
	    salida.escribir(mensaje);
 	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 114:
	Token(1);
	if(parse_temasPorAutor() == 0){
	  ret = temasPorAutor(autor.getId());
	  if (ret){
	    sprintf(mensaje,"(!) Autor no existe");
	    salida.escribir(mensaje);
 	  }

	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 115:
	Token(1);
	if(parse_autoresPorTema() == 0){
	  ret = autoresPorTema(categoria.getId(),tema.getNombre());
	  if (ret){
	    sprintf(mensaje,"(!) Categoria o tema no existe");
	    salida.escribir(mensaje);
	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 116:
	Token(1);
	if(parse_autoresEditora() == 0){
	  ret = autoresEditora(editora.getId());
	  if (ret){
	    sprintf(mensaje,"(!) Editora no existe");
	    salida.escribir(mensaje);
	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 117:
	Token(1);
	if(parse_prestamosLibro() == 0){
	  ret = prestamosLibro(categoria.getId(),libro.getIsbn());
	  if (ret){
	    sprintf(mensaje,"(!) Categoria o libro no existe");
	    salida.escribir(mensaje);
 	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 118:
	Token(1);
	if(parse_prestamosLibro() == 0){
	  ret = solicitudesLibro(categoria.getId(),libro.getIsbn());
	  if (ret){
	    sprintf(mensaje,"(!) Categoria o libro no existe");
	    salida.escribir(mensaje);
 	  }
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      default:
	sprintf(mensaje,"Instruccion Invalida, sera ignorada");
	//	Token(1);
      }
      salir++;
    }
    cerrar_archivo();
    return 1;
  }
  return 0;
}

int Libra::crearCategoria(){
  char ret = 0;
  listaCat.Primero();
  if(listaCat.BorrarPrimerValor(categoria)) //elimina nodo si existe
    ret = 1;
  listaCat.Insertar(categoria);
  return ((int)ret);
}

int Libra::crearEditora(){
  signed char ret = 0;
  listaEd.Primero();
  if(listaEd.BorrarPrimerValor(editora))
    ret = 1;
  listaEd.Insertar(editora);
  return ((int)ret);
}
int Libra::crearAutor(){
  signed char ret = 0;
  Categoria * tmp = new Categoria(autor.getCategoria()); // temporal
  Autor * tmpAut = NULL;
  listaAut.Primero();
  //Actualiza o crea Autor
  if(listaAut.BorrarPrimerValor(autor))
    ret = 1;
  listaAut.Insertar(autor);
  listaAut.Primero();
  // busca y asigna puntero del valor previamente guardado
  listaAut.BuscarPrimerValor(autor);
  tmpAut = &(listaAut.ValorActual());
  // si se apunta en la lista a un valor valido
  if((tmpAut)!=NULL){
    listaCat.Primero();
  //Agrega puntero hacia el autor en la categoria
    if(listaCat.BuscarPrimerValor(*tmp)){
      delete(tmp);
      tmp = &(listaCat.ValorActual());
      tmp->setPtrAutor(tmpAut);
    }
    else{
      delete(tmp);
      ret = -1;
    }
  }
  else
    ret = -1;
  return ((int)ret);
}

int Libra::crearLibro(){
  //signed char ret = 0;
  Categoria* tmpCat = buscarCategoria(libro.getCategoria());// = new Categoria(libro.getCategoria()); // temporal
  Editora* tmpEd = buscarEditora(libro.getEditora());// = new Editora(libro.getEditora()); //temporal de editora
  Libro * tmpLib =  buscarLibroISBN(libro.getIsbn());

  Ejemplar tmpEjemplar; //ejemplar a insertar

  if(tmpCat && tmpEd && libro.getCantidad() > 0){
    listaLibros.Primero();
    
    tmpEjemplar.setId(libro.getId()); //establece el numero de ejemplar
    tmpEjemplar.setNumEjemplar(libro.getCantidad());
  //tmpEjemplar.setCantidad(libro.getCantidad()); //establece la cantidad de ejemplares

    if (tmpLib){ // si libro existe
      tmpEjemplar.setLibro(tmpLib);
      //actualiza y agrega ejemplar
      tmpLib->setNombre(libro.getNombre());
      tmpLib->setCodUbicacion(libro.getCodUbicacion());
      tmpLib->setNumEdicion(libro.getNumEdicion());
      tmpLib->setAnioEdicion(libro.getAnioEdicion());
      tmpLib->agregarEjemplar(tmpEjemplar);
    }
    else{ // sino crea nuevo libro
      //crear nuevo libro
      listaLibros.Insertar(libro);
      tmpLib = buscarLibroISBN(libro.getIsbn());//&(listaLibros.ValorActual());
      tmpEjemplar.setLibro(tmpLib); // agrega puntero de libro a ejemplar
      tmpLib->setCantidad(0); // resetea la cantidad de libros a cero
      tmpLib->agregarEjemplar(tmpEjemplar); //agrega ejemplar a libro
      //agrega puntero a editora y categoria
      tmpEd->setPtrLibro(tmpLib); 
      tmpCat->setPtrLibro(tmpLib);
 
    }
    return 0;
  }
  return -1;
}
/*
int Libra::crearLibro(){
  signed char ret = 0;
  Categoria * tmp = new Categoria(libro.getCategoria()); // temporal
  Editora * tmpEd = new Editora(libro.getEditora()); //temporal de editora

  Libro * tmpLib = NULL;
  listaLibros.Primero();
  //Actualiza o crea Libro
  if(listaLibros.BorrarPrimerValor(libro))
    ret = 1;
  listaLibros.Insertar(libro);

  listaLibros.Primero();
  // busca y asigna puntero del valor previamente guardado
  listaLibros.BuscarPrimerValor(libro);
  tmpLib = &(listaLibros.ValorActual());
  // si se apunta en la lista a un valor valido
  if((tmpLib)!=NULL){
    listaCat.Primero();
    listaEd.Primero();
  //Agrega puntero hacia el libro en la categoria y editora
    if(listaCat.BuscarPrimerValor(*tmp) && listaEd.BuscarPrimerValor(*tmpEd)){
      delete(tmp); delete(tmpEd); //borra contenido de punteros
      //asigna libro a categoria
      tmp = &(listaCat.ValorActual());
      tmp->setPtrLibro(tmpLib);
      //asigna libro a editora
      tmpEd = &(listaEd.ValorActual());
      tmpEd->setPtrLibro(tmpLib);
      //inicializa pila de libros
      tmpLib->agregarEjemplares();
    }
    else{
      delete(tmp); delete(tmpEd);
      ret = -1;
    }
  }
  else
    ret = -1;
  return ((int)ret);
}
*/
Categoria* Libra::buscarCategoria(long pid){
  Categoria tmp;
  tmp.setId(pid);
  listaCat.Primero();
  if(listaCat.BuscarPrimerValor(tmp)){
    return (&(listaCat.ValorActual()));
  }
  return NULL;
}

Editora* Libra::buscarEditora(long pid){
  Editora tmp;
  tmp.setId(pid);
  listaEd.Primero();
  if(listaEd.BuscarPrimerValor(tmp)){
    return (&(listaEd.ValorActual()));
  }
  return NULL;
}

Tema* Libra::buscarTemaNombre(char* nombre){
  Tema* tmpTema;
  listaTemas.Primero();
  while(listaTemas.Actual()){
    tmpTema = &(listaTemas.ValorActual());
    if(!strcasecmp(tmpTema->getNombre(),nombre)){
      listaTemas.Primero();
      return tmpTema;
    }
    listaTemas.Siguiente();
  }
  listaTemas.Primero();
  return NULL;
}
Libro * Libra::buscarLibroISBN(char* isbn){
  Libro *tmpLib;
  listaLibros.Primero();
  while(listaLibros.Actual()){
    tmpLib = &(listaLibros.ValorActual());
    if(!strcasecmp(tmpLib->getIsbn(),isbn)){
      listaLibros.Primero();
      return tmpLib;
    }
    listaLibros.Siguiente();
  }
  listaLibros.Primero();
  return NULL;
}

Autor* Libra::buscarAutor(long pid){
  Autor tmp;
  tmp.setId(pid);
  listaAut.Primero();
  if(listaAut.BuscarPrimerValor(tmp)){
    return (&(listaAut.ValorActual()));
  }
  return NULL;
}
int Libra::asociarAutorLibro(){
  Autor* ptrAut = NULL;
  Libro* ptrLib = NULL;
  Categoria* ptrCat= NULL;
  if( (ptrAut = buscarAutor(autor.getId())) && 
     ( ptrLib = buscarLibroISBN(libro.getIsbn()) ) &&
     ( ptrCat = buscarCategoria(categoria.getId()))){
    ptrCat->setPtrAutor(ptrAut); // asocia a la categoria el autor
    ptrLib->asociarAutor(ptrAut); // asocia al libro el autor
    ptrAut->asociarLibro(ptrLib); // asocia al autor el libro
    return 0;
  }
  else
    return -1;
}
int Libra::obtenerUltimoIDTema(){
  return numlinea;
}
int Libra::asociarTemaLibro(){
  Tema* ptrTema = NULL;
  Categoria* ptrCat = NULL;
  Libro* ptrLib = NULL;
  if(( ptrLib=buscarLibroISBN(libro.getIsbn()) ) &&
     (ptrCat=buscarCategoria(categoria.getId()))){
    // busca si tema ya existe en lista de temas y agrega referencias
    if((ptrTema=buscarTemaNombre(tema.getNombre()))){
      ptrTema->agregarLibro(ptrLib);
      ptrTema->agregarCategoria(ptrCat);
    }
    // sino crea nuevo nodo en listaTemas e inserta valor
    else {
      //ptrTema = &(listaTemas.valorActual()); //obtiene referencia al valor actual
      tema.setId(obtenerUltimoIDTema()); // aumenta el id del tema
      //      ptrTema = new Tema(tema.getId); // crea nuevo tema
      // ptrTema->setNombre(tema.getNombre());
      listaTemas.Insertar(tema);
      listaTemas.BuscarPrimerValor(tema);
      ptrTema = &(listaTemas.ValorActual());
      ptrTema->agregarLibro(ptrLib);
      ptrTema->agregarCategoria(ptrCat);
    }
    //agrega referencias a categoria y a libro
    ptrCat->agregarTema(ptrTema);
    ptrLib->agregarTema(ptrTema);
    return 0;
  }
  //else
  return -1;
  
  /*  if((ptrLib = buscarLibroISBN(libro.getIsbn()))){
    ptrLib->setTema();
    return 0;
  }
  return 1;*/
}
int Libra::solicitarLibro(){
  Libro* ptrLibro;
  Ejemplar* ptrEjemplar;
  if((ptrLibro = buscarLibroISBN(solicitud.getIsbn())) 
     && buscarCategoria(categoria.getId())){
    if((ptrEjemplar = ptrLibro->prestar(solicitud))){
      // si hay dispinbile inserta a la lista de prestamos
      listaPrestamos.Insertar(ptrEjemplar);
      return 0;
    }
    else{ 
      // sino agrega solicitud a cola de espera
      //colaEspera.Anadir(solicitud);
      ptrLibro->agregarColaEspera(solicitud);
      return 1;
    }
  }
  return -1;
}
char* Libra::devolucionLibro(){
  Libro * ptrLibro;
  Ejemplar * ptrEjemplar;
  Solicitud tmp;
  if((ptrLibro = buscarLibroISBN(solicitud.getIsbn())) 
     && buscarCategoria(categoria.getId())){
    
    //    librosPrestamos.BuscarPrimerValor(tmpEj);
    
      if((ptrEjemplar = ptrLibro->devolver(solicitud))){
      // borra de la lista de prestamos
      listaPrestamos.BorrarPrimerValor(ptrEjemplar);
      // si hay algun estudiante esperando lo presta
      if(!(ptrLibro->colaEsperaVacia())){
	tmp = ptrLibro->sacarColaEspera();
	ptrEjemplar = ptrLibro->prestar(tmp);
	listaPrestamos.Insertar(ptrEjemplar);
	return tmp.getNombre(); //retorna valor si se logra prestar;
      }
      else
	return solicitud.getNombre();
      }
  }
  return NULL;
}

void Libra::escribirAutoresLibro(Libro *ptrLibro){
  Lista<Autor*>* ptrListaAutores;
  Autor * ptrAutor;
  int i;
  char msg[256]; //mensaje a escribir
  ptrListaAutores = ptrLibro->getListaAutor();
  ptrListaAutores->Primero();
  i = 1;
  while(ptrListaAutores->Actual()){
    ptrAutor = ptrListaAutores->ValorActual();
    sprintf(msg,"\t\t\tAutor No. %d: %s,  %s; %s",i,ptrAutor->getNombre(),ptrAutor->getNombre2(),ptrAutor->getNacionalidad());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    i++;
    ptrListaAutores->Siguiente();
  }
}

void Libra::escribirLibrosPorCategoria(Categoria* ptrCat){
  char msg[256]; //mensaje a escribir
  Lista<Libro*>* ptrListaLibros;
  Libro * ptrLibro;

  ptrListaLibros = ptrCat->getListaLibros();
  ptrListaLibros->Primero();
  while(ptrListaLibros->Actual()){
    ptrLibro = ptrListaLibros->ValorActual();
    sprintf(msg,"\t\tLibro: %s - %s",ptrLibro->getIsbn(),ptrLibro->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
      // para cada autor en libro escribe sus autores
    escribirAutoresLibro(ptrLibro);
    ptrListaLibros->Siguiente();
  }
}

void Libra::escribirLibrosPorTema(Tema * ptrTema){
  char msg[256]; //mensaje a escribir
  Lista<Libro*>* ptrListaLibros = NULL;
  Libro * ptrLibro;
  
  ptrListaLibros = ptrTema->getListaLibros();
  ptrListaLibros->Primero();
  while(ptrListaLibros->Actual()){
    ptrLibro = ptrListaLibros->ValorActual();
    sprintf(msg,"\t\tLibro: %s - %s",ptrLibro->getIsbn(),ptrLibro->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
      // para cada autor en libro escribe sus autores
    escribirAutoresLibro(ptrLibro);
    ptrListaLibros->Siguiente();
  }
}

void Libra::escribirLibrosPorEditora(Editora* ptrEd){
  char msg[256]; //mensaje a escribir
  Lista<Libro*>* ptrListaLibros;
  Libro * ptrLibro;

  ptrListaLibros = ptrEd->getListaLibros();
  ptrListaLibros->Primero();
  while(ptrListaLibros->Actual()){
    ptrLibro = ptrListaLibros->ValorActual();
    sprintf(msg,"\t\tLibro: %s - %s",ptrLibro->getIsbn(),ptrLibro->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
      // para cada autor en libro escribe sus autores
    escribirAutoresLibro(ptrLibro);
    ptrListaLibros->Siguiente();
  }
}

void Libra::consulta_Estructura(){
  char msg[256]; //mensaje a escribir
  msg[0] = 0;
  salida.escribir("************************* Consulta Estructura *************************");
  // para cada categoria
  listaCat.Primero();
  while(listaCat.Actual()){
    categoria = listaCat.ValorActual();
    sprintf(msg,"\n\tCategoria: %s\n\t=========",categoria.getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    sprintf(msg,"\tCantidad de Autores: %d",categoria.getNumAutores());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    sprintf(msg,"\tCantidad de Libros: %d",categoria.getNumAutores());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    // para cada libro en categoria
    escribirLibrosPorCategoria(&categoria);
    listaCat.Siguiente();
  }  
}

int Libra::LibrosPorTema(char* nom){
  char msg[256]; //mensaje a escribir
  msg[0] = 0;
  Tema*  ptrTema = buscarTemaNombre(nom);
  Categoria* ptrCat;
  
  salida.escribir("************************* Libros por Tema *****************************");
  if(ptrTema){
    ptrCat = ptrTema->getPtrCategoria();

    sprintf(msg,"\n\tTema: %s\n\t====",ptrTema->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    sprintf(msg,"\n\tCategoria: %s",ptrCat->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    escribirLibrosPorTema(ptrTema);
    return 0;
  }
  return -1;
}

int Libra::LibrosPorEditora(long pId){
  char msg[256]; //mensaje a escribir
  msg[0] = 0;
  Editora* ptrEditora = buscarEditora(pId);

  salida.escribir("************************* Libros por Editora **************************");
  if (ptrEditora){
    sprintf(msg,"\n\tEditora: %ld - %s\n\t=======",pId,ptrEditora->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    escribirLibrosPorEditora(ptrEditora);
    return 0;
  }
  return -1;
}

int Libra::ejemplaresLibros(long idCat, char pIsbn[]){
  char msg[256]; //mensaje a escribir
  msg[0] = 0;

  Categoria* ptrCat;
  Libro* ptrLibro;
  pila<Ejemplar> * ptrPilaEjemplares;
  pila<Ejemplar> tmpPilaEjemplares;
  Ejemplar tmpEjemplar;

  ptrCat = buscarCategoria(idCat);
  ptrLibro = buscarLibroISBN(pIsbn);

  salida.escribir("************************* Ejemplares de libro  ************************");

  if(ptrCat && ptrLibro){
    ptrPilaEjemplares = ptrLibro->getEjemplares();

    sprintf(msg,"\n\tCategoria: %s\n\t=========",ptrCat->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);

    sprintf(msg,"\t\tLibro: %s - %s",pIsbn,ptrLibro->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);

    // saca ejemplares de la pila
    while(!(ptrPilaEjemplares->estaVacia())){
      tmpEjemplar = ptrPilaEjemplares->Pop();
      sprintf(msg,"\t\t\tCodigo Interno: %d, Ejemplar No.: %d",tmpEjemplar.getId(),tmpEjemplar.getNumEjemplar());
      salida.escribirEnPantalla(msg);
      salida.escribirEnArchivo(msg);
      tmpPilaEjemplares.Push(tmpEjemplar);    
    }
    // mete de nuevo los ejemplares en la pila
    while(!(tmpPilaEjemplares.estaVacia())){
      ptrPilaEjemplares->Push(tmpPilaEjemplares.Pop());
    }
    return 0;
  }
  return -1;
}

int Libra::autoresLibro(char pIsbn[]){
  char msg[256]; //mensaje a escribir
  msg[0] = 0;
  Libro* ptrLibro = buscarLibroISBN(pIsbn);

  salida.escribir("************************* Autores de Libro ****************************");
  if (ptrLibro){
    sprintf(msg,"\tLibro: %s - %s",ptrLibro->getIsbn(),ptrLibro->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    escribirAutoresLibro(ptrLibro);
    return 0;
  }
  return -1;
}

int Libra::temasPorAutor(long IdAutor){
  Autor* ptrAutor = buscarAutor(IdAutor);
  Lista<Libro*>* ptrListaLibros;
  Libro* ptrLibro;

  char msg[256]; //mensaje a escribir
  msg[0] = 0;

  salida.escribir("************************* Temas Por Autor *****************************");
  if(ptrAutor){
    sprintf(msg,"\tAutor : %s,  %s",ptrAutor->getNombre(),ptrAutor->getNombre2());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);

    ptrListaLibros = ptrAutor->getListaLibros();
    ptrListaLibros->Primero();
    while(ptrListaLibros->Actual()){
      ptrLibro = (ptrListaLibros->ValorActual());
      escribirTemasPorLibro(ptrLibro);
      ptrListaLibros->Siguiente();
    }
    return 0;
  }
  return -1;
}
void Libra::escribirTemasPorLibro(Libro* ptrLibro){
  Lista<Tema*>* ptrListaTemas = ptrLibro->getListaTemas();
  Tema * ptrTema;
  signed int i = 1;
  char msg[256]; //mensaje a escribir
  msg[0] = 0;
  ptrListaTemas->Primero();
  while(ptrListaTemas->Actual()){
    ptrTema = (ptrListaTemas->ValorActual());
    sprintf(msg,"\t\tTema No. %d: %s",i,ptrTema->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    i++;

    ptrListaTemas->Siguiente();
  }
}

int Libra::autoresPorTema(long idCat, char descTema[]){
  Categoria* ptrCat = buscarCategoria(idCat);
  Tema * ptrTema = buscarTemaNombre(descTema);
  Lista<Libro*>* ptrListaLibros;
  Libro* ptrLibro;
  char msg[256]; //mensaje a escribir
  msg[0] = 0;

  salida.escribir("************************* Autores por Tema ****************************");
  if(ptrCat && ptrTema){
    sprintf(msg,"\tTema : %s",ptrTema->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);
    
    ptrListaLibros = ptrTema->getListaLibros();
    ptrListaLibros->Primero();
    while(ptrListaLibros->Actual()){
      ptrLibro = ptrListaLibros->ValorActual();
      escribirAutoresLibro(ptrLibro);
      ptrListaLibros->Siguiente();
    }
    return 0;
  }
  return -1;
}

int Libra::autoresEditora(long pId){
  Editora* ptrEditora = buscarEditora(pId);
  Lista<Libro*>* ptrListaLibros;
  Libro * ptrLibro;
  // int i = 1;

  char msg[256]; //mensaje a escribir
  msg[0] = 0;

  salida.escribir("************************* Autores Por Editora *************************");
  if(ptrEditora){

    sprintf(msg,"\tEditora : %s",ptrEditora->getNombre());
    salida.escribirEnPantalla(msg);
    salida.escribirEnArchivo(msg);

    ptrListaLibros = ptrEditora->getListaLibros();
    ptrListaLibros->Primero();
    while(ptrListaLibros->Actual()){
      ptrLibro = ptrListaLibros->ValorActual();
      
      escribirAutoresLibro(ptrLibro);
      //      sprintf(msg,"\t\tAutor No. %d : %s,  %s",i,ptr->getNombre(),ptrAutor->getNombre2());
      //      salida.escribirEnPantalla(msg);
      //      salida.escribirEnArchivo(msg);

      ptrListaLibros->Siguiente(); /*i++*/;
    }
    return 0;
  }
  return -1;
}
int Libra::prestamosLibro(long idCat, char pIsbn[]){
  Categoria * ptrCat = buscarCategoria(idCat);
  Libro * ptrLibro = buscarLibroISBN(pIsbn);
  //  Lista<Ejemplar*>* listaPrestamos;
  Ejemplar* ptrEjemplar;
  Solicitud* ptrSolicitud;
  
  char msg[256]; //mensaje a escribir
  msg[0] = 0;

  salida.escribir("************************* Prestamos Libro *****************************");
  if(ptrCat && ptrLibro){
    listaPrestamos.Primero();
    //recorremos la lista
    while(listaPrestamos.Actual()){
      ptrEjemplar = listaPrestamos.ValorActual();
      // escribir si se apunta al mismo libro
      if(ptrLibro == ptrEjemplar->getLibro()){
	ptrSolicitud = ptrEjemplar->getSolicitud();
	sprintf(msg,"\n\tNum. Sol.: %ld || Carne: %s || Cod. Cat.: %ld\n\t|| ISBN: %s || Cod. Ejemplar: %d",
		ptrSolicitud->getId(),ptrSolicitud->getNombre(),
		idCat,ptrLibro->getIsbn(),ptrEjemplar->getId());
	salida.escribirEnPantalla(msg);
	salida.escribirEnArchivo(msg);
      }
      listaPrestamos.Siguiente();
    }
    return 0;
  }
  return -1;
}

int Libra::solicitudesLibro(long idCat,char pIsbn[]){
  Categoria * ptrCat = buscarCategoria(idCat);
  Libro * ptrLibro = buscarLibroISBN(pIsbn);
  cola<Solicitud> tmpCola;
  cola<Solicitud>* ptrCola;
  Solicitud tmpSolicitud;

  char msg[256]; //mensaje a escribir
  msg[0] = 0;

  salida.escribir("************************* Solicitud Libro *****************************");
  if(ptrCat && ptrLibro){
    // obtiene el address de la cola
    ptrCola = ptrLibro->getColaEspera();
    // saca de la cola, mete a cola temporal y escribe datos
    while(!(ptrCola->estaVacia())){
      tmpSolicitud = ptrCola->Leer();
      tmpCola.Anadir(tmpSolicitud);
      sprintf(msg,"\n\tNum. Sol.:%ld || Carne: %s || Cod. Cat.: %ld\n\t|| ISBN: %s",
	      tmpSolicitud.getId(),tmpSolicitud.getNombre(),
	      idCat,tmpSolicitud.getIsbn());
      salida.escribirEnPantalla(msg);
      salida.escribirEnArchivo(msg);
    }
    // restaura datos desde cola temporal
    while(!tmpCola.estaVacia()){
      ptrCola->Anadir(tmpCola.Leer());
    }
    return 0;
  }
  return -1;
}
/*************************fin Libra*************************/


/***************************Main********************************/
/***************************************************************/
int main(){
  Menu menu; // Crea nueva instancia de Menu
  Libra libra; // Crea nueva instancia de Libra

#ifndef debug
  system("del c:\\*.mot");
#else
  system("rm *.mot");
#endif
  do{
    menu.ejecutar(); // Ejecuta el menu
#ifdef debug
    libra.setArchEntrada("in.txt");
    libra.setArchSalida("salida.txt");
#else
    libra.setArchEntrada(menu.getEntrada()); // Asigna archivo de entrad
    libra.setArchSalida(menu.getSalida()); // Asigna path de salida
#endif
    if (menu.getOpcion() == 3){
      libra.parse();
    }
  }
  while (menu.getOpcion() > 0 && menu.getOpcion() < 4);
  //exit(1);
  return 0;
}

#endif
