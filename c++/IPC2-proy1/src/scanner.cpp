 //unidad scan.h
  /*unidades standar incluidas*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//  #include <conio.h>
//   #include <iostream.h>
//  #include <iostream>
  /*constantes*/

#define false              0
#define true               1
#define E_identificador    2  /*estado identificador*/
#define E_num              3  //estado numerico
#define E_mas              4  // estado signo "+"
#define E_puncoma          5  // estado ";"
#define E_apos             6  // estado "'"
#define E_igual	      7  // estado "="
#define E_asteris	      8  // estado "*"
#define E_corcheteA	      9  // estado "["
#define E_corcheteC	     10  // estado "]"
#define E_parA            11  // estado "("
#define E_parC            12  // estado ")"
#define E_LlaveA	     13  // estado "{"
#define E_LlaveC	     14  // estado "}"
#define E_coma	     15  // estado ","
#define E_preg	     16  // estado "?"
#define E_or		     17  // estado "³"
#define E_punto	     18	 // estado "."
#define E_FinArchivo      19  // estado fin archivo
#define E_ascii           20  // estado cualquier ascii
#define E_inicial         21  // estado inicial
#define E_texto           22  // texto
#define E_guion           23  // estado "-"
   //#define E_space           24  // espacio en blanco
#define E_com             25  // estado "\""

// Mis tokens


//INSTRUCCIONES EN UN ARCHIVO DE ENTRADA
#define E_inicializar 30
#define E_creaconfed 40
#define E_creaselec 41
#define E_creatorneo 42
#define E_juego 43
#define E_puntos 44
#define E_prem_mejeq 45
#define E_prem_desem 46
#define E_clasifica  47
//#define COMPETIDOR	    			26

typedef struct lexico
{
  char C_lex[150];
  int atrib;
};

/*Estructura para guardar las Palabras Rervadas*/
struct Reservadas
{
  char reservada[35];  /*nombre de la reservada*/
  int codigo;         /*codigo*/
};

int Fin=false;
int numlinea = 1 ; /*Numero de Linea del Archivo*/

struct Reservadas Rec_Res[16]={
  
  {"INICIALIZAR", E_inicializar},
  {"CREAR_CONFEDERACION", E_creaconfed},
  {"CREAR_SELECCION", E_creaselec},
  {"CREAR_TORNEO", E_creatorneo},
  {"JUEGO", E_juego},
  {"PUNTOS_ACUMULADOS", E_puntos},
  {"PREMIO_MEJOR_EQUIPO", E_prem_mejeq},
  {"PREMIO_DESEMPENIO", E_prem_desem},
  {"PREMIO_DESEMPEÑO",E_prem_desem},
  {"CLASIFICACION", E_clasifica},

};

/*variables globales del programa*/
char lexema[150];  // Guarda el componente lexico
char letra[2];
int salir;      // Bandera de Lectura
char token;     // Caracter le¡do desde el teclado
FILE *file_in;  // Archivo de entrada
FILE *file_out;
int estado;     // Estado actual del scaner
char pala[13];
char codigo[15];

/* imprime error en el archivo de prueba*/
void error(char *lex)
{
  fprintf(file_out,"ERROR EN LA LINEA # = %d\n",numlinea);
  fprintf(file_out,"VERIFIQUE EL INGRESO: %s\n",lex);
  exit(0);
}

void ReturnFile2()
{
  ungetc(token,file_in);  //retrocede un caracter en el archivo de entrada
  if (token=='\n')
    numlinea--;    // decrementar l¡nea leida
}

 /* estado letra del scanner*/
void Identificador()
{
  if(isalpha(token) || isdigit(token) || token=='_'|| token=='-')
    estado=E_identificador;
  else {
    ReturnFile2();
    salir=true;
    lexema[strlen(lexema)-1]='\0';
  }
}

 /*abre el archivo de entrada*/

int abre_arch(char nombre[40])
{
  file_in = fopen(nombre,"r");
  if(file_in == NULL)
    {
      //  gotoxy(17,9);
      printf("         ESE ARCHIVO NO EXISTE                  \n\r");
      // gotoxy(17,10);
      printf(" ***Presione <ENTER> para salir*** \n\r");
      //   cout<<"     *** Presione Enter para salir ***           \n";
      // gotoxy(17,11);
      //  cout<<"                                                 \n";
      //    getch();
      /* setfillstyle(1,1);
	 bar(0,0,getmaxx(),getmaxy());
	 setcolor(WHITE);
	 rectangle(5, 5, 635, 475);
	 setfillstyle(1,4);
	 bar(175, 125, 450, 325);
	 setcolor(WHITE);
	 settextstyle(1,0,1);
	 outtextxy(200, 205, "El archivo no existe");*/
      return 0;
    }
  else
    return(1);
}

