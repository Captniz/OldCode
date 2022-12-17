/*20&gt; Caricare una matrice quadrata m con numeri random [1..100].
Visualizzare la matrice.
Scambiare le righe 2 a 2(la prima con la seconda ... la penultima con l'ultima).
Visualizzare la matrice.*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 6
int main(){
	srand(time(NULL));
    int m[DIM][DIM],i,j,temp;
    for (i=0;i&lt;DIM;i++){
        for (j=0;j&lt;DIM;j++){
            m[i][j]=rand()%(10-1+1)+1;
        }
    }
    for (i=0;i&lt;DIM;i++){
        for (j=0;j&lt;DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    for (i=0;i&lt;DIM-1;i=i+2){
        for (j=0;j&lt;DIM;j++){
            temp=m[i][j];
            m[i][j]=m[i+1][j];
            m[i+1][j]=temp;
        }
    }
    putchar('\n');
    for (i=0;i&lt;DIM;i++){
        for (j=0;j&lt;DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
