#include<stdio.h>
#define DIM 7

int main()
{
    int i,v[7] ={1,0,1,0,0,0,0},vv[7]={1,0,1,1,0,0,0};
    i=0;

    for(i=0; i<DIM; i++){
        if (v[i]== 1 && vv[i]== 1 )
        {
            printf("Il giorno %d sono liberi entrambi\n",i+1);
        }
        
    }

    return 0;
}
