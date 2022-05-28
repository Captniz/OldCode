//funzione che legge i valori della matrice da file, il file va aperto e gestito nella funzione.
#include<stdio.h>
#include<stdlib.h>
#define DIM 10

FILE *caricadaFile(int m[DIM][DIM], char filename[DIM]);

int main(){
    FILE*fp;
    char s[DIM];
    int m[DIM][DIM];   

    fp=caricadaFile(m, s);
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