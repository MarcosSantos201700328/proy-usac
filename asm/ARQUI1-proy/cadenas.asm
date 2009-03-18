bits 16
org 100h
%include "macros.mac"
;;--------------------------------------------------------------------------------------
;; DATOS
section .data
helloworld: db "hello world",10,13,'$'
c1: db "Por favor ingrese el numero de ml",10,13,'$'
mililitros: resb 5 ;; se almacenara aqui los mililitros
cantidad: resb 5 ;; se almacenara aqui la cantidad de botellas a llenar

	;; inicio del CODIGO
	;; 		segment code
	
	
;;--------------------------------------------------------------------------------------	
section .text
global _start
_start:
init:
	;mov sp,stacktop; movemos a inicio de stack	
ciclo1:
	mov dx,helloworld
	;;llamamos a escribir
	push dx
	call escribir;	
	;;regresamos del ciclo
	jmp ciclo1;

	;;BEGIN PROCEDURE escribir(uint16 stringptr)
	;;primer parametro es puntero hacia la cadena
escribir:
	enter 0,0
	push dx
	push ax	
	;escribimos	
	escribirstring [bp+4]
	;;devolvemos valores de la pila
	pop ax
	pop dx
	leave
	ret 2
	;;END PROCEDURE
	
exitp: mov ax,0x4c00 
	int 0x21

	
;;--------------------------------------------------------------------------------------	
;;STACK
section .bss
buff: resb 1024
buff2: resb 1024
buff3: resb 1024
stacktop: