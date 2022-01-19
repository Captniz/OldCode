//211103_001_tardiani_simone.c 
/*la funzione sommaVet riceve in ingresso un vettore di interi e restituisce la somma dei suoi elementi.
Testare nel main la funzione (interi casuali tra 0 e 10).*/

#include<stdio.h>
#include<stdlib.h>
#define DIM 10

int sommaVet(int v[DIM]);
int LoadRandom(int v[DIM]);
int Vis(int v[DIM]);

int main(){
	int v[DIM];
	
	LoadRandom(v);
	Vis(v);
	putchar('\n');
	printf("%d",sommaVet(v));
	
		
	return 0;
}


LoadRandom(int v[DIM]){
	int i=0;
	srand(time(NULL));
	
	for(i=0;i<DIM;i++){
		v[i]=rand()%10+1;
	}
	
}

int Vis(int v[DIM]){
	int i=0;
	
	for(i=0;i<DIM;i++){
		printf("%d",v[i]);
	}
	
}

sommaVet(int v[DIM]){
	int i,somma;
	i=0;
	somma=0;

	for(i=0;i<DIM;i++){
		somma+=v[i];
	}
	
	return somma;
}
