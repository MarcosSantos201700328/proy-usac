#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <raton.h>
#include <math.h>

//	DECLARACION DE VARIABLES
int i;
char texto[] = "testing the text";
int drivmouse;
char buf[3];
char mtestrt[4];

//	flags
int tecla, bandera_control = 0;
		// bandera_control
		// 1: salir
		// 2: seguir

//	DECLARACION DE PROTOTIPOS DE
//	FUNCIONES GENERALES
int iniciographics(void);
void mouseinit();
void poligono(int,int,int,int,int);

// DECLARACION DE CLASES
class boton
{
	private:
	// 	Variables de control de coordenadas,bandera
	//	y etiquetas
		int x0,y0,xf,yf,z,bandera;

	public:
	char * etiqueta;
	//	 FUNCIONES MIEMBROS
	boton(){xf=0;yf=0;z=0;bandera=0;};
	//   definicion del constructor de ofico
	//   boton(valor en x, valor en y,
	//	etiqueta, constante para la bandera de control)
	boton(int,int,char *,int);

	//   destructor;
	~boton(){xf=0;yf=0;z=0;};
	//  Metodo para actualizar el boton segun el ciclo principal
	virtual int mostrar();

};


// CLASE COMANDO DERIVADA DE BOTON
class comando : public boton
{
	private:
	int x,y,bandera;
	char * nombre;
	public:

	comando()
		{x=0;y=0;};
//     comando(int,int,char * ,int) : boton(int,int,char * , int);
	~comando();
    //int mostrar();
};

//	CLASE MENU
//	crea menu de comandos
class menu
{
	private:
	int j,x,y;
	char * nombre;


	public:
	comando * comandos;

	menu()
		{j=0;x=0;y=0;};
	~menu();
	crearcomandos(int);
};

//	CLASE BARRAMENU :
//		Crea una barra de menu que contendra los menues
class barramenu
{
	private:
	int i, y;

	public:
	menu * menus;	// Puntero a clase menu para crear vector de
					// de tamano n de menus;

	barramenu();
	~barramenu();
	crearmenus(int);	//crea menus basandose en el parametro dado
};

//***	MAIN		*****
int main(void)
{
	//Inicio de Drivers
	iniciographics();
	mouseinit();
	// Otros postulados...
	//while (getbkcolor() == 0)
	setbkcolor(4);
	arc(100,100,0,360,30);
	bar(0,0,getmaxx(),8);
	bar3d(getmaxx()/3,getmaxy()/3,(getmaxx()/3) + (textwidth(texto)),(getmaxy()/3) + 8,2,1);
	setcolor(1);
	outtextxy(getmaxx()/3,getmaxy()/3,texto);

	// creacion de objetos
	bandera_control=2;
	boton boton1(10,10,"salir",1), boton2(50,50,"seguir",2);
	// CICLO PRINCIPAL DEL PROGRAMA
	do
	{
		switch (bandera_control)
		{
		case 0:
			boton1.mostrar();
			boton2.mostrar();
		break;
		case 1:
		break;
		case 2:
			poligono(300,300,225,225,4);
			printf("presione esc para salir");
			tecla=getch();



			if(tecla==27)
				exit(0);
			else
				printf("%d",bandera_control);
		break;
		default:

			printf("presione esc para salir");
			tecla=getch();

			if(tecla==27)
				exit(0);
			else
				printf("%d",bandera_control);
		break;
		}
	}
	while(bandera_control !=1/*,count < 3/*!kbhit()*/);

closegraph();
return 0;
}

//***	DEFINICION FUNCIONES GENERALES	*****///
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

void mouseinit()
{
	MirarRaton();
	MostrarPuntero();
}





