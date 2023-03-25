STARTPGM	= 0xee00		;ROM
RESETVECT	= 0xfffe		;VETTORE DI RESET
STARTDATI	= 0b10000000	;AREA DATI
;			
		.area	DATI (ABS)	;DEFINISCO L'AREA DATI
		.org	STARTDATI
;
sum:		.blkb 	1		;		
ctr:		.blkb 	1		;				
;
		.area   PROGRAMMA (ABS)	;AREA DEL PROGRAMMA
		.org    STARTPGM
;                               Definisci tre var, num1 num2 num3 e ordinale
MAIN: 		MOV #0,sum
            MOV #0,ctr
            LDA #0

LOOP:       LDA ctr
            INCA
            STA ctr
            LDA sum
            ADD ctr
            STA sum
            LDA ctr
            CMP #10
            BNE LOOP
            MOV #0,ctr
DIVISIONE:  LDA sum
            CMP #9
            BLE FINE
            SUB #10
            STA sum
            LDA ctr
            INCA
            STA ctr
            BRA DIVISIONE

FINE:       BRA FINE 

;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN