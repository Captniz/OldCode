#include<stdio.h>
#include<stdlib.h>
#define DIM 10

void sequenza(int v[DIM],int *n, int *ctr);

int main(){
   int v[DIM]={0,0,0,0,1,1,2,3,3,3},*n,*ctr,ctr1,n1;
   n1=0;
   ctr1=0;
   ctr=&ctr1;
   n=&n1;

   sequenza(v, n , ctr);

   printf("\nN:%d",*n);
   printf("\nCTR:%d",*ctr);

   return 0;
}

void sequenza(int v[DIM],int *n, int *ctr){
   int i,seq;
   i=1;
   seq=1;

   for ( i = 1; i < DIM; i++){
      if (v[i]==v[i-1]){
         seq++;
      }else{
         if (*ctr<seq){
            *ctr=seq;
            *n=(v[i-1]);
         }
         seq=1;
      }
   }
   
   if (*ctr<seq){
      *ctr=seq;
      *n=(i-1);
   }
}