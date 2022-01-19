//211218_53_tardiani_simone.c
/*convertire numero decimale a un array dimensionato DIM=8 binario 
es: 7[10]=00000111*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define DIM 8

void CreaInt(int *n);
void Converti(int n);

int main(){
	int i;
	int n;
	//chiamata funzione 1
	CreaInt(&n);
    Converti(n);
}

void CreaInt(int *n){
	//assegnazione del vettore
	printf("Inserisci decimale:");
    scanf("%d",n);
}

void Converti(int n){

    int i,v[DIM];
	
    for(i=0; i<DIM; i++){
        v[i]=0;
    }

    for ( i = 0; n!=0; i++){
        v[DIM-1-i]=n%2;
        n=n-v[DIM-1-i];
        printf("%3d | %3d\n",n,v[DIM-1-i]);
        n=n/2;
    }
    
    for(i=0; i<DIM; i++){
        printf("%d ",v[i]);
    }
	
}
