STARTPGM	= 0xee00
RESETVECT	= 0xfffe
STARTDATI	= 0b10000000
;											
		.area	DATI (ABS)
		.org	STARTDATI
;
num1:		.blkb 	1
num2:		.blkb 	1	
result:		.blkb	1
;
		.area   PROGRAMMA (ABS)
		.org    STARTPGM
;
MAIN:	MOV #20, num1
		MOV #10, num2		
		;
		LDA num1
		;
		CMP num2
		BLT IF
		;
		
		BRA FINE
;
IF : 	LDA num2
		STA result
;
FINE:	BRA FINE				
;
	.area   RESET (ABS)
	.org    RESETVECT			
	.word   MAIN				
