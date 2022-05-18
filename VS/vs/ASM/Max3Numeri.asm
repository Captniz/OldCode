STARTPGM	= 0xee00
RESETVECT	= 0xfffe
STARTDATI	= 0b10000000
;			
		.area	DATI (ABS)
		.org	STARTDATI
;
num1:		.blkb 	1				
num2:		.blkb 	1					
num3:       .blkb   1
;
		.area   PROGRAMMA (ABS)
		.org    STARTPGM
;
MAIN:	MOV #30, num1
		MOV #20, num2
		MOV #20, num3
		;
		LDA num1
		;
		CMP num2 
		BLT IF		;a<var
;
COND:	CMP num3
		BLT IF2
		;
		BRA FINE
;
IF	:	LDA num2
		BRA COND
;
IF2	:	LDA num3
		BRA FINE	
;
FINE:	BRA FINE
;
	.area   RESET (ABS)
	.org    RESETVECT
	.word   MAIN

