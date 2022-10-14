STARTPGM	= 0xee00		;ROM
RESETVECT	= 0xfffe		;VETTORE DI RESET
STARTDATI	= 0b10000000	;AREA DATI
;			
		.area	DATI (ABS)	;DEFINISCO L'AREA DATI
		.org	STARTDATI
;
VETT:       .byte 1
            .byte 1
            .byte 0
            .byte 0
            .byte 0
            .byte 0
;
		.area   PROGRAMMA (ABS)	;AREA DEL PROGRAMMA
		.org    STARTPGM
;                               
MAIN: 		LDA #0
            LDX #2

LOOP:       CBEQX #6,FINE
            DECX
            LDA VETT,X
            DECX
            ADD VETT,X
            INCX
            INCX
            STA VETT,X
            INCX
            BRA LOOP
FINE:       BRA FINE 

;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN