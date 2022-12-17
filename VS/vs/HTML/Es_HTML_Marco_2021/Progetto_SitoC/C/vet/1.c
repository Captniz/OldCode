/*7&gt; caricare un vettore v con DIM=10 con numeri compresi tra 50 e 99 (estremi inclusi)
visualizzare max, min e somma*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
int main()
{
	int v[DIM],i,s,min,max;
	s=0;
	srand(time(NULL));
	for(i=0;i&lt;DIM;i++)	{
		v[i]=rand()%49+50;
		printf("%d\n",v[i]);	
	}
	max=v[0];
	min=v[0];
	for(i=0;i&lt;DIM;i++){
		if(v[i]&gt;max){
			max=v[i];
		}
		
		if(v[i]&lt;min){
			min=v[i];
		}
		s=s+v[i];
	}
	printf("la somma e': %d\n",s);
	printf("il numero maggiore e': %d\n",max);
	printf("il numero minore e': %d",min);
	return 0;
}
