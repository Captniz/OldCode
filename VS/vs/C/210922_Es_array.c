//210922_Es_array.c
//Stampare la somma dei numeri di un array
#include<stdio.h>
#define DIM 10

int main (){
	
 	int v[DIM],i=0,s=0,j=0;
	srand(time(NULL));
		
//loading interno random
/*	for(i=0; i<DIM; i++){
		v[i]=rand()%20+1;
		printf("%d ",v[i]);
		s+=v[i];
	}
	
	printf("\n\n%d ", s); */
	
//loading esterno
/*  	for(i=0; i<DIM; i++){
		printf("Numero %d?:", i+1);
		scanf("%d",&v[i]);
		s+=v[i];
	}

	for (j = 0; j < DIM; j++){
		printf("%d ",v[j]);
	}

	printf("\n\n%d ", s);  */	
	
}
