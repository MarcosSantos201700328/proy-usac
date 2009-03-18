/*
  Nombre: PaintKiller
  Copyright: ©2005 Erik Giron.
  Autor: Erik Giron (Carnet: 200313492)
  Fecha: 10/03/05 21:36
  Descripcion: Proyecto 1 de IPC1 USAC Primer Semestre 2005
			  (Paint para MS-DOS usando modo grafico de Borland C++ 3.1)

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

#include "raton.h"
#include "eventos.h"
#include "control.h"
#include <math.h>
//#include <alloc.h>	//debug
//#include <dir.h>		//debug
//#include <process.h>
/*-------


todo list:
=========
/HECHO/-establecer funciones para valor retornado de clicmenu.
/HECHO/-recondicionar el while en dibujamenu.
/HECHO/-componer el problema del crash subito.	(idea: convertir a punteros todos los objetos estaticos)
/HECHO/-crear ayuda y ayuda en pantalla
/HECHO/-crear canvas y algoritmo de entrada y salida de este con esc y CTRL+X;CTRL+N
/HECHO/-crear algoritmo linea y mano alzada(area de 9*9pixeles)
/HECHO/-implementar poligono
/HECHO/-crear algoritmo movimiento para estas dos.
	/HECHO/-hacer funcionar movimiento horizontal
/HECHO/-crear algoritmo spray
/HECHO/-crear mensajes de texto en pantalla (estilo statusbar)
/HECHO/-escribir texto para la ayuda en pantalla.
/HECHO/-componer las coordenadas de accion para cada comando.
-Escribir manual tecnico.
/HECHO/-Escribir manual de Usuario.
/---- extras -------/
/HECHO/-crear ayuda al presionar f1.
/HECHO/-mejorar el algoritmo poligono para poder incluir relleno.
/HECHO/-establecer clic en area fuera de menu que cierre este.
-agregar variable tipo EventMsg para cada lugar donde se utilize.
/HECHO/-colocar mensajes de texto en pantalla para ayuda
-crear algoritmo de volcado y recuperacion de pantalla a archivo.
/NO/-mejorar el algoritmo de linea para dibujar la linea con un solo boton de mouse.
-crear efecto de resaltado en los menues.
-crear efecto 3d en la linea separadora de comandos de menu.
--------- */



//	DECLARACION DE VARIABLES GLOBALES
//int i;

char mtestrt[4];
//	flags
//int tecla;
int banmenu;	//-Bandera para menu
int outmenu = 0;//-Salida del bucle de gui.

int mainflag;	//-Bandera Principal de control del programa.
				//	valores de mainflag:
				//		unidades: No. comando
				// 		decenas : No. menu
int nuevo = 0;	//-Bandera de Crea nuevo
//opciones de linea
int gruesolin = 1;//-Grueso de linea (default:1)
int tipolin = 0;  //-Tipo de linea(default:1)
int manoalz = 0;  //-bandera de mano alzada(default:0)
//opciones de poligono
int ladospoli = 3;	//-lados poligono (default:3)
int relleno = 0;	//-relleno (default:0)
//opciones de movimiento
int mvment = 0;		//-establece movimiento en poligono y linea. (default:0)

//int radiospray = 10 ;	//-establece opciones de spray.

int colortrazo = 0; //-establece color de trazo
int colorcanvas = 15; //-establece color de lienzo(canvas)




//   declaracion de objetos

//	DECLARACION DE PROTOTIPOS DE
//	FUNCIONES GENERALES
int iniciographics(void);   //Inicia modo grafico

void mouseinit(void);           //Inicia el mouse

void mostrargui(void);		// Dibuja la barra del menu con sus botones
							// para abrir menues desplegables.
							// si su argumento es 1, borra el menu

void muestramenu(int, int); // Muestra menu invocado por mostrargui()
							// sus parametros son la posicion y la bandera
							// si la posicion es -1, destruye el menu identificado
							// con la bandera

int dibujamenu(int,int,int);// Dibuja y establece rango de accion de cada comando
							// de menu; devuelve el valor de y final

void escoge(int);		// valida entrada de texto y asigna valores a var. locales.

void welcome(void);  //Muestra pantalla de Bienvenida

int clicmenu(int,int,int);   //accion cuando se hace clic en algun comando de menu.

int dismiss(int);		 // Dibuja ventana de despedida.

void help(int);			 // Muestra ayuda en linea, ayuda con programa externo y
						 // la ventana de acerca de..

void screenmsg(char *,int);	// dibuja un mensaje en la parte inferior de la pantalla

void colorsel(int,void * &);		// dibuja la ventana de muestra de color
									// toma como parametros un entero(!=0 borra)
									// y un puntero a void que sera el buffer.

int draw(int);           // Establece valores iniciales para dibujo y llama a
						// cada funcion de dibujo especifica segun el argumento de
						// la funcion.

int linea(int);		// 	dibuja una linea (parametro = 1) o poligono(param = 0)
					//	capturando las coordenadas del mouse
					//  con las opciones establecidas en draw()

void poligono(int,int,int,int,int);	// calcula matematicamente y dibuja el poligono.

int manoalzada(void);   //dibuja a mano alzada si se especifica.

int spray(int);			//Dibuja spray.

int movimiento(int);	//algoritmo de movimiento de pantalla invocado por draw();

