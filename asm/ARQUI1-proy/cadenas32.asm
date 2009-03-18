bits 16
%include "macros.mac"
section .data data
;segment data 
helloworld: db "hello world",10,13,24h


section .text ;code
;segment code
	;; inicio del codigo
	;; 		segment code
	;global _start
	global _main
;..start:
_start:
;_main:
	; gdb doesn't like to stop at the entry point address, so
	; we put a nop here for pure convenience
	;;settings
	
	mov ax,data
	mov ds,ax
	mov ax,bss
	mov ss,ax
	mov sp,stacktop ;movemos a inicio de stack
	
	;mov dx,helloworld
init:
	push helloworld
;	call escribir
	escribirchar 'b'
	jmp init;

escribir:;;primer parametro es puntero hacia la cadena
	enter 0,0
	push dx
	push ax	
	;escribimos
	escribirstring [bp+12]	
	;;devolvemos valores de la pila
	pop ax
	pop dx
	leave
	ret
	
	
exitp: mov ax,0x4c00 
	int 0x21

section .bss bss
;segment stack stack
buff: resb 4096
stacktop: