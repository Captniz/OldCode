//Simone Tardiani | 3CIIN | 04/05/22
/*
Scrivere un programma C che accenda (setti a 1) tutti i bit di posizione pari (0, 2, 4,...) 
di un numero intero n casuale tra 0..255. Stampare tutti passaggi sia in decimale che in binario
*/

#include<stdlib.h>
#include<time.h>
#define DIM 8

int main(){
	srand(time(NULL));
	int n,i,j,mask;
	n=rand()%256+0;
	mask=1;

	printf("\nDecimale originale:%d ",n);
	printf("/ Binario originale:");
	
	for(i=0;i<DIM;i++){			//Visualizzazione numero binario come descritto nell'es 1
		if((n>>(DIM-1-i))&1){	
			putchar('1');
		}else{
			putchar('0');
		}
	}
	
	printf("\n\n");

	for(i=0;i<DIM;i+=2){		//Ciclo che scorre solo i bit pari del numero
		
		n=n|(mask<<i);			//Sostituzione del bit pari con 1
		
		printf("Posizione:%d ", i);
		printf("/ Decimale:%d ",n);
		printf("/ Binario:");
		
		for(j=0;j<DIM;j++){		//Visualizzazione numero binario come descritto nell'es 1
			if((n>>(DIM-1-j))&1){
				putchar('1');
			}else{
				putchar('0');
			}
		}
		printf("\n\n");
	}
}
