/*Max di array in mod ricorsiva*/
#include<stdio.h>
#define DIM 5

int trovamax(int a[DIM],int max,int i);

int main(){

    int a[DIM]={1,2,3,4,5};
    printf("%d\n",trovamax(a, a[0], 0));
    

    return 0;
}

int trovamax(int a[DIM], int max,int i){
    
    if (i==DIM){
        return max;
    }else{
        if (a[i]>max){
            max=a[i];
        }
        return trovamax(a,max,(i+1));
    }
}