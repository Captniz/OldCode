/*16&gt; Caricare una matrice con ROW = 5 e COL=7 con numeri random a piacere.
Visualizzare la matrice.
Individuare la colonna con somma degli elementi
massima.
Visualizzare la colonna. */
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define ROW 5
#define COL 7
int main()
{
    int m[ROW][COL],i,j,somma,maxs,colpos;
    i=0;
    j=0;
    somma=0;
    maxs=0;
    colpos=0;
    srand(time(NULL));
    //Load
    for(i=0;i&lt;ROW;i++){
        for(j=0;j&lt;COL;j++){
            m[i][j]=rand()%(20-1+1)+1;
        }
    }
    //Vis
    for(i=0;i&lt;ROW;i++){
        for(j=0;j&lt;COL;j++){
        	printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    for(i=0;i&lt;COL;i++){
    	for(j=0;j&lt;ROW;j++){
    		somma+=m[j][i];
        }
        if(somma&gt;maxs){
        	maxs=somma;
        	colpos=i;
        }
        somma=0;
    }
    //Vis 2
    printf("\nColonna con somma massima e' %d, la somma e' %d.",colpos,maxs);
    //Vis 3
    printf("\n");
    for(i=0;i&lt;ROW;i++){
        printf("%3d",m[i][colpos]);
        printf("\n");
    }
    return 0;
}
