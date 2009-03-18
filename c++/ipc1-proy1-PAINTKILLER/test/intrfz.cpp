#include "control.cpp"
//	DECLARACION DE VARIABLES
int i;
char texto[] = "testing the text";
int drivmouse;
char buf[3];
char mtestrt[4];
//	flags
int tecla;
//   declaracion de objetos

//	DECLARACION DE PROTOTIPOS DE
//	FUNCIONES GENERALES

void mostrargui();
//***	MAIN		*****
int main(void)
{
	//Inicio de Drivers
	iniciographics();
	mouseinit();
	// Otros postulados...
	//while (getbkcolor() == 0)
	setbkcolor(7);
	arc(100,100,0,360,30);
	bar(0,0,getmaxx(),8);
	bar3d(getmaxx()/3,getmaxy()/3,(getmaxx()/3) + (textwidth(texto)),(getmaxy()/3) + 8,2,1);
	setcolor(1);
	outtextxy(getmaxx()/3,getmaxy()/3,texto);

	// creacion de objetos
	bandera_control=0;
//	boton boton1(10,10,"salir",1), boton2(50,50,"seguir",2);

	char * str1;

	comando *cmd1 = new comando;
	cmd1->setxy(50,70);
	cmd1->setatrib("salir s",1);
/*
	menu menu1("testing");
	menu1.setxy(100,0);
	menu1.crearcomandos(3);
	menu1.comandos[0].setatrib("com1",2);
	menu1.comandos[1].setatrib("sas",2);
*/

    Windw wndw1(150, 100, 200, 200, 0, 0);
    wndw1.DrawWindow();
    Windw *wndw2 = new Windw(200, 150, 200, 200, 1, 1);
    wndw2->DrawWindow();
    wndw2->RunWindow();
    delete wndw2;
	// CICLO PRINCIPAL DEL PROGRAMA
	do
	{
		switch (bandera_control)
		{
		case 0:
//						menu1.mostrar();
//			boton1.mostrar();
//			boton2.mostrar();
			cmd1->mostrar();
//debug
//			bandera_control=2;
//			itoa(cmd1.getx0(),str1,10);
//			outtextxy(50,100,str1);
//end debug
		break;
		case 1:
		break;
		case 2:
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
			delete cmd1;
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


//***	DEFINICION FUNCIONES GENERALES	*****/
void mostrargui()       // MUESTRA EL MENU
{
    Windw *menu = new Windw(0,0,getmaxx(),64,0,1);
    menu->DrawWindw;
    Button * prog = new boton(0,0,"^PROGRAMA");
    Button * lin = new boton(64,0,"^LINEAS");
    Button * geom = new boton(128,0,"^GEOMETRICOS");
    Button * spray = new boton(192,0,"^SPRAY");
    Button * color = new boton(256,0,"^COLORES");
    Button * ayuda = new boton(320,0,"^AYUDA");
    prog.DrawWindw;
    lin.DrawWindw;
    geom.DrawWindw;
    spray.DrawWindw;
    color.DrawWindw;
    ayuda.DrawWindw;
}


