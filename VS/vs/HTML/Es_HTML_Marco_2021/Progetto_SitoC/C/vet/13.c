/*25&gt; Caricare un vettore v con DIM=10 con numeri random [10..99].
Visualizzare il vettore.
Scambiare gli elementi due a due: primo col secondo etc.
Visualizzare il vettore. 
.......
carica(v)
visualizza(v)
scambia(v)
visualizza(v)
*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
void carica(int []);
void visualizza(int []);
void scambia(int []);
int main()
{
	srand(time(NULL));
	int v[DIM];
	carica(v);
	visualizza(v);
	scambia(v);
	putchar('\n');
	visualizza(v);
	return 0;
}
void carica(int v[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		v[i]=rand()%90+10;
	}
}
void visualizza(int v[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		printf("%d\t",v[i]);
	}
}
void scambia(int v[DIM]){
	int i,temp;
	for(i=1;i&lt;DIM;i=i+2){
		temp=v[i];
		v[i]=v[i-1];
		v[i-1]=temp;		
	}
}
