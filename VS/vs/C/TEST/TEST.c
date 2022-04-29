#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 3

int main(int argc, char const *argv[]){
   
   int i,temp_voto,VOTI[DIM];
   temp_voto=0;
   i=0;
   
   for(i=0; i<DIM; i++){
      VOTI[i]=0;
   }
   i=0;

   printf("\nVoto %d:",(i+1));
   scanf("%d",&temp_voto);
   fflush(stdin);
zzz
   while (temp_voto!=0){
      VOTI[i]=temp_voto;
      i++;
      if (i<DIM){
         printf("\nVoto %d:",(i+1));
         scanf("%d",&temp_voto);
         fflush(stdin);
      }else{
         temp_voto=0;
      }
   }
   
   for(i=0; i<DIM; i++){
      printf("%d ",VOTI[i]);
      fflush(stdin);
   }

   return 0;
}
