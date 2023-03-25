//211013_Classifica_Tardiani_Simone.c
//prendi due array in input e fai la classifica di ciascuno
#include<stdio.h>
#define DIM 10

int main(){
	int v[DIM],v1[DIM],i,max,j,maxpos;
	i=0;
	j=0;
	max=0;
	
	//Caricamento v1
	for(i=0;i<DIM;i++){
		printf("numero %d di v1:",i+1);
		scanf("%d",&v[i]);
		fflush(stdin);
	}
	//Caricamento v2
	printf("\n");	
	for(i=0;i<DIM;i++){
		printf("numero %d di v2:",i+1);
		scanf("%d",&v1[i]);
	}
	
	//Sorting v1
	printf("\n");
	printf("Classifica voti v1:");
	printf("\n");
	max=v[0];
	for(j=0;j<DIM;j++){
		max=v[0];
		for(i=0;i<DIM;i++){
			if(v[i]>max){
				max=v[i];
				maxpos=i;
			}
		}
		
		printf("%3d",max);
		v[maxpos]=-1;
	}
	
	//Sorting v2
	printf("\n");
	printf("Classifica voti v2:");
	printf("\n");
	max=v1[0];
	for(j=0;j<DIM;j++){
		max=v1[0];
		for(i=0;i<DIM;i++){
			if(v1[i]>max){
				max=v1[i];
				maxpos=i;
			}
		}
		
		printf("%3d",max);
		v1[maxpos]=-1;
	}
	return 0;
}
