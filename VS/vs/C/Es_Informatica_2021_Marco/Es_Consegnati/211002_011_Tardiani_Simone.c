//211002_011_Tardiani_Simone.c
/*Crea un array con loading esterno in cui se si inserisce un numero gia precedentemente inserito, il numero viene chiedto di nuovo*/
#include<stdio.h>
#define DIM 10

int main()
{
    //Variabili
    int v[DIM],i,j;
    i=0;
    j=0;
    //Ciclo richiesta numeri
    for ( i = 0; i < DIM; i++){
        //Input
        printf("Numero %d:",i+1);
        scanf("%d",&v[i]);
        fflush(stdin);
        //Comparazione numeri precedenti
        for ( j = 0; j < i; j++){
            if (v[i]==v[j]){
             i--;
             j=DIM+1;   
            }    
        }
    }
    //Visualizzazione
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);
    }
    return 0;
}
