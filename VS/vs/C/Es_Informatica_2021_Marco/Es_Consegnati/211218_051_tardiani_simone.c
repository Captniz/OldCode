#include<stdio.h>
#define DIM 10

int main()
{
    int v[DIM]={23,11,34,76,99,23,67,83,88,10};
    int i,j,box,c=0,cswap=0;

	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			if(v[i]<v[j]){
				box=v[i];
				v[i]=v[j];
				v[j]=box;
				cswap++;
			}
			c++;
		}
	}

    return 0;
}

//Confronti: 100
//Swap: 22
//Ordina: Si
//Ordine: Crescente