/* Proyecto Mothell
   Erik Vladimir Giron Marquez
   C#200313492
   29/sept/2005
 */

#ifndef MOTHELL_CPP
#define MOTHELL_CPP
#ifdef bc
#include "progra\ipc2\proy2\src\mothell.h"
#else
#include "mothell.h"
#endif
/***********************Metodos*********************************/
/***************************************************************/

/************************* Menu *************************/
int Menu::mostrar(){
  int eleccion = 0;
  cout //<< endl << endl 
    << "Bienvenido a MotHELL" << endl;
  cout << "Proyecto 2: IPC 2 " << endl
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
  //  out = NULL;
  nombreArchivo[0]=0;
  //  datoLeido = NULL;
  datoValido = true;
}
Dato::~Dato(){
  //delete(datoLeido);
}
Dato::Dato(bool valor){
  this->esObjetoInterno(valor);
}
int Dato::setNombre(char * n){
  if (strlen(n)>0 && strlen(n)< 255){
    strcpy(nombre,n);
    return 0;
  }
  else{
    datoValido = false;
    return -1;
  }
}
char * Dato::getNombre(){
  return nombre;
}
int Dato::setID(int pId){
  if( pId>0){
    id = pId;
    datoValido = true ;
  }
  else{
    id = 0;
    datoValido = false ;
  }
  return 0;
}
int Dato::getID(){
  return id;
}
int Dato::setNombreArchivo(char * nom){
#ifdef debug	
  strcpy(nombreArchivo,nom);
#else
  strcpy(nombreArchivo,"c:\\");
  strcat(nombreArchivo,nom);
#endif
  return 0;
}
char * Dato::getNombreArchivo(){
  return nombreArchivo;
}
int Dato::nuevoDato(void * data, int size){
  int escrito = 0;
  if (datoValido){
    in = fopen(nombreArchivo,"a+b");
    escrito = fwrite(data,size,1,in);
    fclose(in);
    return 0;
  }
  else
    return -1;
}
int Dato::actualizarDato(void * data,int size, long pos){
  in = fopen(nombreArchivo,"r+b");
  if(in !=NULL && datoValido){
    fseek(in,pos*size,SEEK_SET);
    fwrite(data,size,1,in);
    fclose(in);
    return 1;
  }
  else
    return -1;
}
bool Dato::esValido(){
  return datoValido;
}
void Dato::esValido(bool b){
  //  if (datoValido)
    datoValido = b;
}
void Dato::esObjetoInterno(bool valor){
  this->objetoInterno = valor;
}
void Dato::setTipoInstalacion(int n){
  TipoInstalacion * tipoInst = new TipoInstalacion();
  tipoInst->setID(n);
  //busca si existe tipo de instalacion
  if ((tipoInst->buscarDato())>-1){
    esValido(true); // si existe es valido
    tipoInstalacion = n;
  }
  else{
    esValido(false);
    tipoInstalacion = 0;
  }
  delete tipoInst;
}
int Dato::getTipoInstalacion(){
  return (tipoInstalacion);
}
/*************************fin Dato*************************/
/*************************TipoInstalacion************************/
TipoInstalacion::TipoInstalacion() : Dato(){
  tmp = new TipoInstalacion(true);
  setNombreArchivo("tinst.mot");
  esObjetoInterno(false);
}
TipoInstalacion::TipoInstalacion(bool valor) : Dato(valor){
  this->setNombreArchivo("tinst.mot");
}
TipoInstalacion::~TipoInstalacion(){
}
int TipoInstalacion::guardarDato(){
  long pos = 0;
  if((pos=buscarDato())>=0){ // si busqueda return >=0
    return 1/*actualizarDato(this,sizeof(TipoInstalacion),pos)*/; //actualiza
  }
  else{ // sino crea
    return nuevoDato(this,sizeof(TipoInstalacion));
  }
}
long TipoInstalacion::buscarDato(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(TipoInstalacion),1,in);
      if(tmp->getID() == getID()){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}
int TipoInstalacion::leerDato(){
  return 0;
}
/*************************fin TipoInstalacion********************/
/*************************Instalacion*************************/
Instalacion::Instalacion() : Dato(){
  ubicacion = 0;
  precio = 0;
  capacidad = 0;
  setNombreArchivo("inst.mot");
  esObjetoInterno(false);
  
  tmp = new Instalacion(true);
}
Instalacion::Instalacion(bool valor) : Dato(valor){
  this->setNombreArchivo("inst.mot");
}
Instalacion::~Instalacion(){
  if (this->objetoInterno == false){
    free(tmp);
  }
}
void Instalacion::setCapacidad(int f){
  capacidad = f;
}
//void Instalacion::setTipoInstalacion(int n){
//  tipoInst = new TipoInstalacion();
//  tipoInst->setID(xn);
  //busca si existe tipo de instalacion
