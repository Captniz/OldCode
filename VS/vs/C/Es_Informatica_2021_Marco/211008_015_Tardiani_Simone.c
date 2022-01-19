//211008_015_Tardiani_Simone.c
//Caricare una matrice quadrata con DIM=10 con numeri random [1..9] nella parte superiore.
//Nella parte inferiore gli elementi sono posti = 0.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
#define RANDMIN 1
#define RANDMAX 9

int main()
{
    int m[DIM][DIM],i,j;
    i=0;
    j=0;
    srand(time(NULL));
    //Load
    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            if (i>j){
                m[i][j]=0;
            }else{
                m[i][j]=rand()%(RANDMAX-RANDMIN+1)+RANDMIN;
            }
        }
    }
    //Vis
    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            printf("%d",m[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
