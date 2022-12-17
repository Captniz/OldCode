/*Caricare una matrice quadrata con DIM=10 con numeri random [1..9] nella parte superiore.
/Nella parte inferiore gli elementi sono posti = 0.*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
int main()
{
    int m[DIM][DIM],i,j;
    srand(time(NULL));
    //Load
    for(i=0;i&lt;DIM;i++){
        for(j=0;j&lt;DIM;j++){
            if(i&gt;j){
                m[i][j]=0;
            }else{
                m[i][j]=rand()%(9-1+1)+1;
            }
        }
    }
    //Vis
    for(i=0;i&lt;DIM;i++){
        for(j=0;j&lt;DIM;j++){
        	printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
