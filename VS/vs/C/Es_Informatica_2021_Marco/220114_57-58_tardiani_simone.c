#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DIM 10

int Menu( int E, int v[DIM] );
void BubbleSort( int v[DIM]);
void InsertionSort( int v[DIM]);
void SelectionSort( int v[DIM]);
void Carica( int v[DIM]);
void Visualizza( int v[DIM]);

int main(){
    int E=0;
    int v[DIM];
    srand(time(NULL));

    while(1){
        switch (Menu(E,v))
        {
        case 0:
            return 0;
            break;
        case 1:
            E=0;
            Carica(v);
            break;
        case 2:
            E=1;
            Visualizza(v);
            break;
        case 3:
            E=1;
            BubbleSort(v);
            break;
        case 4:
            E=1;
            InsertionSort(v);
            break;
        case 5:
            E=1;
            SelectionSort(v);
            break;
        default:
            E=2;
            break;
        }
    }
    return 0;
}

int Menu( int E, int v[DIM]){

    int i=0;
    int a=0;
    for( i = 0; i < 50; i++){
        putchar('\n');
    }

    if (E==2){
        printf("Output:\n!!!ERRORE, selezione sbagliata!!!\n\n");
    }

    if (E==1){
        printf("Output:\n");
        for ( i = 0; i < DIM; i++){
            printf("%3d",v[i]);
        }
        printf("\n\n");
    }

    printf("0.Uscita\n1.Carica array\n2.Visualizza array\n3.Bubble sort\n4.Insertion sort\n5.Selection sort\n\nSelezionare l'opzione:");

    scanf("%d",&a);

    return a;
}
void BubbleSort( int v[DIM]){

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
void InsertionSort( int v[DIM]){
	int i,j,min;
    for(i=1;i<DIM;i++){
        min=v[i];
        for(j=i-1;(j>=0) && (min<v[j]);j--){
            v[j+1]=v[j];
        }
        v[j+1]=min;
    }
}
void SelectionSort( int v[DIM]){
    
    int i,j,box,min;
    j=0;
    i=0;
    box=0;
    min;

    for ( i = 0; i < DIM-1; i++){
        min=i;
        for ( j = i+1; j < DIM; j++){
            if (v[j]<v[min]){
                min=j;
            }
        }

        if (min!=i){
            box=v[i];
            v[i]=v[min];
            v[min]=box;
        }
    }
    
}
void Carica( int v[DIM]){

    int i=0;

    for ( i = 0; i < DIM; i++){
        v[i]=rand()%99+1;
    }
    

}
void Visualizza( int v[DIM]){

    int i=0;

    for ( i = 0; i < DIM; i++){
        printf("%3d",v[i]);
    }
    
}
