/*
todo list:
-[hecho] crear logger.
-[hecho] abrir y analizar el archivo lista.(crear algoritmo de revision caracter por caracter)
	-arreglar problemas de apertura de archivo(comparar con versiones viejas)
												(convertir a punteros estaticos)

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

//struct archivos
//{
//	char nombre[255];
//	char tipo[100];
//	char fecha[50];
//	int fin;
//};

//archivos arch[100];		// puntero a archivos global para uso comun.

struct ArchDest{		// Struct de archivo a guardar (AVISO, puede llenar la memoria
	char path[96];
	char nombre[32];
	char ext[5];
	char tipo[32];
	int d,m,a;
	int n,fin;

};
ArchDest arch[256];		// Podra almacenar hasta 256 archivos

//ArchivDesc * A;


// Prototipos de Funciones
void UItexto(void);		// Interfaz modo texto

int OpenList(char * , struct ArchDest *);   // Abre archivo de lista extension .txt y almacena en un vector de structs su contenido.

int SortSave(ArchDest *); // Organiza y guarda matriz de "structs archivo" a archivo binario en disco, organizado alfabeticamente.

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
//				free(mainpath);
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

int OpenList( char * ruta, struct ArchDest * archivo1)
{
	#ifdef DEBUG
	printf("%s\n",ruta);
	#endif
	FILE * lista;
	// matriz que almacenara las cadenas leidas
	char text[3][256];		//Matriz de cadena de caracteres
	char fecha[2][5];
//	*fecha = (char*)malloc(8*sizeof(char));
//	char *m;
//	char *d;
//	*text=(char*)calloc(512,sizeof(char));	// asigna 32Kb al texto.
//	m=(char*)malloc(sizeof(char)*5);
//	d=(char*)malloc(sizeof(char)*5);
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
	lista = fopen(ruta,"r");	// abre archivo en modo solo lectura

//	printf("%x",&lista);

	if (lista != NULL)		// si archivo existe
	{
//		free(archivo1);   		// borra cualquier instancia anterior de archivos
		// puntero a archivos que almacenara los datos(array dinamico)
//		archivo1 = (ArchDest*) malloc(sizeof(ArchDest)*100);

	//archivo1 = (archivos *)calloc(100,sizeof(archivos)); //asigna 24000 bytes para struct

		while(end <=0) 		// mientras la bandera end sea menor a 0
		{
			if(j==0 || c==' ' || c=='\n' || feof(lista) !=0) // si encuentra un espacio en el scan
			{
//n				fseek(lista,(long)(sizeof(char)*(acum)),SEEK_SET); // busca en el offset de archiv
				fscanf(lista,"%[^' '^\n]",&text[i]);
				if (j==0)
					j++;
				i++;

				if (c=='\n') //almacena en el struct cuando halla cambio de linea.
				{
					fseek(lista,(long)(sizeof(char)) + 1,SEEK_SET); // busca en el offset de archiv

//n					acum++; 			// hack para 0x0D + 0x0A de salto de linea
					#ifdef DEBUG
					printf("extension es %s \n",strrchr(text[0], '.') + 1);
					printf("nombre es %s \n",strrchr(text[0], '\\') + 1);
					printf("a~no es %s \n",strrchr(text[2],'/') + 1);
					printf("mes es %s \n",strchr(text[2],'/') + 1);
					printf("dia es %s \n",&text[2]);

					#endif
		//					printf("path es %s \n",path);

					// copia variables y datos de fecha al struct
					strncpy(fecha[0],text[2],5);
					//	   strlen(text[2]) - strlen(strchr(text[2],'/')) );
					strnset(strpbrk(fecha[0],"/"),'\x0',1);

					strncpy(fecha[1],strchr(text[2],'/') + 1,5);
				  //		strlen(fecha[0]) + 1 - strlen(strrchr(text[2],'/')) );
					strnset(strpbrk(fecha[1],"/"),'\x0',1);

					archivo1[k].a =	atoi(strrchr(text[2],'/') + 1);
					archivo1[k].m = atoi(fecha[0]);
					archivo1[k].d = atoi(fecha[1]);
					archivo1[k].n = 0;
 //					free(*fecha);
					// copia datos de fecha a variables temporales
/*

					// copia nombre, path y extension al struct
					strncpy(archivo1[k].ext,strrchr(text[0], '.') + 1,strlen(strrchr(text[0], '.') + 1) - 1);
					strncpy(archivo1[k].nombre,strrchr(text[0], '\\') + 1,
							strlen(strrchr(text[0], '\\') + 1) - strlen(strrchr(text[0], '.') + 1) - 1);
					strncpy(archivo1[k].path , text[0], strlen(text[0]) - strlen( strrchr( text[0], '\\' ))+1);


					// copia tipo a struct
					strncpy(archivo1[k].tipo,text[2],strlen(text[2])-1);

					#ifdef DEBUG
					printf("Nombre:%s.%s Fecha:%d/%d/%d\n",archivo1[k].nombre,archivo1[k].ext,archivo1[k].d,
														archivo1[k].m,archivo1[k].a);
					#endif
*/					// reset
//					free(text);  	//libera memoria usada por el vector texto.
					i = 0;
					k++;		// incrementa el subindice del array de struct archivo

				}
				if (feof(lista)!=0)	// si se topa con el EOF hace lo mismo que
				{					   // en el paso anterior.

					acum++; 			// hack para 0x0D + 0x0A de salto de linea
					#ifdef DEBUG
					printf("extension es %s \n",strrchr(text[0], '.') + 1);
					printf("nombre es %s \n",strrchr(text[0], '\\') + 1);
					printf("a~no es %s \n",strrchr(text[2],'/') + 1);
					printf("mes es %s \n",strchr(text[2],'/') + 1);
					printf("dia es %s \n",text[2]);

					#endif
//					printf("path es %s \n",path);
					// copia variables y datos de fecha al struct
/*					archivo1[k].a =	atoi(strrchr(text[2],'/') + 1);
					archivo1[k].m = atoi(m);
					archivo1[k].d = atoi(d);
					archivo1[k].n = 0;

					// copia datos de fecha a variables temporales
					strncpy(d,text[2],
						   strlen(text[2]) - strlen(strchr(text[2],'/')) );
					strncpy(m,strchr(text[2],'/') + 1,
							strlen(d) + 1 - strlen(strrchr(text[2],'/')) );

					// copia nombre, path y extension al struct
					strncpy(archivo1[k].ext,strrchr(text[0], '.') + 1,strlen(strrchr(text[0], '.') + 1) - 1);
					strncpy(archivo1[k].nombre,strrchr(text[0], '\\') + 1,
							strlen(strrchr(text[0], '\\') + 1) - strlen(strrchr(text[0], '.') + 1) - 1);
					strncpy(archivo1[k].path , text[0], strlen(text[0]) - strlen( strrchr( text[0], '\\' ))+1);


					// copia tipo a struct
					strncpy(archivo1[k].tipo,text[2],strlen(text[2])-1);

					#ifdef DEBUG
					printf("Nombre:%s.%s Fecha:%d/%d/%d\n",archivo1[k].nombre,archivo1[k].ext,archivo1[k].d,
														archivo1[k].m,archivo1[k].a);
					#endif
*/
					// reset

//					archivo1[k].fin = 1;
					// reset
//					free(text);
					i = 0;
					k++;
					end++;  	 //	incrementa la bandera de fin del ciclo
				}
				// reset de variables
				tam = 0;
//				j=0;
				c=(char)0;

			}
			else 	// sino lee cada caracter dentro del archivo de entrada
			{

				c=(char)fgetc(lista);
//				text[i][j]=c;
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
		return 0;
	}
}

int logger(char * mensaje)
{


	FILE * log;			// punteros a archivo para lista, log(bitacora)
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

int SortSave(ArchDest * arc)
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
	while(arc[i].n!=1);
	return 0;
}

char * tiempo()
{
	time_t ahora;
	time(&ahora);
	return (ctime(&ahora));
};

//ArchDest DescReg(archivos ars)		// descompone los datos de entrada y devuelve un struct de datos
//{
//	char * buffer;
//	char * cuenta;



//}
#endif
#endif
