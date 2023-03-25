//211006_014_Tardiani_Simone.c
//Caricare un vettore v dimensionato 10 con in primi 10 numeri naturali.
//Eseguire un left-shift (spingere a sx) 1 2 3 4 5 6 7 8 9 10 ->  2 3 4 5 6 7 8 9 10 1
#include<stdio.h>
#define DIM 10

int main()
{
    int v[]={1,2,3,4,5,6,7,8,9,10}, FirstNum, i ;
    FirstNum=0;
    i=0;
    //Shift
    FirstNum=v[0];
    for ( i = 1; i <DIM; i++){
        v[i-1]=v[i] ;
    }
    v[DIM-1]=FirstNum;
    //Vis
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);
    }
    return 0;
}
