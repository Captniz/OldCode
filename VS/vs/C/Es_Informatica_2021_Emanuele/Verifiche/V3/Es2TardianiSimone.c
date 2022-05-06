//Simone Tardiani | 3CIIN | 04/05/22
/*
Scrivere un programma C che generi casualmente 8 valori di tipo 0/1 e costruisca progressivamente ed 
esclusivamente con  operazioni bit a bit, il valore intero che dovrà essere stampato, sia in binario che in decimale.
*/

#include<stdlib.h>
#include<time.h>
#define DIM 8

int main(){
	srand(time(NULL));
	int n,temp,i,j;
	n=0;
	temp=0;

	for(i=0;i<DIM;i++){				//Ciclo per scorrere tutti i bit del numero
		temp=rand()%2+0;			//Selezione random di un bit 0 o 1
		printf("Bit:%d ",temp);
		n=n|(temp<<i);				//Sostituzione del bit nel numero
		printf("/ Numero Decimale:%d ",n);
		printf("/ Numero Binario:");
		
		for(j=0;j<DIM;j++){			//Stampa numero in binario come descritto nell'es 1
			if((n>>(DIM-1-j))&1){
				putchar('1');
			}else{
				putchar('0');
			}
		}
		
		printf("\n\n");
	}

}
