//220108_056_tardiani_simone.c
/*ordina-stringhe  - Scrivere un programma che ordini in modo crescente e con un algoritmo in-place un array di
DIM stringhe inserite esternmente, visualizzando il risultato dell'ordinamento sullo schermo. Si assuma che ogni stringa abbia una lunghezza L non superiore a 80 caratteri.*/
#include<stdio.h>
#include<string.h>

#define DIM 5
#define LEN 80

void InputStringhe(char ms[DIM][LEN]);
void VisualizzaStringhe(char ms[DIM][LEN]);
void OrdinaStringhe(char ms[DIM][LEN]);

int main(){
    
    char ms[DIM][LEN];
    int i,j;
    j=0;
    i=0;

    InputStringhe(ms);
    OrdinaStringhe(ms);
    VisualizzaStringhe(ms);

    return 0;
}

void InputStringhe(char ms[DIM][LEN]){

    int i=0;

    for ( i = 0; i < DIM; i++){
        printf("Stringa %d:",i+1);
        gets(ms[i]);
    }
}

void VisualizzaStringhe(char ms[DIM][LEN]){

    int i=0;

    printf("\n");
    for ( i = 0; i < DIM; i++){
        printf("Stringa %d:%s\n",i+1,ms[i]);
    }
}

void OrdinaStringhe(char ms[DIM][LEN]){

    char box[LEN];
    int i,j;
    j=0;
    i=0;

    for ( i = 0; i < DIM-1; i++){
        for ( j = i+1; j < DIM; j++){
            if (strcmp(ms[i],ms[j])>0){
                strcpy(box,ms[i]);
                strcpy(ms[i],ms[j]);
                strcpy(ms[j],box);
            }
        }
    }  
    //-1 se 1 < 2
    //+1 se 2 < 1
}