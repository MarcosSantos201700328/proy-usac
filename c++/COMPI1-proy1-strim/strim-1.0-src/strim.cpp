#include "strim.hpp"

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

void Reporte::escribirNumLinea(int numlinea){
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
  //  yyout = fopen(pathSalida,"a+b");
  fprintf(yyout,msg);
  //  fclose(yyout);
  //  out.open(pathSalida,ofstream::out | ofstream::app);
  //out << msg << endl;
  //  out.close();
  
}

void Reporte::escribir(char * msg,int numlinea){
  escribirNumLinea(numlinea);
  escribirEnPantalla(msg);
  escribirEnArchivo(msg);
}

void Reporte::escribirError(char * msg,int numlinea){
  //escribirNumLinea();
  escribirEnPantalla("Error: ");
  escribirEnArchivo("Error: ");
  escribir(msg,numlinea);
}
void Reporte::escribirReporte(char* msg){
  escribirEnPantalla(msg);
  escribirEnArchivo(msg);
}
/*************************Fin Reporte*************************/


Strim::Strim(){
  //  inst.
  //  listaCat = new Lista<Categoria>();
}
Strim::~Strim(){
}
int Strim::setArchSalida(char * path){
  if (path!=NULL){
    strcpy(pathSalida,path);
    salida.setPathSalida(pathSalida);
    return 0;
  }
  else
    return -1;
}

int Strim::setArchEntrada(char * path){
  if (path!=NULL){
    strcpy(pathEntrada,path);
    return 0;
  }
  else
    return -1;
}

int Strim::parse(){
  char mensaje[255]; // temporal
  int salir = 0;
  int ret = 0;
  char * retstr;
  salida.limpiar(); // limpia archivo de salida
  //Abre archivos
  yyin = fopen(pathEntrada,"r");
  yyout = fopen(pathSalida,"w+");
  return yyparse(); // Llama al parser
}
/**MAIN
 argumentos:
 "": abre el menu principal de la aplicacion
 "-debug": opciomn
 "<ruta_archiv_entrada> <ruta_archivo_salida>": lee archivo de entrada dado por el pimer parametro y
  escribe en archivo de salida dado por el segundo*/
int main(int argc, char* argv[]){
    Menu menu; // Crea nueva instancia de Menu
    Strim strim; // Crea nueva instancia de Strim
    // muestra menu
    if (argc == 1){
#ifndef debug
      //system("del c:\\*.mot");
#else
      //system("rm *.mot");
#endif
      do{
	menu.ejecutar(); // Ejecuta el menu
#ifdef debug
	strim.setArchEntrada("in.txt");
	strim.setArchSalida("salida.txt");
#else
	strim.setArchEntrada(menu.getEntrada()); // Asigna archivo de entrad
	strim.setArchSalida(menu.getSalida()); // Asigna path de salida
#endif
	if (menu.getOpcion() == 3){
	  strim.parse();
	}
      }
      while (menu.getOpcion() > 0 && menu.getOpcion() < 4);
      //exit(1);
      return 0;
    }
    //sino ejecuta sin menu
    else if (argc >1){
      yyout = stdout;
      if (strcasecmp("-debug",&(argv[1][0])) == 0){
	yyin = stdin;
	return yyparse();
      }
      else  /*if(strcasecmp("-open",&(argv[1][0])))*/{
	//strim.setArchEntrada(argv[1]);
//	strim.setArchSalida(argv[2]);
          if ((yyin = fopen(argv[1],"r"))!=NULL){
             yyout = fopen(argv[2],"w+");
             return yyparse();
          }
       return -1;
	//	yyin = fopen(&(argv[2][0]),"r");

//	return 	strim.parse();
      }
    }
}