//  if ((tipoInst->buscarDato())>-1){
//    this->esValido(true); // si existe es valido
//    this->tipoInstalacion = n;
//  }
//  else{
//    this->esValido(false);
//    this->tipoInstalacion = 0;
//  }
//  delete tipoInst;
//}
void Instalacion::setPrecio(float f){
  precio = f;
}
void Instalacion::setUbicacion(int n){
  int nivel = 0;
  if ((nivel=n%100)==0 && n>0)
    ubicacion = n/100;
  else{
    esValido(false);
    ubicacion = n;
  }
}
int Instalacion::guardarDato(){
  long pos = 0;
  if((pos=buscarDato())>=0){ // si busqueda return >=0
    return 1/*actualizarDato(this,sizeof(*this),pos)*/; //actualiza
  }
  else{ // sino crea
    return nuevoDato(this,sizeof(*this));
  }
}
long Instalacion::buscarDato(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if(tmp->getID() == getID()){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true);
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}
int Instalacion::leerDato(int n){
  this->setID(n);
  if (this->buscarDato()>=0){
    this->setNombre(tmp->getNombre()); // copia datos leidos
    this->setCapacidad(tmp->getCapacidad());
    this->setPrecio(tmp->getPrecio());
    this->setUbicacion(tmp->getUbicacion());
    this->setTipoInstalacion(tmp->getTipoInstalacion());
    return 0;
  }
  else
    return -1;
}
int Instalacion::getCapacidad(){
  return (this->capacidad);
}
float Instalacion::getPrecio(){
  return (this->precio);
}
long Instalacion::getUbicacion(){
  return (this->ubicacion);
}
int Instalacion::getNivel(){
  return ubicacion;
}
char * Instalacion::getStrNivel(){
  int niv;
  niv = getNivel();
  switch (niv){
  case 0:
    return "Sotano";
    break;
  case 1:
    return "Primer Nivel";
    break;
  case 2:
    return "Segundo Nivel";
    break;
  case 3:
    return "Tercer Nivel";
    break;
  case 4:
    return "Cuarto Nivel";
    break;
  case 5:
    return "Quinto Nivel";
    break;
  case 6:
    return "Sexto Nivel";
    break;
  case 7:
    return "Septimo Nivel";
    break;
  case 8:
    return "Octavo Nivel";
    break;
  case 9:
    return "Noveno Nivel";
    break;
  case 10:
    return "Decimo Nivel";
    break;
  default:
    return "Nivel mayor a 10";
    break;
  }
}    
int Instalacion::consultarPrecio(){
  return (this->leerDato(this->getID()));
}
/*************************fin Instalacion*************************/
/*************************Cliente*************************/
int Cliente::descuento = 0;
Cliente::Cliente() : Dato(){
  direccion[0] = 0;
  fechaNac[0] = 0;
  telefono[0] = 0;
  habitual = false;
  setNombreArchivo("clientes.mot");
  esObjetoInterno(false);

  tmp = new Cliente(true);
}
Cliente::Cliente(bool valor) : Dato(valor){
  this->setNombreArchivo("clientes.mot");
}
Cliente::~Cliente(){
  if (this->objetoInterno == false){
    free(tmp);
  }
}
void Cliente::setDireccion(char * cad){
  strcpy(direccion,cad);
}
void Cliente::setTel(char * pTel){
  if(strlen(pTel)>0 && strlen(pTel)<19)
    strcpy(telefono,pTel);
  else
    esValido(false);
}
void Cliente::setFechaN(char * cad){
  strcpy(fechaNac,cad);
}
void Cliente::esHabitual(bool valor){
  habitual = valor;
}
char * Cliente::getDireccion(){
  return direccion;
}
char * Cliente::getTel(){
  return this->telefono;
}
char * Cliente::getFechaN(){
  return fechaNac;
}
bool Cliente::esHabitual(){
  return habitual;
}
int Cliente::setDescuento(int n){
  if (n>=0 && n<=100){
    descuento = n;
    return 0;
  }
  else
    return 1;
}
int Cliente::getDescuento(){
  return descuento;
}
int Cliente::guardarDato(){
  long pos = 0;
  if((pos=buscarDato())>=0){ // si busqueda return >=0
   return actualizarDato(this,sizeof(*this),pos); //actualiza
  }
  else{ // sino crea
    return nuevoDato(this,sizeof(*this));
  }
}
long Cliente::buscarDato(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if(strcasecmp(tmp->getNit(),nit) == 0){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}
int Cliente::leerDato(char * n){
  this->setNit(n);
  if (this->buscarDato()>=0){
    //copia datos previamente leidos desde puntero por buscardato
    this->setNombre(tmp->getNombre());
    this->setTel(tmp->getTel());
    this->setDireccion(tmp->getDireccion());
    this->esHabitual(tmp->esHabitual());
    this->setDescuento(tmp->getDescuento());
    return 0;
  }
  else
    return -1;
}
void Cliente::setNit(char * str){
  if ( strlen(str) > 0 && strlen(str) <= 15){
    strcpy(nit,str);
    esValido(true);
  }
  else    {
    strcpy(nit,"invalido");
    esValido(false);
    }
}
char * Cliente::getNit(){
  return this->nit;
}
void Cliente::setHabitual(char * cadena){
  if (cadena[0] == 'H' || cadena[0] == 'h'){
    esHabitual(true);
  }
  else if (cadena[0] == 'E' || cadena[0] == 'e'){
    esHabitual(false);
  }
  else
    esValido(false);
}
int Cliente::listarClientes(Reporte& salida){
  char mensaje[512];
  int i = 0;
  //  Fecha tmpf;
  in = fopen(nombreArchivo,"rb");
  if(in!=NULL){
    salida.escribir("Listado de Clientes");
    salida.escribirReporte("==========================\n");
    while(!feof(in)){
      fread(tmp,sizeof(Cliente),1,in);
      if(tmp->esHabitual() == true && !feof(in)){	
	//	tmpf = tmp->getFechaN();
	if (i == 0){
	  salida.escribirReporte("Clientes Habituales:");
	  salida.escribirReporte("Nit\t\tNombre\t\tDireccion\t\t\tTelefono\tFecha de Nacimiento");}
	sprintf(mensaje,"%s\t%s\t%s\t%s\t%s",tmp->getNit(),
		tmp->getNombre(),tmp->getDireccion(),
		tmp->getTel(),tmp->getFechaN());
	salida.escribirReporte(mensaje);
	i++;
      }
    }
    i = 0;
    rewind(in);
    salida.escribirReporte("------------------------------------------");
    while(!feof(in)){
      fread(tmp,sizeof(Cliente),1,in);
      if(tmp->esHabitual() == false && !feof(in)){	
	//tmpf = (tmp->getFechaN());
	if (i == 0){
	  salida.escribirReporte("Clientes Esporadicos:");
	  salida.escribirReporte("Nit\t\tNombre\t\tDireccion\t\t\tTelefono\tFecha de Nacimiento");}
	sprintf(mensaje,"%s\t%s\t%s\t%s\t%s",tmp->getNit(),
		tmp->getNombre(),tmp->getDireccion(),
		tmp->getTel(),tmp->getFechaN());
	salida.escribirReporte(mensaje);
	i++;
      }
    }
    fclose(in);
    return 0;
  }
  else
    return -1;
}
/*************************fin Cliente*************************/
/*************************Promo*************************/
Promo::Promo() : Dato(){
  setNombreArchivo("promo.mot");
  esObjetoInterno(false);
  tmp = new Promo(true);
  //  tmp = new Promo(true);
}
Promo::Promo(bool valor) : Dato(valor){
  this->setNombreArchivo("promo.mot");
}
Promo::~Promo(){
  if (this->objetoInterno == false){
    free(tmp);
  }
}
int Promo::guardarDato(){
  long pos = 0;
  if((pos=buscarDatoFecha())>=0){ // si busqueda return >=0
    return 1/*actualizarDato(this,sizeof(*this),pos)*/; //actualiza
  }
  else{ // sino crea
    return nuevoDato(this,sizeof(*this));
  }
}
long Promo::buscarDato(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if(tmp->getID() == getID()){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}
long Promo::buscarDatoFecha(){ // busca por intervalo de fecha si aplica promo
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if((fechaInicio >= tmp->getFechaInicio())
	 &&
	 (fechaInicio <= tmp->getFechaFin())){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}

int Promo::leerDato(){
  return 0;
}
void Promo::setFechaInicio(Fecha f){
  fechaInicio = f;
}
void Promo::setFechaFin(Fecha f){
  fechaFin = f;
}
void Promo::setDescuento(int valor){
  if (valor >=0 && valor <=100){ // permite solo valores porcentuales
    descuento = valor;
    this->esValido(true);
  }
  else{
    descuento = false;
    this->esValido(false);
  }
}
int Promo::getDescuento(){
  return descuento;
}
Fecha Promo::getFechaInicio(){
  return fechaInicio;
}
Fecha Promo::getFechaFin(){
  return fechaFin;
}

/*************************fin Promo*************************/
/*************************Actividad*************************/
Actividad::Actividad() : Dato(){
  setNombreArchivo("activity.mot");
  esObjetoInterno(false);
  tmp = new Actividad(true);
}
Actividad::Actividad(bool valor) : Dato(valor){
  this->setNombreArchivo("activity.mot");
}
Actividad::~Actividad(){
  if (this->objetoInterno == false){
    free(tmp);
  }
}
int Actividad::guardarDato(){
  long pos = 0;
  if((pos=buscarDato())>=0){ // si busqueda return >=0
    return 1;//actualizarDato(this,sizeof(*this),pos); //actualiza
  }
  else{ // sino crea
    return nuevoDato(this,sizeof(*this));
  }
}
long Actividad::buscarDato(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if(tmp->getID() == getID()){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}

int Actividad::leerDato(){
  return 0;
}
/*************************fin Actividad*************************/
/*************************Reservacion*************************/
Reservacion::Reservacion() : Dato(){
  setNombreArchivo("reserv.mot");
  esObjetoInterno(false);
  tmp = new Reservacion(true);
}
Reservacion::Reservacion(bool val) : Dato(val){
  this->setNombreArchivo("reserv.mot");
}
Reservacion::~Reservacion(){
  if (this->objetoInterno == false){
    free(tmp);
  }
}
int Reservacion::guardarDato(){
  long pos = 0;
  // busca si la instalacion no se encuentra reservada a la fecha
  if((pos=buscarDatoFecha())>=0){ // si busqueda return >=0
   return 1; //No hace nada ya que esta reservada la instalacion
  }
  else{ // sino crea
    asignarDescuento();
    return nuevoDato(this,sizeof(*this));
  }
}
long Reservacion::buscarDato(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if(strcasecmp(tmp->getNit(),getNit())==0 && 
	 tmp->getInstalacion() == getInstalacion() &&
	 tmp->getFechaInicial() == getFechaInicial()){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}
long Reservacion::buscarDatoFecha(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if(tmp->getInstalacion() == getInstalacion() &&
	 (fechaInicial >= tmp->getFechaInicial())
	 &&
	 (fechaInicial < tmp->getFechaFinal())){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;
}
long Reservacion::buscarDatoId(){
  long i = 0;
  bool encontrado = false;
  in = fopen(nombreArchivo,"rb");
  // Busca dato si exsite
  if(in !=NULL){
    while(!feof(in) && !encontrado){
      fread(tmp,sizeof(*this),1,in);
      if(tmp->getID() == getID()){
	encontrado = true;
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
  if (encontrado)
    return i;
  else
    return -1;

}
int Reservacion::leerDato(char * idnit, int inst, Fecha fecha){
  this->setNit(idnit); // asigna datos a buscar
  this->setInstalacion(inst); 
  this->setFechaInicial(fecha);
  if (this->esValido()) // si no hay error al asignar
    if (this->buscarDatoFecha() >-1) // y si esta reservado
      return 0; // es valida la reservacion;
    else // sino
      return -1; //es invalida
  else
    return -2;
}

void Reservacion::setInstalacion(int n){
  // si no funciona con punteros usar datos estaticos
  int existe = -1;
  tmpInst = new Instalacion(); // crea puntero
  tmpInst->setID(n); // asigna id
  existe = tmpInst->buscarDato(); // busca si exsite instalacion
  if (existe > -1){
    this->instalacion = n; //si existe asigna
    instal.leerDato(n); // asigna propiedades al objeto interno
    this->setTipoInstalacion(instal.getTipoInstalacion()); // asigna tipo de instalacion a reservacion

    //    this->tipoInstalacion = instal.getTipoInstalacion();
  }
  else{
    this->instalacion = 0; //sino desvalida el dato
    this->esValido(false); 
  }
  delete tmpInst;
}
void Reservacion::setNit(char* n){
  int existe = -1;
  tmpCliente = new Cliente(); // crea puntero
  tmpCliente->setNit(n); // asigna id
  existe = tmpCliente->buscarDato(); // busca si exsite instalacion
  if (existe > -1){
    strcpy(this->nit,n);//si existe asigna
    cliente.leerDato(n); //asigna a objego agregado cliente sus propiedades
  }
    //this->nit = n; 
  else{
    this->nit[0] = 0; //sino desvalida el dato
    this->esValido(false); 
  }
  delete tmpCliente;
}
void Reservacion::setFechaInicial(Fecha f){
  fechaInicial = f;
}
void Reservacion::setNumDias(int dias){
  fechaFinal = fechaInicial;
  fechaFinal + dias;
}
void Reservacion::setFechaFinal(Fecha f){
  fechaFinal = f;
}
void Reservacion::setTipoActividad(int n){
  int existe = -1;
  if (n > 0){
    tmpActividad = new Actividad(); // crea puntero
    tmpActividad->setID(n); // asigna id
    existe = tmpActividad->buscarDato(); // busca si exsite instalacion
    if (existe > -1)
      this->actividad = n; //si existe asigna
    else{
      this->actividad = 0; //sino desvalida el dato
      this->esValido(false); 
    }
    delete tmpActividad;
  }
  else
    this->actividad = 0;
}
int Reservacion::getInstalacion(){
  return (this->instalacion);
}
char * Reservacion::getNit(){
  return (this->nit);
}
Fecha Reservacion::getFechaInicial(){
  return (this->fechaInicial);
}
Fecha Reservacion::getFechaFinal(){
  return (this->fechaFinal);
}
int Reservacion::extender(){
  long pos;
  if (diasExt > 0){
    if((pos = buscarDatoId()) >=0){
      //this->setfechaInicial(tmp->getfechaInicial());
      //this->setfechaFinal(tmp->getfechaFinal());
      this->fechaFinal + diasExt; // suma dias extendidos a fecha final
      tmp->setFechaFinal(this->fechaFinal); // asigna fecha final extendida a puntero
      return actualizarDato(tmp,sizeof(*this),pos); //guarda datos de puntero reasignado
    }
    else
      return -1;
  }
  else{
    return -2;
  }
}
int Reservacion::eliminar(){
  int pos = buscarDato();
  if (pos > -1){
    this->setID(0);
    this->nit[0] = 0;
    esValido(true);
    if(actualizarDato(this,sizeof(*this),pos) == 1)
      return 0;
    else
      return -1;
  }
  else
    return -1;
}
void Reservacion::asignarDescuento(){
  Promo promo;
  promo.setFechaInicio(this->fechaInicial); // inicialeza el objeto
  if ((promo.buscarDatoFecha()) > -1) // si la fecha es festiva
    this->aplicaDescuento = true; //aplica descuento
  else
    this->aplicaDescuento = false;
  //  delete promo;
}
void Reservacion::setDiasExt(int n){
  diasExt = n;
}
int Reservacion::getDiasExt(){
  return diasExt;
}
int Reservacion::disponibilidad(Reporte& reporte){
#ifdef debug
  strcpy(archTmpInst,"tmpinst.mot"); // asigna nombre de archivo a temporal
#else
  strcpy(archTmpInst,"c:\\tmpinst.mot");
#endif
  if (this->abrirArchivoInst() == 0){
    this->generarReporteDisp(reporte);
    this->borrarTmpFiles();
    return 0;
  }
  else
    return -1;
}
int Reservacion::abrirArchivoInst(){
  FILE *file, *out;
  tmpInst = new Instalacion(true);
  if((file = fopen(tmpInst->getNombreArchivo(),"r+b"))!=NULL){
    out = fopen(archTmpInst,"a+b");
    while(!feof(file)){
      fread(tmpInst,sizeof(Instalacion),1,file); // lee dato
      this->instalacion = tmpInst->getID()/*setInstalacion(tmp->getID())*/;
      // si no se encuentra dato que coincida con la fecha escribir
      if ((this->buscarDatoFecha() < 0) && !feof(file)){
	fwrite(tmpInst,sizeof(Instalacion),1,out);
      }
    }
    fclose(file);
    fclose(out);
    tmpInst->esObjetoInterno(true);
    //delete this->tmpInst;
    free(this->tmpInst);
    return 0;
  }
  else{
    //    delete this->tmpInst;
    free(this->tmpInst);
    return -1;
  }
}
void Reservacion::generarReporteDisp(Reporte& reporte){
  FILE * file;
  int j = 0;
  //Instalacion instal;//(true);
  tmpInst = new Instalacion(true);
  char mensaje[255];
  sprintf(mensaje,"- Instalaciones Disponibles a la fecha %s",fechaInicial.toString());
  reporte.escribir(mensaje);
  reporte.escribirReporte("  ==================================================");
  if((file = fopen(archTmpInst,"rb"))!=NULL){
    for(int i=1; i<=10; i++){
      rewind(file); 
      j = 0;
      if(!feof(file)){
	while(!feof(file)){
	  fread(/*&instal*/tmpInst,sizeof(Instalacion),1,file);
	  if(/*instal.*/tmpInst->getUbicacion() == i && !feof(file)) { // si ubicacion es igual al subindice
	    if (j==0){
	      reporte.escribirReporte(/*instal.*/tmpInst->getStrNivel()); // escribe No de nivel
	      reporte.escribirReporte("------------------");
	    }
	    reporte.escribirReporte(/*instal.*/tmpInst->getNombre()); // escribe en reporte la instalacion leida
	    j++;
	    reporte.escribirReporte("");
	  }
	}
      }
    }
    fclose(file);
    reporte.escribirReporte("");
  }
  else
    reporte.escribir("No existen datos");
  tmpInst->esObjetoInterno(true);
  //  delete tmpInst;
  free(this->tmpInst);
  //   delete instal;
}

void Reservacion::borrarTmpFiles(){
  FILE * out;
  if((out = fopen(archTmpInst,"r+b"))!=NULL){
    freopen(archTmpInst,"wb",out);
    fwrite(0,0,1,out);
    fclose(out);
  }
}
//void Reservacion::setTipoInstalacion(int r){
//  this->tipoInstalacion = r;
//}
//int Reservacion::getTipoInstalacion(){
//  return (this->tipoInstalacion);
//}

char * Reservacion::getNombreCliente(){
  return (this->cliente.getNombre());
}

void Reservacion::generarListaReservacion(Reporte& salida){
  long i = 0;
  char mensaje[512];
  in = fopen(nombreArchivo,"rb");
  Fecha fecha1;
  Fecha fecha2;
  salida.escribir("Lista de reservaciones");
  salida.escribirReporte("======================");
  // Busca dato si exsite
  if(in !=NULL){
  salida.escribirReporte("No. Instal Nit\t\tNombre Cliente\t\tReservada Desde...\t...Hasta");
  salida.escribirReporte("---------- ---\t\t--------------\t\t------------------\t--------");
    while(!feof(in) && i<64){
      fread(tmp,sizeof(*this),1,in);
      if(tmp->getTipoInstalacion() == (this->tipoInstalacion)
	 && !feof(in)){
	fecha1 = tmp->getFechaInicial();
	fecha2 = tmp->getFechaFinal();
	sprintf(mensaje,"%d\t%s\t%s\t\t%s\t%s\t",
		tmp->getTipoInstalacion(),
		tmp->getNit(),
		tmp->getNombreCliente(),
		fecha1.toString(),fecha2.toString());
	salida.escribirReporte(mensaje);
      }
      else
	i++;
    }
    fclose(in);
    }
  tmp->esObjetoInterno(true); // Reasigna a tmp como objeto interno
  // Devuelve posicion si existe
}
/*************************Fin Reservacion*************************/
/*************************Consumo****************************/
Consumo::Consumo() : Dato(){
  setNombreArchivo("consumo.mot");
  esObjetoInterno(false);
  tmp = new Consumo(false);
}
Consumo::Consumo(bool valor) : Dato(valor){
  this->setNombreArchivo("consumo.mot");
}
Consumo::~Consumo(){
  if (this->objetoInterno == false){
    free(tmp);
  }
}
void Consumo::setInstalacionR(int n){
  //  instalR.setID(n);
  if (instalR.leerDato(n) != 0)
    esValido(false);
}
void Consumo::setInstalacionC(int n){
  //  instalC.setID(n);
  if (instalC.leerDato(n) != 0)
    esValido(false);
}
void Consumo::setNit(char * pNit){
  //  cliente.setNit(pNit);
  if (cliente.leerDato(pNit) !=0)
    esValido(false);
}
char* Consumo::getNit(){
  return (cliente.getNit());
}
void Consumo::setMonto(float f){
  this->monto = f;
}
void Consumo::setFecha(Fecha f){
  this->fecha = f;
}
int Consumo::asignarReservacion(){
  if(reservacion.leerDato(cliente.getNit(),instalR.getID(),fecha) == 0){
    return 0;
  }
  else{
    esValido(false);
    return -1;
  }
}
int Consumo::guardarDato(){
  if(asignarReservacion() != 0)
    return -1;
  else
    return nuevoDato(this,sizeof(*this));
}
long Consumo::buscarDato(){
  return 0;
}
int Consumo::leerDato(){
  return 0;
}
char * Consumo::getNombreInstalR(){
  return instalR.getNombre();
}
char * Consumo::getNombreInstalC(){
  return instalC.getNombre();
}
char * Consumo::getNombreCliente(){
  return cliente.getNombre();
}
float Consumo::getMonto(){
  return monto;
}
Fecha Consumo::getFecha(){
  return this->fecha;
}
int Consumo::getIDinstalR(){
  return instalR.getID();
}
float Consumo::getPrecioInstalR(){
  return instalR.getPrecio();
}
int Consumo::calcularGastoReservacion(Reporte& salida){
  float consumo = 0,desc = 0,total= 0;
  char mensaje[512];
  bool encontrado = false;
  Fecha tmpFecha;
  mensaje[0] = 0;
  in = fopen(nombreArchivo,"rb");
  salida.escribir("Reporte de gastos de reservacion:");
  salida.escribirReporte("================================");
  salida.escribirReporte("");
  salida.escribirReporte("Fecha\t\t\tConsumo\t\tDescuento\tSubtotal");
  salida.escribirReporte("-----\t\t\t-------\t\t---------\t-------");
  if (in!=NULL){
    while(!feof(in)){
      fread(tmp,sizeof(*tmp),1,in);
      tmpFecha = tmp->getFecha();
      if (strcasecmp(this->getNit(),tmp->getNit()) == 0 &&
	  instalR.getID() == tmp->getIDinstalR() &&
	  tmpFecha <= this->fecha && !feof(in)){
	consumo = tmp->getMonto();
	desc = (getDescuento(fecha)*consumo)/100;
	total += (consumo - desc);
	sprintf(mensaje,"%s\t\t%0.2f\t\t%0.2f\t\t%0.2f",
		tmpFecha.toString(),consumo,desc,total);
	salida.escribirReporte(mensaje);
	encontrado = true;
	  	
      }
    }
    fclose(in);
    if (encontrado){
      precioInst = tmp->getPrecioInstalR();
      desc = getDescuento(fecha) * precioInst / 100;
      total = precioInst - desc;
      sprintf(mensaje,"El precio de la instalacion es %0.2f, con descuento de %0.2f,\n El total es: %0.2f",
	      precioInst,desc,total);
      salida.escribirReporte(mensaje);
      return 0;
    }
    else
      return -1;
  }
  else
    return -1;
  return 0;
}

float Consumo::getDescuento(Fecha f){
  Promo promo;
  promo.setFechaInicio(f);
  if (cliente.esHabitual() == true){
    if (promo.buscarDatoFecha()>=1)
      return promo.getDescuento();
    else
      return 0;
  }
  else
    return 0;
}

/*************************fin Consumo*************************/
/*************************Fecha*************************/
Fecha::Fecha(){
  dia = 0;
  mes = 0;
  anio = 0;
}
Fecha::Fecha(int d, int m, int a){
  dia = d;
  mes = m;
  anio = a;
}
void Fecha::setDia(int d){
  dia = d;
}

void Fecha::setMes(int m){
  mes = m;
}
void Fecha::setAnio(int a){
  anio = a;
}
int Fecha::getDia(){
  return dia;
}
int Fecha::getMes(){
  return mes;
}
int Fecha::getAnio(){
  return anio;
}
bool Fecha::operator>=(Fecha f){
  if ((*this)>f || (*this)==f)
    return true;
  else
    return false;
}
bool Fecha::operator<=(Fecha f){
  if ((*this)<f || (*this)==f)
    return true;
  else
    return false;
}

bool Fecha::operator>(Fecha f ){
  if(anio < f.anio)
    return false;
  else if (anio > f.anio)
    return true;
  else
    if (mes < f.mes)
      return false;
    else if (mes > f.mes)
      return true;
    else
      if (dia <= f.dia)
	return false;
      else
	return true;
}
bool Fecha::operator<(Fecha f ){
  if(anio < f.anio)
    return true;
  else if (anio > f.anio)
    return false;
  else
    if (mes < f.mes)
      return true;
    else if (mes > f.mes)
      return false;
    else
      if (dia < f.dia)
	return true;
      else
	return false;
}
bool Fecha::operator==(Fecha f){
  if (f.dia == dia && f.mes == mes && f.anio == anio)
    return true;
  else
    return false;
}
void Fecha::operator+(int dd){
  for(int i = 0;i<dd;i++)
    sumarDia();
}
bool Fecha::esBisiesto(){
  if ((anio%4) == 0)
    return true;
  else return false;
}
void Fecha::sumarAnio(){
  anio++;
}
void Fecha::sumarMes(){
  if (mes>=12){
    sumarAnio();
    mes = 1;
  }
  else
    mes++;
}
void Fecha::sumarDia(){
  if(dia >= 31){ // para meses que terminan con 31 dias
    if(mes ==1 || mes == 3 || mes == 5 || 
       mes ==7 || mes == 8 || mes == 10 || mes == 12){
      sumarMes();
      dia = 1;
    }
    else if(mes == 12){
      sumarAnio();
      mes = 1;
      dia = 0;
    }
  }
  else if(dia == 30){ // para meses que terminan con 30 dias
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
      sumarMes();
      dia = 1;
    }
    else
      dia++;
  }
  else if(dia == 29){ // para febrero
    if (esBisiesto() && mes==2){
      sumarMes(); 
      dia = 1;
    }
    else
      dia++;
  }
  else if(dia == 28){ // para febrero
    if (!esBisiesto() && mes==2){
      sumarMes();
      dia = 1;
    }
    else
      dia++;
  }     
  else
    dia++;
}
void Fecha::operator=(Fecha f){
  this->dia = f.dia;
  this->mes = f.mes;
  this->anio = f.anio;
}
char * Fecha::toString(){
  sprintf(this->fechaStr,"%d/%d/%d",this->dia,this->mes,this->anio);
  return fechaStr;
}
/*************************Fin Fecha**********************/
/*************************Parser*************************/
Parser::Parser(){
  //  inst.
}
int Parser::setArchSalida(char * path){
  if (path!=NULL){
    strcpy(pathSalida,path);
    salida.setPathSalida(pathSalida);
    return 0;
  }
  else
    return -1;
}

int Parser::setArchEntrada(char * path){
  if (path!=NULL){
    strcpy(pathEntrada,path);
    return 0;
  }
  else
    return -1;
}
int Parser::leerEntero(){
  if (estado == E_num)
    if ((isdigit(lexema[0]))!=0){
      return atoi(lexema);
    }
    else
      return -1;
  else
    return -1; // si no es caracter devuelve tamano int negativo
}
float Parser::leerFloat(){
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
char * Parser::leerCadena(){
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
}
int Parser::leerFecha(Fecha& f){
  int i=0;
  int dato[3];
  bool salir, error;
  salir = error = false;
  if (lexema[0] == STRDELIM){
    Token(1);
    while (i<3 && !salir){
      if (estado == E_num && i<3){ 
	dato[i] = atoi(lexema);
	if (i<2)
	  Token(1);
	i++;
      }
      else if((lexema[0] == '/') && i<3)
	Token(1);
      else
	if(i == 3){
	  salir = true;
	}
	else{
	  salir = true;
	  error = true;
	}
    }
  }
  if (!error){
    f.setDia(dato[0]);
    f.setMes(dato[1]);
    f.setAnio(dato[2]);
    Token(1); // CUIDADO CON ESTO, PUEDE DESGRACIAR TODO
    return 0;
  }
  else
    return -1;
}
int Parser::calcularGastoReservacion(){
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
	    consumo.setNit(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==1){
	  if ((entero = leerEntero())!=-1){
	    consumo.setInstalacionR(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i == 2){
	  if( leerFecha(fecha)!=-1){
	    consumo.setFecha(fecha);
	  }
	  else{
	    salida.escribirError("Fecha invalida");
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

int Parser::listarReservaciones(){
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
	    reservacion.setTipoInstalacion(entero);
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

int Parser::instalacionesDisp(){
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
	  if( leerFecha(fecha)!=-1){
	    reservacion.setFechaInicial(fecha);
	  }
	  else{
	    salida.escribirError("Fecha invalida");
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

int Parser::consultarPrecio(){
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
	    inst.setID(entero);
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

int Parser::cambiarDescuento(){
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
	    errnum += cliente.setDescuento(entero);
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

int Parser::asignarConsumo(){
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
	    consumo.setInstalacionR(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if ((entero = leerEntero())!=-1){
	    consumo.setInstalacionC(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}

	else if (i==2){
	  if( leerCadena()!=NULL){
	    consumo.setNit(cadena);
	  }
	  else {
	    errnum++;
	  }
	}
	else if (i==3){
	  if ((flotante = leerFloat())!=-1){
	    consumo.setMonto(flotante);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i == 4){
	  if( leerFecha(fecha)!=-1){
	    consumo.setFecha(fecha);
	  }
	  else{
	    salida.escribirError("Fecha invalida");
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
int Parser::eliminarReservacion(){
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
	    reservacion.setInstalacion(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena()!=NULL){
	    reservacion.setNit(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i == 2){
	  if( leerFecha(fecha)!=-1){
	    reservacion.setFechaInicial(fecha);
	  }
	  else{
	    salida.escribirError("Fecha invalida");
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
int Parser::extenderReservacion(){
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
	    reservacion.setID(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if ((entero = leerEntero())!=-1){
	    reservacion.setDiasExt(entero);
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

int Parser::reservar(){
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
	    reservacion.setID(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if ((entero = leerEntero())!=-1){
	    reservacion.setInstalacion(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==2){
	  if( leerCadena()!=NULL){
	    reservacion.setNit(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i ==3){
	  if( leerFecha(fecha)!=-1){
	    reservacion.setFechaInicial(fecha);
	  }
	  else{
	    salida.escribirError("Fecha invalida");
	    errnum++;
	  }
	}
	else if (i==4){
	  if ((entero = leerEntero())!=-1){
	    reservacion.setNumDias(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i== 5){
	  if ((entero = leerEntero())!=-1){
	    reservacion.setTipoActividad(entero);
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

int Parser::crearActividad(){
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
	    actividad.setID(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if ((entero = leerEntero())!=-1){
	    actividad.setTipoInstalacion(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i == 2){
	  if( leerCadena()!=NULL){
	    actividad.setNombre(cadena);
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

int Parser::crearPromo(){
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
	    promo.setID(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if( leerCadena()!=NULL){
	    promo.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i == 2){
	  if( leerFecha(fecha)!=-1){
	    promo.setFechaInicio(fecha);
	  }
	  else{
	    salida.escribirError("Fecha invalida");
	    errnum++;
	  }
	}
	else if (i==3){
	  if( leerFecha(fecha)!=-1){
	    promo.setFechaFin(fecha);
	  }
	  else {
	    salida.escribirError("Fecha invalida");
	    errnum++;
	  }
	}
	else if (i== 4){
	  if ((entero = leerEntero())!=-1){
	    promo.setTipoInstalacion(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==5){
	  if ((entero = leerEntero())!=-1){
	    promo.setDescuento(entero);
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

int Parser::agregarCliente(){
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

int Parser::agregarInstalacion(){
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
	    inst.setID(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==1){
	  if ((entero = leerEntero())!=-1){
	    inst.setTipoInstalacion(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i == 2){
	  if( leerCadena()!=NULL){
	    inst.setNombre(cadena);
	  }
	  else 
	    errnum++;
	}
	else if (i==3){
	  if ((entero = leerEntero())!=-1){
	    inst.setCapacidad(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i== 4){
	  if ((flotante = leerFloat())!=-1){
	    inst.setPrecio(flotante);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i==5){
	  if ((entero = leerEntero())!=-1){
	    inst.setUbicacion(entero);
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

int Parser::crearInstalacion(){
  int errnum = 0, i = 0;bool salir = false;
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0 && !salir){
      Token(1);
      if (estado == E_coma){
	i++;
      }
      else if (estado == E_parC){
	i++;
	//salir = true;
      }
      else{
	if (i==0){
	  if ((entero = leerEntero())!=-1){
	    tipoInst.setID(entero);
	  }
	  else {
	    salida.escribirError("Valor debe ser numerico");
	    errnum++;
	  }
	}
	else if (i == 1){
	  if( leerCadena()!=NULL){
	    tipoInst.setNombre(cadena);
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

int Parser::parse(){
  char mensaje[255]; // temporal
  int salir = 0;
  int ret = 0;
  salida.limpiar(); // limpia archivo de salida
  if(!abre_arch(pathEntrada)) {
    return -1;
  }
  else {
    while(!feof(file_in) && salir<32000){
      Token(1);
      switch(estado){
      case 41:
	Token(1);
	//	salida.escribir("Instruccion crear Tipo Instalacion");
	if(crearInstalacion() == 0){
	  ret = tipoInst.guardarDato();
	  if(ret == 0)
	    sprintf(mensaje,"(+) Se Creo satisfactoriamente la instalacion %s con codigo %d ",
		    tipoInst.getNombre(),tipoInst.getID());
	  else if(ret == 1)
	    sprintf(mensaje,"(!) ERROR: El tipo de Instalacion ya existe");
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 42:
	Token(1);
	//	salida.escribir("Instruccion Agregar Instalacion");
	if(agregarInstalacion() == 0){
	  ret = inst.guardarDato();
	  if (ret ==0)
	    if (inst.getPrecio()==0)
	    sprintf(mensaje,"(+) Se creo %s con No instalacion %d con capacidad de %d ubicada en el nivel %d",
		    inst.getNombre(),inst.getID(),inst.getCapacidad(),inst.getNivel());
	    else
	    sprintf(mensaje,"(+) Se creo %s con No instalacion %d con capacidad de %d, tiene el precio de %f, ubicada en el nivel %d",
		    inst.getNombre(),inst.getID(),inst.getCapacidad(),inst.getPrecio(),inst.getNivel());
	  else if (ret == 1){
	    sprintf(mensaje,"(!) ERROR: El No. de la Instalacion ya existe");
	  }
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	  salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 43:
	Token(1);
	//	salida.escribir("Instruccion Agregar Cliente");
	if (agregarCliente() == 0){
	  ret = cliente.guardarDato();
	  if (ret ==0)
	    sprintf(mensaje,"(+) Se Agrego el cliente %s con NIT %s,\n que vive en %s con tel # %s",
		    cliente.getNombre(),cliente.getNit(),cliente.getDireccion(),cliente.getTel());
	  else if (ret == 1){
	    sprintf(mensaje,"(*) Se Actualizo el cliente %s con NIT %s",
		    cliente.getNombre(),cliente.getNit());
	  }
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	  if (ret == 0 || ret == 1){
	    strcat(mensaje,"quien es un Cliente ");
	    if (cliente.esHabitual())
	      strcat(mensaje,"Habitual");
	    else
	      strcat(mensaje,"Esporadico");
	  }
	  salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 44:
	Token(1);
	//	salida.escribir("Instruccion Crear Promocion");
	if (crearPromo() ==0){
	  ret = promo.guardarDato();
	  if (ret == 0)
	    sprintf(mensaje,"(+) Se Agrego la promocion %s con ID %d",
		    promo.getNombre(),promo.getID());
	  else if (ret == 1){
	    sprintf(mensaje,"(!) ERROR Ya existe una promocion dentro de esta fecha en esta instalacion");
	  }
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	  salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 45:
	Token(1);
	//	salida.escribir("Instruccion Crear Actividad");
	if (crearActividad() == 0){
	  ret = actividad.guardarDato();
	  if (ret == 0)
	    sprintf(mensaje,"(+) Se creo la actividad %s con ID %d",
		    actividad.getNombre(),actividad.getID());
	  else if (ret == 1){
	    sprintf(mensaje,"(!) ERROR: la actividad con Id %d ya existe",
		    actividad.getID());
	  }
	  else
	    sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	  salida.escribir(mensaje);
	}
	else
	  salida.escribirError("(!) Se encontraron 1 o mas errores, la instruccion actual sera ignorada");
	break;
      case 46:
	Token(1);
	//	salida.escribir("Instruccion Hacer Reservacion");
	if (reservar() == 0){
	  ret = reservacion.guardarDato();
	  if (ret == 0)
	    sprintf(mensaje,"(+) Se Agrego la reservacion para cliente con nit %s \nen la instalacion %d",
		    reservacion.getNit(),reservacion.getInstalacion());
	  else if (ret == 1){
	    sprintf(mensaje,"(?) ERROR: No se puede reservar para cliente con nit %s \nen la instalacion %d por que ya se esta reservada",
		    reservacion.getNit(),reservacion.getInstalacion());
	  }
	  else
	    sprintf(mensaje,"(!) ERROR: Imposible Guardar, los parametros no son logicamente validos");
	  //	  salida.escribir("OK");
	}
	else
	  sprintf(mensaje,"(!) Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	break;
      case 47:
	Token(1);
	//	salida.escribir("Instruccion Extender Reservacion");
	if (extenderReservacion() == 0){
	  ret = reservacion.extender();
	  if (ret == 1)
	    sprintf(mensaje,"(++) Se Extendio la reservacion con ID %d \n a %d dias mas",
		    reservacion.getID(),reservacion.getDiasExt());
	  else if (ret == -1){
	    sprintf(mensaje,"(?) ERROR: No se puede reservar para cliente con nit %s \nen la instalacion %d por que ya se esta reservada",
		    reservacion.getNit(),reservacion.getInstalacion());
	  }
	  else
	    sprintf(mensaje,"(!) ERROR: Imposible Guardar, los parametros no son logicamente validos");
	}
	salida.escribir(mensaje);
	break;
      case 48:
	Token(1);
	//	salida.escribir("Instruccion Eliminar Reservacion");
	if (eliminarReservacion() == 0){
	  ret = reservacion.eliminar();
	  if (ret == 0)
	    sprintf(mensaje,"(-) Se elimino la reservacion para cliente con nit %d en la instalacion %d",
		    entero,reservacion.getInstalacion());
	  else if (ret == 1){
	    sprintf(mensaje,"(?)ERROR: No se puede eliminar reservacion, no existe Fecha \no no es valida la instalacion/nit");
	  }
	  else
 	    sprintf(mensaje,"(!)ERROR: No se puede eliminar reservacion, no existe Fecha \no no es valida la instalacion/nit");
	  //	  salida.escribir("OK");
	}
	else
	  sprintf(mensaje,"(!)ERROR: Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	break;
      case 49:
	Token(1);
	//	salida.escribir("Instruccion Asignar Consumo AYB");
	if(asignarConsumo()==0){
	  consumo.esValido(true);
	  ret = consumo.guardarDato();
	  if (ret == 0)
	    sprintf(mensaje,"(+) El cliente %s tiene reservada la instalacion %s \n y ha consumido Q %f en %s",
		    consumo.getNombreCliente(),consumo.getNombreInstalR(),consumo.getMonto(),consumo.getNombreInstalC());
	  else
 	    sprintf(mensaje,"(!)ERROR: No se asignar consumo, parametros invalidos o reservacion no existe");
	}
	else
	  sprintf(mensaje,"(!)ERROR: Imposible Guardar, los parametros no son logicamente validos");
	salida.escribir(mensaje);
	break;
      case 50:
	Token(1);
	//	salida.escribir("Instruccion Cambiar Descuento");
	if (cambiarDescuento() == 0){
	   sprintf(mensaje,"(*) Se ha cambiado el descuento a los clientes habituales  un %d por ciento",
		    cliente.getDescuento());
	}
	else
	  sprintf(mensaje,"(!)ERROR: Imposible cambiar descuento, debe introducir un valor entre entre 0 y 100");
	salida.escribir(mensaje);
	break;
      case 51:
	Token(1);
	//	salida.escribir("Instruccion Consultar Descuento");
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
	  sprintf(mensaje,"(#) El descuento a los clientes habituales es de %d por ciento",
		  cliente.getDescuento());
	}
	else
	  sprintf(mensaje,"(!)ERROR: Sintaxis incorrecta");
	salida.escribir(mensaje);
	break;
      case 52:
	Token(1);
	//salida.escribir("Instruccion Consultar Precio");
	if(consultarPrecio() == 0){
	  ret = inst.consultarPrecio();
	  if (ret == 0)
	    sprintf(mensaje,"(+) El precio de la instalacion %s(# de habitacion %d) ubicada en %s es de US$ %4.2f",
		    inst.getNombre(),inst.getID(),inst.getStrNivel(),inst.getPrecio());
	  else
 	    sprintf(mensaje,"(!)ERROR: Instalacion no existe");
	}
	else
	  sprintf(mensaje,"(!)ERROR: Sintaxis invalida");
	salida.escribir(mensaje);
	break;
      case 53:
	Token(1);
	//	salida.escribir("Instruccion Instalaciones Disponibles");
	if(instalacionesDisp()==0){
	  ret = reservacion.disponibilidad(salida);
	  if (ret == 0){
	    //  sprintf(mensaje,"(_/\\_) Dato procesado correctamente ");
	    //	    salida.escribir(mensaje);
	  }
	  else {
 	    sprintf(mensaje,"(!)ERROR: Error semantico");
	    salida.escribir(mensaje);
	  }
	}
	else{
	  sprintf(mensaje,"(!)ERROR: Imposible procesar, los parametros no son logicamente validos");
	  salida.escribir(mensaje);
	}
	break;
      case 54:
	Token(1);
	//salida.escribir("Instruccion Listar Clientes");
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
	  cliente.listarClientes(salida);
	}
	else
	  salida.escribir("(!)ERROR: Sintaxis incorrecta");
	//	salida.escribir(mensaje);
	break;
      case 55:
	Token(1);
	//salida.escribir("Instruccion Listar Reservaciones");
	if(listarReservaciones() == 0){
	  reservacion.generarListaReservacion(salida);
	}
	else
	  sprintf(mensaje,"(!)ERROR: Sintaxis invalida");
	//	salida.escribir(mensaje);
	break;
      case 56:
	Token(1);
	//salida.escribir("Instruccion Calcular Gasto Reserva");
	if(calcularGastoReservacion() == 0){
	  consumo.calcularGastoReservacion(salida);
	}
	else
	  sprintf(mensaje,"(!)ERROR: Sintaxis invalida");
	//	salida.escribir(mensaje);
	break;
	//	salida.escribir(mensaje);
	//	break;
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
/*************************fin Parser*************************/


/***************************Main********************************/
/***************************************************************/
int main(){
  Menu menu; // Crea nueva instancia de Menu
  Parser parser; // Crea nueva instancia de Parser
#ifndef debug
  system("del c:\\*.mot");
#else
  system("rm *.mot");
#endif
  do{
    menu.ejecutar(); // Ejecuta el menu
#ifdef debug
    parser.setArchEntrada("in.txt");
    parser.setArchSalida("salida.txt");
#else
    parser.setArchEntrada(menu.getEntrada()); // Asigna archivo de entrad
    parser.setArchSalida(menu.getSalida()); // Asigna path de salida
#endif
    if (menu.getOpcion() == 3){
      parser.parse();
    }
  }
  while (menu.getOpcion() > 0 && menu.getOpcion() < 4);
  //exit(1);
  return 0;
}

#endif
