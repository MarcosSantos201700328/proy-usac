//Copyright (C) 2005  Erik Giron
//
//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software Foundation,
//Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//*********************CLASE Comando******************
// Crea comando de menu
class comando: public Windw
{
private:
    int flag;
    char tec[1];
    char *label;//[20];     //establece etiqueta del boton
    unsigned hotkey;    //establece tecla de acceso rapido
    int altkey;         //establece teclas predeterminadas para el boton
public:
    comando(void):Windw(0, 0, 160, 12, 0, 0)
    {
    flag = 0;hotkey = 0; altkey = 0;
    };
    comando(int x, int y, char *,char *);
    void DrawWindow(void);
    int Clicked(EvntMsg eventmsg);
    void ClickButton(void);
    int over(void);
    void OverButton(void);
    int getflag(void){return flag;};
    void set(int x, int y, char *, char *);
    void setlabel(char *d, char*l)
    {strcpy(label,d);
     strcpy(tec,l);
    };
    
};
//*********************CLASE menu******************
// Crea un menu con comandos
class menu: public Windw
{
private:
    comando * cmd;
    int n;
public:
    menu(int x, int y, int num);        //constructor
    ~menu();
    void setcomando(int,char* , char *);     // establece parametros para cmd[i]
    int getclic(int m)                      // ve el clic del elemento m
    {return cmd[1].Clicked(evntmsg);};
    void DrawWindow(void);                //dibuja la ventana
    
};

// ********************CLASE BOTON***************************************
/*class boton : public comando
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
	virtual dibujar(int);

};*/


// DEFINICION CLASE COMANDO;

comando::comando(int x, int y, char *s, char * ky) 
                : Windw(x, y, 160, 12, 0, 0)
{
    strcpy(label, s);
    altkey = 0;
    hotkey = 0;
    //printf(s);
    //printf(label);//debug
        
    flag = 0;
    strcpy( tec , ky );
}
void comando::set(int x,int y,char *s,char * ky)
{
    strcpy(label, s);
    altkey = 0;
    hotkey = 0;
    //printf(s);
    //printf(label);//debug
    setwx(x);
    setwy(y);
    flag = 0;
    strcpy( tec , ky );
}
void comando::DrawWindow(void)
{
    //int pos = -1;
    char * ctltext;
    strcpy(ctltext,"Ctrl + ") ;
    strcat(ctltext,tec);
    
    Windw::DrawWindow();
    OcultarPuntero();
    setfillstyle(SOLID_FILL, BLUE);
    bar(wx, wy, wx+ww, wy+wh);
// establece la tecla de acceso rapido apropiada.
    // !!!CHECK!!!
    printf("%c",tec[0]);//debug
    hotkey = ctrlkeys[tec[0]/*-65*/];

// alinea y dibuja el texto en el boton.
    int x = wx; //+ 4;
//alinea y dibuja el texto de la tecla de acceso rapido
    int xf = wx+ww - 64;
    setcolor(WHITE);
    outtextxy(x, wy+3, label);
    outtextxy(xf, wy+3, ctltext);
// Subraya el texto para la tecla de acceso rapido.
/*    if (pos >= 0)
        line(x+pos*8, wy+20, x+pos*8+6, wy+20);*/
    MostrarPuntero();
}
int comando::over(void)
{
    //int mx, my;
    int o=0;
    if  ((PosHoriGraf() > wx) && (PosHoriGraf() < wx+ww) &&
	(PosVertGraf() > wy) && (PosVertGraf() < wy+wh))
	{
        OverButton();
		o = 1;
    }
    else
    {
        DrawWindow();
        o = 0;
    }
    return o;
}

