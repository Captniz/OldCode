/*
//*1) Prova AND, OR, XOR, NOT e SHIFT
//*2) Stampa ogni bit di un  valore di una numiabile
//*3) Scrivere un programma che conta i bit ad 1
//*4) Chiedere in input un intero da 0 a 255 (max rappresentabile con 8 bit), controlla l’input e stampare il numero in binario. Calcolare la parità p (pari) e aggiungerla e al numero inserito che diventerà n_con_p. Stampare in binario il numero con il bit di parità n_con_p (ricorda che il bit di parità va aggiunto in testa, quindi è il bit più significativo).
//*5) Chiedere in input un intero n da 0 a 255 (max rappresentabile con 8 bit), controllare l’input e stampa il numero in binario.
//*Calcolare la parità p1 e aggiungerla al numero inserito che diventerà n_con_p1.
//*Stampare in binario il numero con il bit di parità n_con_p1: è questo il numero che verrà trasmesso. 
//*Creare una maschera mask con un solo bit 1 e tutti gli altri a 0 (2pos oppure 1<<pos, dove pos è un numero casuale fra 0 e 8). Stampare la maschera ottenuta in binario.
//*Simulare un errore di trasmissione, cambiando il valore di un bit del numero n_con_p1. Per fare ciò utilizzare la maschera mask creata ed effettuare operazione XOR col n_con_p1.
//*Stampare in binario il numero corrotto ottenuto n_err
//*Calcolare la parità di n_err, p2
//*Rilenume o meno la presenza dell'errore (calcolando la parità p2 di n_err otterremo 1 o 0: se p2 = 1 il numero è arrivato corrotto a destinazione, altrimenti è integro)
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 8

void inputn(int *n);
void Visbin(int n,int dim);
int BitUno(int n,int dim);
int ParitaOriz(int n,int ctr);
void ParitaVert(int v[]);
int AggiungiErrore(int n,int mask);
int RilevaErrore(int par);

int main(){
    srand(time(NULL));
    int mask,i,j,ctr,Bit[(DIM+1)];
    ctr=0;
    i=0;
    j=0;
    
    for(i=0;i<DIM;i++){
        mask=(1<<rand()%9+0)*(rand()%2+0);    // "*rand()%2+0" serve per avere la possibilità di non avere errori
        printf("\n\n%d:",i+1);
        inputn(&Bit[i]);
        printf("\nMSG:\t\t\t");
        Visbin(Bit[i], DIM);
        ctr=0;
        ctr=BitUno(Bit[i],DIM);
        printf("\nNumero di bit ad 1:\t%d",ctr);
        Bit[i]=ParitaOriz(Bit[i],ctr);
        printf("\nMSG con parita:\t\t");
        Visbin(Bit[i], (DIM+1));
        printf("\nMaschera:\t\t");
        Visbin(mask, (DIM+1));
        Bit[i]=AggiungiErrore(Bit[i],mask);
        printf("\nMSG con errore:\t\t");
        Visbin(Bit[i], (DIM+1));
    }
    Bit[DIM]=0;
    ParitaVert(Bit);
    putchar('\n');
    for ( i = 0; i < (DIM+1); i++){
        putchar('\n');
        Visbin(Bit[i],(DIM+1));
    }
    for ( i = 0; i < DIM+1; i++){
        if(RilevaErrore(BitUno(Bit[i],DIM+1))){
            printf(":Riga %d",(i+1));
            exit(1);
        }
    }
    

    return 0;
}

void inputn(int *n){
    do{
    printf("N?:");
    scanf("%d",n);
    }while(*n<0 || *n>255);
}
void Visbin(int n,int dim){

    int i;
    for ( i = 0; i < dim; i++){
        if (n>>(dim-1-i) & 1){
            printf("1");
        }else{
            printf("0");
        }
    }
}
int BitUno(int n,int dim){
    int i,ctr=0;

    for ( i = 0; i < dim; i++){
        if (n>>(dim-1-i) & 1){
            ctr++;
        }
    }

    return ctr;
}
int ParitaOriz(int n,int ctr){
    if (ctr%2!=0){
        n=n|256;
        //1 0000 0000
    }

    return n;
}
int AggiungiErrore(int n,int mask){
    n=n^mask;
    return n;
}
int RilevaErrore(int par){
    if (par%2==1){
        printf("\nErrore rilevato");
        return 1;
    }
    return 0;
}
void ParitaVert(int v[(DIM+1)]){
    int i,j,ctr;
    j=0;
    i=0;
    ctr=0;

    //scorre i bit
    for ( i = 0; i < (DIM+1); i++){
        ctr=0;
        //scorre i byte
        for ( j = 0; j < DIM; j++){
            if(((v[j]>>i)&1)){
                ctr++;
            }
        }
        if (ctr%2==1){
            v[DIM]=v[DIM]|(1<<i); 
        }
    }
}