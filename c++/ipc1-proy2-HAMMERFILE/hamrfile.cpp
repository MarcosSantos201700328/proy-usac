/* DESC
  Nombre: HammerFile
  Copyright: ©2005 Erik Giron.
  Autor: Erik Giron (Carnet: 200313492)
  Fecha: 26/04/05 18:17
  Descripcion: Proyecto 2 de IPC1 USAC Primer Semestre 2005
			  (Admin de Archivos usando modo grafico de Borland C++ 3.1)
			  
Copyright (C) 2005  Erik Giron

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

*/
/* TODO
todo list:

-[hecho] Validar para que no ingresen mas de 255 datos
-[hecho] crear logger.
-[hecho] abrir y analizar el archivo lista.(crear algoritmo de revision caracter por caracter)
[hecho]	-arreglar problemas de apertura de archivo(comparar con versiones viejas)
												(convertir a punteros estaticos)
-[hecho] Globalizar el array de archivo para uso comun.

-[hecho] algoritmo de organizar y guardar alfabeticamente la lista en los archivos binarios
	++ revisar el bug raro de crear carpeta que a veces ocurre.
	[hecho] crear validacion para que no entren dos archivos del mismo path y nombre en el archivo binario.
	[hecho] crear algoritmo de reseteo de variables del struct archdest.
- [hecho]componer el error inicial de caracteres extranos.

- [hecho]Crear Algoritmo de Busqueda
	[hecho]- Subalgoritmo para escribir archivo xml mientras se encuentran datos.
		[hecho](mejorar algoritmo para que sobreescriba el archivo en </reporte>
	[hecho]- Arreglar el bug de 7 caracteres de archivo.tipo
	[hecho]- Busqueda por Tipo
	[hecho]- Busqueda por Fecha

-[hecho] Crear Algoritmo de eliminacion.
	++(bug) encontrar bugs de fseek...fwrite y n++ en el ciclo

-[2/3] Crear Algoritmo de cambiar nombre.
	-[hecho] terminar el algoritmo para cambiar nombre a diferente archivo!!!
	++(bug) encontrar bugss...

-> crear interfaz grafica.
	-[hecho*] Recrear menues y comandos.
		* revisar por bugs del gui
		-[hecho] cuadro abrir lista
		-[hecho] organizar
		-[hecho] salir
		-[hecho] Buscar nombre
		-[hecho] Buscar tipo
			-(bug) quitar archivo null del xml resultante
		-[hecho] buscar fecha
		-[hecho] Eliminar
		-[hecho] Renombrar
			[hecho](bug) Corregir todos los errores iniciales.
		-[hecho] Utilizar system("start iexplore.exe") para abrir archivo XML;
	-[hecho] Crear cuadros de texto y algoritmos de validacion.
	-[hecho] Recrear comandos de acceso rapido.
	-[hecho] Cambiar texto en ayuda en linea
	- llamar a system("start iexplore.exe") para abrir manual de usuario.


- validar para cualquier caso buscar con GUI;
- Desdefinir debug en la version final.
(bug) buscar errores al no usar backslash en el path al ingresar ruta a eliminar
- files 2 include in binary distrib
	- exe, obj, bgi, xsl ,htm

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
#include <dir.h>
#include <time.h>
#include <ctype.h>
#ifdef DEBUG
	#include <process.h>
#endif
	#include <alloc.h>
#ifdef __BCC
	#include <conio.h>
#endif
// Librerias Externas
#include "raton.h"
#include "eventos.h"
#include "control.h"

// Constantes

char prgname[10];
float ver;

#undef DEBUG

// Variables Globales
char mainpath[256];		// almacena el path principal
char tipo[32];					// almacena tipo
int s,d,m,a;						// almacena fecha
// Banderas
int mt;		// define modo texto
// Banderas Modo Grafico
int banmenu;	//-Bandera para menu
int outmenu = 0;//-Salida del bucle de gui.

int mainflag;	//-Bandera Principal de control del programa.
				//	valores de mainflag:
				//		unidades: No. comando
				// 		decenas : No. menu

// Estructuras
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

int iniciographics(void);   //Inicia modo grafico

void mouseinit(void);           //Inicia el mouse

void welcome(void);  //Muestra pantalla de Bienvenida

int GUI(void);			// Funcion principal de modo grafico

int dismiss(int);		 // Dibuja ventana de despedida.

void help(int);			 // Muestra ayuda en linea, ayuda con programa externo y
						 // la ventana de acerca de..

void mostrargui(void);		// Dibuja la barra del menu con sus botones
							// para abrir menues desplegables.
							// si su argumento es 1, borra el menu

void muestramenu(int, int); // Muestra menu invocado por mostrargui()
							// sus parametros son la posicion y la bandera
							// si la posicion es -1, destruye el menu identificado
							// con la bandera

int clicmenu(int,int,int);   //accion cuando se hace clic en algun comando de menu.

void screenmsg(char *,int);	// dibuja un mensaje en la parte inferior de la pantalla

int OpenList(char * , struct ArchDest *);   // Abre archivo de lista extension .txt y almacena en un vector de structs su contenido.

int SortSave(ArchDest *); // Organiza y guarda matriz de "structs archivo" a archivo binario en disco, organizado alfabeticamente.

int NombresRepetidos(char *, ArchDest);	// compara en ruta dada por primer parametro Archdest.Nombre para cada struct en archivo fisico.

int Buscar(char*,int);		// clasifica la busqueda y maneja errores;

int BuscarNombre(char *);	// busca por nombre en el archivo binario.

int BuscarCat(char *);		// busca por categoria en el archivo binario.

int BuscarFecha(int,int,int);	// Busca por fecha en los archivos.

int CambiarNombre(char *, char *,char *,char *); // Cambia el nombre del archivo especificando su path.

int ExportXML(ArchDest, int); // genera archivo xml de busqueda actual dato por dato

int Elimination(char * , char* , int , int , int); // Elimina un archivo si se especifica sus parametros

int logger(char *);		// Funcion de log (Bitacora) a archivo

char * tiempo(void);	// Devuelve la hora y la fecha actual en una cadena de char.

void AbrirLista(void);	// Abre cuadro de dialogo para abrir lista, hace validaciones primitivas

int BuscarGUI(int);	// Muestra ventana de busqueda segun el flag que se le pase por valor.

int ElimGUI(void); // Muestra la pantalla de eliminacion.

int RenGUI(void); // Muestra la pantalla de cambiar nombre de archivo.

/************************* 	main()  *****************************************/
//---------------------------------------------------------------------------/

int main(int argc, char* argv[])
{
	mt=0;			// inicio bandera modo texto
	// define las constantes
	strcpy(prgname,"HammerFile");
	ver = 1;


	if (argc > 1)		// si se llamo con cualquier parametro
	{
		if(argv[1][0]=='t')	// si se especifico modo texto
		{
			printf("entrando modo texto\n");
			mt = 1;
			// Llama a interfaz grafica o modo texto
			UItexto();
		}
		else
		{
			printf("Escribir parametro 't' para modo texto o no escribir ninguno para modo grafico\n");
		}
		return 0;
	}
	else		// si no se especifico parametro
	{
		printf("entrando modo grafico...\n");
		mt--;
			//Inicio de Drivers
		iniciographics();		//inicia el modo grafico
		mouseinit();           	//inicia el mouse
		OcultarPuntero();
		setbkcolor(0);
		setfillstyle(1,7);

		bar(0,0,getmaxx(),getmaxy());	//borra la pantalla a blanco
		MostrarPuntero();
		welcome();
		int s;
		s = GUI();
		closegraph();
		return s;
	}
}
/*************************************	GUI()  ******************************/
//---------------------------------------------------------------------------/

int GUI()
{
	int salida = 0;                 //ventana de bienvenida
	// CICLO PRINCIPAL DEL PROGRAMA


	while (!salida)
	{
			mostrargui();
		#ifdef DEBUG
		char * mm = new char;//debug
		outtextxy(getmaxx()/2,getmaxy()-16,ultoa(coreleft(),mm,10));  //debug
		#endif

		switch (mainflag)	// switch principal del programa
		{
		case 11: 				//cuando se presione abrir archivo
			AbrirLista();
		break;
		case 12:					// cuando se presione organizar
			OcultarPuntero();
			YesNoWindw * organiza = new YesNoWindw("Organizar archivo de entrada","Presione [Si] si desea guardar","los datos actualmente cargados");
			organiza->DrawWindow();
			MostrarPuntero();
			organiza->RunWindow();
			if ( organiza->GetButton() == YES)
				SortSave(arch);
			delete organiza;
		break;
		case 13:            	// cuando se presione salir
			salida = dismiss(0);	//llamada a dismiss para ventana de despedida
		break;                             
		case 21:                // cuando se presione Buscar por Nombre
			if ( BuscarGUI(mainflag) > 0)
				salida = dismiss(2);
		break;
		case 22:                //cuando se presione buscar por tipo
			if ( BuscarGUI(mainflag) > 0)
				salida = dismiss(2);
		break;
		case 23:                //cuando se presione buscar por fecha
			if ( BuscarGUI(mainflag) > 0)
				salida = dismiss(2);
		break;
		case 24:                //cuando se presione
			salida = ElimGUI();
		break;
		case 25:                //cuando se presione
			salida = RenGUI();
		break;
		case 31:                //cuando se presione ayuda
			help(mainflag);
		break;
		case 32:                //cuando se presione manual de usuario
			help(mainflag);
		break;
		case 33:                //cuando se presione acerca de...
			help(mainflag);
		break;
		}
		outmenu = 0;			// se sale del bucle de la interfaz grafica
		OcultarPuntero();
		setfillstyle(1,7);
		bar(0,0,getmaxx(),getmaxy());
		MostrarPuntero();
  }
return salida;
}