/*******************************	MAIN	********************************/
int main(void)
{
	//Inicio de Drivers
	iniciographics();		//inicia el modo grafico
	mouseinit();           	//inicia el mouse
	OcultarPuntero();
	setbkcolor(0);
	setfillstyle(1,colorcanvas);

	bar(0,0,getmaxx(),getmaxy());	//borra la pantalla a blanco
	MostrarPuntero();
	welcome();
	int salida = 0;                 //ventana de bienvenida
	// CICLO PRINCIPAL DEL PROGRAMA
//	char * mm = new char;//debug
	while (!salida)
	{
		mostrargui();
  //		outtextxy(getmaxx()/2,getmaxy()-16,ultoa(coreleft(),mm,10));  //debug
		switch (mainflag)	// switch principal del programa
		{
		case 11: 				//cuando se presione nuevo
			OcultarPuntero();
			nuevo = 1;
			setfillstyle(1,colorcanvas);
			bar(0,0,getmaxx(),getmaxy());
			MostrarPuntero();
		break;
		case 12:            	//cuando se presione salir
			salida = dismiss(0);	//llamada a dismiss para ventana de despedida
		break;
		case 21:                //cuando se presione grueso
			escoge(mainflag);		//llamada a funcion escoge
		break;
		case 22:                //cuando se presione tipo
			escoge(mainflag);       //llamada a funcion escoge
		break;
		case 23:                //cuando se presione movimiento
			escoge(mainflag);       //llamada a funcion escoge
		break;
		case 24:                //cuando se presione mano alzada
			(manoalz==0)?(manoalz=1):(manoalz=0);  	//asigna mano alzada
			(manoalz==0)?screenmsg("mano alzada desactivada",500):screenmsg("mano alzada activada",500);
		break;
		case 25:                //cuando se presione escoger
			(manoalz==0)?screenmsg("Para trazar lineas: 1er punto:Clic izq; 2do punto:Clic der",1000):screenmsg("Deje clic izq. presionado para dibujar.",1000);
			draw(mainflag);
		break;
		case 31:                //cuando se presione lados
			escoge(mainflag);
		break;
		case 32:                //cuando se presione relleno
			escoge(mainflag);
		break;
		case 33:                //cuando se presione movimiento
			escoge(mainflag);
		break;
		case 34:                //cuando se presione escoger
			draw(mainflag);
		break;
		case 41:                //cuando se presione amplio
			draw(mainflag);
		break;
		case 42:                //cuando se presione medio
			draw(mainflag);
		break;
		case 43:                //cuando se presione estrecho
			draw(mainflag);
		break;
//		case 44:
//		break;
		case 51:                //cuando se presione color linea
			escoge(mainflag);
		break;
		case 52:                //cuando se presione color fondo
			escoge(mainflag);
		break;
		case 61:                //cuando se presione ayuda
			help(mainflag);
		break;
		case 62:                //cuando se presione manual de usuario
			help(mainflag);
		break;
		case 63:                //cuando se presione acerca de...
			help(mainflag);
		break;
		}
		outmenu = 0;			// se sale del bucle de la interfaz grafica

	}
	closegraph();               // cierra el modo grafico
	return 0;
}



//***	DEFINICION FUNCIONES GENERALES	*****/

/*******************************  welcome()	*********************************/
//---------------------------------------------------------------------------/
void welcome()
{
	OcultarPuntero();

	OKWindw * w3 = new OKWindw("Bienvienido a PAINTkiller",
								"Para ayuda dirijase al",
								"menu Ayuda->Ayuda en pantalla");
	w3->DrawWindow();
	MostrarPuntero();
	w3->RunWindow();
	delete w3;
}

/****************************  mostrargui() *********************************/
//---------------------------------------------------------------------------/
void mostrargui()       // MUESTRA EL MENU
{

	OcultarPuntero();
	setlinestyle(0,1,1);	//hack para no dibujar lineas gruesas en los objetos.

	// Asigna nombres a los menues
	char * nombres[6] =
	{
	"^PROGRAMA","^LINEAS","^GEOMETRICOS",
	"^SPRAY","^COLORES","^AYUDA"
	};

	// Matriz para establecer el tamano y la ubicacion
	// de cada menu.
	int tam[6], x0[6];

	// Establece automaticamente el tamano  y coordenadas
	// de cada boton que abrira los menues desplegables.
	for (int i =0 ;i < 6; i++)
	{
		tam[i] = (strlen(nombres[i]) * 8);
//		printf("%i\n",tam[i]);  //debug
		if (i == 0)
			x0[i] = 0;
		else
			x0[i] =  x0[i - 1] + tam[i-1] + 1;
	}
		// Generacion de objetos de menu establecidos en control.h
		// Barra de menu de fondo
	Windw *barramenu = new Windw(0,0,getmaxx(),18,0,1);   //Establecido como puntero
									//a Windw para poder ocultar cuando se quiera.

		// botones
	aboton *prog  = new aboton(x0[0],0,tam[0],nombres[0]);
	aboton *lin   = new aboton(x0[1],0,tam[1],nombres[1]);
	aboton *geom  = new aboton(x0[2],0,tam[2],nombres[2]);
	aboton *spray = new aboton(x0[3],0,tam[3],nombres[3]);
	aboton *color = new aboton(x0[4],0,tam[4],nombres[4]);
	aboton *ayuda = new aboton(x0[5],0,tam[5],nombres[5]);


		// dibuja objetos llamando a su funcion mienbro de dibujo.
	barramenu->DrawWindow(); // dibuja barra de menu.

	prog->DrawWindow();
	lin->DrawWindow();    // Dibuja los botones de cada menu.
	geom->DrawWindow();
	spray->DrawWindow();
	color->DrawWindow();
	ayuda->DrawWindow();

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
				help(61);
			}
