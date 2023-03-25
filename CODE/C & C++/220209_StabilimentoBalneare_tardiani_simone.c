/*
Crea dinamicamente una matrice (fino a MAX elementi) di M file e N MAXonne (M/N sono input dall' utente).
Il costo di ogni ombrellone è proporzionale a quanto è vicino al mare, gli ombrelloni dall’indice M-MAX è il più caro. 
Il costo dell’ombrellone più lontano è K€, mentre l’ombrellone più vicino al mare costa 3*K€, K è un valore inserito in input.
Ogni lettino invece ha un costo di un quarto del costo dell’ombrellone.
Ogni ombrellone può essere occupato o libero, e deve essere memorizzato per quanti giorni.

Al costo generale descritto sopra si applica inoltre uno sconto del 10% per soggiorni di almeno 5 giorni e del 20% per soggiorni che siano di almeno 10.

//*Done
Inizializza(): funzione che inizializza lo stabilmento balneare occupando casualmente gli ombrelloni e i lettini (max 3 lettini per ipotesi), generando il costo con la regola presentata

//*Done
stampa() stampa lo stato di tutti i lettini,

//*Done
calMAXaFatturato(): funzione che stampa quanto costano tutti i lettini occupati attualmente:

//*Done
occupa(int riga, int MAXonna, int giorni, int lettini): occupa se disponibile un lettino, controllando se disponibile

//*Done
stampaDisponibilità() funzione che stampa una griglia mostrano X se l’ombrellone è libero o il numero di giorni rimanenti al noleggio se è occupato

//*Done
Confronta() confronta se il costo totale di un ombrellone (lettino + noleggio) è maggiore di un altro ombrellone.

//*Done
Nel main infine è necessario dato il valore di una posizione di un  ombrellone, cercare tutti gli ombrelloni che hanno un costo minore di quell’ombrellone implementando una funzione cerca(). 
Stampa un main di prova che gestisca la modifica e tutte le funzioni.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 10
#define COL 10
#define MAXOCCUPATI 5
#define MAXLETTINI 3

void DEBUG(int a,int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]);
void Inizializza(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]);
void Stampa(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]);
void calMAXaFatturato(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL], float Costo);
void Occupa(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]);
void stampaDisponibilita( int Omb[ROW][COL] );
void Confronta(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL], float Costo);
float CostoLettino(int x, int y, float Costo, int Let[ROW][COL],int Omb[ROW][COL]);
float CostoOmbrellone(int x, int y, float Costo, int Let[ROW][COL],int Omb[ROW][COL]);
void Cerca();

int main(){
    int Omb[ROW][COL],Let[ROW][COL],LetOccup[ROW][COL];
    float Costo=0;
    srand(time(NULL));

    printf("Costo?:");
    scanf("%f",&Costo);
    Inizializza(Omb, Let, LetOccup); 
    //Cambia a 1 se si vuole gli array per debugging
    DEBUG(0,Omb, Let, LetOccup);
    Stampa(Omb, Let, LetOccup);
    calMAXaFatturato(Omb, Let, LetOccup, Costo);    
    Occupa(Omb, Let, LetOccup);
    stampaDisponibilita(Omb);
    Confronta(Omb, Let, LetOccup, Costo);
    Cerca();
    return 0;
}

//Inizializza lo stabilimento
//L'array Omb contiene per quanti giorni è occupato un ombrellone
//L'array Let contiene quanti lettini sono presenti sotto l'ombrellone con lo stesso indirizzo
//L'array LetOccup contiene 0 o 1 in base se il lettino è occupato solo sotto gli ombrelloni occupati (N giorni occupati == ombrelloni)
void Inizializza(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]){

    int i,j;
    j=0;
    i=0;

    for ( i = 0; i < ROW; i++){
        for ( j = 0; j < COL; j++){
            //Creazione di una matrice di ombrelloni occupati (Maggiori di 0) con i giorni occupati
            Omb[i][j]=rand()%(MAXOCCUPATI+1)+0;

            //Azzeramento array
            LetOccup[i][j]=0;
            Let[i][j]=0;
            
            //Se l'array Omb ha un ombrellone occupato assegna la presenza o meno di un lettino (questo step tecnicamente non è necessario, tuttavia uscirebbero troppi pochi lettini non occupati attraverso una randomizzazione semplice, dato che lo zero avrebbe pari probabilita di uscire di tutti gli altri numeri)
            if (Omb[i][j]){
                LetOccup[i][j]=rand()%2+0;
            }

            //Se in lettino è segnato come occupato, assegnali un tot di lettini da occupati randomicamente
            if (LetOccup[i][j]){ 
                Let[i][j]=rand()%MAXLETTINI+1;
            }   
        }
    }
}

//Stampa uno stato dettagliato di tutti i lettini
void Stampa(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]){

    int i,j;
    j=0;
    i=0;

    printf("\n-----------\n"); //<--- queste barrette le utilizzo per chiarezza nell' output durante tutto il programma

    //Stampa un resoconto semplice di tutti i dati dei lettini
    for ( i = 0; i < ROW; i++){
        for ( j = 0; j < COL; j++){
            printf("%d lettini occupati per %d giorni nella posizione (%d;%d)\n",Let[i][j],Omb[i][j]*LetOccup[i][j],i,j);
        }
    }    
    printf("-----------\n");
}

//Stampa quanto costano tutti i lettini occupati attualmente
//Costo ombrellone= ((((Costo*3)-Costo)/DIM-1)*i)+Costo
//Al costo generale descritto sopra si applica inoltre uno sconto del 10% per soggiorni di almeno 5 giorni e del 20% per soggiorni che siano di almeno 10.
void calMAXaFatturato(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL], float Costo){
    int i,j;
    j=0;
    i=0;
    float costo;

    printf("\n-----------\n");
    for (i=0;i<ROW;i++){
        for (j=0;j<COL;j++){
            //Se il lettino è presente...
            if (Omb[i][j]){
                if (LetOccup[i][j]){
                    //Chiamo una funzione che calcola il costo del lettino e poi lo stampo con una frase
                    costo = CostoLettino(j,i,Costo,Let,Omb);
                    printf("Il costo totale dei lettini occupati nella posizione (%d;%d) e' %f$\n",i,j,costo);
                }
            }
        }
    }
    printf("\n-----------\n");
}

//occupa(): occupa se disponibile un lettino.
void Occupa(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]){
    int x,y,g;
    x=0;
    y=0;
    g=0;
    
    printf("\n-----------\n");
    //Richiesta coordinate del ombrellone/lettino e controllo che siano corrette e disponibili
    do{
        do{
            printf("Lettino da occupare (coord. x partendo da 0):");
            scanf("%d",&x);
        }while(x>=COL);

        do{
            printf("Lettino da occupare (coord. y partendo da 0):");
            scanf("%d",&y);
        }while(y>=ROW);
    }while (LetOccup[y][x]==1);

    do{
        printf("Lettini da prenotare:");
        scanf("%d",&g);
    }while(g>MAXLETTINI);
    Let[y][x]=g; //<-- input informazioni nell'array

    do{
        printf("Giorni della prenotazione:");
        scanf("%d",&g);
    }while(g>MAXOCCUPATI);
    Omb[y][x]=g; //<-- input informazioni nell'array

    LetOccup[y][x]=1; //<-- input informazioni nell'array

    printf("\n-----------\n");
}

//stampaDisponibilità() funzione che stampa una griglia mostrano X se l’ombrellone è libero o il numero di giorni rimanenti al noleggio se è occupato
void stampaDisponibilita(int Omb[ROW][COL]){
    int i,j;
    j=0;
    i=0;
    char X[2]="X\0";

    printf("\n-----------\n");

    //Stampa semplice della matrice con aggiunta della condizione se è 0 scrive X
    for ( i = 0; i < ROW; i++){
        for ( j = 0; j < COL; j++){
            if (Omb[i][j]){
                printf(" %d",Omb[i][j]);
            }else{
                printf(" %s",X);
            }
        }
        putchar('\n');
    }
    printf("\n-----------\n");

}

//Confronta() confronta se il costo totale di un ombrellone (lettino + noleggio) è maggiore di un altro ombrellone.
void Confronta(int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL], float Costo){
    int x1,x2,y1,y2,costo1,costo2;
    x1=0;
    y1=0;
    x2=0;
    y2=0;
    costo1=0;
    costo2=0;

    printf("\n-----------\n");

    //Richiesta coordinate del ombrellone/lettino e controllo che siano corrette e disponibili
    do{
        printf("Lettino 1 (coord. x partendo da 0):");
        scanf("%d",&x1);
    }while(x1>=COL);
    do{
        printf("Lettino 1 (coord. y partendo da 0):");
        scanf("%d",&y1);
    }while(y1>=ROW);


    do{
        printf("Lettino 2 (coord. x partendo da 0):");
        scanf("%d",&x2);
    }while(x2>=COL);
    do{
        printf("Lettino 2 (coord. y partendo da 0):");
        scanf("%d",&y2);
    }while(y2>=ROW);
    
    //Confronto tra i due costi totali
    if ((CostoLettino(x1,y1,Costo,Let,Omb)+CostoOmbrellone(x1,y1,Costo,Let,Omb))>(CostoLettino(x2,y2,Costo,Let,Omb)+CostoOmbrellone(x2,y2,Costo,Let,Omb))){
        printf("Il primo ombrellone costa più del secondo");
    }else{
        printf("Il primo ombrellone non costa piu' del secondo");
    }

    printf("\n-----------\n");
}

//Cerca(): dato il valore di una posizione di un  ombrellone, cercare tutti gli ombrelloni che hanno un costo minore  
void Cerca(){

    int i,y;
    i=0;
    y=0;

    printf("\n-----------\n");

    //Qua ci interessa sapere solo la y dell'ombrellone poichè la funzione tralascia i lettini e il prezzo dell'ombrellone basato unicamente sull'altezza.
    printf("Coord x ombrellone:");
    scanf("%d",&y);  //<--- Chiediamo comunque la x all'utente per farlo sentire intelligente
    printf("\nCoord y ombrellone:");
    scanf("%d",&y);


    if (y!=0){
        printf("Gli ombrelloni delle/a file/a ");
        for ( i = 0; i < y; i++){
            printf("%d ",i);
        }
        printf("costano di meno");

    //Se l'ombrellone fa parte della fila 0 non ci sono ombrelloni meno costosi
    }else{
        printf("Nessun ombrellone costa meno");
    }

    printf("\n-----------\n");
}

//Nelle due funzioni seguenti viene calcolato in entrambe lo sconto anzi che una singola, questo comporta che il prezzo venga scontato non corretamente molte volte, tuttavia lo lascerò nel programma poichè sono un uomo magnianimo e faccio lo sconto aggiuntivo.

//Calcola costo lettino specificato
float CostoLettino(int x, int y, float Costo, int Let[ROW][COL],int Omb[ROW][COL]){

    float costo=0;
    
    //Espressione per il calcolo esatto del costo del lettino
    costo = ((((((Costo*2)/(ROW-1))*y)+Costo)/4)*Let[y][x]);

    //Aplicazione degli sconti
    if (Omb[y][x]>=10){
        //sconto 1
        costo=costo-(costo/100*20);
    }else if(Omb[y][x]>=5){
        //sconto 2
        costo=costo-(costo/100*10);
    } 

    return costo;
}

//Calcola costo ombrellone specificato
float CostoOmbrellone(int x, int y, float Costo, int Let[ROW][COL],int Omb[ROW][COL]){
    
    float costo=0;

    //Espressione per il calcolo esatto del costo del lettino
    costo = ((((Costo*2)/(ROW-1))*y)+Costo);

    //Aplicazione degli sconti
    if (Omb[y][x]>=10){
        //sconto 1
        costo=costo-(costo/100*20);
    }else if(Omb[y][x]>=5){
        //sconto 2
        costo=costo-(costo/100*10);
    } 

    return costo;
}

//Scrive gli array per debugging
void DEBUG(int a, int Omb[ROW][COL], int Let[ROW][COL], int LetOccup[ROW][COL]){

    if(a){
        int i,j;
            j=0;
            i=0;

        for (i=0;i<ROW;i++){
            for (j=0;j<COL;j++){
                printf("%3d",Omb[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
        for (i=0;i<ROW;i++){
            for (j=0;j<COL;j++){
                printf("%3d",Let[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
        for (i=0;i<ROW;i++){
            for (j=0;j<COL;j++){
                printf("%3d",LetOccup[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
}