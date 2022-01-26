//220126_tardiani_simone_02.c

#define DIM 10
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//Randomizza array
void random(int v[DIM]);
//Visualizza array
void vis(int v[DIM]);
void insertion(int v[DIM]);
void selection(int v[DIM]);
void merge(int v3[DIM*2],int v1[DIM], int v2[DIM]);
void vis2(int v[DIM*2]);

int main(){
	int v1[DIM],v2[DIM],v3[DIM*2],i;
	srand(time(NULL));

	random(v1);
	random(v2);
	selection(v1);
	vis(v1);
	insertion(v2);
	vis(v2);
	merge(v3,v1,v2);
	vis2(v3);
}
void random(int v[DIM]){
	int i=0;
	
	for(i=0; i<DIM; i++){
		v[i]=rand()%57+31;
	}
}
void vis(int v[DIM]){
	int i=0;
	
	for(i=0;i<DIM;i++){
		printf("%3d",v[i]);
	}
	putchar('\n');
}
void insertion(int v[DIM]){	
	int i,j,min;
	min=0;
	i=0;
	j=0;
	
	for(i=1;i<DIM;i++){
		min=v[i];
		for(j=i-1;(j>=0) && (min<v[j]);j--){
			v[j+1]=v[j];
		}
		v[j+1]=min;
	}
}
void selection(int v[DIM]){
	int min,box,i,j;
	i=0;
	box=0;
	j=0;
	min=0;
	
	for(i=0;i<DIM-1;i++){
		min=i;
		for(j=i+1;j<DIM;j++){
			if(v[min]>v[j]){
				min=j;
			}
		}
		if(min!=i){
			box=v[i];
			v[i]=v[min];
			v[min]=box;
		}
	}
}
void merge(int v3[DIM*2],int v1[DIM], int v2[DIM]){
	
	int ctr1,ctr3,ctr2,i;
	ctr1=0;
	ctr2=0;
	ctr3=0;
	i=0;
	
	//Ciclo fin che uno dei due array non finisce
	while(ctr1!=10 && ctr2!=10){
		
		//Testo primo del primo array con il primo del secondo array, 
		//dopo che ho deciso qual dei due mettere nel array v3 
		//mando avanti il counter della fine dell' array da cui ho preso il numero minore
		if(v1[ctr1]>=v2[ctr2]){
			v3[ctr3]=v2[ctr2];
			ctr3++;
			ctr2++;
		}else if (v1[ctr1]<v2[ctr2]){
			v3[ctr3]=v1[ctr1];
			ctr3++;
			ctr1++;
		}
	}
	
	//Quando uno dei due array è finito controllo qual dei due ha ancora numeri al suo interno e li
	//attacco alla fine dell' array v3
	if(ctr1!=10){
		for(i=0;(ctr3+i)<DIM*2;i++){
			v3[ctr3+i]=v1[ctr1+i];
		}
	}else{
		for(i=0;(ctr3+i)<DIM*2;i++){
			v3[ctr3+i]=v2[ctr2+i];
		}
	}
	
}
void vis2(int v[DIM*2]){
	int i=0;
	
	for(i=0;i<DIM*2;i++){
		printf("%3d",v[i]);
	}
	putchar('\n');
}
