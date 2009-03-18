/*
  Nombre: CONTROL.H 
  Copyright: ©2005 Erik Giron, 
  Autor: Erik Giron.(C#200313492)
  Fecha: Febrero, Marzo 2005
  Descripcion: DECLARACION DE LIBRERIAS, CLASES PARA OBJETOS DE
  LA INTERFAZ GRAFICA Y PROTOTIPADO DE FUNCIONES DE USO GENERAL.
*/

#ifndef _CONTROL_H
#define _CONTROL_H
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define YES 2
#define NO 3
#define CANCEL 4
#define OKALT 0x1c0d
#define CANCELALT 0x011b
// DECLARACION VARIABLES


int bandera_control = 0;        	// bandera_control(1: salir,2: seguir)

unsigned ctrlkeys[] =
    {
    0x1e01, 0x3002, 0x2e03, 0x2004, 0x1205, 0x2106,
    0x2207, 0x2308, 0x1709, 0x240a, 0x250b, 0x260c,
    0x320d, 0x310e, 0x180f, 0x1910, 0x1011, 0x1312,
    0x1f13, 0x1414, 0x1615, 0x2f16, 0x1117, 0x2d18,
    0x1519, 0x2c1a
    };
    

// DECLARACION DE FUNCIONES GENERALES


//*********************** FAMILIA DE CLASES WINDW*********************************
// Crea una clase ventana base para clases que se deriven de ella;
class Windw
{
int *buffer; // Puntero a bufer de pantalla.
protected:
    int wx, wy, ww, wh;     // Coordenadas de Window.
    int border,             // Bandera para crear con borde.
    buffered;             // Bandera para asignar bufer.
    EvntMsg evntmsg;         // Mensaje de evento.
public:
    Windw(int x, int y, int w, int h, int bdr, int buf);
    virtual ~Windw(void);                // el destructor borra la ventana
    virtual void DrawWindow(void);       //dibuja la ventana
    void setwx(int x);
    void setww(int x);
    void setwh(int y);
    void setwy(int y);
    virtual void RunWindow(void);      // corre la ventana y espera ...
                                       // ... entrada de teclado o mouse
private:
    void WindwError(char *s);
};
//*************************CLASE CapWindw ********************************
// Crea ventana con titulo.

class CapWindw: public Windw
{
protected:
    char label[61];     // variable que contendra el titulo de la ventana
public:
    CapWindw(int x, int y, int w, int h, int bdr, int buf, char *s);
    //~CapWindw()    {delete[] label;};
    virtual void DrawWindow(void);
    void SetCaption(char *s);        //Cambia el titulo de la ventana
private:
    void DrawCapBar(void);        //dibuja la barra de titulo

};

//***********************CLASE CapTWindw***********************************
// Clase hija de CapWindw que crea y dibuja un cuadro de dialogo 
// en el centro de la pantalla

class CapTWindw: public CapWindw
{
protected:
    char *line1, *line2; // cadenas para las lineas de dialogo
    int button;          // bandera para boton
public:
    CapTWindw(char *s1, char *s2, char *s3);
//    ~CapTWindw()                //debug
//    {if (line1!=NULL && line2!=NULL) delete[] line1,line2;};      //debug
    virtual void DrawWindow(void);
    int GetButton(void) { return button; }
};
//*********************CLASE BUTTON***************************************
//  Crea un boton basico basandose en la clase Windw
class Button: public Windw
{
protected:
    char label[20];     //establece etiqueta del boton
    unsigned hotkey;    //establece tecla de acceso rapido
    int altkey;         //establece teclas predeterminadas para el boton
public:
    Button(int x, int y, char *s);
//   ~Button()
//    {delete []label;};
    virtual void DrawWindow(void);
    virtual int Clicked(EvntMsg evntmsg);
    virtual void ClickButton(void);
};
//*********************CLASE aboton***************************************
//  Crea un boton basico basandose en la clase Windw, con tamano variable
class aboton: public Windw
{
private:
    char label[20];     //establece etiqueta del boton
    unsigned hotkey;    //establece tecla de acceso rapido
//    int altkey;         //establece teclas predeterminadas para el boton

public:
    virtual void DrawWindow(void);
    virtual int Clicked(EvntMsg evntmsg);
    virtual void ClickButton(void);
    aboton (int x, int y,int a, char *s);
    ~aboton()
    {delete [] label;};
};

