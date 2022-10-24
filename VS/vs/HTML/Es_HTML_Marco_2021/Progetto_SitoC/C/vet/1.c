/*7> caricare un vettore v con DIM=10 con numeri compresi tra 50 e 99 (estremi inclusi)
visualizzare max, min e somma*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
int main()
{
	int v[DIM],i,s,min,max;
	s=0;
	srand(time(NULL));
	for(i=0;i<DIM;i++)	{
		v[i]=rand()%49+50;
		printf("%d\n",v[i]);	
	}
	max=v[0];
	min=v[0];
	for(i=0;i<DIM;i++){
		if(v[i]>max){
			max=v[i];
		}
		
		if(v[i]<min){
			min=v[i];
		}
		s=s+v[i];
	}
	printf("la somma e': %d\n",s);
	printf("il numero maggiore e': %d\n",max);
	printf("il numero minore e': %d",min);
	return 0;
}
