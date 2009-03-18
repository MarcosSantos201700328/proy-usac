'ESPECIFICACIONES:
'PUERTO B:
' RB0, RB1. MOTOR PLASTICO 1
' RB2, RB3. MOTOR PLASTICO 2
' RB4, RB5. MOTOR TENAZA
' RB6, RB7. MOTOR TENAZA inversa

'PUERTO A:
' RA0, RA1,RA2,RA3. MOTOR EMBUDO
' RA4. RESISTENCIAS CALOR

'Motores plastico
Const timeout1 = 0  '50
Const num1 = 4  '1000
'motor tenazas fase 1
Const timeout2 = 0  '50
Const num2 = 4  '1000
'motor tenazas fase 2
Const timeout3 = 0  '50
Const num3 = 4  '1000
'motor embudo
Const timeout4 = 0  '50
Const num4 = 4  '1000
'resistencia calor
Const timeout5 = 0  '500
'tiempo de llenado
Const timeout6 = 0  '150

'asignamos todos los puertos como salidas
TRISA = 0
TRISB = 0
TRISC = 0

PORTA = 0
PORTB = 0
'-------INICIO----------
'movemos motores de plastico
Dim i As Word
Dim j As Byte

For i = 0 To num1
	PORTB = %00000101
	WaitMs timeout1
	PORTB = %00001010
	WaitMs timeout1
Next i
'apagamos motores plastico
PORTB = 0
'activamos tenazas

For i = 0 To num2
	PORTB = %00010000
	WaitMs timeout2
	PORTB = %00100000
	WaitMs timeout2
Next i

'activamos portezuela embudo
Dim rot As Word

For i = 0 To num3
	rot = %0011
	For j = 0 To 3
		If j = 0 Then
			PORTA = rot
		Else
			If j = 3 Then
				PORTA = %1001
			Else			
				rot = ShiftLeft(rot, 1)
				PORTA = rot
			Endif
		Endif
		WaitMs timeout3
	Next j	
Next i
WaitMs timeout6
'cerramos portezuela
For i = 0 To num3
	rot = %1100
	For j = 0 To 3
		If j = 0 Then
			PORTA = rot
		Else
			If j = 3 Then
				PORTA = %1001
			Else			
				rot = ShiftRight(rot, 1)
				PORTA = rot
			Endif
		Endif
		WaitMs timeout3
	Next j	
Next i

'cerramos tenazas
For i = 0 To num4
	PORTB = %10000000
	WaitMs timeout4
	PORTB = %01000000
	WaitMs timeout4
Next i
'encendemos resistencia
PORTA = %10000000
WaitMs timeout5
'apagamos resistencias
PORTA = 0
'abrimos tenazas
' como usamos reversa en motor 2 fases???

'---------FIN-----------

