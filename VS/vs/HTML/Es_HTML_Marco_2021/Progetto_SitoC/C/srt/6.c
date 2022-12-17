/*59&gt;
Caricare un vet v DIM=20 con numeri random a piacere.
Visualizzare v.
Ordinare la prima met� di v e poi la seconda met� di v.
Alla fine v risulter� ordinato.
Visualizzare nuovamente v.
*/
#define DIM 20
#include&lt;stdio.h&gt;
#include&lt;time.h&gt;
#include&lt;stdlib.h&gt;
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
    for(i=0;i&lt;DIM;i++){
        v[i]=rand()%100+1;
    }
}
void visualizza(int v[DIM]){
    int i=0;
    for(i=0;i&lt;DIM/2;i++){
        printf("%4d",v[i]);
    }
    putchar('/');
    for (i=i;i&lt;DIM;i++){
        printf("%4d",v[i]);
    }
    
    printf("\n\n");
}
void sort(int v[DIM],int start, int end){
    int box,i,j;
    for(i=start;i&lt;end-1;i++){
        for(j=i+1;j&lt;end;j++){
            if(v[i]&gt;v[j]){
               box=v[i];
               v[i]=v[j];
               v[j]=box;
            }
        } 
    }
}
