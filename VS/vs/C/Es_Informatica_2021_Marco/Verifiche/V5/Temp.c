#include<stdio.h>

#include<stdlib.h>

#define DIM 10;



void sequenza(int v[DIM],int *n, int *ctr);



int main(){

   int v[DIM]={0,0,0,0,1,1,2,3,3,3},*n,*ctr;

   sequenza(v, n , ctr);

}



void sequenza(int v[DIM],int *n, int *ctr){

   int i,max,ctr,maxctr,nctr;

   i=0;

   maxn=v[0];

   ctr=1;

   maxctr=0;

   nctr=v[0];

   for(i=1;i<DIM;i++){

      if(nctr=v[i]){

        ctr++;

     }else{

         if(ctr>maxctr){

             maxctr=ctr;

             max=nctr;

         }

         nctr=v[i];

         ctr=1;

    }

  }

   if(ctr>maxctr){

             maxctr=ctr;

             max=nctr;

         }


  *n=maxn;

  *ctr=maxctr;

}
