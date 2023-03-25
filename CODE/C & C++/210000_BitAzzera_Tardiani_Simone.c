#include<stdio.h>
#include<stdlib.h>
#define DIM 8

int main(){
    
    int n,i,mask;
    n=0;
    i=0;
    mask=215;

    do{
        printf("N:");
        scanf("%d",&n);
    }while(n>255 || n<0);

    for ( i = 0; i < DIM; i++){
        printf("%d",(n>>DIM-1-i)&1);
    }

    putchar('\n');
    n=n&mask;
    
    for ( i = 0; i < DIM; i++){
        printf("%d",(n>>DIM-1-i)&1);
    }

    return 0;
}
