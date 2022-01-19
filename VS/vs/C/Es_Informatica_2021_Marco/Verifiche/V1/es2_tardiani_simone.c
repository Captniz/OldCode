//es2_tardiani_simone.txt

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DIM 10

int main(){
	int v[DIM],v2[DIM],i;
	i=0;
	srand(time(NULL));	

	for(i=0;i<DIM;i++){
		v[i]=rand()%21+10;
	}
	for(i=0;i<DIM;i++){
		printf("%4d",v[i]);
	}
	putchar('\n');
	v2[0]=v[0];
	for(i=1;i<DIM;i++){
		v2[i]=v[i]+v2[i-1];
	}
	for(i=0;i<DIM;i++){
		printf("%4d",v2[i]);
	}
	return 0;
}
