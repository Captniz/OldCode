//Tardiani Simone
/*
Questo programma prende in input una stringa di massimo 50 char e restituisce la 
lunghezza della stringa e la somma dei valori dell'ASCII dei suoi char.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 51

//Creo il prototipo della funzione
void funz(char s[DIM],int *len, int *sum);

int main(){
	char s[DIM];
	int len,sum;
	len=0;
	sum=0;
	
	printf("Stringa:");	//Prendo in input la stringa
	gets(s);			
	fflush(stdin); 		//Uso fflush al posto di while(getchar()!='\n'); poichè mi dava un errore (loop)
	
	funz(s,&len,&sum);	//Chiamo la funzione
	
	printf("\nLa stinga %s e' lunga %d char di somma %d",s,len,sum);	//Stampo il risultato
	return 0;
}

void funz(char s[DIM],int *len, int *sum){
	int i=0;
	
	for(i=0;s[i]!='\0';i++){	//Ciclo fino a fine stringa
		*sum=*sum+s[i];			//Ogni ciclo sommo il valore dell'ASCII alla variabile SUM
		*len=*len+1;			//Ogni ciclo incremento di 1 la lunghezza della stringa
	}
}
