JUMPS
.MODEL SMALL
.STACK 1024h
.DATA
ALEATORIO         dw  0
METEOROS          dw  0
CHOQUES           dw  0
SCORE             dw  0
VIDAS             DW  3
SALIDA_SCORE      dw  ?
SALIDA_VIDAS      DW  ?
POSICION 		  DW  300
AX1 			  DW 40
AX2 			  DW 600
AY1 			  DW 58
AY2 			  DW 440
XFIN 			  DW 570
YBALA             DW 394
RETARDO		      DW 1334 ;2FFFH
M1                Db 9
M2                Db 9
M3                Db 9
M4                Db 9
M5                Db 9
M6                Db 9
M7                Db 9
M8                Db 9
M9                Db 9
M10               Db 9
sentido           db 1
altura            Dw 75
altura2           DW 75
POSICION2		  DW 60
PD                DW 0
retardo_enemigos  DW 0FFFFh
retardo_enemigos2 Dw 02FFh
retardo_enemigos3 Dw 0FFh

VIDAS1 			  DB 'VIDAS: '
LONG_VIDAS 		  equ $-VIDAS1
PUNTOS 			  DB 'SCORE: '
LONG_PUNTOS 	  equ $-PUNTOS
MSG1 			  DB 'PRESIONA ESC PARA SALIR'
LONG_MSG1 		  equ $-MSG1
MSG2 			  DB '** GAME OVER **'
LONG_MSG2 		  equ $-MSG2
;*****
XINI DW 295
YINI DW 330
CLRBALL DB 14
BALLX DW 320
BALLY DW 160
VELX DW -1
VELY DW -1
YFIN DW 345
POSY DW 330
FLAGPY DW 0
CLRAREA DB 10
COLORBARRA DB 8




.CODE

MAIN PROC

MOV AX,@DATA
MOV DS,AX

CALL MODO12     ;INICIAMOS EL MODO 12H
CALL AREA       ;DIBUJAMOS EL AREA PARA JUGAR
CALL ESTRELLAS  ;PINTAMOS LAS ESTRELLAS DE FONDO
CALL NAVE       ;PINTAMOS LA NAVE EN LA POSICION INICIAL
       
       MOV ah,13h           ;Mostrar cadena.
       MOV al,0             ;Especifica que el atributo se encuentra en BL.
       MOV bh,00h           ;Pagina.
       MOV bl,0bh           ;Atributo (aguamarina claro sobre negro).
       MOV dh,2             ;Fila donde se mostrara la cadena. 
                            ; para imprimir VIDAS
       MOV cx,long_vidas    ;Longitud de la cadena.
       MOV dl,15            ;Para centrar la cadena.
       PUSH ds
       POP es
       MOV bp,offset vidas1 ;ES:BP = Puntero a la cadena.
       INT 10h              ;Llamar a servicio de video de BIOS                          
                            ; para imprimir SCORE
       MOV cx,long_puntos   ;Longitud de la cadena.
       MOV dl,40            ;Para centrar la cadena.
       PUSH ds
       POP es
       MOV bp,offset puntos ;ES:BP = Puntero a la cadena.
       INT 10h              ;Llamar a servicio de video de BIOS
       
       mov cx,LONG_MSG1 ;Longitud de la cadena.
       mov dh,28         ;Fila donde se mostrara la cadena.
       mov dl,(80-LONG_MSG1)/2  ;Para centrar la cadena.
       push ds
       pop es
       mov bp,offset MSG1  ;ES:BP = Puntero a la cadena.
       int 10h           ;Llamar a servicio de video de BIOS.
CALL PUNTEO      
CALL CICLO    ;INICIAMOS EL CICLO QUE LEE MOVIMIENTOS      