//			if (evntmsg.key == 0x011b)
//			{			// Si se presiona esc
//				s = -1;
//				break;
//			}
			if (evntmsg.key == 0x2d18) // ctrl + x
			{
				dismiss(1);      // Si se presiona CTRL+X
			}
			if (evntmsg.key == 0x310e)
			{
				OcultarPuntero();
				setfillstyle(1,colorcanvas);
				bar(0,20,getmaxx(),getmaxy());      // Si se presiona CTRL+N
				MostrarPuntero();
			}
		}
		if (prog->Clicked(evntmsg))
		{
			muestramenu(banmenu,-1);
			banmenu=1;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		 //button = OK;
		}
		else if (lin->Clicked(evntmsg))
		{  // button = CANCEL;

			muestramenu(banmenu,-1);
			banmenu = 2;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
		else if (geom->Clicked(evntmsg))
		{  // button = CANCEL;


			muestramenu(banmenu,-1);
			banmenu = 3;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);

		}
		else if (spray->Clicked(evntmsg))
		{  // button = CANCEL;

			muestramenu(banmenu,-1);
			banmenu = 4;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
		else if (color->Clicked(evntmsg))
		{  // button = CANCEL;
			muestramenu(banmenu,-1);
			banmenu = 5;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
		else if (ayuda->Clicked(evntmsg))
		{

			muestramenu(banmenu,-1);
			banmenu = 6;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
	}

	// borra objetos luego de escoger comando para no llenar la POCA
	// memoria que asigna borland c++ a los programas para DOS.
	delete barramenu, prog, lin, geom, spray, color, ayuda;
	delete [] nombres;

}


/*****************************	muestramenu()********************************/
//---------------------------------------------------------------------------/
void muestramenu(int flag, int x) //x condicion,-1 destruye menu
{

	int y0=19;

	Windw * fmenu = new Windw(0,y0,0,100,0,1);		// crea ventana de fondo para cada
												// menu
	if (x!=-1)
	{
		fmenu->setwx(x);
		switch (flag)     		//asigna dimensiones para cada menu
		{
			case 1:
//				printf("clicked prog\n"); //debug
				fmenu->setww(125);
				fmenu->setwh(36);
			break;
			case 2:
//				printf ("clicked lin\n"); //debug
				fmenu->setww(100);
				fmenu->setwh(90);
			break;
			case 3:
//				printf ("clicked geom\n"); //debug
				fmenu->setww(100);
				fmenu->setwh(76);
			break;
			case 4:
//				printf ("clicked spray\n"); //debug
				fmenu->setww(88);
				fmenu->setwh(55);
			break;
			case 5:
//				printf ("clicked color\n"); //debug
				fmenu->setww(100);
				fmenu->setwh(36);
			break;
			case 6:
				fmenu->setww(150);
				fmenu->setwh(56);
//				printf("clicked ayuda\n"); //debug
			break;
		};

		fmenu->DrawWindow();	//dibuja la ventana de cada menu
		MostrarPuntero();

// espera valor de retorno para asignarlo a la bandera principal
		mainflag = dibujamenu(flag,x,y0);
//	printf("Mainflag es: %d ",mainflag); //debug

 //oculta y borra el objeto
		OcultarPuntero();

//	setfillstyle(1,getbkcolor());
//	bar (0,19,getmaxx(),getmaxy());
		delete fmenu;
		outmenu = 1;			// establece salida de bucle principal de la interfaz grafica
		MostrarPuntero();
	}
	else
	{
		delete fmenu;
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

/****************************** dibujamenu() ********************************/
//---------------------------------------------------------------------------/
int dibujamenu(int flag,int x,int y)
{
	char *cmd[6][5]=                    // matriz de string para cada nombre
	{                                   // elemento de menu(comandos)
		{" NUEVO   CTRL+N"," SALIR   CTRL+X","",NULL,NULL},
		{" GROSOR"," TIPO"," MOVIMIENTO","*MANO ALZADA"," ESCOGER"},
		{" LADOS"," RELLENO"," MOVIMIENTO"," ESCOGER",NULL},
		{" AMPLIO"," MEDIO"," ESTRECHO",NULL,NULL},
		{" COLOR LINEA"," COLOR FONDO","",NULL,NULL},
		{" EN PANTALLA"," MANUAL DE USUARIO"," ACERCA DE...","",NULL}
	};

	int posy[5];						// matriz que almacenara posiciones

	int limite = 5;//(sizeof( *cmd[flag + 1] ) + 1); // Establece limite para el
												// sig. ciclo.

	for (int i=0; i< limite; i++)		// calcula posicion en y para cada
	{                                   // elemento del menu
		posy[i] = (y*(i+1)) +2;

	}

	int j = 0;


	//debug
//	char pos[5];
//	itoa(ret,pos,10);

//	outtextxy(getmaxx() - 16,100,pos);
	// end debug
	setcolor(1);       // establece color de texto.

	OcultarPuntero();
	switch(flag)
	{
	case 1:
		outtextxy(x+2,posy[0],cmd[0][0]);
		line(x+10,posy[1]-5,x+115,posy[1]-5);
		outtextxy(x+2,posy[1],cmd[0][1]);
	break;
	case 2:
		outtextxy(x+2,posy[0],cmd[1][0]);
		line(x+10,posy[1]-5,x+90,posy[1]-5);
		outtextxy(x+2,posy[1],cmd[1][1]);
		line(x+10,posy[2]-5,x+90,posy[2]-5);
		outtextxy(x+2,posy[2],cmd[1][2]);
		line(x+10,posy[3]-5,x+90,posy[3]-5);
		outtextxy(x+2,posy[3],cmd[1][3]);
		line(x+10,posy[4]-5,x+90,posy[4]-5);
		outtextxy(x+2,posy[4],cmd[1][4]);

	break;
	case 3:
		outtextxy(x+2,posy[0],cmd[2][0]);
		line(x+10,posy[1]-5,x+90,posy[1]-5);
		outtextxy(x+2,posy[1],cmd[2][1]);
		line(x+10,posy[2]-5,x+90,posy[2]-5);
		outtextxy(x+2,posy[2],cmd[2][2]);
		line(x+10,posy[3]-5,x+90,posy[3]-5);
		outtextxy(x+2,posy[3],cmd[2][3]);
//		line(x+10,posy[4]-5,x+90,posy[4]-5);
//		outtextxy(x+2,posy[4],cmd[2][4]);

	break;
	case 4:
		outtextxy(x+2,posy[0],cmd[3][0]);
		line(x+10,posy[1]-5,x+80,posy[1]-5);
		outtextxy(x+2,posy[1],cmd[3][1]);
		line(x+10,posy[2]-5,x+80,posy[2]-5);
		outtextxy(x+2,posy[2],cmd[3][2]);

	break;
	case 5:
		outtextxy(x+2,posy[0],cmd[4][0]);
		line(x+10,posy[1]-5,x+90,posy[1]-5);
		outtextxy(x+2,posy[1],cmd[4][1]);

	break;
	case 6:
		outtextxy(x+2,posy[0],cmd[5][0]);
		line(x+10,posy[1]-5,x+115,posy[1]-5);
		outtextxy(x+2,posy[1],cmd[5][1]);
		line(x+10,posy[2]-5,x+115,posy[2]-5);
		outtextxy(x+2,posy[2],cmd[5][2]);

	break;
	};
	setcolor(colortrazo);    //resetea al color de trazo
	MostrarPuntero();

	// invoca la funcion clicmenu que establece rango.
	j = clicmenu(flag,x+2,posy[0]);
	delete []cmd;
									//	regresa el valor devuelto por clicmenu
	return j;
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
					numcom = 2;
					clic = 1;
				}
				if (evntmsg.key == 0x310e)			//Ctrl+N
				{
					numcom = 1;
					clic = 1;
				}

			}
			//comando 1
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > (y-2)) && (PosVertGraf() < 2*(y-2)) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 1;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			// Comando 2
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 2*(y-2)) && (PosVertGraf() < 3*(y-2)/*+19*/) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 2;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			//comando 3
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 3*(y-2)) && (PosVertGraf() < 4*(y-2)/*+19*/) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 3;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 4*(y-2)) && (PosVertGraf() < 5*(y-2)/*+19*/) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 4;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			 //comando 5
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 5*(y-2)) && (PosVertGraf() < 6*(y-2)/*+19*/) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 5;
//				printf("encima clic\t"); //debug
				clic = 1;
			}
			// clic fuera de area de menu cierra el menu
			if ((PosHoriGraf() < x) || (PosHoriGraf() > x+100) ||
				(PosVertGraf() > 6*(y-2)) && BotonPulsado() !=0)
					clic = 1;

	}
	return (flag*10)+numcom;    // retorna la bandera del parametro como decena
}                               // y el numero de comando como unidad

