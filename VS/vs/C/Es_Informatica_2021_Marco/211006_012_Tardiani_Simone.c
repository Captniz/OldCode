//211006_012_Tardiani_Simone.c
//Caricare un vettore v dimensionato 15 con in primi 15 numeri primi.
#define DIM 15
#include<stdio.h>

int main(){
	
	int i=2,j=0,v[DIM],flag=1,c=1;
	
	v[0]=1;
	do{
		flag=1;
		for(j=1;j<=i/2;j++){
				
			if(i%j==0 && j!=1){
				
				flag=0;
			}
		}
					
		if(flag==1){
			v[c]=i;
			c++;
		}
		
		i++;
	}while(c<DIM);

	//VIS
	for(i=0;i<DIM;i++){
		
		printf("%d ",v[i]);
	}
	
}
