//220107_055_tardiani_simone.c
/*Ci sono 2 gare di 10 atleti con punteggio [1..50] 
ordinate gara1 e gara2 in modo decrescente
scrivere gli atleti che hanno realizzato i 3 migliori tempi tenendo conto delle due gare

es di 2 gare tra 5 atleti: (1 7 sta per atleta1 con punteggio 7)
gara1: 1  7, 2 21, 3 12, 4 45, 5 13
gara2: 1 17, 2 20, 3 12, 4 41,	5 18

ordinamento gara 1
4 45, 2 21, 5 13, 3 12, 1 7

ordinamento gara 2
4 41, 2 20, 5 18, 1 17, 3 12

3 migliori tempi:
4 45, 4 41, 2 21 
(cioè l'atleta4 si piazza al primo posto con 45 e al secondo posto con 41, terzo l'atleta2 con 21)*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DIM 6

void RandomLoad(int m[2][DIM]);
void Sort(int m[2][DIM]);
void Vis(int m[2][DIM]);

int main(){
    int i,j;
    int g1[2][DIM],g2[2][DIM],max[2][DIM];
    i=0;
    j=0;
    srand(time(NULL));
    
    RandomLoad(g1);
    RandomLoad(g2);

    Sort(g1);
    Sort(g2);

    printf("Gara 1:");
    Vis(g1);
    printf("Gara 2:");
    Vis(g2);

    for ( i = 0; i < 3; i++){
        max[0][i]=g1[0][i];
        max[1][i]=g1[1][i];
    }

    for ( i = 3; i < 6; i++){
        max[0][i]=g2[0][i-3];
        max[1][i]=g2[1][i-3];
    }   

    Sort(max);
    printf("Max:");
    Vis(max);

    return 0;
}

void RandomLoad(int m[2][DIM]){

    int i=0;

    for ( i = 0; i < DIM; i++){
        m[0][i]=rand()%50+1;  
        m[1][i]=i+1;     
    }
    
}

void Sort(int m[2][DIM]){

    int box,i,j;
    j=0;
    i=0;
    box=0;

    for ( i = 0; i < DIM-1; i++){
        for ( j = i+1; j < DIM; j++){
            if (m[0][i]<m[0][j]){
                box=m[0][j];
                m[0][j]=m[0][i];
                m[0][i]=box;    

                box=m[1][j];
                m[1][j]=m[1][i];
                m[1][i]=box;           
            }
        }
    }
}

void Vis(int m[2][DIM]){

    int i=0;

    printf("\n");
    for ( i = 0; i < DIM; i++){
        printf("%2d\t%2d",m[1][i],m[0][i]);
        printf("\n");
    }
    printf("\n");
}