/*******************************  dismiss()	*********************************/
//---------------------------------------------------------------------------/
int dismiss(int subito)
{
	setfillstyle(1,colorcanvas);
	bar(0,0,getmaxx(),getmaxy());

	// crea punteros a objetos boton para aceptar o cancelar
	Button *bt1= new Button(200, 200, "^ACEPTAR");
	Button *bt2= new Button(280, 200, "^CANCELAR");
	setcolor(0);
	outtextxy(getmaxx()/2 - 120, 100,
				"Seguro que desea salir ??");  //dibuja texto en pantalla
	outtextxy(getmaxx()/2 - 140 ,116,
				"[Enter](Aceptar): Si");
	outtextxy(getmaxx()/2 - 140 ,132,
				"[Esc](Cancelar): No");
	// dibuja los botones en pantalla			
	bt1->DrawWindow();        
	bt2->DrawWindow();
	int button = 0;

	while (!button)    //espera evento de teclado o mouse
	{
		GetEvent(evntmsg);
	// Espera algun clic.
		if (bt1->Clicked(evntmsg))
		 	    button = OK;
		 else if (bt2->Clicked(evntmsg))
		       button = CANCEL;
	}
	OcultarPuntero();
	setcolor(15);
	delete bt1,bt2;            //borra los botones cuando han sido clickeados
	
	if (button == OK)    //si boton tiene el valor de la constante OK
	{                    // se sale del programa subitamente si subito = 1
		outtextxy(200, 300, "Adios...");
		delay(500);
		if (subito == 1)
		{
			closegraph();
			exit(0);
		}
		return 1;
	}
	else    // sino borra la pantalla y regresa al GUI
	{
		setfillstyle(1,colorcanvas);
		bar(0,0,getmaxx(),getmaxy());
		setcolor(colortrazo);

		MostrarPuntero();
		return 0;
	}

}
/*******************************   escoge()	*********************************/
//---------------------------------------------------------------------------/
void escoge(int f)
{
	OcultarPuntero();
	char op[4];
	char texto[3][36];  //matriz para tratamiento del mensaje a mostrar.
	int val,li,ls;
	int usacero = 0; 	//le restara 1 si el parametro de la funcion invocada
						//por el comando usa cero como valor inicial.
                        // (e.g. setfillstyle(1,0) usa cero para color negro)
	switch (f)            //asigna las cadenas y valores a aceptar
	{                     //para cada opcion que se elija
	case 21:
		strcpy(texto[0],"Grueso de Linea");
		strcpy(texto[1],"Escriba el grueso en");
		strcpy(texto[2],"pixeles que desee(1 a 4).");
		li = 1; ls = 4;
		usacero = 1;
	break;
	case 22:
		strcpy(texto[0],"Tipo de Linea");
		strcpy(texto[1],"Escoja el tipo de linea");
		strcpy(texto[2],"que le agrade (1 a 3).");
		li = 1; ls = 3;
	break;
	case 23:
		strcpy(texto[0],"Movimiento inicial");
		strcpy(texto[1],"Escoja el movimiento");
		strcpy(texto[2],"(1:sin mov. 2:Horiz. 3:Vert.)");
		li = 1; ls = 3;
		usacero = 1;
	break;
	case 31:
		strcpy(texto[0],"Numero de Lados");
		strcpy(texto[1],"Ingrese un numero de lados entre");
		strcpy(texto[2],"3 y 10, 360 crea circulo");
		li = 3; ls = 360;
	break;
	case 32:
		strcpy(texto[0],"Relleno");
		strcpy(texto[1],"Elija el color de relleno.");
		strcpy(texto[2],"(1: sin relleno a 16)");
		li = 1; ls = 16;
		usacero = 1;
	break;
	case 33:
		strcpy(texto[0],"Movimiento Inicial");
		strcpy(texto[1],"Escoja el movimiento");
		strcpy(texto[2],"(1:sin mov. 2:Horiz. 3:Vert.)");
		li = 1; ls = 3;
		usacero = 1;
	break;
	case 51:
		strcpy(texto[0],"Cambiar Color Trazado");
		strcpy(texto[1],"Ingrese entre 1 y 16 para");
		strcpy(texto[2],"color de trazo");
		li = 1; ls = 16;
		usacero = 1 ;
	break;
	case 52:
		strcpy(texto[0],"Cambiar Color Fondo");
		strcpy(texto[1],"Ingrese entre 1 y 16 para");
		strcpy(texto[2],"color de fondo");
		li = 1; ls = 16;
		usacero = 1;
	break;
	}

	MostrarPuntero();

	val = 0;
	void * buff;		// bufer para colorsel

	// Validacion para la entrada de texto.
	while ((val < li) || (val >ls))
	{

		if((f==51) || (f==52) || (f==32))
			colorsel(0,buff);

		InputWindw * escog = new InputWindw(texto[0],texto[1],texto[2]);
		escog->DrawWindow();
		escog->RunWindow();


		if (escog->GetButton() == OK)
		{
			escog->GetInput(op);
		}
		val = atoi(op);
//		printf("string = %s integer = %d\n",op,val); //debug

		if ((val <li) || (val>ls))
		{
			if((f==51) || (f==52) || (f==32))
				colorsel(-1,buff);

			// crea ventana de aviso
			CapTWindw * aviso = new CapTWindw("AVISO","Ingrese un numero"
												,"correcto");// lims);
			aviso->DrawWindow();
			aviso->RunWindow();
			// elimina los punteros
			delete aviso;


		}
		//else printf("Correcto\n");  //debug
		delete escog;
		delete op,texto;

		if((f==51) || (f==52) || (f==32))
			colorsel(-1,buff);

	}
	// asigna valores ingresados a variables globales
	switch(f)
	{
	case 21:
		gruesolin = val - usacero;
	break;
	case 22:
		tipolin =  val - usacero;
	break;
	case 23:
		mvment =  val - usacero;
	break;
	case 31:
		ladospoli =  val - usacero;
	break;
	case 32:
		relleno =  val - usacero;
	break;
	case 33:
		mvment =  val - usacero;
	break;
	case 51:
		colortrazo =  val - usacero;
	break;
	case 52:
		colorcanvas =  val - usacero;
	break;
	}


}


