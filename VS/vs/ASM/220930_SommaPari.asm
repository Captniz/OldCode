STARTPGM	= 0xee00		;ROM
RESETVECT	= 0xfffe		;VETTORE DI RESET
STARTDATI	= 0b10000000	;AREA DATI
;			
		.area	DATI (ABS)	;DEFINISCO L'AREA DATI
		.org	STARTDATI
;
VETT:       .byte 2
            .byte 0
            .byte 0
            .byte 0
            .byte 0
            .byte 0
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

LOOP:       CBEQX #9,RESET
            LDA VETT,X
            ADD #2
            INCX
            STA VETT,X
            BRA LOOP

RESET:      LDX #0
            LDA #0
LOOP2:      CBEQX #10,FINE
            ADD VETT,X
            INCX
            BRA LOOP2

FINE:       BRA FINE 

;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN