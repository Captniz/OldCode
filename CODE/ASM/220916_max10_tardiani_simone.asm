STARTPGM	= 0xee00		;ROM
RESETVECT	= 0xfffe		;VETTORE DI RESET
STARTDATI	= 0b10000000	;AREA DATI
;			
		.area	DATI (ABS)	;DEFINISCO L'AREA DATI
		.org	STARTDATI
;
num1:		.blkb 	1		;VARIABILE DI TEST 1		
count:		.blkb 	1		;VARIABILE DI TEST 2		
risultato:		.blkb 	1		;VARIABILE DI TEST 2			
;
		.area   PROGRAMMA (ABS)	;AREA DEL PROGRAMMA
		.org    STARTPGM
;
MAIN: 		MOV #6,num1 
			MOV #1,count 
			MOV #0,risultato 
LDA count 

CICLOW: 	CMP num1 
			BGT FINE 
			LDA risultato 
			ADD num1 
			STA risultato 
			LDA count 
			ADD #1 
			STA count 
			BRA CICLOW 
FINE: BRA FINE 

;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN

