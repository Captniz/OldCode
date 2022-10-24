/*62> dato una matrice numerica quadrata m dimensionato 
DIM=10 con caricamento random a piacere [10..90].
visualizzare la matrice.
Riga dispari ordinata in modo crescente
Riga pari ordinata in modo decrescente
visualizzare la matrice.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
void load (int m[DIM][DIM]);
void vis (int m[DIM][DIM]);
void sort (int m[DIM][DIM]);
int main(){
    int m[DIM][DIM];
    srand(time(NULL));
    load(m);
    vis(m);
    putchar('\n');
    sort(m);
    vis(m);
    return 0;
}
void load(int m[DIM][DIM]){
    int i,j;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            m[i][j]=rand()%81+10;
        }
    }
}
void vis(int m[DIM][DIM]){
    int i,j;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
}
void sort(int m[DIM][DIM]){
    int i,j,k,temp;
    for(i=0;i<DIM;i++){
        if(i%2==0){
            for(j=0;j<DIM-1;j++){
                for(k=j+1;k<DIM;k++){
                   	if(m[i][j]<m[i][k]){
                    	temp=m[i][k];
                    	m[i][k]=m[i][j];
                    	m[i][j]=temp;
                   	}
                }
            }
        }else{
            for(j=0;j<DIM-1;j++){
                for(k=j+1;k<DIM;k++){
                   	if(m[i][j]>m[i][k]){
                    	temp=m[i][k];
                    	m[i][k]=m[i][j];
                       	m[i][j]=temp;
                   	}
                }
            }
        }
    }
}
