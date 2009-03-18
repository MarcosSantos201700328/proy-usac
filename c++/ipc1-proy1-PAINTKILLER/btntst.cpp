#include "raton.h"
#include "eventos.h"
#include "control.h"


/*-------

todo list:
=========
*-establecer funciones para valor retornado de clicmenu.
-mostrar el help y recondicionar el while en dibujamenu.
	-componer el problema del crash subito.
			(idea: convertir a punteros todos los objetos estaticos);
--------- */



//	DECLARACION DE VARIABLES
int i;

int drivmouse;
char buf[3];
char mtestrt[4];
//	flags
int tecla;
int banmenu;	// 	Bandera para menu
int outmenu = 0;// salida del bucle de gui.
int mainflag;	//  Bandera Principal de control del programa.
				//	valores de mainflag:
				//		unidades: No. comando
				// 		decenas : No. menu

//   declaracion de objetos

//	DECLARACION DE PROTOTIPOS DE
//	FUNCIONES GENERALES

void mostrargui();			// Dibuja la barra del menu con sus botones
							// para abrir menues desplegables.
							// si su argumento es 1, borra el menu

void muestramenu(int, int); // Muestra menu invocado por mostrargui()
							// sus parametros son la posicion y la bandera
							// si la posicion es -1, destruye el menu identificado
							// con la bandera
int dibujamenu(int,int,int);// Dibuja y establece rango de accion de cada comando
							// de menu; devuelve el valor de y final

//void ocultamenu(int);// esconde menues(deprecado)
void escoje(int);
void welcome(void);  //Muestra pantalla de Bienvenida
int clicmenu(int,int,int);   //accion cuando se hace clic en algun comando de menu.

int dismiss(void);		 //Despedida
int iniciographics(void);
void mouseinit(void);

//***	MAIN		*****
int main(void)
{
	//Inicio de Drivers
	iniciographics();
	mouseinit();
	setbkcolor(8);
	setfillstyle(1,8);

	bar(0,0,getmaxx(),getmaxy());

//	comando cmd1(200, 300, "Nuevo", "n");

//	cmd1.DrawWindow();
	welcome();
	int salida = 0;
	// CICLO PRINCIPAL DEL PROGRAMA
	while (!salida)
	{
		mostrargui();

		switch (mainflag)
		{
		case 11:
		break;
		case 12:
			salida = dismiss();
		break;
		case 21:
			escoje(mainflag);
		break;
		case 22:
		break;
		case 23:
		break;
		case 24:
		break;
		case 25:
		break;
		case 31:
		break;
		case 32:
		break;
		case 33:
		break;
		case 34:
		break;
		case 41:
		break;
		case 42:
		break;
		case 43:
		break;
		case 44:
		break;
		case 51:
		break;
		case 52:
		break;
		case 61:
		break;
		case 62:
		break;
		case 63:
		break;
		}
		outmenu = 0;

	}
	// creacion de objetos
//	bandera_control=0;

	// Repite hasta que un boton es escojido


	getch();
	closegraph();
	return 0;
}



//***	DEFINICION FUNCIONES GENERALES	*****/


void welcome()
{
	OcultarPuntero();
	OKWindw * w3 = new OKWindw("Bienvienido a PAINTera",
								"Para ayuda dirijase al",
								"menu Ayuda->Ayuda en pantalla");
	w3->DrawWindow();
	MostrarPuntero();
	w3->RunWindow();
	delete w3;

}

