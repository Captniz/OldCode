#include<stdio.h>
#include<string.h>
#define DIM 80

void MyStrcpy(char s1[DIM], char s2[DIM]);

int main(){
    
    char s1[80]={"ciao1"};
    char s2[80]={"ciao2"};
    char s3[80]={"ciao3"};
    MyStrcpy(s3,s1);
    puts(s3);
    putchar('\n');
    strcpy(s3,s2);
    puts(s3);
    return 0;
}

void MyStrcpy(char s1[DIM], char s2[DIM]) {

    int i;
    i=0;

    for ( i = 0; s2[i] != '\0'; i++){
        s1[i]=s2[i];
    }
    s1[i]='\0';

}