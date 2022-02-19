#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 20

void load ( int v[DIM] );
void vis ( int v[DIM] );
void sort ( int v[DIM] );
int count ( int v[DIM] );

int main(){
    int v[DIM];
    srand(time(NULL));

    load(v);
    vis(v);
    putchar('\n');
    sort(v);
    vis(v);
    printf("\n%d",count(v));

    return 0;
}

void load ( int v[DIM] ){
    int i=0;

    for ( i = 0; i < DIM; i++){
        v[i]=rand()%9+1;
    }
}

void vis ( int v[DIM] ){
    int i=0;

    for ( i = 0; i < DIM; i++){
        printf("%2d",v[i]);
    }
}

void sort ( int v[DIM] ){
    int i,j,imin,temp;

	for(i=0;i<(DIM-1);i++){
		imin=i;
		for(j=i+1;j<DIM;j++){
			if(v[imin]>v[j]){
				imin=j;
			}
		}
		if(i!=imin){
            temp=v[i];
            v[i]=v[imin];
            v[imin]=temp;
		}
	}
}

int count ( int v[DIM] ){
    
    int i,c,maxc,maxctr,ctr;
    i = 0;
    c = v[0]; 
    maxc = 0;
    ctr = 0;
    maxctr = 0;

    for ( i = 0; i < DIM-1; i++){
        ctr++;
        if (v[i]!=v[i+1]){
            if(ctr>maxctr){
                maxctr=ctr;
                maxc=v[i];
                ctr=0;
            }
        }
    }
    return maxc;
}