void poligono(int xc,int yc,int xf,int yf,int lados)
{
	long double theta,d,l,angulo,pi;
	int i,x,y,x0,y0;

		 //se establece un numero grande de pi para mayor exactitud en los calculos
	pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446;

		 // angulo de giro para la funcion vectorial
	theta = (2*pi)/(long double)lados;

		// distancia del centro a la orilla
	d = sqrtl(powl((long double)(xf-xc),2) + powl((long double)(yf-yc),2));

		// ley de senos para longitud de lado
	l = (sinl(theta)*d)/(sinl((pi-theta)/2));
	printf("d=%e,theta=%e,l=%e,pi=%f\n",d,theta,l,pi);

	for (i=0;i<lados;i++)
	{
		angulo=(-1)*theta*(i+1);
		if (i==0)
		{
			x0=xf;
			y0=yf;
		}
		else
		{
			x0=x;
			y0=y;
		}
		x=ceill(l*cosl(angulo) + x0);
		y=ceill(l*sinl(angulo) + y0);
		line(x0,y0,x,y);
//		getch();
	}

}







//***	DEFINICION DE METODOS DE LAS CLASES	*****


// INICIO DEFINICION CLASE BOTON

boton::boton(int x, int y, char * cadena,int control)
{
	//settextstyle(1,0,1);
	x0=x;
	y0=y;
	xf = x + textwidth(cadena)+8;
	yf = y+10;
	z=2;
	bandera=control;
	strcpy(etiqueta,cadena);


}

boton::mostrar()
{
	setviewport(x0,y0,xf,yf,0);
	setfillstyle(1,7);
	bar3d(0,0,xf-x0,yf-y0,z,1);
	setcolor(8);
	outtextxy(0,0+1,etiqueta);
	while((PosHoriGraf() > x0) && (PosHoriGraf() < xf) &&
		(PosVertGraf() > y0) && (PosVertGraf() < yf))
	{

		// ESTABLECE LOS LIMITES ESPACIALES PARA CLIC
		// Y CONDICIONA EL CLIC

		if ((PosHoriGraf() > x0) && (PosHoriGraf() < xf) &&
			(PosVertGraf() > y0) && (PosVertGraf() < yf) &&
				BotonPulsado() == 1)
		{
		 //	clearviewport();
		 //	setviewport(x0,y0,xf,yf,0);
			setfillstyle(1,15);
			bar(0,0,xf-x0,yf-y0);
			setcolor(8);
			outtextxy(0,1,etiqueta);
			bandera_control = bandera;
			clearviewport();
		}
		else
		{
		//	clearviewport();
		 //	setviewport(x0,y0,xf,yf,0);
			setfillstyle(1,7);
			bar3d(0,0,xf-x0,yf-y0,z,1);
			setcolor(8);
			outtextxy(0,0+1,etiqueta);
			clearviewport();
		}
	    //	clearviewport();
	}
	return 0;
}
// FIN DEFINICION CLASE BOTON

// DEFINICION CLASE COMANDO;
/*
comando::mostrar()
{
	setviewport(x0,y0,xf,yf,0);
	setfillstyle(1,7);
	bar3d(0,0,xf-x0,yf-y0,z,1);
	setcolor(8);
	outtextxy(0,0+1,etiqueta);
	while((PosHoriGraf() > x0) && (PosHoriGraf() < xf) &&
		(PosVertGraf() > y0) && (PosVertGraf() < yf))
	{
		setviewport(x0,y0,xf,yf,0);
		// ESTABLECE LOS LIMITES ESPACIALES PARA CLIC
		// Y CONDICIONA EL CLIC

		if ((PosHoriGraf() > x0) && (PosHoriGraf() < xf) &&
			(PosVertGraf() > y0) && (PosVertGraf() < yf) &&
				BotonPulsado() == 1)
		{
		 //	clearviewport();
			setviewport(x0,y0,xf,yf,0);
			setfillstyle(1,15);
			bar(0,0,xf-x0,yf-y0);
			setcolor(8);
			outtextxy(0,1,etiqueta);
			bandera_control = bandera;
			clearviewport();
		}
		else
		{
		//	clearviewport();
			setviewport(x0,y0,xf,yf,0);
			setfillstyle(1,7);
			bar3d(0,0,xf-x0,yf-y0,z,1);
			setcolor(8);
			outtextxy(0,0+1,etiqueta);
			clearviewport();
		}
		clearviewport();
	}
	return 0;
}
*/
//	DEFINICION CLASE BARRAMENU;

barramenu::crearmenus(int num)
{
	// establece el espacio para almacenar el vector
	menu * menus = new menu[num];
	return num;
}

menu::crearcomandos(int num)
{
	comando *comandos = new comando[num];
	return num;
}