int File_Out(char nombre[40])
{
  char nom[20];
  file_out = fopen(nombre,"a+");
  if (file_out == NULL)
    {
      return 0;
    }
  else
    return(1);
}

/*lee un caracter del archivo de entrada*/
void lee_car()
{
  token=getc(file_in);
//   if (token == 255)
//       strcpy(lexema,"caracter 255");
  if (token=='\n')
     numlinea++;
}

 /* reinserta el Lexema en el archivo de entrada*/
void ReturnfileLexema()
{
  int i=(strlen(lexema)-1);
  while (i>=0)
    {
      token=lexema[i];
      i--;
      ReturnFile2();
    }//while
}

/*estado inicial del scanner*/
void Inicial()
{
  if((token==' ')||(token=='\n')||(token=='\t'))
    lexema[strlen(lexema)-1]='\0';
  else if(isalpha(token))
    estado=E_identificador;
  else if(isdigit(token))
    estado=E_num;
  /*else if(token=='-')
    estado=E_guion;*/
  else if(token=='+')
    estado=E_mas;
  else if(token=='(')
    estado=E_parA;
  else if(token==')')
    estado=E_parC;
  /*else if(token==' ')
    estado=E_space;*/
  else if(token=='\"')
    estado=E_com;
  else if(token==',')
    estado=E_coma;
  else if(token==';')
    estado=E_puncoma;
  else if (token == '[')
    estado = E_corcheteA;
  else if (token == ']')
    estado = E_corcheteC;
  else if (token == '{')
    estado = E_LlaveA;
  else if (token == '}')
    estado = E_LlaveC;
  else if (token == '?')
    estado = E_preg;
  else if (token == '.')
    estado = E_punto;
  else if (token == '|')
    estado = E_or;
  else if (token == 39)
    estado = E_apos;
  else if (token == '=')
    estado = E_igual;
  else if (token==EOF)
    estado=E_FinArchivo;
  else
    {
      estado=E_ascii;
      salir=true;
    }//else
}
/*estado Numero*/
void numero()
{
  if (isdigit(token))  // Busca el siguiente digito
    estado= E_num;
  else
    {
      if((token==' ')||(token=='\n')||(token=='\t')) //fin de linea
	lexema[strlen(lexema)-1]='\0';
      else
	{
	  ReturnFile2();    // siguiente lexema
	  salir=true;
	  lexema[strlen(lexema)-1]='\0';
	}
    }
}

/* estado punto */

int abre_archivo(char *nom1)
{
  file_in=fopen(nom1,"r");
  if (file_in!=NULL) return true;
  else return  false;
};

/* identifica las reservadas*/
int identifica_reservada()
{
  char lexema2[150];
  strcpy(lexema2,lexema);
  int i=0 ;
  for (i=0;i<strlen(lexema);i++)
    lexema2[i]=toupper(lexema2[i]);  // Convierte a mayusculas el ID //
  i=0;
  while (i < 17)
    {
      if (strcmp(Rec_Res[i].reservada,lexema2)==0)
	{
	  strcpy(lexema,lexema2);
	  estado = Rec_Res[i].codigo;
	  i = 17;
	}
      else
	i++;
    };
  return estado;
};

/*funcion principal que devuelve el token*/
lexico Token(int tipo)
{
  lexico RegLex;  // devuelve el componente lexico y el atributo //
  estado =E_inicial;
  strcpy(lexema,"");
  strcpy(letra," ");
  Fin = false;
  salir=false;
  while (!salir && token!=EOF)
    {
      lee_car();
      letra[0]=token;
      letra[1] = 0;
      strcat(lexema,letra);
      switch (estado){
      case E_inicial :        Inicial();	break;
      case E_identificador :  Identificador();	break;
      case E_num:             numero();	break;
	
      default:  	  salir=true;
	lexema[strlen(lexema)-1]='\0';
	ReturnFile2();
	break;
      }//switch
    }//while
  if (token == EOF)
    Fin=true;
  
  if(estado == E_identificador && strlen(lexema) > 35)
    estado = E_texto;
  
  if (estado == E_identificador && tipo == 1)
    estado =identifica_reservada();
  
  strcpy(RegLex.C_lex,lexema);
  RegLex.atrib = estado;
  return RegLex;
}

void cerrar_archivo()
{
  fclose(file_in);
}

void cerrararch()
{
  fclose(file_out);
}
