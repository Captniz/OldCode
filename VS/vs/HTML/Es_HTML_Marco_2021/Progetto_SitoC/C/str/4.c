/*30> emulare la funzione:
strcat(s1, s2)   Concatena s2 dopo s1
visualizzare le 2 stringhe. */
#include<stdio.h>
#include<string.h>
#define DIM 80
void MyStrcat(char [],char []);
int main(){
    char s1[DIM]={'p','r','o','v','a','\0'};
	char s2[DIM]={'e','s','a','m','e','\0'};
    MyStrcat(s1,s2);
    puts(s1);
    return 0;
}
void MyStrcat(char s1[DIM],char s2[DIM]){
    int i,BaseLength;
    BaseLength=strlen(s1);
    for(i=0;i<strlen(s2);i++){
        s1[i+BaseLength]=s2[i];
    }
}