/******************************* 	help()  *********************************/
//---------------------------------------------------------------------------/
void help(int f)
{
	switch( f )        
	{
	case 24:		//dibujar ventana de ayuda
		CapWindw * hlp1 = new CapWindw(100,100,308,200,
									1,1,"Ayuda en Linea (Mano Alzada)");
		hlp1->DrawWindow();
		setcolor(0);
		outtextxy(112,124 + 12*0,"Dibujar Lineas a mano alzada:");
		outtextxy(112,124 + 12*1," Para dibujar estas, haga clic en el");
		outtextxy(112,124 + 12*2,"menu lineas posicionese sobre *MANO");
		outtextxy(112,124 + 12*3,"ALZADA, para activar el dibujo a ");
		outtextxy(112,124 + 12*4,"mano alzada,  luego haga clic en ");
		outtextxy(112,124 + 12*5,"ESCOGER  dentro de este menu.");
		outtextxy(112,124 + 12*6,"-----------------------------------");
		outtextxy(112,124 + 12*7," Podra dejar presionado el boton ");
		outtextxy(112,124 + 12*8,"izquierdo del mouse y mover suave-");
		outtextxy(112,124 + 12*9,"mente mientras mantiene presionado");
		outtextxy(112,124 + 12*10,"el boton para dibujar una linea ");
		outtextxy(112,124 + 12*11,"suave en pantalla.");
		outtextxy(112,124 + 12*12," Presione ESC si desea ir al menu");
		outtextxy(112,124 + 12*13,"-borrar: CTRL+N, Salir: CTRL+X");

		hlp1->RunWindow();

		delete hlp1;
		setcolor(colortrazo);
	break;
	case 25:		//dibujar ventana de ayuda
		CapWindw * hlp2 = new CapWindw(100,100,308,200,
									1,1,"Ayuda en Linea (Rectas)");
		hlp2->DrawWindow();
		setcolor(0);
		outtextxy(112,124 + 12*0,"Dibujar Lineas:");
		outtextxy(112,124 + 12*1," Para dibujar estas, haga clic en el");
		outtextxy(112,124 + 12*2,"menu lineas.luego haga clic en.");
		outtextxy(112,124 + 12*3,"ESCOGER. ");
		outtextxy(112,124 + 12*4,"-----------------------------------");
		outtextxy(112,124 + 12*5,"Podra hacer clic izquierdo sobre");
		outtextxy(112,124 + 12*6,"cualquier punto en pantalla, y ");
		outtextxy(112,124 + 12*7,"luego clic derecho sobre cualquier ");
		outtextxy(112,124 + 12*8,"otro punto.");
		outtextxy(112,124 + 12*9,"Luego del segundo clic la linea se");
		outtextxy(112,124 + 12*10,"dibujara entre los dos puntos.");
		outtextxy(112,124 + 12*11,"presione [ESC] si desea ir al menu");
		outtextxy(112,124 + 12*12,"-para salir del programa: CTRL+X");
		outtextxy(112,124 + 12*13,"-para borrar la pantalla: CTRL+N");

		hlp2->RunWindow();

		delete hlp2;
		setcolor(colortrazo);
	break;
	case 34:		//dibujar ventana de ayuda
		CapWindw * hlp3 = new CapWindw(100,100,308,200,
									1,1,"Ayuda en Linea (Poligonos)");
		hlp3->DrawWindow();
		setcolor(0);
		outtextxy(112,124 + 12*0,"Dibujar Poligonos:");
		outtextxy(112,124 + 12*1," Haga clic en el menu POLIGONO,");
		outtextxy(112,124 + 12*2,"luego haga clic sobre ESCOGER");
		outtextxy(112,124 + 12*3,"-----------------------------------");
		outtextxy(112,124 + 12*4," Podra hacer clic izquierdo sobre");
		outtextxy(112,124 + 12*5,"cualquier punto en pantalla, y ");
		outtextxy(112,124 + 12*6,"luego clic derecho sobre cualquier ");
		outtextxy(112,124 + 12*7,"otro punto.");
		outtextxy(112,124 + 12*8," Luego del segundo clic un poligono");
		outtextxy(112,124 + 12*9,"de 3 lados se dibujara. ");
		outtextxy(112,124 + 12*10," Podra especificar opciones para los");
		outtextxy(112,124 + 12*11,"poligonos dentro del menu. ");
		outtextxy(112,124 + 12*12,"-presione [ESC] para ir al menu.");
		outtextxy(112,124 + 12*13,"-borrar: CTRL+N, salir: CTRL+X");

		hlp3->RunWindow();

		delete hlp3;
		setcolor(colortrazo);
	break;
	case 4:		//dibujar ventana de ayuda
		CapWindw * hlp4 = new CapWindw(100,100,308,200,
									1,1,"Ayuda en Linea (Spray)");
		hlp4->DrawWindow();
		setcolor(0);
		outtextxy(112,124 + 12*0,"Dibujar con Spray:");
		outtextxy(112,124 + 12*1,"  Podra dibujar en pantalla a mano");
		outtextxy(112,124 + 12*2,"alzada con efecto de spray al hacer");
		outtextxy(112,124 + 12*3,"clic en el menu SPRAY para luego ");
		outtextxy(112,124 + 12*4,"elegir el tamaño de spray que desee.");
		outtextxy(112,124 + 12*5,"-----------------------------------");
		outtextxy(112,124 + 12*6," Luego podra dejar presionado el ");
		outtextxy(112,124 + 12*7,"boton izquierdo del mouse para ");
		outtextxy(112,124 + 12*8,"dibujar una linea a mano alzada");
		outtextxy(112,124 + 12*9,"con efecto de spray.");
		outtextxy(112,124 + 12*10,"----------------------------------");
		outtextxy(112,124 + 12*11," Presione [ESC] para ir al menu");
		outtextxy(112,124 + 12*12,"-para salir del programa: CTRL+X");
		outtextxy(112,124 + 12*13,"-para borrar la pantalla: CTRL+N");

		hlp4->RunWindow();

		delete hlp4;
		setcolor(colortrazo);
	break;
	case 61:		//dibujar ventana de ayuda
		CapWindw * hlp5 = new CapWindw(100,100,308,200,
									1,1,"Ayuda en Linea General");
		hlp5->DrawWindow();
		setcolor(0);
		outtextxy(112,124 + 12*0,"Dibujar Lineas y Poligonos:");
		outtextxy(112,124 + 12*1," Para dibujar estas, haga clic en el");
		outtextxy(112,124 + 12*2,"menu lineas o en el menu poligono,");
		outtextxy(112,124 + 12*3,"elija el tipo y grueso de lineas que");
		outtextxy(112,124 + 12*4,"desee haciendo clic en su respectivo");
		outtextxy(112,124 + 12*5,"elemento del menu, luego de esto");
		outtextxy(112,124 + 12*6,"haga clic en [ESCOGER] para dibujar ");
		outtextxy(112,124 + 12*7,"la figura correspondiente.");
		outtextxy(112,124 + 12*8,"-----------------------------------");
		outtextxy(112,124 + 12*9," Si desea regresar a la interfaz");
		outtextxy(112,124 + 12*10,"grafica para elegir alguna otra");
		outtextxy(112,124 + 12*11,"opcion, presione [ESC] en el teclado");
		outtextxy(112,124 + 12*12,"-para salir del programa: CTRL+X");
		outtextxy(112,124 + 12*13,"-para borrar la pantalla: CTRL+N");

		hlp5->RunWindow();

		delete hlp5;
		setcolor(colortrazo);
	break;
	case 62:    // abre el manual de usuario con programa externo y cierra el programa
/*		char *path;
		path = searchpath("winword.exe");
		printf("\n\n\nBuscando MS Word... : %s\n",path);
*/
//		execl("more","c:\\prog1\\proy1\\test.txt",NULL);
		setcolor(1);
		outtextxy(getmaxx()/2 - 200,getmaxy()/2,
					"Se Abrira un programa externo en 2 seg. y PaintKiller se cerrara");
		outtextxy(getmaxx()/2 - 200,getmaxy()/2 + 16,
				"Cuando termine de leer la ayuda, abra PaintKiller de nuevo.");
		delay (2000);
		//cambiar el path cuando se entregue el proyecto.
		//system("c:\\\%programfiles\%\\%intern~1\%\\\iexplore.exe c:\\prog1\\proy1\\test.txt");
		system("notepad man.txt");
		exit(0);
	break;
	case 63:    //muestra ventana de acerca de...
		OKWindw * about = new OKWindw("Acerca de PAINTkiller...",
									"PAINTkiller v1.0 - Por: Erik Giron Marquez",
									"C# 200313492; Proyecto #1. IPC1. USAC 2005");
		about->DrawWindow();
		about->RunWindow();
		delete about;
	break;

	}
}
/******************************* 	draw()  *********************************/
//---------------------------------------------------------------------------/
int draw(int f)
{
	OcultarPuntero();
	int x0,y0,xf,yf,salir; // establece coordenadas de accion.

	if (nuevo == 1)       // si la bandera nuevo es 1, borra la pantalla
	{
		setfillstyle(1,colorcanvas);
		bar(0,0,getmaxx(),getmaxy());
		nuevo = 0;
	}
	setcolor(colortrazo);    // asigna color de trazo a lo que se vaya a dibujar
	setlinestyle(tipolin,1,gruesolin);  // asigna tipo del linea

	salir = 0;
	MostrarPuntero();
	while(salir == 0)       //dibuja hasta que la funcion llamada devuelva algun
	{                       //valor
		switch(f)
		{
		case 25:    //dibujar lineas a mano alzada o con movimento
			if (mvment == 0)		//si la bandera mvment = 0 se dibuja sin mov.
				//condicional que establece manoalzada
				(manoalz==0)?(salir = linea(1)):(salir = manoalzada());
			else	// sino se le aplica la animacion
				salir = movimiento(1);
		break;
		case 34:    //para dibujar poligonos estaticos o con movimiento
			(mvment==0)?(salir = linea(0)):(salir = movimiento(0));
		break;
		case 41:     //de aqui en adelante dibuja spray
			salir = spray(30);
		break;
		case 42:
			salir = spray(20);
		break;
		case 43:
			salir = spray(10);
		break;
		}
	}
	return 0;
}
/******************************* 	linea()  ********************************/
//---------------------------------------------------------------------------/
int linea(int eslinea)
{
	int s = 0; 			// bandera de salida
	int x0,y0,xf,yf; 	// coordenadas
	int punto = 0;   	// variable para orden sucesivo(Cuenta el no. de punto)

	while(s == 0)
	{

		GetEvent(evntmsg);	//espera evento de mouse o teclado
		if (evntmsg.type == KEYBD)
		{
			if (evntmsg.key == 0x3b00)	//f1
			{
				(eslinea==1)?help(25):help(34);
			}
			if (evntmsg.key == 0x011b)
			{			// Si se presiona esc
				s = -1;
				break;
			}
			if (evntmsg.key == 0x2d18) // ctrl + x
			{
				dismiss(1);      // Si se presiona CTRL+X
			}
			if (evntmsg.key == 0x310e)
			{
				OcultarPuntero();
				setfillstyle(1,colorcanvas);
				bar(0,0,getmaxx(),getmaxy());      // Si se presiona CTRL+N
				MostrarPuntero();
			}
		}
		else if ((BotonPulsado() == 1)/*(evntmsg.type == MBUTTON)*/ /*&& (punto == 0)*/)
		{// cuando se cliquee con boton izquierdo asigna punto inicial
			x0 = PosHoriGraf();
			y0 = PosVertGraf();
			punto = 1;
		}
//			GetEvent(evntmsg);
		else if ((BotonPulsado() == 2)/*(evntmsg.type == MBUTTON)*/ /*&& (punto == 1)*/)
		{// cuando se cliquee con boton derecho asigna punto final
			xf = PosHoriGraf();
			yf = PosVertGraf();
			punto = 2;
		}
		if(punto == 2)
		{
//			OcultarPuntero();
			if (eslinea == 1)
			{
				OcultarPuntero();
				line(x0,y0,xf,yf);
				MostrarPuntero();
			}
			if (eslinea == 0)
				poligono(x0,y0,xf,yf,ladospoli);
			punto = 0;
//			MostrarPuntero();
		}

	}

return s;
}