void mostrargui()       // MUESTRA EL MENU
{

	OcultarPuntero();

	// Asigna nombres a los menues
	char * nombres[6] =
	{
	"^PROGRAMA","^LINEAS","^GEOMETRICOS",
	"^SPRAY","^COLORES","^AYUDA"
	};

	// Matriz para establecer el tamano y la ubicacion
	// de cada menu.
	int tam[6], x0[6];

	// Establece automaticamente el tamano de cada boton
	// que abre los menues desplegables.
	for (int i =0 ;i < 6; i++)
	{

		tam[i] = (strlen(nombres[i]) * 8);
//		printf("%i\n",tam[i]);//debug
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
	aboton prog(x0[0],0,tam[0],nombres[0]);
	aboton lin(x0[1],0,tam[1],nombres[1]);
	aboton geom(x0[2],0,tam[2],nombres[2]);
	aboton spray(x0[3],0,tam[3],nombres[3]);
	aboton color(x0[4],0,tam[4],nombres[4]);
	aboton ayuda(x0[5],0,tam[5],nombres[5]);


		// dibuja objetos llamando a su funcion mienbro de dibujo.
	barramenu->DrawWindow(); // dibuja barra de menu.

	prog.DrawWindow();
	lin.DrawWindow();    // Dibuja los botones de cada menu.
	geom.DrawWindow();
	spray.DrawWindow();
	color.DrawWindow();
	ayuda.DrawWindow();


	MostrarPuntero();

	// Ciclo principal del menu
	while ((banmenu >=0) && (banmenu <7)  && outmenu == 0)
	{
		GetEvent(evntmsg); // espera respuesta de mouse o teclado

		if (prog.Clicked(evntmsg))
		{
			muestramenu(banmenu,-1);
			banmenu=1;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		 //button = OK;
		}
		else if (lin.Clicked(evntmsg))
		{  // button = CANCEL;

			muestramenu(banmenu,-1);
			banmenu = 2;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
		else if (geom.Clicked(evntmsg))
		{  // button = CANCEL;


			muestramenu(banmenu,-1);
			banmenu = 3;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);

		}
		else if (spray.Clicked(evntmsg))
		{  // button = CANCEL;

			muestramenu(banmenu,-1);
			banmenu = 4;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
		else if (color.Clicked(evntmsg))
		{  // button = CANCEL;
			muestramenu(banmenu,-1);
			banmenu = 5;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
		else if (ayuda.Clicked(evntmsg))
		{

			muestramenu(banmenu,-1);
			banmenu = 6;
			muestramenu(banmenu,x0[banmenu - 1]);
			delay(250);
		}
	}

	// borra objetos luego de escojer comando para no llenar la poca
	// memoria que asigna este compilador a los programas para DOS.
	delete barramenu, prog, lin, geom, spray, color, ayuda;

}

void muestramenu(int flag, int x) //x condicion,-1 destruye menu
{
//OcultarPuntero();
int y0=19;

Windw * fmenu = new Windw(0,y0,0,100,0,0);


if (x!=-1)
{
	fmenu->setwx(x);
	switch (flag)
	{
		case 1:
//			printf("clicked prog\n"); //debug

//			fmenu->setwx(x);
			fmenu->setww(125);
			fmenu->setwh(40);
//			fmenu->DrawWindow();
//			MostrarPuntero();
//			dibujamenu(flag,x,y0);

		break;
		case 2:
//			printf ("clicked lin\n"); //debug
//			fmenu->setwx(x);
			fmenu->setww(100);
			fmenu->setwh(90);
//			fmenu->DrawWindow();
//			MostrarPuntero();
//			dibujamenu(flag,x,y0);
		break;
		case 3:
//			printf ("clicked geom\n"); //debug
//			fmenu->setwx(x);
			fmenu->setww(100);
			fmenu->setwh(90);
//			fmenu->DrawWindow();
//			MostrarPuntero();
//			dibujamenu(flag,x,y0);
		break;
		case 4:
//			printf ("clicked spray\n"); //debug
//			fmenu->setwx(x);
			fmenu->setww(88);
			fmenu->setwh(55);
//			fmenu->DrawWindow();
//			MostrarPuntero();
//			dibujamenu(flag,x,y0);
		break;
		case 5:
//			printf ("clicked color\n"); //debug
//			fmenu->setwx(x);
			fmenu->setww(100);
			fmenu->setwh(40);
//			fmenu->DrawWindow();
//			dibujamenu(flag,x,y0);
		break;
		case 6:
			fmenu->setww(150);
			fmenu->setwh(56);
//			cleardevice();  //debug
//			abort();		//debug
//			printf("clicked ayuda\n"); //debug
//			mostrargui();
		break;
	};
	//muestra
	fmenu->DrawWindow();
	MostrarPuntero();
	//espera accion
	mainflag = dibujamenu(flag,x,y0);
	printf("Mainflag es: %d ",mainflag); //debug
	//oculta y borra el objeto
	OcultarPuntero();
	setfillstyle(1,getbkcolor());
	bar (0,19,getmaxx(),getmaxy());
	delete fmenu;
	outmenu = 1;			// establece salida de bucle principal
	MostrarPuntero();

}
else
{
	setfillstyle(1,getbkcolor());
	bar (0,19,getmaxx(),getmaxy());
	delete fmenu;
	/*
	switch (flag)
	{
		case 1:
			printf("ocult prog, ");		//debug
			setfillstyle(1,getbkcolor());
			bar (0,19,getmaxx(),getmaxy());
			delete fmenu;
		break;
		case 2:
			printf ("ocult lin, ");		//debug
			setfillstyle(1,getbkcolor());
			bar (0,19,getmaxx(),getmaxy());
			delete fmenu;
		break;
		case 3:
			printf ("ocult geom, ");		//debug
			setfillstyle(1,getbkcolor());
			bar (0,19,getmaxx(),getmaxy());
			delete fmenu;
		break;
		case 4:
			printf ("ocult spray, ");		//debug
			setfillstyle(1,getbkcolor());
			bar (0,19,getmaxx(),getmaxy());
			delete fmenu;
		break;
		case 5:
			printf ("ocult color, ");		//debug
			setfillstyle(1,getbkcolor());
			bar (0,19,getmaxx(),getmaxy());
			delete fmenu;
		break;
		case 6:
			printf("ocult ayuda, ");		//debug
			setfillstyle(1,getbkcolor());
			bar (0,19,getmaxx(),getmaxy());
			delete fmenu;
		break;
		default:
			printf("1st time, ");		//debug
		break;
	};*/

}
}

/*
void ocultamenu(int flag)
{
-flag;
}
*/


int dibujamenu(int flag,int x,int y)
{
	char *cmd[6][5]=
	{
		{"NUEVO    CTRL+N","SALIR    CTRL+X","",NULL,NULL},
		{"GROSOR","TIPO","MOVIMIENTO","MANO ALZADA","ESCOJER"},
		{"LADOS","TIPO","MOVIMIENTO","MANO ALZADA","ESCOJER"},
		{"AMPLIO","MEDIO","ESTRECHO","",NULL},
		{"COLOR LINEA","COLOR FONDO","",NULL,NULL},
		{"EN PANTALLA","MANUAL DE USUARIO","ACERCA DE...","",NULL}
	};

	char * buff = NULL;

	int posy[5];						//matriz que almacenara posiciones

	int limite = 5;//(sizeof( *cmd[flag + 1] ) + 1); // Establece limite para el
												// sig. ciclo.

	for (int i=0; i< limite; i++)		//calcula posicion en y
	{
		posy[i] = (y*(i+1)) +2;

	}

//	int f = flag - 1;
	int ret = 0;
	int j = 0;
	setcolor(6);


	//debug
	char pos[5];
	itoa(ret,pos,10);
	setcolor(1);
	outtextxy(getmaxx() - 16,100,pos);
	// end debug

//
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
		line(x+10,posy[4]-5,x+90,posy[4]-5);
		outtextxy(x+2,posy[4],cmd[2][4]);

	break;
	case 4:
		outtextxy(x+2,posy[0],cmd[3][0]);
		line(x+10,posy[1]-5,x+115,posy[1]-5);
		outtextxy(x+2,posy[1],cmd[3][1]);
		line(x+10,posy[2]-5,x+115,posy[2]-5);
		outtextxy(x+2,posy[2],cmd[3][2]);

	break;
	case 5:
		outtextxy(x+2,posy[0],cmd[4][0]);
		line(x+10,posy[1]-5,x+115,posy[1]-5);
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
	MostrarPuntero();

	// invoca la funcion clicmenu que establece rango.
	j = clicmenu(flag,x+2,posy[0]);
									//	regresa el valor devuelto por clicmenu
	return j;
}


int clicmenu(int flag,int x, int y) // retorna en decimal el valor de la bandera
									// y en unidad el valor del boton
{
	int clic, tc,numcom = 0;

	setcolor(1);//debug
	outtextxy(getmaxx()-100,200,"si");  //debug
//	if (flag == 1)
//	{
		outtextxy(getmaxx()-100,200,"tambien");//debug
	// mientras clic no sea 1
	while ((clic!=1) /*|| (tc==0)*/)
		{
			//if (flag == 1)
			GetEvent(evntmsg);

			//--------------------------comando 1


/*			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
				(PosVertGraf() > y-19) && (PosVertGraf() < y + 19) &&
				BotonPulsado == 0)
			{
				//resaltar(0);
				printf("encima\t"); //debug
				//	clic = 1;
			}
			else*/
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > y) && (PosVertGraf() < y+19) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 1;
				printf("encima clic\t"); //debug
				clic = 1;
			}
			else if ((flag == 1) && (evntmsg.type == KEYBD))
			{
				if (evntmsg.key == 0x310e)			//Ctrl+N
				{
				//ClickButton();
				numcom = 1;
				printf("teclado");//debug
				clic = 1;
				}
			}
			else if ((PosHoriGraf() <= x) && (PosHoriGraf() >= x+100) &&
				(PosVertGraf() <= y-19) && (PosVertGraf() >= y + 19) &&
				BotonPulsado() != 0)
			{
				//resaltar(1);
				printf("afuera\t"); //debug
				clic = 1;
			}

			//-------------- Comando 2


			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 2*y) && (PosVertGraf() < 2*y+19) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 2;
				printf("encima clic\t"); //debug
				clic = 1;
			}
			else if ((flag == 1) && (evntmsg.type == KEYBD))
			{
				if (evntmsg.key == 0x2d18)			//Ctrl+X
				{
				//ClickButton();
				numcom = 2;
				printf("teclado");//debug
				clic = 1;
				}
			}
			else if ((PosHoriGraf() <= x) && (PosHoriGraf() >= x+100) &&
				(PosVertGraf() <= 2*y) && (PosVertGraf() >= 2*y + 19) &&
				BotonPulsado() != 0)
			{
				//resaltar(1);
				printf("afuera\t"); //debug
				clic = 1;
			}

			// ------------------comando 3
		// elimina posibilidad de asignar comandos a menues con menos de 2
		// miembros
		if ((flag !=1) && (flag !=5) )
		{
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 3*y) && (PosVertGraf() < 3*y+19) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 3;
				printf("encima clic\t"); //debug
				clic = 1;
			}
			else if ((PosHoriGraf() <= x) && (PosHoriGraf() >= x+100) &&
				(PosVertGraf() <= 3*y) && (PosVertGraf() >= 3*y + 19) &&
				BotonPulsado() != 0)
			{
				//resaltar(1);
				printf("afuera\t"); //debug
				clic = 1;
			}
		}
		// ------------------------comando 4
		if ((flag !=1) && (flag !=5) && (flag != 4) && (flag != 6) )
		{
			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 4*y) && (PosVertGraf() < 4*y+19) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 4;
				printf("encima clic\t"); //debug
				clic = 1;
			}
			else if ((PosHoriGraf() <= x) && (PosHoriGraf() >= x+100) &&
				(PosVertGraf() <= 4*y) && (PosVertGraf() >= 4*y + 19) &&
				BotonPulsado() != 0)
			{
				//resaltar(1)
				printf("afuera\t"); //debug
				clic = 1;
			}

		 // -----------------------comando 5

			if ((PosHoriGraf() > x) && (PosHoriGraf() < x+100) &&
					(PosVertGraf() > 5*y) && (PosVertGraf() < 5*y+19) &&
					BotonPulsado() != 0)
			{
				//ClickButton();
				numcom = 5;
				printf("encima clic\t"); //debug
				clic = 1;
			}
			else if ((PosHoriGraf() <= x) && (PosHoriGraf() >= x+100) &&
				(PosVertGraf() <= 5*y) && (PosVertGraf() >= 5*y + 19) &&
				BotonPulsado() != 0)
			{
				//resaltar(1);
				printf("afuera\t"); //debug
				clic = 1;
			}
		}

	}


	return (flag*10)+numcom;
}