MAIN ENDP
;**********************ACTIVA EL MODO GRAFICO 12H*******************************************
PUNTEO PROC 
       
       mov ax,score                  ; cadena a convertir
       mov di, offset [salida_score] ; direccion de la cadena de salida
       mov cx,1                      ; tamaño minimo de la salida      
       mov bx,10                     ; Base para conversión
	   call ConvAsc                  ; Pasa a ASCII el score
       mov ax,vidas                  ; cadena a convertir
       mov di, offset [salida_vidas] ; direccion de la cadena de salida
       mov cx,1                      ; tamaño minimo de la salida      
       mov bx,10                     ; Base para conversión
	   call ConvAsc                  ; Pasa a ASCII las vidas
       
       MOV ah,13h                   ;Mostrar cadena.
       MOV al,0             		;Especifica que el atributo se encuentra en BL.
       MOV bh,00h           		;Pagina.
       MOV bl,0bh           		;Atributo (aguamarina claro sobre negro).
       MOV dh,2             		;Fila donde se mostrara la cadena.       
                                    ;imprime score
       MOV cx,3             		;Longitud de la cadena.
       MOV dl,47            		;Para centrar la cadena.
       PUSH ds
       POP es
       MOV bp,offset salida_score 	;ES:BP = Puntero a la cadena.
       INT 10h              		;Llamar a servicio de video de BIOS
                                    ;imprime vidas
       MOV cx,1             		;Longitud de la cadena.
       MOV dl,22            		;Para centrar la cadena.
       PUSH ds
       POP es
       MOV bp,offset salida_vidas 	;ES:BP = Puntero a la cadena.
       INT 10h              		;Llamar a servicio de video de BIOS

       RET
PUNTEO ENDP

MODO12 PROC
        MOV AH,0
        MOV AL,12h
        INT 10h

MODO12 ENDP

;************************  AREaA *******************************
AREA PROC
        PUSH AX          ; guardamos el la pila el registro ax 
        PUSH BX          ; guardamos el la pila el registro bx
        PUSH CX          ; guardamos el la pila el registro cx
        PUSH DX          ; guardamos el la pila el registro dx

        MOV AH,0CH       ; subrutina para pintar un pixel
        MOV AL,CLRAREA   ; guardamo en color del pixel  2 
        MOV CX,AX1       ; columna AX1  
        MOV DX,AY1       ; fila AY1

A1:     INT 10h          ; pinta el punto anterior
        MOV DX,AY2       ; fila ay2 
        INT 10h          ; pinta otro punto
        MOV DX,AY1       ; fila ay1
        INC CX           ; incrementa cx; incrementa una columna
        CMP CX,AX2       ; compara si cx  es igual a ax2        (cx=580)
        JLE A1           ; si es menor o igual repite el proceso   ; pinta las lineas horizontales del area de juego 
        
        MOV CX,AX1
        MOV DX,AY1
A2:     INT 10h
        MOV CX,AX2
        INT 10h
        MOV CX,AX1
        INC DX
        CMP DX,AY2      ; compara si dx es igual a ay2
        JLE A2          ; si es menor o igual repite el proceso   ; pinta las lineas verticales del area de juego       
        POP DX          ; sacamos de la pila el registro dx         
        POP CX          ; sacamos de la pila el registro cx 
        POP BX          ; sacamos de la pila el registro bx 
        POP AX          ; sacamos de la pila el registro ax 
        
        RET

AREA ENDP
;*******************************************estrellas******************************

ESTRELLAS PROC
                  PUSH AX          ; guardamos el la pila el registro ax 
        PUSH BX                    ; guardamos el la pila el registro bx
        PUSH CX                    ; guardamos el la pila el registro cx
        PUSH DX                    ; guardamos el la pila el registro dx
        PUSH AX1                   ; guardamos el valor que tiene Ax1
        PUSH AY1                   ; guardamos el valor que tiene AY1
        MOV CX,40                  ; columna inicial de las estrellas 
ESTRELLAS_ALEATORIAS:      
        mov ax,aleatorio           ;AX = Semilla generador nros aleatorios.
        mov dx,75                  ;Pr¢xima semilla = (semilla * 75)
        mul dx                     ;                  mod 65537.
        and ax,ax                  ;(si la semilla era cero, considerarla
        jnz semilla_no_cero        ;como 65536).
        mov dx,75
SEMILLA_NO_CERO:
        sub ax,dx
        jnc guardar_semilla
        inc ax
