#include<stdio.h>
#define DIM 10

void CaricaArray(int v[DIM]);
int TrovaIndiceInput(int v[DIM]);
void ArrayShift(int v[DIM], int n);
void StampaArray(int v[DIM]);

int main()
{
    int v[DIM];
    CaricaArray(v);
    ArrayShift(v,TrovaIndiceInput(v));
    StampaArray(v);
    return 0;
}

void CaricaArray(int v[DIM]){

    int i;
    i=0;

    for(i=0; i<DIM; i++){
        v[i]=i+1;
    }
}
int TrovaIndiceInput(int v[DIM]){

    int n,i;
    n=0;
    i=0;

    do{
        printf("Numero?:");
        scanf("%d",&n);
        fflush(stdin);

        for ( i = 0; i < DIM; i++){
            if (v[i]==n){
                return i;
            }
        }
    }while(1);
}
void ArrayShift(int v[DIM], int n){

    int i;
    i=0;

    for(i=n+1; i<DIM; i++){
        v[i-1]=v[i];
    }
}
void StampaArray(int v[DIM]){
    int i;
    i=0;

    for(i=0; (i<DIM-1); i++){
        printf("%d ",v[i]);
    }
}