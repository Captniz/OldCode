//tardiani_simone
//da un vettore letto in input trovare la sequenza piu grande
#include<stdio.h>
#define DIM 10

int main(){
	
	int  ctr_max,i,ctr,v[DIM];
	i=0;
	ctr=1;
	ctr_max=0;
	
	//!HO DATO PER SCONTATO CHE SE NON � PRESENTE UNA SEQ. DI ALMENO DUE NUMERI 
	//SIA SEMPRE PRESENTE UNA SEQUENZA PARI AD UNO, CONSIDERANDO IL SINGOLO NUMERO COME SEQUENZA.
	
	//input vettore
	for(i=0;i<DIM;i++){
		printf("Numero %d:",i+1);
		scanf("%d",&v[i]);
		while(getchar()!='\n');
	}

	//input calcolo sequenza piu lunga
	for(i=1;i<DIM;i++){
		
		//se il valore � maggiore del precedente allora aumenta il counter...
		if(v[i]>v[i-1]){
			ctr++;
			
			//...altrimenti controlla se la sequenza ottenuta fin ora � la maggiore
		}else{
			if(ctr>ctr_max){
				ctr_max=ctr;
			}
			ctr=1;
		}
	}
	
	//ultimo controllo per non escludere le sequenze che arrivano fino alla fine del vettore
	if(ctr>ctr_max){
		ctr_max=ctr;
	}

	printf("\n La sequenza piu' lunga e' di %d numeri",ctr_max);
}
