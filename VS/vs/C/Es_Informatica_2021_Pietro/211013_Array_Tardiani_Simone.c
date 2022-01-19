//211013_Array_tardiani_Simone.c
//1.Caricare un vettore di DIM=10 con num casuali tra 1 e 100.
//Inserire un numero N maggiore di 0 (controllo data entry).
//Contare quante volte occorre N nel vettore

#include <stdio.h>
#define DIM 10
#define RANDMIN 1
#define RANDMAX 100

int main(){
	int v[DIM],i,n,ctr;
	ctr=0;
	i=0;
	srand(time(NULL));
	
	do{
	printf("Numero:");
	scanf("%d",&n);
	fflush(stdin);
	}while(n<=0);
	
	//CARICAMENTO
	for(i=0;i<DIM;i++){
		v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
	}
	
	for(i=0;i<DIM;i++){
		if(v[i]==n){
			ctr++;
		}
	}
	
	//VIS
	for(i=0;i<DIM;i++){
		printf("%3d",v[i]);
	}
	printf("Numeri uguali a %d: %d",n,ctr);
		
}
