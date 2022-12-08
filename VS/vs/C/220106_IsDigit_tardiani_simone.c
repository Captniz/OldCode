//220106_IsDigit_tardiani_simone.c
//Scrivi una funzione C isdigit che, dato un carattere car restituisca 1 se è una cifra, 0 se non lo è. 
//Scrivi un main di prova che provi la funzione

#include<stdio.h>

int IsDigit (char car);

int main(){
    
    char car=' ';

    printf("Carattere:");
    car = getchar();

    printf("%d",IsDigit(car));

    return 0;
}

int IsDigit (char car){

    if (car >= 48 && car <= 57){
        return 1;
    }else{
        return 0;
    }
}