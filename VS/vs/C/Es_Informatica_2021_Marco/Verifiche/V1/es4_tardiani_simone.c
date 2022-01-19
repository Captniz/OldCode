//es4_tardiani_simone.txt

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DIM 10

int main(){
	int m[DIM][DIM],v[DIM],j,i,max;
	i=0;
	j=0;
	max=0;
	srand(time(NULL));	

	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			m[i][j]=rand()%90+10;
		}
	}
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("%3d",m[i][j]);
		}
		putchar('\n');
	}
	printf("\n\n");
	for(i=0;i<DIM;i++){
		max=m[0][i];	
		for(j=0;j<DIM;j++){
			if(m[j][i]>max){
				max=m[j][i];
			}	
		}
		v[i]=max;
	}
	for(i=0;i<DIM;i++){
		printf("%3d",v[i]);
	}
	return 0;
}
