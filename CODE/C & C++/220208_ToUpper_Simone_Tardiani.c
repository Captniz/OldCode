/*
Cambia tutte le lettere in maiuscole
*/
#include<stdio.h>
#include<string.h>

int main(){
    
    int i=0;
    char s[80];

    printf("Parola:\n");
    gets(s);

    for( i = 0; s[i] != '\0'; i++){
        if (s[i]>= 97 && s[i]<= 122){
            s[i]=s[i]-32;
        }
    }

    puts(s);

    return 0;
}
