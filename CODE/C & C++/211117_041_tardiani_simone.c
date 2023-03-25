#include<stdio.h>
#include<string.h>
#define DIM 80

void MyStrcat(char s1[DIM], char s2[DIM]);

int main(){

    char s1[DIM],s2[DIM];

    MyStrcat(s1,s2);

    printf("%s",s1);
    return 0;
}

void MyStrcat(char s1[DIM], char s2[DIM]) {

    int i,BaseLen;
    i=0;
    BaseLen=strlen(s1);

    for ( i = 0; s2[i] != '\0'; i++){
        s1[BaseLen+i] = s2[i];
    }
}