/******************************* manoalzada()********************************/
//---------------------------------------------------------------------------/
int manoalzada()
{
	int s = 0;
	int brocha[3][3] ={{0,1,0},{1,1,1},{0,1,0}};// matriz que establece los
												// puntos de la "brocha" para dibujar

	while (s==0)
	{
	GetEvent(evntmsg); // espera evento
		if (evntmsg.type == KEYBD)
		{
			if (evntmsg.key == 0x3b00)	//f1
			{
				help(24);
			}
			if (evntmsg.key == 0x011b)	// ESC
			{		
				s = -1;
				break;
			}
			if (evntmsg.key == 0x2d18) // ctrl + x
			{
				dismiss(1);      
			}
			if (evntmsg.key == 0x310e)     // Si se presiona CTRL+N
			{
				OcultarPuntero();
				setfillstyle(1,colorcanvas);
				bar(0,0,getmaxx(),getmaxy());
				MostrarPuntero();
			}
		}
		else //if ((BotonPulsado() == 1)/*(evntmsg.type == MBUTTON)*/ /*&& (punto == 0)*/)
		{  // sino comenzara a dibujar en cada punto mientras se presione el mouse
			while(BotonPulsado() == 1)
			{
			//OcultarPuntero();
				for(int i = 0;i<3;i++)
				{
					for (int j = 0;j<3;j++)
					{
						if(brocha[i][j] == 1)
						putpixel(PosHoriGraf() - j - 1,PosVertGraf() - i - 1,colortrazo);
					}
				}
			//MostrarPuntero();
			}

		}
	}
	return s;
}

