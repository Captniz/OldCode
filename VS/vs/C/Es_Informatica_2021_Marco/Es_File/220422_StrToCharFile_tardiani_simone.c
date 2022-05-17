#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 4

typedef char bool;

void InputVar(char s[DIM], char *c);                                                //input stringa e carattere
int ArrCompare(char Str[DIM], char Buf[DIM]);                                       //Comparo la stringa nel buffer e quella da sostituire: 1=stringa non trovata, 0=stringa trovata
void Substitute(char Str[DIM], char Buf[DIM],char *c,FILE *in,FILE *out);           //Modifco il file: str=stringa da sostituire, buf=buffer, c=carattere da stampare, in=file in, out=file out
int Check(FILE *in,FILE *out);                                                      //Controllo aperture file

int main(){   
    FILE* in = fopen("Input.txt", "r");     //apertura file in lettura
    FILE* out = fopen("Output.txt", "w");   //apertura file in scrittura
    char Buf[DIM];                          //buffer
    char Str[DIM];                          //stringa da sostituire
    char c;                                 //carattere da stampare

    InputVar(Str,&c);                       //Input stringa e carattere
    Check(in,out);                          //Controllo aperture file

    Substitute(Str,Buf,&c,in,out);          //Modifco il file attraverso il buffer
    
    printf("FINE");                         //Fine programma
    fclose(in);
    fclose(out);

    return 0;
}

int ArrCompare(char Str[DIM], char Buf[DIM]){
    int i=0;

    for ( i = 0; i < DIM; i++ ){
        if ( Str[i] != Buf[i] ){
            return 1;                                   //stringa non trovata
        }
    }
    return 0;                                           //stringa trovata
}
void InputVar(char s[DIM], char *c){
    printf("Stringa da trovare (4 char):");                     //input stringa 
    gets(s);
    fflush(stdin);

    printf("\nChar da sostituire:");                            //input char 
    *c=getchar();
    fflush(stdin);
}
void Substitute(char Str[DIM], char Buf[DIM],char *c,FILE *in,FILE *out){
    int ctr=0;
    bool PrecFound=0;

    do{
        ctr=fread(Buf, sizeof(char), DIM, in);          //leggo il buffer

        if (ArrCompare(Str, Buf)){                      //se la NON stringa è presente nel buffer   
            if (PrecFound){                             //se la stringa precedente è stata trovata
                fputc(Buf[1], out); 
                fputc(Buf[2], out); 
                fputc(Buf[3], out); 
                PrecFound=0;                            //resetto il flag
            }
            fseek(in, (1-DIM), SEEK_CUR);               //mi sposto indietro di 3 caratteri
            fputc(Buf[0], out);                         //stampo il primo carattere del buffer
        }else{                                          //se la stringa è presente nel buffer
            fputc(*c, out);                              //stampo il char
            fseek(in, -1, SEEK_CUR);                    //mi sposto indietro di 1 carattere
            PrecFound=1;                                //setto il flag
        }
    }while(ctr==DIM);
}
int Check(FILE *in,FILE *out){
    if(in == NULL){
        printf("Errore apertura file in\n");
        return 0;
    }
    if(out == NULL){
        printf("Errore apertura file out\n");
        return 0;
    }
    return 1;
}