//211006_Array_Random_Tardiani_Simone.c
/*Creare un vettore di 100 elementi che contenga numero random tra -50 e 50, stamparlo e 
creare un altro vettore che contenga il conteggio delle ripetizioni di ogni numero estratto.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 50
#define RANDMAX 50
#define RANDMIN -50

int main()
{
    int v[DIM],v1[DIM],i,c,cNum,j;
    i=0;
    j=0;
    c=0;
    cNum=0;
    srand(time(NULL));

    //CARICAMENTO vettore 1
    for(i=0; i<DIM; i++){
        v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
    }
    //VIS vettore 1
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);
    }
    //VIS ripetizioni numeri
    printf("\n");
    for ( i = 0; i < DIM; i++)
    {
        c=0;
        cNum=v[i];
        if (cNum!=(RANDMIN-1))
        {
            for ( j = 0; j < DIM; j++)
            {
                if (v[j]== cNum)
                {
                    c++;
                    v[j]=(RANDMIN-1);
                } 
            }
            printf("\n%d e' visualizzato %d volte",cNum,c);
        }
        v1[i]=c;
    }
    //VIS vettore 2
    printf("\n");
    for(i=0; (i<sizeof(v1)/sizeof(int)); i++){
        printf("%d ",v1[i]);
    }
    return 0;
}