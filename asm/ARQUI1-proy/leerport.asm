%include "macros.mac"

	;; inicio del codigo
	;; 		segment code
		section .text

	global _start


_start:
	; gdb doesn't like to stop at the entry point address, so
	; we put a nop here for pure convenience

	mov sp,buff ;movemos a inicio de stack
	writeppic pconf,wcinput 	; setup
escribir:	
	escribirtecla 'n'
;	readppic pa
;	escribirtecla al
;	escribirtecla 'n'
;	escribirtecla 10
;	escribirtecla 13
	jmp escribir
	




exitp: mov ax,0x4c00 
	int 0x21

	;shit:	writeppic pa,00000010b
	;	writeppic pb,00000010b
	;	writeppic pc,00000010b
	;	mov ax,10
	;	jmp shit

	section .stack
buff: resb 64