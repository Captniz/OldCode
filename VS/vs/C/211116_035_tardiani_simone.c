//211116_035_tardiani_simone.c
/* 35> Scrivere una funzione che calcoli una qualunque potenza maggiore o uguale a zero.
long int potenza(int , int); */

#include<stdio.h>

int main(){

    int ris,i,n,p;
    n=0;
    p=0;
    ris=1;
    i=0;

    printf("Numero?:");
    scanf("%d",&n);

    printf("Potenza?:");
    scanf("%d",&p); 

    for ( i = 0; i < p; i++){
        ris=ris*n;
    }
    
    printf("%d",ris);

    return 0;
}
