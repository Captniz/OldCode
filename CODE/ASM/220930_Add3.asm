STARTPGM	= 0xee00		;ROM
RESETVECT	= 0xfffe		;VETTORE DI RESET
STARTDATI	= 0b10000000	;AREA DATI
;			
		.area	DATI (ABS)	;DEFINISCO L'AREA DATI
		.org	STARTDATI
;
VETT:       .byte 1
            .byte 0
            .byte 0
            .byte 0
            .byte 0

;
		.area   PROGRAMMA (ABS)	;AREA DEL PROGRAMMA
		.org    STARTPGM
;                               
MAIN: 		LDA #0
            LDX #0

LOOP:       CBEQX #4,FINE
            LDA VETT,X
            ADD #3
            INCX
            STA VETT,X
            BRA LOOP

FINE:       BRA FINE 

;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN