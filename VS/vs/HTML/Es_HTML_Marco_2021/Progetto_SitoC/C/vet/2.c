/*8> caricare un vettore v con DIM=10 con numeri random a piacere
-visualizzare il vettore
-scambiare il max col min
-visualizzare nuovamente il vettore*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
int main()
{
	int v[DIM],i,max,min,contamax,contamin;
	srand(time(NULL));
	for(i=0;i<DIM;i++){
		v[i]=rand()%20+1;
	}
	for(i=0;i<DIM;i++){
		printf("%d ",v[i]);
	}
	max=v[0];
	min=v[0];
	for(i=1;i<DIM;i++){
		if(v[i]>max){
			max=v[i];
			contamax=i;	
		}
		if(v[i]<min){
			min=v[i];
			contamin=i;
		}
	}
	v[contamax]=min;
	v[contamin]=max;
	printf("\n");
	for(i=0;i<DIM;i++){
		printf("%d ",v[i]);
	}
	return 0;
}
