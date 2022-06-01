STARTPGM	= 0xee00
RESETVECT	= 0xfffe
STARTDATI	= 0b10000000
;											
		.area	DATI (ABS)
		.org	STARTDATI
;
num:		.blkb 	1   ;Numero da dividere
div:		.blkb 	1	;Divisore
ctr:        .blkb 	1	;Contatore
ris:		.blkb	1   ;Risultato
;
		.area   PROGRAMMA (ABS)
		.org    STARTPGM
;
MAIN:	MOV #0,ctr      ;Do i valori alle variabili
        MOV #0,ris
        MOV #5,div
        MOV #14,num

        LDA ctr         ;Carico in A il contatore
        CMP num         ;Controllo se il la divisoione può essere effettuata almeno una volta
        BGT FINE

LOOP:   ADD div         ;Sommo il divisore al contatore
        CMP num         ;Controllo se il contatore è maggiore del numero da dividere
        BGT FINE        ;Se è maggiore esco dal ciclo
        INC ris         ;Incremento il risultato
        BRA LOOP        ;Ripeto il ciclo

FINE:	BRA FINE				
;
	.area   RESET (ABS)
	.org    RESETVECT			
	.word   MAIN				
