/*19> Caricare un vettore v di DIM=10 con numeri random [1..100].
Inserire esternamente un numero N > 0 (data entry).
Contare quante volte occorre N nel vettore.
Visualizzare N.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
int main()
{
	int v[DIM],i,num,c;
	srand(time(NULL));
	for(i=0;i<DIM;i++){
		v[i]=rand()%100+1;
		printf("%d ",v[i]);
	}
	putchar('\n');
	do{
		printf("Numero: ");
		scanf("%d",&num);
		fflush(stdin);
	}while(num<=0);
	c=0;
	for(i=0;i<DIM;i++){
		if(num==v[i]){
			c++;
		}
	}
	printf("Il numero compare %d volte",c);
	return 0;
}
