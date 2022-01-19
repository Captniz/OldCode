//tardiani_simone
//stampare un  triangolo di floyd
#include<stdio.h>

int main(){
	
	int  i,n,ctr,ctr2;
	i=0;
	n=0;
	ctr=0;
	ctr2=1;
	
	//input numero
	do{
		printf("Numero:");
		scanf("%d",&n);
		while(getchar()!='\n');
	}while(n<=0);
	
	//ciclo di stampa
	for(i=1;ctr2<(n+1);i++){
		
		//stampa
		printf("%d ",i);
		
		//aumento counter
		ctr++;
		
		//controllo se si va a capo
		if(ctr==ctr2){
			ctr2++;
			ctr=0;
			printf("\n");
		}
	}
}
