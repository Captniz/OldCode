/*61> Eseguire una ricerca binaria su un array v dimensionato DIM=10.
Inserire un valore esternamente e trovare se appartiene o meno a v.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
void carica(int []);
void visualizza(int []);
void sort(int []);
int binary_search(int [], int);
int main()
{
	srand(time(NULL));
	int v[DIM],n,ris;
	carica(v);
	visualizza(v);
	sort(v);
	visualizza(v);
	printf("inserire un numero da ricercare: ");
	scanf("%d",&n);
	putchar('\n');
	ris=binary_search(v,n);
	if(ris==-1){
		printf("%d non trovato",n);
	}else{
		printf("%d trovato nella posizione %d",n,ris);
	}
	return 0;
}
void carica(int v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		v[i]=rand()%50+1;
	}
}
void visualizza(int v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		printf("%3d",v[i]);
	}
	putchar('\n');
}
void sort(int v[DIM]){
	int i,j,box;
	for(i=0;i<DIM-1;i++){
		for(j=i+1;j<DIM;j++){
			if(v[i]>v[j]){
				box=v[i];
				v[i]=v[j];
				v[j]=box;
			}
		}
	}
}
int binary_search(int v[DIM], int n){
	int imin,imax,i;
	imin=0;
	imax=DIM-1;
	while(imin<=imax){
		i=(imin+imax)/2;
		if(v[i]==n){
			return i;
		}else{
			if(n>v[i]){
				imin=i+1;
			}else{
				imax=i-1;
			}
		}
	}
	return -1;
}
