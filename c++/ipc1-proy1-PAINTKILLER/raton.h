/*incluir dos.h*/

int MirarRaton();
int MostrarPuntero();
int OcultarPuntero();
int PosVertGraf(void);
int PosHoriGraf(void);
int BotonPulsado(void);


/*Está función retorna 0 si no existe ningún ratón
instalado.
Si existe un ratón retorna el número de los botones
de nuestro ratón.                                  */

int MirarRaton()
{
  asm xor ax, ax
  asm int 33h
  asm cmp ax, -1
  asm je  ExisteRaton
  return 0;

ExisteRaton:
return _BX;

}

/*Mostrar raton*/
int MostrarPuntero()
{
  asm mov ax, 01h
  asm int 33h
  return 0;
}


/*Ocultar raton*/
int OcultarPuntero()
                                     {

asm mov ax, 02h
asm int 33h
return 0;
}

/*posicion*/

int PosVertGraf()
{
asm mov ax, 03h
asm int 33h
return _DX;
}
int PosHoriGraf()
 {
 asm mov ax,03h
 asm int 33h
 return _CX;
 }

/*boton pulsado,Si vale 0 no habrá ningún botón apretado.
 Si vale 1 el botón izquierdo estará apretado y si vale 2
 estará el botón derecho apretado. Si están los botones
 izquierdo y derecho apretados el registro BX devolverá el
 valor 3.       */


int BotonPulsado()
{
 asm mov ax, 03h
 asm int 33h
 return _BX;
}