GUARDAR_SEMILLA:
        mov aleatorio,AX             ;Preservar semilla aleatoria.
        mov AL,80
        mul AH                     ;AH = N£mero "aleatorio" entre 0 y 79.
        MOV Dl,0
        MOV Dh,AH             
        MOV AH,0CH                 ; subrutina para pintar un pixel
        MOV AL,15                  ; guardamo en color del pixel  15 =BLANCO 
        ADD CX,5
        INT 10h                    ; pinta el punto anterior
        CMP CX,600                 ; compara si cx es igual a ay2
        JLE ESTRELLAS_ALEATORIAS   ; si es menor o igual repite el proceso 
        
        POP AY1
        POP AX1
        POP DX          ; sacamos de la pila el registro dx         
        POP CX          ; sacamos de la pila el registro cx 
        POP BX          ; sacamos de la pila el registro bx 
        POP AX          ; sacamos de la pila el registro ax 
        RET 
ESTRELLAS ENDP
;****************************************procedimiento para dibujar la nave
NAVE PROC

        PUSH AX1         ; se guarda el valor de ax1
        MOV AH,0CH       ; subrutina para pintar un pixel
        MOV AL,15        ; guardamoS en color del pixel  blanclo  
        SUB POSICION,1
        MOV CX,POSICION
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION,2   ;
        MOV CX,POSICION  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,395       ; fila inicial de la nave
        SUB POSICION,1
ETIQUETA1:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA2: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA2    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        INC DX           ; bajamos una fila
        CMP DX,410       ; comparamos si ya llegamos a la mitad de la nave  
        JLE ETIQUETA1    ; si no volvemos a repetir el proceso
 
 
        MOV AL,2         ; guardamoS en color del pixel  ROJO 
        SUB POSICION,6
        MOV CX,POSICION
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION,12  ;
        MOV CX,POSICION  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,425       ; fila inicial de la nave
        SUB POSICION,6      
ETIQUETA3:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA4:  
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA4    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,410       ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA3    ; si no volvemos a repetir el proceso            
        POP AX1
        CALL SOMBRAS
     RET
NAVE ENDP

;*****************************************SOMBRAS***********************************************
SOMBRAS PROC

        PUSH AX1         ; se guarda el valor de ax1
        MOV AH,0CH       ; subrutina para pintar un pixel
        MOV AL,0         ; guardamoS en color del pixel  NEGRO 
        ADD POSICION,30  ; sombra derecha 
        SUB POSICION,1
        MOV CX,POSICION
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION,2   ;
        MOV CX,POSICION  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,395       ; fila inicial de la nave
        SUB POSICION,1
ETIQUETA5:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA6: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA6    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        INC DX           ; bajamos una fila
        CMP DX,410       ; comparamos si ya llegamos a la mitad de la nave  
        JLE ETIQUETA5    ; si no volvemos a repetir el proceso
 
 
        SUB POSICION,6
        MOV CX,POSICION
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION,12  ;
        MOV CX,POSICION  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,425       ; fila inicial de la nave
        SUB POSICION,6      
ETIQUETA7:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA8:  
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA8    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,410       ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA7    ; si no volvemos a repetir el proceso   
        
        
        SUB POSICION,60  ; sombra IZQUIERDA 
        SUB POSICION,1
        MOV CX,POSICION
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION,2   ;
        MOV CX,POSICION  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,395       ; fila inicial de la nave
        SUB POSICION,1
ETIQUETA9:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA10: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA10   ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        INC DX           ; bajamos una fila
        CMP DX,410       ; comparamos si ya llegamos a la mitad de la nave  
        JLE ETIQUETA9    ; si no volvemos a repetir el proceso
 
 
        SUB POSICION,6
        MOV CX,POSICION
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION,12  ;
        MOV CX,POSICION  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,425       ; fila inicial de la nave
        SUB POSICION,6      
ETIQUETA11:              ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA12:  
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA12   ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,410       ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA11   ; si no volvemos a repetir el proceso                          
        ADD POSICION,30  ; posicion normal          
        
        MOV AL,CLRAREA   ; guardamoS en color del pixel  VERDE 
        MOV DX,395 
PINTA_TOPES:             ; pintar los topes que manchan las sombras
        MOV CX,600
        INT 10H
        MOV CX,40
        INT 10H
        INC DX
        CMP DX,425
        JLE PINTA_TOPES   
        POP AX1
     RET
SOMBRAS ENDP
;***************************************PIEDRA******************************************************************
ENEMIGOS PROC
        push posicion2
        PUSH AX1         ; se guarda el valor de ax1
        MOV AX,altura
        sub ax,15
        mov ALTURA2,AX
        MOV AH,0CH       ; subrutina para pintar un pixel
        MOV AL,M1         ; guardamoS en color del pixel  
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,altura      ; fila inicial de la nave
        SUB POSICION2,1
