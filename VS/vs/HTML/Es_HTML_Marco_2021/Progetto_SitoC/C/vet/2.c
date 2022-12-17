/*8&gt; caricare un vettore v con DIM=10 con numeri random a piacere
-visualizzare il vettore
-scambiare il max col min
-visualizzare nuovamente il vettore*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
int main()
{
	int v[DIM],i,max,min,contamax,contamin;
	srand(time(NULL));
	for(i=0;i&lt;DIM;i++){
		v[i]=rand()%20+1;
	}
	for(i=0;i&lt;DIM;i++){
		printf("%d ",v[i]);
	}
	max=v[0];
	min=v[0];
	for(i=1;i&lt;DIM;i++){
		if(v[i]&gt;max){
			max=v[i];
			contamax=i;	
		}
		if(v[i]&lt;min){
			min=v[i];
			contamin=i;
		}
	}
	v[contamax]=min;
	v[contamin]=max;
	printf("\n");
	for(i=0;i&lt;DIM;i++){
		printf("%d ",v[i]);
	}
	return 0;
}
