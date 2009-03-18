bits 16
org 100h
%include "macros.mac"
;fixme delay
;fixme funcion x(detectar niveles)
;;--------------------------------------------------------------------------------------
;; DATOS
section .data
breakline: db 10,13,'$'
pregunta1: db 10,13,"Desea Continuar?, s: si, otra tecla: no.",10,13,'$' ;; pregunta de main
preguntavol: db 10,13,"Ingrese volumen (en centilitros):",10,13,'$' ;; pregunta de volumen
preguntacant: db 10,13,"Ingrese cantidad de envases (en centilitros):",10,13,'$' ;; pregunta de cantidad
estado_title: db 10,13,"Estado: ",'$' ; titulo de estado
estado_esperando: db 10,13,"Esperando recipiente.",10,13,'$' ;estado de esperando recipiente
estado_error_nrecip: db 10,13,"ERROR, no se encontro recipiente",10,13,'$' ;  estado de error sino hay recipiente
estado_vasolleno: db 10,13,"Recipiente llenado satisfactoriamente.",10,13,'$' ;  estado de vaso lleno
estado_llenando_backup: db 10,13,"Llenando tanque principal.",10,13,'$' ; 
estado_llenando_vaso: db 10,13,"Llenando Recipiente. Presione t para detener",10,13,'$' ; 
errnum: db 10,13,"Por favor ingrese un entre 1 y 9.",10,13,'$'
;respuesta1: resb 1 ;; respuesta de main
volumen: db 0 ;; se almacenara aqui los mililitros
cantidad: db 0 ;; se almacenara aqui la cantidad de botellas a llenar
tiempollenado: db 3
;recipiente detectado
rdetectado db 0
;nivel de agua
nivel db 0
;tipo de reporte
tipo_reporte db 0
hora: db 0;;hora para delay
minuto: db 0;; minuto para delay
segundo: db 0;; segundo para delay

horabak: db 0;;backup hora para delay 
minutobak: db 0;;backup minuto para delay
segundobak: db 0;;backup segundo para delay

;puertos ppic
data_port_a: db 00000000b
data_port_b: db 00000000b
data_port_c: db 00000000b
;;--------------------------------------------------------------------------------------	
section .text
;;/****************** MAIN **********************************/
global _start
_start:
init:;inicializamos ppic
	writeppic pconf,aout_bin_cin
	writeppic pa,00000000b
main:
;	escribirchar 'a'
	call pedir_datos ; llamamos a subrutina de pedir datos
	call calcular_tiempo ; calculamos tiempo de llenado
;	mov dx,estado_esperando
;	call escribir_estado
	call procesar_tarea ; llamamos a subrutina de procesar
	;call enviar_reporte; llamamos a subrutina de enviar reporte
	escribirstring pregunta1; ; escribimos pregunta	
	leerchar
	cmp al,'s' 
	jz main ; si presiono s, continua ejecucion
	jmp exitp ; si no se sale del programa
	
;/// rutina de salida
exitp: mov ax,0x4c00 
	int 0x21
	

;;/****************** PEDIR_DATOS **********************************/
pedir_datos:
	enter 0,0
	pusha
start_pedirdatos:
	;escribirchar 'b'
	;pregunta de volumen
escribir_volumen:
	escribirstring preguntavol
	leerchar
	;cmp al,'0';
	;jz storevol
	cmp al,'1'; validamos del 1 al 9
	jz storevol
	cmp al,'2';
	jz storevol
	cmp al,'3';
	jz storevol
	cmp al,'4';
	jz storevol
	cmp al,'5';
	jz storevol
	cmp al,'6';
	jz storevol
	cmp al,'7';
	jz storevol
	cmp al,'8';
	jz storevol
	cmp al,'9';
	jz storevol
	jmp msgerrvol
msgerrvol: ; escribimos mensaje de error
	escribirstring errnum;
	jmp escribir_volumen;	
storevol: ;almacena valor leido
	sub al,'0'
	mov [volumen],al	
	jmp escribir_cantidad
	; pregunta de cantidad
escribir_cantidad:
	escribirstring preguntacant
	leerchar
	;cmp al,'0';
	;jz storecant
	cmp al,'1'; validamos del 1 al 9;
	jz storecant
	cmp al,'2';
	jz storecant
	cmp al,'3';
	jz storevol
	cmp al,'4';
	jz storecant
	cmp al,'5';
	jz storecant
	cmp al,'6';
	jz storecant
	cmp al,'7';
	jz storecant
	cmp al,'8';
	jz storecant
	cmp al,'9';
	jz storecant
	jmp msgerrcant
