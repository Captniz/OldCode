//211008_017_Tardiani_Simone.c
/* Visualizzare la matrice. 
Individuare la colonna con somma degli elementi
massima e minima.
Scambiare le due colonne.
Visualizzare nuovamente la matrice. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 5
#define COL 7
#define RANDMIN 1
#define RANDMAX 20


int main()
{
    int m[ROW][COL],i,j,somma,maxS,minS,COLposMax,COLposMin,HoldNum;
    i=0;
    j=0;
    somma=0;
    maxS=ROW*RANDMIN;
    minS=ROW*RANDMAX;
    COLposMax=0;
    COLposMin=0;
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
            COLposMax=i;
        }
        if (somma<minS){
            minS=somma;
            COLposMin=i;
        }
        somma=0;
    }
    for ( i = 0; i < ROW; i++){
        HoldNum=m[i][COLposMax];
        m[i][COLposMax]=m[i][COLposMin];
        m[i][COLposMin]=HoldNum;
    }
    
    //Vis 2
    printf("Colonna con somma massima e' %d, la somma e' %d.",COLposMax+1,maxS);
    printf("\nColonna con somma minima e' %d, la somma e' %d.\n",COLposMin+1,minS);    
    
    //Vis 3
    for (i=0;i<ROW;i++){
        for (j=0;j<COL;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
