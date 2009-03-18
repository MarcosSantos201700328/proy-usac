bits 16
	;; macros para los puertos
%define pa 0x200
%define pb 0x201
%define pc 0x202
%define pconf 0x203
	;; byte de control del ppic
%define wc 0x91	

	;; macro para escribir en puerto especificado por el primer parametro y con el dato del segundo parametro 
%macro writeppic 2		; macro para escribir en ppic
	mov dx,%1
	mov ax,%2
	out dx,ax		; escribe en puerto	
%endmacro

	;; macro para leer desde el puerto del param 1 al registro ax
%macro readppic 1
	mov dx,%1
	in ax,dx
%endmacro	
	;lee tecla desde consola
%macro leertecla 0 
	mov ah,06
	mov dl,0xff
	int 0x21
%endmacro
	;escribe caracter a consola
%macro escribirtecla 1
	mov ah,06
	mov dl,%1
	int 0x21
%endmacro
	; macro para terminar ejecucion
%macro salirprograma 0
	mov ax,0x4c00 
	int 0x21
%endmacro


	;; inicio del codigo
	;; 		segment code
section .text

	global _start
_start:
	; gdb doesn't like to stop at the entry point address, so
	; we put a nop here for pure convenience

	mov sp,buff ;movemos a inicio de stack	
	writeppic pconf,wc 	; setup
poff:	
	;-writeppic pb,0h		; apagamos bombas
	escribirtecla 'a' ;-;

checkb:	
	escribirtecla 'b'
	
	;-readppic pc
	;-cmp al,1000b		; si el boton de emergencia esta presionado
	leertecla ;-;
	cmp al,'b' ;-;
	jnz poff		; encendemos motor;
	

bon:
	escribirtecla 'c'	
	;-writeppic pb,1100b	; encendemos bomba y led principal

checkL1:
	escribirtecla 'd'
	;-readppic pa		; Leemos del puerto a.
	;-cmp al,00000001b	; Si hay nivel 1 de agua continuamos 
	leertecla ;-;
	cmp al,'1' ;-;
	jz aon
	jnz checkE		; sino checkeamos el boton de emergencia.


aon:
	escribirtecla 'f'	
	;-writeppic pb,1111b	; Encendemos bomba de llenado en puerto b.

checkL8:
	escribirtecla 'g'
	;-readppic pa		; Leemos del puerto a.
	;-cmp al,11111111b	; Si el agua esta en nivel 8 apagamos motor
	leertecla ;-;
	cmp al,'8' ;-;
	jnz checkE		; de llenado, sino checkeamos emergencia.

aoff:
	escribirtecla 'h'	
	;-writeppic pb,1100b	; Apagamos motor de llenado.
	jmp checkL1		; Regresamos a ver si hay nivel 1 de agua.

checkE:
	escribirtecla 'i'
	;-readppic pc		; Leemos puerto c.
	;-and al,0100b	; filtramos bit del boton
	;-cmp al,0100b	; comparamos si esta presionado
	leertecla ;-;
	cmp al,'e' ;-;
	jz poff			; saltamos si se presiono boton

;;	cmp al,0100b		; Si boton de emergencia esta presionado;
;;	jz poff			; apagamos bombas y regresamos al ciclo
;;	cmp al,1100b		; Sino,...
;;	jz poff	
	jmp checkL1		; ... volvemos a revisar nivel 1 de agua

exitp: 
	escribirtecla 'j'
	salirprograma ; nos salimos de la ejecucion
segment bss
buff:	resb 64
	
	
	
	

	
		
