/*29> data una stringa s1, caricare il reverse di s1 in s2.
visualizzare le 2 stringhe.*/
#include<stdio.h>
#include<string.h>
#define DIM 80
void MyStrcpyReverse(char [], char []);
int main(){
    char s1[DIM],s2[DIM]="ciao";
    MyStrcpyReverse(s1,s2);
    puts(s1);
    return 0;
}

void MyStrcpyReverse(char s1[DIM], char s2[DIM]) {
    int i;
    for(i=1;i<=strlen(s2);i++){
        s1[i-1]=s2[strlen(s2)-i];
    }
    s1[strlen(s2)]='\0';
}

