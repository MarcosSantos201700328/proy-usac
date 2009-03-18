Const timeout = 50
Const num = 1000
TRISA = 0

'rutina de giro
'Proc rotate4(num As integer, timeout As integer)
'rotate4(1000, 50)

PORTA = 0



Dim rot As Word
Dim i As Word
Dim j As Byte


For i = 0 To num
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
'		WaitMs timeout
	Next j	
Next i
'End Proc

' main



