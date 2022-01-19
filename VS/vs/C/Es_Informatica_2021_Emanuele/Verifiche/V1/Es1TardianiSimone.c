//tardiani_simone
//prendere in input due vettore di DIM (massa e volume), calcola densit�, se ogni densit� e maggiore della media delle densit�
#include<stdio.h>
#define DIM 10

int main(){
	
	int i, v[DIM], m[DIM];
	float d[DIM];
	float med;
	i=0;
	med=0;
	
	//input volume
	for(i=0;i<DIM;i++){
		printf("Volume %d:",i+1);
		scanf("%d",&v[i]);
		while(getchar()!='\n');
	}
		
	// input massa
	for(i=0;i<DIM;i++){
		printf("Massa %d:",i+1);
		scanf("%d",&m[i]);
		while(getchar()!='\n');
	}
		
	//calcolo somma media e calcolo densita
	for(i=0;i<DIM;i++){
		d[i]=m[i]/v[i];
		med=med+d[i];
	}
	
	//calcolo media finale
	med=med/DIM;
	
	//stampa vettore densita
	printf("\nValori densita':");
	for(i=0;i<DIM;i++){
		printf("%f ",d[i]);
	}
	printf("\n");
	
	//stampa media
	printf("Media:%f",med);
	printf("\n");
	printf("\n");
	
	//stampa media + dens.
	for(i=0;i<DIM;i++){
		if(d[i]>med){
			printf("Densita' %f e' maggiore della media",d[i]);
		}else if(d[i]<med){
			printf("Densita' %f e' minore della media",d[i]);
		}else{
			printf("Densita' %f e' uguale alla media",d[i]);
		}
		
		printf("\n");		
	}
}