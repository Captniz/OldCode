//Simone Tardiani | 3CIIN | 04/05/22
/*Scrivere un programma C  che generi casualmente un numero compreso 1..255 e azzeri un bit a caso, non già di valore 0. 
 A tal fine si devono utilizzare maschere e operatori bit a bit. Stampare i passaggi sia in decimale che in binario*/
 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 8

int main(){
	srand(time(NULL));
	int n,mask,i,flag;
	n=rand()%255+1;
	mask=1;
	flag=0;
	i=0;
	
	printf("Prima---------");
	
	printf("\nDecimale:%d",n);	//Visualizzazione Decimale
	
	printf("\nBinario:");		//Visualizzazione Binaria
	for(i=0;i<DIM;i++){			//Ciclo che scorre tutti i bit del numero partendo dall' ultimo in modo da visualizzare correttamente
		if((n>>(DIM-1-i))&1){	//Se il bit in esame è uguale a 1 stampa 1
			putchar('1');
		}else{
			putchar('0');		//Se il bit in esame è uguale a 0 stampa 0
		}
	}
	
	while(flag==0){				//Ciclo fino a che non viene scelto un bit casuale del numero con all'interno un uno
		i=rand()%8+0;			//Selezione casuale del bit
		if((n>>i)&1){			//Se il bit è uguale a uno
			n=n^(mask<<i);		//Viene portato a 0 con una maschera
			flag=1;
		}
	}
	
	printf("\nDopo---------");

	printf("\nDecimale:%d",n);	//Visualizzazione Decimale
	printf("\nBinario:");		//Visualizzazione Binaria
	
	for(i=0;i<DIM;i++){			//Ciclo che scorre tutti i bit del numero partendo dall' ultimo in modo da visualizzare correttamente
		if((n>>(DIM-1-i))&1){	//Se il bit in esame è uguale a 1 stampa 1
			putchar('1');
		}else{
			putchar('0');		//Se il bit in esame è uguale a 0 stampa 0
		}
	}
}

