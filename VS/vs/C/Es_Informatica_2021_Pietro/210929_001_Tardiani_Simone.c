//Carica una matrice (random tra 1 e 100), misualizzarla, 
//misuallizzare la somma di tutti gli elementi 
//e calcola la media di una riga e di una colonna scelta dall'utente.
#define DIM 10
#define RANDMAX 100
#define RANDMIN 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main () {
	
	int m[DIM][DIM],i,j,s,NRow,NCol;
	float Media=0;
	i=0;
	j=0;
	s=0;
	srand(time(NULL));
	
	//Richiesta di riga e colonna da utente
	printf("Riga:");
	scanf("%d",&NRow);
	printf("Colonna:");
	scanf("%d",&NCol);
		
	//Caricamento
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++){
			m[i][j]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;		
			s+=m[i][j];
		}
	}
	
	//Visualizzazione
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++){
			printf("%4d",m[i][j]);
		}
		putchar('\n'); //Visualizza un solo carattere
	}	
	
	for(i=0;i<DIM;i++){
		Media+=m[NRow-1][i];
	}
	Media=Media/DIM;
	printf("\nMedia Riga:%f",Media);
	
	Media=0;
	for(i=0;i<DIM;i++){
		Media+=m[i][NCol-1];
	}
	Media=Media/DIM;
	printf("\nMedia Colonna:%f",Media);
	
	printf("\nSomma:%d", s);
	return 0;
}