ETIQUETA15:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA16: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA16    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA15    ; si no volvemos a repetir el proceso

;segundo enemigo
        MOV AL,M2         ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,altura       ; fila inicial de la nave
        SUB POSICION2,1
ETIQUETA17:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA18: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA18    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA17    ; si no volvemos a repetir el proceso 
;tercer enemigo
        MOV AL,M3         ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,altura       ; fila inicial de la nave
        SUB POSICION2,1
ETIQUETA19:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA20: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA20    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA19    ; si no volvemos a repetir el proceso 
 ;cuarto enemigo
         MOV AL,M4         ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,altura       ; fila inicial de la nave
        SUB POSICION2,1
ETIQUETA21:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA22: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA22    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA21    ; si no volvemos a repetir el proceso 
;quinto enemigo
        MOV AL,M5         ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE
        MOV DX,altura       ; fila inicial de la nave
        SUB POSICION2,1
ETIQUETA23:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA24: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA24    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA23    ; si no volvemos a repetir el proceso 
;sexto enemigo
        MOV AL,M6         ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV DX,altura      ; fila inicial de la nave
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE
        SUB POSICION2,1
ETIQUETA25:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA26: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA26    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA25    ; si no volvemos a repetir el proceso 
;septimo enemigo
        MOV AL,M7         ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV DX,altura      ; fila inicial de la nave
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE
        SUB POSICION2,1
ETIQUETA27:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA28: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA28    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA27    ; si no volvemos a repetir el proceso 
;octavo enemigo
        MOV AL,M8         ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV DX,altura      ; fila inicial de la nave
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE

        SUB POSICION2,1
ETIQUETA29:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA30: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA30    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA29    ; si no volvemos a repetir el proceso 
        
        
        
;sombra derecha
        MOV AL,0       ; guardamoS en color del pixel
        ADD posicion2,30
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV DX,altura      ; fila inicial de la nave
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE

        SUB POSICION2,1
ETIQUETA31:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA32: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA32    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA31    ; si no volvemos a repetir el proceso          
        POP AX1
        POP posicion2


;sombra izquierda
        push posicion2
        MOV AL,0       ; guardamoS en color del pixel
        SBB posicion2,29
        SUB POSICION2,1
        MOV CX,POSICION2
        MOV AX1,CX       ;COLUMNA FINAL DE LA NAVE
        ADD POSICION2,2   ;
        MOV DX,altura      ; fila inicial de la nave
        MOV CX,POSICION2  ;COLUMNA INICIAL DE LA NAVE

        SUB POSICION2,1
ETIQUETA33:               ; ciclo para avanzar fila por fila el dibujo 
         DEC CX          ; decrementa el valor de  la columna izquierda
         INC AX1         ; incrementa el valor de la columna derecha
         PUSH CX         ; guarda el valor actual de la columna izquierda
ETIQUETA34: 
        INT 10h        
        INC CX           ; incrementa la columna izquierda
        CMP CX,AX1       ; comparamos si cx es igual a la columna derecha 
        JLE ETIQUETA34    ; si es menor o iguala repetimos el ciclo
        POP CX           ; regresamo el valor actual de la columna izquierda 
        DEC DX           ; bajamos una fila
        CMP DX,ALTURA2      ; comparamos si ya llegamos a la mitad de la nave  
        JGE ETIQUETA33    ; si no volvemos a repetir el proceso
        
        pop posicion2
       RET
ENEMIGOS ENDP












;***************************************BALA********************************************************************
BALA PROC
        MOV AH,0CH       ; subrutina para pintar un pixel
        MOV AL,0  ; guardamoS en color del pixel  negro  
        ;dibuja la sombra
        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        MOV DX,ybala      ; fila inicial de la nave
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX
        
        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX
 
        ;**dibuja la bala
        MOV AL,14   ; guardamoS en color del pixel  amarillo

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX
        
        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        DEC DX         
        RET
BALA ENDP