msgerrcant: ; escribimos mensaje de error
	escribirstring errnum;	
	jmp escribir_cantidad;	
storecant: ;almacena valor leido
	sub al,'0'
	mov [cantidad],al	
	jmp end_pedirdatos;
end_pedirdatos:
	;-debug
	;escribirstring breakline
	;escribirchar [volumen]
	;escribirchar [cantidad]
	;escribirstring breakline
	;-end debug
	popa
	leave
	ret 0
	
;;/****************** PROCESAR_TAREA **********************************/
;;subrutina que procesa la tarea de llenado
procesar_tarea:
	enter 0,0
	pusha
	;escribirchar 'c'
start_procesar_tarea:
	mov cl,[cantidad] ;contador de vasos
ciclo_vasos: ;inicio ciclo vasos
	mov cl,[cantidad]
	cmp cl,0
	jz set_reporte_OK; escribimos reporte bueno
	; escribimos estado
	mov dx,estado_esperando
	call escribir_estado
	;encendemos banda
	call encender_banda
	;seteamos hora para delay de la banda
;	mov bl,[tiempo_espera_recipiente]
;	call set_hora_delay
	;esperamos recipiente
esperar_recipiente:
	;call encender_banda ;debug
	call detectar_recipiente
	mov dx,[rdetectado]
	cmp dx,1 ; si sedetecto se debe detener la banda
	;detenemos banda
	je detener_banda
;	call cmp_hora_delay ;llamar  hasta que delay se implemente
	mov bh,1
	cmp bh,0 ; si no se ha cumplido el tiempo, seguimos esperando
	jne esperar_recipiente	
	call apagar_banda
	mov dx,estado_error_nrecip
	call escribir_estado
	jmp set_reporte_ERROR ; sino detenemos banda  y escribimos reporte de error
detener_banda:
	;apagamos banda
	call apagar_banda
	;llenamos
	call llenar
	;decrementamos cl
	mov cl,[cantidad]
	dec cl
	mov [cantidad],cl
	jmp ciclo_vasos
set_reporte_OK:
	mov bl,reporte_OK
	call escribir_reporte_serial
	mov dx,estado_vasolleno
	call escribir_estado
	jmp salida_pt
set_reporte_ERROR:
	mov bl,reporte_error
	call escribir_reporte_serial
	jmp salida_pt
salida_pt:
	popa
	leave
	ret 0
;;/****************** SET_HORA_DELAY **********************************/
;; Asigna hora a la que alguna tarea debe terminar, dependiendo del macro delay para tiempo limite
;; bl:input, cantidad de segundos de retardo
set_hora_delay:
	enter 0,0
	push ax
	push cx
	push dx
	;escribirchar 'd'
	leer_hora 
	; comparamos segundos
	add bl,dh
	cmp bl,60
	jge inc_min
	jmp set_hora_mem
	;incrementamos minutos
inc_min:
	inc cl
	cmp cl,60	
	jne reset_seg;
	;incrementamos hora si se alcanzo los 60 minutos
	inc ch
	mov cl,0	
	; asignamos nuevo valor a seg como seg = seg-60
reset_seg:
	sub bl,60
	jmp set_hora_mem
	;asignamos hora actual a memoria
set_hora_mem:
	mov [hora],ch
	mov [minuto],cl
	mov [segundo],dh
	;debug
;	leer_hora
;	mov [hora],ch
;	mov [minuto],cl
;	mov [segundo],dh
	;enddebug
	pop dx
	pop cx
	pop ax
	leave
	ret 0
;;/****************** CMP_HORA_DELAY **********************************/
; Compara hora actual con hora en la que la tarea debe terminar
;; bh, salida, 1 se alcanzo la hora limite,0 no se ahcanzo
; bh
cmp_hora_delay:
	enter 0,0
	push ax
	push cx
	push dx
	;escribirchar 'e'
	leer_hora
	mov bh,0;
	;debug
	call printhora ;debug
	;panic key
	leerchar
	cmp al,'t'
	jnz incbh
	jmp exit_chd
	;end panic
	;comparamos hora	
	mov bl,[hora]
	cmp bl,ch
	je incbh;
	mov bl,[minuto]
	cmp bl,cl
	je incbh;
	mov bl,[segundo]
	cmp bl,dh 
	je incbh;
	
	jmp exit_chd
	;incrementamos bh si no se ha alcanzado hora limite
incbh:
	inc bh
exit_chd:
	pop dx
	pop cx
	pop ax
	leave
	ret 0

