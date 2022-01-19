#include<stdio.h>
#define DIM 10

void azzera(int m[][DIM]);
void visualizza(int m[][DIM]);
void carica(int m[][DIM]);

int main()
{
    int m[DIM][DIM];
    azzera(m);
    visualizza(m);
    putchar('\n');
    carica(m);
    visualizza(m);
    return 0;
}

void azzera(int m[][DIM]){

    int i,j;
    j=0;
    i=0;

    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            m[i][j]=0;
        }
    }

}

void visualizza(int m[][DIM]){


    int i,j;
    j=0;
    i=0;

    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            printf("%4d",m[i][j]);
        }
        putchar('\n');
    }

}

void carica(int m[][DIM]){
    
    int i,j,dim,MinCOL,max;
    j=0;
    i=0;
    dim=DIM;
    MinCOL=0;
    max=0;

    do{
        for ( i = MinCOL; i < dim; i++){
            for ( j = MinCOL; j < dim; j++){
                if (j==dim-1 || i==MinCOL){
                    m[i][j]=i+j+1+max-((DIM-dim)*2);
                }
                if ((j<dim-1 && i==dim-1) || (j==MinCOL && i>MinCOL) ){
                    m[i][j]=((dim*4)-3)-(i+j)+max-((DIM-dim)*2);
                }  
            }
        }
        max=m[MinCOL+1][MinCOL];
        dim=dim-1;
        MinCOL++;
    }while(dim!=0);
}