/********************************* spray() **********************************/
//---------------------------------------------------------------------------/
int spray(int tam)     // similar al algoritmo de mano alzada
{
	int s = 0;
	unsigned int patron;  //establece el patron para dibujar la linea base
	int coci_ang;		  //cociente de angulo para el asterisco de spray

	// Establece tamano de angulo para cada radio.
		coci_ang = 15;
	// patron para linea 16 bits (en binario: 1010101010101010)
		patron = 43690;

	while (s==0)
	{
	GetEvent(evntmsg);
		if (evntmsg.type == KEYBD)
		{
			if (evntmsg.key == 0x3b00)	//f1
			{
				setlinestyle(tipolin,1,gruesolin);		//revierte a la linea predeterminada
				help(4);
			}
			if (evntmsg.key == 0x011b)
			{			// Si se presiona esc
				s = -1;
				break;
			}
			if (evntmsg.key == 0x2d18) // ctrl + x
			{
				dismiss(1);      // Si se presiona CTRL+X
			}
			if (evntmsg.key == 0x310e)
			{
				OcultarPuntero();
				setfillstyle(1,colorcanvas);
				bar(0,0,getmaxx(),getmaxy());      // Si se presiona CTRL+N
				MostrarPuntero();
			}
		}
		else //if ((BotonPulsado() == 1)/*(evntmsg.type == MBUTTON)*/ /*&& (punto == 0)*/)
		{
			while(BotonPulsado() == 1)
			{
			OcultarPuntero();
			int x1 = PosHoriGraf();
			int y1 = PosVertGraf();
				// dibuja un asterisco con lineas punteadas simulando spray
				for(int i = 0;i< (coci_ang * 2);i++)
				{
					//patron = random(65000);
					setlinestyle(4,patron,gruesolin);
					line(x1,
						 y1,
						(tam*cos((i*M_PI/coci_ang))+x1),
						(tam*sin((i*M_PI/coci_ang))+y1));
				}
			MostrarPuntero();
			}

		}
	}
	setlinestyle(tipolin,1,gruesolin);		//revierte a la linea predeterminada
	return s;

}

/******************************* poligono  ()********************************/
//---------------------------------------------------------------------------/
void poligono(int xc,int yc,int xf,int yf,int lados)
{
	OcultarPuntero();
	long double theta,d,l,angulo,pi;
	int i,x,y,x0,y0,x1,y1;
		 //se establece un numero grande de pi para mayor exactitud en los calculos
	pi = M_PI;

		 // angulo de giro para la funcion vectorial
	theta = (2*pi)/(long double)lados;

		// distancia del centro a la orilla (formula de la distancia)
	d = sqrtl( powl((long double)(xf-xc),2) + powl((long double)(yf-yc),2) );

		// ley de senos para longitud de lado
	l = (sinl(theta)*d)/(sinl((pi-theta)/2));
	//	printf("d=%e,theta=%e,l=%e,pi=%f\n",d,theta,l,pi); //debug

	// Condicional para crear poligono cuando lados es menor o igual a 10
	if (lados <= 10)
	{
		for (i=0;i<lados;i++)
		{
			angulo=(-1)*theta*(i+1);
			if (i==0)
			{
				x0=xf;
				y0=yf;
				x1=xf;
				y1=yf;
			}
			else
			{
				x0=x;
				y0=y;
			}
			x=/*ceill*/(int)(l*cosl(angulo) + x0);
			y=/*ceill*/(int)(l*sinl(angulo) + y0);
			line(x0,y0,x,y);
			if (i==(lados-1) && (relleno!=0))
				{line(x,y,x1,y1);} //hack para cerrar el polig.
		}
	}
//	if((lados >10) && (lados < 360))
//		outtextxy(xc, yc,"funcion no implementada");
	// Condicional para crear circulo cuando lado es mayor a 10
	if(lados > 10)
		circle(xc,yc,d);

	// algoritmo de relleno
	if (relleno!=0)
	{
		setfillstyle(1,relleno);
		(lados<=10)?floodfill(x-1,y-1,0):floodfill(xc,yc,0);
	}
	MostrarPuntero();
	setfillstyle(1,colorcanvas);
}