//*********************CLASE OKWindw******************
// Crea una ventana de aviso
class OKWindw: public CapTWindw
{
    Button *butn;
public:
    OKWindw(char *s1, char *s2, char *s3);
    virtual ~OKWindw(void);
    virtual void DrawWindow(void);
    virtual void RunWindow(void);
};
//*********************CLASE YesNoWindw******************
// Dibuja una ventana de confirmacion
class YesNoWindw: public CapTWindw
{
protected:
    Button *butn1, *butn2;
public:
    YesNoWindw(char *s1, char *s2, char *s3);
    virtual ~YesNoWindw(void);
    virtual void DrawWindow(void);
    virtual void RunWindow(void);
};
//*********************CLASE InputWindw******************
// Dibuja una ventana de entrada de texto
class InputWindw: public CapTWindw
{
    char input[81];
    Button *butn1, *butn2;
public:
    InputWindw(char *s1, char *s2, char *s3);
    virtual ~InputWindw(void);
    void GetInput(char *s) { strcpy(s, input); }
    virtual void DrawWindow(void);
    virtual void RunWindow(void);
private:
    void HandleInput(char k);
};





// *****   DEFINICION FUNCIONES GENERALES ***********


//***	IMPLEMENTACION DE METODOS DE LAS CLASES	*****


// INICIO DEFINICION CLASE BASE WINDW

Windw::Windw(int x, int y, int w, int h, int brd, int buf)
{
    wx = x; wy=y; ww=w; wh=h;
    border=brd;
    buffered = buf;
    buffer = NULL;
}

Windw::~Windw(void)
{
    if (buffer != NULL)
    {
	   OcultarPuntero();
	   putimage(wx, wy, buffer, COPY_PUT);
	   free(buffer);
	   MostrarPuntero();
    }
}

void Windw::setww(int x)
{
    ww = x;
};

