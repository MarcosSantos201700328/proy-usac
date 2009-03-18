; Begin
	R0L EQU 0x20
	R0H EQU 0x21
	R1L EQU 0x22
	R1H EQU 0x23
	R2L EQU 0x24
	R2H EQU 0x25
	R3L EQU 0x26
	R3H EQU 0x27
	R4L EQU 0x28
	R4H EQU 0x29
	R5L EQU 0x2A
	R5H EQU 0x2B
	ORG 0x0000
	BCF PCLATH,3
	BCF PCLATH,4
	GOTO L0001
	ORG 0x0004
	RETFIE
L0001:
; 1: AllDigital
	BSF STATUS,RP0
	MOVLW 0x06
	MOVWF 0x1F
	BCF STATUS,RP0
; 2: 
; 3: TRISA = %11111111 'los primeros 2 pines del puerto a de entrada
	BSF STATUS,RP0
	MOVLW 0xFF
	MOVWF 0x05
	BCF STATUS,RP0
; 4: TRISB = %00000000 ' todo el puerto b de salida
	BSF STATUS,RP0
	CLRF 0x06
	BCF STATUS,RP0
; 5: 
; 6: Symbol exitb = PORTA.0
;       The address of 'exitb' is 0x5,0
; 7: Symbol run = PORTA.1
;       The address of 'run' is 0x5,1
; 8: Symbol stepper = PORTB
;       The address of 'stepper' is 0x6
	stepper EQU 0x6
; 9: 
; 10: While exitb = 0 '
L0002:
	BTFSC 0x05,0
	GOTO L0003
; 11: stepper = 1
	MOVLW 0x01
	MOVWF 0x06
; 12: While run = 1
L0004:
	BTFSS 0x05,1
	GOTO L0005
; 13: stepper = ShiftLeft(stepper, 1)
	MOVF 0x06,W
	MOVWF R0L
	CLRF R0H
	MOVLW 0x01
	CALL SL00
	MOVWF 0x06
; 14:  '		WaitMs 50
; 15: If stepper = %1000 Then
	MOVF 0x06,W
	SUBLW 0x08
	BTFSS STATUS,Z
	GOTO L0006
; 16: stepper = 1
	MOVLW 0x01
	MOVWF 0x06
; 17:  '			WaitMs 50
; 18: Endif
L0006:	MOVLW 0x1F
	ANDWF STATUS,F
; 19: Wend
	GOTO L0004
L0005:	MOVLW 0x1F
	ANDWF STATUS,F
; 20: Wend
	GOTO L0002
L0003:	MOVLW 0x1F
	ANDWF STATUS,F
; 21: 
; End of program
L0007:	GOTO L0007
; ShiftLeft Routine
SL01:	BCF STATUS,C
	RLF R0L,F
	RLF R0H,F
SL00:	ADDLW 0xFF
	BTFSC STATUS,C
	GOTO SL01
	MOVF R0L,W
	RETURN
; End of listing
	END
