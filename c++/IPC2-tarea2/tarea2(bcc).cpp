#ifndef debug
#define debug
#undef debug
#endif
// Inclusion de "libreria" de Scanner
#include "../scanner.cpp"
//#include <fstream>

// encabezados nativos de C
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
};

using namespace std;

// Log:

// -[probar] Carnet estudiante acepta guiones
//

// Registro de datos de Estudiante
typedef struct estudiante{
  long carnet;
  char nombre[128];
  char direccion[256];
  unsigned long telefono;
  char correo[64];
};

// Registro de Datos de Catedratico
typedef struct catedratico{
  long id;
  char nombre[128];
  char direccion[256];
  char correo[64];
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
      switch (estado){
      case E_num: // si token leido es numero
	(i==0)?(RegCated.id = atol(lexema)):errnum++;
	i++;
	break;
      case E_identificador: // si token leido es texto sin apostrofo
	if (i==3){
		RegCated.correo[0]=0;
		while(estado!=E_parC){
			strcat(RegCated.correo,lexema);
			Token(1);
		}
	}
	i++;
	break;
      case E_apos: // si se lee apostrofo
	Token(1);
	while((estado !=E_apos)) {
	  if (i==1 && estado == E_identificador){
	    strcat(RegCated.nombre,lexema);
	    strcat(RegCated.nombre," ");
	    
	  }
	  else if (i==2 ){
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
  unsigned long z;

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
		z = RegEstud.carnet * (long)pow(10,strlen(lexema));
	    RegEstud.carnet = atol(lexema) + z;
	  }
	}
#ifdef debug
	printf("Carnet : %ld\n",RegEstud.carnet);
#endif
			         
						   
	  //	(i==0)?(RegEstud.carnet = atol(lexema)):errnum++;
	(i==3)?(RegEstud.telefono = atol(lexema)):errnum++;
//	(i==4)?(RegEstud.correo= atol(lexema)):errnum++;
	i++;
	break;
      // Cambiar para incluir a email
    case E_identificador: // si token leido es texto sin apostrofo
    if (i==4){
		RegEstud.correo[0]=0;
	//	strcpy(RegEstud.correo,lexema);
		while(estado!=E_parC){
			strcat(RegEstud.correo,lexema);
			Token(1);
		}
	}
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
  int num = 0;

  printf("Desea ver en pantalla??\n\t1) SI \n\t2) NO y salir del programa\n");
  scanf("%d",&opcion);
  if(opcion == 1) {

    if ((in = fopen("estud.bin","rb"))!=NULL ){
	  num = 0;
      printf("\t\t\tEstudiante\n");
      printf("\t\t\t==========\n");
      printf  ("+---+------------+-----------------------------+------------------------+");
      printf  ("|No |   Carnet   |         Nombre              |         Correo         |\n");
      printf  ("+===+============+=============================+========================+\n");
      while(!feof(in)){
		num++;
	    fread(&regEstud,sizeof(estudiante),1,in);
		if (!feof(in))
	      printf("%d)  %ld\t, %s , %s ;\n",num,regEstud.carnet,regEstud.nombre,regEstud.correo);
      }
      fclose(in);
    }
    else
      printf("no existe archivo de entrada para Estudiante\n");
    if ((in = fopen("cated.bin","rb"))!=NULL ){
	  num= 0;
      //regEstud = new estudiante;
      printf("\n\n\t\t\tCatedratico\n");
      printf("\t\t\t===========\n");
      printf  ("+---+------------+-----------------------------+------------------------+\n");
      printf  ("|No |   Codigo   |       Nombre                |           Correo       |\n");
      printf  ("+===+============+=============================+========================+\n");
      while(!feof(in)){
		num++;
		fread(&regCated,sizeof(catedratico),1,in);
		if (!feof(in))
		  printf("%d)  %ld\t, %s , %s ;\n",num,regCated.id,regCated.nombre,regCated.correo);
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
// Pantalla de Presentacion	 
void presentacion(){
  printf("\t\tPractica 1: IPC2 Sec. C ,Segundo Semestre 2005\n");
  printf("\t\t==============================================\n");
  printf("\t\t\t Nombre: Erik Vladimir Giron Marquez\n");
  printf("\t\t\t Carnet: 200313492\n\n");
  printf("\tNOTA: Se crearan archivos binarios auxiliares,\n");
  printf("\tpara poder realizar las operaciones.\n\n\n");
}



int main(int argc, char argv[])
{
  char filename[50];
  char salida = 0;
  presentacion();
	while (salida!='\n'){
      printf("Ingresar nombre de archivo:\t");
      scanf("%s",&filename);
      lee(filename);
      ShowScreen();
      printf("\n\n\n\n\n\t\tDesea Salir?:\n\tSi:\t[s + enter]\n\n");
	  salida = getchar();
      scanf("%d",salida);
	}
  return 0;
  //return 0;
}
