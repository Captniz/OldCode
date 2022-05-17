#include<stdio.h>
#include<string.h>
#define DIM 80

int MyStrlen(char s1[DIM]);

int main(){

    char s1[DIM];

    MyStrlen(s1);

    printf("%d",MyStrlen(s1));
    return 0;
}

int MyStrlen(char s1[DIM]) {

    int i;
    i=0;

    for ( i = 0; s1[i] != '\0'; i++){
    }    

    return i;
}
