	.file "proy1.pas"
	.stabs "d:/progra/pascal/proy1_lfp/",100,0,0,.Ltext0
	.stabs "proy1.pas",100,0,0,.Ltext0
.Ltext0:
	.stabd	72,0,1

.section .text
# [proy1.pas]
fpc_compiled:
gcc2_compiled:
	.stabd	68,0,727
# [727] begin
.globl	DEBUGINFO_P$STATIC
DEBUGINFO_P$STATIC:
# Begin unit SYSTEM has index 1
	.stabs "LONGINT:t30=r30;-2147483648;2147483647;",128,0,0,0
	.stabs "DOUBLE:t11=r30;8;0;",128,0,0,0
	.stabs "CHAR:t28=-20;",128,0,0,0
	.stabs "BYTE:t5=r5;0;255;",128,0,0,0
	.stabs "SHORTSTRING:Tt1=s256length:5,0,8;st:ar5;1;255;28,8,2040;;",128,0,0,0
	.stabs "BOOLEAN:t32=-21;",128,0,0,0
	.stabs "WORD:t29=r29;0;65535;",128,0,0,0
	.stabs "SMALLINT:t21=r21;-32768;32767;",128,0,0,0
	.stabs "TEXT:Tt2=s592HANDLE:30,0,32;MODE:30,32,32;RECSIZE:30,64,32;_PRIVATE:ar30;1;32;28,96,256;USERDATA:ar30;1;16;5,352,128;NAME:ar30;0;255;28,480,2048;;",128,0,0,0
	.stabs "void:t8=8",128,0,0,0
# End unit SYSTEM has index 1
# Begin unit OBJPAS has index 6
# End unit OBJPAS has index 6
# Begin unit WINDOWS has index 5
# End unit WINDOWS has index 5
# Begin unit CRT has index 2
# End unit CRT has index 2
# Begin unit STRINGS has index 9
# End unit STRINGS has index 9
# Begin unit DOS has index 8
# End unit DOS has index 8
# Begin unit SYSCONST has index 10
# End unit SYSCONST has index 10
# Begin unit SYSUTILS has index 7
# End unit SYSUTILS has index 7
# Begin unit STRUTILS has index 3
# End unit STRUTILS has index 3
# Begin unit MATH has index 4
# End unit MATH has index 4
# Begin unit STATIC has index 0
	.stabs "ARRDATA:t3=ar5;1;255;21",128,0,0,0
	.stabs "READATA:t4=ar5;1;255;11",128,0,0,0
	.stabs "TABLA:t34=ar5;1;255;4",128,0,0,0
	.stabs "SHORTINT:t39=r39;-128;127;",128,0,0,0
	.stabs "BOOLARR:t6=ar39;1;7;32",128,0,0,0
# End unit STATIC has index 0

.section .text

.section .text
	.balign 4
	.balign 4
	.stabs "FRECUENCIA:F8",36,0,51,P$STATIC_FRECUENCIA
	.stabs "I:5",160,0,53,-4
	.stabs "J:5",160,0,53,-8
.Ll1:
	.stabn 68,0,54,.Ll1 - P$STATIC_FRECUENCIA
# [54] begin
.globl	P$STATIC_FRECUENCIA
P$STATIC_FRECUENCIA:
# Temps allocated between ebp-20 and ebp-8
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$20,%esp
# Temp -4,4 allocated
# Var i located at ebp-4
# Temp -8,4 allocated
# Var j located at ebp-8
	# Register %eax allocated
	movl	$20,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
# Temp -12,4 allocated
	# Register %al allocated
.Ll2:
	.stabn 68,0,55,.Ll2 - P$STATIC_FRECUENCIA
# [55] for i:=1 to numdatos do
	movb	U_P$STATIC_NUMDATOS,%al
	# Register %al released
	movb	%al,-12(%ebp)
	movb	$1,-4(%ebp)
	# Register %al allocated
	movb	-4(%ebp),%al
	# Register %al released
	cmpb	-12(%ebp),%al
	ja	.L10
	subb	$1,-4(%ebp)
	.balign 4
.L11:
	addb	$1,-4(%ebp)
# Temp -16,4 allocated
	# Register %al allocated
.Ll3:
	.stabn 68,0,56,.Ll3 - P$STATIC_FRECUENCIA
# [56] for j:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-16(%ebp)
	movb	$1,-8(%ebp)
	# Register %al allocated
	movb	-8(%ebp),%al
	# Register %al released
	cmpb	-16(%ebp),%al
	ja	.L13
	subb	$1,-8(%ebp)
	.balign 4
.L14:
	addb	$1,-8(%ebp)
	# Register %edx allocated
.Ll4:
	.stabn 68,0,57,.Ll4 - P$STATIC_FRECUENCIA