/****************************  mostrargui() *********************************/
//---------------------------------------------------------------------------/
void mostrargui()       // MUESTRA EL MENU
{

	OcultarPuntero();
	setlinestyle(0,1,1);	//hack para no dibujar lineas gruesas en los objetos.

	// Asigna nombres a los menues
	char nombres[3][15];// =
//	{
//	"^Archivo\x0","A^dministrador\x0","A^yuda\x0"
//	};
	strcpy(nombres[0],"^ARCHIVO");
	strcpy(nombres[1],"A^DMINISTRADOR");
	strcpy(nombres[2],"A^YUDA");

	// Matriz para establecer el tamano y la ubicacion
	// de cada menu.
	int tam[3], x0[3];

	// Establece el tamano  y coordenadas
	// de cada boton que abrira los menues desplegables.
	tam[0] = textwidth(nombres[0]);
	tam[1] = textwidth(nombres[1]);
	tam[2] = textwidth(nombres[2]);
	x0[0] = 0;
	x0[1] =  x0[0] + tam[0] + 1;
	x0[2] =  x0[1] + tam[1] + 1;
		// Generacion de objetos de menu establecidos en control.h
		// Barra de menu de fondo
	Windw *barramenu = new Windw(0,0,getmaxx(),18,0,1);
		// botones
	aboton *archv = new aboton(x0[0],0,tam[0],nombres[0]);
	aboton *admin = new aboton(x0[1],0,tam[1],nombres[1]);
	aboton *hlp = new aboton(x0[2],0,tam[2],nombres[2]);


		// dibuja objetos llamando a su funcion mienbro de dibujo.
	barramenu->DrawWindow(); // dibuja barra de menu.

	archv->DrawWindow();
	admin->DrawWindow();    // Dibuja los botones de cada menu.
	hlp->DrawWindow();

	MostrarPuntero();
	if (mainflag == 0)
		screenmsg("Presione [F1] para ayuda",750);


	// Ciclo principal del menu
	while ((banmenu >=0) && (banmenu <7)  && outmenu == 0)
	{
		GetEvent(evntmsg); // espera respuesta de mouse o teclado
		if (evntmsg.type == KEYBD)
		{
			if (evntmsg.key == 0x3b00)	//f1
			{
				help(31);
			}
			if (evntmsg.key == 0x2d18) // ctrl + x
			{
//				abort();
				dismiss(1);      // Si se presiona CTRL+X
			}
			if (evntmsg.key == 0x3d00)			//F3
			{
				BuscarGUI(21);
			}
			if (evntmsg.key == 0x6000)			//Ctrl+F3
			{
				BuscarGUI(22);
			}
			if (evntmsg.key == 0x5600) // Shift + F3
			{
				BuscarGUI(23);
			}
			if (evntmsg.key == 0x5300) // Del
			{
				ElimGUI();
			}
			if (evntmsg.key == 0x3c00) // F2
			{
				RenGUI();
			}
			OcultarPuntero();
			bar(0,19,getmaxx(),getmaxy());
			MostrarPuntero();

		}
		if (archv->Clicked(evntmsg))
		{
			muestramenu(banmenu,-1);
			banmenu=1;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		 //button = OK;
		}
		if (admin->Clicked(evntmsg))
		{  // button = CANCEL;
			muestramenu(banmenu,-1);
			banmenu = 2;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
		if (hlp->Clicked(evntmsg))
		{  // button = CANCEL;
			muestramenu(banmenu,-1);
			banmenu = 3;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);

		}
	}
	delete barramenu, archv, admin, hlp;
//	delete [] nombres;
}


/*****************************	muestramenu()********************************/
//---------------------------------------------------------------------------/
void muestramenu(int flag, int x) //x condicion,-1 destruye menu
{

	int y0=19;
	char cmd[5][32]=                    // matriz de string para cada nombre
	{                                // elemento de menu(comandos)
	NULL,NULL,NULL,NULL,NULL
	};

	int posy[5];						// matriz que almacenara posiciones

	int limite = 5;//(sizeof( *cmd[flag + 1] ) + 1); // Establece limite para el
												// sig. ciclo.
	int y = 19;
	for (int i=0; i< limite; i++)		// calcula posicion en y para cada
	{                                   // elemento del menu
		posy[i] = (y*(i+1)) +2;

	}

	int j = 0;
	Windw fmenu(0,y0,0,100,0,0);		// crea ventana de fondo para cada
											// menu
	if (x!=-1)
	{
		fmenu.setwx(x);
		switch (flag)     		//asigna dimensiones para cada menu
		{
			case 1:
//				printf("clicked prog\n"); //debug
				fmenu.setwh(54);
                strcpy(cmd[0]," Archivo de Entrada CTRL+E");
                strcpy(cmd[1]," Organizar          CTRL+O");
                strcpy(cmd[2]," Salir              CTRL+X");
			break;
			case 2:
//				printf ("clicked lin\n"); //debug
				fmenu.setwh(90);
				strcpy(cmd[0]," Buscar por Nombre...   F3");
				strcpy(cmd[1]," Buscar por Tipo... CTR+F3");
				strcpy(cmd[2]," Buscar por Fecha...SFT+F3");
				strcpy(cmd[3]," Eliminar Archivo...   DEL");
				strcpy(cmd[4]," Renombrar Archivo...   F2");
			break;
			case 3:
//				printf ("clicked geom\n"); //debug
				strcpy(cmd[0]," Ayuda...         F1");
				strcpy(cmd[1]," Manual de Usuario  ");
				strcpy(cmd[2]," Acerca de...       ");
				fmenu.setwh(54);
			break;
		};
		fmenu.setww(textwidth(cmd[0])+8);
		OcultarPuntero();
		fmenu.DrawWindow();	//dibuja la ventana de cada menu

//		delay(1000);
// espera valor de retorno para asignarlo a la bandera principal
//		mainflag = dibujamenu(flag,x,y0);

    	setcolor(1);       // establece color de texto.

    	switch(flag)
    	{
		case 1:
    		outtextxy(x+2,posy[0],cmd[0]);
    		line(x+10,posy[1]-5,x+115,posy[1]-5);
    		outtextxy(x+2,posy[1],cmd[1]);
    		line(x+10,posy[2]-5,x+115,posy[2]-5);
			outtextxy(x+2,posy[2],cmd[2]);
    		
    	break;
		case 2:
			 outtextxy(x+2,posy[0],cmd[0]);
    	     line(x+10,posy[1]-5,x+90,posy[1]-5);
    	     outtextxy(x+2,posy[1],cmd[1]);
    	     line(x+10,posy[2]-5,x+90,posy[2]-5);
    	     outtextxy(x+2,posy[2],cmd[2]);
    	     line(x+10,posy[3]-5,x+90,posy[3]-5);
    	     outtextxy(x+2,posy[3],cmd[3]);
    	     line(x+10,posy[4]-5,x+90,posy[4]-5);
    	     outtextxy(x+2,posy[4],cmd[4]);
    	     
		break;
  	    case 3:
			 outtextxy(x+2,posy[0],cmd[0]);
			 line(x+10,posy[1]-5,x+90,posy[1]-5);
			 outtextxy(x+2,posy[1],cmd[1]);
			 line(x+10,posy[2]-5,x+90,posy[2]-5);
			 outtextxy(x+2,posy[2],cmd[2]);
		break;
	};
	setcolor(1);    //resetea al color de trazo
	MostrarPuntero();

	// invoca la funcion clicmenu que establece rango.
	j = clicmenu(flag,x+2,posy[0]);
	mainflag = j;
//	printf("Mainflag es: %d ",mainflag); //debug

 //oculta y borra el objeto
	OcultarPuntero();

	setfillstyle(1,7);
	bar (0,19,getmaxx(),getmaxy());
	outmenu = 1;			// establece salida de bucle principal de la interfaz grafica
		MostrarPuntero();
	}
	else
	{

	setfillstyle(1,7);
	bar (0,19,getmaxx(),getmaxy());
	/*
		switch (flag)
		{
			case 1:	printf("ocult prog, ");		//debug
			break;
			case 2:	printf ("ocult lin, ");		//debug
			break;
			case 3:	printf ("ocult geom, ");		//debug
			break;
			case 4:	printf ("ocult spray, ");		//debug
			break;
			case 5:	printf ("ocult color, ");		//debug
			break;
			case 6:	printf("ocult ayuda, ");		//debug
			break;
			default: printf("1st ");		//debug
			break;
		};*/
	}
}

/******************************* clicmenu() *********************************/
//---------------------------------------------------------------------------/
int clicmenu(int flag,int x, int y) // retorna en decimal el valor de la bandera
									// y en unidad el valor del boton
{
	int clic, tc,numcom = 0;         // numcom establecera el elemento del menu
									 // al que se le hizo clic
//	setcolor(1);//debug
//	outtextxy(getmaxx()-100,200,"si");  //debug
//	outtextxy(getmaxx()-100,200,"tambien");//debug

	// espera entrada de mouse o teclado mientras la bandera clic no sea 1
	while ((clic!=1) /*|| (tc==0)*/)
		{
			//if (flag == 1)
			GetEvent(evntmsg);
			// eventos de teclado
			if ((flag == 1) && (evntmsg.type == KEYBD))
			{
				if (evntmsg.key == 0x2d18)			//Ctrl+X
				{
					numcom = 3;
					clic = 1;
				}
				if (evntmsg.key == 0x1205)			//Ctrl+E
				{
					numcom = 1;
					clic = 1;
				}
				if (evntmsg.key == 0x180f) // ctrl + O
				{
					numcom = 2;
					clic = 1;
				}
			}
			if ((flag == 2) && (evntmsg.type == KEYBD))
			{
				if (evntmsg.key == 0x3d00)			//F3
				{
					numcom = 1;
					clic = 1;
				}
				if (evntmsg.key == 0x6000)			//Ctrl+F3
				{
					numcom = 2;
					clic = 1;
				}
				if (evntmsg.key == 0x5600) // Shift + F3
				{
					numcom = 3;
					clic = 1;
				}
				if (evntmsg.key == 0x5300) // Del
				{
					numcom = 4;
					clic = 1;
				}
				if (evntmsg.key == 0x3c00) // F2
				{
					numcom = 5;
					clic = 1;
				}

			}
			//comando 1
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+150) &&
					(PosVertGraf() > (y-2)) && (PosVertGraf() < 2*(y-2)) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 1;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			// Comando 2
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+150) &&
					(PosVertGraf() > 2*(y-2)) && (PosVertGraf() < 3*(y-2)) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 2;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			//comando 3
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+150) &&
					(PosVertGraf() > 3*(y-2)) && (PosVertGraf() < 4*(y-2)) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 3;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+150) &&
					(PosVertGraf() > 4*(y-2)) && (PosVertGraf() < 5*(y-2)) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 4;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			 //comando 5
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+150) &&
					(PosVertGraf() > 5*(y-2)) && (PosVertGraf() < 6*(y-2)) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 5;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			// clic fuera de area de menu cierra el menu
			if ((PosHoriGraf() < x) || (PosHoriGraf() > x+150) ||
				(PosVertGraf() > 6*(y-2)) && BotonPulsado() !=0)
					clic = 1;

	}
	return (flag*10)+numcom;    // retorna la bandera del parametro como decena
}                               // y el numero de comando como unidad

/******************************* AbrirLista()	*****************************/
//---------------------------------------------------------------------------/
void AbrirLista()
{
	OcultarPuntero();
	char op[64];
	int s;
	s = 0;
	MostrarPuntero();

	while (s ==0)
	{
		InputWindw * escog = new InputWindw("Abrir Archivo Lista","Ingrese la RUTA COMPLETA y","el nombre del archivo");
		escog->DrawWindow();
		escog->RunWindow();


		if (escog->GetButton() == OK)
		{
			escog->GetInput(op);
			if (strstr(op,":\\") == NULL || strlen(op) > 32)
			{
				// crea ventana de aviso
				OKWindw * aviso = new OKWindw("AVISO","Ingrese un path"
													," correcto");// lims);
				aviso->DrawWindow();
				aviso->RunWindow();
				// elimina los punteros
				delete aviso;
			}
			else
			{
				s = OpenList(op,arch);
			}

		}
		else if (escog->GetButton() == CANCEL)
		{
			s++;
		}
		delete escog;
	}

  //	return s;
}
/******************************* BuscarGUI()	*****************************/
//---------------------------------------------------------------------------/
int BuscarGUI( int flag)
{
	OcultarPuntero();
	char op[64], sm[5],sd[5];
	int s,m,d,a;
	s = 0;
	m=0;
	d=0;
	a=0;
	MostrarPuntero();

	while (s ==0)
	{
		InputWindw * escog;
		switch (flag)
		{
		case 21:
			escog = new InputWindw("Buscar archivo por Nombre","Ingrese el nombre de archivo a","buscar (Puede usar comodines).");
		break;
		case 22:
			escog = new InputWindw("Buscar archivo por Tipo","Ingrese el tipo de archivo a","buscar (Puede usar comodines)");
		break;
		case 23:
			escog = new InputWindw("Buscar archivo por Fecha","Ingrese la fecha de archivo a ","buscar en formato dd/mm/aaaa");
		break;
		}
		escog->DrawWindow();
		escog->RunWindow();


		if (escog->GetButton() == OK)
		{
			escog->GetInput(op);
			switch (flag)
			{
			case 21:
				if (strchr(op,'.') == NULL || strlen(op) > 32)
				{
					// crea ventana de aviso
					CapTWindw * aviso = new CapTWindw("AVISO","Ingrese nombre de archivo"
														,"correcto");// lims);
					aviso->DrawWindow();
					aviso->RunWindow();
					// elimina los punteros
					delete aviso;
				}
				else
				{
					s = Buscar(op,1);
				}
			break;
			case 22:
				if (strlen(op) == 0 || strlen(op) > 32)
				{
					// crea ventana de aviso
					CapTWindw * aviso = new CapTWindw("AVISO","Ingrese una categoria"
														,"correcta");// lims);
					aviso->DrawWindow();
					aviso->RunWindow();
					// elimina los punteros
					delete aviso;
				}
				else
					s = Buscar(op,2);
			break;
			case 23:
				if (op[2]!='/' && op[4]!='/')//strchr(op,'/') == NULL)
				{
					// crea ventana de aviso
					CapTWindw * aviso = new CapTWindw("AVISO","Ingrese una fecha en"
														,"formato dd/m/aaaa");// lims);
					aviso->DrawWindow();
					aviso->RunWindow();
					// elimina los punteros
					delete aviso;
				}
				else
				{
					strncpy(sd,op,5);
					strnset(strpbrk(sd,"/"),'\x0',1);
					strncpy(sm,strchr(op,'/') + 1,5);
					strnset(strpbrk(sm,"/"),'\x0',1);

					a =	atoi(strrchr(op,'/') + 1);
					m = atoi(sm);
					d = atoi(sd);
					s = BuscarFecha(d,m,a);
				}
			break;
			}

		}
		else if (escog->GetButton() == CANCEL)
		{
			s = -1;
		}
		delete escog;
	}
	return s;
}
/******************************* ElimGUI()	    *****************************/
//---------------------------------------------------------------------------/
int ElimGUI(void)
{
	int sf;		// bandera
	sf = 0;
	char nm[32], cat[32];
	char *dd = new char;
	char *mm = new char;
	char *aa = new char;
	nm[0] = cat[0] = dd[0] = mm[0] = aa[0] = 0;
	OKWindw * val;
	Input in1(100,50,"Archivo ");
	Input in2(100,100,"Categoria ");
	Input in3(100,150,"Dia ");
	Input in4(250,150,"Mes ");
	Input in5(400,150,"A~no ");
	Button btnOK(150,200,"^Eliminar");
	Button btnCan(300,200,"^Cancelar");

	in1.DrawWindow();
	in2.DrawWindow();
	in3.DrawWindow();
	in4.DrawWindow();
	in5.DrawWindow();
	btnOK.DrawWindow();
	btnCan.DrawWindow();
	while (!sf)
	{
		GetEvent(evntmsg);

		if (evntmsg.mx > 100 && evntmsg.mx < 300
		&& evntmsg.my > 50 && evntmsg.my < 50 + 18)// && evntmsg.type == MBUTTON)
		{
			in1.RunWindow();
		}
		else if (evntmsg.mx > 100 && evntmsg.mx < 300
		&& evntmsg.my > 100 && evntmsg.my < 100 + 18)// && evntmsg.type == MBUTTON)
		{
			in2.RunWindow();
		}
		else if (evntmsg.mx > 100// && evntmsg.mx < 300
		&& evntmsg.my > 150 && evntmsg.my < 150 + 18)// && evntmsg.type == MBUTTON)
		{
			if (evntmsg.mx > 100 && evntmsg.mx < 250)
				in3.RunWindow();
			else if (evntmsg.mx > 250 && evntmsg.mx < 400)
				in4.RunWindow();
			if (evntmsg.mx > 400 && evntmsg.mx < 550)
				in5.RunWindow();
		}
		else if ((evntmsg.mx > 100 && evntmsg.mx < 500)
		&& (evntmsg.my < 50 || evntmsg.my > 150 + 18))// && evntmsg.type == MBUTTON)
		{
			if (btnOK.Clicked(evntmsg))
			{
				in1.GetInput(nm);
				in2.GetInput(cat);
				in3.GetInput(dd);
				in4.GetInput(mm);
				in5.GetInput(aa);
				if (strchr(nm,'.')!=NULL && cat[0]!=0 && atoi(dd) > 0 && atoi(dd) < 32 // validacion
					&& atoi(mm) > 0 && atoi(mm) < 13
					&& atoi(aa) > 0 && atoi(dd) < 9999)
				{
					if (Elimination(nm,cat,atoi(dd),atoi(mm),atoi(dd)) == 0)
						logger("Archivo a eliminar no existe");
					else
						logger("Archivo eliminado satsfactoriamente");
					sf = 1;
				}
				else
				{
					val = new OKWindw("Aviso","Ingrese valores correctos","o complete datos");
					val->DrawWindow();
					val->RunWindow();
					delete val;
				}
			}
			else if (btnCan.Clicked(evntmsg))
				sf = 1;

		}
	}
	delete mm,dd,aa;
	return 0;
}
/******************************* RenGUI()	    *****************************/
//---------------------------------------------------------------------------/
int RenGUI(void)
{
	int sf;		// bandera
	sf = 0;
	char *nm1 = new char;
	char *nm2 = new char;
	char *path1 = new char;
	char *path2 = new char;
	nm1[0] = nm2[0] = path1[0] = path2[0] = 0;
	OKWindw * val;
	Input in1(100,50,"Path ");
	Input in2(100,100,"Nombre ");
	Input in3(100,150,"Nuevo Path ");
	Input in4(100,200,"Nuevo Nombre ");
	Button btnOK(150,300,"^Cambiar");
	Button btnCan(300,300,"^Cancelar");
	in1.DrawWindow();
	in2.DrawWindow();
	in3.DrawWindow();
	in4.DrawWindow();
	btnOK.DrawWindow();
	btnCan.DrawWindow();
	while (!sf)
	{
		GetEvent(evntmsg);

		if (evntmsg.mx > 100 && evntmsg.mx < 300
		&& evntmsg.my > 50 && evntmsg.my < 50 + 18)// && evntmsg.type == MBUTTON)
		{
			in1.RunWindow();
		}
		else if (evntmsg.mx > 100 && evntmsg.mx < 300
		&& evntmsg.my > 100 && evntmsg.my < 100 + 18)// && evntmsg.type == MBUTTON)
		{
			in2.RunWindow();
		}
		else if (evntmsg.mx > 100 && evntmsg.mx < 300
		&& evntmsg.my > 150 && evntmsg.my < 150 + 18)// && evntmsg.type == MBUTTON)
		{
			in3.RunWindow();
		}
		else if (evntmsg.mx > 100 && evntmsg.mx < 300
		&& evntmsg.my > 200 && evntmsg.my < 200 + 18)// && evntmsg.type == MBUTTON)
		{
			in4.RunWindow();
		}
		else if ((evntmsg.mx > 150 && evntmsg.mx < 500)
		&& (evntmsg.my < 50 || evntmsg.my > 200 + 18))// && evntmsg.type == MBUTTON)
		{
			if (btnOK.Clicked(evntmsg))
			{
				in1.GetInput(path1);
				in2.GetInput(nm1);
				in3.GetInput(path2);
				in4.GetInput(nm2);
				if (strchr(nm1,'.')!=NULL && strchr(nm2,'.')!=NULL
					&& strchr(path1,':')!=NULL && strchr(path2,':')!=NULL
					&& strchr(path1,'\\')!=NULL && strchr(path2,'\\')!=NULL)
				{
					if (strlen(nm1) < 37 && strlen(nm2) < 37)
					{
						if ( CambiarNombre(path1,nm1,path2,nm2) == 0)
							logger("Archivo a renombrar no existe");
						else
							logger("Archivo renombrado satisfactoriamente");
						sf = 1;
					}
					else
						logger("ingrese un nombre menor a 32 caracteres");

				}
				else
				{
					val = new OKWindw("Aviso","Ingrese valores correctos","o complete datos");
					val->DrawWindow();
					val->RunWindow();
					delete val;
				}
			}
			else if (btnCan.Clicked(evntmsg))
				sf = 1;

//		else if ((evntmsg.mx > 300 && evntmsg.mx < 450)
//		&& (evntmsg.my > 300 && evntmsg.my < 350 ))// && evntmsg.type == MBUTTON)
//			if (btnCan.Clicked(evntmsg))
//				sf = 1;
		}
	}
	delete nm1,nm2,path1,path2;
	return 0;
}

