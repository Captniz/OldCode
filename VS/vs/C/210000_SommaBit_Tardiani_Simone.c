#include<stdio.h>
#include<stdlib.h>
#define DIM 8

int main(){
    
    int i,n1,n2,sum;
    i=0;
    n1=0;
    n2=0;
    sum=0;

    do{
        printf("N1:");
        scanf("%d",&n1);
    }while(n1>255 || n1<0);

    do{
        printf("N2:");
        scanf("%d",&n2);
    }while(n2>255 || n2<0);

    for ( i = 0; i < DIM; i++){
        if( ((n1>>i)&1) ^ ((n2>>i)&1) ^ ((sum>>i)&1) ){
            sum=sum|(1<<i);
        }else if( ((n1>>i)&1) || ((n2>>i)&1) || ((sum>>i)&1) ){
            sum=sum|(1<<(i+1));
        }
    }

    for ( i = 0; i < (DIM+1); i++){
        if (sum>>(DIM-i) & 1){
            printf("1");
        }else{
            printf("0");
        }
    }

    return 0;
}
