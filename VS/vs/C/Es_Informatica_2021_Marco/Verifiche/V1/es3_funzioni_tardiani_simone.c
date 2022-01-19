//es3_tardiani_simone.txt

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DIM 10

//Funzioni
void vis(int m[DIM][DIM]);
void load(int m[DIM][DIM]);
void azzera(int m[DIM][DIM]);

int main(){
	int m[DIM][DIM];
	
	load(m);
	vis(m);
	azzera(m);
	vis(m);

	return 0;
}

void vis(int m[DIM][DIM]){
	
	int j,i;
	i=0;
	j=0;

	printf("\n\n");
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("%3d",m[i][j]);
		}
		putchar('\n');
	}
}

void load(int m[DIM][DIM]){
	
	int j,i;
	i=0;
	j=0;	
	srand(time(NULL));

	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			m[i][j]=rand()%90+10;
		}
	}
}

void azzera(int m[DIM][DIM]){

	int diagDes,diagSin,i;
	i=0;
	diagSin=0;
	diagDes=DIM-1;
		
	for(i=0;i<DIM;i++){
		m[i][diagDes]=0;
		m[i][diagSin]=0;
		diagDes--;
		diagSin++;
	}	
}