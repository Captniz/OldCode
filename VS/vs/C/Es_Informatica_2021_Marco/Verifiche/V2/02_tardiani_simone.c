/*2> Dato un array di interi di dimensione DIM, scrivere solo la funzione:int min_med(int [ ]);
se ogni valore presente nell’array è minore della somma dei numeri presenti nelle 
celle che lo precedonor estituisce 1 altrimenti restituisce 0*/

#include<stdio.h>
#define DIM 5
int min_med(int v[DIM]);

int min_med(int v[DIM]){

    int i,sum;
    i=0;
    sum=v[i];

    for (i=1; i<DIM; i++){
        if (v[i]>=sum){
            return 0;
        }
        sum=sum+v[i];
    }
    return 1;
}