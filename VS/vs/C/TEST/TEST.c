#include<stdio.h>
#include<stdlib.h>
#define DIM 10

int main(){
    
    int n,i;
    n=0;
    i=0;

    do{
    printf("n:");
    scanf("%d",&n);
    }while(n<=10);

    int v[n];

    for ( i = 0; i < n; i++){
        v[i]=i;
        printf("%d",v[i]);
    }    

    return 0;
}