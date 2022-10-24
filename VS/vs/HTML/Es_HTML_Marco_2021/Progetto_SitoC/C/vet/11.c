/*21> Caricare un vettore v di DIM=20 con i primi DIM numeri della successione di FIBONACCI.
Visualizzare un vettore v.
1 1 3 5 8 13 21 34 55 ...*/
#include<stdio.h>
#define DIM 20
int main()
{
	int v[DIM],i;
	v[0]=v[1]=1;
	for(i=2;i<DIM;i++){
		v[i]=v[i-2]+v[i-1];
	}
	for(i=0;i<DIM;i++){
		printf("%d\t",v[i]);
	}
	return 0;
}
