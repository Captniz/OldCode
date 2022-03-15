/* 220305_quicksort.c
 Ordinamento quicksort di un array di int
 ----------------------------------------*/

// rispondere ai 7 punti del listato spiegando il codice e per ultimo al punto 8
// (08) ragionamento generale

#include <stdio.h>
#define DIM 23
void quick(int [],int, int);
void scambia(int *, int *);
void visualizza(int []);

int main(){
    int v[DIM]={1,3,45,6,77,82,5,23,9,11,233,45,67,600,56,2234,56,7,77,878,1234,2,44};
    quick(v,0,DIM-1); //(1): Chiamo la funzione, come variabili gli passo l'array, l'indice estremo di sinistra e l'indice estremo di destra
    visualizza(v);
    return 0;
}

void visualizza(int v[DIM]){
    int i;
    for(i=0; i<DIM; i++){
        printf("%d ", v[i]);
    }
    putchar('\n');
}

/* Procedura ricorsiva "quick" */
void quick(int v[DIM], int sin, int des)
{
    int i, j, media;
    media= (v[sin]+v[des]) / 2; // (2): Trovo la media tra i valori contenuti nell'indice estremo di destre e l'indice estremo di sinistra
    i = sin;
    j = des;

    do {
        while(v[i]<media) {
            i++; // (4): Trovo il primo valore superiore alla media nel lato sinistro dell'array partendo dall'inzizio
        }
        while(media<v[j]) {
            j--; // (5): Trovo il primo valore inferiore alla media nel lato destro dell'array partendo dal fondo
        }
        if(i<=j){
            scambia(&v[i], &v[j]);
            i++;
            j--;
        }
    }while (j>=i); // (5): Ripeti fino a che il contatore j diventa minore del contatore i, questo significa che tutto l'array è stato passato

    if(sin<j){ 
        quick(v,sin,j); // (6)
    }

    if(i<des){
        quick(v,i,des); // (7)
    }
}

void scambia(int *a, int *b){
    int box;
    box = *a;
    *a = *b;
    *b = box;
}