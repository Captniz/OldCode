#define DIM 20
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void carica(int v[DIM]);
void vis(int v[DIM]);
void sort(int v[DIM],int start, int end);

int main(){
    int v[DIM];
    srand(time(NULL));

    carica(v);
    vis(v);
    sort(v,0,DIM/2);
    sort(v,DIM/2,DIM);
    vis(v);

    return 0;
}

void carica(int v[DIM]){
    int i=0;
    for ( i = 0; i < DIM; i++){
        v[i]=rand()%100+1;
    }
}

void vis(int v[DIM]){
    int i=0;
    for(i=0; i<DIM/2; i++){
        printf("%3d ",v[i]);
    }
    putchar('/');
    for ( i = i; i < DIM; i++){
        printf("%3d ",v[i]);
    }
    
    printf("\n\n");
}

void sort(int v[DIM],int start, int end){
    int box,i,j;
    j=0;
    i=0;
    box=0;

    for ( i = start; i < end-1; i++){
        for ( j = i+1; j < end; j++){
            if (v[i]>v[j]){
                box=v[i];
                v[i]=v[j];
                v[j]=box;
            }
        } 
    }
}

/*#define DIM 50
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int j,i,v[DIM],box;
    i=0;
    j=0;
    srand(time(NULL));

    for ( i = 0; i < DIM; i++)
    {
        v[i]=rand()%10+1;
    }
    for ( i = 0; i < DIM; i++)
    {
        printf("%3d",v[i]);
    }
    
    for ( i = 0; i < (DIM/2)-1; i++)
    {
        for ( j = i+1; j < (DIM/2); j++)
        {
            if (v[i]>v[j])
            {
                box=v[i];
                v[i]=v[j];
                v[j]=box;
            }
            
        }
        
        
    }
    
    for(i=DIM/2; i<DIM-1; i++) {
        for(j=i+1;j<DIM;j++){
            if (v[i]>v[j])
            {
                box=v[i];
                v[i]=v[j];
                v[j]=box;
            } 
        }
    }

    putchar('\n');
    for(i=0; i<DIM; i++){
        printf("%3d",v[i]);
    }

    return 0;
}
*/