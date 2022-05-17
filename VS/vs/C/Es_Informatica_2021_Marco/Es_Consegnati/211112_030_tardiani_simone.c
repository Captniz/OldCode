//211112_030_tardiani_simone.c
/* 30> emulare la funzione:
strcat(s1, s2)   Concatena s2 dopo s1
visualizzare le 2 stringhe. */

#include<stdio.h>
#include<string.h>
#define DIM 80

void MyStrcat(char s1[DIM],char s2[DIM]);

int main(){

    char s1[DIM],s2[DIM];  
    MyStrcat(s1,s2);
    printf("%s",s1);
    return 0;
}

void MyStrcat(char s1[DIM],char s2[DIM]){

    int i,BaseLength;
    i=0;
    BaseLength=strlen(s1);

    for ( i = 0; i < strlen(s2); i++){
        s1[i+BaseLength]=s2[i];
    }
}
