/*
Scrivere un programma che simuli il controllo di parità come segue:

Il main richiama le seguenti funzioni:

Scelta della parità (pari o dispari)

Crea e stampa messaggio (in un vettore di 8 elementi riempire dall’elemento 1 all’elemento 7 con numeri random 0 e 1)

Spedisci messaggio con calcolo parità (calcolo della parità richiesta e aggiunta del bit all’elemento 0 del vettore)

Simula rumore (random per scelta del bit da modificare tra 1 e 7 e random se mettere 0 o 1)

Ricevi messaggio con controllo parità e stampa “messaggio arrivato correttamente” o messaggio arrivato non correttamente”
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 8

int TipoPAR();                                          //Sceglie il tipo di parità
void CreaEVisualizzaMSG(int msg[DIM]);                  //Crea e stampa messaggio
void SpedisciMSGePAR( int par,int msg[DIM]);            //Spedisci messaggio con calcolo parità
void SimRumore( int msg[DIM]);                          //Simula rumore
void RiceviEControllaMSG( int msg[DIM], int par);       /*Ricevi messaggio con controllo parità e stampa 
                                                          “messaggio arrivato correttamente” o 
                                                          "messaggio arrivato non correttamente”*/

int main(){
    int msg[DIM],par;
    par = TipoPAR();
    srand(time(NULL));

    CreaEVisualizzaMSG(msg);
    SpedisciMSGePAR(par, msg);
    SimRumore(msg);
    RiceviEControllaMSG(msg, par);
    return 0;
}

int TipoPAR(){
    int par;

    do{
        printf("===Tipo Parita'===\n1>Pari\n0>Dispari\nOpzione:");
        scanf("%d",&par);
        putchar('\n');
    }while(par!=0 && par!=1);
    return par;
}                              
void CreaEVisualizzaMSG(int msg[DIM]){
    int i=1;

    printf("\nMessaggio:\n[");
    for ( i = 1; i < DIM; i++){
        msg[i]=rand()%2+0;
        printf("%2d ",msg[i]);
    }
    putchar(']');
}          
void SpedisciMSGePAR( int par,int msg[DIM]){
    int i,ctr;
    ctr=0;
        
    if (par){
        //pari: se c'è un numero pari di cifre 1 nell' array aggiungi 0 all' inzio, se sono dispari aggiungi 1
        for ( i = 1; i < DIM; i++){
            if (msg[i]){
                ctr++;
            }
        }
        if (ctr%2==0){  //Se c'è un numero pari di 1
            msg[0]=0;
        }else{
            msg[0]=1;
        }
    }else{
        for ( i = 1; i < DIM; i++){
            if (msg[i]){
                ctr++;
            }
        }
        if (ctr%2==0){  //Se c'è un numero pari di 1
            msg[0]=1;
        }else{
            msg[0]=0;
        }
    }  

    printf("\nMessaggio con parita':\n[");
    for ( i = 0; i < DIM; i++){
        printf("%2d ",msg[i]);
    }
    putchar(']');
}
void SimRumore( int msg[DIM]){
    msg[rand()%7+1]=rand()%2+0;
}              
void RiceviEControllaMSG( int msg[DIM], int par){
    int i,ctr;
    ctr=0;

    for ( i = 0; i < DIM; i++){
        if (msg[i]){
            ctr++;
        }  
    }

    if (ctr%2==0){
        ctr=1;          //1=n 1 par
    }else{
        ctr=0;          //0=n 1 dispari
    }
    
    printf("\nMessaggio ricevuto':\n[");
    for ( i = 0; i < DIM; i++){
        printf("%2d ",msg[i]);
    }
    putchar(']');

    if (par==ctr){
        printf("\nMessaggio corretto\n");
    }else{
        printf("\nMessaggio NON corretto\n");
    }  
} 