/*******************************  dismiss()	*********************************/
//---------------------------------------------------------------------------/
int dismiss(int subito)
{
	OcultarPuntero();
	setfillstyle(1,7);
	bar(0,0,getmaxx(),getmaxy());

	YesNoWindw * salida;
	switch (subito)
	{
		case 2:
			salida = new YesNoWindw("Ver Resultados de Busqueda","Le gustaria ver el archivo de","resultados de busqueda?");
		break;
		default:
			salida = new YesNoWindw("Salida","Seguro que desea salirse","de esta aplicacion??");
		break;
	}

	salida->DrawWindow();
	MostrarPuntero();
	salida->RunWindow();

	if (salida->GetButton() == YES )
	{
		logger("Adios...");
		delay(500);
		if (subito > 0)
		{
			switch ( subito )
			{
			case 1:
				logger("salida subita del programa");
				closegraph();
				exit(0);
			break;
			case 2:     // En caso de que se desee ver el XML
				screenmsg("Se Abrira archivo un archivo XML con Internet Explorer",2500);
				logger("Abriendo archivo XML");
/*				if ( system("c:\\archiv~1\\intern~1\\iexplore.exe c:\\found.xml") == 0)
				{
					closegraph();
					exit(0);
				}
				else if( system("c:\\progra~1\\intern~1\\iexplore.exe c:\\found.xml") == 0)
				{
					closegraph();
					exit(0);
				}
				else
				{
					logger("Internet Explorer no instalado, salida no normal");
					delay(3000);
					closegraph();
					abort();
				}

*/
				system("c:\\archiv~1\\intern~1\\iexplore.exe c:\\found.xml");
				system("c:\\progra~1\\intern~1\\iexplore.exe c:\\found.xml");
				closegraph();
				exit(0);
			break;
			}
		}
		delete salida;
		return 1;
	}
	else
	{
		delete salida;
		return 0;
	}
}


/******************************* 	help()  *********************************/
//---------------------------------------------------------------------------/
void help(int f)
{
	switch( f )
	{
	case 31:		//dibujar ventana de ayuda
		CapWindw * hlp5 = new CapWindw(100,100,308,200,
									1,1,"Ayuda en Linea General");// = new CapWindw
		hlp5->DrawWindow();
		setcolor(0);
		outtextxy(112,124 + 12*0,"Accesos de Teclado:");
		outtextxy(112,124 + 12*1,"- CTRL + A : Menu Archivo");
		outtextxy(112,124 + 12*2,"Abre y guarda archivos de entrada.");
		outtextxy(112,124 + 12*3,"- CTRL + D : Menu Administrador");
		outtextxy(112,124 + 12*4,"Permite busqueda por nombre, ");
		outtextxy(112,124 + 12*5,"fecha, tipo, asi como renombrar y");
		outtextxy(112,124 + 12*6,"eliminacion de archivos. ");
		outtextxy(112,124 + 12*7,"- CTRL + Y : Menu Ayuda");
		outtextxy(112,124 + 12*8,"Permite ver la ayuda general,  ");
		outtextxy(112,124 + 12*9,"manual de usuario e informacion de");
		outtextxy(112,124 + 12*10,"este programa.");
		outtextxy(112,124 + 12*11,"-CTRL+X : Cierra este programa");
		outtextxy(112,124 + 12*12,"------NOTA----------");
		outtextxy(112,124 + 12*13,"Leer man. de usuario para + info");

		hlp5->RunWindow();

		delete hlp5;
		setcolor(1);
	break;
	case 32:    // abre el manual de usuario con programa externo y cierra el programa
/*		char *path;
		path = searchpath("winword.exe");
		printf("\n\n\nBuscando MS Word... : %s\n",path);
*/
//		execl("more","c:\\prog1\\proy1\\test.txt",NULL);
		setcolor(1);
		outtextxy(getmaxx()/2 - 200,getmaxy()/2,
					"Se Abrira un programa externo en 2 seg. y HammerFile se cerrara");
		outtextxy(getmaxx()/2 - 200,getmaxy()/2 + 16,
				"Cuando termine de leer la ayuda, abra HammerFile de nuevo.");
		delay (2000);
		//cambiar el path cuando se entregue el proyecto.
		//system("c:\\\%programfiles\%\\%intern~1\%\\\iexplore.exe c:\\prog1\\proy1\\test.txt");
		system("copy man.mht c:\\man.mht");
		system("c:\\archiv~1\\intern~1\\iexplore.exe c:\\man.mht");
		system("c:\\progra~1\\intern~1\\iexplore.exe c:\\man.mht");
		exit(0);
	break;
	case 33:    //muestra ventana de acerca de...
		OKWindw about("Acerca de HammerFile...",
									"HammerFile v1.0 - Por: Erik Giron Marquez",
									"C# 200313492; Proyecto #2. IPC1. USAC 2005");
		about.DrawWindow();
		about.RunWindow();
//		delete about;
	break;
	}
}
/********************************* 	UItexto()  ******************************/
//---------------------------------------------------------------------------/
void UItexto()
{
	int select = 0;
	char path1[32];
	char path2[32];
	char nombre1[32];
	char nombre2[32];
	while( (select < 1) || (select > 8))
	{
		printf("\n\t\t\tBienvenido a %s V. %1.2f\n",prgname,ver);
		printf("\n\t\tEl modo texto es una alternativa al modo grafico, sin embargo puede fallar en cualquier momento en este modo");
		printf("\t\t\tSeleccione lo que desee hacer:\n\n");
		printf("\t1. Abrir Archivo de entrada\n");
		printf("\t2. Organizar Archivo de Entrada\n");
		printf("\t3. Buscar por Nombre\n");
		printf("\t4. Buscar por Tipo\n");
		printf("\t5. Buscar por Fecha\n");
		printf("\t6. Eliminar\n");
		printf("\t7. Renombrar\n");
		printf("\t8. Salir\n");
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
			s=0;
			while(s == 0)
			{
				printf("Escribir nombre del archivo\n");
				scanf(" %[^\n]",mainpath);
				printf("%s",&mainpath);
				s = Buscar(mainpath, 1);
//				free(mainpath);
				select=0;

			}
		break;
		case 4:
			s=0;
			while(s == 0)
			{
				printf("Escribir categoria del archivo\n");
				scanf(" %[^\n]",mainpath);
				printf("%s",&mainpath);
				s = Buscar(mainpath, 2);
//				free(mainpath);
					select=0;

//				execlp("start","c:\\found.xml");
				system("c:\\archiv~1\\intern~1\\iexplore.exe c:\\found.xml");
				system("c:\\progra~1\\intern~1\\iexplore.exe c:\\found.xml");
				exit(0);
			}
		break;
		case 5:
			s=0;
			while(s == 0)
			{
				printf("Escribir dia,mes,a~no del archivo\n");
				scanf("%d",&d);
				scanf("%d",&m);
				scanf("%d",&a);
				printf("%d/%d/%d\n",d,m,a);
				s = BuscarFecha(d,m,a);
//				free(mainpath);
				select=0;
			}
		break;
		case 6:
			s=0;
			while(s == 0)
			{
				printf("Escribir nombre, tipo, dia,mes,a~no del archivo\n");
				scanf(" %[^\n]",mainpath);
				scanf(" %[^\n]",tipo);
				scanf("%d",&d);
				scanf("%d",&m);
				scanf("%d",&a);
				printf("%s,%s, %d/%d/%d\n",&mainpath,&tipo,d,m,a);
				s = Elimination(mainpath,tipo,d,m,a);
//				free(mainpath);
				select=0;
			}

		break;
		case 7:
			s=0;
			while(s == 0)
			{
				printf("Escribir ruta 1, nombre 1, ruta 2, nombre 2\n");
				scanf(" %[^\n]",path1);
				scanf(" %[^\n]",nombre1);
				scanf(" %[^\n]",path2);
				scanf(" %[^\n]",nombre2);
				printf("%s%s, %s%s\n",&path1,&nombre1,&path2,&nombre2);
				s = CambiarNombre(path1,nombre1,path2,nombre2);
//				free(mainpath);
				select=0;
			}

		break;
		case 8:
		abort();
		break;

		//default:
		//printf("ingrese alguna opcion valida");
		//break;
		}
   }

}


