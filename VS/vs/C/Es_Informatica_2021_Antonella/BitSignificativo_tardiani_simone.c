#include<stdio.h>
#include<stdlib.h>
#define DIM 8

int main(){
    
    int n,i,flag;
    n=0;
    i=0;
    flag=0;

    do{
        printf("N:");
        scanf("%d",&n);
    }while(n>255 || n<0);

    for ( i = 0; i < DIM; i++){
        printf("%d",(n>>DIM-1-i)&1);
        if (!flag && ((n>>DIM-1-i)&1)==1){
            flag=DIM-1-i;
        }
    }
    
    printf("\nPosizione bit piu' significativo: %d",flag);

    return 0;
}
