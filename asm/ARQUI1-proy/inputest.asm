bits 16
org 100h
%include "macros.mac"

;;--------------------------------------------------------------------------------------
;; DATOS
section .data

	;; inicio del CODIGO
	;; 		segment code	
;;--------------------------------------------------------------------------------------	
section .text
global _start
_start:
init:
	writeppic pconf,aout_bin_cin
ciclo:	
	readppic pc		
	mov cl,al
	push ax
	escribirchar cl
	escribirchar 'b'
	pop ax
	writeppic pa,cl
	jmp ciclo;


;;STACK
section .bss
buff: resb 1024
buff2: resb 1024
buff3: resb 1024
stacktop: