#include<stdio.h>
#define DIM 5

int main()
{
    int i,t,n,v[]={0,1,2,3,0};
    t=0;
    n=0;
    i=0;

    do{
    printf("Posizione?:");
    scanf("%d",&t);
    }while(t<0 && t>DIM-2);
    fflush(stdin);

    printf("Numero?:");
    scanf("%d",&n);
    fflush(stdin);

    for(i=DIM-1; i>t; i--){
        v[i]=v[i-1];
    }

    v[t]=n;

    for(i=0; i<DIM; i++){
        printf("%d ",v[i]);
    }
    return 0;
}