/*********************************	OpenList()  *****************************/
//---------------------------------------------------------------------------/
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
	int i=0;
	int k=0;
	char c;
	c='\000';
	int end;
	end = 0;

	logger("abriendo archivo de entrada...");	// mensaje
	lista = fopen(ruta,"r");	// abre archivo en modo solo lectura

//	printf("%x",&lista);

	if (lista != NULL &&
		(
		 (getc(lista) > 64 && getc(lista) < 91) ||
		 (getc(lista) > 96 && getc(lista) < 123)
		)
	   )		// si archivo existe y su primer caracter es desconocido
	{
		rewind(lista);
//		free(archivo1);   		// borra cualquier instancia anterior de archivos
		// puntero a archivos que almacenara los datos(array dinamico)
//		archivo1 = (ArchDest*) malloc(sizeof(ArchDest)*100);

	//archivo1 = (archivos *)calloc(100,sizeof(archivos)); //asigna 24000 bytes para struct

		// reinicia el struct si ya existe
		for (int f=0;f< 256; f++)
		{
			strnset(archivo1[i].path,0,strlen(archivo1[i].path));
			strnset(archivo1[i].nombre,0,strlen(archivo1[i].nombre));
			strnset(archivo1[i].ext,0,strlen(archivo1[i].ext));
			strnset(archivo1[i].tipo,0,strlen(archivo1[i].tipo));
		}


		while(end <=0) 		// mientras la bandera end sea menor a 0
		{
				fscanf(lista,"%[^' '^\n]",&text[i]);
				fseek(lista,(sizeof(char)*strlen(text[i])),SEEK_CUR); // se adelanta la lista
				switch (i)
				{
				case 0:
					if (isalnum(text[i][0]) == 0)
						{
							end++;
							logger("Archivo erroneo: nombre de archivo debe iniciar con letras o numeros");
						}
				break;
				case 1:
					if (isalpha(text[i][0]) == 0)
						{
							end++;
							logger("Archivo erroneo: tipo de archivo debe iniciar con letras");
						}
				break;
				case 2:
					if (isdigit(text[i][0]) == 0)
						{
							end++;
							logger("Archivo erroneo: fecha de archivo debe iniciar con digito");
						}
				break;
				}
				i++;

				if ((c=getc(lista))=='\n' || feof(lista)!=0) //almacena en el struct cuando halla cambio de linea.
				{
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
					strnset(strpbrk(fecha[0],"/"),'\x0',1);
					strncpy(fecha[1],strchr(text[2],'/') + 1,5);
					strnset(strpbrk(fecha[1],"/"),'\x0',1);

					archivo1[k].a =	atoi(strrchr(text[2],'/') + 1);
					archivo1[k].m = atoi(fecha[1]);
					archivo1[k].d = atoi(fecha[0]);
					archivo1[k].n = 0;

					// copia nombre, path y extension al struct
					strncpy(archivo1[k].ext,strrchr(text[0], '.') + 1,strlen(strrchr(text[0], '.') + 1));
					strncpy(archivo1[k].nombre,strrchr(text[0], '\\') + 1,
							strlen(strrchr(text[0], '\\') + 1) - strlen(strrchr(text[0], '.') + 1) - 1);
					strncpy(archivo1[k].path , text[0], strlen(text[0]) - strlen( strrchr( text[0], '\\' ))+1);

					// copia tipo a struct
					strncpy(archivo1[k].tipo,text[1],strlen(text[1]));

					#ifdef DEBUG
					printf("Nombre:%s.%s Fecha:%d/%d/%d\n",archivo1[k].nombre,archivo1[k].ext,archivo1[k].d,
														archivo1[k].m,archivo1[k].a);
					#endif

					// reset
//					free(text);  	//libera memoria usada por el vector texto.
					i = 0;         // reinicia i para volver a leer
					k++;
					if (feof(lista)!=0 || k == 254)
					{
						archivo1[k-1].fin = 1;
						end++;
						if (k == 255)         // validacion para que no se vuelque la memoria al ingresar mas de 255 caracteres
						{
							logger("Archivo de entrada muy grande para continuar...");
							logger("... se usaran los primeros 255 datos");
							end++;
						}
					}
				}
			c=(char)0;

		}
		#ifdef DEBUG
		printf("\n---------------\n");
		#endif
		logger("cerrando archivo de entrada");
//		SortSave(archivo1);
//		free(archivo1);
//		delete archivo1;
		fclose(lista);
		k=0;
		return 1;

	}
	else
	{
		logger("Archivo de entrada o directorio no existen o erroneos, ingrese de nuevo");
		return 0;
	}
}


