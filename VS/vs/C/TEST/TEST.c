#include<stdio.h>
#define DIM 10

void vis(int []);

int main(){
    int v[DIM]={1,2,3,4,5,6,7,8,9,10};
    vis(v);
    return 0;
}

void vis(int v[DIM]){
    int i=0;

    for ( i = 0; i < DIM; i++){
        printf("%d",v[i]);
    }
}