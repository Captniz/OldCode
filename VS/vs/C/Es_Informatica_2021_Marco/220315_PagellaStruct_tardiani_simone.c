#include<stdio.h>
#include<string.h>
#define DIM 15
#define CLASSE 2

struct Alunno{
    char Cognome[DIM];
    char Nome[DIM];
    int VotoInfo;
    int VotoCondotta;
};
typedef struct Alunno Alunno;

void Reload();
int Menu();
void clear();

void CaricaSingolo(Alunno Studenti[CLASSE], int Indice);
void CaricaClasse(Alunno Studenti[CLASSE]);
void CambiaCondotta(Alunno Studenti[CLASSE], char Nome[DIM]);
void ModificaInformatica(Alunno Studenti[CLASSE], int Segno);
void VisClasse(Alunno Studenti[CLASSE]);
void VisAlunno(Alunno Studenti[CLASSE], int Indice);

int main(){
    Alunno Studenti[CLASSE];
    int Indx=0;
    char Nome[DIM];
    while(1){
        switch (Menu()){
            case 1:
                printf("\n---------------------------------\nIndice alunno:");
                scanf("%d",&Indx);
                fflush(stdin);
                CaricaSingolo(Studenti,Indx);
                Reload();
                break;

            case 2:
                CaricaClasse(Studenti);
                Reload();
                break;

            case 3:
                printf("\n---------------------------------\nNome alunno:");
                gets(Nome);
                fflush(stdin);
                CambiaCondotta(Studenti,Nome);
                Reload();
                break;

            case 4:
                printf("\n---------------------------------\nValore punto (+1 / -1):");
                scanf("%d",&Indx);
                fflush(stdin);
                ModificaInformatica(Studenti,Indx);
                Reload();
                break;

            case 5:
                VisClasse(Studenti);
                Reload();
                break;
            case 6:
                printf("\n---------------------------------\nIndice alunno:");
                scanf("%d",&Indx);
                fflush(stdin);
                VisAlunno(Studenti,Indx);
                Reload();
                break;

            case 0:
                return 0;
                break;

            default:
                ("\n---------------------------------\nOpzione non esistente");
                Reload();
                break;
        }
    }
    return 0;
}

void clear(){
    int i=0;

    for ( i = 0; i < 50; i++){
        putchar('\n');
    }
    
}

int Menu(){
    int Opz;
    Opz=0;

    clear();    
    
    printf("1) Carica singolo alunno\n2) Carica tutta la classe\n3) Modifica voto di condotta attraverso il nome\n4) Incrementa o decrementa voto informatica della classe (Un punto)\n5) Visualizza classe\n6) Visualizza alunno\n0) Esci\nScelta:");
    scanf("%d",&Opz);
    fflush(stdin);

    return Opz;
}

void Reload(){
    printf("\n\nEnter per ricaricare menu");
    getchar();
    fflush(stdin);
    printf("\n\n");
}

void CaricaClasse(Alunno Studenti[CLASSE]){
    int i=0;

    for ( i = 0; i < CLASSE; i++){
        printf("\n---------------------------------\n");
        printf("Nome Studente %d:",i);
        gets(Studenti[i].Nome);
        fflush(stdin);
        printf("\nCognome Studente %d:",i);
        gets(Studenti[i].Cognome);
        fflush(stdin);
        printf("\nVoto informatica Studente %d:",i);
        scanf("%d",&Studenti[i].VotoInfo);
        fflush(stdin);
        printf("\nVoto condotta Studente %d:",i);
        scanf("%d",&Studenti[i].VotoCondotta);
        fflush(stdin);
    }
}

void CaricaSingolo(Alunno Studenti[CLASSE], int Indice){
    if((Indice<CLASSE) && (Indice>=0)){
        printf("\n---------------------------------\n");
        printf("Nome Studente:");
        gets(Studenti[Indice].Nome);
        fflush(stdin);
        printf("\nCognome Studente:");
        gets(Studenti[Indice].Cognome);
        fflush(stdin);
        printf("\nVoto informatica Studente:");
        scanf("%d",&Studenti[Indice].VotoInfo);
        fflush(stdin);
        printf("\nVoto condotta Studente:");
        scanf("%d",&Studenti[Indice].VotoCondotta);
        fflush(stdin);
    }else{
        printf("Indice errato");
    }
    
}

void CambiaCondotta(Alunno Studenti[CLASSE], char Nome[DIM]){
    int i,flag;
    flag=1;
    i=0;

    for ( i = 0; i < CLASSE; i++){
        if (strcmp(Nome, Studenti[i].Nome) == 0){
            printf("\n---------------------------------\n");
            printf("\nVoto condotta Studente:");
            scanf("%d",&Studenti[i].VotoCondotta); 
            fflush(stdin);  
            flag=0;
        }   
    }
    if (flag){
        printf("Nome non trovato");
    }
    
}

void ModificaInformatica(Alunno Studenti[CLASSE], int Segno){
    int i,flag;
    i=0;
    flag=1;

    if (Segno != -1 && Segno != +1){
        printf("\n---------------------------------\n");
        printf("Segno errato");
    }else{
        for ( i = 0; i < CLASSE; i++){
            if (Segno < 0){
                if(Studenti[i].VotoInfo <= 1){
                    flag = 0;
                }
            }else{
                if(Studenti[i].VotoInfo == 10){
                    flag = 0;
                }
            }
        }

        if(flag){
            for ( i = 0; i < CLASSE; i++){
                Studenti[i].VotoInfo = Studenti[i].VotoInfo + Segno;
            } 
        }else{
            printf("\n---------------------------------\n");
            printf("Non tutti i voti possono essere modificati");
        }
    }    
}

void VisClasse(Alunno Studenti[CLASSE]){
    int i=0;

    for ( i = 0; i < CLASSE; i++){
        printf("\n---------------------------------\n");
        printf("Nome Studente %d: %s",i,Studenti[i].Nome);
        printf("\nCognome Studente %d: %s",i,Studenti[i].Cognome);
        printf("\nVoto informatica Studente %d: %d",i,Studenti[i].VotoInfo);
        printf("\nVoto condotta Studente %d: %d",i,Studenti[i].VotoCondotta);
    }
    
}

void VisAlunno(Alunno Studenti[CLASSE], int Indice){
    int i=0;

    if((Indice<CLASSE) && (Indice>=0)){
        printf("\n---------------------------------\n");
        printf("Nome Studente %d: %s",Indice,Studenti[Indice].Nome);
        printf("\nCognome Studente %d: %s",Indice,Studenti[Indice].Cognome);
        printf("\nVoto informatica Studente %d: %d",Indice,Studenti[Indice].VotoInfo);
        printf("\nVoto condotta Studente %d: %d",Indice,Studenti[Indice].VotoCondotta);
    }else{
        printf("Indice errato");
    }
}