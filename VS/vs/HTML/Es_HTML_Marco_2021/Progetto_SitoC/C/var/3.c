/*3> Dati due numeri "m" e "n", visualizzare, contare e sommare i numeri che sono divisori di entrambi.
Esempio con m=20, n=30 
1 2 5 10 conteggio 4, somma 18*/

#include<stdio.h>

int main()
{
	int m,n,div,conteggio,somma;
	conteggio=0;
	somma=0;
	printf("primo numero: ");
	scanf("%d",&m);
	fflush(stdin);
	printf("secondo numero: ");
	scanf("%d",&n);
	fflush(stdin);
	for(div=1;(div<=m) && (div<=n);div++){
		if((m%div==0) && (n%div==0)){
			conteggio=conteggio+1;
			somma=somma+div;
			printf(" %d ",div);
		}
	}
	printf("\nconteggio: %d\n",conteggio);
	printf("somma: %d ",somma);
	return 0;
}
