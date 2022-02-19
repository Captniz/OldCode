//220126_tardiani_simone_01.c
#include <stdio.h>
#define DIM 10

int main(){
	int v[DIM]={1,2,5,3,7,4,6,11,35,21},i,j,box;
	i=0;
	j=0;
	box=0;
	char x=' ';
	
	//Ciclo infinito
	while(1){
		
		//Print menu
		printf("Opzioni:\n0 -> uscita\na -> ascendente\nd -> discendente\n");
		x=getchar();
		fflush(stdin);
		
		//Se zero esci
		if(x=='0'){
			return 0;
			
		//Se d discendente
		}else if(x=='d'){
			for(i=0;i<DIM-1;i++){
				for(j=i+1;j<DIM;j++){
					if(v[i]<v[j]){
						box=v[i];
						v[i]=v[j];
						v[j]=box;
					}
				}
			}
			
		//Se a ascendente
		}else if(x=='a'){
			for(i=0;i<DIM-1;i++){
				for(j=i+1;j<DIM;j++){
					if(v[i]>v[j]){
						box=v[i];
						v[i]=v[j];
						v[j]=box;
					}
				}
			}
		}
		
		//Stampa
		putchar('\n');
		for(i=0;i<DIM;i++){
			printf("%3d",v[i]);
		}
		putchar('\n');
	}
}