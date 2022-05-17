#include<stdio.h>
#define DIM 10

int main(){

    int v[DIM]={9,1,3,2,4,6,5,8,7,0},box,j,i,iMAX,iMIN;
    i=0;
    j=0;
    iMAX=0;
    iMIN=0;
    box=0;

    for ( i = 0; i < DIM; i++){
        if (v[i]>v[iMAX]){
            iMAX=i;
        }else if(v[i]<v[iMIN]){
            iMIN=i;
        }
    }

    if (iMAX>iMIN){
        for(j=0;j<((iMAX-iMIN)-2);j++){
            for ( i = iMIN+1; i < iMAX-j-1; i++){
                if (v[i]>(v[i+1])){
                    box=v[i];
                    v[i]=v[i+1];
                    v[i+1]=box;
                }
            }
        }
    }else{
        for(j=0;j<((iMIN-iMAX)-2);j++){
            for ( i = iMAX+1; i < iMIN-j-1; i++){
                if (v[i]<(v[i+1])){
                    box=v[i];
                    v[i]=v[i+1];
                    v[i+1]=box;
                }
            }
        } 
    }
    
    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
        printf("%d ",v[i]);
    }    
    
    return 0;
}
