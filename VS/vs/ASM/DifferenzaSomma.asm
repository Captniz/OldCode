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
MAIN:	MOV #10, num1
		MOV #20, num2		
		;
		LDA num1
		;
		CMP num2
		BLT IF
		;
		ADD num2
		STA result
		BRA FINE
;
IF : 	SUB num2
		STA result
;
FINE:	BRA FINE				
;
	.area   RESET (ABS)
	.org    RESETVECT			
	.word   MAIN				
