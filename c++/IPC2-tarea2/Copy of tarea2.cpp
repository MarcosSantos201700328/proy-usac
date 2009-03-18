#ifndef debug
#define debug
//#undef debug
#endif
// Inclusion de libreria de Scanner
#include "../scanner.cpp"
//#include <fstream>
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
};

using namespace std;


// LOg:

// -[probar] Carnet estudiante acepta guiones
//


// Registro de datos de Estudiante
typedef struct estudiante{
  long carnet;
  char nombre[64];
  char direccion[128];
  unsigned long telefono;
  long correo;
} ;

// Registro de Datos de Catedratico
typedef struct catedratico{
  long id;
  char nombre[64];
  char direccion[128];
  long correo;
};

// Identificacion sintactica de la instruccion catedratico
void esCated(catedratico &RegCated){

  FILE * out; // archivo de salida

  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores

  // Inicializacion
  RegCated.nombre[0]=0;
  RegCated.direccion[0]=0;

  // Reconocimiento sintactico

  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0){ // mientras no se llegue a ';'
      Token(1);
      
#ifdef debug
      printf("i=%d:\t%s\n",i,lexema);
#endif
      switch (estado){
      case E_num: // si token leido es numero
	(i==0)?(RegCated.id = atol(lexema)):errnum++;
	//(i==3)?(RegCated.telefono = atol(lexema)):errnum++;
	(i==3)?(RegCated.correo= atol(lexema)):errnum++;
	i++;
	break;
      case E_identificador: // si token leido es texto sin apostrofo
	(i==1)?(int)strcpy(RegCated.nombre,lexema):errnum++;
	(i==2)?(int)strcpy(RegCated.direccion,lexema):errnum++;
	i++;
	break;
      case E_apos: // si se lee apostrofo
	Token(1);
	while((estado !=E_apos)) {
	  if (i==1 && estado == E_identificador){
	    strcat(RegCated.nombre,lexema);
	    strcat(RegCated.nombre," ");
	    
	  }
	  else if (i==2 && (estado == E_identificador || estado == E_num)){
	    strcat(RegCated.direccion,lexema);
	    strcat(RegCated.direccion," ");
	    
	  }
	  else{
	    error("cadena incorrecta!!");
	    errnum++;
	  }
	  Token(1);
	}
	i++;
	break;
      }
    }
  }
  else
    error("Sintaxis incorrecta!!");

// Escritura de archivo de salida
  out = fopen("cated.bin","ab");
#ifdef debug
  printf("reg: %p\n",out);
#endif
  fwrite(&RegCated,sizeof(RegCated),1,out);
  fclose(out);

}


// Identificacion sintactica de la instruccion estudiante
void esEstud(estudiante &RegEstud){

  FILE * out; // archivo de salida

  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores

  // Inicializacion
  RegEstud.nombre[0]=0;
  RegEstud.direccion[0]=0;

  // Reconocimiento sintactico

  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0){ // mientras no se llegue a ';'
      Token(1);
      
#ifdef debug
      printf("i=%d:\t%s\n",i,lexema);
#endif
      switch (estado){
      case E_num: // si token leido es numero

	if(i==0) {// Rutina para incluir guion PROBAR
	  RegEstud.carnet = atol(lexema);
	  Token(1);
	  if (estado==E_ascii){
	    Token(1);
	    RegEstud.carnet = (RegEstud.carnet * (long)pow(10,sizeof(lexema)/8)) + 
	      atol(lexema);
	  }
	}
#ifdef debug
	printf("Carnet : %ld\n",RegEstud.carnet);
#endif
			         
						   
	  //	(i==0)?(RegEstud.carnet = atol(lexema)):errnum++;
	(i==3)?(RegEstud.telefono = atol(lexema)):errnum++;
	(i==4)?(RegEstud.correo= atol(lexema)):errnum++;
	i++;
	break;
      // Cambiar para incluir a email
      case E_identificador: // si token leido es texto sin apostrofo
	(i==1)?(int)strcpy(RegEstud.nombre,lexema):errnum++;
	(i==2)?(int)strcpy(RegEstud.direccion,lexema):errnum++;
	i++;
	break;
      case E_apos: // si se lee apostrofo
	Token(1);
	while((estado !=E_apos)) {
	  if (i==1 && estado == E_identificador){
	    strcat(RegEstud.nombre,lexema);
	    strcat(RegEstud.nombre," ");
	    
	  }
	  else if (i==2 //&& (estado == E_identificador || estado == E_num)
		   ){
	    strcat(RegEstud.direccion,lexema);
	    strcat(RegEstud.direccion," ");
	    
	  }
	  else{
	    error("cadena incorrecta!!");
	    errnum++;
	  }
	  Token(1);
	}
	i++;
	break;
      }
    }
  }
  else
    error("Sintaxis incorrecta!!");

// Escritura de archivo de salida
  out = fopen("estud.bin","ab");
#ifdef debug
  printf("reg: %p\n",out);
#endif
  fwrite(&RegEstud,sizeof(RegEstud),1,out);
  fclose(out);

}

// Rutina para leer archivo de entrada
int lee(char * filename)
{
  estudiante RegEstud;
  catedratico RegCated;
  
	// Si no se logra abrir archivo por rutina de scanner
  if(!abre_arch(filename))
    {
      return -1;
    }

  else {
    while(!feof(file_in))
      {
	Token(1);
	switch(estado)
	  {
	  case E_estudiante:
	    Token(1);
	    //rutina para cuando es estudiante.
#ifdef debug
	    printf("%s\n",lexema);
#endif
		printf("- Guardando datos de Estudiante en linea No. %d a archivo \'estud.bin\'\n",numlinea);
	    esEstud(RegEstud);
	    break;
	  case E_catedratico:
	    Token(1);
#ifdef debug
	    printf("%s\n",lexema);
#endif
		printf("- Guardando datos de Catedratico en linea No. %d a archivo \'cated.bin\'\n",numlinea);
	    esCated(RegCated);
	    //rutina para cuando es catedratico.
	    break;
	  
	  
	  }
      }
    return 1;
  }
  return 0;
}


//Rutina para mostrar en pantalla
int ShowScreen(void)
{
  int opcion = 0;	// Guarda opcion
  estudiante regEstud;	// Registros temporal para mostrar
  catedratico regCated;
  FILE * in;		// Archivo de Entrada

  printf("Desea ver en pantalla??\n\t1) SI \n\t2) NO y salir del programa\n");
  scanf("%d",&opcion);
  if(opcion == 1) {

    if ((in = fopen("estud.bin","rb"))!=NULL ){
		
      printf("\t\t\tEstudiante\n");
      printf("\t\t\t==========\n");
      printf  ("+--------+--------+-----------+----------+--------+\n");
      printf  ("| Carnet | Nombre | Direccion | Telefono | Correo |\n");
      printf  ("+-------------------------------------------------+\n");
      while(!feof(in)){
	fread(&regEstud,sizeof(estudiante),1,in);
	printf("| %ld | %s | %s | %ld | %ld |\n",
	       regEstud.carnet,regEstud.nombre,regEstud.direccion,
	       regEstud.telefono,regEstud.correo);
	printf("+-------------------------------------------------+\n");
      }
      fclose(in);
    }
    else
      printf("no existe archivo de entrada para Estudiante\n");

    if ((in = fopen("cated.bin","rb"))!=NULL ){
      //regEstud = new estudiante;
      printf("\t\t\tCatedratico\n");
      printf("\t\t\t===========\n");
      printf  ("+--------+--------+-----------+--------+\n");
      printf  ("| Codigo | Nombre | Direccion | Correo |\n");
      printf  ("+--------------------------------------+\n");
      while(!feof(in)){
	fread(&regCated,sizeof(catedratico),1,in);
	printf("| %ld | %s | %s | %ld |\n",
	       regCated.id,regCated.nombre,regCated.direccion,
	       regCated.correo);
	printf("+--------------------------------------+\n");
      }
      fclose(in);
    }
    else
      printf("no existe archivo de entrada para Catedratico!!\n");

    return 0;
    }
  else if(opcion == 2){
    return 0;
  }
  else{
    printf("opcion invalida!!\n");
    return 1;
  }
  return 0;
}
	 







int main(int argc, char argv[])
{
  char filename[50];
  printf("Ingresar nombre de archivo:\t");
  scanf("%s",&filename);
  lee(filename);
  ShowScreen();
  printf("para salir presionar cualquier tecla, luego [enter]");
  scanf("%[\n]",&filename);
  return 0;
  //return 0;
}
