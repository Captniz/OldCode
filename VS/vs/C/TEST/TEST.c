#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//FAttoreiale: 5*4*3*2*1

int fat(int n);

int main(){
    int n=5;

    printf("%d",fat(n));

}

int fat(int n){
    if (n == 1){
        return n;
    }
    return n * fat((n-1));
}
