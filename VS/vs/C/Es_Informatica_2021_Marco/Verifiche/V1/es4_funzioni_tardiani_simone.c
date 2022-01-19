//es4_tardiani_simone.txt

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DIM 10

//Funzioni
void visMatrice(int m[DIM][DIM]);
void load(int m[DIM][DIM]);
void visArray(int v[DIM]);
void MaxCol(int m[DIM][DIM],int v[DIM]);

int main(){
	int m[DIM][DIM],v[DIM],j,i,max;
	i=0;
	j=0;
	max=0;	

	load(m);

	visMatrice(m);

	MaxCol(m, v);

	visArray(v);

	return 0;
}

void visMatrice(int m[DIM][DIM]){
	
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

void visArray(int v[DIM]){
	
	int i;
	i=0;

	printf("\n\n");
	for(i=0;i<DIM;i++){
		printf("%3d",v[i]);
	}
}

void MaxCol(int m[DIM][DIM],int v[DIM]){

	int j,i,max;
	i=0;
	j=0;
	max=0;

	for(i=0;i<DIM;i++){
		max=m[0][i];	
		for(j=0;j<DIM;j++){
			if(m[j][i]>max){
				max=m[j][i];
			}	
		}
		v[i]=max;
	}
}