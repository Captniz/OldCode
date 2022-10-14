STARTPGM	= 0xee00		;ROM
RESETVECT	= 0xfffe		;VETTORE DI RESET
STARTDATI	= 0b10000000	;AREA DATI
;			
		.area	DATI (ABS)	;DEFINISCO L'AREA DATI
		.org	STARTDATI
;
VETT:       .byte 1
            .byte 2
            .byte 3
            .byte 4
            .byte 5
            .byte 6
            .byte 7
            .byte 8

sum:		.blkb 	1		;		
ctr:		.blkb 	1		;				
;
		.area   PROGRAMMA (ABS)	;AREA DEL PROGRAMMA
		.org    STARTPGM
;                               
MAIN: 		MOV #0,sum
            MOV #0,ctr
            LDA #0

LOOP:       CBEQX #8,DIVISIONE
            ADD VETT,X
            INCX
            BRA LOOP

DIVISIONE:  CMP #7
            BLE FINE
            SUB #8
            STA sum
            LDA ctr
            INCA
            STA ctr
            LDA sum
            BRA DIVISIONE

FINE:       BRA FINE 

;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN