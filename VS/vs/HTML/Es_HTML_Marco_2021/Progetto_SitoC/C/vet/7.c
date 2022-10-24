/*13> Caricare un vettore v dimensionato 10 con in primi 10 numeri naturali.
Eseguire un right-shift (spingere a dx) 1 2 3 4 5 6 7 8 9 10 ->  10 1 2 3 4 5 6 7 8 9*/
#include<stdio.h>
#define DIM 10
int main()
{
    int v[]={1,2,3,4,5,6,7,8,9,10}, lastnum, i ;
    lastnum=0;
    i=0;
    //Vis
    for(i=0;i<DIM;i++){
        printf("%3d",v[i]);
    }
    //Shift
    lastnum=v[DIM-1];
    for (i=DIM-2;i>=0;i--){
        v[i+1]=v[i] ;
    }
    v[0]=lastnum;
    putchar('\n');
    //Vis
    for(i=0;i<DIM;i++){
        printf("%3d",v[i]);
    }
    return 0;
}
