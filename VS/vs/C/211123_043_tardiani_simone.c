#include<stdio.h>
#include<string.h>
#define DIM 80

int main(){

    char s[DIM];
    int i,ctr;
    i=0;
    ctr=0; 

    for ( i = 0; s[i]!= '\0'; i++){
        if (s[i] >= 48 && s[i] <= 57){
            ctr++;
        }
    }
    
    printf("Ci sono %d cifre",ctr);

    return 0;
}

