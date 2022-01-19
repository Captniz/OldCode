//210928_010_Tardiani_Simone.c
//010 - caricare un vettore let con DIM=10 con lettere maiuscole (HELP: dichiarare quindi  char let[DIM])
//- visualizzare il numero complessivo delle vocali presenti nel vettore.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RANDMIN 65
#define RANDMAX 90
#define DIM 10

int main()
{
    int let[DIM],i,voc;
    i=0;
    voc=0;
    srand(time(NULL));
    //Load
    for(i=0; i<DIM; i++){
        let[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
        if(let[i]==65 || let[i]==69 || let[i]==49 || let[i]==79 || let[i]==85){
            voc++;
        }
    }
    //vis
    for(i=0; (i<sizeof(let)/sizeof(int)); i++){
        printf("%c ",let[i]);
    }
    printf("\n");
    printf("Le vocali sono %d",voc);
    return 0;
    
}
