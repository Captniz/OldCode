//220106_DataMesi_tardiani_simone.c
/*Scrivi un programma che, dato un array ( inizializzato opportunamente) avente i giorni totali dei singoli mesi dell’anno 
richieda da tastiera due date specifiche dell’anno (una data è composta da un numero per il giorno e un numero per il mese). 
Una volta controllate le date il programma deve calcolare quanti giorni ci sono tra le due date.*/

#include<stdio.h>

int GiorniData ();

int main(){

    int Data1,Data2;
    Data1 = GiorniData();
    Data2 = GiorniData();

    if (Data1 < Data2){
        printf("Tra la seconda e la prima data ci sono %d giorni",Data2-Data1);
    }else{
        printf("Tra la prima e la seconda data ci sono %d giorni",Data1-Data2);
    }

    return 0;
}

int GiorniData (){

    int Mesi[12] ={31,28,31,30,31,30,31,31,30,31,30,31},M,G,SommaGiorni,i;
    M=0;
    G=0;
    SommaGiorni=0;
    i=0;

    do{
    printf("Mese:");    
    scanf("%d",&M);
    }while(M<1 || M>12);

    M=M-1;

    do{
    printf("Giorno:");    
    scanf("%d",&G);
    }while(G<1 || G>Mesi[M]);

    printf("\n");

    for ( i = 0; i < M; i++){
        SommaGiorni = SommaGiorni + Mesi[i];
    }
    
    SommaGiorni= SommaGiorni + G;

    return SommaGiorni;
}