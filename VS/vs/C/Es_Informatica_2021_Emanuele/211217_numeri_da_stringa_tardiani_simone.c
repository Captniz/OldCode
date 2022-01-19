#include<stdio.h>
#include<string.h>
#define DIM 80

int main(){

    char c[DIM];
    int i,ctr,tot;
    i=0;
    ctr=0;
    tot=0;

    printf("Stringa:");
    gets(c);

    for ( i = 0; c[i] != '\0'; i++){
        if (c[i]>=48 && c[i]<=57 ){
            ctr=(ctr*10)+(c[i]-48);
        }else{
            tot=tot+ctr;
            ctr=0;
        }
    }

    tot=tot+ctr;
    ctr=0;

    printf("%d",tot);

    return 0;
}
