//211105_Cornice_tardiani_simone.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10

void carica (int v[DIM]);
void carica_max (int v[DIM], int v2[DIM], int v3[DIM]);
void visualizza_frame(int v[DIM]);

int main()
{
    int v[DIM],v2[DIM],v3[DIM];

    carica(v);
    carica(v2);
    carica_max(v,v2,v3);
    visualizza_frame(v);  // potete passare un 2° parametro
    visualizza_frame(v2); // potete passare un 2° parametro
    visualizza_frame(v3); // potete passare un 2° parametro
    return 0;
}

void carica (int v[DIM]){

    int i;
    i=0;

    for(i=0; i<DIM; i++){
        v[i]=rand()%100+1;
    }
}

void carica_max (int v[DIM], int v2[DIM], int v3[DIM]){
    
    int i;
    i=0;

    for ( i = 0; i < DIM; i++){
        if (v[i]>v2[i]){
            v3[i]=v[i];
        }else{
            v3[i]=v2[i];
        }        
    }
}

void visualizza_frame(int v[DIM]){

    int i=0;

    for ( i = 0; i < DIM; i++){
        printf(" %c%c%c",196,196,196);
    }

    printf("\n");

    for ( i = 0; i < DIM; i++){
        putchar(179);
        printf("%3d",v[i]);
    }

    putchar(179);

    printf("\n");

    for ( i = 0; i < DIM; i++){
        printf(" %c%c%c",196,196,196);
    }

    printf("\n");
}