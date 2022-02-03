/*
> dichiarare la seguente struttura:

struct studente {
        char cognome[20];
        char nome[20];
        int voto;
};

> inserire un array di 10 studenti
> visualizzare gli studenti con voto >= 8
> calcolare la media dei voti
> visualizzare lo studente con voto più alto (nel caso di voto più alto uguale visualizzare il primo)*/

#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#define DIM 20
#define DIM2 10

struct studente {
    char cognome[DIM];
    char nome[DIM];
    int voto;
};
typedef struct studente st;

void CaricaVoti(st classe[DIM2]);
void CaricaNomi(st classe[DIM2]);
void VisBuoni(st classe[DIM2]);
int CalcolaMedia(st classe[DIM2]);
int TrovaMigliore(st classe[DIM2]);
void ArVis(st classe[DIM2]);

int main(){
    st classe[DIM2];
    int Max=0;
    srand(time(NULL));

    CaricaVoti(classe);
    CaricaNomi(classe);
    printf("\n\n---\n\n");
    VisBuoni(classe);
    printf("---\n\n");
    printf("Media:%d",CalcolaMedia(classe));
    printf("\n\n---\n\n");
    Max=TrovaMigliore(classe);
    printf("Lo studente migliore e' %s %s con il voto %d",classe[Max].nome,classe[Max].cognome,classe[Max].voto);
    printf("\n\n---\n\n");
    ArVis(classe);
}

void CaricaVoti(st classe[DIM2]){

    int i=0;

    for ( i = 0; i < DIM2; i++){
        classe[i].voto = rand()%10+1;
    }   
}

void CaricaNomi(st classe[DIM2]){

    int i=0;

    for ( i = 0; i < DIM2; i++){
        printf("\nNome %d:", i+1);
        gets(classe[i].nome);
        fflush(stdin);
        printf("Cognome %d:", i+1);
        gets(classe[i].cognome);
        fflush(stdin);
    } 
}

void VisBuoni(st classe[DIM2]){

    int i=0;

    printf("Studenti Migliori:\n\n");

    for ( i = 0; i < DIM2; i++){
        if (classe[i].voto >= 8){
            puts(classe[i].nome);
            puts(classe[i].cognome);
            printf("%d\n\n",classe[i].voto);
        }
    }
}

int CalcolaMedia(st classe[DIM2]){

    int i=0;
    int media=0;

    for ( i = 0; i < DIM2; i++){
        media=media+classe[i].voto;    
    }
    
    return media/DIM2;
}

int TrovaMigliore(st classe[DIM2]){

    int max=0;
    int i=0;

    for ( i = 1; i < DIM2; i++){
        if (classe[i].voto>classe[max].voto){
            max=i;
        }
    }
    
    return max;
}

void ArVis(st classe[DIM2]){

    int i=0;
    printf("Array di struct completo:\n\n");
    for ( i = 0; i < DIM2; i++){
        printf("%s\n%s\n%d\n\n",classe[i].nome,classe[i].cognome,classe[i].voto);
    }
    
}
