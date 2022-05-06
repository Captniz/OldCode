/*
5. Scrivere un programma che permetta di gestire una rubrica telefonica in modo che i dati vengano memorizzati in forma permanente sul file rubrica.dat. Offrire all’utente un menu con le opzioni: inserimento, modifica, cancellazione e visualizzazione dell’intera rubrica.
Siete liberi di scegliere la struttura dei dati.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 30

typedef struct Contatto{
    int Id;
    char Nome[DIM];
    char Cognome[DIM];
    char Numero[13];
};

/*Idea per svolgimento interamente su file: mettere tutte le info del contatto su un unica linea

ID NOME COGNOME NUMERO
*/

void seekContact(char cognome[]);
void addContact(int id);

int main(){
    //ID + SPACE + NOME + SPACE + COGNOME + SPACE + NUMERO
    char Data[(3+1+DIM*2+1+1+13)];
    int id=1;


    
}

void addContact(int id){
    char temp[DIM];
    
    fprintf(out, "%",VarAssign);

    printf("\nNome:");
    gets(temp);

    fflush(stdin);

    printf("\nCognome:");

    fflush(stdin);
    printf("\nNumero:");
    
    fflush(stdin);
}