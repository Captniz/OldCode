#include "F:\Rep_1\VS\vs\C\MyLibs\Essentials.c"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 5

int main(){

    int a[DIM], b[DIM], c[(DIM*2)];
    int i=0;
    srand(time(NULL));

    ranload(a,DIM,10,1);
    ranload(b,DIM,10,1);
    Bubble(a,DIM);
    Bubble(b,DIM);
    MergeOrdinated(a,b,c,DIM,DIM);

    vis(a,DIM);
    putchar('\n');
    vis(b,DIM);
    putchar('\n');
    for(i=0; i<(DIM*2); i++){
        printf("%d ",c[i]);
    }

    return 0;
}