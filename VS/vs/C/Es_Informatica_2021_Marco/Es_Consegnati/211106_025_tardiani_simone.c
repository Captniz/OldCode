//211106_025_tardiani_simone.c
/*25> Caricare un vettore v con DIM=10 con numeri random [10..99].
Visualizzare il vettore.
Scambiare gli elementi due a due: primo col secondo etc.
Visualizzare il vettore. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
#define RANDMIN 10
#define RANDMAX 99

int carica(int v[DIM]);
int visualizza(int v[DIM]);
int scambia(int v[DIM]);

int main(){
    
    int i,v[DIM],temp;
    i=0;
    temp =0;

    carica(v);
    visualizza(v);
    scambia(v);
    printf("\n");
    visualizza(v);

    return 0;
}

int carica(int v[DIM]){
    int i=0;

    for(i=0; i<DIM; i++){
        v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
    }
}
int visualizza(int v[DIM]){
    int i=0;

    for(i=0; i<DIM; i++){
        printf("%3d ",v[i]);
    }
}
int scambia(int v[DIM]){
    
    int i,temp;
    i=0;
    temp=0;

    for ( i = 0; i < DIM; i=i+2){
        temp=v[i];
        v[i]=v[i+1];
        v[i+1]=temp;
    }
}