void Windw::setwh(int y)
{
    wh=y;
};
void Windw::setwy(int y)
{
    wy = y;
};
void Windw::setwx(int x)
{
    wx = x;
}
void Windw::DrawWindow (void)
{
    int size;
    OcultarPuntero();

    // Guarda area ocupada por la ventana si se le pide
    if (buffered)
    {
        if ((size = imagesize(wx, wy, wx+ww, wy+wh)) < 0)
        WindwError("Imagen muy grande como para guardar");
        else
        {
                if ((buffer = (int *)malloc(size)) == NULL)
				    WindwError("No existe suficiente memoria");
                else 
                        getimage(wx, wy, wx+ww, wy+wh, buffer);
        }
    }
    //Dibuja ventana basica con efecto 3d.
    setcolor(WHITE);
    moveto(wx+ww, wy);
    lineto(wx, wy);
    lineto(wx, wy+wh);
    moveto(wx+ww-1, wy+1);
    lineto(wx+1, wy+1);
    lineto(wx+1, wy+wh-1);
    setcolor(DARKGRAY);
    moveto(wx+1, wy+wh);
    lineto(wx+ww, wy+wh);
    lineto(wx+ww, wy);
    moveto(wx+2, wy+wh-1);
    lineto(wx+ww-1, wy+wh-1);
    lineto(wx+ww-1, wy+1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(wx+2, wy+2, wx+ww-2, wy+wh-2);
    //Dibuja borde si se le pide.
    if (border) 
    {
        setcolor(DARKGRAY);
        moveto(wx+ww-10, wy+10);
        lineto(wx+10, wy+10);
        lineto(wx+10, wy+wh-10);
        setcolor(WHITE);
        lineto(wx+ww-10, wy+wh-10);
        lineto(wx+ww-10, wy+10);
    }
    MostrarPuntero();
}

void Windw::RunWindow(void)
{
    GetEvent(evntmsg);
}

void Windw::WindwError(char *s)
{
    printf("Error: %s\n Presione algo",s);
    getch();
    abort();
}
//  FIN DEFINICION CLASE BASE WINDW
//------------------------------------
//  DEFINICION CLASE CAPWNDW

CapWindw::CapWindw(int x, int y, int w, int h,
                    int brd, int buf, char *s) : Windw(x, y, w, h, brd, buf)
{
    strcpy(label, s);
}

void CapWindw::DrawWindow(void)
{
    // Dibuja ventana base.
    Windw::DrawWindow();
    // Dibuja la barra de titulo.
    DrawCapBar();
}

void CapWindw::DrawCapBar(void)
{
    OcultarPuntero();
    setcolor(WHITE);
//    moveto(wx+20, wy+40);
    moveto(wx+2,wy+22);
    //lineto(wx+20, wy+20);
    lineto(wx+2,wy+2);
    //lineto(wx+ww-20, wy+20);
    lineto(wx+ww-2,wy+2);
    
    setcolor(BLACK);
    //lineto(wx+ww-20, wy+40);
    lineto(wx+ww-2,wy+22);
    //lineto(wx+20, wy+40);
    lineto(wx+2,wy+22);
    
    setfillstyle(SOLID_FILL, BLUE);
//    bar(wx+21, wy+21, wx+ww-21, wy+39);
    bar(wx+3,wy+3,wx+ww-3,wy+21);
    setcolor(WHITE);
    
    int x = (wx+ww/2) - (strlen(label)*4);
    //outtextxy(x, wy+27, label);
    outtextxy(x,wy+9,label);
    MostrarPuntero();
}

void CapWindw::SetCaption(char *s)
{
    strcpy(label, s);
    DrawCapBar();
}
//  FIN DEFINICION CLASE CAPWNDW
//----------------------------------
//  DEFINICION CLASE CAPTWNDW
CapTWindw::CapTWindw(char *s1, char *s2, char *s3) :
            CapWindw(0, 0, 0, 150, 0, 1, s1)
{
// Calcula que cadena es la mas larga y usa ese ancho para
// calcular el ancho de la ventana.
    int w = strlen(s1) * 8 + 60;
    if (strlen(s2) > strlen(s3))
        ww = strlen(s2) * 8 + 60;
    else ww = strlen(s3) * 8 + 60;
        if (w > ww) ww = w;
// Establece un ancho minimo.
    if (ww < 230) ww = 230;
// Calcula las coordenadas x y y de la ventana.
    wx = 320 - ww/2;
    wy = 164;
// Establece el texto de la ventana.
    line1 = s2;
    line2 = s3;
}

void CapTWindw::DrawWindow(void)
{
// dibuja la ventana madre.
    CapWindw::DrawWindow();
// Posiciona y dibuja el texto en la ventana.
    OcultarPuntero();
    int x = (wx+ww/2) - (strlen(line1)*8)/2;
    setcolor(BLACK);
    if (strlen(line2)==0)
        outtextxy(x, wy+68, line1);
    else
    {
        outtextxy(x, wy+56, line1);
        x = (wx+ww/2) - (strlen(line2)*8)/2;
        outtextxy(x, wy+71, line2);
    }
    MostrarPuntero();
}
//  FIN DEFINICION CLASE CAPTWNDW
//----------------------------------
//  DEFINICION CLASE BUTTON

Button::Button(int x, int y, char *s) : Windw(x, y, 64, 32, 0, 0)
{
    strcpy(label, s);
    altkey = 0;
    hotkey = 0;
}

void Button::DrawWindow(void)
{
    int pos = -1;
    char tlabel[20];
    Windw::DrawWindow();
    OcultarPuntero();
// Busca y elimina el caracter ^ y
// establece la tecla de acceso rapido apropiada.
    strcpy(tlabel, label);
    for (int i = 0; i<strlen(tlabel); ++i) // busca caracter
    {
        if (tlabel[i] == '^')
        {
            pos = i;
            hotkey = ctrlkeys[tlabel[i+1]-65];
            //copia los caracteres siguientes a la posicion donde
            //se encontraba ^ sucesivamente
            for (int j=i; j<strlen(tlabel); ++j)
                tlabel[j] = tlabel[j+1];
        }
    }
    if (strcmp(tlabel,"ACEPTAR")==0) 
        altkey = OKALT;
    else if (strcmp(tlabel, "CANCELAR")==0) 
        altkey = CANCELALT;
// Centra y dibuja el texto en el boton.
    int x = (wx+ww/2) - (strlen(tlabel)*4);
    setcolor(BLACK);
    outtextxy(x, wy+12, tlabel);
// Subraya el texto para la tecla de acceso rapido.
    if (pos >= 0)
        line(x+pos*8, wy+20, x+pos*8+6, wy+20);
    MostrarPuntero();
}

int Button::Clicked(EvntMsg evntmsg)
{
    int mx, my;
    int click = 0;
// Chequea si un boton fue seleccionado por mouse.
    if  ((PosHoriGraf() > wx) && (PosHoriGraf() < wx+ww) &&
		(PosVertGraf() > wy) && (PosVertGraf() < wy+wh) &&
		BotonPulsado() != 0)
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

void Button::ClickButton(void)
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
// Dibuja los bordes del boton para que
// para que este aparezca presionado.
    setcolor(DARKGRAY);
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
// hace sonido del boton.
    sound ( 1500 );
    delay ( 20 );
    nosound();
// Redibuja el boton en su estado natural.
    DrawWindow();
    MostrarPuntero();
}
//  FIN DEFINICION CLASE Button
//----------------------------------
//  DEFINICION CLASE aboton

aboton::aboton(int x, int y,int a, char *s) : Windw(x, y, 0, 16, 0, 0)
{
    strcpy(label, s);
    hotkey = 0;
    setww(a);
}

void aboton::DrawWindow(void)
{
    int pos = -1;
    char tlabel[20];
    Windw::DrawWindow();
    OcultarPuntero();
// Busca y elimina el caracter ^ y
// establece la tecla de acceso rapido apropiada.
    strcpy(tlabel, label);
    for (int i = 0; i<strlen(tlabel); ++i) // busca caracter
    {
        if (tlabel[i] == '^')
        {
            pos = i;
            hotkey = ctrlkeys[tlabel[i+1]-65];
            //copia los caracteres siguientes a la posicion donde
            //se encontraba ^ sucesivamente
            for (int j=i; j<strlen(tlabel); ++j)
                tlabel[j] = tlabel[j+1];
        }
    }
/*    if (strcmp(tlabel,"ACEPTAR")==0) 
        altkey = OKALT;
    else if (strcmp(tlabel, "CANCELAR")==0) 
       altkey = CANCELALT;*/
// Centra y dibuja el texto en el boton.
    int x = (wx+ww/2) - (strlen(tlabel)*4);
    setcolor(BLACK);
    outtextxy(x, wy+3, tlabel);
// Subraya el texto para la tecla de acceso rapido.
    if (pos >= 0)
        line(x+pos*8, wy+11, x+pos*8+6, wy+11);
    MostrarPuntero();
}

int aboton::Clicked(EvntMsg evntmsg)
{
    int mx, my;
    int click = 0;
// Chequea si un boton fue seleccionado por mouse.
    if  ((PosHoriGraf() > wx) && (PosHoriGraf() < wx+ww) &&
		(PosVertGraf() > wy) && (PosVertGraf() < wy+wh) &&
		BotonPulsado() != 0)
	{
        ClickButton();
		click = 1;
    }
// Chequea si un boton fue seleccionado por teclado.
    else if (evntmsg.type == KEYBD)
    {
        if ((evntmsg.key == hotkey))// || (evntmsg.key == altkey))
        {
        ClickButton();
        click = 1;
        }
    }
    return click;
}

void aboton::ClickButton(void)
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
// Dibuja los bordes del boton para que
// para que este aparezca presionado.
    setcolor(DARKGRAY);
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
// hace sonido del boton.
    sound ( 50 );
    delay ( 20 );
    nosound();
// Redibuja el boton en su estado natural.
    DrawWindow();
    MostrarPuntero();
}
//  FIN DEFINICION CLASE aboton
//----------------------------------
//  DEFINICION CLASE OKWindw