;;/****************** ESCRIBIR_ESTADO **********************************/
; Escribe en pantalla el estado actual de la embotelladora
;; dx apunta al mensaje que se quiere mostrar
escribir_estado:
	enter 0,0
	push ax
	push bx
	push cx
	
	
	; asignamos 
	mov cx,dx
	push dx
	;escribirchar 'f'
	;escribimos a pantalla
	escribirstring estado_title
	escribirstring cx	
	escribirstring breakline
	pop dx
	pop cx
	pop bx
	pop ax
	leave
	ret 0

;;/****************** ENCENDER_BANDA **********************************/
; enciende banda de la embotelladora
encender_banda
	enter 0,0
	pusha
	;escribirchar 'g'
	mov bx,[data_port_a];
	;probamos bit de la banda
	bt bx,0
	;si esta encendida, la dejamos encendida
	;writeppic pa,11111111b	;debug
	jc exit_ebanda
	;sino encendemos la banda si se encuentra apagada
	xor bl,00000001b
	
	writeppic pa,bl	
	;writeppic pa,11111111b	;debug
	mov [data_port_a],bx
	
exit_ebanda:
	clc ;borramos carry
	popa
	leave
	ret 0
	
;;/****************** APAGAR_BANDA **********************************/
; apaga banda de la embotelladora
apagar_banda
	enter 0,0
	pusha
	;escribirchar 'h'
	mov bx,[data_port_a]
	;probamos bit de la banda
	bt bx,0
	;si esta apagada, la dejamos apagada
	jnc exit_abanda
	;sino apagamos la banda si se encuentra encendida
	xor bl,00000001b
	writeppic pa,bl
	mov [data_port_a],bx
exit_abanda:
	clc ;borramos carry
	popa
	leave
	ret 0
;;/****************** DETECTAR_RECIPIENTE **********************************/
; lee ojo electronico para ver si se detecto algun recipiente
detectar_recipiente:
	enter 0,0
	pusha
	clc
	;escribirchar 'q'
	;leemos puerto c
	
	readppic pc	
	;si bit 0 (ojo) esta encendido, no se ha detectado nada
	;bt ax,0
	bt ax,0
	jnc set_rdetectado
	;escribirchar 'z'
	jmp set_rnodetectado
	;jnc exit_drecipiente	
set_rnodetectado:
	mov dx,0
	mov [rdetectado],dx
	jmp exit_drecipiente
set_rdetectado:
	;escribimos en memoria si se detecto algo
	mov dx,1
	mov [rdetectado],dx
	;escribirchar 'o'
	jmp exit_drecipiente
exit_drecipiente:
	clc ;borramos carry
	popa
	leave
	ret 0

;;/****************** LLENAR **********************************/
; Controla el llenado de recipientes
llenar:
	enter 0,0
	pusha
	;escribirchar 'i'
	;leer niveles
test_nivel_bajo:
	call leer_niveles;
	mov dx,[nivel]
	cmp dx,1; nivel bajo
	jz encenderbombab
	jmp escribir_estado_llenando_backup
	;encendemos bomba
encenderbombab:
	call encender_bomba_b;
	jmp test_nivel_alto
	;probamos si el nivel alto
test_nivel_alto:
	call leer_niveles;
	mov dx,[nivel]
	cmp dx,8; nivel alto
	jz togglebombas
	jmp encenderbombab
	;escribimos estado
escribir_estado_llenando_backup:
	mov dx,estado_llenando_backup
	call escribir_estado
	jmp test_nivel_alto;
togglebombas:
	call encender_bomba_a;
	call apagar_bomba_b;
	mov dx,estado_llenando_vaso
	call escribir_estado	
	call llenar_vaso ;delay para llenado de vaso
	call apagar_bomba_a;	
exit_llenar:
	clc ;borramos carry
	popa
	leave
	ret 0

;;/****************** LLENAR_VASO **********************************/
; delay para llenado de vaso, mantiene bomba encendida
llenar_vaso:
	enter 0,0
	pusha
	;escribirchar 'j'
	;copiamos hora delay a backup
	mov dx,[hora]
	mov cx,[minuto]
	mov bx,[segundo]
	mov [horabak],dx
	mov [minutobak],cx
	mov [segundobak],bx
	;seteamos tiempo de llenado
	mov bl,[tiempollenado]
	call set_hora_delay
	;mantenemos la bomba encendida
ll_enc_pump_a:
	call encender_bomba_a;
	;verificamos si ya se cumplio el tiempo
	call cmp_hora_delay
	cmp bh,0 ; si no se ha cumplido el tiempo, seguimos esperando
	jne ll_enc_pump_a	
	;restablecemos hora delay
	mov dx,[horabak]
	mov cx,[minutobak]
	mov bx,[segundobak]
	mov [hora],dx
	mov [minuto],cx
	mov [segundo],bx
	
	popa
	leave
	ret 0

