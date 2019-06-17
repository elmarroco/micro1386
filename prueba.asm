;PRUEBA.ASM 
%include "186.inc" 

CPU 186 
ORG 0000

;Fijamos la Pila
MOV AX, PILA 
MOV SS, AX
MOV SP, BASE

;Determinamos la dirección CS:IP y los registros de segmento de datos
MOV AX, CS
MOV DS, AX
MOV ES, AX
CALL SABER_IP
IP:
SUB AX, IP

;Conociendo CS:IP sabremos en donde está la cadena de mensaje (MSG1).
;En AX se localiza el desplazamiento
MOV BX, AX
ADD BX, MSG1

;Memoria de VIDEO
MOV AX, VIDEO
MOV DS, AX
MOV SI, 0
XOR SI, SI
CICLO_FOR:
MOV DL, [ES:BX]
INC BX
MOV BYTE [SI], DL
INC SI
MOV BYTE [SI], 72H
INC SI
;Fin de cadena?
CMP DL, 0
JE SIN_FIN
CMP SI, 4000
JNE CICLO_FOR

SIN_FIN:
JMP SIN_FIN

;En general, las cadenas en ensamblador terminan con '$', pero usamos 0
MSG1:
DB "HOLA PROOOOSSSSS!!!", 0

SABER_IP:
MOV BP, SP
MOV AX, [BP]
RET