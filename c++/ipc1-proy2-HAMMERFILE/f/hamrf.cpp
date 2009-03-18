/*
todo list:
-[hecho] crear logger.
-[hecho] abrir y analizar el archivo lista.(crear algoritmo de revision caracter por caracter)
- Globalizar el array de archivo para uso comun.
- algoritmo de organizar y guardar alfabeticamente la lista en los archivos binarios
- componer el error inicial de caracteres extranos.

- crear interfaz grafica.
*/
// Constantes de debug
#ifndef DEBUG
#define DEBUG
#ifndef __BCC
#define __BCC
//#undef __BCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef __BCC
	#include <conio.h>
#endif
// Librerias Externas

// Constantes

char prgname[10];
float ver;

//#undef DEBUG

// Variables Globales
char mainpath[256];

struct archivos
{
	char nombre[255];
	char tipo[100];
	char fecha[50];
	int fin;
};

archivos arch[100];		// puntero a archivos global para uso comun.

struct ArchDest{		// Struct de archivo a guardar (AVISO, puede llenar la memoria
	char path[100];
	char nombre[100];
	char extension[5];
	char tipo;
	int d,m,a;
	int n;

};

//ArchivDesc * A;


FILE * lista, * log;			// punteros a archivo para lista, log(bitacora)

// Prototipos de Funciones
void UItexto(void);		// Interfaz modo texto

int OpenList(char * , struct archivos *);   // Abre archivo de lista extension .txt y almacena en un vector de structs su contenido.

int SortSave(archivos *); // Organiza y guarda matriz de "structs archivo" a archivo binario en disco, organizado alfabeticamente.

int logger(char *);		// Funcion de log (Bitacora) a archivo
char * tiempo(void);	// Devuelve la hora y la fecha actual en una cadena de char.


// ***************************
int main(void)
{

	// define las constantes
	strcpy(prgname,"HammerFile");
	ver = 1;

	// Llama a interfaz grafica o modo texto
	#ifdef DEBUG
	UItexto();
	#endif
	return 0;
}

#ifdef DEBUG
void UItexto()
{
	int select = 0;
	int s;
	while( (select < 1) || (select > 8))
	{
		printf("\n\t\t\tBienvenido a %s V. 0.%1.0f\n",prgname,ver);
		printf("\t\t\tSeleccione lo que desee hacer:\n\n");
		printf("\t1. Abrir Archivo de entrada\n");
		printf("\t2. Organizar Archivo de Entrada\n");
		printf("\t3. Salir\n");
		printf("\t4. Buscar\n");
		printf("\t5. Eliminar Archivo\n");
		printf("\t6. Abrir Archivo de entrada\n");
		printf("\t7. Abrir Archivo de entrada\n");
		printf("\t8. Abrir Archivo de entrada\n");
		scanf("%d",&select);
		switch (select)
		{
		case 1:
			s=0;
			while(s == 0)
			{
				printf("Escribir archivo de entrada\n");
				scanf(" %[^\n]",mainpath);
				printf("%s",&mainpath);
				s = OpenList(mainpath, arch);
				select=0;
			}
		break;
		case 2:
			SortSave(arch);
		break;
		case 3:
		abort();
		//exit = 1;
		break;
		case 4:
		break;
		case 5:
		break;
		//default:
		//printf("ingrese alguna opcion valida");
		//break;
		}
   }

}
#endif

