//211112_028_tardiani_simone.c
/*28> Emulare la funzione:
strcpy(s1, s2)   Copia s2 in s1
visualizzare le 2 stringhe.*/

#include<stdio.h>
#include<string.h>
#define DIM 80

void MyStrcpy(char s1[DIM], char s2[DIM]);

int main(){
    char s1[DIM],s2[DIM]="ciao";

    MyStrcpy(s1,s2);
    puts(s1);
    return 0;
}

void MyStrcpy(char s1[DIM], char s2[DIM]) {

    int i;
    i=0;

    for ( i = 0; i < strlen(s2)+1; i++){
        s1[i]=s2[i];
    }
}
