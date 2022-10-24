/*33> Inserire esternamente un numero di 5 cifre.
Demolire il numero nelle 5 cifre.
Caricarlo in un array DIM 5 nello stesso ordine.
*/
#include <stdio.h>
#define DIM 5
int main(){
    int v[DIM],n,mod,i;
    printf("Inserisci il numero di 5 cifre: ");
    scanf("%d",&n);
    fflush(stdin);
    for(i=DIM-1;i>=0;i--){
        v[i]=n%10;
        n=n/10;
    }
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    return 0;
}
