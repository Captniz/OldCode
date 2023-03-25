//211006_Divisori_Tardiani_Simone.c
//Scrivi un programma che legga un numero e stampi tutti i suoi divisori.
#include<stdio.h>
int main()
{
    int n,i;
    n=0;
    i=0;

    printf("Numero?:");
    scanf("%d",&n);

    for (i=1; i<=(n/2); i++){
        if (n%i==0 || n==0){
            printf("\n%d e' un divisore di %d",i,n);
        }
    }
    printf("\n%d e' un divisore di %d",n,n);
    return 0;
}