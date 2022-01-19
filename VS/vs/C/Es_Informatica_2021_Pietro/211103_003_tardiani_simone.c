//211103_003_tardiani_simone.c
/*la funzione maxMat riceve in ingresso una matrice quadrata di interi e restituisce la somma maggiore di due elementi adiacenti (di riga).
Testare nel main la funzione (interi casuali tra 1 e 30).*/

#include<stdio.h>
#define DIM 10

int maxMat(int m[DIM][DIM]);
int LoadRan(int m[DIM][DIM]);
int Vis(int m[DIM][DIM]);

int main(){
	int m[DIM][DIM];
	
	LoadRan(m);
	Vis(m);
	putchar('\n');
	maxMat(m);
	return 0;
}

int LoadRan(int m[DIM][DIM]){
	int i,j;
	i=0;
	j=0;
	srand(time(NULL));
	
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			m[i][j]=rand()%30+1;
		}
	}
}

int Vis(int m[DIM][DIM]){
	int i,j;
	i=0;
	j=0;
	
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("%3d",m[i][j]);
		}
		putchar('\n');
	}	
	
}

int maxMat(int m[DIM][DIM]){
	int max,i,j,N1,N2,row;
	max=0;
	i=0;
	j=0;
	N1=0;
	N2=0;
	row=0;
	
	for(i=0;i<DIM;i++){
		for(j=0;j+1<DIM;j++){
			if(max<(m[i][j]+m[i][j+1])){
				max=m[i][j]+m[i][j+1];
				N1=m[i][j];
				N2=m[i][j+1];
				row=i-1;
			}	
		}
	}	
	
	printf("%d = %d + %d, riga:%d",max,N1,N2,row);
}
