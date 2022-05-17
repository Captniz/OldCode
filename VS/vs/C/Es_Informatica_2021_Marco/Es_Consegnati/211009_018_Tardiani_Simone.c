//211009_018_Tardiani_Simone.c
//dato un vettore riscrivere il vettore con i numeri primi nelle prime posizioni e i nojn primi dopo
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
#define RANDMIN 0
#define RANDMAX 50

int main()
{
    int v[DIM],v1[DIM],j,i,flag,ctrPrimi,ctrNPrimi;
    i=0;
    j=0;
    flag=0;
    ctrPrimi=0;
    ctrNPrimi=DIM-1;
    srand(time(NULL));
    //load
    for(i=0; i<DIM; i++){
        v[i]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
    }
    //vis
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);
    }
    //Analisi
    for(i=0; i<DIM; i++){
        flag=1;
        if(v[i]>1){
            for ( j = 2; j <= (v[i]/2) && flag!=0; j++){
                if (v[i]%j==0){
                    flag=0;
                }                               //Flag 0 non sono primi
            }                                   //Flag 1 primi
        }else{
            flag=0;
        }
        //Aggiunta nella corretta posizione all'interno del secondo array
        if (flag){
            v1[ctrPrimi]=v[i];
            ctrPrimi++;
        }else{
            v1[ctrNPrimi]=v[i];
            ctrNPrimi--;
        }
    }
    //Vis secondo array
    printf("\n");
    for(i=0; (i<sizeof(v1)/sizeof(int)); i++){
        printf("%d ",v1[i]);
    }
    return 0;
}