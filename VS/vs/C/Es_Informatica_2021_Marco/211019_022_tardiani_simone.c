//211019_022_tardiani_simone.c
/* 22> Scrivere un programma che, letti gli elementi di due vettori v e v2 di lunghezza 5, determini il vettore w di lunghezza 10 ottenuto “appendendo” gli elementi di v2 a v. 
Visualizzare v, v2 e w. */

#include<stdio.h>
#define DIM 5

int main(){

    int i,v[DIM]={'p','i','p','p','o'},vv[DIM]={'p','l','u','t','o'},w[DIM*2];

    for ( i = 0; i < DIM; i++){
        w[i]=v[i];
    }
    

    for ( i = 0; i < DIM; i++){
        w[i+DIM]=vv[i];
    }
    
    for(i=0; i<DIM; i++){
        printf("%c",v[i]);
    }

    printf("\n");

    for(i=0; i<DIM; i++){
        printf("%c",vv[i]);
    }

    printf("\n");

    for(i=0; i<DIM*2; i++){
        printf("%c",w[i]);
    }

    return 0;
}