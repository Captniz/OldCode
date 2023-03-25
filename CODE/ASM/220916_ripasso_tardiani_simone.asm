STARTPGM	= 0xee00		;ROM
RESETVECT	= 0xfffe		;VETTORE DI RESET
STARTDATI	= 0b10000000	;AREA DATI
;			
		.area	DATI (ABS)	;DEFINISCO L'AREA DATI
		.org	STARTDATI
;
num1:		.blkb 	1		;VARIABILE DI TEST 1		
num2:		.blkb 	1		;VARIABILE DI TEST 2		
num3:		.blkb 	1		;VARIABILE DI TEST 2			
;
		.area   PROGRAMMA (ABS)	;AREA DEL PROGRAMMA
		.org    STARTPGM
;                               Definisci tre var, num1 num2 num3 e ordinale
MAIN: 		MOV #0,num1 
			MOV #1,num2 
			MOV #6,num3
            
            LDA num3    ;LOAD n3
            CMP num1    ;CMP
            BLT SWITCH1 ;END CMP
            LDX num1    ;START SWITCH
            MOV num1, num3
            STA num1    ;END SWITCH
SWITCH1:    CMP num2
            BLT SWITCH2
            LDX num2    ;START SWITCH
            MOV num2, num3
            STA num2    ;END SWITCH
SWITCH2:    LDA num2
            CMP num1
            BLT FINE
            LDX num1    ;START SWITCH
            MOV num1, num2
            STA num1    ;END SWITCH

FINE: BRA FINE 

;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN

