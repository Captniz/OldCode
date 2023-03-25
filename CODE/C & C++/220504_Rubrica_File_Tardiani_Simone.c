/*5. 
Scrivere un programma che permetta di gestire una rubrica telefonica in modo che i dati vengano memorizzati in forma permanente sul file rubrica.dat. 
Offrire all’utente un menu con le opzioni: 
//*inserimento, 
ricerca,
modifica, 
cancellazione e 
visualizzazione 
dell’intera rubrica.
Siete liberi di scegliere la struttura dei dati.

Idea per svolgimento interamente su file: mettere tutte le info del contatto su un unica linea

ID NOME COGNOME NUMERO
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 16
#define ID_DIM 3
#define NUM_DIM 14
//Alla stampa stampo 48 + 2 char (CRLF) = 50 char per ogni contatto


typedef struct Contatto{
    char id[ID_DIM];
    char Nome[DIM];
    char Cognome[DIM];
    char Numero[NUM_DIM];
} cont;

void addContact(cont *c, int *id, FILE *out);
void addContactInStruct(cont *c, int *id);
void zeroOutStruct(cont *c);
void zeroOutTeminators(cont *c);
void addContactInFile(cont *c, FILE *f);
int menu(cont *c, int *id, FILE *out);
void seekConact(FILE*out);
void visAllContacts(cont *c,FILE * out);

int main(){
    cont c;
    int id=1;
    FILE *out=fopen("Output.txt", "r+");

    while(1){
        menu(&c,&id,out);
    }
}
//!FIX
void seekConact(FILE*out){
    int opz,i,flag;
    opz=0;
    i=0;
    flag=1;
    char buf[DIM],str[DIM],trash[80];

    printf("\n\nTipo di dato da cercare:\n1.Nome\n2.Cognome\nOpzione:");
    scanf("%d",&opz);
    fflush(stdin);
    printf("\nStringa da cercare:");
    gets(str);
    fflush(stdin);

    fseek(out,0,SEEK_SET);

    switch(opz){
        case 1:
            fseek(out,ID_DIM,SEEK_CUR);

            do{ 
                buf[i]=fgetc(out);
                while (buf[i]!='~'){
                    i++;
                    buf[i]=fgetc(out);
                }
                buf[i]='\0';                    //ID_DIM è usato per dire la poszione del nome in modo relativo al file
                if (strcmp(buf,str)==0){        //Corretto
                    fgets(trash,80,out);
                    fseek(out,-50,SEEK_CUR);
                    flag=0;
                }else{
                    fgets(trash,80,out);         //Sbagliato
                    fseek(out,ID_DIM,SEEK_CUR);
                    //memset(buf,0,DIM);
                }
            }while(flag && !feof(out));

            printf("%d",ftell(out));
            putchar(fgetc(out));

            break;
        case 2:
            
            break;
        default:
            printf("Opzione non valida");
        break;
    }          
}
//!FIX
int menu(cont *c, int *id, FILE *out){
    int opt=0;

    printf("0.Esci\n1.Aggiungi contatto\n2.Visualizza rubrica\nOpzione:");
    scanf("%d",&opt);
    fflush(stdin);
    switch (opt)
    {
    case 0:
        fclose(out);
        exit (0);
        break;
    case 1:
        addContact(c,id,out);
        break;
    case 2:
        visAllContacts(c,out);
    default:
        break;
    }
} 
void addContact(cont *c, int *id, FILE *out){
    fseek(out,0,SEEK_END);
    zeroOutStruct(c);
    addContactInStruct(c, id);
    addContactInFile(c, out);
    zeroOutStruct(c);
}
void addContactInStruct(cont *c, int *id){
    //ID + 0 + NOME + 0 + COGNOME + 0 + NUMERO
    //Lunghezze fissate in modo da essere facilmente leggibili
    itoa(*id, c->id, 10);
    *id=*id+1;

    printf("Nome (Fino a %d char): ", (DIM-1));
    gets(c->Nome);
    fflush(stdin);
    printf("\nCognome (Fino a %d char): ", (DIM-1));
    gets(c->Cognome);
    fflush(stdin);
    printf("\nNumero (Fino a %d char, Es. \"39 3924722478\"): ", (NUM_DIM-1));
    gets(c->Numero);
    fflush(stdin);
    zeroOutTeminators(c);

    printf("\nContatto aggiunto\n");
}
void zeroOutStruct(cont *c){
    memset(c->id, '~', ID_DIM);
    memset(c->Nome, '~', DIM);
    memset(c->Cognome, '~', DIM);
    memset(c->Numero, '~', NUM_DIM);
}
void zeroOutTeminators(cont *c){
    int i=0;
    for ( i = 0; i < ID_DIM; i++){
        if (c->id[i]== '\0' || c->id[i]== '\n'){
            c->id[i]='~';
        }
    }   
    for ( i = 0; i < DIM; i++ ){
        if ( c->Nome[i] == '\0' || c->Nome[i]== '\n'){
            c->Nome[i] = '~';
        }
    }
    for ( i = 0; i < DIM; i++ ){
        if ( c->Cognome[i] == '\0' || c->Cognome[i]== '\n'){
            c->Cognome[i] = '~';
        }
    }
    for ( i = 0; i < NUM_DIM; i++ ){
        if ( c->Numero[i] == '\0' || c->Numero[i]== '\n'){
            c->Numero[i] = '~';
        }
    }
}
void addContactInFile(cont *c, FILE *f){
    int i=0;
    for ( i = 0; i < ID_DIM; i++){
        fputc(c->id[i], f);
    }
    for ( i = 0; i < DIM; i++){
        fputc(c->Nome[i], f);
    }
    for ( i = 0; i < DIM; i++){
        fputc(c->Cognome[i], f);
    }
    for ( i = 0; i < (NUM_DIM-1); i++){
        fputc(c->Numero[i], f);
    }
    fputc('\n', f);
}
void visAllContacts(cont *c,FILE * out){
    char trash[80];
    int i=0;

    fseek(out,0,0);

    while(!feof(out)){
        for ( i = 0; i < ID_DIM; i++){
            c->id[i]=fgetc(out);
        }

        for ( i = 0; i < DIM; i++){
            c->Nome[i]=fgetc(out);
        }
        c->Nome[i]='\0';

        for ( i = 0; i < DIM; i++){
            c->Cognome[i]=fgetc(out);
        }
        c->Cognome[i]='\0';

        for ( i = 0; i < NUM_DIM; i++){
            fgets(c->Numero,NUM_DIM,out);
        }
        c->Numero[i]='\0';

        fgets(trash,80,out);
        
        putchar('\n');
        putchar('\n');
        puts(c->id);
        putchar('\n');
        puts(c->Nome);
        putchar('\n');
        puts(c->Cognome);
        putchar('\n');
        puts(c->Numero);

    }
}