int OpenList( char * path, struct archivos * archivo1)
{
	#ifdef DEBUG
	printf("%s\n",path);
	#endif
	// puntero a archivos que almacenara los datos(array dinamico)
//	archivos * archivo1;

	// matriz que almacenara las cadenas leidas
	char *text[3];		//Matriz de cadena de caracteres
	*text=(char*)calloc(32000,sizeof(char));	// asigna 32Kb al texto.

	// inicializacion de variables
	int j=0;
	int i=0;
	int k=0;
	char c='\000';
	int tam, acum,end;
	tam = 0;
	acum=0;
	end = 0;

	logger("abriendo archivo...");	// mensaje
	lista = fopen(path,"r");	// abre archivo en modo solo lectura

	if (lista != NULL)		// si archivo existe
	{
		free(archivo1);   		// borra cualquier instancia anterior de archivos

	//archivo1 = (archivos *)calloc(100,sizeof(archivos)); //asigna 24000 bytes para struct


		while(end <=0) 		// mientras la bandera end sea menor a 0
		{
			if(c==' ' || c=='\n' || feof(lista) !=0) // si encuentra un espacio en el scan
			{
				tam=j;		//tam es igual a j
				text[i] =(char*) malloc(tam+1); //reserva memoria para cadena
				fseek(lista,(long)(sizeof(char)*(acum)),SEEK_SET); // busca en el offset de archiv				acum+=j;	//aumenta a 1 el acumulador de offset.
				acum+=j;	//aumenta a 1 el acumulador de offset.
				fread(text[i],sizeof(char)*j,1,lista);//lee bloque de caracteres desde archivo a memoria
				text[i][j-1]='\t'; //coloca un tab en el espacio
				text[i][j]='\000';	//escribe el fin de cadena en el espac
				i++;	//incrementa numero de cadena;

				if (c=='\n') //almacena en el struct cuando halla cambio de linea.
				{
					acum++; 			// hack para 0x0D + 0x0A de salto de linea
					stpcpy(archivo1[k].nombre,text[0]);	//Asigna a cada
					stpcpy(archivo1[k].tipo,text[1]);   //elemento del array
					stpcpy(archivo1[k].fecha,text[2]);  //de archivo su texto.
					archivo1[k].fin = 0;
					#ifdef DEBUG
					printf("-nombre:%s \n",archivo1[k].nombre);
					printf("-tipo:%s \n",archivo1[k].tipo);
					printf("-fecha:%s \n",archivo1[k].fecha);
					#endif
					// reset
					free(text);  	//libera memoria usada por el vector texto.
					i = 0;
					k++;		// incrementa el subindice del array de struct archivo

				}
				if (feof(lista)!=0)	// si se topa con el EOF hace lo mismo que
				{					   // en el paso anterior.
					acum++;
					stpcpy(archivo1[k].nombre,text[0]);
					stpcpy(archivo1[k].tipo,text[1]);
					stpcpy(archivo1[k].fecha,text[2]);
					archivo1[k].fin = 1;
					#ifdef DEBUG
					printf("-nombre:%s \n",archivo1[k].nombre);
					printf("-tipo:%s \n",archivo1[k].tipo);
					printf("-fecha:%s \n",archivo1[k].fecha);
					#endif
					// reset
					free(text);
					i = 0;
					k++;
					end++;  	 //	incrementa la bandera de fin del ciclo
				}
				// reset de variables
				tam = 0;
				j=0;
				c=(char)0;

			}
			else 	// sino lee cada caracter dentro del archivo de entrada
			{

				c=(char)fgetc(lista);
				#ifdef DEBUG
				putchar(c);
				#endif
				j++; // incrementa el contador para offset de fseek y tamano de cadena;

			}

		}
		#ifdef DEBUG
		printf("\n---------------\n");
		#endif
		logger("cerrando archivo");
//		SortSave(archivo1);
//		free(archivo1);
//		delete archivo1;
		fclose(lista);
		k=0;
		return 1;

	}
	else
	{
		printf("escribir path correcto\n");
		return 1;
	}
}

int logger(char * mensaje)
{
	// escribe mensaje en pantalla
	#ifdef DEBUG
	printf("%s\n",mensaje);
	#endif

	// abre el archivo y escribe en este
//	#ifndef __BCC
	log = fopen("mensajes.log","a");
//	#else
//	log = fopen("c:\\mensajes.log","a");
//	#endif
	if (log != NULL)
	{
		fprintf(log," %s:\t\"%s\"\n",tiempo(),mensaje);
		fclose(log);
		return 0;
	}
	else
	{
		printf("no se pudo crear archivo bitacora. \nRevise que no esta corriendo en cdrom\n");
		return 1;
	}
}

int SortSave(archivos * arc)
{
	int orden[26][100];	//guarda alfabeticamente el orden
	int i, j,k, cmp, ndat = 0;
	char inicial[2];
	inicial[1] = 0;

	do
	{
	i=0;
		for (j=0;j<26;j++)
		{
			inicial[0] = 65+j;
			#ifdef DEBUG
			printf("%s \n",inicial);
			#endif
			//NOTA: USAR STRPBRK PARA ENCONTRAR EL "." Y EL ULTIMO "\"
			cmp=strnicmp(arc[i].nombre,inicial,1);
			#ifdef DEBUG
			printf("comparando %s con %s \n",inicial,&arc[i].nombre);
			#endif

			if(cmp == 0)
			{
				orden[j][k] = i;
				i++;
				k++;
			#ifdef DEBUG
			printf("-inicial de %s es igual a inicial de %s\n",arc[i-1].nombre,inicial);
			#endif
			}

		}
		ndat = i;

	}
	while(arc[i].fin!=1);
	return 0;
}

char * tiempo()
{
	time_t ahora;
	time(&ahora);
	return (ctime(&ahora));
};

ArchDest DescReg(archivos ars)		// descompone los datos de entrada y devuelve un struct de datos
{
	char * buffer;
	char * cuenta;



}
#endif
#endif
