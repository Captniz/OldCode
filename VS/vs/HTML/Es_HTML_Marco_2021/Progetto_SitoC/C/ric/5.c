/*70> Algoritmo ricorsivo per la ricerca di un intero in un vettore
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
void carica(int []);
void visualizza(int []);
int ricerca(int [],int , int);
int main()
{
	srand(time(NULL));
	int v[DIM],n;
	carica(v);
	visualizza(v);
	printf("inseire un numero: ");
	scanf("%d",&n);
	fflush(stdin);
	if(ricerca(v,0,n)==1){
		printf("il numero %d e' presente nell'array",n);
	}else{
		printf("il numero %d non e' presente nell'array",n);
	}
	return 0;
}
void carica(int v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		v[i]=rand()%20+1;
	}
}
void visualizza(int v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		printf("%4d",v[i]);
	}
	putchar('\n');
}
int ricerca(int v[DIM],int i, int n){
	if(i>=DIM)
		return 0;
	if(v[i]==n)
		return 1;
	else
		return ricerca(v,i+1,n);
	
}
