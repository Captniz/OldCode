//211218_52_tardiani_simone.c
/*convertire un array dimensionato DIM=8 da binario a decimale
es int v[]={0,0,0,0,1,1,0,1}; //un byte
00001101[2]=13[10]*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define DIM 8

void CreaBinario(char v[DIM]);
int Converti(char v[DIM]);

int main(){
	int  i;
	char v[DIM];
	//chiamata funzione 1
	CreaBinario(v);
	
	//stampa vettore
	for(i=0;i<DIM;i++){
		printf("%d",v[i]);
	}
	printf(" [2]");

	//chiamata e stampa funzione 2
	printf("\n%d [10]",Converti(v));
}

void CreaBinario(char v[DIM]){
	
	int i;
	srand(time(NULL));
	i=0;
	
	//assegnazione del vettore
	printf("Inserisci binario:");
    gets(v);
    for(i=0;i<DIM;i++){
        v[i]=v[i]-48;
	}
}

int Converti(char v[DIM]){
	
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