int dismiss(void)
{
	Button wndw1(200, 200, "^ACEPTAR");
	Button wndw2(280, 200, "^CANCELAR");

	wndw1.DrawWindow();
	wndw2.DrawWindow();
	int button = 0;
	while (!button)
	{
	 GetEvent(evntmsg);
	// Espera algun clic.
	 if (wndw1.Clicked(evntmsg))
		 button = OK;
	 else if (wndw2.Clicked(evntmsg))
	   button = CANCEL;
	 //else if (cmd1.Clicked(evntmsg))
	 //  printf("clicked");
	}
	OcultarPuntero();
	setcolor(15);
	if (button == OK)
	outtextxy(200, 300, "You clicked OK.");
	else
	outtextxy(200, 300, "You clicked CANCEL.");


return 1;
}

void escoje(int f)
{
    OcultarPuntero();
	char op[4];
	char texto[3][36];

	switch (f)
	{
	case 21:
		strcpy(texto[0],"Grueso de Linea");
		strcpy(texto[1],"Escoja el grueso en");
		strcpy(texto[2],"pixeles qu desee.");
	break;
	case 22:
		strcpy(texto[0],"Tipo de Linea");
		strcpy(texto[1],"Escoja el tipo de linea");
		strcpy(texto[2],"que le agrade.");
	break;
	case 23:
		strcpy(texto[0],"Movimiento inicial");
		strcpy(texto[1],"Escoja el movimiento");
		strcpy(texto[2],"(0:sin mov. 1:Horiz. 2:Vert.)");
	break;
	case 31:
		strcpy(texto[0],"Numero de Lados");
		strcpy(texto[1],"Ingrese un numero de lados entre");
		strcpy(texto[2],"3 y 10, 360 crea circulo");
	break;
	case 32:
		strcpy(texto[0],"Relleno");
		strcpy(texto[1],"Elija el color de relleno.");
		strcpy(texto[2],"(0: sin relleno)");
	break;
	case 33:
		strcpy(texto[0],"Movimiento Inicial");
		strcpy(texto[1],"Escoja el movimiento");
		strcpy(texto[2],"(0:sin mov. 1:Horiz. 2:Vert.)");
	break;
	case 51:
		strcpy(texto[0],"Cambiar Color Trazado");
		strcpy(texto[1],"Elija entre 0 y 15 para");
		strcpy(texto[2],"color de trazo");
	break;
	case 52:
		strcpy(texto[0],"Cambiar Color Fondo");
		strcpy(texto[1],"Elija entre 0 y 15 para");
		strcpy(texto[2],"color de fondo");
	break;
	}
	InputWindw * escoj = new InputWindw(texto[0],texto[1],texto[2]);
	delete[] texto;
	MostrarPuntero();
	escoj->DrawWindow();
	escoj->RunWindow();
	if (escoj->GetButton() == OK)
	{
		escoj->GetInput(op);
	}
	delete escoj;



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