OKWindw::OKWindw(char *s1, char *s2, char *s3) :
CapTWindw(s1, s2, s3)
{
    butn = NULL;
}

OKWindw::~OKWindw(void)
{
    if (butn != NULL) delete butn;
}

void OKWindw::DrawWindow(void)
{
    CapTWindw::DrawWindow();
    butn = new Button(wx+ww/2-32, wy+wh-42, "^ACEPTAR");
    butn->DrawWindow();
}

void OKWindw::RunWindow(void)
{
    button = 0;
    // Repite hasta que un boton es escojido.
    while (!button)
    {
        GetEvent(evntmsg);
        // Espera por clic en boton.
        if (butn->Clicked(evntmsg))
        button = OK;
        // Espera un evento de teclado.
        else if (evntmsg.type == KEYBD)
        {
        // Convierte codigo de caracter a ASCII,
        // y espera la tecla ESC.
                char k = evntmsg.key & 0x00ff;
                if (k == ESC) button = CANCEL;
        }
    }
}

//  FIN DEFINICION CLASE OKWindw
//----------------------------------
//  DEFINICION CLASE YesNoWindw

YesNoWindw::YesNoWindw(char *s1, char *s2, char *s3) :
            CapTWindw(s1, s2, s3)
{
    butn1 = NULL;
    butn2 = NULL;
}

