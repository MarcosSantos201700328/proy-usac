bits 16
org 100h
%include "macros.mac"



section .data


	;; inicio del codigo
	;; 		segment code
global _start

section .text
_start:


	mov sp,buff ;movemos a inicio de stack
	writeppic pconf,wc 	; setup
	mov cx,0
	mov ax,0
	mov bx,0
leer: 
	leertecla;
	cmp al,'0'
	jz es0;
	cmp al,'1'
	jz es1
	cmp al,'2'
	jz es2
	cmp al,'3'
	jz es3
	cmp al,'4'
	jz es4
	cmp al,'5'
	jz es5
	cmp al,'6'
	jz es6
	cmp al,'7'
	jz es7
	cmp al,'8'
	jz es8
	cmp al,'9'
	jz es9
	cmp al,'x'
	jz exitp
	jmp escribirpic;
es0:	mov cl,0;
		mov ch,'0';
	jmp escribirpic;
es1:	mov cl,1;
		mov ch,'1';
	jmp escribirpic;
es2:	mov cl,00000010b;
		mov ch,'2';
	jmp escribirpic;
es3:	mov cl,00000100b;
		mov ch,'3';
	jmp escribirpic;
es4:	mov cl,00001000b;
		mov ch,'4';
	jmp escribirpic;
es5:	mov cl,00010000b;
		mov ch,'5';
	jmp escribirpic;
es6:	mov cl,00100000b;
		mov ch,'6';
	jmp escribirpic;
es7:	mov cl,01000000b;
		mov ch,'7';
	jmp escribirpic;
es8:	mov cl,10000000b;
		mov ch,'8';
	jmp escribirpic;
es9:	mov cl,11111111b;
		mov ch,'9';
	jmp escribirpic;
escribirpic:	
	escribirchar ch
	escribirchar 10
	escribirchar 13
	writeppic pa,cl

	jmp leer
	
exitp: mov ax,0x4c00 
	int 0x21



section .bss
buff: resb 2048
