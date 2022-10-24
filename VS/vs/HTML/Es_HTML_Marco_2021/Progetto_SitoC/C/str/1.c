/*22> Scrivere un programma che, letti gli elementi di due vettori v e v2 di lunghezza 5, determini il vettore w di lunghezza 10 ottenuto “appendendo” gli elementi di v2 a v. 
Visualizzare v, v2 e w.

Es: se v1 e v2 sono i vettori di caratteri
v 	PROVA
v2 	ESAME
w	PROVAESAME*/
#include<stdio.h>
#define DIM 5
int main()
{
	char v1[]={'P','R','O','V','A'}, v2[]={'E','S','A','M','E'},w[DIM*2];
	int i;
	// visualizzo primo vettore
	for(i=0;i<DIM;i++){
		printf("%c",v1[i]);
	}
	putchar('\n');
	//visualizza secondo vettore
	for(i=0;i<DIM;i++){
		printf("%c",v2[i]);
	}
	putchar('\n');
	//unione di v1 e v2
	for(i=0;i<DIM;i++){
		w[i]=v1[i];
	}
	for(i=DIM;i<DIM*2;i++){
		w[i]=v2[i-DIM];
	}
	//visualizza vettore w
	for(i=0;i<DIM*2;i++){
		printf("%c",w[i]);
	}
	return 0;
}
