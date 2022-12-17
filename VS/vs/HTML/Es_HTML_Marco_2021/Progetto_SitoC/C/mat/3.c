/*17&gt; Caricare una matrice con ROW = 5 e COL=7 con numeri random a piacere.
Visualizzare la matrice. 
Individuare la colonna con somma degli elementi
massima e minima.
Scambiare le due colonne.
Visualizzare nuovamente la matrice*/
#include&lt;stdio.h&gt;
#define ROW 5
#define COL 7
int main()
{
	int m[ROW][COL],i,j,sc,posmin,posmax,max,min;
	srand(time(NULL));
	for(i=0;i&lt;ROW;i++){
		for(j=0;j&lt;COL;j++){
			m[i][j]=rand()%20+1;
			printf("%2d\t",m[i][j]);
		}
		putchar('\n');
	}
	for(j=0;j&lt;COL;j++){
		for(i=0;i&lt;ROW;i++){	
			sc=sc+m[i][j];		
			if(j==0){
				max=sc;
				posmax=j;
				min=sc;
				posmin=j;
			}
			if(sc&gt;max){
				max=sc;
				posmax=j;
			}
			if(i&gt;=ROW-1){
				if(sc&lt;min){
					min=sc;
					posmin=j;
				}
			}
		}
		sc=0;
	}
	putchar('\n');
	printf("la colonna con la somma massima vale: %d posizione %d\n",max,posmax);
	printf("la colonna con la somma minima vale: %d posizione %d\n",min,posmin);
	putchar('\n');
	for(i=0;i&lt;ROW;i++){
		for(j=0;j&lt;COL;j++){
			if(j!=posmin && j!=posmax){
				printf("%2d\t",m[i][j]);
			}else{
				if(j==posmin){
					printf("%2d\t",m[i][posmax]);
				}else{
					printf("%2d\t",m[i][posmin]);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
