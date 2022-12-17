/*19&gt; Caricare un vettore v di DIM=10 con numeri random [1..100].
Inserire esternamente un numero N &gt; 0 (data entry).
Contare quante volte occorre N nel vettore.
Visualizzare N.*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
int main()
{
	int v[DIM],i,num,c;
	srand(time(NULL));
	for(i=0;i&lt;DIM;i++){
		v[i]=rand()%100+1;
		printf("%d ",v[i]);
	}
	putchar('\n');
	do{
		printf("Numero: ");
		scanf("%d",&num);
		fflush(stdin);
	}while(num&lt;=0);
	c=0;
	for(i=0;i&lt;DIM;i++){
		if(num==v[i]){
			c++;
		}
	}
	printf("Il numero compare %d volte",c);
	return 0;
}
