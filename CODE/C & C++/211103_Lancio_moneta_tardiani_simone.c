//211103_Lancio_moneta_tardiani_simone.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10

void Moneta();

int main()
{
    int i;
    i=0;
    srand(time(NULL));
    
    for (i = 0; i < DIM; i++){
        Moneta();
    }
    return 0;
}

void Moneta(){
    int a;
    a=0;

    a=rand()%2+0;
    if (a==1){
        printf("Testa ");
    }else{
        printf("Croce ");
    }
}