YesNoWindw::~YesNoWindw(void)
{
    if (butn1 != NULL) delete butn1;
    if (butn2 != NULL) delete butn2;
}

void YesNoWindw::DrawWindow(void)
{                                           
    CapTWindw::DrawWindow();
    butn1 = new Button(wx+ww/2-70, wy+108, "^Si");
    butn1->DrawWindow();
    butn2 = new Button(wx+ww/2+6, wy+108, "^No");
    butn2->DrawWindow();
}

void YesNoWindw::RunWindow(void)
{
    button = 0;
    // Repite hasta que un boton es escojido.
    while (!button)
    {
        GetEvent(evntmsg);
        // Espera por clic en botones.
        if (butn1->Clicked(evntmsg))
        button = YES;
	    else if (butn2->Clicked(evntmsg))
        button = NO;
        // Espera un evento de teclado.
        else if (evntmsg.type == KEYBD)
        {
        // Convierte codigo de caracter a ASCII,
        // y espera la tecla ESC.
                char k = evntmsg.key & 0x00ff;
                if (k == ESC) button = CANCEL;
                // else if (k == CR) button = OK;
        }
    }
}

//  FIN DEFINICION CLASE YesNoWindw
//----------------------------------
//  DEFINICION CLASE InputWindw
InputWindw::InputWindw(char *s1, char *s2, char *s3) :
            CapTWindw(s1, s2, s3)
{
    input[0] = 0;
    butn1 = NULL;
    butn2 = NULL;
}
InputWindw::~InputWindw()
{
    if (butn1!=NULL) delete butn1;
    if (butn2!=NULL) delete butn2;
}

void InputWindw::DrawWindow(void)
{
    CapTWindw::DrawWindow();
    butn1 = new Button(wx+ww/2-70, wy+108, "^ACEPTAR");
    butn1->DrawWindow();
    butn2 = new Button(wx+ww/2+6, wy+108, "^CANCELAR");
    butn2->DrawWindow();
    OcultarPuntero();
    setfillstyle(SOLID_FILL, BLACK);
    bar(wx+15, wy+85, wx+ww-15, wy+99);
    MostrarPuntero();
}

void InputWindw::RunWindow(void)
{
    button = 0;
    while (!button)
    {
        GetEvent(evntmsg);
        if (butn1->Clicked(evntmsg))
                button = OK;
        else if (butn2->Clicked(evntmsg))
                button = CANCEL;
        else if (evntmsg.type == KEYBD)
        {
                char k = evntmsg.key & 0x00ff;
                HandleInput(k);
        }
    }
}

void InputWindw::HandleInput(char k)
{
    int l = strlen(input);
    int w = (ww - 30)/8;
    settextjustify(LEFT_TEXT, TOP_TEXT);
// Chequea que una tecla apropiada fuese presionada
// y si la cadena puede contener otro caracter.
    if ((k>31) && (k<127) && (l<80))
    {
// Agrega un caracter a la cadena.
        input[l+1] = 0; input[l] = k;
// Dibuja la porcion de la cadena que
// quepa dentro del cuadro de entrada.
        setcolor(WHITE);
        if (l < w) outtextxy(wx+15, wy+88, input);
        else
        {
                int i = l - w + 1;
                setfillstyle(SOLID_FILL, BLACK);
                bar(wx+15, wy+85, wx+ww-15, wy+99);
                outtextxy(wx+15, wy+88, &input[i]);
        }
    }
// Chequea un backspace y que la cadena tenga
// algun caracter para borrar.
    else if ((k==BACKSP) && (l>0))
    {
    // Borra el ultimo caracter.
        l -= 1;
        input[l] = 0;
    // Dibuja la porcion de la cadena que
    // cabra dentro del cuadro de entrada.
        setfillstyle(SOLID_FILL, BLACK);
        bar(wx+15, wy+85, wx+ww-15, wy+99);
        setcolor(WHITE);
        if (l < w+1) outtextxy(wx+15, wy+88, input);
        else
        {
             int i = l - w;
             outtextxy(wx+15, wy+88, &input[i]);
        }
    }
}
#endif
