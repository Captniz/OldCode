//211008_Multipli_Tre_Tardiani_Simone.c
//Leggi dei numeri, se sono pari inverti il segno mentre se sono dispari falli diventare dei sivisori di 3
#include<stdio.h>

int main()
{
    int i,n;
    i=0;
    n=0;

    for ( i = 0; i < 10; i++){
        printf("Numero %d?:",i+1);
        scanf("%d",&n);

        if (n%2==0){
            n=n*(-1);
        }else{
            while (n%3!=0){    
            n=n+1;};            
        }
        printf("%d\n",n);
    }
    return 0;
}