# [57] if (datos[i] >= intervI[j]) and (datos[i] < intervD[j]) then
	movzbl	-4(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L18
	call	FPC_RANGEERROR
.L18:
	# Register %edx released
	fldl	U_P$STATIC_DATOS-8(,%edx,8)
	# Register %edx allocated
	movzbl	-8(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L19
	call	FPC_RANGEERROR
.L19:
# Temp -20,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVI-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-20(%ebp)
	fildl	-20(%ebp)
# Temp -20,4 released
	fcompp
	# Register %ax allocated
	fnstsw	%ax
	sahf
	# Register %ax released
	jbe	.L17
	jmp	.L16
.L17:
	# Register %edx allocated
	movzbl	-4(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L20
	call	FPC_RANGEERROR
.L20:
	# Register %edx released
	fldl	U_P$STATIC_DATOS-8(,%edx,8)
	# Register %edx allocated
	movzbl	-8(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L21
	call	FPC_RANGEERROR
.L21:
# Temp -20,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVD-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-20(%ebp)
	fildl	-20(%ebp)
# Temp -20,4 released
	fcompp
	# Register %ax allocated
	fnstsw	%ax
	sahf
	# Register %ax released
	ja	.L15
	jmp	.L16
.L15:
	# Register %edx allocated
.Ll5:
	.stabn 68,0,58,.Ll5 - P$STATIC_FRECUENCIA
# [58] frec[j]:=frec[j]+1;
	movzbl	-8(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L24
	call	FPC_RANGEERROR
.L24:
	movswl	U_P$STATIC_FREC-2(,%edx,2),%edx
	addl	$1,%edx
	jno	.L25
	call	FPC_OVERFLOW
.L25:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$-32768,%eax
	# Register %eax released
	cmpl	$65535,%eax
	jbe	.L26
	call	FPC_RANGEERROR
.L26:
	# Register %edx released
	# Register %dx,%ecx allocated
	movzbl	-8(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L27
	call	FPC_RANGEERROR
.L27:
	# Register %dx,%ecx released
	movw	%dx,U_P$STATIC_FREC-2(,%ecx,2)
.L16:
	# Register %al allocated
.Ll6:
	.stabn 68,0,56,.Ll6 - P$STATIC_FRECUENCIA
	movb	-8(%ebp),%al
	# Register %al released
	cmpb	-16(%ebp),%al
	jb	.L14
# Temp -16,4 released
.L13:
	# Register %al allocated
.Ll7:
	.stabn 68,0,55,.Ll7 - P$STATIC_FRECUENCIA
	movb	-4(%ebp),%al
	# Register %al released
	cmpb	-12(%ebp),%al
	jb	.L11
# Temp -12,4 released
.L10:
# Temp -4,4 released
# Temp -8,4 released
.Ll8:
	.stabn 68,0,59,.Ll8 - P$STATIC_FRECUENCIA
# [59] end; { Frecuencia }
	leave
	# Register %ebp released
	ret
.L33:
	.stabn 192,0,0,P$STATIC_FRECUENCIA-P$STATIC_FRECUENCIA
	.stabn 224,0,0,.L33-P$STATIC_FRECUENCIA

.section .text
	.balign 4
	.balign 4
	.stabs "PUNTOMEDIO:F4",36,0,67,P$STATIC_PUNTOMEDIO$$READATA
	.stabs "result:v4",160,0,67,-4
	.stabs "I:5",160,0,69,-8
	.stabs "PM:4",160,0,70,-2048
.Ll9:
	.stabn 68,0,71,.Ll9 - P$STATIC_PUNTOMEDIO$$READATA
# [71] begin
.globl	P$STATIC_PUNTOMEDIO$$READATA
P$STATIC_PUNTOMEDIO$$READATA:
# Temps allocated between ebp-2064 and ebp-2048
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$2064,%esp
# Temp -2064,8 allocated
	movl	%esi,-2064(%ebp)
	movl	%edi,-2060(%ebp)
# Temp -4,4 allocated
# Var $result located at ebp-4
# Temp -8,4 allocated
# Var i located at ebp-8
# Temp -2048,2040 allocated
# Var PM located at ebp-2048
	# Register %eax allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %eax allocated
	movl	$2064,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
# Temp -2052,4 allocated
	# Register %al allocated
.Ll10:
	.stabn 68,0,72,.Ll10 - P$STATIC_PUNTOMEDIO$$READATA
# [72] for i:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-2052(%ebp)
	movb	$1,-8(%ebp)
	# Register %al allocated
	movb	-8(%ebp),%al
	# Register %al released
	cmpb	-2052(%ebp),%al
	ja	.L37
	subb	$1,-8(%ebp)
	.balign 4
.L38:
	addb	$1,-8(%ebp)
	# Register %edx allocated
.Ll11:
	.stabn 68,0,73,.Ll11 - P$STATIC_PUNTOMEDIO$$READATA
# [73] PM[i]:=(intervI[i] + intervD[i])/2;
	movzbl	-8(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L41
	call	FPC_RANGEERROR
.L41:
	# Register %edx released
	# Register %ecx allocated
	movswl	U_P$STATIC_INTERVI-2(,%edx,2),%ecx
	# Register %edx allocated
	movzbl	-8(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L42
	call	FPC_RANGEERROR
.L42:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVD-2(,%edx,2),%eax
	# Register %ecx released
	addl	%ecx,%eax
	jno	.L43
	call	FPC_OVERFLOW
.L43:
# Temp -2056,4 allocated
	# Register %eax released
	movl	%eax,-2056(%ebp)
	fildl	-2056(%ebp)
# Temp -2056,4 released
	fldt	_$PROGRAM$_L44
	fdivrp	%st,%st(1)
	# Register %edx allocated
	movzbl	-8(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L45
	call	FPC_RANGEERROR
.L45:
	# Register %edx released
	fstpl	-2056(%ebp,%edx,8)
	fwait
	# Register %al allocated
.Ll12:
	.stabn 68,0,72,.Ll12 - P$STATIC_PUNTOMEDIO$$READATA
	movb	-8(%ebp),%al
	# Register %al released
	cmpb	-2052(%ebp),%al
	jb	.L38
# Temp -2052,4 released
.L37:
	# Register %edi allocated
.Ll13:
	.stabn 68,0,74,.Ll13 - P$STATIC_PUNTOMEDIO$$READATA
# [74] PuntoMedio:=PM;
	movl	-4(%ebp),%edi
	# Register %esi allocated
	leal	-2048(%ebp),%esi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -8,4 released
# Temp -2048,2040 released
# Temp -4,4 released
	# Register %esi allocated
.Ll14:
	.stabn 68,0,75,.Ll14 - P$STATIC_PUNTOMEDIO$$READATA
# [75] end; { PuntoMedio }
	movl	-2064(%ebp),%esi
	# Register %edi allocated
	movl	-2060(%ebp),%edi
# Temp -2064,8 released
	leave
	# Register %ebp released
	ret
.L53:
	.stabs "PUNTOMEDIO:X*4",160,0,0,-4
	.stabn 192,0,0,P$STATIC_PUNTOMEDIO$$READATA-P$STATIC_PUNTOMEDIO$$READATA
	.stabn 224,0,0,.L53-P$STATIC_PUNTOMEDIO$$READATA

.section .text
	.balign 4
	.balign 4
	.stabs "MEDIASUPUESTA:F11",36,0,82,P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE
	.stabs "PM:p4",160,0,82,-2052
	.stabs "result:11",160,0,82,-12
.Ll15:
	.stabn 68,0,85,.Ll15 - P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE
# [85] begin
.globl	P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE
P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE:
# Temps allocated between ebp-2060 and ebp-12
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$2060,%esp
# Temp -2060,8 allocated
	movl	%esi,-2060(%ebp)
	movl	%edi,-2056(%ebp)
# Temp -4,4 allocated
# Var PM located at ebp-4
# Temp -12,8 allocated
# Var $result located at ebp-12
	# Register %eax allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -2052,2040 allocated
	# Register %edi allocated
	leal	-2052(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$2060,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
# Temp -4,4 allocated
	# Register %eax allocated
.Ll16:
	.stabn 68,0,87,.Ll16 - P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE
# [87] MediaSupuesta:= PM[round(NumInterv/2 +  0.001)]
	movzbl	U_P$STATIC_NUMINTERV,%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
	fldt	_$PROGRAM$_L44
	fdivrp	%st,%st(1)
	fldt	_$PROGRAM$_L60
	faddp	%st,%st(1)
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax,%ecx,%edx allocated
	call	fpc_round_real
	# Register %ecx released
	testl	%edx,%edx
	je	.L61
	# Register %edx released
	cmpl	$-1,%edx
	je	.L62
	call	FPC_RANGEERROR
.L61:
	# Register %edx allocated
	movl	%eax,%edx
	# Register %edx released
	cmpl	$2147483647,%edx
	jbe	.L63
	call	FPC_RANGEERROR
.L63:
	jmp	.L64
.L62:
	testl	%eax,%eax
	jl	.L65
	call	FPC_RANGEERROR
.L65:
.L64:
	# Register %edx allocated
	movl	%eax,%edx
	subl	$1,%edx
	# Register %edx released
	cmpl	$254,%edx
	jbe	.L66
	call	FPC_RANGEERROR
.L66:
	# Register %edx allocated
	movl	-2060(%ebp,%eax,8),%edx
	# Register %edx released
	movl	%edx,-12(%ebp)
	movl	-2056(%ebp,%eax,8),%eax
	# Register %eax released
	movl	%eax,-8(%ebp)
.Ll17:
	.stabn 68,0,88,.Ll17 - P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE
# [88] end;
	fldl	-12(%ebp)
# Temp -12,8 released
# Temp -2052,2040 released
	# Register %esi allocated
	movl	-2060(%ebp),%esi
	# Register %edi allocated
	movl	-2056(%ebp),%edi
# Temp -2060,8 released
	leave
	# Register %ebp released
	ret
.L72:
	.stabs "MEDIASUPUESTA:X11",160,0,0,-12
	.stabn 192,0,0,P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE-P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE
	.stabn 224,0,0,.L72-P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "DESVRESPA:F4",36,0,95,P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
	.stabs "PM:p4",160,0,95,-4092
	.stabs "A:p11",160,0,95,8
	.stabs "result:v4",160,0,95,-8
	.stabs "DESV:4",160,0,97,-2048
	.stabs "I:5",160,0,98,-2052
.Ll18:
	.stabn 68,0,99,.Ll18 - P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
# [99] begin
.globl	P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA:
# Temps allocated between ebp-4100 and ebp-2052
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$4096,%esp
	movl	$0,4(%esp)
	pushl	%eax
# Temp -4100,8 allocated
	movl	%esi,-4100(%ebp)
	movl	%edi,-4096(%ebp)
# Temp -4,4 allocated
# Var PM located at ebp-4
# Var A located at ebp+8
# Temp -8,4 allocated
# Var $result located at ebp-8
# Temp -2048,2040 allocated
# Var Desv located at ebp-2048
# Temp -2052,4 allocated
# Var i located at ebp-2052
	# Register %eax,%edx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -4092,2040 allocated
	# Register %edi allocated
	leal	-4092(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$4100,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
# Temp -4,4 allocated
	# Register %al allocated
.Ll19:
	.stabn 68,0,100,.Ll19 - P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
# [100] for i:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-4(%ebp)
	movb	$1,-2052(%ebp)
	# Register %al allocated
	movb	-2052(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	ja	.L76
	subb	$1,-2052(%ebp)
	.balign 4
.L77:
	addb	$1,-2052(%ebp)
	# Register %edx allocated
.Ll20:
	.stabn 68,0,101,.Ll20 - P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
# [101] desv[i] := PM[i] - A;
	movzbl	-2052(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L80
	call	FPC_RANGEERROR
.L80:
	fldl	8(%ebp)
	# Register %edx released
	fldl	-4100(%ebp,%edx,8)
	fsubp	%st,%st(1)
	# Register %edx allocated
	movzbl	-2052(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L81
	call	FPC_RANGEERROR
.L81:
	# Register %edx released
	fstpl	-2056(%ebp,%edx,8)
	fwait
	# Register %al allocated
.Ll21:
	.stabn 68,0,100,.Ll21 - P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
	movb	-2052(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	jb	.L77
# Temp -4,4 released
.L76:
	# Register %edi allocated
.Ll22:
	.stabn 68,0,102,.Ll22 - P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
# [102] DesvRespA:=desv;
	movl	-8(%ebp),%edi
	# Register %esi allocated
	leal	-2048(%ebp),%esi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -2048,2040 released
# Temp -2052,4 released
# Temp -4092,2040 released
# Temp -8,4 released
	# Register %esi allocated
.Ll23:
	.stabn 68,0,103,.Ll23 - P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
# [103] end; { DesvRespA }
	movl	-4100(%ebp),%esi
	# Register %edi allocated
	movl	-4096(%ebp),%edi
# Temp -4100,8 released
	leave
	# Register %ebp released
	ret	$8
.L89:
	.stabs "DESVRESPA:X*4",160,0,0,-8
	.stabn 192,0,0,P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA-P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
	.stabn 224,0,0,.L89-P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA

.section .text
	.balign 4
	.balign 4
	.stabs "TOTALDESV:F8",36,0,112,P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
	.stabs "DRA:p4",160,0,112,-2064
	.stabs "TD:v4",160,0,112,-8
	.stabs "TOTAL:v11",160,0,112,-12
	.stabs "I:5",160,0,114,-16
	.stabs "SUM:11",160,0,115,-24
.Ll24:
	.stabn 68,0,116,.Ll24 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
# [116] begin
.globl	P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
P$STATIC_TOTALDESV$READATA$READATA$DOUBLE:
# Temps allocated between ebp-2076 and ebp-24
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$2076,%esp
# Temp -2076,8 allocated
	movl	%esi,-2076(%ebp)
	movl	%edi,-2072(%ebp)
# Temp -4,4 allocated
# Var DRA located at ebp-4
# Temp -8,4 allocated
# Var TD located at ebp-8
# Temp -12,4 allocated
# Var total located at ebp-12
# Temp -16,4 allocated
# Var i located at ebp-16
# Temp -24,8 allocated
# Var sum located at ebp-24
	# Register %eax,%edx,%ecx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %ecx released
	movl	%ecx,-12(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -2064,2040 allocated
	# Register %edi allocated
	leal	-2064(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$2076,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll25:
	.stabn 68,0,117,.Ll25 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
# [117] sum :=0;
	fldz
	fstpl	-24(%ebp)
	fwait
# Temp -4,4 allocated
	# Register %al allocated
.Ll26:
	.stabn 68,0,118,.Ll26 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
# [118] for i:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-4(%ebp)
	movb	$1,-16(%ebp)
	# Register %al allocated
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	ja	.L95
	subb	$1,-16(%ebp)
	.balign 4
.L96:
	addb	$1,-16(%ebp)
	# Register %edx allocated
.Ll27:
	.stabn 68,0,120,.Ll27 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
# [120] TD[i]:=frec[i]*DRA[i];
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L99
	call	FPC_RANGEERROR
.L99:
# Temp -2068,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-2068(%ebp)
	fildl	-2068(%ebp)
# Temp -2068,4 released
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L100
	call	FPC_RANGEERROR
.L100:
	# Register %edx released
	fldl	-2072(%ebp,%edx,8)
	fmulp	%st,%st(1)
	# Register %ecx allocated
	movl	-8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L101
	call	FPC_RANGEERROR
.L101:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %ecx allocated
.Ll28:
	.stabn 68,0,121,.Ll28 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
# [121] sum := sum + td[i];
	movl	-8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L104
	call	FPC_RANGEERROR
.L104:
	fldl	-24(%ebp)
	# Register %ecx,%edx released
	fldl	-8(%ecx,%edx,8)
	faddp	%st,%st(1)
	fstpl	-24(%ebp)
	fwait
	# Register %al allocated
.Ll29:
	.stabn 68,0,118,.Ll29 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	jb	.L96
# Temp -4,4 released
.L95:
	# Register %edx allocated
.Ll30:
	.stabn 68,0,123,.Ll30 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
# [123] total:=sum;
	movl	-12(%ebp),%edx
	# Register %eax allocated
	movl	-24(%ebp),%eax
	# Register %eax released
	movl	%eax,(%edx)
	# Register %eax allocated
	movl	-20(%ebp),%eax
	# Register %edx,%eax released
	movl	%eax,4(%edx)
# Temp -16,4 released
# Temp -24,8 released
# Temp -2064,2040 released
# Temp -8,4 released
# Temp -12,4 released
	# Register %esi allocated
.Ll31:
	.stabn 68,0,124,.Ll31 - P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
# [124] end; { TotalDesv }
	movl	-2076(%ebp),%esi
	# Register %edi allocated
	movl	-2072(%ebp),%edi
# Temp -2076,8 released
	leave
	# Register %ebp released
	ret
.L112:
	.stabn 192,0,0,P$STATIC_TOTALDESV$READATA$READATA$DOUBLE-P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
	.stabn 224,0,0,.L112-P$STATIC_TOTALDESV$READATA$READATA$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "FRECACUM:F3",36,0,131,P$STATIC_FRECACUM$ARRDATA$$ARRDATA
	.stabs "F:p3",160,0,131,-1040
	.stabs "result:v3",160,0,131,-8
	.stabs "I:5",160,0,133,-12
	.stabs "SUM:5",160,0,133,-16
	.stabs "RETDATA:3",160,0,134,-528
.Ll32:
	.stabn 68,0,135,.Ll32 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
# [135] begin;
.globl	P$STATIC_FRECACUM$ARRDATA$$ARRDATA
P$STATIC_FRECACUM$ARRDATA$$ARRDATA:
# Temps allocated between ebp-1048 and ebp-528
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$1048,%esp
# Temp -1048,8 allocated
	movl	%esi,-1048(%ebp)
	movl	%edi,-1044(%ebp)
# Temp -4,4 allocated
# Var F located at ebp-4
# Temp -8,4 allocated
# Var $result located at ebp-8
# Temp -12,4 allocated
# Var i located at ebp-12
# Temp -16,4 allocated
# Var sum located at ebp-16
# Temp -528,512 allocated
# Var retdata located at ebp-528
	# Register %eax,%edx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -1040,512 allocated
	# Register %edi allocated
	leal	-1040(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$127,%ecx
	rep
	movsl
	movsw
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$1048,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll33:
	.stabn 68,0,136,.Ll33 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
# [136] sum := 0;
	movb	$0,-16(%ebp)
# Temp -4,4 allocated
	# Register %al allocated
.Ll34:
	.stabn 68,0,137,.Ll34 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
# [137] for i := 1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-4(%ebp)
	movb	$1,-12(%ebp)
	# Register %al allocated
	movb	-12(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	ja	.L118
	subb	$1,-12(%ebp)
	.balign 4
.L119:
	addb	$1,-12(%ebp)
	# Register %edx allocated
.Ll35:
	.stabn 68,0,139,.Ll35 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
# [139] sum := sum + F[i];
	movzbl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L122
	call	FPC_RANGEERROR
.L122:
	# Register %edx released
	# Register %eax allocated
	movswl	-1042(%ebp,%edx,2),%eax
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax released
	addl	%eax,%edx
	jno	.L123
	call	FPC_OVERFLOW
.L123:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L124
	call	FPC_RANGEERROR
.L124:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-16(%ebp)
	# Register %edx allocated
.Ll36:
	.stabn 68,0,140,.Ll36 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
# [140] retdata[i]:= sum;
	movzbl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L127
	call	FPC_RANGEERROR
.L127:
	# Register %ax allocated
	movzbw	-16(%ebp),%ax
	# Register %edx,%ax released
	movw	%ax,-530(%ebp,%edx,2)
	# Register %al allocated
.Ll37:
	.stabn 68,0,137,.Ll37 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
	movb	-12(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	jb	.L119
# Temp -4,4 released
.L118:
	# Register %edi allocated
.Ll38:
	.stabn 68,0,142,.Ll38 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
# [142] FrecAcum := RetData
	movl	-8(%ebp),%edi
	# Register %esi allocated
	leal	-528(%ebp),%esi
	# Register %ecx allocated
	cld
	movl	$127,%ecx
	rep
	movsl
	movsw
	# Register %ecx,%esi,%edi released
# Temp -12,4 released
# Temp -16,4 released
# Temp -528,512 released
# Temp -1040,512 released
# Temp -8,4 released
	# Register %esi allocated
.Ll39:
	.stabn 68,0,143,.Ll39 - P$STATIC_FRECACUM$ARRDATA$$ARRDATA
# [143] end; { FrecAcum }
	movl	-1048(%ebp),%esi
	# Register %edi allocated
	movl	-1044(%ebp),%edi
# Temp -1048,8 released
	leave
	# Register %ebp released
	ret
.L135:
	.stabs "FRECACUM:X*3",160,0,0,-8
	.stabn 192,0,0,P$STATIC_FRECACUM$ARRDATA$$ARRDATA-P$STATIC_FRECACUM$ARRDATA$$ARRDATA
	.stabn 224,0,0,.L135-P$STATIC_FRECACUM$ARRDATA$$ARRDATA

.section .text
	.balign 4
	.balign 4
	.stabs "FLOGPM:F8",36,0,149,P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
	.stabs "PM:p4",160,0,149,-2056
	.stabs "F:p3",160,0,149,-2568
	.stabs "LPM:v4",160,0,150,-12
	.stabs "FLPM:v4",160,0,150,8
	.stabs "TOTALFLPM:v11",160,0,150,12
	.stabs "I:5",160,0,152,-16
.Ll40:
	.stabn 68,0,153,.Ll40 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
# [153] begin
.globl	P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE:
# Temps allocated between ebp-2576 and ebp-16
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$2576,%esp
# Temp -2576,8 allocated
	movl	%esi,-2576(%ebp)
	movl	%edi,-2572(%ebp)
# Temp -4,4 allocated
# Var PM located at ebp-4
# Temp -8,4 allocated
# Var F located at ebp-8
# Temp -12,4 allocated
# Var LPM located at ebp-12
# Var FLPM located at ebp+8
# Var totalflpm located at ebp+12
# Temp -16,4 allocated
# Var i located at ebp-16
	# Register %eax,%edx,%ecx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %ecx released
	movl	%ecx,-12(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -2056,2040 allocated
	# Register %edi allocated
	leal	-2056(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %esi allocated
	movl	-8(%ebp),%esi
# Temp -2568,512 allocated
	# Register %edi allocated
	leal	-2568(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$127,%ecx
	rep
	movsl
	movsw
	# Register %ecx,%esi,%edi released
# Temp -8,4 released
	# Register %eax allocated
	movl	$2576,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll41:
	.stabn 68,0,154,.Ll41 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
# [154] totalflpm:=0;
	movl	12(%ebp),%eax
	fldz
	# Register %eax released
	fstpl	(%eax)
	fwait
# Temp -8,4 allocated
	# Register %al allocated
.Ll42:
	.stabn 68,0,155,.Ll42 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
# [155] for i:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-8(%ebp)
	movb	$1,-16(%ebp)
	# Register %al allocated
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-8(%ebp),%al
	ja	.L141
	subb	$1,-16(%ebp)
	.balign 4
.L142:
	addb	$1,-16(%ebp)
	# Register %edx allocated
.Ll43:
	.stabn 68,0,157,.Ll43 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
# [157] LPM[i]:=log10(PM[i]);
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L147
	call	FPC_RANGEERROR
.L147:
	# Register %edx released
	fldl	-2064(%ebp,%edx,8)
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax,%ecx,%edx allocated
	call	MATH_LOG10$EXTENDED$$EXTENDED
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	-12(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L148
	call	FPC_RANGEERROR
.L148:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %edx allocated
.Ll44:
	.stabn 68,0,158,.Ll44 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
# [158] FLPM[i]:=F[i]*LPM[i];
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L151
	call	FPC_RANGEERROR
.L151:
# Temp -4,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	-2570(%ebp,%edx,2),%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
	# Register %ecx allocated
	movl	-12(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L152
	call	FPC_RANGEERROR
.L152:
	# Register %ecx,%edx released
	fldl	-8(%ecx,%edx,8)
	fmulp	%st,%st(1)
	# Register %ecx allocated
	movl	8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L153
	call	FPC_RANGEERROR
.L153:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %ecx allocated
.Ll45:
	.stabn 68,0,159,.Ll45 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
# [159] totalflpm:= totalflpm + flpm[i];
	movl	8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L156
	call	FPC_RANGEERROR
.L156:
	# Register %eax allocated
	movl	12(%ebp),%eax
	# Register %eax released
	fldl	(%eax)
	# Register %ecx,%edx released
	fldl	-8(%ecx,%edx,8)
	faddp	%st,%st(1)
	# Register %eax allocated
	movl	12(%ebp),%eax
	# Register %eax released
	fstpl	(%eax)
	fwait
	# Register %al allocated
.Ll46:
	.stabn 68,0,155,.Ll46 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-8(%ebp),%al
	jb	.L142
# Temp -8,4 released
.L141:
# Temp -16,4 released
# Temp -2056,2040 released
# Temp -2568,512 released
# Temp -12,4 released
	# Register %esi allocated
.Ll47:
	.stabn 68,0,161,.Ll47 - P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
# [161] end; { FLogPM }
	movl	-2576(%ebp),%esi
	# Register %edi allocated
	movl	-2572(%ebp),%edi
# Temp -2576,8 released
	leave
	# Register %ebp released
	ret	$8
.L162:
	.stabn 192,0,0,P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE-P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
	.stabn 224,0,0,.L162-P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "FINVPM:F8",36,0,169,P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
	.stabs "PM:p4",160,0,169,-2056
	.stabs "INVPM:v4",160,0,169,-8
	.stabs "FXINVPM:v4",160,0,169,-12
	.stabs "TOTAL:v11",160,0,170,8
	.stabs "I:5",160,0,172,-16
.Ll48:
	.stabn 68,0,173,.Ll48 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
# [173] begin
.globl	P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE:
# Temps allocated between ebp-2068 and ebp-16
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$2068,%esp
# Temp -2068,8 allocated
	movl	%esi,-2068(%ebp)
	movl	%edi,-2064(%ebp)
# Temp -4,4 allocated
# Var pm located at ebp-4
# Temp -8,4 allocated
# Var InvPM located at ebp-8
# Temp -12,4 allocated
# Var FxInvPM located at ebp-12
# Var total located at ebp+8
# Temp -16,4 allocated
# Var i located at ebp-16
	# Register %eax,%edx,%ecx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %ecx released
	movl	%ecx,-12(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -2056,2040 allocated
	# Register %edi allocated
	leal	-2056(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$2068,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll49:
	.stabn 68,0,174,.Ll49 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
# [174] total:=0;
	movl	8(%ebp),%eax
	fldz
	# Register %eax released
	fstpl	(%eax)
	fwait
# Temp -4,4 allocated
	# Register %al allocated
.Ll50:
	.stabn 68,0,175,.Ll50 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
# [175] for i:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-4(%ebp)
	movb	$1,-16(%ebp)
	# Register %al allocated
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	ja	.L168
	subb	$1,-16(%ebp)
	.balign 4
.L169:
	addb	$1,-16(%ebp)
.Ll51:
	.stabn 68,0,177,.Ll51 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
# [177] invPM[i]:=1/pm[i];
	fld1
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L172
	call	FPC_RANGEERROR
.L172:
	# Register %edx released
	fldl	-2064(%ebp,%edx,8)
	fdivrp	%st,%st(1)
	# Register %ecx allocated
	movl	-8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L173
	call	FPC_RANGEERROR
.L173:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %ecx allocated
.Ll52:
	.stabn 68,0,178,.Ll52 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
# [178] FxInvPM[i] :=invpm[i]*frec[i];
	movl	-8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L176
	call	FPC_RANGEERROR
.L176:
	# Register %ecx,%edx released
	fldl	-8(%ecx,%edx,8)
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L177
	call	FPC_RANGEERROR
.L177:
# Temp -2060,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-2060(%ebp)
	fildl	-2060(%ebp)
# Temp -2060,4 released
	fmulp	%st,%st(1)
	# Register %ecx allocated
	movl	-12(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L178
	call	FPC_RANGEERROR
.L178:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %ecx allocated
.Ll53:
	.stabn 68,0,179,.Ll53 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
# [179] total:=total + FxInvPM[i];
	movl	-12(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L181
	call	FPC_RANGEERROR
.L181:
	# Register %eax allocated
	movl	8(%ebp),%eax
	# Register %eax released
	fldl	(%eax)
	# Register %ecx,%edx released
	fldl	-8(%ecx,%edx,8)
	faddp	%st,%st(1)
	# Register %eax allocated
	movl	8(%ebp),%eax
	# Register %eax released
	fstpl	(%eax)
	fwait
	# Register %al allocated
.Ll54:
	.stabn 68,0,175,.Ll54 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	jb	.L169
# Temp -4,4 released
.L168:
# Temp -16,4 released
# Temp -2056,2040 released
# Temp -8,4 released
# Temp -12,4 released
	# Register %esi allocated
.Ll55:
	.stabn 68,0,181,.Ll55 - P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
# [181] end; { invPM }
	movl	-2068(%ebp),%esi
	# Register %edi allocated
	movl	-2064(%ebp),%edi
# Temp -2068,8 released
	leave
	# Register %ebp released
	ret	$4
.L187:
	.stabn 192,0,0,P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE-P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
	.stabn 224,0,0,.L187-P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "MEDIAARIT:F11",36,0,189,P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE
	.stabs "A:p11",160,0,189,8
	.stabs "SUMFXV:p11",160,0,190,16
	.stabs "result:11",160,0,189,-8
.Ll56:
	.stabn 68,0,191,.Ll56 - P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE
# [191] begin
.globl	P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE
P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE:
# Temps allocated between ebp-12 and ebp-8
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$12,%esp
# Var A located at ebp+8
# Var sumfxv located at ebp+16
# Temp -8,8 allocated
# Var $result located at ebp-8
	# Register %eax allocated
	movl	$12,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll57:
	.stabn 68,0,192,.Ll57 - P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE
# [192] MediaArit:=A + (sumfxv/numdatos);
	fldl	16(%ebp)
# Temp -12,4 allocated
	# Register %eax allocated
	movzbl	U_P$STATIC_NUMDATOS,%eax
	# Register %eax released
	movl	%eax,-12(%ebp)
	fildl	-12(%ebp)
# Temp -12,4 released
	fdivrp	%st,%st(1)
	fldl	8(%ebp)
	faddp	%st,%st(1)
	fstpl	-8(%ebp)
	fwait
.Ll58:
	.stabn 68,0,193,.Ll58 - P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE
# [193] end; { MediaArit }
	fldl	-8(%ebp)
# Temp -8,8 released
	leave
	# Register %ebp released
	ret	$16
.L197:
	.stabs "MEDIAARIT:X11",160,0,0,-8
	.stabn 192,0,0,P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE-P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE
	.stabn 224,0,0,.L197-P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "DIFFMEDIA:F4",36,0,201,P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
	.stabs "PM:p4",160,0,201,-2052
	.stabs "MA:p11",160,0,201,8
	.stabs "result:v4",160,0,201,-8
	.stabs "I:5",160,0,203,-12
.Ll59:
	.stabn 68,0,204,.Ll59 - P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
# [204] begin
.globl	P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA:
# Temps allocated between ebp-2060 and ebp-12
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$2060,%esp
# Temp -2060,8 allocated
	movl	%esi,-2060(%ebp)
	movl	%edi,-2056(%ebp)
# Temp -4,4 allocated
# Var PM located at ebp-4
# Var MA located at ebp+8
# Temp -8,4 allocated
# Var $result located at ebp-8
# Temp -12,4 allocated
# Var i located at ebp-12
	# Register %eax,%edx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -2052,2040 allocated
	# Register %edi allocated
	leal	-2052(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$2060,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
# Temp -4,4 allocated
	# Register %al allocated
.Ll60:
	.stabn 68,0,205,.Ll60 - P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
# [205] for i:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-4(%ebp)
	movb	$1,-12(%ebp)
	# Register %al allocated
	movb	-12(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	ja	.L201
	subb	$1,-12(%ebp)
	.balign 4
.L202:
	addb	$1,-12(%ebp)
	# Register %edx allocated
.Ll61:
	.stabn 68,0,206,.Ll61 - P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
# [206] DiffMedia[i]:=PM[i] - MA;
	movzbl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L205
	call	FPC_RANGEERROR
.L205:
	fldl	8(%ebp)
	# Register %edx released
	fldl	-2060(%ebp,%edx,8)
	fsubp	%st,%st(1)
	# Register %ecx allocated
	movl	-8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L206
	call	FPC_RANGEERROR
.L206:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %al allocated
.Ll62:
	.stabn 68,0,205,.Ll62 - P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
	movb	-12(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	jb	.L202
# Temp -4,4 released
.L201:
# Temp -12,4 released
# Temp -2052,2040 released
# Temp -8,4 released
	# Register %esi allocated
.Ll63:
	.stabn 68,0,207,.Ll63 - P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
# [207] end; { DiffMedia }
	movl	-2060(%ebp),%esi
	# Register %edi allocated
	movl	-2056(%ebp),%edi
# Temp -2060,8 released
	leave
	# Register %ebp released
	ret	$8
.L212:
	.stabs "DIFFMEDIA:X*4",160,0,0,-8
	.stabn 192,0,0,P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA-P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
	.stabn 224,0,0,.L212-P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA

.section .text
	.balign 4
	.balign 4
	.stabs "FXDIFFMEDIA:F8",36,0,214,P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
	.stabs "X:p4",160,0,214,-2056
	.stabs "FXX:v4",160,0,214,-8
	.stabs "FXX2:v4",160,0,214,-12
	.stabs "TOT:v11",160,0,214,8
	.stabs "I:5",160,0,216,-16
.Ll64:
	.stabn 68,0,217,.Ll64 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
# [217] begin
.globl	P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE:
# Temps allocated between ebp-2072 and ebp-16
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$2072,%esp
# Temp -2072,12 allocated
	movl	%ebx,-2072(%ebp)
	movl	%esi,-2068(%ebp)
	movl	%edi,-2064(%ebp)
# Temp -4,4 allocated
# Var X located at ebp-4
# Temp -8,4 allocated
# Var FxX located at ebp-8
# Temp -12,4 allocated
# Var FxX2 located at ebp-12
# Var tot located at ebp+8
# Temp -16,4 allocated
# Var i located at ebp-16
	# Register %eax,%edx,%ecx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %ecx released
	movl	%ecx,-12(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -2056,2040 allocated
	# Register %edi allocated
	leal	-2056(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$2072,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll65:
	.stabn 68,0,218,.Ll65 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
# [218] tot:=0;
	movl	8(%ebp),%eax
	fldz
	# Register %eax released
	fstpl	(%eax)
	fwait
# Temp -4,4 allocated
	# Register %al allocated
.Ll66:
	.stabn 68,0,219,.Ll66 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
# [219] for i:=1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-4(%ebp)
	movb	$1,-16(%ebp)
	# Register %al allocated
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	ja	.L218
	subb	$1,-16(%ebp)
	.balign 4
.L219:
	addb	$1,-16(%ebp)
	# Register %edx allocated
.Ll67:
	.stabn 68,0,221,.Ll67 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
# [221] FxX[i] := frec[i]*X[i];
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L222
	call	FPC_RANGEERROR
.L222:
# Temp -2060,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-2060(%ebp)
	fildl	-2060(%ebp)
# Temp -2060,4 released
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L223
	call	FPC_RANGEERROR
.L223:
	# Register %edx released
	fldl	-2064(%ebp,%edx,8)
	fmulp	%st,%st(1)
	# Register %ecx allocated
	movl	-8(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L224
	call	FPC_RANGEERROR
.L224:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %edx allocated
.Ll68:
	.stabn 68,0,222,.Ll68 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
# [222] FxX2[i] := X[i]*FxX[i];
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L227
	call	FPC_RANGEERROR
.L227:
	# Register %ebx allocated
	movl	-8(%ebp),%ebx
	# Register %ecx allocated
	movzbl	-16(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L228
	call	FPC_RANGEERROR
.L228:
	# Register %ebx,%ecx released
	fldl	-8(%ebx,%ecx,8)
	# Register %edx released
	fldl	-2064(%ebp,%edx,8)
	fmulp	%st,%st(1)
	# Register %ecx allocated
	movl	-12(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L229
	call	FPC_RANGEERROR
.L229:
	# Register %ecx,%edx released
	fstpl	-8(%ecx,%edx,8)
	fwait
	# Register %ecx allocated
.Ll69:
	.stabn 68,0,223,.Ll69 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
# [223] tot:=tot + FxX2[i];
	movl	-12(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L232
	call	FPC_RANGEERROR
.L232:
	# Register %eax allocated
	movl	8(%ebp),%eax
	# Register %eax released
	fldl	(%eax)
	# Register %ecx,%edx released
	fldl	-8(%ecx,%edx,8)
	faddp	%st,%st(1)
	# Register %eax allocated
	movl	8(%ebp),%eax
	# Register %eax released
	fstpl	(%eax)
	fwait
	# Register %al allocated
.Ll70:
	.stabn 68,0,219,.Ll70 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
	movb	-16(%ebp),%al
	# Register %al released
	cmpb	-4(%ebp),%al
	jb	.L219
# Temp -4,4 released
.L218:
# Temp -16,4 released
# Temp -2056,2040 released
# Temp -8,4 released
# Temp -12,4 released
	# Register %ebx allocated
.Ll71:
	.stabn 68,0,225,.Ll71 - P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
# [225] end; { fxDiffMedia }
	movl	-2072(%ebp),%ebx
	# Register %esi allocated
	movl	-2068(%ebp),%esi
	# Register %edi allocated
	movl	-2064(%ebp),%edi
# Temp -2072,12 released
	leave
	# Register %ebp released
	ret	$4
.L238:
	.stabn 192,0,0,P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE-P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
	.stabn 224,0,0,.L238-P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "ORDEN:F8",36,0,233,P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
	.stabs "VECTOR:v3",160,0,233,-4
	.stabs "PRIMER:p21",160,0,233,-8
	.stabs "ULTIMO:p21",160,0,233,-12
	.stabs "I:5",160,0,235,-16
	.stabs "J:5",160,0,235,-20
	.stabs "VALOR:21",160,0,236,-24
	.stabs "VALT:21",160,0,236,-28
.Ll72:
	.stabn 68,0,237,.Ll72 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [237] begin
.globl	P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT:
# Temps allocated between ebp-36 and ebp-28
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$36,%esp
# Temp -36,8 allocated
	movl	%ebx,-36(%ebp)
	movl	%esi,-32(%ebp)
# Temp -4,4 allocated
# Var vector located at ebp-4
# Temp -8,4 allocated
# Var primer located at ebp-8
# Temp -12,4 allocated
# Var ultimo located at ebp-12
# Temp -16,4 allocated
# Var i located at ebp-16
# Temp -20,4 allocated
# Var j located at ebp-20
# Temp -24,4 allocated
# Var valor located at ebp-24
# Temp -28,4 allocated
# Var valt located at ebp-28
	# Register %eax,%dx,%cx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %dx released
	movw	%dx,-8(%ebp)
	# Register %cx released
	movw	%cx,-12(%ebp)
	# Register %eax allocated
	movl	$36,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll73:
	.stabn 68,0,238,.Ll73 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [238] i:=primer;
	movswl	-8(%ebp),%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L243
	call	FPC_RANGEERROR
.L243:
	# Register %al allocated
	movb	-8(%ebp),%al
	# Register %al released
	movb	%al,-16(%ebp)
	# Register %eax allocated
.Ll74:
	.stabn 68,0,239,.Ll74 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [239] j:=ultimo;
	movswl	-12(%ebp),%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L246
	call	FPC_RANGEERROR
.L246:
	# Register %al allocated
	movb	-12(%ebp),%al
	# Register %al released
	movb	%al,-20(%ebp)
	# Register %ecx allocated
.Ll75:
	.stabn 68,0,241,.Ll75 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [241] valor := vector[(primer+ultimo)div 2];
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movswl	-8(%ebp),%edx
	# Register %eax allocated
	movswl	-12(%ebp),%eax
	# Register %edx released
	addl	%edx,%eax
	jno	.L249
	call	FPC_OVERFLOW
.L249:
	testl	%eax,%eax
	jns	.L250
	incl	%eax
.L250:
	sarl	$1,%eax
	# Register %edx allocated
	movl	%eax,%edx
	subl	$1,%edx
	# Register %edx released
	cmpl	$254,%edx
	jbe	.L251
	call	FPC_RANGEERROR
.L251:
	# Register %ecx,%eax released
	# Register %ax allocated
	movw	-2(%ecx,%eax,2),%ax
	# Register %ax released
	movw	%ax,-24(%ebp)
	.balign 4
.L252:
.Ll76:
	.stabn 68,0,243,.Ll76 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [243] while vector[i] < valor do
	jmp	.L256
	.balign 4
.L255:
	# Register %edx allocated
.Ll77:
	.stabn 68,0,244,.Ll77 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [244] i := i +1;
	movzbl	-16(%ebp),%edx
	addl	$1,%edx
	jno	.L260
	call	FPC_OVERFLOW
.L260:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L261
	call	FPC_RANGEERROR
.L261:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-16(%ebp)
.L256:
	# Register %ecx allocated
.Ll78:
	.stabn 68,0,243,.Ll78 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L262
	call	FPC_RANGEERROR
.L262:
	# Register %ecx released
	movswl	-2(%ecx,%edx,2),%edx
	# Register %eax allocated
	movswl	-24(%ebp),%eax
	# Register %edx,%eax released
	cmpl	%eax,%edx
	jl	.L255
	jmp	.L257
.L257:
.Ll79:
	.stabn 68,0,245,.Ll79 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [245] while vector[j] > valor do
	jmp	.L264
	.balign 4
.L263:
	# Register %edx allocated
.Ll80:
	.stabn 68,0,246,.Ll80 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [246] j := j - 1;
	movzbl	-20(%ebp),%edx
	subl	$1,%edx
	jno	.L268
	call	FPC_OVERFLOW
.L268:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L269
	call	FPC_RANGEERROR
.L269:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-20(%ebp)
.L264:
	# Register %ecx allocated
.Ll81:
	.stabn 68,0,245,.Ll81 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L270
	call	FPC_RANGEERROR
.L270:
	# Register %ecx,%edx released
	# Register %eax allocated
	movswl	-2(%ecx,%edx,2),%eax
	# Register %edx allocated
	movswl	-24(%ebp),%edx
	# Register %eax,%edx released
	cmpl	%edx,%eax
	jg	.L263
	jmp	.L265
.L265:
	# Register %edx allocated
.Ll82:
	.stabn 68,0,247,.Ll82 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [247] if i<=j then
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movzbl	-20(%ebp),%eax
	# Register %edx,%eax released
	cmpl	%eax,%edx
	jbe	.L271
	jmp	.L272
.L271:
	# Register %ecx allocated
.Ll83:
	.stabn 68,0,249,.Ll83 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [249] valt := vector[i];
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L275
	call	FPC_RANGEERROR
.L275:
	# Register %ecx,%edx released
	# Register %ax allocated
	movw	-2(%ecx,%edx,2),%ax
	# Register %ax released
	movw	%ax,-28(%ebp)
	# Register %ebx allocated
.Ll84:
	.stabn 68,0,250,.Ll84 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [250] vector[i] := vector[j];
	movl	-4(%ebp),%ebx
	# Register %edx allocated
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L278
	call	FPC_RANGEERROR
.L278:
	# Register %esi allocated
	movl	-4(%ebp),%esi
	# Register %ecx allocated
	movzbl	-16(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L279
	call	FPC_RANGEERROR
.L279:
	# Register %ebx,%edx released
	# Register %ax allocated
	movw	-2(%ebx,%edx,2),%ax
	# Register %esi,%ecx,%ax released
	movw	%ax,-2(%esi,%ecx,2)
	# Register %ecx allocated
.Ll85:
	.stabn 68,0,251,.Ll85 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [251] vector[j]:= valt;
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L282
	call	FPC_RANGEERROR
.L282:
	# Register %ax allocated
	movw	-28(%ebp),%ax
	# Register %ecx,%edx,%ax released
	movw	%ax,-2(%ecx,%edx,2)
	# Register %edx allocated
.Ll86:
	.stabn 68,0,252,.Ll86 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [252] i := i + 1;
	movzbl	-16(%ebp),%edx
	addl	$1,%edx
	jno	.L285
	call	FPC_OVERFLOW
.L285:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L286
	call	FPC_RANGEERROR
.L286:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-16(%ebp)
	# Register %edx allocated
.Ll87:
	.stabn 68,0,253,.Ll87 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [253] j := j - 1;
	movzbl	-20(%ebp),%edx
	subl	$1,%edx
	jno	.L289
	call	FPC_OVERFLOW
.L289:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L290
	call	FPC_RANGEERROR
.L290:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-20(%ebp)
.L272:
	# Register %edx allocated
.Ll88:
	.stabn 68,0,255,.Ll88 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [255] until i > j;
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movzbl	-20(%ebp),%eax
	# Register %edx,%eax released
	cmpl	%eax,%edx
	ja	.L254
	jmp	.L252
.L254:
	# Register %edx allocated
.Ll89:
	.stabn 68,0,256,.Ll89 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [256] if primer < j then
	movswl	-8(%ebp),%edx
	# Register %eax allocated
	movzbl	-20(%ebp),%eax
	# Register %edx,%eax released
	cmpl	%eax,%edx
	jl	.L291
	jmp	.L292
.L291:
	# Register %cx allocated
.Ll90:
	.stabn 68,0,257,.Ll90 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [257] orden(vector,primer,j);
	movzbw	-20(%ebp),%cx
	# Register %dx allocated
	movw	-8(%ebp),%dx
	# Register %eax allocated
	movl	-4(%ebp),%eax
	# Register %cx,%dx released
	# Register %ecx,%edx allocated
	call	P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
	# Register %eax,%ecx,%edx released
.L292:
	# Register %edx allocated
.Ll91:
	.stabn 68,0,258,.Ll91 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [258] if i < ultimo then
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movswl	-12(%ebp),%eax
	# Register %edx,%eax released
	cmpl	%eax,%edx
	jl	.L299
	jmp	.L300
.L299:
	# Register %cx allocated
.Ll92:
	.stabn 68,0,259,.Ll92 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [259] orden(vector,i,ultimo);
	movw	-12(%ebp),%cx
	# Register %dx allocated
	movzbw	-16(%ebp),%dx
	# Register %eax allocated
	movl	-4(%ebp),%eax
	# Register %cx,%dx released
	# Register %ecx,%edx allocated
	call	P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
	# Register %eax,%ecx,%edx released
.L300:
# Temp -16,4 released
# Temp -20,4 released
# Temp -24,4 released
# Temp -28,4 released
# Temp -4,4 released
# Temp -8,4 released
# Temp -12,4 released
	# Register %ebx allocated
.Ll93:
	.stabn 68,0,260,.Ll93 - P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
# [260] end; { orden }
	movl	-36(%ebp),%ebx
	# Register %esi allocated
	movl	-32(%ebp),%esi
# Temp -36,8 released
	leave
	# Register %ebp released
	ret
.L312:
	.stabn 192,0,0,P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT-P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT
	.stabn 224,0,0,.L312-P$STATIC_ORDEN$ARRDATA$SMALLINT$SMALLINT

.section .text
	.balign 4
	.balign 4
	.stabs "MEDIANA:F11",36,0,268,P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	.stabs "FAC:p3",160,0,268,-532
	.stabs "result:11",160,0,268,-12
	.stabs "I:5",160,0,270,-16
	.stabs "INDEX:5",160,0,270,-20
.Ll94:
	.stabn 68,0,273,.Ll94 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [273] begin
.globl	P$STATIC_MEDIANA$ARRDATA$$DOUBLE
P$STATIC_MEDIANA$ARRDATA$$DOUBLE:
# Temps allocated between ebp-544 and ebp-20
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$544,%esp
# Temp -544,12 allocated
	movl	%ebx,-544(%ebp)
	movl	%esi,-540(%ebp)
	movl	%edi,-536(%ebp)
# Temp -4,4 allocated
# Var FAc located at ebp-4
# Temp -12,8 allocated
# Var $result located at ebp-12
# Temp -16,4 allocated
# Var i located at ebp-16
# Temp -20,4 allocated
# Var index located at ebp-20
	# Register %eax allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -532,512 allocated
	# Register %edi allocated
	leal	-532(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$127,%ecx
	rep
	movsl
	movsw
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %eax allocated
	movl	$544,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll95:
	.stabn 68,0,274,.Ll95 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [274] i:=1;
	movb	$1,-16(%ebp)
.Ll96:
	.stabn 68,0,275,.Ll96 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [275] index:=0;
	movb	$0,-20(%ebp)
.Ll97:
	.stabn 68,0,276,.Ll97 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [276] while (index = 0) AND (i <= numinterv) do
	jmp	.L320
	.balign 4
.L319:
	# Register %edx allocated
.Ll98:
	.stabn 68,0,278,.Ll98 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [278] if FAc[i] >= (numdatos/2) then
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L324
	call	FPC_RANGEERROR
.L324:
# Temp -4,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	-534(%ebp,%edx,2),%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
# Temp -4,4 allocated
	# Register %eax allocated
	movzbl	U_P$STATIC_NUMDATOS,%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
	fldt	_$PROGRAM$_L44
	fdivrp	%st,%st(1)
	fcompp
	# Register %ax allocated
	fnstsw	%ax
	sahf
	# Register %ax released
	jbe	.L322
	jmp	.L323
.L322:
	# Register %al allocated
.Ll99:
	.stabn 68,0,280,.Ll99 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [280] index := i;
	movb	-16(%ebp),%al
	# Register %al released
	movb	%al,-20(%ebp)
.L323:
	# Register %edx allocated
.Ll100:
	.stabn 68,0,282,.Ll100 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [282] i:=i+1;
	movzbl	-16(%ebp),%edx
	addl	$1,%edx
	jno	.L329
	call	FPC_OVERFLOW
.L329:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L330
	call	FPC_RANGEERROR
.L330:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-16(%ebp)
.L320:
	# Register %eax allocated
.Ll101:
	.stabn 68,0,276,.Ll101 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	movzbl	-20(%ebp),%eax
	# Register %eax released
	testl	%eax,%eax
	je	.L331
	jmp	.L321
.L331:
	# Register %eax allocated
	movzbl	-16(%ebp),%eax
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMINTERV,%edx
	# Register %eax,%edx released
	cmpl	%edx,%eax
	jbe	.L319
	jmp	.L321
.L321:
	# Register %edx allocated
.Ll102:
	.stabn 68,0,285,.Ll102 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [285] if (frec[index] <> 0) AND (index > 0) then
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L335
	call	FPC_RANGEERROR
.L335:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	testl	%eax,%eax
	jne	.L334
	jmp	.L333
.L334:
	# Register %eax allocated
	movzbl	-20(%ebp),%eax
	# Register %eax released
	cmpl	$0,%eax
	jg	.L332
	jmp	.L333
.L332:
# Temp -4,4 allocated
	# Register %eax allocated
.Ll103:
	.stabn 68,0,286,.Ll103 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [286] mediana:= IntervI[index] + (((numdatos/2) -
	movzbl	U_P$STATIC_NUMDATOS,%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
	fldt	_$PROGRAM$_L44
	fdivrp	%st,%st(1)
	# Register %edx allocated
.Ll104:
	.stabn 68,0,287,.Ll104 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [287] FAc[index-1])/Frec[index]) * (intervD[index]-intervI[index])
	movzbl	-20(%ebp),%edx
	subl	$1,%edx
	jno	.L338
	call	FPC_OVERFLOW
.L338:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L339
	call	FPC_RANGEERROR
.L339:
# Temp -4,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	-534(%ebp,%edx,2),%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
.Ll105:
	.stabn 68,0,286,.Ll105 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	fsubrp	%st,%st(1)
	# Register %edx allocated
.Ll106:
	.stabn 68,0,287,.Ll106 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L340
	call	FPC_RANGEERROR
.L340:
# Temp -4,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
.Ll107:
	.stabn 68,0,286,.Ll107 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	fdivrp	%st,%st(1)
	# Register %edx allocated
.Ll108:
	.stabn 68,0,287,.Ll108 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L341
	call	FPC_RANGEERROR
.L341:
	# Register %edx released
	# Register %ecx allocated
	movswl	U_P$STATIC_INTERVD-2(,%edx,2),%ecx
	# Register %edx allocated
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L342
	call	FPC_RANGEERROR
.L342:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVI-2(,%edx,2),%eax
	# Register %eax released
	subl	%eax,%ecx
	jno	.L343
	call	FPC_OVERFLOW
.L343:
# Temp -4,4 allocated
	# Register %ecx released
	movl	%ecx,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
	fmulp	%st,%st(1)
	# Register %edx allocated
.Ll109:
	.stabn 68,0,286,.Ll109 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	movzbl	-20(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L344
	call	FPC_RANGEERROR
.L344:
# Temp -4,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVI-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-4(%ebp)
	fildl	-4(%ebp)
# Temp -4,4 released
	faddp	%st,%st(1)
	fstpl	-12(%ebp)
	fwait
	jmp	.L345
.L333:
	# Register %eax,%ecx,%edx allocated
.Ll110:
	.stabn 68,0,290,.Ll110 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [290] writeln('Error: imposible calcular mediana, division entre cero');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L350,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax allocated
.Ll111:
	.stabn 68,0,291,.Ll111 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [291] mediana:=-1;
	movl	_$PROGRAM$_L359,%eax
	# Register %eax released
	movl	%eax,-12(%ebp)
	# Register %eax allocated
	movl	_$PROGRAM$_L359+4,%eax
	# Register %eax released
	movl	%eax,-8(%ebp)
.L345:
.Ll112:
	.stabn 68,0,293,.Ll112 - P$STATIC_MEDIANA$ARRDATA$$DOUBLE
# [293] end; { mediana }
	fldl	-12(%ebp)
# Temp -12,8 released
# Temp -16,4 released
# Temp -20,4 released
# Temp -532,512 released
	# Register %ebx allocated
	movl	-544(%ebp),%ebx
	# Register %esi allocated
	movl	-540(%ebp),%esi
	# Register %edi allocated
	movl	-536(%ebp),%edi
# Temp -544,12 released
	leave
	# Register %ebp released
	ret
.L365:
	.stabs "MEDIANA:X11",160,0,0,-12
	.stabn 192,0,0,P$STATIC_MEDIANA$ARRDATA$$DOUBLE-P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	.stabn 224,0,0,.L365-P$STATIC_MEDIANA$ARRDATA$$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "MODA:F11",36,0,300,P$STATIC_MODA$$DOUBLE
	.stabs "result:11",160,0,300,-8
	.stabs "I:5",160,0,302,-12
	.stabs "IDX:5",160,0,302,-16
	.stabs "TMP:11",160,0,303,-24
.Ll113:
	.stabn 68,0,304,.Ll113 - P$STATIC_MODA$$DOUBLE
# [304] begin
.globl	P$STATIC_MODA$$DOUBLE
P$STATIC_MODA$$DOUBLE:
# Temps allocated between ebp-36 and ebp-24
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$36,%esp
# Temp -36,4 allocated
	movl	%ebx,-36(%ebp)
# Temp -8,8 allocated
# Var $result located at ebp-8
# Temp -12,4 allocated
# Var i located at ebp-12
# Temp -16,4 allocated
# Var idx located at ebp-16
# Temp -24,8 allocated
# Var tmp located at ebp-24
	# Register %eax allocated
	movl	$36,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll114:
	.stabn 68,0,305,.Ll114 - P$STATIC_MODA$$DOUBLE
# [305] idx:=0;
	movb	$0,-16(%ebp)
# Temp -28,4 allocated
	# Register %al allocated
.Ll115:
	.stabn 68,0,306,.Ll115 - P$STATIC_MODA$$DOUBLE
# [306] for i:=1 to numdatos do
	movb	U_P$STATIC_NUMDATOS,%al
	# Register %al released
	movb	%al,-28(%ebp)
	movb	$1,-12(%ebp)
	# Register %al allocated
	movb	-12(%ebp),%al
	# Register %al released
	cmpb	-28(%ebp),%al
	ja	.L371
	subb	$1,-12(%ebp)
	.balign 4
.L372:
	addb	$1,-12(%ebp)
	# Register %eax allocated
.Ll116:
	.stabn 68,0,308,.Ll116 - P$STATIC_MODA$$DOUBLE
# [308] if (i>1) and (i <=2) then
	movzbl	-12(%ebp),%eax
	# Register %eax released
	cmpl	$1,%eax
	jg	.L375
	jmp	.L374
.L375:
	# Register %eax allocated
	movzbl	-12(%ebp),%eax
	# Register %eax released
	cmpl	$2,%eax
	jle	.L373
	jmp	.L374
.L373:
	# Register %edx allocated
.Ll117:
	.stabn 68,0,310,.Ll117 - P$STATIC_MODA$$DOUBLE
# [310] if (frec[i] > frec[i-1]) then
	movzbl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L378
	call	FPC_RANGEERROR
.L378:
	# Register %edx released
	# Register %ecx allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%ecx
	# Register %edx allocated
	movzbl	-12(%ebp),%edx
	subl	$1,%edx
	jno	.L379
	call	FPC_OVERFLOW
.L379:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L380
	call	FPC_RANGEERROR
.L380:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %ecx,%eax released
	cmpl	%eax,%ecx
	jg	.L376
	jmp	.L377
.L376:
	# Register %edx allocated
.Ll118:
	.stabn 68,0,312,.Ll118 - P$STATIC_MODA$$DOUBLE
# [312] tmp := frec[i];
	movzbl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L383
	call	FPC_RANGEERROR
.L383:
# Temp -32,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-32(%ebp)
	fildl	-32(%ebp)
# Temp -32,4 released
	fstpl	-24(%ebp)
	fwait
	# Register %al allocated
.Ll119:
	.stabn 68,0,313,.Ll119 - P$STATIC_MODA$$DOUBLE
# [313] idx := i
	movb	-12(%ebp),%al
	# Register %al released
	movb	%al,-16(%ebp)
	jmp	.L386
.L377:
	# Register %edx allocated
.Ll120:
	.stabn 68,0,317,.Ll120 - P$STATIC_MODA$$DOUBLE
# [317] tmp := frec[i+1];
	movzbl	-12(%ebp),%edx
	addl	$1,%edx
	jno	.L389
	call	FPC_OVERFLOW
.L389:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L390
	call	FPC_RANGEERROR
.L390:
# Temp -32,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-32(%ebp)
	fildl	-32(%ebp)
# Temp -32,4 released
	fstpl	-24(%ebp)
	fwait
	# Register %edx allocated
.Ll121:
	.stabn 68,0,318,.Ll121 - P$STATIC_MODA$$DOUBLE
# [318] idx := i+1
	movzbl	-12(%ebp),%edx
	addl	$1,%edx
	jno	.L393
	call	FPC_OVERFLOW
.L393:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L394
	call	FPC_RANGEERROR
.L394:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-16(%ebp)
.L386:
.L374:
	# Register %eax allocated
.Ll122:
	.stabn 68,0,321,.Ll122 - P$STATIC_MODA$$DOUBLE
# [321] if (i > 2) and (i <= numdatos) then
	movzbl	-12(%ebp),%eax
	# Register %eax released
	cmpl	$2,%eax
	jg	.L397
	jmp	.L396
.L397:
	# Register %eax allocated
	movzbl	-12(%ebp),%eax
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMDATOS,%edx
	# Register %eax,%edx released
	cmpl	%edx,%eax
	jbe	.L395
	jmp	.L396
.L395:
	# Register %edx allocated
.Ll123:
	.stabn 68,0,323,.Ll123 - P$STATIC_MODA$$DOUBLE
# [323] if (frec[i+1]> frec[i]) or (frec[i+1] > tmp) then
	movzbl	-12(%ebp),%edx
	addl	$1,%edx
	jno	.L401
	call	FPC_OVERFLOW
.L401:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L402
	call	FPC_RANGEERROR
.L402:
	# Register %edx released
	# Register %ecx allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%ecx
	# Register %edx allocated
	movzbl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L403
	call	FPC_RANGEERROR
.L403:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %ecx,%eax released
	cmpl	%eax,%ecx
	jg	.L398
	jmp	.L400
.L400:
	# Register %edx allocated
	movzbl	-12(%ebp),%edx
	addl	$1,%edx
	jno	.L404
	call	FPC_OVERFLOW
.L404:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L405
	call	FPC_RANGEERROR
.L405:
# Temp -32,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-32(%ebp)
	fildl	-32(%ebp)
# Temp -32,4 released
	fldl	-24(%ebp)
	fcompp
	# Register %ax allocated
	fnstsw	%ax
	sahf
	# Register %ax released
	jb	.L398
	jmp	.L399
.L398:
	# Register %edx allocated
.Ll124:
	.stabn 68,0,325,.Ll124 - P$STATIC_MODA$$DOUBLE
# [325] tmp := frec[i+1];
	movzbl	-12(%ebp),%edx
	addl	$1,%edx
	jno	.L408
	call	FPC_OVERFLOW
.L408:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L409
	call	FPC_RANGEERROR
.L409:
# Temp -32,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-32(%ebp)
	fildl	-32(%ebp)
# Temp -32,4 released
	fstpl	-24(%ebp)
	fwait
	# Register %edx allocated
.Ll125:
	.stabn 68,0,326,.Ll125 - P$STATIC_MODA$$DOUBLE
# [326] idx := i+1
	movzbl	-12(%ebp),%edx
	addl	$1,%edx
	jno	.L412
	call	FPC_OVERFLOW
.L412:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L413
	call	FPC_RANGEERROR
.L413:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-16(%ebp)
.L399:
.L396:
	# Register %al allocated
.Ll126:
	.stabn 68,0,306,.Ll126 - P$STATIC_MODA$$DOUBLE
	movb	-12(%ebp),%al
	# Register %al released
	cmpb	-28(%ebp),%al
	jb	.L372
# Temp -28,4 released
.L371:
	# Register %edx allocated
.Ll127:
	.stabn 68,0,330,.Ll127 - P$STATIC_MODA$$DOUBLE
# [330] if (2*frec[idx] - frec[idx-1] - frec[idx+1])<> 0 then
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L416
	call	FPC_RANGEERROR
.L416:
	# Register %edx released
	# Register %ecx allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%ecx
	imull	$2,%ecx
	jno	.L417
	call	FPC_OVERFLOW
.L417:
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	subl	$1,%edx
	jno	.L418
	call	FPC_OVERFLOW
.L418:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L419
	call	FPC_RANGEERROR
.L419:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	subl	%eax,%ecx
	jno	.L420
	call	FPC_OVERFLOW
.L420:
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	addl	$1,%edx
	jno	.L421
	call	FPC_OVERFLOW
.L421:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L422
	call	FPC_RANGEERROR
.L422:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	subl	%eax,%ecx
	jno	.L423
	call	FPC_OVERFLOW
.L423:
	# Register %ecx released
	testl	%ecx,%ecx
	jne	.L414
	jmp	.L415
.L414:
	# Register %edx allocated
.Ll128:
	.stabn 68,0,331,.Ll128 - P$STATIC_MODA$$DOUBLE
# [331] moda := IntervI[idx] + (frec[idx]-frec[idx-1])*
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L426
	call	FPC_RANGEERROR
.L426:
	# Register %edx released
	# Register %ecx allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%ecx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	subl	$1,%edx
	jno	.L427
	call	FPC_OVERFLOW
.L427:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L428
	call	FPC_RANGEERROR
.L428:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	subl	%eax,%ecx
	jno	.L429
	call	FPC_OVERFLOW
.L429:
	# Register %edx allocated
.Ll129:
	.stabn 68,0,332,.Ll129 - P$STATIC_MODA$$DOUBLE
# [332] (intervD[idx] - IntervI[idx])/ (2*frec[idx] - frec[idx-1] - frec[idx+1]);
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L430
	call	FPC_RANGEERROR
.L430:
	# Register %edx released
	# Register %ebx allocated
	movswl	U_P$STATIC_INTERVD-2(,%edx,2),%ebx
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L431
	call	FPC_RANGEERROR
.L431:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVI-2(,%edx,2),%eax
	# Register %eax released
	subl	%eax,%ebx
	jno	.L432
	call	FPC_OVERFLOW
.L432:
	# Register %ecx released
.Ll130:
	.stabn 68,0,331,.Ll130 - P$STATIC_MODA$$DOUBLE
	imull	%ecx,%ebx
	jno	.L433
	call	FPC_OVERFLOW
.L433:
# Temp -32,4 allocated
	# Register %ebx released
	movl	%ebx,-32(%ebp)
	fildl	-32(%ebp)
# Temp -32,4 released
	# Register %edx allocated
.Ll131:
	.stabn 68,0,332,.Ll131 - P$STATIC_MODA$$DOUBLE
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L434
	call	FPC_RANGEERROR
.L434:
	# Register %edx released
	# Register %ecx allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%ecx
	imull	$2,%ecx
	jno	.L435
	call	FPC_OVERFLOW
.L435:
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	subl	$1,%edx
	jno	.L436
	call	FPC_OVERFLOW
.L436:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L437
	call	FPC_RANGEERROR
.L437:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	subl	%eax,%ecx
	jno	.L438
	call	FPC_OVERFLOW
.L438:
	# Register %edx allocated
	movzbl	-16(%ebp),%edx
	addl	$1,%edx
	jno	.L439
	call	FPC_OVERFLOW
.L439:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L440
	call	FPC_RANGEERROR
.L440:
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	subl	%eax,%ecx
	jno	.L441
	call	FPC_OVERFLOW
.L441:
# Temp -32,4 allocated
	# Register %ecx released
	movl	%ecx,-32(%ebp)
	fildl	-32(%ebp)
# Temp -32,4 released
	fdivrp	%st,%st(1)
	# Register %edx allocated
.Ll132:
	.stabn 68,0,331,.Ll132 - P$STATIC_MODA$$DOUBLE
	movzbl	-16(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L442
	call	FPC_RANGEERROR
.L442:
# Temp -32,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVI-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-32(%ebp)
	fildl	-32(%ebp)
# Temp -32,4 released
	faddp	%st,%st(1)
	fstpl	-8(%ebp)
	fwait
.L415:
.Ll133:
	.stabn 68,0,334,.Ll133 - P$STATIC_MODA$$DOUBLE
# [334] end; { moda }
	fldl	-8(%ebp)
# Temp -8,8 released
# Temp -12,4 released
# Temp -16,4 released
# Temp -24,8 released
	# Register %ebx allocated
	movl	-36(%ebp),%ebx
# Temp -36,4 released
	leave
	# Register %ebp released
	ret
.L448:
	.stabs "MODA:X11",160,0,0,-8
	.stabn 192,0,0,P$STATIC_MODA$$DOUBLE-P$STATIC_MODA$$DOUBLE
	.stabn 224,0,0,.L448-P$STATIC_MODA$$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "MEDIAGEOM:F11",36,0,341,P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE
	.stabs "TOTFLPM:p11",160,0,341,8
	.stabs "result:11",160,0,341,-8
.Ll134:
	.stabn 68,0,342,.Ll134 - P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE
# [342] begin
.globl	P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE
P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE:
# Temps allocated between ebp-12 and ebp-8
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$12,%esp
# Var totflpm located at ebp+8
# Temp -8,8 allocated
# Var $result located at ebp-8
	# Register %eax allocated
	movl	$12,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll135:
	.stabn 68,0,343,.Ll135 - P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE
# [343] MediaGeom := power(10,totflpm/numdatos);
	fldl	8(%ebp)
# Temp -12,4 allocated
	# Register %eax allocated
	movzbl	U_P$STATIC_NUMDATOS,%eax
	# Register %eax released
	movl	%eax,-12(%ebp)
	fildl	-12(%ebp)
# Temp -12,4 released
	fdivrp	%st,%st(1)
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	movzwl	_$PROGRAM$_L457+8,%eax
	# Register %eax released
	pushl	%eax
	pushl	_$PROGRAM$_L457+4
	pushl	_$PROGRAM$_L457
	# Register %eax,%ecx,%edx allocated
	call	MATH_POWER$EXTENDED$EXTENDED$$EXTENDED
	# Register %eax,%ecx,%edx released
	fstpl	-8(%ebp)
	fwait
.Ll136:
	.stabn 68,0,344,.Ll136 - P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE
# [344] end; { MediaGeom }
	fldl	-8(%ebp)
# Temp -8,8 released
	leave
	# Register %ebp released
	ret	$8
.L463:
	.stabs "MEDIAGEOM:X11",160,0,0,-8
	.stabn 192,0,0,P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE-P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE
	.stabn 224,0,0,.L463-P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "MEDIAARM:F11",36,0,350,P$STATIC_MEDIAARM$DOUBLE$$DOUBLE
	.stabs "TOTFXIPM:p11",160,0,350,8
	.stabs "result:11",160,0,350,-8
.Ll137:
	.stabn 68,0,351,.Ll137 - P$STATIC_MEDIAARM$DOUBLE$$DOUBLE
# [351] begin
.globl	P$STATIC_MEDIAARM$DOUBLE$$DOUBLE
P$STATIC_MEDIAARM$DOUBLE$$DOUBLE:
# Temps allocated between ebp-12 and ebp-8
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$12,%esp
# Var TotFxIPM located at ebp+8
# Temp -8,8 allocated
# Var $result located at ebp-8
	# Register %eax allocated
	movl	$12,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
# Temp -12,4 allocated
	# Register %eax allocated
.Ll138:
	.stabn 68,0,352,.Ll138 - P$STATIC_MEDIAARM$DOUBLE$$DOUBLE
# [352] MediaArm:=numdatos/(TotFxIPM);
	movzbl	U_P$STATIC_NUMDATOS,%eax
	# Register %eax released
	movl	%eax,-12(%ebp)
	fildl	-12(%ebp)
# Temp -12,4 released
	fldl	8(%ebp)
	fdivrp	%st,%st(1)
	fstpl	-8(%ebp)
	fwait
.Ll139:
	.stabn 68,0,353,.Ll139 - P$STATIC_MEDIAARM$DOUBLE$$DOUBLE
# [353] end;
	fldl	-8(%ebp)
# Temp -8,8 released
	leave
	# Register %ebp released
	ret	$8
.L473:
	.stabs "MEDIAARM:X11",160,0,0,-8
	.stabn 192,0,0,P$STATIC_MEDIAARM$DOUBLE$$DOUBLE-P$STATIC_MEDIAARM$DOUBLE$$DOUBLE
	.stabn 224,0,0,.L473-P$STATIC_MEDIAARM$DOUBLE$$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "VARIANZA:F11",36,0,359,P$STATIC_VARIANZA$DOUBLE$$DOUBLE
	.stabs "TOTFXX2:p11",160,0,359,8
	.stabs "result:11",160,0,359,-8
.Ll140:
	.stabn 68,0,360,.Ll140 - P$STATIC_VARIANZA$DOUBLE$$DOUBLE
# [360] begin
.globl	P$STATIC_VARIANZA$DOUBLE$$DOUBLE
P$STATIC_VARIANZA$DOUBLE$$DOUBLE:
# Temps allocated between ebp-12 and ebp-8
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$12,%esp
# Var totFxX2 located at ebp+8
# Temp -8,8 allocated
# Var $result located at ebp-8
	# Register %eax allocated
	movl	$12,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll141:
	.stabn 68,0,361,.Ll141 - P$STATIC_VARIANZA$DOUBLE$$DOUBLE
# [361] Varianza :=  TotFxX2/numdatos;
	fldl	8(%ebp)
# Temp -12,4 allocated
	# Register %eax allocated
	movzbl	U_P$STATIC_NUMDATOS,%eax
	# Register %eax released
	movl	%eax,-12(%ebp)
	fildl	-12(%ebp)
# Temp -12,4 released
	fdivrp	%st,%st(1)
	fstpl	-8(%ebp)
	fwait
.Ll142:
	.stabn 68,0,362,.Ll142 - P$STATIC_VARIANZA$DOUBLE$$DOUBLE
# [362] end;
	fldl	-8(%ebp)
# Temp -8,8 released
	leave
	# Register %ebp released
	ret	$8
.L483:
	.stabs "VARIANZA:X11",160,0,0,-8
	.stabn 192,0,0,P$STATIC_VARIANZA$DOUBLE$$DOUBLE-P$STATIC_VARIANZA$DOUBLE$$DOUBLE
	.stabn 224,0,0,.L483-P$STATIC_VARIANZA$DOUBLE$$DOUBLE

.section .text
	.balign 4
	.balign 4
	.stabs "PARSE:F8",36,0,370,P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
	.stabs "LIN:p1",160,0,370,-552
	.stabs "FASE:p28",160,0,370,-8
	.stabs "INDEX:p21",160,0,370,-12
	.stabs "SUBSTR:1",160,0,372,-268
	.stabs "NUM:11",160,0,373,-276
	.stabs "CODE:29",160,0,374,-280
	.stabs "IL:21",160,0,375,-284
	.stabs "IR:21",160,0,375,-288
	.stabs "POSS:30",160,0,376,-292
	.stabs "POSL:30",160,0,376,-296
.Ll143:
	.stabn 68,0,377,.Ll143 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [377] begin
.globl	P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT:
# Temps allocated between ebp-1120 and ebp-296
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$1120,%esp
# Temp -1120,12 allocated
	movl	%ebx,-1120(%ebp)
	movl	%esi,-1116(%ebp)
	movl	%edi,-1112(%ebp)
# Temp -4,4 allocated
# Var lin located at ebp-4
# Temp -8,4 allocated
# Var fase located at ebp-8
# Temp -12,4 allocated
# Var index located at ebp-12
# Temp -268,256 allocated
# Var substr located at ebp-268
# Temp -276,8 allocated
# Var num located at ebp-276
# Temp -280,4 allocated
# Var code located at ebp-280
# Temp -284,4 allocated
# Var IL located at ebp-284
# Temp -288,4 allocated
# Var IR located at ebp-288
# Temp -292,4 allocated
# Var poss located at ebp-292
# Temp -296,4 allocated
# Var posl located at ebp-296
	# Register %eax,%dl,%cx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %dl released
	movb	%dl,-8(%ebp)
	# Register %cx released
	movw	%cx,-12(%ebp)
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
# Temp -552,256 allocated
	# Register %ecx,%eax allocated
	leal	-552(%ebp),%eax
	# Register %eax released
	movl	%eax,%ecx
	# Register %ebx released
	# Register %edx,%ebx allocated
	# Register %ebx released
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	FPC_SHORTSTR_ASSIGN
	# Register %eax,%ecx,%edx released
# Temp -4,4 released
	# Register %eax allocated
	movl	$1120,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll144:
	.stabn 68,0,377,.Ll144 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
	movl	$0,-852(%ebp)
	movl	$0,-848(%ebp)
# Temp -564,12 allocated
# Temp -588,24 allocated
# Temp -4,4 allocated
	# Register %ecx,%eax allocated
	leal	-564(%ebp),%eax
	# Register %eax released
	movl	%eax,%ecx
	# Register %edx,%eax allocated
	leal	-588(%ebp),%eax
	# Register %eax released
	movl	%eax,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	FPC_PUSHEXCEPTADDR
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_SETJMP
	# Register %eax,%ecx,%edx released
	pushl	%eax
	testl	%eax,%eax
	jne	.L486
	# Register %al allocated
.Ll145:
	.stabn 68,0,378,.Ll145 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [378] case fase of
	movb	-8(%ebp),%al
	cmpb	$99,%al
	jb	.L490
	subb	$99,%al
	je	.L493
	subb	$1,%al
	je	.L492
	# Register %al released
	subb	$5,%al
	je	.L491
	jmp	.L490
.L491:
	# Register %edx allocated
.Ll146:
	.stabn 68,0,381,.Ll146 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [381] poss := pos(' ',lin);
	leal	-552(%ebp),%edx
	# Register %al allocated
	movb	$32,%al
	# Register %edx,%al released
	# Register %eax,%ecx,%edx allocated
	call	SYSTEM_POS$CHAR$SHORTSTRING$$LONGINT
	# Register %ecx,%edx,%eax released
	movl	%eax,-292(%ebp)
	# Register %edx allocated
.Ll147:
	.stabn 68,0,382,.Ll147 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [382] posl := pos('<',lin);
	leal	-552(%ebp),%edx
	# Register %al allocated
	movb	$60,%al
	# Register %edx,%al released
	# Register %eax,%ecx,%edx allocated
	call	SYSTEM_POS$CHAR$SHORTSTRING$$LONGINT
	# Register %ecx,%edx,%eax released
	movl	%eax,-296(%ebp)
	# Register %eax allocated
.Ll148:
	.stabn 68,0,383,.Ll148 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [383] if ((poss < posl) and (poss<>0)) then
	movl	-292(%ebp),%eax
	# Register %eax released
	cmpl	-296(%ebp),%eax
	jl	.L508
	jmp	.L507
.L508:
	# Register %eax allocated
	movl	-292(%ebp),%eax
	# Register %eax released
	testl	%eax,%eax
	jne	.L506
	jmp	.L507
.L506:
	# Register %ebx allocated
.Ll149:
	.stabn 68,0,384,.Ll149 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [384] substr := copy(lin,1,poss-1)
	leal	-268(%ebp),%ebx
# Temp -844,256 allocated
	# Register %eax allocated
	leal	-844(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	-292(%ebp),%ecx
	subl	$1,%ecx
	jno	.L517
	call	FPC_OVERFLOW
.L517:
	# Register %edx allocated
	movl	$1,%edx
	# Register %eax allocated
	leal	-552(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx released
	leal	-844(%ebp),%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ebx released
	# Register %ecx allocated
	movl	%ebx,%ecx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
# Temp -844,256 released
	jmp	.L524
.L507:
	# Register %ebx allocated
.Ll150:
	.stabn 68,0,386,.Ll150 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [386] substr := copy(lin,1,posl-1);
	leal	-268(%ebp),%ebx
# Temp -844,256 allocated
	# Register %eax allocated
	leal	-844(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	-296(%ebp),%ecx
	subl	$1,%ecx
	jno	.L533
	call	FPC_OVERFLOW
.L533:
	# Register %edx allocated
	movl	$1,%edx
	# Register %eax allocated
	leal	-552(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx released
	leal	-844(%ebp),%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ebx released
	# Register %ecx allocated
	movl	%ebx,%ecx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
# Temp -844,256 released
.L524:
# Temp -844,4 allocated
	# Register %ecx allocated
.Ll151:
	.stabn 68,0,387,.Ll151 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [387] val(substr,IL,code);
	leal	-844(%ebp),%ecx
	# Register %edx allocated
	leal	-268(%ebp),%edx
	# Register %eax allocated
	movl	$2,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_val_sint_shortstr
	# Register %ecx released
	movl	%eax,%edx
	subl	$-32768,%edx
	# Register %edx released
	cmpl	$65535,%edx
	jbe	.L548
	call	FPC_RANGEERROR
.L548:
	# Register %eax released
	# Register %ax allocated
	# Register %ax released
	movw	%ax,-284(%ebp)
	# Register %eax allocated
	movl	-844(%ebp),%eax
	# Register %eax released
	cmpl	$65535,%eax
	jbe	.L551
	call	FPC_RANGEERROR
.L551:
	# Register %ax allocated
	movw	-844(%ebp),%ax
	# Register %ax released
	movw	%ax,-280(%ebp)
# Temp -844,4 released
	# Register %eax allocated
.Ll152:
	.stabn 68,0,388,.Ll152 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [388] if code = 0 then
	movzwl	-280(%ebp),%eax
	# Register %eax released
	testl	%eax,%eax
	je	.L552
	jmp	.L553
.L552:
	# Register %ebx allocated
.Ll153:
	.stabn 68,0,390,.Ll153 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [390] substr := copy(lin,pos('<',lin)+1,64);
	leal	-268(%ebp),%ebx
# Temp -844,256 allocated
	# Register %eax allocated
	leal	-844(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %esi allocated
	movl	$64,%esi
	# Register %edx allocated
	leal	-552(%ebp),%edx
	# Register %al allocated
	movb	$60,%al
	# Register %edx,%al released
	# Register %eax,%ecx,%edx allocated
	call	SYSTEM_POS$CHAR$SHORTSTRING$$LONGINT
	# Register %ecx,%edx,%eax released
	# Register %edx allocated
	movl	%eax,%edx
	addl	$1,%edx
	jno	.L568
	call	FPC_OVERFLOW
.L568:
	# Register %eax allocated
	leal	-552(%ebp),%eax
	# Register %esi released
	# Register %ecx allocated
	movl	%esi,%ecx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx released
	leal	-844(%ebp),%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ebx released
	# Register %ecx allocated
	movl	%ebx,%ecx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
# Temp -844,256 released
# Temp -844,4 allocated
	# Register %ecx allocated
.Ll154:
	.stabn 68,0,391,.Ll154 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [391] val(substr,IR,code);
	leal	-844(%ebp),%ecx
	# Register %edx allocated
	leal	-268(%ebp),%edx
	# Register %eax allocated
	movl	$2,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_val_sint_shortstr
	# Register %ecx released
	movl	%eax,%edx
	subl	$-32768,%edx
	# Register %edx released
	cmpl	$65535,%edx
	jbe	.L581
	call	FPC_RANGEERROR
.L581:
	# Register %eax released
	# Register %ax allocated
	# Register %ax released
	movw	%ax,-288(%ebp)
	# Register %eax allocated
	movl	-844(%ebp),%eax
	# Register %eax released
	cmpl	$65535,%eax
	jbe	.L584
	call	FPC_RANGEERROR
.L584:
	# Register %ax allocated
	movw	-844(%ebp),%ax
	# Register %ax released
	movw	%ax,-280(%ebp)
# Temp -844,4 released
	# Register %edx allocated
.Ll155:
	.stabn 68,0,392,.Ll155 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [392] intervD[index]:=IR;
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L587
	call	FPC_RANGEERROR
.L587:
	# Register %ax allocated
	movw	-288(%ebp),%ax
	# Register %edx,%ax released
	movw	%ax,U_P$STATIC_INTERVD-2(,%edx,2)
	# Register %edx allocated
.Ll156:
	.stabn 68,0,393,.Ll156 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [393] intervI[index]:=IL;
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L590
	call	FPC_RANGEERROR
.L590:
	# Register %ax allocated
	movw	-284(%ebp),%ax
	# Register %edx,%ax released
	movw	%ax,U_P$STATIC_INTERVI-2(,%edx,2)
	# Register %eax allocated
.Ll157:
	.stabn 68,0,394,.Ll157 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [394] numinterv:=index; {establece total de intervalos}
	movswl	-12(%ebp),%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L593
	call	FPC_RANGEERROR
.L593:
	# Register %al allocated
	movb	-12(%ebp),%al
	# Register %al released
	movb	%al,U_P$STATIC_NUMINTERV
.L553:
	jmp	.L489
.L492:
	# Register %ecx allocated
.Ll158:
	.stabn 68,0,399,.Ll158 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [399] substr := lin;
	leal	-268(%ebp),%ecx
	# Register %edx allocated
	leal	-552(%ebp),%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
# Temp -844,4 allocated
	# Register %edx allocated
.Ll159:
	.stabn 68,0,400,.Ll159 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [400] val(lin,num,code);
	leal	-844(%ebp),%edx
	# Register %eax allocated
	leal	-552(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_val_real_shortstr
	# Register %eax,%ecx,%edx released
	fstpl	-276(%ebp)
	fwait
	# Register %eax allocated
	movl	-844(%ebp),%eax
	# Register %eax released
	cmpl	$65535,%eax
	jbe	.L608
	call	FPC_RANGEERROR
.L608:
	# Register %ax allocated
	movw	-844(%ebp),%ax
	# Register %ax released
	movw	%ax,-280(%ebp)
# Temp -844,4 released
	# Register %eax allocated
.Ll160:
	.stabn 68,0,401,.Ll160 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [401] if code = 0 then
	movzwl	-280(%ebp),%eax
	# Register %eax released
	testl	%eax,%eax
	je	.L609
	jmp	.L610
.L609:
	# Register %edx allocated
.Ll161:
	.stabn 68,0,403,.Ll161 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [403] datos[index]:=num;
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L613
	call	FPC_RANGEERROR
.L613:
	# Register %eax allocated
	movl	-276(%ebp),%eax
	# Register %eax released
	movl	%eax,U_P$STATIC_DATOS-8(,%edx,8)
	# Register %eax allocated
	movl	-272(%ebp),%eax
	# Register %edx,%eax released
	movl	%eax,U_P$STATIC_DATOS-4(,%edx,8)
	# Register %eax allocated
.Ll162:
	.stabn 68,0,404,.Ll162 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [404] numdatos:=index; {establece total de datos}
	movswl	-12(%ebp),%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L616
	call	FPC_RANGEERROR
.L616:
	# Register %al allocated
	movb	-12(%ebp),%al
	# Register %al released
	movb	%al,U_P$STATIC_NUMDATOS
.L610:
	jmp	.L489
.L493:
	# Register %ebx allocated
.Ll163:
	.stabn 68,0,409,.Ll163 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [409] substr:=DelSpace(copy(upcase(lin),1,9));
	leal	-268(%ebp),%ebx
# Temp -848,4 allocated
	# Register %eax,%edx allocated
	leal	-848(%ebp),%edx
	# Register %edx released
	movl	%edx,%eax
	# Register %ecx,%edx allocated
	call	FPC_ANSISTR_DECR_REF
	# Register %eax,%ecx,%edx released
# Temp -852,4 allocated
	# Register %eax,%edx allocated
	leal	-852(%ebp),%edx
	# Register %edx released
	movl	%edx,%eax
	# Register %ecx,%edx allocated
	call	FPC_ANSISTR_DECR_REF
	# Register %eax,%ecx,%edx released
# Temp -844,256 allocated
	# Register %eax allocated
	leal	-844(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %edi allocated
	movl	$9,%edi
	# Register %esi allocated
	movl	$1,%esi
# Temp -1108,256 allocated
	# Register %edx allocated
	leal	-1108(%ebp),%edx
	# Register %eax allocated
	leal	-552(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	SYSTEM_UPCASE$SHORTSTRING$$SHORTSTRING
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1108(%ebp),%eax
	# Register %edi released
	# Register %ecx allocated
	movl	%edi,%ecx
	# Register %esi released
	# Register %edx allocated
	movl	%esi,%edx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx,%edx released
# Temp -1108,256 released
	# Register %eax allocated
	leal	-844(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_ansistr
	# Register %ecx,%edx,%eax released
	movl	%eax,-852(%ebp)
# Temp -844,256 released
	# Register %eax allocated
	movl	-852(%ebp),%eax
	# Register %ecx,%edx allocated
	call	STRUTILS_DELSPACE$ANSISTRING$$ANSISTRING
	# Register %ecx,%edx,%eax released
	movl	%eax,-848(%ebp)
# Temp -852,4 released
	# Register %edx allocated
	movl	-848(%ebp),%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ebx released
	# Register %ecx allocated
	movl	%ebx,%ecx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_ansistr_to_shortstr
	# Register %eax,%ecx,%edx released
# Temp -848,4 released
	# Register %eax,%ecx,%edx allocated
.Ll164:
	.stabn 68,0,411,.Ll164 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [411] writeln(' fase: ',fase,' index: ',index,' linea: ',substr);
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %esi allocated
	movl	%eax,%esi
	# Register %ecx allocated
	movl	$_$PROGRAM$_L643,%ecx
	# Register %edx allocated
	movl	%esi,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	-8(%ebp),%cl
	# Register %eax allocated
	movl	%esi,%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L656,%ecx
	# Register %edx allocated
	movl	%esi,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %edx allocated
	movl	%esi,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_sint
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L669,%ecx
	# Register %edx allocated
	movl	%esi,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	leal	-268(%ebp),%ecx
	# Register %edx allocated
	movl	%esi,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%esi,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%esi released
	# Register %edx allocated
.Ll165:
	.stabn 68,0,413,.Ll165 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [413] if substr = 'MEDIAARI' then calcular[1] := true;
	movl	$_$PROGRAM$_L686,%edx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L682
	jmp	.L683
.L682:
	movb	$1,U_P$STATIC_CALCULAR
.L683:
	# Register %edx allocated
.Ll166:
	.stabn 68,0,414,.Ll166 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [414] if substr = 'MEDIANA'  then calcular[2] := true;
	movl	$_$PROGRAM$_L695,%edx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L691
	jmp	.L692
.L691:
	movb	$1,U_P$STATIC_CALCULAR+1
.L692:
	# Register %edx allocated
.Ll167:
	.stabn 68,0,415,.Ll167 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [415] if substr = 'MODA' then calcular[3]  := true;
	movl	$_$PROGRAM$_L704,%edx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L700
	jmp	.L701
.L700:
	movb	$1,U_P$STATIC_CALCULAR+2
.L701:
	# Register %edx allocated
.Ll168:
	.stabn 68,0,416,.Ll168 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [416] if substr = 'MEDIAARM' then calcular[4]:= true;
	movl	$_$PROGRAM$_L713,%edx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L709
	jmp	.L710
.L709:
	movb	$1,U_P$STATIC_CALCULAR+3
.L710:
	# Register %edx allocated
.Ll169:
	.stabn 68,0,417,.Ll169 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [417] if substr = 'MEDIAGEO' then calcular[5] := true;
	movl	$_$PROGRAM$_L722,%edx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L718
	jmp	.L719
.L718:
	movb	$1,U_P$STATIC_CALCULAR+4
.L719:
	# Register %edx allocated
.Ll170:
	.stabn 68,0,418,.Ll170 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [418] if substr = 'VARIANZA' then calcular[6] := true;
	movl	$_$PROGRAM$_L731,%edx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L727
	jmp	.L728
.L727:
	movb	$1,U_P$STATIC_CALCULAR+5
.L728:
	# Register %edx allocated
.Ll171:
	.stabn 68,0,419,.Ll171 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [419] if substr = 'DESVIACI' then calcular[7] := true;
	movl	$_$PROGRAM$_L740,%edx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L736
	jmp	.L737
.L736:
	movb	$1,U_P$STATIC_CALCULAR+6
.L737:
	jmp	.L489
.L490:
.L489:
.L486:
	# Register %eax,%ecx,%edx allocated
.Ll172:
	.stabn 68,0,377,.Ll172 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
	call	FPC_POPADDRSTACK
	# Register %eax,%ecx,%edx released
	# Register %eax,%edx allocated
.Ll173:
	.stabn 68,0,422,.Ll173 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
# [422] end;
	leal	-852(%ebp),%edx
	# Register %edx released
	movl	%edx,%eax
	# Register %ecx,%edx allocated
	call	FPC_ANSISTR_DECR_REF
	# Register %eax,%ecx,%edx released
	movl	$0,-852(%ebp)
	# Register %eax,%edx allocated
	leal	-848(%ebp),%edx
	# Register %edx released
	movl	%edx,%eax
	# Register %ecx,%edx allocated
	call	FPC_ANSISTR_DECR_REF
	# Register %eax,%ecx,%edx released
	movl	$0,-848(%ebp)
.Ll174:
	.stabn 68,0,377,.Ll174 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
	popl	%eax
	testl	%eax,%eax
	je	.L487
	call	FPC_RERAISE
# Temp -588,24 released
# Temp -564,12 released
# Temp -4,4 released
.L487:
# Temp -268,256 released
# Temp -276,8 released
# Temp -280,4 released
# Temp -284,4 released
# Temp -288,4 released
# Temp -292,4 released
# Temp -296,4 released
# Temp -552,256 released
# Temp -8,4 released
# Temp -12,4 released
	# Register %ebx allocated
.Ll175:
	.stabn 68,0,422,.Ll175 - P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
	movl	-1120(%ebp),%ebx
	# Register %esi allocated
	movl	-1116(%ebp),%esi
	# Register %edi allocated
	movl	-1112(%ebp),%edi
# Temp -1120,12 released
	leave
	# Register %ebp released
	ret
.L750:
	.stabn 192,0,0,P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT-P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
	.stabn 224,0,0,.L750-P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT

.section .text
	.balign 4
	.balign 4
	.stabs "INPUTFILE:F32",36,0,429,P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
	.stabs "PATH:p1",160,0,429,-796
	.stabs "result:32",160,0,429,-8
	.stabs "LINEA:1",160,0,431,-264
	.stabs "I:21",160,0,432,-268
	.stabs "J:21",160,0,432,-272
	.stabs "FASE:28",160,0,434,-276
	.stabs "COMANDO:1",160,0,435,-532
	.stabs "EXISTE:21",160,0,436,-536
.Ll176:
	.stabn 68,0,438,.Ll176 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [438] begin
.globl	P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN:
# Temps allocated between ebp-1320 and ebp-540
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$1320,%esp
# Temp -1320,12 allocated
	movl	%ebx,-1320(%ebp)
	movl	%esi,-1316(%ebp)
	movl	%edi,-1312(%ebp)
# Temp -4,4 allocated
# Var path located at ebp-4
# Temp -8,4 allocated
# Var $result located at ebp-8
# Temp -264,256 allocated
# Var linea located at ebp-264
# Temp -268,4 allocated
# Var i located at ebp-268
# Temp -272,4 allocated
# Var j located at ebp-272
# Temp -276,4 allocated
# Var fase located at ebp-276
# Temp -532,256 allocated
# Var comando located at ebp-532
# Temp -536,4 allocated
# Var existe located at ebp-536
# Temp -540,4 allocated
# Var Strvalor located at ebp-540
	# Register %eax allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
# Temp -796,256 allocated
	# Register %ecx,%eax allocated
	leal	-796(%ebp),%eax
	# Register %eax released
	movl	%eax,%ecx
	# Register %ebx released
	# Register %edx,%ebx allocated
	# Register %ebx released
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	FPC_SHORTSTR_ASSIGN
	# Register %eax,%ecx,%edx released
# Temp -4,4 released
	# Register %eax allocated
	movl	$1320,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
.Ll177:
	.stabn 68,0,439,.Ll177 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [439] i := 1;
	movw	$1,-268(%ebp)
.Ll178:
	.stabn 68,0,440,.Ll178 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [440] j := 1;
	movw	$1,-272(%ebp)
.Ll179:
	.stabn 68,0,441,.Ll179 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [441] fase := '0';
	movb	$48,-276(%ebp)
	# Register %edx allocated
.Ll180:
	.stabn 68,0,442,.Ll180 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [442] assign(entrada,path);
	leal	-796(%ebp),%edx
	# Register %eax allocated
	movl	$U_P$STATIC_ENTRADA,%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	SYSTEM_ASSIGN$TEXT$SHORTSTRING
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll181:
	.stabn 68,0,444,.Ll181 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [444] reset(entrada);
	movl	$U_P$STATIC_ENTRADA,%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_RESET$TEXT
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll182:
	.stabn 68,0,445,.Ll182 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [445] existe:=IOresult;
	call	SYSTEM_IORESULT$$WORD
	# Register %ecx released
	movzwl	%ax,%edx
	# Register %edx released
	cmpl	$32767,%edx
	jbe	.L767
	call	FPC_RANGEERROR
.L767:
	# Register %ax released
	movw	%ax,-536(%ebp)
	# Register %eax allocated
.Ll183:
	.stabn 68,0,447,.Ll183 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [447] if existe<>0 then
	movswl	-536(%ebp),%eax
	# Register %eax released
	testl	%eax,%eax
	jne	.L768
	jmp	.L769
.L768:
	# Register %eax,%ecx,%edx allocated
.Ll184:
	.stabn 68,0,449,.Ll184 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [449] writeln('archivo no existe');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L774,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
.Ll185:
	.stabn 68,0,450,.Ll185 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [450] inputfile:=false;
	movb	$0,-8(%ebp)
	jmp	.L783
.L769:
.Ll186:
	.stabn 68,0,454,.Ll186 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [454] numinterv :=0;
	movb	$0,U_P$STATIC_NUMINTERV
.Ll187:
	.stabn 68,0,455,.Ll187 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [455] numdatos:=0;
	movb	$0,U_P$STATIC_NUMDATOS
	# Register %eax,%ecx,%edx allocated
.Ll188:
	.stabn 68,0,456,.Ll188 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [456] writeln('Leyendo y Analizando el archivo de texto dado...');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L792,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
.Ll189:
	.stabn 68,0,457,.Ll189 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [457] while not eof(entrada) do
	jmp	.L800
	.balign 4
.L799:
	# Register %ecx allocated
.Ll190:
	.stabn 68,0,459,.Ll190 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [459] readln(entrada,linea);  {lee linea}
	movl	$255,%ecx
	# Register %edx allocated
	leal	-264(%ebp),%edx
	# Register %eax allocated
	movl	$U_P$STATIC_ENTRADA,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_read_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	$U_P$STATIC_ENTRADA,%eax
	# Register %ecx,%edx allocated
	call	fpc_readln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ebx allocated
.Ll191:
	.stabn 68,0,460,.Ll191 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [460] comando := copy(upcase(linea),1,6); {genera comando}
	leal	-532(%ebp),%ebx
# Temp -1052,256 allocated
	# Register %eax allocated
	leal	-1052(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %edi allocated
	movl	$6,%edi
	# Register %esi allocated
	movl	$1,%esi
# Temp -1308,256 allocated
	# Register %edx allocated
	leal	-1308(%ebp),%edx
	# Register %eax allocated
	leal	-264(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	SYSTEM_UPCASE$SHORTSTRING$$SHORTSTRING
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1308(%ebp),%eax
	# Register %edi released
	# Register %ecx allocated
	movl	%edi,%ecx
	# Register %esi released
	# Register %edx allocated
	movl	%esi,%edx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx,%edx released
# Temp -1308,256 released
	# Register %edx allocated
	leal	-1052(%ebp),%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ebx released
	# Register %ecx allocated
	movl	%ebx,%ecx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
# Temp -1052,256 released
	# Register %eax,%ecx,%edx allocated
.Ll192:
	.stabn 68,0,461,.Ll192 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [461] {$ifdef debug}      writeln(comando); {$endif}
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	leal	-532(%ebp),%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %edx allocated
.Ll193:
	.stabn 68,0,464,.Ll193 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [464] if comando = 'TITULO' then
	movl	$_$PROGRAM$_L842,%edx
	# Register %eax allocated
	leal	-532(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L838
	jmp	.L839
.L838:
	# Register %ebx allocated
.Ll194:
	.stabn 68,0,466,.Ll194 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [466] titulo := upcase(copy(linea,8,max)); {Copia el Titulo principal}
	movl	$U_P$STATIC_TITULO,%ebx
# Temp -1308,256 allocated
	# Register %esi allocated
	leal	-1308(%ebp),%esi
# Temp -1052,256 allocated
	# Register %eax allocated
	leal	-1052(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$255,%ecx
	# Register %edx allocated
	movl	$8,%edx
	# Register %eax allocated
	leal	-264(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1052(%ebp),%eax
	# Register %esi released
	# Register %edx allocated
	movl	%esi,%edx
	# Register %edx released
	# Register %ecx,%edx allocated
	call	SYSTEM_UPCASE$SHORTSTRING$$SHORTSTRING
	# Register %eax,%ecx,%edx released
# Temp -1052,256 released
	# Register %edx allocated
	leal	-1308(%ebp),%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ebx released
	# Register %ecx allocated
	movl	%ebx,%ecx
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
# Temp -1308,256 released
	# Register %eax,%ecx,%edx allocated
.Ll195:
	.stabn 68,0,468,.Ll195 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [468] writeln('titulo:',titulo);
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L867,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$U_P$STATIC_TITULO,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %ax allocated
.Ll196:
	.stabn 68,0,470,.Ll196 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [470] j := i;
	movw	-268(%ebp),%ax
	# Register %ax released
	movw	%ax,-272(%ebp)
.L839:
	# Register %edx allocated
.Ll197:
	.stabn 68,0,472,.Ll197 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [472] if comando = 'INTERV' then
	movl	$_$PROGRAM$_L886,%edx
	# Register %eax allocated
	leal	-532(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L882
	jmp	.L883
.L882:
.Ll198:
	.stabn 68,0,474,.Ll198 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [474] fase := 'i';
	movb	$105,-276(%ebp)
	# Register %ax allocated
.Ll199:
	.stabn 68,0,475,.Ll199 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [475] j := i;
	movw	-268(%ebp),%ax
	# Register %ax released
	movw	%ax,-272(%ebp)
.L883:
	# Register %edx allocated
.Ll200:
	.stabn 68,0,477,.Ll200 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [477] if comando = 'DATOS' then
	movl	$_$PROGRAM$_L897,%edx
	# Register %eax allocated
	leal	-532(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L893
	jmp	.L894
.L893:
.Ll201:
	.stabn 68,0,479,.Ll201 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [479] fase := 'd';
	movb	$100,-276(%ebp)
	# Register %ax allocated
.Ll202:
	.stabn 68,0,480,.Ll202 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [480] j := i;
	movw	-268(%ebp),%ax
	# Register %ax released
	movw	%ax,-272(%ebp)
.L894:
	# Register %edx allocated
.Ll203:
	.stabn 68,0,482,.Ll203 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [482] if comando = 'CALCUL' then
	movl	$_$PROGRAM$_L908,%edx
	# Register %eax allocated
	leal	-532(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_compare
	# Register %ecx,%edx,%eax released
	testl	%eax,%eax
	je	.L904
	jmp	.L905
.L904:
.Ll204:
	.stabn 68,0,484,.Ll204 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [484] fase := 'c';
	movb	$99,-276(%ebp)
	# Register %ax allocated
.Ll205:
	.stabn 68,0,485,.Ll205 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [485] j:= i;
	movw	-268(%ebp),%ax
	# Register %ax released
	movw	%ax,-272(%ebp)
.L905:
	# Register %ecx allocated
.Ll206:
	.stabn 68,0,487,.Ll206 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [487] Parse(linea,fase,i-j);
	movswl	-268(%ebp),%ecx
	# Register %eax allocated
	movswl	-272(%ebp),%eax
	# Register %eax released
	subl	%eax,%ecx
	jno	.L917
	call	FPC_OVERFLOW
.L917:
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$-32768,%eax
	# Register %eax released
	cmpl	$65535,%eax
	jbe	.L918
	call	FPC_RANGEERROR
.L918:
	# Register %ecx released
	# Register %cx,%dl allocated
	movb	-276(%ebp),%dl
	# Register %eax allocated
	leal	-264(%ebp),%eax
	# Register %cx,%dl released
	# Register %ecx,%edx allocated
	call	P$STATIC_PARSE$SHORTSTRING$CHAR$SMALLINT
	# Register %eax,%ecx released
.Ll207:
	.stabn 68,0,488,.Ll207 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [488] i := i + 1;
	movswl	-268(%ebp),%edx
	addl	$1,%edx
	jno	.L925
	call	FPC_OVERFLOW
.L925:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$-32768,%eax
	# Register %eax released
	cmpl	$65535,%eax
	jbe	.L926
	call	FPC_RANGEERROR
.L926:
	# Register %edx released
	# Register %dx allocated
	# Register %dx released
	movw	%dx,-268(%ebp)
.L800:
	# Register %eax allocated
.Ll208:
	.stabn 68,0,457,.Ll208 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
	movl	$U_P$STATIC_ENTRADA,%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_EOF$TEXT$$BOOLEAN
	# Register %ecx,%edx,%al released
	# Register %bl allocated
	movb	%al,%bl
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%bl released
	testb	%bl,%bl
	jne	.L801
	jmp	.L799
.L801:
	# Register %eax allocated
.Ll209:
	.stabn 68,0,490,.Ll209 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [490] close(entrada);
	movl	$U_P$STATIC_ENTRADA,%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_CLOSE$TEXT
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
.Ll210:
	.stabn 68,0,491,.Ll210 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [491] inputfile:=true;
	movb	$1,-8(%ebp)
.L783:
	# Register %al allocated
.Ll211:
	.stabn 68,0,493,.Ll211 - P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
# [493] end; { inputfile }
	movb	-8(%ebp),%al
# Temp -8,4 released
# Temp -264,256 released
# Temp -268,4 released
# Temp -272,4 released
# Temp -276,4 released
# Temp -532,256 released
# Temp -536,4 released
# Temp -540,4 released
# Temp -796,256 released
	# Register %ebx allocated
	movl	-1320(%ebp),%ebx
	# Register %esi allocated
	movl	-1316(%ebp),%esi
	# Register %edi allocated
	movl	-1312(%ebp),%edi
# Temp -1320,12 released
	leave
	# Register %ebp released
	ret
	# Register %al released
.L938:
	.stabs "INPUTFILE:X32",160,0,0,-8
	.stabn 192,0,0,P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN-P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
	.stabn 224,0,0,.L938-P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN

.section .text
	.balign 4
	.balign 4
	.stabs "DATAGEN:F8",36,0,499,P$STATIC_DATAGEN$TABLA$READATA
	.stabs "T1:v34",160,0,499,-4
	.stabs "RESCALCS:v4",160,0,499,-8
	.stabs "I:21",160,0,501,-12
	.stabs "PM:4",160,0,502,-2052
	.stabs "V:4",160,0,502,-4092
	.stabs "FXV:4",160,0,502,-6132
	.stabs "LPM:4",160,0,502,-8172
	.stabs "FLPM:4",160,0,502,-10212
	.stabs "IPM:4",160,0,502,-12252
	.stabs "DM:4",160,0,502,-14292
	.stabs "FXIPM:4",160,0,502,-16332
	.stabs "FXX:4",160,0,502,-18372
	.stabs "FXX2:4",160,0,502,-20412
	.stabs "FA:3",160,0,503,-20924
	.stabs "A:11",160,0,504,-20932
	.stabs "TOTFXV:11",160,0,504,-20940
	.stabs "TOTFLPM:11",160,0,504,-20948
	.stabs "TOTFXIPM:11",160,0,504,-20956
	.stabs "MAR:11",160,0,504,-20964
	.stabs "TOTFXX2:11",160,0,504,-20972
.Ll212:
	.stabn 68,0,505,.Ll212 - P$STATIC_DATAGEN$TABLA$READATA
# [505] begin
.globl	P$STATIC_DATAGEN$TABLA$READATA
P$STATIC_DATAGEN$TABLA$READATA:
# Temps allocated between ebp-23024 and ebp-20972
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$23020,%esp
	movl	$0,18928(%esp)
	movl	$0,14832(%esp)
	movl	$0,10736(%esp)
	movl	$0,6640(%esp)
	movl	$0,2544(%esp)
	pushl	%eax
# Temp -23024,12 allocated
	movl	%ebx,-23024(%ebp)
	movl	%esi,-23020(%ebp)
	movl	%edi,-23016(%ebp)
# Temp -4,4 allocated
# Var t1 located at ebp-4
# Temp -8,4 allocated
# Var ResCalcs located at ebp-8
# Temp -12,4 allocated
# Var i located at ebp-12
# Temp -2052,2040 allocated
# Var PM located at ebp-2052
# Temp -4092,2040 allocated
# Var V located at ebp-4092
# Temp -6132,2040 allocated
# Var FxV located at ebp-6132
# Temp -8172,2040 allocated
# Var LPM located at ebp-8172
# Temp -10212,2040 allocated
# Var FLPM located at ebp-10212
# Temp -12252,2040 allocated
# Var IPM located at ebp-12252
# Temp -14292,2040 allocated
# Var DM located at ebp-14292
# Temp -16332,2040 allocated
# Var FxIPM located at ebp-16332
# Temp -18372,2040 allocated
# Var FxX located at ebp-18372
# Temp -20412,2040 allocated
# Var FxX2 located at ebp-20412
# Temp -20924,512 allocated
# Var FA located at ebp-20924
# Temp -20932,8 allocated
# Var A located at ebp-20932
# Temp -20940,8 allocated
# Var TotFxV located at ebp-20940
# Temp -20948,8 allocated
# Var TotFLPM located at ebp-20948
# Temp -20956,8 allocated
# Var totFxIPM located at ebp-20956
# Temp -20964,8 allocated
# Var MAr located at ebp-20964
# Temp -20972,8 allocated
# Var TotFxX2 located at ebp-20972
	# Register %eax,%edx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %eax allocated
	movl	$23024,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll213:
	.stabn 68,0,506,.Ll213 - P$STATIC_DATAGEN$TABLA$READATA
# [506] Writeln('Generando Tabla de Datos...');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L945,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax,%ecx,%edx allocated
.Ll214:
	.stabn 68,0,507,.Ll214 - P$STATIC_DATAGEN$TABLA$READATA
# [507] Writeln('  Calculando datos para los intervalos...');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L956,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
# Temp -23012,2040 allocated
	# Register %eax allocated
.Ll215:
	.stabn 68,0,508,.Ll215 - P$STATIC_DATAGEN$TABLA$READATA
# [508] PM := PuntoMedio(); {Punto Medio}
	leal	-23012(%ebp),%eax
	# Register %ecx,%edx allocated
	call	P$STATIC_PUNTOMEDIO$$READATA
	# Register %eax,%ecx,%edx released
	# Register %edi allocated
	leal	-2052(%ebp),%edi
	# Register %esi allocated
	leal	-23012(%ebp),%esi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -23012,2040 released
	# Register %eax allocated
.Ll216:
	.stabn 68,0,509,.Ll216 - P$STATIC_DATAGEN$TABLA$READATA
# [509] A := MediaSupuesta(PM); {Media Supuesta}
	leal	-2052(%ebp),%eax
	# Register %ecx,%edx allocated
	call	P$STATIC_MEDIASUPUESTA$READATA$$DOUBLE
	# Register %eax,%ecx,%edx released
	fstpl	-20932(%ebp)
	fwait
.Ll217:
	.stabn 68,0,510,.Ll217 - P$STATIC_DATAGEN$TABLA$READATA
# [510] V := DesvRespA(PM,A); {Desviacion Respecto A}
	pushl	-20928(%ebp)
	pushl	-20932(%ebp)
# Temp -23012,2040 allocated
	# Register %edx allocated
	leal	-23012(%ebp),%edx
	# Register %eax allocated
	leal	-2052(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_DESVRESPA$READATA$DOUBLE$$READATA
	# Register %eax,%ecx,%edx released
	# Register %edi allocated
	leal	-4092(%ebp),%edi
	# Register %esi allocated
	leal	-23012(%ebp),%esi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -23012,2040 released
	# Register %ecx allocated
.Ll218:
	.stabn 68,0,511,.Ll218 - P$STATIC_DATAGEN$TABLA$READATA
# [511] TotalDesv(V,FxV,TotFxV); {frec * Desv y Desviacion Total}
	leal	-20940(%ebp),%ecx
	# Register %edx allocated
	leal	-6132(%ebp),%edx
	# Register %eax allocated
	leal	-4092(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_TOTALDESV$READATA$READATA$DOUBLE
	# Register %eax,%ecx,%edx released
# Temp -23012,512 allocated
	# Register %edx allocated
.Ll219:
	.stabn 68,0,512,.Ll219 - P$STATIC_DATAGEN$TABLA$READATA
# [512] FA := FrecAcum(frec); {Frecuencia Acumulada}
	leal	-23012(%ebp),%edx
	# Register %eax allocated
	movl	$U_P$STATIC_FREC,%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_FRECACUM$ARRDATA$$ARRDATA
	# Register %eax,%ecx,%edx released
	# Register %edi allocated
	leal	-20924(%ebp),%edi
	# Register %esi allocated
	leal	-23012(%ebp),%esi
	# Register %ecx allocated
	cld
	movl	$127,%ecx
	rep
	movsl
	movsw
	# Register %ecx,%esi,%edi released
# Temp -23012,512 released
	# Register %eax allocated
.Ll220:
	.stabn 68,0,513,.Ll220 - P$STATIC_DATAGEN$TABLA$READATA
# [513] FLogPM(PM,frec,LPM,FLPM,TotFLPM);{Log(PM) frec*Log(PM) y Total Frec*Log(PM}
	leal	-20948(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %eax allocated
	leal	-10212(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	leal	-8172(%ebp),%ecx
	# Register %edx allocated
	movl	$U_P$STATIC_FREC,%edx
	# Register %eax allocated
	leal	-2052(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_FLOGPM$READATA$ARRDATA$READATA$READATA$DOUBLE
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll221:
	.stabn 68,0,514,.Ll221 - P$STATIC_DATAGEN$TABLA$READATA
# [514] FInvPM(PM,IPM,FxIPM,totFxIPM); {inverso Punto Medio}
	leal	-20956(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	leal	-16332(%ebp),%ecx
	# Register %edx allocated
	leal	-12252(%ebp),%edx
	# Register %eax allocated
	leal	-2052(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_FINVPM$READATA$READATA$READATA$DOUBLE
	# Register %eax,%ecx,%edx released
.Ll222:
	.stabn 68,0,515,.Ll222 - P$STATIC_DATAGEN$TABLA$READATA
# [515] MAr := MediaArit(A,TotFxV); {Media Aritmetica}
	pushl	-20936(%ebp)
	pushl	-20940(%ebp)
	pushl	-20928(%ebp)
	pushl	-20932(%ebp)
	# Register %eax,%ecx,%edx allocated
	call	P$STATIC_MEDIAARIT$DOUBLE$DOUBLE$$DOUBLE
	# Register %eax,%ecx,%edx released
	fstpl	-20964(%ebp)
	fwait
.Ll223:
	.stabn 68,0,516,.Ll223 - P$STATIC_DATAGEN$TABLA$READATA
# [516] DM := DiffMedia(PM,MAr); {diferencia Punto Medio}
	pushl	-20960(%ebp)
	pushl	-20964(%ebp)
# Temp -23012,2040 allocated
	# Register %edx allocated
	leal	-23012(%ebp),%edx
	# Register %eax allocated
	leal	-2052(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_DIFFMEDIA$READATA$DOUBLE$$READATA
	# Register %eax,%ecx,%edx released
	# Register %edi allocated
	leal	-14292(%ebp),%edi
	# Register %esi allocated
	leal	-23012(%ebp),%esi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -23012,2040 released
	# Register %eax allocated
.Ll224:
	.stabn 68,0,517,.Ll224 - P$STATIC_DATAGEN$TABLA$READATA
# [517] FxDiffMedia(DM,FxX,FxX2,TotFxX2);{Frec*DiffMedia, Frec*DiffMedia^2}
	leal	-20972(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	leal	-20412(%ebp),%ecx
	# Register %edx allocated
	leal	-18372(%ebp),%edx
	# Register %eax allocated
	leal	-14292(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_FXDIFFMEDIA$READATA$READATA$READATA$DOUBLE
	# Register %eax,%ecx,%edx released
	# Register %ax allocated
.Ll225:
	.stabn 68,0,519,.Ll225 - P$STATIC_DATAGEN$TABLA$READATA
# [519] for i:=1 to numinterv do
	movzbw	U_P$STATIC_NUMINTERV,%ax
# Temp -23012,4 allocated
	# Register %ax released
	movw	%ax,-23012(%ebp)
	movw	$1,-12(%ebp)
	# Register %ax allocated
	movw	-12(%ebp),%ax
	# Register %ax released
	cmpw	-23012(%ebp),%ax
	jg	.L1032
	subw	$1,-12(%ebp)
	.balign 4
.L1033:
	addw	$1,-12(%ebp)
	# Register %ecx allocated
.Ll226:
	.stabn 68,0,521,.Ll226 - P$STATIC_DATAGEN$TABLA$READATA
# [521] t1[i][1]  := i;
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1036
	call	FPC_RANGEERROR
.L1036:
	imull	$2040,%edx
# Temp -23008,4 allocated
	# Register %eax allocated
	movswl	-12(%ebp),%eax
	# Register %eax released
	movl	%eax,-23008(%ebp)
	fildl	-23008(%ebp)
# Temp -23008,4 released
	# Register %ecx,%edx released
	fstpl	-2040(%ecx,%edx)
	fwait
	# Register %edx allocated
.Ll227:
	.stabn 68,0,522,.Ll227 - P$STATIC_DATAGEN$TABLA$READATA
# [522] t1[i][2]  := intervI[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1039
	call	FPC_RANGEERROR
.L1039:
# Temp -23008,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVI-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-23008(%ebp)
	fildl	-23008(%ebp)
# Temp -23008,4 released
	# Register %ecx allocated
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1040
	call	FPC_RANGEERROR
.L1040:
	imull	$2040,%edx
	# Register %ecx,%edx released
	fstpl	-2032(%ecx,%edx)
	fwait
	# Register %edx allocated
.Ll228:
	.stabn 68,0,523,.Ll228 - P$STATIC_DATAGEN$TABLA$READATA
# [523] t1[i][3]  := intervD[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1043
	call	FPC_RANGEERROR
.L1043:
# Temp -23008,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_INTERVD-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-23008(%ebp)
	fildl	-23008(%ebp)
# Temp -23008,4 released
	# Register %ecx allocated
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1044
	call	FPC_RANGEERROR
.L1044:
	imull	$2040,%edx
	# Register %ecx,%edx released
	fstpl	-2024(%ecx,%edx)
	fwait
	# Register %edx allocated
.Ll229:
	.stabn 68,0,524,.Ll229 - P$STATIC_DATAGEN$TABLA$READATA
# [524] t1[i][4]  := PM[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1047
	call	FPC_RANGEERROR
.L1047:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1048
	call	FPC_RANGEERROR
.L1048:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-2060(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-2016(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-2056(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-2012(%ebx,%ecx)
	# Register %edx allocated
.Ll230:
	.stabn 68,0,525,.Ll230 - P$STATIC_DATAGEN$TABLA$READATA
# [525] t1[i][5]  := frec[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1051
	call	FPC_RANGEERROR
.L1051:
# Temp -23008,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	U_P$STATIC_FREC-2(,%edx,2),%eax
	# Register %eax released
	movl	%eax,-23008(%ebp)
	fildl	-23008(%ebp)
# Temp -23008,4 released
	# Register %ecx allocated
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1052
	call	FPC_RANGEERROR
.L1052:
	imull	$2040,%edx
	# Register %ecx,%edx released
	fstpl	-2008(%ecx,%edx)
	fwait
	# Register %edx allocated
.Ll231:
	.stabn 68,0,526,.Ll231 - P$STATIC_DATAGEN$TABLA$READATA
# [526] t1[i][6]  := V[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1055
	call	FPC_RANGEERROR
.L1055:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1056
	call	FPC_RANGEERROR
.L1056:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-4100(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-2000(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-4096(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1996(%ebx,%ecx)
	# Register %edx allocated
.Ll232:
	.stabn 68,0,527,.Ll232 - P$STATIC_DATAGEN$TABLA$READATA
# [527] t1[i][7]  := FxV[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1059
	call	FPC_RANGEERROR
.L1059:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1060
	call	FPC_RANGEERROR
.L1060:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-6140(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1992(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-6136(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1988(%ebx,%ecx)
	# Register %edx allocated
.Ll233:
	.stabn 68,0,528,.Ll233 - P$STATIC_DATAGEN$TABLA$READATA
# [528] t1[i][8]  := FA[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1063
	call	FPC_RANGEERROR
.L1063:
# Temp -23008,4 allocated
	# Register %edx released
	# Register %eax allocated
	movswl	-20926(%ebp,%edx,2),%eax
	# Register %eax released
	movl	%eax,-23008(%ebp)
	fildl	-23008(%ebp)
# Temp -23008,4 released
	# Register %ecx allocated
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1064
	call	FPC_RANGEERROR
.L1064:
	imull	$2040,%edx
	# Register %ecx,%edx released
	fstpl	-1984(%ecx,%edx)
	fwait
	# Register %edx allocated
.Ll234:
	.stabn 68,0,529,.Ll234 - P$STATIC_DATAGEN$TABLA$READATA
# [529] t1[i][9]  := LPM[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1067
	call	FPC_RANGEERROR
.L1067:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1068
	call	FPC_RANGEERROR
.L1068:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-8180(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1976(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-8176(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1972(%ebx,%ecx)
	# Register %edx allocated
.Ll235:
	.stabn 68,0,530,.Ll235 - P$STATIC_DATAGEN$TABLA$READATA
# [530] t1[i][10] := FLPM[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1071
	call	FPC_RANGEERROR
.L1071:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1072
	call	FPC_RANGEERROR
.L1072:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-10220(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1968(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-10216(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1964(%ebx,%ecx)
	# Register %edx allocated
.Ll236:
	.stabn 68,0,531,.Ll236 - P$STATIC_DATAGEN$TABLA$READATA
# [531] t1[i][11] := IPM[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1075
	call	FPC_RANGEERROR
.L1075:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1076
	call	FPC_RANGEERROR
.L1076:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-12260(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1960(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-12256(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1956(%ebx,%ecx)
	# Register %edx allocated
.Ll237:
	.stabn 68,0,532,.Ll237 - P$STATIC_DATAGEN$TABLA$READATA
# [532] t1[i][12] := FxIPM[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1079
	call	FPC_RANGEERROR
.L1079:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1080
	call	FPC_RANGEERROR
.L1080:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-16340(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1952(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-16336(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1948(%ebx,%ecx)
	# Register %edx allocated
.Ll238:
	.stabn 68,0,533,.Ll238 - P$STATIC_DATAGEN$TABLA$READATA
# [533] t1[i][13] := DM[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1083
	call	FPC_RANGEERROR
.L1083:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1084
	call	FPC_RANGEERROR
.L1084:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-14300(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1944(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-14296(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1940(%ebx,%ecx)
	# Register %edx allocated
.Ll239:
	.stabn 68,0,534,.Ll239 - P$STATIC_DATAGEN$TABLA$READATA
# [534] t1[i][14] := FxX[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1087
	call	FPC_RANGEERROR
.L1087:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1088
	call	FPC_RANGEERROR
.L1088:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-18380(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1936(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-18376(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1932(%ebx,%ecx)
	# Register %edx allocated
.Ll240:
	.stabn 68,0,535,.Ll240 - P$STATIC_DATAGEN$TABLA$READATA
# [535] t1[i][15] := FxX2[i];
	movswl	-12(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1091
	call	FPC_RANGEERROR
.L1091:
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
	# Register %ecx allocated
	movswl	-12(%ebp),%ecx
	# Register %eax allocated
	movl	%ecx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1092
	call	FPC_RANGEERROR
.L1092:
	imull	$2040,%ecx
	# Register %eax allocated
	movl	-20420(%ebp,%edx,8),%eax
	# Register %eax released
	movl	%eax,-1928(%ebx,%ecx)
	# Register %edx released
	# Register %eax allocated
	movl	-20416(%ebp,%edx,8),%eax
	# Register %ebx,%ecx,%eax released
	movl	%eax,-1924(%ebx,%ecx)
	# Register %ax allocated
.Ll241:
	.stabn 68,0,519,.Ll241 - P$STATIC_DATAGEN$TABLA$READATA
	movw	-12(%ebp),%ax
	# Register %ax released
	cmpw	-23012(%ebp),%ax
	jl	.L1033
# Temp -23012,4 released
.L1032:
	# Register %ecx allocated
.Ll242:
	.stabn 68,0,537,.Ll242 - P$STATIC_DATAGEN$TABLA$READATA
# [537] t1[numinterv + 1][5] := numdatos;
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMINTERV,%edx
	addl	$1,%edx
	jno	.L1095
	call	FPC_OVERFLOW
.L1095:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1096
	call	FPC_RANGEERROR
.L1096:
	imull	$2040,%edx
# Temp -23012,4 allocated
	# Register %eax allocated
	movzbl	U_P$STATIC_NUMDATOS,%eax
	# Register %eax released
	movl	%eax,-23012(%ebp)
	fildl	-23012(%ebp)
# Temp -23012,4 released
	# Register %ecx,%edx released
	fstpl	-2008(%ecx,%edx)
	fwait
	# Register %ecx allocated
.Ll243:
	.stabn 68,0,538,.Ll243 - P$STATIC_DATAGEN$TABLA$READATA
# [538] t1[numinterv + 1][7] := TotFxV;
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMINTERV,%edx
	addl	$1,%edx
	jno	.L1099
	call	FPC_OVERFLOW
.L1099:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1100
	call	FPC_RANGEERROR
.L1100:
	imull	$2040,%edx
	# Register %eax allocated
	movl	-20940(%ebp),%eax
	# Register %eax released
	movl	%eax,-1992(%ecx,%edx)
	# Register %eax allocated
	movl	-20936(%ebp),%eax
	# Register %ecx,%edx,%eax released
	movl	%eax,-1988(%ecx,%edx)
	# Register %ecx allocated
.Ll244:
	.stabn 68,0,539,.Ll244 - P$STATIC_DATAGEN$TABLA$READATA
# [539] t1[numinterv + 1][10] := TotFLPM;
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMINTERV,%edx
	addl	$1,%edx
	jno	.L1103
	call	FPC_OVERFLOW
.L1103:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1104
	call	FPC_RANGEERROR
.L1104:
	imull	$2040,%edx
	# Register %eax allocated
	movl	-20948(%ebp),%eax
	# Register %eax released
	movl	%eax,-1968(%ecx,%edx)
	# Register %eax allocated
	movl	-20944(%ebp),%eax
	# Register %ecx,%edx,%eax released
	movl	%eax,-1964(%ecx,%edx)
	# Register %ecx allocated
.Ll245:
	.stabn 68,0,540,.Ll245 - P$STATIC_DATAGEN$TABLA$READATA
# [540] t1[numinterv + 1][12] := TotFxIPM;
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMINTERV,%edx
	addl	$1,%edx
	jno	.L1107
	call	FPC_OVERFLOW
.L1107:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1108
	call	FPC_RANGEERROR
.L1108:
	imull	$2040,%edx
	# Register %eax allocated
	movl	-20956(%ebp),%eax
	# Register %eax released
	movl	%eax,-1952(%ecx,%edx)
	# Register %eax allocated
	movl	-20952(%ebp),%eax
	# Register %ecx,%edx,%eax released
	movl	%eax,-1948(%ecx,%edx)
	# Register %ecx allocated
.Ll246:
	.stabn 68,0,541,.Ll246 - P$STATIC_DATAGEN$TABLA$READATA
# [541] t1[numinterv + 1][15] := TotFxX2;
	movl	-4(%ebp),%ecx
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMINTERV,%edx
	addl	$1,%edx
	jno	.L1111
	call	FPC_OVERFLOW
.L1111:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1112
	call	FPC_RANGEERROR
.L1112:
	imull	$2040,%edx
	# Register %eax allocated
	movl	-20972(%ebp),%eax
	# Register %eax released
	movl	%eax,-1928(%ecx,%edx)
	# Register %eax allocated
	movl	-20968(%ebp),%eax
	# Register %ecx,%edx,%eax released
	movl	%eax,-1924(%ecx,%edx)
	# Register %eax,%ecx,%edx allocated
.Ll247:
	.stabn 68,0,543,.Ll247 - P$STATIC_DATAGEN$TABLA$READATA
# [543] WriteLN('  Calculando Medidas de Tendencia Central...');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1117,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %edx allocated
.Ll248:
	.stabn 68,0,544,.Ll248 - P$STATIC_DATAGEN$TABLA$READATA
# [544] ResCalcs[1] := MAr;
	movl	-8(%ebp),%edx
	# Register %eax allocated
	movl	-20964(%ebp),%eax
	# Register %eax released
	movl	%eax,(%edx)
	# Register %eax allocated
	movl	-20960(%ebp),%eax
	# Register %edx,%eax released
	movl	%eax,4(%edx)
# Temp -23012,512 allocated
	# Register %edx allocated
.Ll249:
	.stabn 68,0,545,.Ll249 - P$STATIC_DATAGEN$TABLA$READATA
# [545] ResCalcs[2] := mediana(FrecAcum(frec));
	leal	-23012(%ebp),%edx
	# Register %eax allocated
	movl	$U_P$STATIC_FREC,%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_FRECACUM$ARRDATA$$ARRDATA
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-23012(%ebp),%eax
	# Register %ecx,%edx allocated
	call	P$STATIC_MEDIANA$ARRDATA$$DOUBLE
	# Register %eax,%ecx,%edx released
# Temp -23012,512 released
	# Register %eax allocated
	movl	-8(%ebp),%eax
	# Register %eax released
	fstpl	8(%eax)
	fwait
	# Register %eax,%ecx,%edx allocated
.Ll250:
	.stabn 68,0,546,.Ll250 - P$STATIC_DATAGEN$TABLA$READATA
# [546] ResCalcs[3] := moda();
	call	P$STATIC_MODA$$DOUBLE
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	-8(%ebp),%eax
	# Register %eax released
	fstpl	16(%eax)
	fwait
.Ll251:
	.stabn 68,0,547,.Ll251 - P$STATIC_DATAGEN$TABLA$READATA
# [547] ResCalcs[4] := MediaGeom(TotFLPM);
	pushl	-20944(%ebp)
	pushl	-20948(%ebp)
	# Register %eax,%ecx,%edx allocated
	call	P$STATIC_MEDIAGEOM$DOUBLE$$DOUBLE
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	-8(%ebp),%eax
	# Register %eax released
	fstpl	24(%eax)
	fwait
.Ll252:
	.stabn 68,0,548,.Ll252 - P$STATIC_DATAGEN$TABLA$READATA
# [548] ResCalcs[5] := MediaArm(TotFxIPM);
	pushl	-20952(%ebp)
	pushl	-20956(%ebp)
	# Register %eax,%ecx,%edx allocated
	call	P$STATIC_MEDIAARM$DOUBLE$$DOUBLE
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	-8(%ebp),%eax
	# Register %eax released
	fstpl	32(%eax)
	fwait
.Ll253:
	.stabn 68,0,549,.Ll253 - P$STATIC_DATAGEN$TABLA$READATA
# [549] ResCalcs[6] := Varianza(TotFxX2);
	pushl	-20968(%ebp)
	pushl	-20972(%ebp)
	# Register %eax,%ecx,%edx allocated
	call	P$STATIC_VARIANZA$DOUBLE$$DOUBLE
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	-8(%ebp),%eax
	# Register %eax released
	fstpl	40(%eax)
	fwait
	# Register %eax allocated
.Ll254:
	.stabn 68,0,550,.Ll254 - P$STATIC_DATAGEN$TABLA$READATA
# [550] ResCalcs[7] := sqrt(ResCalcs[6]);
	movl	-8(%ebp),%eax
	# Register %eax released
	fldl	40(%eax)
	fsqrt
	# Register %eax allocated
	movl	-8(%ebp),%eax
	# Register %eax released
	fstpl	48(%eax)
	fwait
.Ll255:
	.stabn 68,0,551,.Ll255 - P$STATIC_DATAGEN$TABLA$READATA
# [551] i:=1;
	movw	$1,-12(%ebp)
# Temp -12,4 released
# Temp -2052,2040 released
# Temp -4092,2040 released
# Temp -6132,2040 released
# Temp -8172,2040 released
# Temp -10212,2040 released
# Temp -12252,2040 released
# Temp -14292,2040 released
# Temp -16332,2040 released
# Temp -18372,2040 released
# Temp -20412,2040 released
# Temp -20924,512 released
# Temp -20932,8 released
# Temp -20940,8 released
# Temp -20948,8 released
# Temp -20956,8 released
# Temp -20964,8 released
# Temp -20972,8 released
# Temp -4,4 released
# Temp -8,4 released
	# Register %ebx allocated
.Ll256:
	.stabn 68,0,552,.Ll256 - P$STATIC_DATAGEN$TABLA$READATA
# [552] end;
	movl	-23024(%ebp),%ebx
	# Register %esi allocated
	movl	-23020(%ebp),%esi
	# Register %edi allocated
	movl	-23016(%ebp),%edi
# Temp -23024,12 released
	leave
	# Register %ebp released
	ret
.L1157:
	.stabn 192,0,0,P$STATIC_DATAGEN$TABLA$READATA-P$STATIC_DATAGEN$TABLA$READATA
	.stabn 224,0,0,.L1157-P$STATIC_DATAGEN$TABLA$READATA

.section .text
	.balign 4
	.balign 4
	.stabs "SALIDA:F32",36,0,563,P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	.stabs "DATOS:p34",160,0,563,-521324
	.stabs "RESULTADOS:p4",160,0,563,-523364
	.stabs "result:32",160,0,563,-12
	.stabs "RUTA:1",160,0,565,-268
	.stabs "CALCS:1",160,0,565,-524
	.stabs "OUT:2",160,0,566,-1116
	.stabs "I:5",160,0,568,-1120
	.stabs "MOSTRAR:28",160,0,569,-1124
.Ll257:
	.stabn 68,0,570,.Ll257 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [570] begin
.globl	P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN:
# Temps allocated between ebp-523376 and ebp-1124
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	# Register %edi allocated
	movl	$127,%edi
.L1820:
	subl	$4092,%esp
	pushl	%eax
	decl	%edi
	jne	.L1820
	# Register %edi released
	subl	$3184,%esp
# Temp -523376,12 allocated
	movl	%ebx,-523376(%ebp)
	movl	%esi,-523372(%ebp)
	movl	%edi,-523368(%ebp)
# Temp -4,4 allocated
# Var Datos located at ebp-4
# Temp -8,4 allocated
# Var resultados located at ebp-8
# Temp -12,4 allocated
# Var $result located at ebp-12
# Temp -268,256 allocated
# Var ruta located at ebp-268
# Temp -524,256 allocated
# Var calcs located at ebp-524
# Temp -1116,592 allocated
# Var out located at ebp-1116
# Temp -1120,4 allocated
# Var i located at ebp-1120
# Temp -1124,4 allocated
# Var mostrar located at ebp-1124
	# Register %eax,%edx allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %edx released
	movl	%edx,-8(%ebp)
	# Register %esi allocated
	movl	-4(%ebp),%esi
# Temp -521324,520200 allocated
	# Register %edi allocated
	leal	-521324(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$130050,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -4,4 released
	# Register %esi allocated
	movl	-8(%ebp),%esi
# Temp -523364,2040 allocated
	# Register %edi allocated
	leal	-523364(%ebp),%edi
	# Register %ecx allocated
	cld
	movl	$510,%ecx
	rep
	movsl
	# Register %ecx,%esi,%edi released
# Temp -8,4 released
	# Register %eax allocated
	movl	$523376,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	.balign 4
.L1160:
	# Register %eax,%ecx,%edx allocated
.Ll258:
	.stabn 68,0,573,.Ll258 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [573] Writeln('ingrese nombre de archivo de salida');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1167,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax,%ecx,%edx allocated
.Ll259:
	.stabn 68,0,574,.Ll259 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [574] readln(ruta);
	call	fpc_get_input
	# Register %ecx,%edx,%eax released
	# Register %esi allocated
	movl	%eax,%esi
	# Register %ecx allocated
	movl	$255,%ecx
	# Register %eax allocated
	leal	-268(%ebp),%eax
	# Register %ebx allocated
	movl	%esi,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_read_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%esi,%eax
	# Register %ecx,%edx allocated
	call	fpc_readln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%esi released
	# Register %eax allocated
.Ll260:
	.stabn 68,0,575,.Ll260 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [575] until length(ruta)>0;
	movzbl	-268(%ebp),%eax
	# Register %eax released
	cmpl	$0,%eax
	jg	.L1162
	jmp	.L1160
.L1162:
	# Register %edx allocated
.Ll261:
	.stabn 68,0,576,.Ll261 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [576] assign(out,ruta);
	leal	-268(%ebp),%edx
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	SYSTEM_ASSIGN$TEXT$SHORTSTRING
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll262:
	.stabn 68,0,578,.Ll262 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [578] rewrite(out);
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_REWRITE$TEXT
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll263:
	.stabn 68,0,583,.Ll263 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [583] writeln('Creando Tabla en archivo ',ruta,'....');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1194,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	leal	-268(%ebp),%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1207,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %ecx allocated
.Ll264:
	.stabn 68,0,584,.Ll264 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [584] writeln(out,'                               -=',Titulo,'=-');
	movl	$_$PROGRAM$_L1216,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$U_P$STATIC_TITULO,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1229,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
.Ll265:
	.stabn 68,0,585,.Ll265 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [585] writeln(out,'+___+__________+_____+__________+__________+_____+__________+______+_______+_______+____+______+_______+_______+');
	movl	$_$PROGRAM$_L1238,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
.Ll266:
	.stabn 68,0,586,.Ll266 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [586] writeln(out,'|   |          |     |          |          |Total|          |      |       |       |    | X=   |       |       |');
	movl	$_$PROGRAM$_L1247,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
.Ll267:
	.stabn 68,0,587,.Ll267 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [587] writeln(out,'|No.|Intervalo |Punto|Frecuencia|Desviacion|Desv.|Frecuencia| Log  |  f*   |Inverso| f* |PM-   | f*x   | f*x^2 |');
	movl	$_$PROGRAM$_L1256,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
.Ll268:
	.stabn 68,0,588,.Ll268 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [588] writeln(out,'|   |          |Medio|    f     | v=PM-A   |f*v  |Acumulada | (PM) |Log(PM)| 1/PM  |1/PM| MAR  |       |       |');
	movl	$_$PROGRAM$_L1265,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
.Ll269:
	.stabn 68,0,589,.Ll269 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [589] writeln(out,'+===+==========+=====+==========+==========+=====+==========+======+=======+=======+====+======+=======+=======+');
	movl	$_$PROGRAM$_L1274,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
# Temp -8,4 allocated
	# Register %al allocated
.Ll270:
	.stabn 68,0,591,.Ll270 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [591] for i:= 1 to numinterv do
	movb	U_P$STATIC_NUMINTERV,%al
	# Register %al released
	movb	%al,-8(%ebp)
	movb	$1,-1120(%ebp)
	# Register %al allocated
	movb	-1120(%ebp),%al
	# Register %al released
	cmpb	-8(%ebp),%al
	ja	.L1282
	subb	$1,-1120(%ebp)
	.balign 4
.L1283:
	addb	$1,-1120(%ebp)
	# Register %cl allocated
.Ll271:
	.stabn 68,0,593,.Ll271 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [593] writeln(out,'|',Datos[i][1]:3:0,'|',Datos[i][2]:3:0,'  < ',
	movb	$124,%cl
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1292
	call	FPC_RANGEERROR
.L1292:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523364(%ebp,%edx)
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$3,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1309
	call	FPC_RANGEERROR
.L1309:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523356(%ebp,%edx)
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$3,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1320,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll272:
	.stabn 68,0,594,.Ll272 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [594] Datos[i][3]:3:0,'|', datos[i][4]:5:0,'|',datos[i][5]:6:0,
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1327
	call	FPC_RANGEERROR
.L1327:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523348(%ebp,%edx)
.Ll273:
	.stabn 68,0,593,.Ll273 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$3,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll274:
	.stabn 68,0,594,.Ll274 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1344
	call	FPC_RANGEERROR
.L1344:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523340(%ebp,%edx)
.Ll275:
	.stabn 68,0,593,.Ll275 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$5,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll276:
	.stabn 68,0,594,.Ll276 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1361
	call	FPC_RANGEERROR
.L1361:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523332(%ebp,%edx)
.Ll277:
	.stabn 68,0,593,.Ll277 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$6,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1372,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll278:
	.stabn 68,0,595,.Ll278 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [595] '    |',datos[i][6]:5:0,'     |',datos[i][7]:5:0,'|',
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1379
	call	FPC_RANGEERROR
.L1379:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523324(%ebp,%edx)
.Ll279:
	.stabn 68,0,593,.Ll279 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$5,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1390,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll280:
	.stabn 68,0,595,.Ll280 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1397
	call	FPC_RANGEERROR
.L1397:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523316(%ebp,%edx)
.Ll281:
	.stabn 68,0,593,.Ll281 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$5,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll282:
	.stabn 68,0,596,.Ll282 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [596] datos[i][8]:5:0,'     |',datos[i][9]:1:4,'|',
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1414
	call	FPC_RANGEERROR
.L1414:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523308(%ebp,%edx)
.Ll283:
	.stabn 68,0,593,.Ll283 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$5,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1390,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll284:
	.stabn 68,0,596,.Ll284 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1431
	call	FPC_RANGEERROR
.L1431:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523300(%ebp,%edx)
.Ll285:
	.stabn 68,0,593,.Ll285 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$1,%ecx
	# Register %edx allocated
	movl	$4,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll286:
	.stabn 68,0,597,.Ll286 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [597] datos[i][10]:7:5,'|',datos[i][11]:7:5,'|',
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1448
	call	FPC_RANGEERROR
.L1448:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523292(%ebp,%edx)
.Ll287:
	.stabn 68,0,593,.Ll287 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$7,%ecx
	# Register %edx allocated
	movl	$5,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll288:
	.stabn 68,0,597,.Ll288 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1465
	call	FPC_RANGEERROR
.L1465:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523284(%ebp,%edx)
.Ll289:
	.stabn 68,0,593,.Ll289 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$7,%ecx
	# Register %edx allocated
	movl	$5,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll290:
	.stabn 68,0,598,.Ll290 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [598] datos[i][12]:4:2,'|', datos[i][13]:6:2,'|',
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1482
	call	FPC_RANGEERROR
.L1482:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523276(%ebp,%edx)
.Ll291:
	.stabn 68,0,593,.Ll291 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$4,%ecx
	# Register %edx allocated
	movl	$2,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll292:
	.stabn 68,0,598,.Ll292 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1499
	call	FPC_RANGEERROR
.L1499:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523268(%ebp,%edx)
.Ll293:
	.stabn 68,0,593,.Ll293 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$6,%ecx
	# Register %edx allocated
	movl	$2,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll294:
	.stabn 68,0,599,.Ll294 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [599] datos[i][14]:7:3,'|',datos[i][15]:7:3,'|');
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1516
	call	FPC_RANGEERROR
.L1516:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523260(%ebp,%edx)
.Ll295:
	.stabn 68,0,593,.Ll295 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$7,%ecx
	# Register %edx allocated
	movl	$3,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll296:
	.stabn 68,0,599,.Ll296 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1533
	call	FPC_RANGEERROR
.L1533:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523252(%ebp,%edx)
.Ll297:
	.stabn 68,0,593,.Ll297 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$7,%ecx
	# Register %edx allocated
	movl	$3,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll298:
	.stabn 68,0,600,.Ll298 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [600] if i<numinterv then
	movzbl	-1120(%ebp),%eax
	# Register %edx allocated
	movzbl	U_P$STATIC_NUMINTERV,%edx
	# Register %eax,%edx released
	cmpl	%edx,%eax
	jb	.L1550
	jmp	.L1551
.L1550:
	# Register %ecx allocated
.Ll299:
	.stabn 68,0,601,.Ll299 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [601] writeln(out,'+---+----------+-----+----------+----------+-----+----------+------+-------+-------+----+------+-------+-------+')
	movl	$_$PROGRAM$_L1554,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	jmp	.L1561
.L1551:
	# Register %ecx allocated
.Ll300:
	.stabn 68,0,603,.Ll300 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [603] writeln(out,'+===+==========+=====+==========+==========+=====+==========+======+=======+=======+====+======+=======+=======+');
	movl	$_$PROGRAM$_L1274,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
.L1561:
	# Register %al allocated
.Ll301:
	.stabn 68,0,591,.Ll301 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movb	-1120(%ebp),%al
	# Register %al released
	cmpb	-8(%ebp),%al
	jb	.L1283
# Temp -8,4 released
.L1282:
	# Register %ecx allocated
.Ll302:
	.stabn 68,0,607,.Ll302 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [607] writeln(out,'|   |   Total  |     | =',Datos[i+1][5]:8:0,
	movl	$_$PROGRAM$_L1572,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
	movzbl	-1120(%ebp),%edx
	addl	$1,%edx
	jno	.L1579
	call	FPC_OVERFLOW
.L1579:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1580
	call	FPC_RANGEERROR
.L1580:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523332(%ebp,%edx)
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$8,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1591,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll303:
	.stabn 68,0,608,.Ll303 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [608] '|          |=',Datos[i+1][7]:4:0,'|          |      |=',
	movzbl	-1120(%ebp),%edx
	addl	$1,%edx
	jno	.L1598
	call	FPC_OVERFLOW
.L1598:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1599
	call	FPC_RANGEERROR
.L1599:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523316(%ebp,%edx)
.Ll304:
	.stabn 68,0,607,.Ll304 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$4,%ecx
	# Register %edx allocated
	movl	$0,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1610,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll305:
	.stabn 68,0,609,.Ll305 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [609] Datos[i+1][10]:6:2, '|       |',Datos[i+1][12]:4:1,
	movzbl	-1120(%ebp),%edx
	addl	$1,%edx
	jno	.L1617
	call	FPC_OVERFLOW
.L1617:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1618
	call	FPC_RANGEERROR
.L1618:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523292(%ebp,%edx)
.Ll306:
	.stabn 68,0,607,.Ll306 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$6,%ecx
	# Register %edx allocated
	movl	$2,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1629,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll307:
	.stabn 68,0,609,.Ll307 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	movzbl	-1120(%ebp),%edx
	addl	$1,%edx
	jno	.L1636
	call	FPC_OVERFLOW
.L1636:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1637
	call	FPC_RANGEERROR
.L1637:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523276(%ebp,%edx)
.Ll308:
	.stabn 68,0,607,.Ll308 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$4,%ecx
	# Register %edx allocated
	movl	$1,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1648,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
.Ll309:
	.stabn 68,0,610,.Ll309 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [610] '|      |       |=',datos[i+1][15]:6:2,'|');
	movzbl	-1120(%ebp),%edx
	addl	$1,%edx
	jno	.L1655
	call	FPC_OVERFLOW
.L1655:
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1656
	call	FPC_RANGEERROR
.L1656:
	imull	$2040,%edx
	# Register %edx released
	fldl	-523252(%ebp,%edx)
.Ll310:
	.stabn 68,0,607,.Ll310 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$6,%ecx
	# Register %edx allocated
	movl	$2,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %cl allocated
	movb	$124,%cl
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ebx allocated
	movl	$0,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %cl,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
.Ll311:
	.stabn 68,0,611,.Ll311 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [611] writeln(out,'+===+==========+=====+==========+==========+=====+==========+======+=======+=======+====+======+=======+=======+');
	movl	$_$PROGRAM$_L1274,%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
.Ll312:
	.stabn 68,0,614,.Ll312 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [614] for i:=1 to 7 do
	movb	$1,-1120(%ebp)
	subb	$1,-1120(%ebp)
	.balign 4
.L1683:
	addb	$1,-1120(%ebp)
	# Register %edx allocated
.Ll313:
	.stabn 68,0,616,.Ll313 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [616] if calcular[i]=true then
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$6,%eax
	jbe	.L1686
	call	FPC_RANGEERROR
.L1686:
	# Register %edx released
	cmpb	$0,U_P$STATIC_CALCULAR-1(,%edx,1)
	jne	.L1684
	jmp	.L1685
.L1684:
	# Register %al allocated
.Ll314:
	.stabn 68,0,618,.Ll314 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [618] case i of
	movb	-1120(%ebp),%al
	cmpb	$1,%al
	jb	.L1688
	subb	$1,%al
	je	.L1689
	subb	$1,%al
	je	.L1690
	subb	$1,%al
	je	.L1691
	subb	$1,%al
	je	.L1692
	subb	$1,%al
	je	.L1693
	subb	$1,%al
	je	.L1694
	# Register %al released
	subb	$1,%al
	je	.L1695
	jmp	.L1688
.L1689:
	# Register %ecx allocated
.Ll315:
	.stabn 68,0,619,.Ll315 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [619] 1 : calcs:='Media Aritmetica: ';
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	movl	$_$PROGRAM$_L1700,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
	jmp	.L1687
.L1690:
	# Register %ecx allocated
.Ll316:
	.stabn 68,0,620,.Ll316 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [620] 2 : calcs:='Mediana : ';
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	movl	$_$PROGRAM$_L1707,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
	jmp	.L1687
.L1691:
	# Register %ecx allocated
.Ll317:
	.stabn 68,0,621,.Ll317 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [621] 3 : calcs:='Moda : ';
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	movl	$_$PROGRAM$_L1714,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
	jmp	.L1687
.L1692:
	# Register %ecx allocated
.Ll318:
	.stabn 68,0,622,.Ll318 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [622] 4 : calcs:='Media Geometrica : ';
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	movl	$_$PROGRAM$_L1721,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
	jmp	.L1687
.L1693:
	# Register %ecx allocated
.Ll319:
	.stabn 68,0,623,.Ll319 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [623] 5 : calcs:='Media Armonica : ';
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	movl	$_$PROGRAM$_L1728,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
	jmp	.L1687
.L1694:
	# Register %ecx allocated
.Ll320:
	.stabn 68,0,624,.Ll320 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [624] 6 : calcs:='Varianza : ';
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	movl	$_$PROGRAM$_L1735,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
	jmp	.L1687
.L1695:
	# Register %ecx allocated
.Ll321:
	.stabn 68,0,625,.Ll321 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [625] 7 : calcs:='Desviacion Estandar: ';
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	movl	$_$PROGRAM$_L1742,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_to_shortstr
	# Register %eax,%ecx,%edx released
	jmp	.L1687
.L1688:
.L1687:
	# Register %ecx allocated
.Ll322:
	.stabn 68,0,627,.Ll322 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [627] writeln(out,calcs,resultados[i]:8:5);
	leal	-524(%ebp),%ecx
	# Register %edx allocated
	leal	-1116(%ebp),%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx released
	movzbl	-1120(%ebp),%edx
	# Register %eax allocated
	movl	%edx,%eax
	subl	$1,%eax
	# Register %eax released
	cmpl	$254,%eax
	jbe	.L1753
	call	FPC_RANGEERROR
.L1753:
	# Register %edx released
	fldl	-523372(%ebp,%edx,8)
	subl	$12,%esp
	fstpt	(%esp)
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$8,%ecx
	# Register %edx allocated
	movl	$5,%edx
	# Register %eax allocated
	movl	$1,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_float
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
.L1685:
.Ll323:
	.stabn 68,0,614,.Ll323 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	cmpb	$7,-1120(%ebp)
	jb	.L1683
	# Register %eax allocated
.Ll324:
	.stabn 68,0,630,.Ll324 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [630] close(out);
	leal	-1116(%ebp),%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_CLOSE$TEXT
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll325:
	.stabn 68,0,631,.Ll325 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [631] writeln('Archivo ',ruta,' creado satisfactoriamente.');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1770,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	leal	-268(%ebp),%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1783,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax,%ecx,%edx allocated
.Ll326:
	.stabn 68,0,633,.Ll326 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [633] writeln('Desea ver en pantalla?? [s:si, n:no]');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1794,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax,%ecx,%edx allocated
.Ll327:
	.stabn 68,0,634,.Ll327 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [634] readln(mostrar);
	call	fpc_get_input
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %edx allocated
	leal	-1124(%ebp),%edx
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	fpc_read_text_char
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_readln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %al allocated
.Ll328:
	.stabn 68,0,635,.Ll328 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [635] if mostrar='s' then
	movb	-1124(%ebp),%al
	# Register %al released
	cmpb	$115,%al
	je	.L1809
	jmp	.L1810
.L1809:
	# Register %eax allocated
.Ll329:
	.stabn 68,0,636,.Ll329 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [636] MostrarStdout(ruta);
	leal	-268(%ebp),%eax
	# Register %ecx,%edx allocated
	call	P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
	# Register %ecx,%edx,%al released
.L1810:
.Ll330:
	.stabn 68,0,637,.Ll330 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [637] salida:=true;
	movb	$1,-12(%ebp)
	# Register %al allocated
.Ll331:
	.stabn 68,0,638,.Ll331 - P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
# [638] end;
	movb	-12(%ebp),%al
# Temp -12,4 released
# Temp -268,256 released
# Temp -524,256 released
# Temp -1116,592 released
# Temp -1120,4 released
# Temp -1124,4 released
# Temp -521324,520200 released
# Temp -523364,2040 released
	# Register %ebx allocated
	movl	-523376(%ebp),%ebx
	# Register %esi allocated
	movl	-523372(%ebp),%esi
	# Register %edi allocated
	movl	-523368(%ebp),%edi
# Temp -523376,12 released
	leave
	# Register %ebp released
	ret
	# Register %al released
.L1821:
	.stabs "SALIDA:X32",160,0,0,-12
	.stabn 192,0,0,P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN-P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	.stabn 224,0,0,.L1821-P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN

.section .text
	.balign 4
	.balign 4
	.stabs "MOSTRARSTDOUT:F32",36,0,640,P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
	.stabs "RUTA:p1",160,0,560,-1120
	.stabs "result:32",160,0,640,-8
	.stabs "MAXLIN:c=i60;",36,0,642,0
	.stabs "I:5",160,0,644,-12
	.stabs "J:5",160,0,644,-16
	.stabs "ENTRADA:2",160,0,645,-608
	.stabs "LINEA:1",160,0,646,-864
.Ll332:
	.stabn 68,0,648,.Ll332 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [648] begin
.globl	P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN:
# Temps allocated between ebp-1380 and ebp-864
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	subl	$1380,%esp
# Temp -1380,4 allocated
	movl	%ebx,-1380(%ebp)
# Temp -4,4 allocated
# Var ruta located at ebp-4
# Temp -8,4 allocated
# Var $result located at ebp-8
# Temp -12,4 allocated
# Var i located at ebp-12
# Temp -16,4 allocated
# Var j located at ebp-16
# Temp -608,592 allocated
# Var entrada located at ebp-608
# Temp -864,256 allocated
# Var linea located at ebp-864
	# Register %eax allocated
	# Register %eax released
	movl	%eax,-4(%ebp)
	# Register %ebx allocated
	movl	-4(%ebp),%ebx
# Temp -1120,256 allocated
	# Register %ecx,%eax allocated
	leal	-1120(%ebp),%eax
	# Register %eax released
	movl	%eax,%ecx
	# Register %ebx released
	# Register %edx,%ebx allocated
	# Register %ebx released
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$255,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	FPC_SHORTSTR_ASSIGN
	# Register %eax,%ecx,%edx released
# Temp -4,4 released
	# Register %eax allocated
	movl	$1380,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	# Register %edx allocated
.Ll333:
	.stabn 68,0,651,.Ll333 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [651] assign(entrada,ruta);
	leal	-1120(%ebp),%edx
	# Register %eax allocated
	leal	-608(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	SYSTEM_ASSIGN$TEXT$SHORTSTRING
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
.Ll334:
	.stabn 68,0,653,.Ll334 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [653] reset(entrada);
	leal	-608(%ebp),%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_RESET$TEXT
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll335:
	.stabn 68,0,656,.Ll335 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [656] if IOresult<>0 then
	call	SYSTEM_IORESULT$$WORD
	# Register %ecx,%edx,%ax released
	# Register %eax allocated
	movzwl	%ax,%eax
	# Register %eax released
	testl	%eax,%eax
	jne	.L1830
	jmp	.L1831
.L1830:
	# Register %eax,%ecx,%edx allocated
.Ll336:
	.stabn 68,0,658,.Ll336 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [658] writeln('Archivo no existe');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1836,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
.Ll337:
	.stabn 68,0,659,.Ll337 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [659] MostrarStdout := false;
	movb	$0,-8(%ebp)
	jmp	.L1845
.L1831:
.Ll338:
	.stabn 68,0,663,.Ll338 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [663] i:=1;
	movb	$1,-12(%ebp)
.Ll339:
	.stabn 68,0,664,.Ll339 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [664] j:=maxlin;
	movb	$60,-16(%ebp)
.Ll340:
	.stabn 68,0,665,.Ll340 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [665] while not eof(entrada) do
	jmp	.L1851
	.balign 4
.L1850:
	# Register %ecx allocated
.Ll341:
	.stabn 68,0,667,.Ll341 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [667] readln(entrada,linea);
	movl	$255,%ecx
	# Register %edx allocated
	leal	-864(%ebp),%edx
	# Register %eax allocated
	leal	-608(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_read_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	leal	-608(%ebp),%eax
	# Register %ecx,%edx allocated
	call	fpc_readln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %dl allocated
.Ll342:
	.stabn 68,0,668,.Ll342 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [668] gotoxy(1,i);
	movb	-12(%ebp),%dl
	# Register %al allocated
	movb	$1,%al
	# Register %dl,%al released
	# Register %eax,%ecx,%edx allocated
	call	CRT_GOTOXY$BYTE$BYTE
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll343:
	.stabn 68,0,669,.Ll343 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [669] writeln(copy(linea,1,75));
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
# Temp -1376,256 allocated
	# Register %eax allocated
	leal	-1376(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$75,%ecx
	# Register %edx allocated
	movl	$1,%edx
	# Register %eax allocated
	leal	-864(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	leal	-1376(%ebp),%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
# Temp -1376,256 released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %dl allocated
.Ll344:
	.stabn 68,0,670,.Ll344 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [670] gotoxy(1,j);
	movb	-16(%ebp),%dl
	# Register %al allocated
	movb	$1,%al
	# Register %dl,%al released
	# Register %eax,%ecx,%edx allocated
	call	CRT_GOTOXY$BYTE$BYTE
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll345:
	.stabn 68,0,671,.Ll345 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [671] writeln(copy(linea,75,255));
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
# Temp -1376,256 allocated
	# Register %eax allocated
	leal	-1376(%ebp),%eax
	# Register %eax released
	pushl	%eax
	# Register %ecx allocated
	movl	$255,%ecx
	# Register %edx allocated
	movl	$75,%edx
	# Register %eax allocated
	leal	-864(%ebp),%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_shortstr_copy
	# Register %eax,%ecx,%edx released
	# Register %ecx allocated
	leal	-1376(%ebp),%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
# Temp -1376,256 released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax allocated
.Ll346:
	.stabn 68,0,672,.Ll346 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [672] if (i=maxlin)then
	movzbl	-12(%ebp),%eax
	# Register %eax released
	cmpl	$60,%eax
	je	.L1905
	jmp	.L1906
.L1905:
	# Register %eax,%ecx,%edx allocated
.Ll347:
	.stabn 68,0,674,.Ll347 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [674] writeln('Presione caulquier tecla para continuar...');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1911,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax,%ecx,%edx allocated
.Ll348:
	.stabn 68,0,675,.Ll348 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [675] readkey();
	call	CRT_READKEY$$CHAR
	# Register %ecx,%edx,%al released
	# Register %eax,%ecx,%edx allocated
.Ll349:
	.stabn 68,0,676,.Ll349 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [676] clrscr();
	call	CRT_CLRSCR
	# Register %eax,%ecx,%edx released
.Ll350:
	.stabn 68,0,677,.Ll350 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [677] i:=1;
	movb	$1,-12(%ebp)
.Ll351:
	.stabn 68,0,678,.Ll351 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [678] j:=maxlin;
	movb	$60,-16(%ebp)
	jmp	.L1922
.L1906:
	# Register %edx allocated
.Ll352:
	.stabn 68,0,682,.Ll352 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [682] i:=i+1;
	movzbl	-12(%ebp),%edx
	addl	$1,%edx
	jno	.L1925
	call	FPC_OVERFLOW
.L1925:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L1926
	call	FPC_RANGEERROR
.L1926:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-12(%ebp)
	# Register %edx allocated
.Ll353:
	.stabn 68,0,683,.Ll353 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [683] j:=j+1;
	movzbl	-16(%ebp),%edx
	addl	$1,%edx
	jno	.L1929
	call	FPC_OVERFLOW
.L1929:
	# Register %eax allocated
	movl	%edx,%eax
	# Register %eax released
	cmpl	$255,%eax
	jbe	.L1930
	call	FPC_RANGEERROR
.L1930:
	# Register %edx released
	# Register %dl allocated
	# Register %dl released
	movb	%dl,-16(%ebp)
.L1922:
.L1851:
	# Register %eax allocated
.Ll354:
	.stabn 68,0,665,.Ll354 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
	leal	-608(%ebp),%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_EOF$TEXT$$BOOLEAN
	# Register %ecx,%edx,%al released
	# Register %bl allocated
	movb	%al,%bl
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%bl released
	testb	%bl,%bl
	jne	.L1852
	jmp	.L1850
.L1852:
	# Register %eax allocated
.Ll355:
	.stabn 68,0,686,.Ll355 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [686] close(entrada);
	leal	-608(%ebp),%eax
	# Register %ecx,%edx allocated
	call	SYSTEM_CLOSE$TEXT
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
.Ll356:
	.stabn 68,0,687,.Ll356 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [687] MostrarStdout:=true;
	movb	$1,-8(%ebp)
.L1845:
	# Register %al allocated
.Ll357:
	.stabn 68,0,689,.Ll357 - P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
# [689] end;
	movb	-8(%ebp),%al
# Temp -8,4 released
# Temp -12,4 released
# Temp -16,4 released
# Temp -608,592 released
# Temp -864,256 released
# Temp -1120,256 released
	# Register %ebx allocated
	movl	-1380(%ebp),%ebx
# Temp -1380,4 released
	leave
	# Register %ebp released
	ret
	# Register %al released
.L1942:
	.stabs "MOSTRARSTDOUT:X32",160,0,0,-8
	.stabn 192,0,0,P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN-P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN
	.stabn 224,0,0,.L1942-P$STATIC_MOSTRARSTDOUT$SHORTSTRING$$BOOLEAN

.section .text
	.balign 4
	.balign 4
	.stabs "PRINCIPAL:F32",36,0,697,P$STATIC_PRINCIPAL$$BOOLEAN
	.stabs "result:32",160,0,697,-4
	.stabs "PATH:1",160,0,699,-260
	.stabs "TABLADATOS:34",160,0,700,-520460
	.stabs "RESULTADOS:4",160,0,701,-522500
.Ll358:
	.stabn 68,0,703,.Ll358 - P$STATIC_PRINCIPAL$$BOOLEAN
# [703] begin
.globl	P$STATIC_PRINCIPAL$$BOOLEAN
P$STATIC_PRINCIPAL$$BOOLEAN:
# Temps allocated between ebp-524552 and ebp-522504
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	# Register %edi allocated
	movl	$128,%edi
.L2012:
	subl	$4092,%esp
	pushl	%eax
	decl	%edi
	jne	.L2012
	# Register %edi released
	subl	$264,%esp
# Temp -524552,8 allocated
	movl	%ebx,-524552(%ebp)
	movl	%esi,-524548(%ebp)
# Temp -4,4 allocated
# Var $result located at ebp-4
# Temp -260,256 allocated
# Var path located at ebp-260
# Temp -520460,520200 allocated
# Var TablaDatos located at ebp-520460
# Temp -522500,2040 allocated
# Var Resultados located at ebp-522500
# Temp -522504,4 allocated
# Var existe located at ebp-522504
	# Register %eax allocated
	movl	$524552,%eax
	# Register %eax released
	# Register %eax,%ecx,%edx allocated
	call	FPC_STACKCHECK
	# Register %eax,%ecx,%edx released
	.balign 4
.L1945:
	# Register %eax,%ecx,%edx allocated
.Ll359:
	.stabn 68,0,705,.Ll359 - P$STATIC_PRINCIPAL$$BOOLEAN
# [705] clrscr();
	call	CRT_CLRSCR
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll360:
	.stabn 68,0,706,.Ll360 - P$STATIC_PRINCIPAL$$BOOLEAN
# [706] writeln('Archivo de entrada:');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1952,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax,%ecx,%edx allocated
.Ll361:
	.stabn 68,0,707,.Ll361 - P$STATIC_PRINCIPAL$$BOOLEAN
# [707] readln(path);
	call	fpc_get_input
	# Register %ecx,%edx,%eax released
	# Register %esi allocated
	movl	%eax,%esi
	# Register %ecx allocated
	movl	$255,%ecx
	# Register %eax allocated
	leal	-260(%ebp),%eax
	# Register %ebx allocated
	movl	%esi,%ebx
	# Register %eax released
	# Register %edx allocated
	movl	%eax,%edx
	# Register %ebx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_read_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%esi,%eax
	# Register %ecx,%edx allocated
	call	fpc_readln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%esi released
.Ll362:
	.stabn 68,0,708,.Ll362 - P$STATIC_PRINCIPAL$$BOOLEAN
# [708] while (inputfile(path) = false) do
	jmp	.L1970
	.balign 4
.L1969:
	# Register %eax,%ecx,%edx allocated
.Ll363:
	.stabn 68,0,710,.Ll363 - P$STATIC_PRINCIPAL$$BOOLEAN
# [710] clrscr();
	call	CRT_CLRSCR
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll364:
	.stabn 68,0,711,.Ll364 - P$STATIC_PRINCIPAL$$BOOLEAN
# [711] Writeln('AVISO: Escriba Archivo de Entrada Correcto: ');
	call	fpc_get_output
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$_$PROGRAM$_L1976,%ecx
	# Register %edx allocated
	movl	%ebx,%edx
	# Register %eax allocated
	movl	$0,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_write_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_writeln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
	# Register %eax,%ecx,%edx allocated
.Ll365:
	.stabn 68,0,712,.Ll365 - P$STATIC_PRINCIPAL$$BOOLEAN
# [712] readln(path);
	call	fpc_get_input
	# Register %ecx,%edx,%eax released
	# Register %ebx allocated
	movl	%eax,%ebx
	# Register %ecx allocated
	movl	$255,%ecx
	# Register %edx allocated
	leal	-260(%ebp),%edx
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx released
	# Register %ecx,%edx allocated
	call	fpc_read_text_shortstr
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx released
	# Register %eax allocated
	movl	%ebx,%eax
	# Register %ecx,%edx allocated
	call	fpc_readln_end
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
	call	FPC_IOCHECK
	# Register %eax,%ecx,%edx,%ebx released
.L1970:
	# Register %eax allocated
.Ll366:
	.stabn 68,0,708,.Ll366 - P$STATIC_PRINCIPAL$$BOOLEAN
	leal	-260(%ebp),%eax
	# Register %ecx,%edx allocated
	call	P$STATIC_INPUTFILE$SHORTSTRING$$BOOLEAN
	# Register %ecx,%edx,%al released
	testb	%al,%al
	jne	.L1971
	jmp	.L1969
.L1971:
	# Register %eax allocated
.Ll367:
	.stabn 68,0,714,.Ll367 - P$STATIC_PRINCIPAL$$BOOLEAN
# [714] until length(path)>0;
	movzbl	-260(%ebp),%eax
	# Register %eax released
	cmpl	$0,%eax
	jg	.L1947
	jmp	.L1945
.L1947:
	# Register %eax,%ecx,%edx allocated
.Ll368:
	.stabn 68,0,715,.Ll368 - P$STATIC_PRINCIPAL$$BOOLEAN
# [715] frecuencia;
	call	P$STATIC_FRECUENCIA
	# Register %eax,%ecx,%edx released
# Temp -524544,2040 allocated
	# Register %eax allocated
.Ll369:
	.stabn 68,0,716,.Ll369 - P$STATIC_PRINCIPAL$$BOOLEAN
# [716] puntomedio;
	leal	-524544(%ebp),%eax
	# Register %ecx,%edx allocated
	call	P$STATIC_PUNTOMEDIO$$READATA
	# Register %eax,%ecx,%edx released
# Temp -524544,2040 released
	# Register %edx allocated
.Ll370:
	.stabn 68,0,717,.Ll370 - P$STATIC_PRINCIPAL$$BOOLEAN
# [717] DataGen(TablaDatos,Resultados);
	leal	-522500(%ebp),%edx
	# Register %eax allocated
	leal	-520460(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_DATAGEN$TABLA$READATA
	# Register %eax,%ecx released
.Ll371:
	.stabn 68,0,718,.Ll371 - P$STATIC_PRINCIPAL$$BOOLEAN
# [718] Salida(TablaDatos,Resultados);
	leal	-522500(%ebp),%edx
	# Register %eax allocated
	leal	-520460(%ebp),%eax
	# Register %edx released
	# Register %ecx,%edx allocated
	call	P$STATIC_SALIDA$TABLA$READATA$$BOOLEAN
	# Register %ecx,%edx,%al released
.Ll372:
	.stabn 68,0,720,.Ll372 - P$STATIC_PRINCIPAL$$BOOLEAN
# [720] principal := true;
	movb	$1,-4(%ebp)
	# Register %al allocated
.Ll373:
	.stabn 68,0,722,.Ll373 - P$STATIC_PRINCIPAL$$BOOLEAN
# [722] end;
	movb	-4(%ebp),%al
# Temp -4,4 released
# Temp -260,256 released
# Temp -520460,520200 released
# Temp -522500,2040 released
# Temp -522504,4 released
	# Register %ebx allocated
	movl	-524552(%ebp),%ebx
	# Register %esi allocated
	movl	-524548(%ebp),%esi
# Temp -524552,8 released
	leave
	# Register %ebp released
	ret
	# Register %al released
.L2013:
	.stabs "PRINCIPAL:X32",160,0,0,-4
	.stabn 192,0,0,P$STATIC_PRINCIPAL$$BOOLEAN-P$STATIC_PRINCIPAL$$BOOLEAN
	.stabn 224,0,0,.L2013-P$STATIC_PRINCIPAL$$BOOLEAN

.section .text
	.balign 4
	.balign 4
	.stabs "main:F8",36,0,29,_main
.Ll374:
	.stabn 68,0,727,.Ll374 - PASCALMAIN
.globl	PASCALMAIN
PASCALMAIN:
.globl	_main
_main:
# Temps allocated between ebp+0 and ebp+0
	# Register %ebp allocated
	pushl	%ebp
	movl	%esp,%ebp
	# Register %eax,%ecx,%edx allocated
	call	FPC_INITIALIZEUNITS
	# Register %eax,%ecx,%edx released
	# Register %eax,%ecx,%edx allocated
.Ll375:
	.stabn 68,0,728,.Ll375 - _main
# [728] principal();
	call	P$STATIC_PRINCIPAL$$BOOLEAN
	# Register %ecx,%edx,%al released
.Ll376:
	.stabn 68,0,729,.Ll376 - _main
# [729] end.
	call	FPC_DO_EXIT
	leave
	# Register %ebp released
	ret
.L2019:
	.stabn 192,0,0,_main-_main
	.stabn 224,0,0,.L2019-_main

.section .data
	.long	DEBUGINFO_P$STATIC
	.balign 4

.section .data
	.stabd	70,0,731
# [731] 
	.ascii	"FPC 2.0.0 [2005/05/08] for i386 - Win32"
	.balign 4
	.balign 4
.globl	THREADVARLIST_P$STATIC
THREADVARLIST_P$STATIC:
	.long	0
	.balign 4
.globl	FPC_THREADVARTABLES
FPC_THREADVARTABLES:
	.long	11
	.long	THREADVARLIST_SYSTEM
	.long	THREADVARLIST_OBJPAS
	.long	THREADVARLIST_WINDOWS
	.long	THREADVARLIST_CRT
	.long	THREADVARLIST_STRINGS
	.long	THREADVARLIST_DOS
	.long	THREADVARLIST_SYSCONST
	.long	THREADVARLIST_SYSUTILS
	.long	THREADVARLIST_STRUTILS
	.long	THREADVARLIST_MATH
	.long	THREADVARLIST_P$STATIC
	.balign 4
.globl	FPC_RESOURCESTRINGTABLES
FPC_RESOURCESTRINGTABLES:
	.long	2
	.long	RESOURCESTRINGLIST_SYSCONST
	.long	RESOURCESTRINGLIST_MATH
	.balign 4
.globl	INITFINAL
INITFINAL:
	.long	5,0
	.long	INIT$_SYSTEM
	.long	FINALIZE$_SYSTEM
	.long	INIT$_OBJPAS
	.long	FINALIZE$_OBJPAS
	.long	INIT$_CRT
	.long	0
	.long	INIT$_DOS
	.long	0
	.long	INIT$_SYSUTILS
	.long	FINALIZE$_SYSUTILS
	.balign 4
.globl	__stklen
__stklen:
	.long	131072
.globl	__heapsize
__heapsize:
	.long	2097152

.section .data

.section .data
	.balign 4
.globl	_$PROGRAM$_L44
_$PROGRAM$_L44:
# value: 0d+2.0000000000000000E+0000
	.byte	0,0,0,0,0,0,0,128,0,64

.section .data
	.balign 4
.globl	_$PROGRAM$_L60
_$PROGRAM$_L60:
# value: 0d+1.0000000000000000E-0003
	.byte	59,223,79,141,151,110,18,131,245,63

.section .data
	.balign 4
.globl	_$PROGRAM$_L350
_$PROGRAM$_L350:
	.stabd	70,0,290
	.ascii	"6Error: imposible calcular mediana, division entre "
	.ascii	"cero\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L359
_$PROGRAM$_L359:
# value: 0d-1.000000000000000E+000
	.byte	0,0,0,0,0,0,240,191

.section .data
	.balign 4
.globl	_$PROGRAM$_L457
_$PROGRAM$_L457:
# value: 0d+1.0000000000000000E+0001
	.byte	0,0,0,0,0,0,0,160,2,64

.section .data
	.balign 4
.globl	_$PROGRAM$_L643
_$PROGRAM$_L643:
	.stabd	70,0,411
	.ascii	"\007 fase: \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L656
_$PROGRAM$_L656:
	.ascii	"\010 index: \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L669
_$PROGRAM$_L669:
	.ascii	"\010 linea: \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L686
_$PROGRAM$_L686:
	.stabd	70,0,413
	.ascii	"\010MEDIAARI\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L695
_$PROGRAM$_L695:
	.stabd	70,0,414
	.ascii	"\007MEDIANA\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L704
_$PROGRAM$_L704:
	.stabd	70,0,415
	.ascii	"\004MODA\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L713
_$PROGRAM$_L713:
	.stabd	70,0,416
	.ascii	"\010MEDIAARM\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L722
_$PROGRAM$_L722:
	.stabd	70,0,417
	.ascii	"\010MEDIAGEO\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L731
_$PROGRAM$_L731:
	.stabd	70,0,418
	.ascii	"\010VARIANZA\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L740
_$PROGRAM$_L740:
	.stabd	70,0,419
	.ascii	"\010DESVIACI\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L774
_$PROGRAM$_L774:
	.stabd	70,0,449
	.ascii	"\021archivo no existe\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L792
_$PROGRAM$_L792:
	.stabd	70,0,456
	.ascii	"0Leyendo y Analizando el archivo de texto dado...\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L842
_$PROGRAM$_L842:
	.stabd	70,0,464
	.ascii	"\006TITULO\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L867
_$PROGRAM$_L867:
	.stabd	70,0,468
	.ascii	"\007titulo:\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L886
_$PROGRAM$_L886:
	.stabd	70,0,472
	.ascii	"\006INTERV\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L897
_$PROGRAM$_L897:
	.stabd	70,0,477
	.ascii	"\005DATOS\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L908
_$PROGRAM$_L908:
	.stabd	70,0,482
	.ascii	"\006CALCUL\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L945
_$PROGRAM$_L945:
	.stabd	70,0,506
	.ascii	"\033Generando Tabla de Datos...\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L956
_$PROGRAM$_L956:
	.stabd	70,0,507
	.ascii	")  Calculando datos para los intervalos...\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1117
_$PROGRAM$_L1117:
	.stabd	70,0,543
	.ascii	",  Calculando Medidas de Tendencia Central...\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1167
_$PROGRAM$_L1167:
	.stabd	70,0,573
	.ascii	"#ingrese nombre de archivo de salida\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1194
_$PROGRAM$_L1194:
	.stabd	70,0,583
	.ascii	"\031Creando Tabla en archivo \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1207
_$PROGRAM$_L1207:
	.ascii	"\004....\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1216
_$PROGRAM$_L1216:
	.stabd	70,0,584
	.ascii	"!                               -=\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1229
_$PROGRAM$_L1229:
	.ascii	"\002=-\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1238
_$PROGRAM$_L1238:
	.stabd	70,0,585
	.ascii	"p+___+__________+_____+__________+__________+_____+"
	.ascii	"__________+______+_______+_______+____+______+_____"
	.ascii	"__+_______+\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1247
_$PROGRAM$_L1247:
	.stabd	70,0,586
	.ascii	"p|   |          |     |          |          |Total|"
	.ascii	"          |      |       |       |    | X=   |     "
	.ascii	"  |       |\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1256
_$PROGRAM$_L1256:
	.stabd	70,0,587
	.ascii	"p|No.|Intervalo |Punto|Frecuencia|Desviacion|Desv.|"
	.ascii	"Frecuencia| Log  |  f*   |Inverso| f* |PM-   | f*x "
	.ascii	"  | f*x^2 |\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1265
_$PROGRAM$_L1265:
	.stabd	70,0,588
	.ascii	"p|   |          |Medio|    f     | v=PM-A   |f*v  |"
	.ascii	"Acumulada | (PM) |Log(PM)| 1/PM  |1/PM| MAR  |     "
	.ascii	"  |       |\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1274
_$PROGRAM$_L1274:
	.stabd	70,0,589
	.ascii	"p+===+==========+=====+==========+==========+=====+"
	.ascii	"==========+======+=======+=======+====+======+====="
	.ascii	"==+=======+\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1320
_$PROGRAM$_L1320:
	.stabd	70,0,593
	.ascii	"\004  < \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1372
_$PROGRAM$_L1372:
	.stabd	70,0,595
	.ascii	"\005    |\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1390
_$PROGRAM$_L1390:
	.ascii	"\006     |\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1554
_$PROGRAM$_L1554:
	.stabd	70,0,601
	.ascii	"p+---+----------+-----+----------+----------+-----+"
	.ascii	"----------+------+-------+-------+----+------+-----"
	.ascii	"--+-------+\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1572
_$PROGRAM$_L1572:
	.stabd	70,0,607
	.ascii	"\030|   |   Total  |     | =\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1591
_$PROGRAM$_L1591:
	.stabd	70,0,608
	.ascii	"\015|          |=\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1610
_$PROGRAM$_L1610:
	.ascii	"\024|          |      |=\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1629
_$PROGRAM$_L1629:
	.stabd	70,0,609
	.ascii	"\011|       |\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1648
_$PROGRAM$_L1648:
	.stabd	70,0,610
	.ascii	"\021|      |       |=\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1700
_$PROGRAM$_L1700:
	.stabd	70,0,619
	.ascii	"\022Media Aritmetica: \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1707
_$PROGRAM$_L1707:
	.stabd	70,0,620
	.ascii	"\012Mediana : \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1714
_$PROGRAM$_L1714:
	.stabd	70,0,621
	.ascii	"\007Moda : \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1721
_$PROGRAM$_L1721:
	.stabd	70,0,622
	.ascii	"\023Media Geometrica : \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1728
_$PROGRAM$_L1728:
	.stabd	70,0,623
	.ascii	"\021Media Armonica : \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1735
_$PROGRAM$_L1735:
	.stabd	70,0,624
	.ascii	"\013Varianza : \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1742
_$PROGRAM$_L1742:
	.stabd	70,0,625
	.ascii	"\025Desviacion Estandar: \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1770
_$PROGRAM$_L1770:
	.stabd	70,0,631
	.ascii	"\010Archivo \000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1783
_$PROGRAM$_L1783:
	.ascii	"\033 creado satisfactoriamente.\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1794
_$PROGRAM$_L1794:
	.stabd	70,0,633
	.ascii	"$Desea ver en pantalla?? [s:si, n:no]\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1836
_$PROGRAM$_L1836:
	.stabd	70,0,658
	.ascii	"\021Archivo no existe\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1911
_$PROGRAM$_L1911:
	.stabd	70,0,674
	.ascii	"*Presione caulquier tecla para continuar...\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1952
_$PROGRAM$_L1952:
	.stabd	70,0,706
	.ascii	"\023Archivo de entrada:\000"

.section .data
	.balign 4
.globl	_$PROGRAM$_L1976
_$PROGRAM$_L1976:
	.stabd	70,0,711
	.ascii	",AVISO: Escriba Archivo de Entrada Correcto: \000"

.section .data

.section .data
	.balign 4
	.stabd	70,0,32
# [32] ArrData  = array [1..max] of integer;
.globl	_$PROGRAM$_L4
_$PROGRAM$_L4:
	.byte	1
	.ascii	"\010SmallInt"
	.byte	2
	.long	-32768,32767

.section .data
	.balign 4
.globl	RTTI__P$STATIC_ARRDATA
RTTI__P$STATIC_ARRDATA:
	.byte	12
	.ascii	"\007ArrData"
	.long	2,255
	.long	_$PROGRAM$_L4

.section .data
	.balign 4
	.stabd	70,0,34
# [34] ReaData  = array [1..max] of real;
.globl	_$PROGRAM$_L5
_$PROGRAM$_L5:
	.byte	4
	.ascii	"\006Double"
	.byte	1

.section .data
	.balign 4
.globl	RTTI__P$STATIC_READATA
RTTI__P$STATIC_READATA:
	.byte	12
	.ascii	"\007ReaData"
	.long	8,255
	.long	_$PROGRAM$_L5

.section .data
	.balign 4
	.stabd	70,0,35
# [35] Tabla    = array [1..max] of ReaData;
.globl	RTTI__P$STATIC_TABLA
RTTI__P$STATIC_TABLA:
	.byte	12
	.ascii	"\005Tabla"
	.long	2040,255
	.long	RTTI__P$STATIC_READATA

.section .data
	.balign 4
	.stabd	70,0,36
# [36] BoolArr  = array [1..7] of boolean;
.globl	_$PROGRAM$_L6
_$PROGRAM$_L6:
	.byte	18
	.ascii	"\007Boolean"
	.byte	1
	.long	0,1

.section .data
	.balign 4
.globl	RTTI__P$STATIC_BOOLARR
RTTI__P$STATIC_BOOLARR:
	.byte	12
	.ascii	"\007BoolArr"
	.long	1,7
	.long	_$PROGRAM$_L6

.section .data

.section .bss

.section .bss
	.balign 4
	.stabs "TITULO:S1",40,0,38,U_P$STATIC_TITULO
	.stabd	72,0,38
# [38] titulo.      : string[max];
	.lcomm	U_P$STATIC_TITULO,256

.section .bss
	.balign 4
	.stabs "ENTRADA:S2",40,0,39,U_P$STATIC_ENTRADA
	.stabd	72,0,39
# [39] entrada.      : Text; (*archivo de entrada*)
	.lcomm	U_P$STATIC_ENTRADA,592

.section .bss
	.balign 4
	.stabs "INTERVD:S3",40,0,40,U_P$STATIC_INTERVD
	.stabd	72,0,40
# [40] intervD.      : ArrData;(* intervalos *)
	.lcomm	U_P$STATIC_INTERVD,510

.section .bss
	.balign 4
	.stabs "INTERVI:S3",40,0,41,U_P$STATIC_INTERVI
	.stabd	72,0,41
# [41] intervI.      : ArrData;
	.lcomm	U_P$STATIC_INTERVI,510

.section .bss
	.balign 4
	.stabs "FREC:S3",40,0,42,U_P$STATIC_FREC
	.stabd	72,0,42
# [42] frec..      : ArrData; (* datos importantes *)
	.lcomm	U_P$STATIC_FREC,510

.section .bss
	.balign 4
	.stabs "DATOS:S4",40,0,43,U_P$STATIC_DATOS
	.stabd	72,0,43
# [43] datos.      : ReaData;
	.lcomm	U_P$STATIC_DATOS,2040

.section .bss
	.stabs "NUMINTERV:S5",40,0,44,U_P$STATIC_NUMINTERV
	.stabd	72,0,44
# [44] numinterv,numdatos : byte;
	.lcomm	U_P$STATIC_NUMINTERV,1

.section .bss
	.stabs "NUMDATOS:S5",40,0,44,U_P$STATIC_NUMDATOS
	.lcomm	U_P$STATIC_NUMDATOS,1

.section .bss
	.balign 4
	.stabs "CALCULAR:S6",40,0,45,U_P$STATIC_CALCULAR
	.stabd	72,0,45
# [45] calcular.      : BoolArr;{bandera para calculos}
	.lcomm	U_P$STATIC_CALCULAR,7

.section .text
	.stabs "",100,0,0,.Letext
.Letext:

