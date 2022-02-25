#include<stdio.h>
#include<stdlib.h>
#define DIM 10

int main(){
    char v[DIM]={'a','b','a','b','a','b','a','b','a','b'},*ar;
    int n,i;
    n=0;
    i=0;

    do{
    printf("Size:");
    scanf("%d",&n);
    fflush(stdin);
    }while(n<=10);

    ar = malloc(n * sizeof(char));

    for ( i = 0; i < n; i++){
        ar[i]='0';
    }
    
    for ( i = 0; i < DIM; i++){
        ar[i]=v[i];
    }
    
    for ( i = 0; i < n; i++){
        printf("%3c",ar[i]);
    }
    
    return 0;
}
