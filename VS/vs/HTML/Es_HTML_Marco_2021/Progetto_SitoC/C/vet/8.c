/*14&gt; Caricare un vettore v dimensionato 10 con in primi 10 numeri naturali.
Eseguire un left-shift (spingere a sx) 1 2 3 4 5 6 7 8 9 10 -&gt;  2 3 4 5 6 7 8 9 10 1*/
#include&lt;stdio.h&gt;
#define DIM 10

int main()
{
    int v[]={1,2,3,4,5,6,7,8,9,10}, FirstNum, i ;
    FirstNum=0;
    i=0;
    //Vis
    for(i=0;i&lt;DIM;i++){
        printf("%3d",v[i]);
    }
    //Shift
    FirstNum=v[0];
    for(i=1;i&lt;DIM;i++){
        v[i-1]=v[i] ;
    }
    v[DIM-1]=FirstNum;
    putchar('\n');
    //Vis
    for(i=0;i&lt;DIM;i++){
        printf("%3d",v[i]);
    }
    return 0;
}
