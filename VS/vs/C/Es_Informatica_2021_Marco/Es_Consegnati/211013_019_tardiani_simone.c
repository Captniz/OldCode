//211013_019_tardiani_simone.c
/* 019 - Caricare un vettore v di DIM=10 con numeri random [1..100].
Inserire esternamente un numero N > 0 (data entry).
Contare quante volte occorre N nel vettore.
Visualizzare N. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
#define RANDMIN 1
#define RANDMAX 100

int main(){

    int v[DIM],n,i,ctr;
    i=0;
    n=0;
    ctr=0;

    printf("Numero?:");
    scanf("%d",&n);
    fflush(stdin);

    for(i=0; i<DIM; i++){
        v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
    }

    for(i=0;i<DIM; i++){
        printf("%d ",v[i]);
    }

    for(i=0; i<DIM; i++){
        if (v[i]==n){
            ctr++;
        }
    }

    printf("\nIl numero e' presente %d volte.", ctr);

    return 0;
}
