//Simone Tardiani | 3CIIN | 04/05/22
/*
Scrivere un programma che generi un numero casuale tra 0 e 255,
utilizzando gli operatori bit-a-bit stampi il numero sia in formato binario che in base 16.
*/

#include<stdlib.h>
#include<time.h>
#define DIM 8

int main(){
	srand(time(NULL));
	int n,i,j,temp,pow;
	n=rand()%256+0;
	temp=0;
	pow=1;
	char syb[]="0123456789ABCDEF";

	printf("\nDecimale:%d",n);
	
	printf("\nBinario:");
	for(i=0;i<DIM;i++){			//Visualizzazione numero binario come descritto nell'es 1
		if((n>>(DIM-1-i))&1){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	
	printf("\nEsadecimale:");
	for(i=4;i<DIM;i++){			//Ciclo che scorre gli ultimi 4 bit del numero
		if((n>>i)&1){			//Se il bit è 1 
			temp=temp+pow;		//aggiungi a 'temp' il valore del bit in decimale
		}
		pow=pow*2;				//Aumenta la potenza che rappresenta il valore del bit in decimale
	}
	printf("%c",syb[temp]);		//Stampo associando il valore decimale di temp a un char contenuto nell'array syb (symbols), rappresentanti i simboli della base esadecimale
	pow=1;						//Riporto ai valori normali le variabili
	temp=0;						//
		
	for(i=0;i<(DIM/2);i++){		//Ciclo che scorre i primi 4 bit del numero
		if((n>>i)&1){			//Se il bit è 1
			temp+=pow;			//aggiungi a 'temp' il valore del bit in decimale
		}
		pow=pow*2;				//Aumenta la potenza che rappresenta il valore del bit in decimale
	}
	printf("%c",syb[temp]);		//Stampo associando il valore decimale di temp a un char contenuto nell'array syb (symbols), rappresentanti i simboli della base esadecimale
}
