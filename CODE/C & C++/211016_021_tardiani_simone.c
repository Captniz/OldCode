//211016_021_tardiani_simone.c
/* 021 - Caricare un vettore v di DIM=20 con i primi DIM numeri della successione di FIBONACCI.
Visualizzare un vettore v. */

#include<stdio.h>
#define DIM 20

int main(){

    int i,v[DIM];
    i=0;
    v[0]=v[1]=1;

    for ( i = 2; i < DIM; i++){
        v[i]=v[i-1]+v[i-2];
    }
    
    for(i=0;i<DIM; i++){
        printf("%d ",v[i]);
    }

    return 0;
}