;;/****************** CALCULAR_TIEMPO **********************************/
; Calcula tiempo de llenado de un vaso y lo almacena en memoria
calcular_tiempo:
	enter 0,0
	pusha
	;escribirchar 'k'
	mov al,tiempo_llenado_unidad	
	mov dx,cantidad
	mul dl
	mov [tiempollenado],ax
	popa
	leave
	ret 0

;;/****************** LEER_NIVELES **********************************/
; Lee niveles desde el ppic, lo interpreta y lo almacena en memorai
leer_niveles:
	enter 0,0
	pusha
	;escribirchar 'x'
	clc
	;leemos ppic
	readppic pc
	;probamos nivel alto
	bt ax,2	
	jnc set_nivel_bajo	
	bt ax,1	
	jc set_nivel_alto
	jmp exit_leerniveles
set_nivel_alto: ;seteamos nivel alto
	mov bx,8
	mov [nivel],bx
	;escribirchar '1'
	jmp exit_leerniveles;
set_nivel_bajo ;seteamos nivel bajo
	mov bx,1
	mov [nivel],bx
	;escribirchar '2'
	jmp exit_leerniveles
exit_leerniveles:
	clc
	popa
	leave
	ret 0

;;/****************** ENCENDER_BOMBA_B **********************************/
; Enciende bomba de backup (b)
encender_bomba_b:
	enter 0,0
	pusha
	;escribirchar 'm'
	mov bx,[data_port_a];
	;probamos bit de la bomba
	bt bx,2
	;si esta encendida, la dejamos encendida
	jc exit_encender_bombab
	;sino encendemos la banda si se encuentra apagada
	xor bl,00000100b
	writeppic pa,bl		
	mov [data_port_a],bx ; actualizamos estado
exit_encender_bombab:
	popa
	leave
	ret 0
;;/****************** APAGAR_BOMBA_B **********************************/
; apaga bomba de backup (b)
apagar_bomba_b:
	enter 0,0
	pusha
	;escribirchar 'n'
	mov bx,[data_port_a];
	;probamos bit de la bomba
	bt bx,2
	;si esta apagada, la dejamos apagada
	jnc exit_apagar_bombab
	;sino apagamos la banda si se encuentra encendida
	xor bl,00000100b
	writeppic pa,bl		
	mov [data_port_a],bx; actualizamos estado
exit_apagar_bombab:
	popa
	leave
	ret 0
;;/****************** ENCENDER_BOMBA_A **********************************/
; Enciende bomba de principal
encender_bomba_a:
	enter 0,0
	pusha
	mov bx,[data_port_a];
	;probamos bit de la bomba
	bt bx,1
	;si esta encendida, la dejamos encendida
	jc exit_encender_bombaa
	;sino encendemos la banda si se encuentra apagada
	xor bl,00000010b
	writeppic pa,bl			
	mov [data_port_a],bx ; actualizamos estado
exit_encender_bombaa:
	clc ;borramos carry	
	popa
	leave
	ret 0

;;/****************** APAGAR_BOMBA_A**********************************/
; Apaga bomba de principal
apagar_bomba_a:
	enter 0,0
	pusha
	;escribirchar 'o'
	mov bx,[data_port_a];
	;probamos bit de la banda
	bt bx,1
	;si esta apagada, la dejamos apagada
	jnc exit_apagar_bombaa
	;sino apagamos la banda si se encuentra encendida
	xor bl,00000010b
	writeppic pa,bl			
	mov [data_port_a],bx ; actualizamos estado
exit_apagar_bombaa:
	clc ;borramos carry	
	popa
	leave
	ret 0
	
;;/****************** ESCRIBIR_REPORTE_SERIAL**********************************/
; establece el tipo de reporte a escribir
;;input bl: tipo de reporte
escribir_reporte_serial:
	enter 0,0
	pusha
	;escribirchar 'p'
	mov [tipo_reporte],bl	
	popa
	leave
	ret 0
;;/****************** PRINTHORA**********************************/
printhora:
	enter 0,0
	pusha
	
	escribirchar [hora]
	
	escribirchar [minuto]
	
	escribirchar [segundo]
	escribirchar 10
	escribirchar 13
	popa
	leave
	ret 0
;;--------------------------------------------------------------------------------------	
;;STACK
section .bss
buff: resb 1024
buff2: resb 1024
buff3: resb 1024
stacktop:
