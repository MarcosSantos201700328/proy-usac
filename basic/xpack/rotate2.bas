Const timeout = 50
Const num = 1000
TRISA = 0

'rutina de giro
'Proc rotate4(num As integer, timeout As integer)
'rotate4(1000, 50)

PORTA = 0

Dim i As Word
Dim j As Byte


For i = 0 To num
	PORTA = %01
	WaitMs timeout
	PORTA = %10
	WaitMs timeout
Next i
'End Proc

' main



