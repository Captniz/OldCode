#include<stdio.h>
#include<string.h>
#define DIM 80

int cerca (char s1[DIM],char s2[DIM]);

int main(){

    char s1[DIM]="aaaciaoiufai",s2[DIM]="ciao";

    printf("%d",cerca(s1,s2));

    return 0;
}

int cerca (char s1[DIM],char s2[DIM]){

    int i,ctr,start;
    i=0;
    ctr=0;
    start=0;

    for ( i = 0; ((s1[i] != '\0') || (ctr == strlen(s2))); i++){
        if (s1[i] == s2[ctr]){
            ctr++;
        }else{
            ctr=0;
        }
    }

    start=i-ctr;

    if (ctr==strlen(s2)){
        return start;
    }else{
        return 0;
    }
}