/**********************************	logger()  *******************************/
//---------------------------------------------------------------------------/
int logger(char * mensaje)
{


	FILE * log;			// punteros a archivo para lista, log(bitacora)
	// escribe mensaje en pantalla
	if (mt <= 0)
	{
	    screenmsg(mensaje,700);
	}
	else
	{
		printf("%s\n",mensaje);
	}

	// abre el archivo y escribe en este
//	#ifndef __BCC
	log = fopen("c:\\mensajes.log","a");
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


/***************************** 	SortSave()  *********************************/
//---------------------------------------------------------------------------/
int SortSave(ArchDest * arc)
{
	#define CHARMAX 100
	int orden[26][CHARMAX];	//guarda alfabeticamente el orden
	//(orden[j][k] donde j = {0=a,1=b,2=c,3=d,4=e,5=f,6=g,7=h,8=i,9=j,10=k,11=l,12=m,13=n,14=o,15=p,16=q17=r,18=s,19=t,20=u,21=v,22=w,23=x,24=y,25=z})
	//				k = numero de elemento donde esta la ocurrencia mas 1

	int i, j,k, cmp, ndat = 0;
	char inicial[2]; 		//cadena que contendra la inicial para comparar
	FILE * out;
	char filename[6];
	char ruta[32];
	char dicdir[9];

    ArchDest muestra;
	// inicializa a 0 la matriz de orden
	for (i=0;i< 26; i++)
	{
		for(j=0;j<CHARMAX;j++)
			orden[i][j] = 0;
	}
	strcpy(filename,"^.bin");
	strcpy(dicdir,"c:\\dic\\");
	strnset(ruta,'\x0',1);
	inicial[1] = 0;
	inicial[0] = 65;
	i=0;
	j=0;
	k=0;
		while(j<26)
		{
			inicial[0] = 65 + j;
			#ifdef DEBUG
			printf("%s \n",inicial);
			#endif
			//NOTA: USAR STRPBRK PARA ENCONTRAR EL "." Y EL ULTIMO "\"

			#ifdef DEBUG
			printf("comparando %s con %s \n",inicial,&arc[i].nombre);
			#endif
			j++;
			if((cmp=strnicmp(arc[i].nombre,inicial,1)) == 0)
			{
				while (orden[j][k]!=0)
					k++;
				orden[j][k] = i+1;
				(arc[i].fin==1)?(j=27):(j=0);
				i++;
				k=0;

				#ifdef DEBUG
				printf("-inicial de %s es igual a inicial de %s\n",arc[i-1].nombre,inicial);
				#endif
				inicial[0]=65;
			}

		}
	ndat = i;
	// TODO
	// crea carpeta diccionario
	strcat(ruta,dicdir);
	strcat(ruta,"bandera.bin");
//	printf("%s\n",ruta);
	while((out = fopen(ruta,"r"))==NULL)
	{
		int dr = 0;
		dr = mkdir("c:\\dic");//execlp("mkdir",dicdir,NULL);//system("mkdir d:\\dic");
//		if(errno!=ENOENT || errno!=EACCESS || errno!=ENOMEM)
//		{
		if(dr != 0)
		{
			logger("imposible crear carpeta diccionario");
			return 0;
		}
		else
		{
			out = fopen(ruta,"w+b");
			fwrite(&ndat,sizeof(int),1,out);
			fclose(out);
//		}
//		else
			logger("Creando carpeta diccionario en ...");
			logger(dicdir);
			strnset(ruta,'\x0',1);
			strcat(ruta,dicdir);
			strcat(ruta,"bandera.bin");
		}

	}
	if (out!=NULL)
	{
		fclose(out);
		for (i = 0; i<26; i++)
		{
			if(orden[i][0]!=0)
			{
				j=0;
				strnset(ruta,'\x0',1);
				filename[0]=(char)(64+i);
				strcat(ruta,dicdir);
				strcat(ruta,filename);
				logger("creando archivo:");
				logger(ruta);
/*				out = fopen(ruta,"a+b");
				//ESTA FUNCIONA BIEN
				while(orden[i][j]!=0)
				{
					fwrite(&arc[(orden[i][j] - 1)],sizeof(ArchDest),1,out);
					j++;
				}
				fclose(out);
*/              while(orden[i][j]!=0)
				{
					if(NombresRepetidos(ruta,arc[(orden[i][j]-1)])==0)
					{
						out = fopen(ruta,"a+b");
						fwrite(&arc[(orden[i][j] - 1)],sizeof(ArchDest),1,out);
						j++;
						fclose(out);
					}
					else j++;
				}
			}

		}


	}
	return 0;
}


/************************* 	tiempo()  ***************************************/
//---------------------------------------------------------------------------/
char * tiempo()
{
	time_t ahora;
	time(&ahora);
	return (ctime(&ahora));
};

                    
/************************* 	NombresRepetidos()  *****************************/
//---------------------------------------------------------------------------/
int NombresRepetidos(char * ruta, ArchDest a)
{
	FILE * input;
	ArchDest b;
	int i;
	int rs;
	#ifdef DEBUG
	printf("a comparar:%s\n",a.nombre); // debug
	#endif
	if((input=fopen(ruta,"rb"))!=NULL)
	{
		rs=0;      
		i=0;
		while(rs==0)
		{
			rs = feof(input);
			i++;
			fread(&b,sizeof(ArchDest),1,input);
//			fseek(input,sizeof(ArchDest)*i,SEEK_SET);
			if (strcmpi(a.path, b.path) == 0)
			{
				#ifdef DEBUG
				printf("comparando %s, con %s \n",a.path,b.path); // debug
				#endif
				if(strcmpi(a.nombre, b.nombre) == 0)
				{
					#ifdef DEBUG
					printf("comparando %s, con %s \n",a.nombre,b.nombre); // debug
					#endif
					fclose(input);
					return 1;
				}
//				else return 0;
			}
//			else
//				i++;
		}
	fclose(input);
	return 0;
	}
	else
	return 0;
}


/********************************* 	Buscar()  *******************************/
//---------------------------------------------------------------------------/
int Buscar(char * busqueda,int tipo)
{
	int retorno = 0;
	switch (tipo)
	{
		case 1:
			retorno = BuscarNombre(busqueda);
		break;
		case 2:
			retorno = BuscarCat(busqueda);
		break;
	}
	return retorno;
}

/**************************  BuscarNombre()  ********************************/
//---------------------------------------------------------------------------/
int BuscarNombre(char * busqueda)
{
	char nm[32];		// almacena nombre
	char ext[5];		// almacena extension
	FILE * in;
	char path[16];		// el path del archivo binario.
	short n = 0;		// define el numero de coincidencias
	ArchDest tmp;

	strcpy(path,"c:\\dic\\?.bin");
	if (strchr(busqueda,'.')!=NULL)
	{
		sscanf(busqueda,"%[^.]",&nm);
		nm[31]=0;
		strncpy(ext,strrchr(busqueda,'.')+1,3);
		ext[3]=0;
		#ifdef DEBUG
		printf("nombre: %s, extension: %s\n",nm,ext); // debug
		#endif
		// Caso 1
		if(strchr(nm,'*')!=NULL && strchr(ext,'*')!=NULL)
		{
			// Caso *nombre.*
			if((nm[0]=='*') && ( strlen(nm) > 1 ) && ( nm[strlen(nm)-1]!='*' ))
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if (strstr( strlwr(tmp.nombre) , strlwr(strchr(nm,'*')+1) ) != NULL
								&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext); // debug
								#endif
								ExportXML(tmp,2);
							}
							else
							{
								#ifdef DEBUG
								printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif DEBUG
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// Caso nombre*.*
			else if((nm[0]!='*') && ( strlen(nm)>1 ) && ( nm[strlen(nm)-1]=='*' ))
			{
				nm[strlen(nm)-1]=0;
				strnset(strchr(path,'?'),nm[0],1);
				logger("buscando coincidencias...");
				if((in = fopen(path,"rb"))!=NULL)
				{
					ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
					while(!feof(in))
					{
						fread(&tmp,sizeof(ArchDest),1,in);
						if (strstr( strlwr(tmp.nombre) ,strlwr(nm) ) != NULL
							&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
						{
							n++;
							#ifdef DEBUG
							printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
							#endif
							ExportXML(tmp,2);
						}
						else
						{
							#ifdef DEBUG
							printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
							#endif
						}
					}
					ExportXML(tmp,3);
						fclose(in);
				}
				else
					logger("no se encontraron coincidencias");
			}
			// Caso *nombre*.*
			else if((nm[0]=='*') && ( strlen(nm)>1 ) && ( nm[strlen(nm)-1]=='*' ))
			{
				nm[strlen(nm)-1]=0;
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if (strstr( strlwr(tmp.nombre) , strlwr(strchr(nm,'*')+1) ) != NULL
								&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
								#ifdef DEBUG
								printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// Caso *.*
			else if((nm[0]=='*') && ( strlen(nm)==1 ))
			{
//				nm[strlen(nm)-1]=0;
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if ((!feof(in)) && tmp.nombre[0]!=0) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
								#ifdef DEBUG
								printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
		}
		// Caso 2
		else if (strchr(nm,'*')!=NULL && strchr(ext,'*')==NULL)
		{	// Caso *nombre.ext
			if((nm[0]=='*') && ( strlen(nm)>2 ) && ( nm[strlen(nm)-1]!='*' ))
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if (strstr( strlwr(tmp.nombre) , strlwr(strchr(nm,'*')+1) ) != NULL
								&& strcmpi(ext,tmp.ext) == 0 && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
								#ifdef DEBUG
								printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// Caso nombre*.ext
			else if((nm[0]!='*') && ( strlen(nm)>1 ) && ( nm[strlen(nm)-1]=='*' ))
			{
				nm[strlen(nm)-1]=0;
				strnset(strchr(path,'?'),nm[0],1);
				logger("buscando coincidencias...");
				if((in = fopen(path,"rb"))!=NULL)
				{
					ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
					while(!feof(in))
					{
						fread(&tmp,sizeof(ArchDest),1,in);
						if (strstr( strlwr(tmp.nombre) ,strlwr(nm) ) != NULL
							&& strcmpi(ext,tmp.ext) == 0 && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
						{
							n++;
							#ifdef DEBUG
							printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
							ExportXML(tmp,2);
							#endif
						}
						else
						{
						#ifdef DEBUG
							printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
						#endif
						}
					}
					ExportXML(tmp,3);
						fclose(in);
				}
				else
					logger("no se encontraron coincidencias");
			}
			// Caso *.ext
			else if((nm[0]=='*') && ( strlen(nm)==1 ))
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if ((strcmpi(ext,tmp.ext) == 0 && !feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
								#ifdef DEBUG
								printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// Caso *nombre*.ext
			else if((nm[0]=='*') && ( strlen(nm)>1 ) && ( nm[strlen(nm)-1]=='*' ))
			{
				nm[strlen(nm)-1]=0;
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if (strstr( strlwr(tmp.nombre) , strlwr(strchr(nm,'*')+1) ) != NULL
								&& strcmpi(ext,tmp.ext) == 0 && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
							#ifdef DEBUG
								printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
		}
		// Caso 3
		else if (strchr(nm,'*')==NULL && strchr(ext,'*')!=NULL)
		{	// Caso nombre.*
			strnset(strchr(path,'?'),nm[0],1);
			logger("buscando coincidencias...");
			if((in = fopen(path,"rb"))!=NULL)
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				while(!feof(in))
				{

					fread(&tmp,sizeof(ArchDest),1,in);
					if (strcmpi(tmp.nombre,nm) == 0
						&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
					{
						n++;
						#ifdef DEBUG
						printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
						#endif
						ExportXML(tmp,2);
					}
					else
					{
					#ifdef DEBUG
						printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
						#endif
					}
				}
				ExportXML(tmp,3);
				fclose(in);
			}
			else
				logger("no se encontraron coincidencias");
		}
		// Caso 4
		else if (strchr(nm,'*')==NULL && strchr(ext,'*')==NULL)
		{   // Caso: Nombre.Ext
			strnset(strchr(path,'?'),nm[0],1);
			logger("buscando coincidencias...");
			if((in = fopen(path,"rb"))!=NULL)
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				while(!feof(in))
				{

					fread(&tmp,sizeof(ArchDest),1,in);
					if (strcmpi(tmp.nombre,nm) == 0
						&& strcmpi(tmp.ext,ext) == 0 && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
					{
						n++;
						#ifdef DEBUG
						printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
						#endif
						ExportXML(tmp,2);
					}
					else
					{
					#ifdef DEBUG
						printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
					#endif
					}
				}
				ExportXML(tmp,3);
				fclose(in);
			}
			else
				logger("no se encontraron coincidencias");
			}
//		ExportXML(tmp,4);
		return 1;
	}
	else
	{
		logger("Nombre incorrecto de archivo");
		return 0;
	}

}


/***************************** 	BuscarCat() *********************************/
//---------------------------------------------------------------------------/
int BuscarCat(char * busqueda)
{
	char categ[32];		// almacena categ
	FILE * in;
	char path[16];		// el path del archivo binario.
	short n = 0;		// define el numero de coincidencias
	ArchDest tmp;

	strcpy(path,"c:\\dic\\?.bin");
	strcpy(categ,busqueda);
	if (strchr(busqueda,'.')==NULL) // si existe un punto no busca
	{
			categ[31]=0;
			// Caso *tipo
			if((categ[0]=='*') && ( strlen(categ) > 1 ) && ( categ[strlen(categ)-1]!='*' ))
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if (strstr( strlwr(tmp.tipo) , strlwr(strchr(categ,'*')+1) ) != NULL
								&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s. es igual a %s.\n",tmp.tipo,tmp.ext,categ);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
							#ifdef DEBUG
								printf("%s.%s no es igual a %s\n",tmp.tipo,tmp.ext,categ);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// Caso tipo*
			else if((categ[0]!='*') && ( strlen(categ)>1 ) && ( categ[strlen(categ)-1]=='*' ))
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
						if (strstr( strlwr(tmp.tipo) ,strlwr(categ) ) != NULL
							&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
						{
								n++;
								#ifdef DEBUG
								printf("%s. es igual a %s.\n",tmp.tipo,tmp.ext,categ);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
							#ifdef DEBUG
								printf("%s.%s no es igual a %s\n",tmp.tipo,tmp.ext,categ);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// Caso *tipo*
			else if((categ[0]=='*') && ( strlen(categ)>1 ) && ( categ[strlen(categ)-1]=='*' ))
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				categ[strlen(categ)-1] = 0;
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
						if (strstr( strlwr(tmp.tipo) , strlwr(strchr(categ,'*')+1) ) != NULL
								&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s. es igual a %s.\n",tmp.tipo,tmp.ext,categ);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
							#ifdef DEBUG
								printf("%s.%s no es igual a %s\n",tmp.tipo,tmp.ext,categ);
							#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// Caso *
			else if((categ[0]=='*') && ( strlen(categ)==1 ))
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if ((!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s. es igual a %s.\n",tmp.tipo,tmp.ext,categ);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
							#ifdef DEBUG
								printf("%s.%s no es igual a %s\n",tmp.tipo,tmp.ext,categ);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);
			}
			// caso tipo
			else if (strchr(categ,'*')==NULL)
			{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
						if (strcmpi(categ,tmp.tipo)==0
								&& (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								n++;
								#ifdef DEBUG
								printf("%s. es igual a %s.\n",tmp.tipo,tmp.ext,categ);
								#endif
								ExportXML(tmp,2);
							}
							else
							{
							#ifdef DEBUG
								printf("%s.%s no es igual a %s\n",tmp.tipo,tmp.ext,categ);
								#endif
							}
						}
						fclose(in);
					}
//					else
//						logger("no se encontraron coincidencias");
				}
				ExportXML(tmp,3);

			}
			return 1;
	}
	else
	{
		logger("Tipo incorrecto de archivo");
		return 0;
	}
}

/***************************   BuscarFecha()  *******************************/
//---------------------------------------------------------------------------/
int BuscarFecha(int d,int m ,int a)
{
	FILE * in;
	char path[16];		// el path del archivo binario.
	ArchDest tmp;

	strcpy(path,"c:\\dic\\?.bin");

	if( (d<=31 && d>=1) && (m>=1 && m<=12) && (a > 999 && a < 10000))
	{
				ExportXML(arch[0],1);		// abre o crea archivo xml si no existe
				logger("buscando coincidencias...");
				for (int i = 1; i <=26; i++)
				{
					strnset((strrchr(path,'\\')+1),64+i,1);
					if((in = fopen(path,"rb"))!=NULL)
					{
						while(!feof(in))
						{
							fread(&tmp,sizeof(ArchDest),1,in);
							if ((d==tmp.d)&&(m==tmp.m)&&(a==tmp.a)
								&&(!feof(in))) // hack para que no lea 2 veces el ultimo dato.
							{
								logger("se encontro una o mas conincidencias");
//								printf("%d/%d/%d. es igual a %d/%d/%d.\n",tmp.d,tmp.m,tmp.a,d,m,a);
								ExportXML(tmp,2);
							}
							else
							{
							#ifdef DEBUG
								printf("%d/%d/%d. no es igual a %d/%d/%d.\n",tmp.d,tmp.m,tmp.a,d,m,a);
							#endif
							}
						}
						fclose(in);
					}
					else
						logger("buscando coincidencias...");
				}
				ExportXML(tmp,3);
				return 1;
	}
	else
		logger("Fecha Incorrecta");
		return 0;
}

/***************************** Elimination()  *******************************/
//---------------------------------------------------------------------------/
int Elimination(char * nombre, char* tipo, int d, int m, int a)
{
	char nm[32];		// almacena nombre
	char ext[5];		// almacena extension
	FILE * in;
	char path[16];		// el path del archivo binario.
	short n;		// define el numero de coincidencias

	ArchDest tmp;

	n = 0;
	strcpy(path,"c:\\dic\\?.bin");
	if (strchr(nombre,'.')!=NULL)
	{
		sscanf(nombre,"%[^.]",&nm);
		nm[31]=0;
		strncpy(ext,strrchr(nombre,'.')+1,3);
		ext[3]=0;
		#ifdef DEBUG
		printf("nombre: %s, extension: %s\n",nm,ext); // debug
		#endif

		strnset(strchr(path,'?'),nm[0],1);
		logger("buscando coincidencias...");
		if((in = fopen(path,"r+b"))!=NULL)
		{
			while(!feof(in))
			{
				fread(&tmp,sizeof(ArchDest),1,in);
				if (strcmpi(tmp.nombre,nm) == 0
					&& strcmpi(tmp.ext,ext) == 0 && (strcmpi(tipo,tmp.tipo)==0)
					&& d==tmp.d && m==tmp.m && a == tmp.a && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
				{
					strnset(tmp.nombre,0,sizeof(tmp.nombre));
					strnset(tmp.ext,0,sizeof(tmp.ext));
					strnset(tmp.path,0,sizeof(tmp.path));
					strnset(tmp.tipo,0,sizeof(tmp.tipo));
					tmp.d=0;
					tmp.m=0;
					tmp.a=0;
					fseek(in,sizeof(tmp)*n,0);
					fwrite(&tmp,sizeof(tmp),1,in);
//                    fseek(in,sizeof(tmp)*(n-)
#ifdef DEBUG
					printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
#endif
				}
				else
				{
#ifdef DEBUG
					printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
#endif
				}
				n++;
			}
			fclose(in);
		}
		else
			logger("no se encontraron coincidencias");
		return 1;
	}
	else
	{
		logger("Nombre incorrecto de archivo");
		return 0;
	}

}

/**************************  CambiarNombre()  *******************************/
//---------------------------------------------------------------------------/
int CambiarNombre(char * ruta1,char * nombre, char * ruta2, char * nombre2)
// retorna 0: nombre2 ya existe; -1: nombre1 no existe 1: cambio satisfactorio.
{
	char nm[32];		// almacena nombre
	char ext[5];		// almacena extension
	FILE * in;
	char path[16];		// el path del archivo binario.
	ArchDest tmp;
	int ban1,n,t;

	char nm2[32];
	char ext2[5];

	strcpy(path,"c:\\dic\\?.bin");
	ban1=0;
	n=0;
	t=0;

	if (ruta1[strlen(ruta1) - 1] != '\\')
		strcat(ruta1,"\\");
	if (ruta2[strlen(ruta2) - 1] != '\\')
	strcat(ruta2,"\\");

	// validacion: Busca si el nombre y el path de destino ya existen. aumenta ban1
	if (strchr(nombre2,'.')!=NULL)  //
	{
		sscanf(nombre2,"%[^.]",&nm);
		nm[31]=0;
		strncpy(ext,strrchr(nombre2,'.')+1,3);
		ext[3]=0;
#ifdef DEBUG
		printf("nombre: %s, extension: %s\n",nm,ext); // debug
#endif
					strnset(strchr(path,'?'),nm[0],1);
			logger("buscando similitudes...");
			if((in = fopen(path,"rb"))!=NULL)
			{
				while(!feof(in))
				{

					fread(&tmp,sizeof(ArchDest),1,in);
					if (strcmpi(tmp.nombre,nm) == 0
						&& strcmpi(tmp.ext,ext) == 0 && strcmpi(ruta2,tmp.path)==0 && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
					{
						ban1++;
#ifdef DEBUG
						printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
#endif
					}
					else
					{
#ifdef DEBUG
						printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
#endif
					}
				}
				fclose(in);
			}
			else
			{
				logger("Libre de cambiar nombre.");
				ban1 = -1;
			}
	}
	else
	{
		logger("Nombre a asignar incorrecto");
		return 0;
	}

	// reasignacion de variables.
	strcpy(path,"c:\\dic\\?.bin");



	if (ban1>0) 	// no cambiar nombre
	{
		logger("nombre de archivo ya existe, ingrese otro nuevo nombre");
		return 0;
	}
	else if (ban1 <= 0) // solo cambiar nombre a archivo existente (inicial destino = inicial origen)
	{
		sscanf(nombre,"%[^.]",&nm);
		nm[31]=0;
		strncpy(ext,strrchr(nombre,'.')+1,3);
		ext[3]=0;
#ifdef DEBUG
		printf("nombre: %s, extension: %s\n",nm,ext); // debug
#endif

		sscanf(nombre2,"%[^.]",&nm2);
		nm2[31]=0;
		strncpy(ext2,strrchr(nombre2,'.')+1,3);
		ext2[3]=0;

		strnset(strchr(path,'?'),nm[0],1);
		logger("buscando coincidencias...");

			if((in = fopen(path,"rb"))!=NULL)
			{
				while(!feof(in) && t == 0)
				{

					fread(&tmp,sizeof(ArchDest),1,in);
					if (strcmpi(tmp.nombre,nm) == 0
						&& strcmpi(tmp.ext,ext) == 0 && strcmpi(ruta1,tmp.path)==0 && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
					{
						//ban1++;
						t++;
#ifdef DEBUG
						printf("%s.%s es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
#endif
					}
					else
					{
#ifdef DEBUG
						printf("%s.%s no es igual a %s.%s\n",tmp.nombre,tmp.ext,nm,ext);
#endif
					}
				}
				fclose(in);
			}
			else
			{
				logger("Imposible abrir archivo");
				return 0;
//				ban1 = -1;
			}
		if (t>0)
		{
			Elimination(nombre,tmp.tipo,tmp.d,tmp.m,tmp.a);

			strcpy(path,"c:\\dic\\?.bin");

			strnset(strchr(path,'?'),nm2[0],1);
			logger("buscando coincidencias...");

//		if((in = fopen(path,"a+b"))!=NULL)
//		{

			in = fopen(path,"a+b");
			strcpy(tmp.nombre,nm2);
			strcpy(tmp.ext,ext2);
			strcpy(tmp.path,ruta2);
			fwrite(&tmp,sizeof(tmp),1,in);

/*			while(!feof(in))
			{
				fread(&tmp,sizeof(ArchDest),1,in);
				if (strcmpi(tmp.nombre,nm) == 0
					&& strcmpi(tmp.ext,ext) == 0 && (!feof(in))) // hack para que no lea 2 veces el ultimo dato.
				{

					strcpy(tmp.nombre,nm2);
					strcpy(tmp.ext,ext2);
					strcpy(tmp.path,ruta2);

//					fseek(in,sizeof(tmp)*n,0);
//					fwrite(&tmp,sizeof(tmp),1,in);
//                    fseek(in,sizeof(tmp)*(n-)

					logger("El archivo ha sido renombrado.");
					return 1;
				}
				else if (feof(in))
				{
					logger("nombre de origen no existe");
					return -1;
				}
				else
				{
					logger("continua...");
				}
				n++;
			}
*/
//		}
//		}
			fclose(in);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else	// borrar del archivo origen y crear en nuevo archivo con la inicial dada en destino.
	{
		return 1;
	}
}

/**************************** 	ExportXML()   *******************************/
//---------------------------------------------------------------------------/
int ExportXML(ArchDest origen, int modo)	// modo 1, inicia busqueda
											// modo 2, continua busqueda ,
											// modo 3, cerra busqueda
											// modo 4, cierra el tag principal
{
	FILE * xml;
//	char foot]
	char fecha[5];
	long inicio, fin;
	if((xml = fopen("c:\\found.xml","r")) == NULL)
	{
		logger("Se copiara definicion XSL al c:\\");
		system("copy .\\estilo.xsl c:\\estilo.xsl");
		logger("definicion XSL ha sido copiada a c:\\");
		logger("Se creara archivo found.xml en c:\\");
		xml = fopen("c:\\found.xml","wt");
		// copiar xsl a donde se vaya a ver el xml
		fprintf(xml,"<?xml version=\"1.0\"?>\n");  
		fprintf(xml,"<?xml:stylesheet type=\"text/xsl\" href=\"ESTILO.XSL\"?>\n");
		fprintf(xml,"<!--inicio xmlns=\"x-schema:Esquemas.xml\"-->\n");
		fprintf(xml,"<reporte>\n");
		fprintf(xml,"<titulo> Archivos Encontrados ... </titulo>\n");
//		fprintf(xml,"\n");
				fprintf(xml,"<subtitulo>");
				fprintf(xml,"en busqueda hecha en:");
				fprintf(xml,tiempo());
				fprintf(xml,"</subtitulo>\n");
				fprintf(xml,"<tabla>\n");
				fprintf(xml,"<tituloscampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Nombre");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Extension");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Categoria");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Fecha");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Path");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"</tituloscampo>\n");
		fprintf(xml,"</reporte>");

		fclose(xml);

		logger("c:\\found.xml ha sido creado");
		return 1;
		//  fprintf
	}
	else
	{
		fclose(xml);
		//xml = fopen("c:\\found.xml","at");
		xml = fopen("c:\\found.xml","r+t");
		rewind(xml);
		inicio = ftell(xml);
		fseek(xml,0L,2);
		fin = ftell(xml);
		fseek(xml,(fin-inicio)-sizeof(char)*(strlen("</reporte>")),0);
//		fseek(xml,sizeof(char)*(strlen("</reporte>\n")+1),2);

		switch (modo)
		{
			case 1:
				fprintf(xml,"<subtitulo>");
				fprintf(xml,"en busqueda hecha en:");
				fprintf(xml,tiempo());
				fprintf(xml,"</subtitulo>\n");
				fprintf(xml,"<tabla>\n");
				fprintf(xml,"<tituloscampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Nombre");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Extension");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Categoria");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Fecha");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"<titulocampo>");
				fprintf(xml,"Path");
				fprintf(xml,"</titulocampo>\n");
				fprintf(xml,"</tituloscampo>");
				fprintf(xml,"</reporte>");
			break;
			case 2:
				fprintf(xml,"<registro>");
				fprintf(xml,"<dato>");
				fprintf(xml,origen.nombre);
				fprintf(xml,"</dato>\n");
				fprintf(xml,"<dato>");
				fprintf(xml,origen.ext);
				fprintf(xml,"</dato>\n");
				fprintf(xml,"<dato>");
				fprintf(xml,origen.tipo);
				fprintf(xml,"</dato>\n");
				fprintf(xml,"<dato>");
				for (int i = 0;i<5;i++)
					fecha[i] = 0;
				fprintf(xml,itoa(origen.d,fecha,10));
				for (i = 0;i<5;i++)
					fecha[i] = 0;
				fputc('/',xml);
				fprintf(xml,itoa(origen.m,fecha,10));
				for (i = 0;i<5;i++)
					fecha[i] = 0;
				fputc('/',xml);
				fprintf(xml,itoa(origen.a,fecha,10));
				fprintf(xml,"</dato>\n");
				fprintf(xml,"<dato>");
				fprintf(xml,origen.path);
				fprintf(xml,"</dato>\n");
				fprintf(xml,"</registro>\n");
				fprintf(xml,"</reporte>");
			break;
			case 3:
				fprintf(xml,"</tabla>\n");
				fprintf(xml,"</reporte>");
			break;
			case 4:
//				fprintf(xml,"</reporte>");
			break;
		}
		fclose(xml);
	return 1;
	}
}



/************************* 	iniciographics()  *******************************/
//---------------------------------------------------------------------------/
int iniciographics()
{
	int gdriver = DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"");
	errorcode=graphresult();
	if (errorcode != grOk)
	{
		printf("Error Grafico; %s\n",grapherrormsg(errorcode));
		printf("Presionar algo\n");
		getch();
		exit(1);
	}
return 0;
}

/***************************** 	mouseinit()  ********************************/
//---------------------------------------------------------------------------/
void mouseinit()
{
	MirarRaton();
	MostrarPuntero();
}

/*******************************  welcome()	*********************************/
//---------------------------------------------------------------------------/
void welcome()
{
	OcultarPuntero();

	char titulo[64];
	strcpy(titulo,"Bienvenido a ");
	strcat(titulo,prgname);
	strcat(titulo," Ver 1.0");
	OKWindw w3(titulo,"Para ayuda dirijase al",
								"menu Ayuda->Ayuda en pantalla");
	w3.DrawWindow();
	MostrarPuntero();
	w3.RunWindow();

}

/******************************* screenmsg() ********************************/
//---------------------------------------------------------------------------/
void screenmsg(char * mensaje, int tiempo)
{
	int x1,y1,x2,y2;
	x1=0;                      	//Coordenadas
	y1=getmaxy() -16;
	x2=textwidth(mensaje) + 8;
	y2=getmaxy();

	setfillstyle(1,15);
	bar(x1,y1,x2,y2);               // dibuja barra de fondo
	setcolor(1);
	outtextxy(x1+10,y1,mensaje);    // escribe texto en pantalla
	delay(tiempo);

	setfillstyle(1,7);    // retorna a los colores de dibujo
	bar(x1,y1,x2,y2);               // dibuja barra de fondo
	setcolor(0);

}
#endif
#endif
