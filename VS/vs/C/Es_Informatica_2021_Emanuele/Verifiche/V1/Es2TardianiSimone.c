//tardiani_simone
//ottenere un numero binario random e convertirlo a decimale attraverso due funzioni
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DIM 7

void CreaBinario(int v[DIM]);
int Converti(int v[DIM]);

int main(){
	int  i,v[DIM];
	
	//chiamata funzione 1
	CreaBinario(v);
	
	//stampa vettore
	for(i=0;i<DIM;i++){
		printf("%d",v[i]);
	}
	
	//chiamata e stampa funzione 2
	printf("\n%d",Converti(v));
}

void CreaBinario(int v[DIM]){
	
	int i;
	srand(time(NULL));
	i=0;
	
	//assegnazione del vettore
	for(i=0;i<DIM;i++){
		v[i]=rand()%2+0;
	}
}

int Converti(int v[DIM]){
	
	int i,dec,pow;
	dec=0;
	pow=1;
	i=0;
	
	//conversione
	for(i=DIM-1;i>=0;i--){
		//moltiplicazione per potenza di 2
		dec=dec+(v[i]*pow);
		//aumento potenza
		pow=pow*2;
	}
	
	return dec;
}
