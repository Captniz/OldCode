//211112_031_tardiani_simone.c
/*31> emulare la funzione:
strlen(s)     Resituisce la lunghezza di s
--------------
l=lunghezza(s) */


#include<stdio.h>
#include<string.h>
#define DIM 80

int MyStrlen(char s1[DIM]);

int main()
{
    char s1[DIM];  

    printf("%d",MyStrlen(s1));
    return 0;
}

int MyStrlen(char s1[DIM]) {

    int i;
    i=0;


    for(i=0; 1; i++){
        if(s1[i]=='\0'){
            return i;
        }
    }
}
