// funzione che fa la somma verticale dei valori contenuti nel file. Si restituisca al pgm chiamante la somma di tutta la matrice.
#include<stdio.h>
#include<stdlib.h>
#define DIM 10

int sommaVerticale(int m[DIM][DIM], int somma[DIM]);
FILE *caricadaFile(int m[DIM][DIM], char filename[DIM]);

int main(){
    FILE*fp;
    char s[DIM];
    int m[DIM][DIM];   
    int somma[DIM];
    int somtot=0;

    fp=caricadaFile(m, s);
    somtot=sommaVerticale(m,somma);

}

FILE *caricadaFile(int m[DIM][DIM], char filename[DIM]){
    int i,j;
    j=0;
    i=0;

    printf("Nfile:");
    gets(filename); 
    FILE*fp=fopen(filename,"r");

    for ( i = 0; i < DIM; i++){
        for ( j = 0; j < DIM; j++){
            fscanf(fp,"%d",&m[i][j]);
        } 
    }
    fclose(fp);
    return fp;
}

int sommaVerticale(int m[DIM][DIM], int somma[DIM]){
    int i,j,som;
    j=0;
    i=0;
    som=0;

    for ( i = 0; i < DIM; i++){
        somma[i]=0;
    }

    for ( i = 0; i < DIM; i++){
        for ( j = 0; j < DIM; j++){
            somma[i]=somma[i]+m[j][i];
        } 
    }
    
    for ( i = 0; i < DIM; i++){
        som=som+somma[i];
    }
    
    return som;
}