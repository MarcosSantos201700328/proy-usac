/*incluir dos.h*/

int MirarRaton();
int MostrarPuntero();
int OcultarPuntero();
int PosVertGraf(void);
int PosHoriGraf(void);
int BotonPulsado(void);


/*Est� funci�n retorna 0 si no existe ning�n rat�n
instalado.
Si existe un rat�n retorna el n�mero de los botones
de nuestro rat�n.                                  */

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

/*boton pulsado,Si vale 0 no habr� ning�n bot�n apretado.
 Si vale 1 el bot�n izquierdo estar� apretado y si vale 2
 estar� el bot�n derecho apretado. Si est�n los botones
 izquierdo y derecho apretados el registro BX devolver� el
 valor 3.       */


int BotonPulsado()
{
 asm mov ax, 03h
 asm int 33h
 return _BX;
}
