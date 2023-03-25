/*
Gets stringa di max 80 separata da '-',a ogni trattino vai a capo usando strtok
*/
#include<stdio.h>
#include<string.h>

int main(){
    
    int i=0;
    char s[80];

    printf("Parola:\n");
    gets(s);

    for( i = 0; s[i] != '\0'; i++){
        if (s[i]!='-'){
            putchar(s[i]);
        }else{
            putchar('\n');
        }
    }
    return 0;
}
