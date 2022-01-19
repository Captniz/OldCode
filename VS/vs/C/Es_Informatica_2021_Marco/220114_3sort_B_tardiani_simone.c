#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DIM 10

int Menu(char x,int v[DIM],int vmaster[DIM], int swap, int conf);
void BubbleSort(int v[DIM],int *swap,int *conf);
void InsertionSort(int v[DIM],int *swap,int *conf);
void SelectionSort(int v[DIM],int *swap,int *conf);
void Carica(int vmaster[DIM]);
void Copia(int vmaster[DIM], int v[DIM]);
void Reset(int *, int *);

int main(){
    char x = 'x';
    int v[DIM];
    int vmaster[DIM]; //ARRAY PRINCIPALE
    int swap = 0;
    int conf = 0;
    srand(time(NULL));


    while(1){
        switch (Menu(x,v[DIM],vmaster[DIM],swap,conf))
        {
        case 0:
            return 0;
            break;
        case 1:
            x='x';
            Carica(v);
            Copia(vmaster,v);
            break;
        case 2:
            x='P';
            Reset(&swap,&conf);
            Copia(vmaster,v);
            BubbleSort(v, &swap, &conf);
            break;
        case 3:
            x='P';
            Reset(&swap,&conf);
            Copia(vmaster,v);
            InsertionSort(v, &swap, &conf);
            break;
        case 4:
            x='P';
            Reset(&swap,&conf);
            Copia(vmaster,v);
            SelectionSort(v, &swap, &conf);
            break;
        default:
            x='E';
            break;
        }
    }

    //TODO: casino coi puntatori dei array?
}

int Menu(char x,int v[DIM],int vmaster[DIM], int swap, int conf){

    int i=0;
    int a=0;

    for( i = 0; i < 50; i++){
        putchar('\n');
    }

    switch (x)
    {
    case 'P':
        printf("Output:\n");

        printf("Array master: ");
        for ( i = 0; i < DIM; i++){
            printf("%3d",vmaster[i]);
        }
        putchar('\n');

        printf("Array sortato: ");
        for ( i = 0; i < DIM; i++){
            printf("%3d",v[i]);
        }
        putchar('\n');

        printf("Swap: %d\nConf:%d");
        
        break;
    
    case 'E':
        printf("!!!ERRORE: input non riconosciuto!!!");

    default:
        break;
    }    

    printf("\n\n");

    printf("0.Uscita\n1.Carica array\n2.Bubble sort\n3.Insertion sort\n4.Selection sort\n\nSelezionare l'opzione:");

    scanf("%d",&a);

    return a;
}

void Reset(int *swap, int *conf){
    swap =0;
    conf =0;
}

void Copia(int vmaster[DIM], int v[DIM]){
    int i=0;

    for ( i = 0; i < DIM; i++){
        v[i]=vmaster[i];
    }
}

void SelectionSort( int v[DIM],int *swap,int *conf){
    
    int i,j,box,min;
    j=0;
    i=0;
    box=0;
    min;

    for ( i = 0; i < DIM-1; i++){
        min=i;
        for ( j = i+1; j < DIM; j++){
            *conf=*conf+1;
            if (v[j]<v[min]){
                min=j;
            }
        }

        if (min!=i){
            box=v[i];
            v[i]=v[min];
            v[min]=box;
            *swap=*swap+1;
        }
    }
    
}

void BubbleSort( int v[DIM],int *swap,int *conf){

    int box,i,j;
    j=0;
    i=0;
    box=0;

    for ( i = 0; i < DIM-1; i++){
        for ( j = i+1; j < DIM; j++){
            *conf=*conf+1;
            if (v[j]<v[i]){
                box=v[j];
                v[j]=v[i];
                v[i]=box;
                *swap=*swap+1;
            }
        }
    }

}

void InsertionSort( int v[DIM],int *swap,int *conf){

//!DIOPORCO CHE SORTING DA MANGIAPISELLI
    
}
