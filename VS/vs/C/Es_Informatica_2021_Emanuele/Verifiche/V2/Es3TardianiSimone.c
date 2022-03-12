//Tardiani Simone
/*
Il programma prende in input una stringa e restituisce quante volte appare il primo e l'ultimo char.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 51

int main(){
	char s[DIM];
	int i,ctrlast,ctrfirst;
	i=0;
	ctrlast=0;
	ctrfirst=0;
	
	printf("Stringa:");	//Prendo in input la stringa
	gets(s);
	fflush(stdin);
	
	for(i=0;s[i]!='\0';i++){			//Ciclo fino a fine stringa
		if(s[i]==s[0]){					//Se il char è uguale al primo char -> contatore1 + 1
			ctrfirst++;
		}
		if(s[i]==s[(strlen(s)-1)]){		//Se il char è uguale all'ultimo char -> contatore2 + 1
			ctrlast++;
		}
	}
	
	//Stampo il risultato
	printf("\nIl primo carattere e' presente %d volte mentre l'ultimo carattere e' presente %d volte",ctrfirst,ctrlast);
	return 0;
}