;**************************************************************************************************************
BALA_FINAL PROC
     MOV AH,0CH       ; subrutina para pintar un pixel
        MOV AL,0  ; guardamoS en color del pixel  negro  
        ;dibuja la sombra
        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        MOV DX,59      ; fila inicial de la nave
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        INC DX
        
        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        INC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        INC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        INC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        INC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        INC DX

        MOV CX,POSICION  ; COLUMNA INICIAL DE LA NAVE
        INT 10h
        SUB CX,1
        INT 10H
        ADD CX,2
        INT 10H
        INC DX
 
     RET
BALA_FINAL ENDP
;*****************************************MATA*****************************************************************
MATA PROC
        PUSH YBALA
            
PINTA_BALA:        
           CALL BALA
           CALL DELAY
           SUB YBALA,7
           CMP YBALA,72       ; comparamos si ya llegamos aL TOPE  
           JGE PINTA_BALA     ; si no volvemos a repetir el proceso 
        CALL BALA_FINAL
        POP YBALA

        RET
MATA ENDP
;*****************************************NO MATA**************************************************************
NO_MATA PROC
        PUSH YBALA
            
PINTA_BALA2:        
           CALL BALA
           CALL DELAY
           SUB YBALA,7
           CMP YBALA,72       ; comparamos si ya llegamos aL TOPE  
           JGE PINTA_BALA2     ; si no volvemos a repetir el proceso 
        CALL BALA_FINAL
        POP YBALA

        RET
NO_MATA ENDP
;********************************************DISPARA***********************************************************
DISPARA PROC
        PUSH YBALA
        MOV AX,POSICION2
        CMP AX,POSICION
        JE N1
        ADD AX,30
        CMP AX,POSICION
        JE N2

        ADD AX,30
        CMP AX,POSICION
        JE N3

        ADD AX,30
        CMP AX,POSICION
        JE N4
        
        ADD AX,30
        CMP AX,POSICION
        JE N5

        ADD AX,30
        CMP AX,POSICION
        JE N6

        ADD AX,30
        CMP AX,POSICION
        JE N7

        ADD AX,30
        CMP AX,POSICION
        JE N8
        CALL NO_MATA
        JMP NF
N1:
   MOV M1,0 
   CALL MATA
   JMP NF
N2:
   MOV M2,0
   CALL MATA
   JMP NF

N3:
   MOV M3,0
   CALL MATA
   JMP NF

N4:
   MOV M4,0
   CALL MATA
   JMP NF

N5:
   MOV M5,0
   CALL MATA
   JMP NF

N6:
   MOV M6,0
   CALL MATA
   JMP NF

N7:
   MOV M7,0
   CALL MATA
   JMP NF

N8:
   MOV M8,0
   CALL MATA
   JMP NF

NF:
        RET
DISPARA ENDP

;*****************************************MUEVE_ENEMIGOS********************************************************
MUEVE_ENEMIGOS PROC
      mov DX,POSICION2
      mov pd,dx
      add pd,210
      
      cmp retardo_enemigos,0
      je  mas_tiempo
      DEC retardo_enemigos
      jne siguiente
MAS_TIEMPO:
           cmp retardo_enemigos2,0 
           je  mas_tiempo2
           DEC retardo_enemigos2
           jne siguiente
MAS_TIEMPO2:
           cmp retardo_enemigos3,0
           je enemig
           DEC retardo_enemigos3
           jne siguiente
ENEMIG:
      cmp sentido,1
      je  right
      jmp left
RIGHT:
      CMP pd,530
      JLE SUMADER
      ADD ALTURA,30
      MOV sentido,0
      JMP REINICIA_TIEMPO
SUMADER:
      ADD POSICION2,30
      JMP REINICIA_TIEMPO 
LEFT:
     CMP posicion2,70
     JGE SUMAIZ
     ADD altura,30
     MOV SENTIDO,1
     JMP REINICIA_TIEMPO
SUMAIZ:
     SBB posicion2,30
     JMP reinicia_tiempo 
REINICIA_TIEMPO: 
      call enemigos     
      mov retardo_enemigos,0FFFFH
      mov retardo_enemigos2,00H
      mov retardo_enemigos3,0FFH     
      
               RET
MUEVE_ENEMIGOS ENDP
;*****************************************CICLO*****************************************************************
CICLO PROC

REPITE:
       CALL mueve_enemigos
      
