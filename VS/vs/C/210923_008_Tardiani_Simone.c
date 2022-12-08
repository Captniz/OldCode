//210923_008_Tardiani_Simone.c
/* 008 - caricare un vettore v con DIM=10 con numeri random a piacere
-visualizzare il vettore
-scambiare il max col min
-visualizzare nuovamente il vettore */
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#define DIM 10
#define RANDMAX 10
#define RANDMIN 1

int main()
{
    int v[DIM],i,max=RANDMIN,min=RANDMAX;
     srand(time(NULL));

    //Assegnazione
    for(i=0; i<DIM; i++){
        v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
    } 
    //Prima visualizzazione
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);

        if (v[i]<min){
            min=v[i];
        }
        
        if (v[i]>max){
            max=v[i];
        }
    }
    //Seconda visualizzazione
    printf("\n\n");
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        if (v[i]==min){
            printf("%d ",max);
        }else{
            if(v[i]==max){
            printf("%d ",min);
            }else{
            printf("%d ",v[i]);
            }
        }
    }
    return 0;
}