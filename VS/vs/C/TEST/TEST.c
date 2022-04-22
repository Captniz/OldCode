#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 4
/*TODO :
idea -> 
//* mettere la stringa sotto esame e il buffer in una struct, 
//* poi leggere il file con buffer = alla lunghezza della stringa esaminata.
comparare le due attraverso la comparazione con le struct,dopo una lettura in cui non viene trovata la stringa mandare il puntatore indietro di 3 e stampare solo il primo char; altrimenti stampare il char, inoltre se si rileva la stringa mandare il puntatore indietro di uno e se non si rileva di nuovo la stringa stampare il buffer meno il primo char.
*/


int main(){
    int i=0;
    char Buf[DIM];
    char Str[DIM]="effe";

    printf("Str (4char):");
    scanf("%s",&Str);

    printf("buf (4char):");
    scanf("%s",&Buf);

    for(i=0; i<DIM; i++){
        printf("%c ",Buf[i]);
    }
    putchar('\n');
    for(i=0; i<DIM; i++){
        printf("%c ",Str[i]);
    }
    printf("FINE");
    return 0;
}
