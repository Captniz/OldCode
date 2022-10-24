/*18> caricare un vettore v dimensionato 10 con numeri random.
Visualizzare un vettore.
Mettere prima i numeri primi e poi i non primi, senza alterare l'ordine.*/
#include<stdio.h>
#define DIM 10
int main()
{
	int v[DIM],v2[DIM],i,c=0,j=1,k;
	srand(time(NULL));
	for(i=0;i<DIM;i++){
		v[i]=rand()%20+1;
		printf("%d\t",v[i]);
	}
	putchar('\n');
	for(i=0;i<DIM;i++){
		while(j<=v[i]){
			if(v[i]%j==0){
				k=k+1;
			}
			j++;
		}
		if(k<=2){
			v2[c]=v[i];
			c++;
		}
		k=0;
		j=1;
	}
	putchar('\n');
	for(i=0;i<DIM;i++){
		while(j<=v[i]){
			if(v[i]%j==0){
				k=k+1;
			}
			j++;
		}
		if(k>2){
			v2[c]=v[i];
			c++;
		}
		k=0;
		j=1;
	}
	for(c=0;c<DIM;c++){
		printf("%d\t",v2[c]);
	}
	return 0;
}
