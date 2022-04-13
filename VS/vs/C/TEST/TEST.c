#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 3

int main()
{   
    int v[DIM]={0,1,2},i,temp,j,n;

    printf("N:");
    scanf("%d",&n);

    for(j=0;j<n;j++){
        temp = v[0];
        for ( i = 1; i < DIM; i++){
            v[i-1] = v[i];
        }
        v[--i]=temp;
    }
    //VIS
    for(i=0; i<DIM; i++){
        printf("%d ",v[i]);
    }
}
