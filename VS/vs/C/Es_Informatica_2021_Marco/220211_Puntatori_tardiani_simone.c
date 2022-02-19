#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define DIM 10

void carica(int []);
void Trovamax(int v[], int *min, int *max, int *p_max, int *p_min, int *Vmax, int *Vmin);

int main(){
    int v[DIM],max,min,Vmax,Vmin;
    max=0;
    min=0;
    Vmax=0;
    Vmin=0;
    int *p_max;
    int *p_min;
    srand(time(NULL));

    carica(v);
    Trovamax(v,&min,&max,p_max,p_min,&Vmax,&Vmin);

    printf("Il massimo e' %d\n",max);
    printf("Il minimo e' %d\n",min);
    printf("Il massimo con puntatore e' %d con indirizzo %d uguale a %d dell'array\n",*p_max,p_max,&v[Vmax]);
    printf("Il minimo con puntatore e' %d con indirizzo %d uguale a %d dell'array\n",*p_min,p_min,&v[Vmin]);

    return 0;
}

void carica(int v[DIM]){
    int i;

    for ( i = 0; i < DIM; i++){
        v[i]=rand()%10+1;
    }
}

void Trovamax(int v[], int *min, int *max, int *p_max, int *p_min, int *Vmax, int *Vmin){

    int i;
    *max = v[0];
    *min = v[0];

    for ( i = 1; i < DIM; i++){
        if (v[i]>*max){
            *max=v[i];
            p_max=&v[i];
            *Vmax=i;
        }
        if (v[i]<*min){
            *min=v[i];
            p_min=&v[i];
            *Vmin=i;
        }
    }
}