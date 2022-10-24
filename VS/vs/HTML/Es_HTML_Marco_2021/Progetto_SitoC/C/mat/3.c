/*17> Caricare una matrice con ROW = 5 e COL=7 con numeri random a piacere.
Visualizzare la matrice. 
Individuare la colonna con somma degli elementi
massima e minima.
Scambiare le due colonne.
Visualizzare nuovamente la matrice*/
#include<stdio.h>
#define ROW 5
#define COL 7
int main()
{
	int m[ROW][COL],i,j,sc,posmin,posmax,max,min;
	srand(time(NULL));
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			m[i][j]=rand()%20+1;
			printf("%2d\t",m[i][j]);
		}
		putchar('\n');
	}
	for(j=0;j<COL;j++){
		for(i=0;i<ROW;i++){	
			sc=sc+m[i][j];		
			if(j==0){
				max=sc;
				posmax=j;
				min=sc;
				posmin=j;
			}
			if(sc>max){
				max=sc;
				posmax=j;
			}
			if(i>=ROW-1){
				if(sc<min){
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
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
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