void comando::OverButton(void)
{
    int *buff;
    OcultarPuntero();
// Invierte la imagen el el boton hacia abajo y derecha
// para simular movimiento del boton.
    int size = imagesize(wx+2, wy+2, wx+ww-2, wy+wh-2);
    buff = (int *)malloc(size);
    if (buff)
    {
        getimage(wx+2, wy+2, wx+ww-2, wy+wh-2, buff);
        putimage(wx+3, wy+3, buff, COPY_PUT);
        free(buff);
    }

    setfillstyle(SOLID_FILL, RED);
    //bar(wx, wy, wx+ww, wy+wh);
// Dibuja los bordes del boton para que
// para que este aparezca presionado.
/*    setcolor(DARKGRAY);
    moveto(wx+ww, wy);
    lineto(wx, wy); lineto(wx, wy+wh);
    moveto(wx+ww-1, wy+1);
    lineto(wx+1, wy+1); lineto(wx+1, wy+wh-1);
    setcolor(WHITE);
    moveto(wx+1, wy+wh);
    lineto(wx+ww, wy+wh); lineto(wx+ww, wy);
    moveto(wx+2, wy+wh-1);
    lineto(wx+ww-1, wy+wh-1);
    lineto(wx+ww-1, wy+1);
*/
// Redibuja el boton en su estado natural.
   // DrawWindow();
    MostrarPuntero();
}
int comando::Clicked(EvntMsg evntmsg)
{
    int mx, my;
    int click = 0;
// Chequea si un boton fue seleccionado por mouse.
    if  ((PosHoriGraf() > wx) && (PosHoriGraf() < wx+ww) &&
		(PosVertGraf() > wy) && (PosVertGraf() < wy+wh) &&
		(BotonPulsado() != 0))
	{
        ClickButton();
		click = 1;
    }
    
// Chequea si un boton fue seleccionado por teclado.
    else if (evntmsg.type == KEYBD)
    {
        if ((evntmsg.key == hotkey) || (evntmsg.key == altkey))
        {
        ClickButton();
        click = 1;
        }
    }
    return click;
}

void comando::ClickButton(void)
{

    OcultarPuntero();
    int *buff;
// Invierte la imagen el el boton hacia abajo y derecha
// para simular movimiento del boton.
    int size = imagesize(wx+2, wy+2, wx+ww-2, wy+wh-2);
    buff = (int *)malloc(size);
    if (buff)
    {
        getimage(wx+2, wy+2, wx+ww-2, wy+wh-2, buff);
        putimage(wx+3, wy+3, buff, COPY_PUT);
        free(buff);
    }

    setfillstyle(SOLID_FILL, RED);
    //bar(wx, wy, wx+ww, wy+wh);
// Dibuja los bordes del boton para que
// para que este aparezca presionado.
/*    setcolor(DARKGRAY);
    moveto(wx+ww, wy);
    lineto(wx, wy); lineto(wx, wy+wh);
    moveto(wx+ww-1, wy+1);
    lineto(wx+1, wy+1); lineto(wx+1, wy+wh-1);
    setcolor(WHITE);
    moveto(wx+1, wy+wh);
    lineto(wx+ww, wy+wh); lineto(wx+ww, wy);
    moveto(wx+2, wy+wh-1);
    lineto(wx+ww-1, wy+wh-1);
    lineto(wx+ww-1, wy+1);
*/
// Redibuja el boton en su estado natural.
    DrawWindow();
    MostrarPuntero();
}
/*
comando::mostrar()
{
		// ESTABLECE LOS LIMITES ESPACIALES PARA CLIC
		// Y CONDICIONA EL CLIC
	// ENCIMA
	if ((PosHoriGraf() > x0) && (PosHoriGraf() < xf) &&
		(PosVertGraf() > y0) && (PosVertGraf() < yf) &&
			BotonPulsado() == 0)
	{
		 OcultarPuntero();
		 dibujar(1);
		 MostrarPuntero();
	}
	// ENCIMA HACIENDO CLIC
	else if ((PosHoriGraf() > x0) && (PosHoriGraf() < xf) &&
		(PosVertGraf() > y0) && (PosVertGraf() < yf) &&
			BotonPulsado() != 0)
	{
		dibujar(2);
	}
	// AFUERA
	else
	{
		dibujar(0);
	}
return 0;
}
*/
//  FIN DEFINICION CLASE COMANDO
//-------------------------------------
//  DEFINICION CLASE MENU
menu::menu(int x, int y, int num)
        : Windw(x,y,0,204,0,1)
{
    cmd = new comando[num];
    n = num;
}

void menu::setcomando(int m, char* p, char* q)
{
 //   for (int i =0; i < num, i++)
    
    cmd[m].setlabel(p,q);
}

void menu::DrawWindow(void)
{
    setwh((n*8)+4);
    Windw::DrawWindow();
    for (int i =0; i < n; i++)
    {
        cmd[i].setwx(wx);
        cmd[i].setwy(wy + (32*i));
        cmd[i].DrawWindow();
    }
    
}
menu::~menu()
{
    delete[] cmd;
    Windw::~Windw();
}
//  FIN DEFINICION CLASE MENU
//-------------------------------------
