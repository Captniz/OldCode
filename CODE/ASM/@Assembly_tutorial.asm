//I commenti non vengono contati come  righe di programma (ATTENTO AI JMP)
//In assembly ci sono tre registri:

//POLLING: Continuamente controllare un indirizzo di memoria
//INTERRUPT: Segnale che arriva e fa partire una serie di istruzioni

A   //Tiene gli indirizzi
D   //Tiene i dati
M   //Tiene i dati in memoria attraverso un indirizzo in A

@0  //La chiocciola mette dei numeri in A
    //I numeri in a fungono da indirizzi quando metti o togli in memoria o fai dei jump
D=A //Assegna il valore di A in D (unico modo per assegnare valori a D oltre che prenderli da memoria)
D=M //Assegna il valore di M all'indirizzo A in D 
M=D //Assegna il valore di D all'indirizzo A in M

//Jumps:
//Tutti i jump hanno condizioni che si riferiscono a 0
//I jump esistenti sono:

0;JMP //Salta all' indirzzo in A senza condizioni
//Tutte i JMP qua sotto hanno la condizione riferita a D rispetto a 0
D;JGT   //Greater than:         D>0
D;JGE   //Greater equal than:   D>=0
D;JLT   //Lesser than:          D<0
D;JLE   //Lesser equal than:    D<=0
D;JEQ   //Equal:                D==0
D;JNE   //Not Equal:            D!=0

//Variabili:
//Si può specificare una variabile per un indirizzo di memoria in questo modo
@20
@Var    //@Var==@20

//Tags:
//Si possono specificare dei tag per evitare di contare le righe quando si esegue un jump
(LOOP)
@10
D=A
@LOOP   //Si assegna ad A il valore della riga (LOOP)
0;JMP   //Si esegue un JMP

//CPU sim:
16384 //Indirizzo monitor
24576 //Indirizzo tastiera

//VETT:
VETT:   .byte 5
        .byte 6
        .byte 7
ENDVETT:

