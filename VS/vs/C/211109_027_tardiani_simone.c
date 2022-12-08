//211109_027_tardiani_simone.c
/* 27>  Caricare una matrice quadrata m con DIM=10 con tutti 0.
Visualizzare la matrice.
Sovrascivere sulla matrice numeri progressivi, in senso orario, a partire dalla prima riga, ultima colonna, ultima riga e proma colonna. */

#include<stdio.h>
#define DIM 10

void azzera(int m[][DIM]);
void visualizza(int m[][DIM]);
void carica(int m[][DIM]);

int main()
{
    int m[DIM][DIM];
    azzera(m);
    visualizza(m);
    putchar('\n');
    carica(m);
    visualizza(m);
    return 0;
}

void azzera(int m[][DIM]){

    int i,j;
    j=0;
    i=0;

    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            m[i][j]=0;
        }
    }

}

void visualizza(int m[][DIM]){


    int i,j;
    j=0;
    i=0;

    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }

}

void carica(int m[][DIM]){
    
    int i,j;
    j=0;
    i=0;
    
    for ( i = 0; i < DIM; i++)
    {




        
        for ( j = 0; j < DIM; j++)
        {
            if (j==DIM-1 || i==0)
            {
                m[i][j]=i+j+1;
            }
            if ((j<DIM-1 && i==DIM-1) || (j==0 && i>0) )
            {
                m[i][j]=((DIM*4)-3)-(i+j);
            }  
        }
    }
}