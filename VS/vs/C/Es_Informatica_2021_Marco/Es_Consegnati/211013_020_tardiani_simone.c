//211013_020_tardiani_simone.c
/* 20 -Caricare una matrice quadrata m con numeri random [1..100].
Visualizzare la matrice.
Scambiare le righe 2 a 2(la prima con la seconda ... la penultima con l'ultima).
Visualizzare la matrice. */

#include<stdio.h>
#define DIM 6
#define RANDMIN 1
#define RANDMAX 10

int main(){
    
    int m[DIM][DIM],i,j,temp;
    i=0;
    j=0;
    temp=0;

    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            m[i][j]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
        }
    }

    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }

    for (i=0;i<DIM;i=i+2){
        for (j=0;j<DIM;j++){
            temp=m[i][j];
            m[i][j]=m[i+1][j];
            m[i+1][j]=temp;
        }
    }

    printf("\n");

    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
