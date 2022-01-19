//211013_Matrice_tardiani_Simone.c
//2.Caricare una matrice quadrata di DIM=10 con num casuali tra 1 e 100.
//Scambiare le rgihe a due a due.
//visualizzare.
#include<stdio.h>
#define DIM 10
#define RANDMIN 1
#define RANDMAX 100

int main(){

	int m[DIM][DIM],i,j,temp,CTRcol;
	i=0;
	j=0;
	temp=0;
	CTRcol=0;
	
	//CARICMAENTO
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			m[i][j]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
		}
	}	
	
	//Vis
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("%4d",m[i][j]);
		}
		printf("\n");
	}
	
	//ANALISI
	for(j=0;j<(DIM/2);j++){
		for(i=0;i<DIM;i++){
			temp=m[CTRcol][i];
			m[CTRcol][i]=m[CTRcol+1][i];
			m[CTRcol+1][i]=temp;	
		}
		CTRcol=CTRcol+2;
	}
	
	printf("\n");
	//Vis
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("%4d",m[i][j]);
		}
		printf("\n");
	}
}