/******************************* movimiento()********************************/
//---------------------------------------------------------------------------/
int movimiento(int eslinea)
{
	int s = 0; 			// bandera de salida
	int x0,y0,xf,yf; 	// coordenadas
	int punto = 0;   	// Cuenta el no. de punto
	setfillstyle(1,colorcanvas);
	while(s == 0)
	{

		GetEvent(evntmsg);	//espera evento de mouse o teclado

		if (evntmsg.type == KEYBD)
		{
			if (evntmsg.key == 0x3b00)	//f1
			{
				(eslinea==1)?help(25):help(34);
			}
			if (evntmsg.key == 0x011b)
			{			// Si se presiona esc
				s = -1;
				break;
			}
			if (evntmsg.key == 0x2d18) // ctrl + x
			{
				dismiss(1);      // Si se presiona CTRL+X
			}
			if (evntmsg.key == 0x310e)
			{
				OcultarPuntero();
				setfillstyle(1,colorcanvas);
				bar(0,0,getmaxx(),getmaxy());      // Si se presiona CTRL+N
				MostrarPuntero();
			}
		}
		else if ((evntmsg.button/*BotonPulsado()*/ == 1)/*(evntmsg.type == MBUTTON)*/ /*&& (punto == 0)*/)
		{
			x0 = PosHoriGraf();
			y0 = PosVertGraf();
			punto = 1;
		}
//			GetEvent(evntmsg);
		else if ((/*BotonPulsado() */evntmsg.button == 2)/*(evntmsg.type == MBUTTON)*/ /*&& (punto == 1)*/)
		{
			xf = PosHoriGraf();
			yf = PosVertGraf();
			punto = 2;
		}
		// Algoritmo de Movimiento
		if(punto == 2)
		{
//			OcultarPuntero();
			int c1,c2,j = 0;
			int limit = 0;
			//int signo = 1;
			if (mvment == 1)
			{
				limit = 2*getmaxx();
				for (int i=0; i < limit; i++)
				{
					if ((i <= ((limit/2)-x0) ) || ( i > (limit- x0) ))	// cuando tope en la pantalla
						j++;            // j comenzara (2*limit/2)
					if ((i > (limit/2) - x0) && (i<= (limit) - x0))        // cuand
						j--;
	  //				while (i > limit - x0)
	  //					j++;
					c1 = x0 + j;
					c2 = xf + j;
					bar(0,0,getmaxx(),getmaxy());
					if (eslinea == 1)
					{
						line(c1,y0,c2,yf);
					}
					if (eslinea == 0)
					{
						poligono(c1,y0,c2,yf,ladospoli);
					}
					delay(1);
				}
			}
			if (mvment == 2)
			{
				limit = 2*getmaxy();
				for (int i=0; i < limit; i++)
				{   // primer movimiento o cuando tope la pantalla por 2da vez
					if ( (i <= ((limit/2)-y0) ) || ( i > (limit- y0) ))

						j++;            // j comenzara (2*limit/2)
					if ((i > (limit/2) - y0) && (i<= (limit) - y0)) // cuando tope en la pantalla 1er vez
						j--;
					bar(0,0,getmaxx(),getmaxy());
					c1 = y0 + j;
					c2 = yf + j;
					if (eslinea == 1)
					{
						line(x0,c1,xf,c2);
					}
					if (eslinea == 0)
					{
						poligono(x0,c1,xf,c2,ladospoli);
					}
					delay(1);
				}
			}
//			punto = 0;
			s = -1;		//se sale del bucle luego de terminar la animacion.
//			MostrarPuntero();
		}

	}
return s;
}

/******************************* screenmsg() ********************************/
//---------------------------------------------------------------------------/
void screenmsg(char * mensaje, int tiempo)
{
	void * buff;				//buffer
	int size,x1,y1,x2,y2;
	x1=0;                      	//Coordenadas
	y1=getmaxy() -16;
	x2=textwidth(mensaje) + 8;
	y2=getmaxy();

	size = imagesize(x1,y1,x2,y2);	// Apartar memoria de sistema
	buff = (int *)malloc(size);

	getimage(x1,y1,x2,y2,buff);		// guarda imagen limitada por coordenadas
	setfillstyle(1,15);
	bar(x1,y1,x2,y2);               // dibuja barra de fondo
	setcolor(1);
	outtextxy(x1+10,y1,mensaje);    // escribe texto en pantalla
	delay(tiempo);

	putimage(x1,y1,buff,0);         // coloca imagen en buffer a pantalla
	free(buff);                     // libera la memoria del buffer

	setfillstyle(1,colorcanvas);    // retorna a los colores de dibujo
	setcolor(colortrazo);

}
/******************************* screenmsg() ********************************/
//---------------------------------------------------------------------------/
void colorsel(int salir, void * &buff)
{
	char s[3];
	int size,x1,y1,x2,y2;

	x1=0;                      	//Coordenadas
	y1=20;
	x2=x1+32;
	y2=(y1*16)+y1 ;

	if (salir == 0)
	{

		size = imagesize(x1,y1,x2,y2);	// Apartar memoria de sistema
		buff = (int *)malloc(size);

		getimage(x1,y1,x2,y2,buff);		// guarda imagen limitada por coordenadas

		setfillstyle(1,7);
		bar(x1,y1,x2,y2);               // dibuja barra de fondo
		setcolor(0);

		for (int i = 0; i < 16; i++)
		{
			itoa(i+1,s,10);
			outtextxy(x1,y1*(i+1),s);
			setfillstyle(1,i);
			bar(x1+16,y1*(i+1),x1+32,y1*(i+1)+8);
			rectangle(x1+16,y1*(i+1),x1+32,y1*(i+1)+8);
		}

	}
	else
	{
		putimage(x1,y1,buff,0);         // coloca imagen en buffer a pantalla
		free(buff);                     // libera la memoria del buffer
		delete [] s;
		setfillstyle(1,colorcanvas);    // retorna a los colores de dibujo
		setcolor(colortrazo);
	}

	setfillstyle(1,colorcanvas);    // retorna a los colores de dibujo
	setcolor(colortrazo);

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

