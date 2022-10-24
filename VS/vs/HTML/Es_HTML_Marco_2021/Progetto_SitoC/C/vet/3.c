/*9> caricare un vettore v con DIM=10 con numeri random a piacere
- inserire un  numero k
- determinare  l'elemento  di v  piu' prossimo a k e la relativa posizione*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
int main()
{
	int v[DIM],i,k,distanza,distmin,distpos,num;
	srand(time(NULL));
	for(i=0;i<DIM;i++){
		v[i]=rand()% 50+1;
		printf("%d ",v[i]);
	}
	printf("\nNumero: ");
	scanf("%d",&k);
	fflush(stdin);
	distmin=v[0]+k;
	for(i=0;i<DIM;i++){
		if(k>v[i]){
			distanza=k-v[i];
		}else{
			distanza=v[i]-k;
		}
		if(distanza<distmin){
			distmin=distanza;
			num=v[i];
			distpos=i;		
		}
	}
	printf("\nElemento piu' prossimo a %d = %d",k,num);
	printf("\nPosizione=%d",distpos);
	return 0;
}
