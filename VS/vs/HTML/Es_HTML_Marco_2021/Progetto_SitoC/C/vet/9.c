/*18&gt; caricare un vettore v dimensionato 10 con numeri random.
Visualizzare un vettore.
Mettere prima i numeri primi e poi i non primi, senza alterare l'ordine.*/
#include&lt;stdio.h&gt;
#define DIM 10
int main()
{
	int v[DIM],v2[DIM],i,c=0,j=1,k;
	srand(time(NULL));
	for(i=0;i&lt;DIM;i++){
		v[i]=rand()%20+1;
		printf("%d\t",v[i]);
	}
	putchar('\n');
	for(i=0;i&lt;DIM;i++){
		while(j&lt;=v[i]){
			if(v[i]%j==0){
				k=k+1;
			}
			j++;
		}
		if(k&lt;=2){
			v2[c]=v[i];
			c++;
		}
		k=0;
		j=1;
	}
	putchar('\n');
	for(i=0;i&lt;DIM;i++){
		while(j&lt;=v[i]){
			if(v[i]%j==0){
				k=k+1;
			}
			j++;
		}
		if(k&gt;2){
			v2[c]=v[i];
			c++;
		}
		k=0;
		j=1;
	}
	for(c=0;c&lt;DIM;c++){
		printf("%d\t",v2[c]);
	}
	return 0;
}
