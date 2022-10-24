/*Caricare una matrice quadrata con DIM=10 con numeri random [1..9] nella parte superiore.
/Nella parte inferiore gli elementi sono posti = 0.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
int main()
{
    int m[DIM][DIM],i,j;
    srand(time(NULL));
    //Load
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            if(i>j){
                m[i][j]=0;
            }else{
                m[i][j]=rand()%(9-1+1)+1;
            }
        }
    }
    //Vis
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
        	printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
