//211013_Classifica_Tardiani_Simone.c
//prendi due array in input e fai la classifica di ciascuno
#include<stdio.h>
#define DIM 10

int main(){
	int v[DIM],index[]={0,1,2,3,4,5,6,7,8,9,10},i,j,temp;
	i=0;
	j=0;
	temp=0;

	//Caricamento v1
	for(i=0;i<DIM;i++){
		printf("numero %d di v1:",i+1);
		scanf("%d",&v[i]);
		fflush(stdin);
	}
	
	//Sorting v1
	for ( i = 0; i < DIM-1; i++){
		j=1+i;
		while (j<DIM){
			if (v[j]>v[i]){
 				temp=index[j];
				index[j]=index[i];
				index[i]=temp; 
			}
			j++;
		}
	}
	//Vis
	for(i=0; (i<sizeof(v)/sizeof(int)); i++){
		printf("%d ",v[i]);
	}
	
	printf("\n");

	return 0;
}