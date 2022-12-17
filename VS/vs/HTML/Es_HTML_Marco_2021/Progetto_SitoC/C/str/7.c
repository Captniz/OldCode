/*33&gt; Inserire esternamente un numero di 5 cifre.
Demolire il numero nelle 5 cifre.
Caricarlo in un array DIM 5 nello stesso ordine.
*/
#include &lt;stdio.h&gt;
#define DIM 5
int main(){
    int v[DIM],n,mod,i;
    printf("Inserisci il numero di 5 cifre: ");
    scanf("%d",&n);
    fflush(stdin);
    for(i=DIM-1;i&gt;=0;i--){
        v[i]=n%10;
        n=n/10;
    }
    for(i=0;i&lt;DIM;i++){
        printf("%d ",v[i]);
    }
    return 0;
}
