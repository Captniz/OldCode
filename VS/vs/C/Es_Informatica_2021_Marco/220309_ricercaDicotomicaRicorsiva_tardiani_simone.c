#include<stdio.h>
#include<stdlib.h>
#define DIM 11

int BinSearch(int a[DIM],int n, int start, int end);

int main(){
    int a[DIM]={0,1,2,3,4,5,6,7,8,9,10},n;
    while(1){
    printf("Numero:");
    scanf("%d",&n);
    printf("Posizione numero:%d\n",BinSearch(a,n,0,DIM-1));
    }
    return 0;
}

int BinSearch(int a[DIM],int n, int start, int end){
    int half=((start+end)/2);
    if (a[half] == n){
        return half;
    }
    if (n>a[half]){
        if (half==end){
            return -1;
        }
        return BinSearch(a,n,half+1,end);
    }else{
        if (half==start){
            return -1;
        }
        return BinSearch(a,n,start,half);
    }
}