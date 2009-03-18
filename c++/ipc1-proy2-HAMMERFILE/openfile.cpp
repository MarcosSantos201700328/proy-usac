#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct archivos
{
	char * nombre;
	char * tipo;
	char * fecha;
};


int main (void)
{
	FILE * lista;

	archivos * archivo1 = new archivos;

	char path[255];
	char *text[3];
	lista = NULL;
	scanf("%[^\n]",&path);
	lista = fopen(path,"r");
	if (lista != NULL)
	{
	   //	for (int i = 0; i < 3; i++)
	   //	{
	   //		fscanf(in,"%[^\' '^\n]",text[i]);
	   //			fseek(in,sizeof(text[i])-2,SEEK_CUR);
	   //		printf("linea %d: %s\n",i+1,text[i]);
	   //	}
	   int j=0;
	   int i=0;
	   char c='\000';
//	   int end=0;

		int tam, acum,end;
		tam = 0;
		acum=0;
		end = 0;
		//while(c!='\n')
		while(!end)
		{
		/*
			// este ya no se toca, funciona perfectamente
			if(c==' ' && c!='\n') // si encuentra un espacio en el scan
			{
				tam=j;		//tam es igual a j
				text[i] =(char*) malloc(tam+1); //reserva memoria para cadena
				fseek(in,(long)(sizeof(char)*(acum)),SEEK_SET); // busca en el offset de archivo
				acum+=j;	//aumenta a 1 el acumulador de offset.
				fread(text[i],sizeof(char)*j,1,in);//lee bloque de caracteres desde archivo a memoria
				text[i][j-1]='\t'; //coloca un tab en el espacio
				text[i][j]='\000';	//escribe el fin de cadena en el espac
				//fseek(in,strlen(text[i]),SEEK_CUR);	// establece la pocision en el archivo

				tam = 0;
				i++;
				j=0;
				//c=(char)fgetc(in);
				c=(char)0;
			}
			*/
			//nuevo
			if(c==' ' || c=='\n') // si encuentra un espacio en el scan
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
					stpcpy(archivo1->nombre,text[0]);
					stpcpy(archivo1->tipo,text[1]);
					stpcpy(archivo1->fecha,text[2]);
					printf("-nombre:%s \n",archivo1->nombre);
					printf("-tipo:%s \n",archivo1->tipo);
					printf("-fecha:%s \n",archivo1->fecha);
					// reset
					free(text);
					i = 0;

				}
				if(feof(lista)!=0)
				{
					acum++; 			// hack para 0x0D + 0x0A de salto de linea
					stpcpy(archivo1->nombre,text[0]);
					stpcpy(archivo1->tipo,text[1]);
					stpcpy(archivo1->fecha,text[2]);
					printf("-nombre:%s \n",archivo1->nombre);
					printf("-tipo:%s \n",archivo1->tipo);
					printf("-fecha:%s \n",archivo1->fecha);
					// reset
					free(text);
					i = 0;
                    end = 1;

				}
				// reset de variables
				tam = 0;


				j=0;
				c=(char)0;

			}
			else
			{
				c=(char)fgetc(lista);
				putchar(c);
				j++;

			}

		}
		printf("\n---------------\n");
		delete archivo1;
		fclose(lista);

	}
	else
	{
		printf("escribir path correcto\n");
	}
	return 0;
}
