/** @file main.cpp
 * Punto de entrada del programa.*/
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/

#include <qapplication.h>
extern "C"{
#include <string.h>
#include "parserheader.h"
}

#include "godzilla.h"
/**Crea objetos QApplication y GodZilla, y los ejecuta para mostrar interfaz grafica*/
int main( int argc, char ** argv ) {
  //QApplication a( argc, argv );
  QApplication* a;
  GodZilla * mw/* = new GodZilla()*/;
    if(argc ==1){
      a = new QApplication(argc,argv);
      mw = new GodZilla();
      mw->setCaption( "GodZilla" );
      mw->show();
      a->connect( a, SIGNAL(lastWindowClosed()), a, SLOT(quit()) );
      return a->exec();
      //a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
      //return a.exec();
    }
    else if(argc == 4)
    {
      if (inputparse(argv[1],argv[2]) == 0)
	return 0;
      else{
	printf("Se encontraron errores, se generara un XML de errores hacia %s",argv[3]);
	generarSalidaError(argv[3]);
	return 1;
      }
    }      
    else{
      printf("ERROR: Debe ingresar parametros para archivo de entrada(texto), de salida(html), y de salida de error(xml)\n");
      printf("\tEjemplo: $./godzilla input.txt salida.htm errores.xml\n\n");
      printf("Tambien puede ingresar sin ningun paramentro para utilizarlo en modo grafico.\n NOTA: necesitara las librerias de X11 y QT si esta usando sistemas UNIX");
    }
    return 0;
}
