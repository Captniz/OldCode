STARTPGM	= 0xee00    		; L'inizio dell'ipotetica ROM  
RESETVECT	= 0xfffe    		; La posizione del vettore di reset (punt a prima riga da eseguire)
STARTDATI	= 0b10000000		; Inizio area dati (primo indirizzo di RAM disponibile)
								; le pseudo istruzioni sul come tradurre sono precedute dal simbolo punto
											
		.area	DATI (ABS)		; tutti i .area DATI verranno messi insieme 
		.org	STARTDATI		; indirizzo da cui parte l'area di definizione DATI
		
num1:		.blkb 	1				; definisco tre variabili scalari num1,num2,max 
num2:		.blkb 	1				; blkb definisce blocco di byte non iniz. (nell'esempio 1 byte)		
result:		.blkb	1				; variable per il risultato

		.area   PROGRAMMA (ABS)
		.org    STARTPGM		;inizio area PROGRAMMA (il nome PROGRAMMA è scelto liberamente)

MAIN:	MOV #20,  num1
		MOV #10, num2		
		LDA num1				;LOAD carica nel registro A la variabile num1
		
		CMP num2	;CONDITION compare il contenuto del registro A con num2
		BLT IF				;BGT salto se num1 < num2

		BRA FINE				;BRA salta alla fine del programma

IF : 	LDA num2
		STA result				;STORE salva il contenuto del registro A in result

;
FINE:	BRA FINE				; Loop infinito per fermare il programma
;
	.area   RESET (ABS)
	.org    RESETVECT			;inizio area RESET (il nome RESET è scelto liberamente)
	.word   MAIN				; alloca 2 byte con valore MAIN (locazione iniziale del prg)

