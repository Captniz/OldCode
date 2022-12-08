//211201_02_Sirico_Davide.c
/*
Scrivere un programma che legga in ingresso due vettori di 10 elementi di interi maggiori di zero (codprod e vendite)
che contengono rispettivamente i codici prodotto (da 1 a 100) e le vendite di quel prodotto di un mese.
Stampare a video l’incidenza % delle vendite di ciascun prodotto sul totale dei prodotti venduti.
Le incidenza % di ciascun prodotto devono essere memorizzate in un vettore.
Nota bene: l’incidenza % delle vendite di un prodotto è uguale a:
Inc.% prodotto = (valore delle vendite del prodotto / totale delle vendite)*100
e deve essere scritto seguito dal carattere %.
*/

#include <stdio.h>
#define DIM 10
int main(){
    
    int i;
    float cod[DIM],vend[DIM],TotVend,inc[DIM];
    i=0;
    TotVend=0;

    for(i=0; i<DIM; i++){
        do{
            printf("Codice %d:",i+1);
            scanf("%f",&cod[i]);
            while(getchar()!='\n');
        }while(cod[i]<=0 || cod[i]>100); 
        
        do{
            printf("Vendite %d:",i+1);
            scanf("%f",&vend[i]);
            while(getchar()!='\n');
        }while(vend[i]<0);
        TotVend=TotVend+vend[i];
    }

    for ( i = 0; i < DIM; i++){
        inc[i]=(vend[i]/TotVend);
    }
    
    for(i=0; i<DIM; i++){
        printf("%f ",inc[i]);
    }

    return 0;
}
