//211113_033_tardiani_simone.c
/*33> Inserire esternamente un numero di 5 cifre.
Demolire il numero nelle 5 cifre.
Caricarlo in un array DIM 5 nello stesso ordine.*/

#include<stdio.h>
#define DIM 5

int main(int argc, char const *argv[])
{
    int n,i,pow,v[DIM];
    n=0;
    i=0;
    pow=10;

    do{
        printf("Numero?:");
        scanf("%d",&n);
    }while(n<=9999);

    for ( i = DIM-1; i >=0; i--){
        v[i]=(n%pow)/(pow/10);
        pow*=10;
        n-=v[i];
    }
    
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);
    }
    return 0;
}
