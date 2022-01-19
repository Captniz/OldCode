//es3_tardiani_simone.txt

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define DIM 10

int main(){
	int m[DIM][DIM],j,i,diagDes,diagSin;
	i=0;
	j=0;
	diagSin=0;
	diagDes=DIM-1;
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
		m[i][diagDes]=0;
		m[i][diagSin]=0;
		diagDes--;
		diagSin++;
	}	
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("%3d",m[i][j]);
		}
		putchar('\n');
	}
	return 0;
}