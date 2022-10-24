/*59>
Caricare un vet v DIM=20 con numeri random a piacere.
Visualizzare v.
Ordinare la prima metà di v e poi la seconda metà di v.
Alla fine v risulterà ordinato.
Visualizzare nuovamente v.
*/
#define DIM 20
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void carica(int v[DIM]);
void visualizza(int v[DIM]);
void sort(int v[DIM],int start, int end);
int main(){
    int v[DIM];
    srand(time(NULL));
    carica(v);
    visualizza(v);
    sort(v,0,DIM/2);
    sort(v,DIM/2,DIM);
    visualizza(v);
    return 0;
}
void carica(int v[DIM]){
    int i=0;
    for(i=0;i<DIM;i++){
        v[i]=rand()%100+1;
    }
}
void visualizza(int v[DIM]){
    int i=0;
    for(i=0;i<DIM/2;i++){
        printf("%4d",v[i]);
    }
    putchar('/');
    for (i=i;i<DIM;i++){
        printf("%4d",v[i]);
    }
    
    printf("\n\n");
}
void sort(int v[DIM],int start, int end){
    int box,i,j;
    for(i=start;i<end-1;i++){
        for(j=i+1;j<end;j++){
            if(v[i]>v[j]){
               box=v[i];
               v[i]=v[j];
               v[j]=box;
            }
        } 
    }
}