siguiente:      
      MOV AH,0BH        ; RUTINA PARA SABER SI HAY CARACTER DISPONIBLE
      INT 21H           ; LLAMADA A LA BIOS
      CMP AL,00H        ; SI NO HAY CARACTER DISPONIBLE
      JE REPITE
      JMP COMPARA
COMPARA:
        MOV AH,08       ; LEE LA TECLA PRESIONADA SIN ECO
        INT 21H
        CMP AL, 075     ;FLECHA IZQUIERDA
        JE IZQUIERDA
        CMP AL, 072     ;FLECHA DE ARRIBA
        JE ARRIBA
        CMP AL,077      ;FLECHA DERECHA 
        JE DERECHA    
		CMP AL,1BH		;ESC SALIMOS DEL PROGRAMA
		JE SALIR
        JMP REPITE
IZQUIERDA:              ; si se quierem mover a la izquierda
        SUB POSICION,30                     
        MOV DX,POSICION
        CMP DX,AX1      ; comparamos si ya llegamos aL tope izquierdo del area de juego  
        JGE MUEVE_IZ    ; si no, movemos la nave
        ADD POSICION,30
        JMP REPITE      ; si ya llegamos no hacemos nada
MUEVE_IZ:           
        CALL NAVE
        JMP REPITE
ARRIBA:
        CALL DISPARA    ; disparamos
        JMP REPITE
DERECHA:                ; si se quieren mover a la derecha
        ADD POSICION,30
        MOV DX,POSICION        
        CMP DX,XFIN     ; comparamos si ya llegamos aL tope derecho del area de juego  
        JLE MUEVE_DE    ; si no movemos la nave
        SUB POSICION,30
        JMP REPITE      ; si ya llegamos no hacemos nada
MUEVE_DE:        
        CALL NAVE
        JMP REPITE    
      RET
CICLO ENDP


;**************************************RETARDO******************************************
	DELAY PROC
		MOV DX,RETARDO
		D1:
			MOV CX,0FFFH
			D2:
			DEC CX
			JNZ D2
			DEC DX
		JNZ D1	
		RET
	DELAY ENDP

;**************************CONVIERTE UN NUMERO A SU VALOR HEXA***************************************
PROC DigitoHex
	cmp dl,10      ;DL < 10 (es decir hex 'A')?
	jb eti13       ;Sí, brinca
	add dl, 'A'-10 ;No, convertir A, B, C, D, E o F
	ret
	eti13:
	add dl,'0'     ;Convierte a dígitos 0 a 9
	ret            ;Retorna
DigitoHex ENDP 
;************************************CONVIERTE UN NUMERO A SU VALOR ASCII*******************************
PROC ConvAsc
	push dx     ;Entrada normal
	push di     ;Salva registros
	push si  	; SI controla los dígitos guardados en la pila
	xor si,si   ;Contador de dígitos a cero
	jcxz ET20   ;Si CX = 0 brinca a ponerlo a 1
ET10:
	xor dx,dx   ;Extiende AX a 32 bits
	div bx 		;AX = DX. AX/BX, DX = residuo
	call DigitoHex ;Convierte DL a dígito hexadecimal
	push dx     ;Salva dígito en la pila
	inc si 		;Cuenta dígitos salvados
	loop ET10
ET20:
	inc cx 		;Pone CX = 1 por si no se hizo
	or ax,ax 	;AX = 0? (todos los dígitos)
	jnz ET10 	;Si AX > 0 continua la conversión
	mov cx,si 	;CX = contador de caracteres en pila
	jcxz ET40 	;Omite sgte bucle si CX=0000
	cld 		;Autoincrementa DI en STOSB
ET30:
	pop ax 		;Trae siguiente dígito en AL
	stosb 		;Pone dígito en cadena y avanza DI
	loop ET30 	;Repite el bucle
ET40:
	pop si di dx ;Repone registros
	ret          ;Regresa
ConvAsc	ENDP 

;************************Finaliza el programa y devuelve el control al sistema operativo
salir:
 mov ah, 0     ;inicializar la tarjeta grafica     
 mov al, 03h   ; vuelve al modo texto   
 int 10h       ; se llama a la interrrupcion            
 MOV AH,4CH    ; La funcio 4CH de la inte 21HF devuelve el control al sistema operativo
 INT 21H
 .exit
END