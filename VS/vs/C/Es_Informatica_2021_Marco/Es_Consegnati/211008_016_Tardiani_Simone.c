//211008_016_Tardiani_Simone.c
/* Caricare una matrice con ROW = 5 e COL=7 con numeri random a piacere.
Visualizzare la matrice.
Individuare la colonna con somma degli elementi
massima.
Visualizzare la colonna. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 5
#define COL 7
#define RANDMIN 1
#define RANDMAX 20


int main()
{
    int m[ROW][COL],i,j,somma,maxS,COLpos;
    i=0;
    j=0;
    somma=0;
    maxS=0;
    COLpos=0;
    srand(time(NULL));
    //Load
    for (i=0;i<ROW;i++){
        for (j=0;j<COL;j++){
            m[i][j]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
        }
    }
    //Vis
    for (i=0;i<ROW;i++){
        for (j=0;j<COL;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    //Analisi
    for (i=0;i<COL;i++){
        for (j=0;j<ROW;j++){
            somma+=m[j][i];
        }
        if (somma>maxS){
            maxS=somma;
            COLpos=i;
        }
        somma=0;
    }
    //Vis 2
    printf("Colonna con somma massima e' %d, la somma e' %d.",COLpos+1,maxS);
    //Vis 3
    printf("\n");
    for(i=0; (i<ROW); i++){
        printf("%d ",m[i][COLpos]);
        printf("\n");
    }
    return 0;
}