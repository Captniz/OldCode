/*63> dato un vettore numerico v dimensionato DIM=20 con caricamento random [1..9] 
visualizzare la cifra che presenta più occorrenze
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 20
void carica(int []);
void visualizza(int []);
void sort(int []);
int occorrenze(int []);
int main()
{
	srand(time(NULL));
	int v[DIM],c;
	carica(v);
	visualizza(v);
	sort(v);
	visualizza(v);
	c=occorrenze(v);
	printf("il numero con piu' occorrenze e': %d",v[c]);
	return 0;
}
void carica(int v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		v[i]=rand()%9+1;
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
int occorrenze(int v[DIM]){
	int i,j,c,max,pos;
	int occ[DIM];
	for(i=0;i<DIM;i++){
		j=i+1;
		c=1;
		while(j<DIM){
			if(v[i]==v[j]){
				c++;
			}
			j++;
		}
		occ[i]=c;
	}
	max=occ[0];
	pos=0;
	for(i=1;i<DIM;i++){
		if(occ[i]>max){
			max=occ[i];
			pos=i;
		}
	}
	return pos;
}
