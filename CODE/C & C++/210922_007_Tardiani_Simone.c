//210922_007_James_Bond.c
//007 - caricare un vettore v con DIM=10 con numeri compresi tra 50 e 99 (estremi inclusi)
//visualizzare max, min e somma
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RANDMAX 99
#define RANDMIN 50
#define DIM 10

int main()
{
    int v[DIM],i,s,max,min;
    float med;
    i=0;
    s=0;
    max=RANDMIN;
    min=RANDMAX;
    med=0;
    srand(time(NULL));
    //Loading
    for(i=0; i<DIM; i++){
        v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
        s+=v[i];
        if (v[i]>max){
            max=v[i];
        }
        if (v[i]<min){
            min=v[i];
        }
    }
    //Visualizzazione
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);  
    }
    med=s/DIM;
    printf("\nsomma:%d",s);
    printf("\nmax:%d",max);
    printf("\nmin:%d",min);
    printf("\nmedia:%d",med);
}