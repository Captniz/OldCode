#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define DIM 10

int BinarySearch(int Start, int End, int N, int v[DIM]);
void carica(int v[]);
void vis(int v[]);
void ordina(int v[]);

int main(){
    int v[DIM];
    srand(time(NULL));

    carica(v);
    ordina(v);
    vis(v);
    printf("\n\n%d\n",BinarySearch(0,DIM,2,v));
    return 0;
}

void carica(int v[DIM]){
    
    int i=0;

    for(i=0; i<DIM; i++){
        v[i]=rand()%10+1;
    }
}

void vis(int v[DIM]){

    int i=0;
    
    for(i=0; i<DIM; i++){
        printf("%d ",v[i]);
    }
}

int BinarySearch(int Start, int End, int N, int v[DIM]){
    int Half=0;
    while (Start <= End){
        Half=((End-Start)/2)+Start;        
    
        if (v[Half]==N){
            return 1;
        }else if (v[Half] > N){
            End=Half-1;
        }else{
            Start=Half+1;
        }
    }

    return 0;
}

void ordina(int v[]){
    
    int box,i,j;
    j=0;
    i=0;
    box=0;

    for ( i = 0; i < DIM-1; i++){
        for ( j = i+1; j < DIM; j++){
            if (v[j]<v[i]){
                box=v[j];
                v[j]=v[i];
                v[i]=box;
            }
        }
    }

}