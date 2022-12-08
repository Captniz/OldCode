//210922_009_Sirico_Davide.c
//009 - caricare un vettore v con DIM=10 con numeri random a piacere
//- inserire un numero k
//- determinare l'elemento di v piu' prossimo a k e la relativa posizione
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10

int main()
{
    int i,v[DIM],k,CloseNum,Distance,MinDistance,CloseNumPosition;
    srand(time(NULL));
    printf("Inserire numero K: ");
    scanf("%d",&k);
    while(getchar()!='\n')
    //Load
    for (i=0;i<DIM;i++){
        v[i]=rand()%100+1;
    }
    //Analisi
    MinDistance=v[0]+k;
    for (i=1;i<DIM;i++){
    	if(k>v[i]){
            Distance=k-v[i];
        } else {
            Distance=v[i]-k;
        }
        if(Distance<MinDistance){
			MinDistance=Distance;
            CloseNum=v[i];
            CloseNumPosition=i;
        }
	}
    //Vis
    for (i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    printf("\nPosizione numero piu' vicino:%d",CloseNumPosition+1);
    printf("\nNumero piu' vicino:%d",CloseNum);
    return 0;
}