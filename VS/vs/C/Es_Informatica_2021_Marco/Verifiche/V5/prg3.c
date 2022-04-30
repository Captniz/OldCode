#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define DIM 3

struct studente{
   char Nome[20];
   char Cognome[20];
   int Voto;
};

float inserisci(struct studente v[DIM]);

int main(){
   
   struct studente v[DIM];

   printf("\n\n%f",inserisci(v));
   
   return 0;
}


float inserisci(struct studente v[DIM]){

   int i,j,media;
   i=0;
   j=0;
   media=0;

   printf("Nome %d:",i+1);
   gets(v[i].Nome);
   fflush(stdin);
   printf("Cognome %d:",i+1);
   gets(v[i].Cognome);
   fflush(stdin);
   printf("Voto %d:",i+1);
   scanf("%d",&v[i].Voto);
   fflush(stdin);
   i++;

   while(i<DIM && v[i-1].Voto!=0){
      printf("Nome %d:",i+1);
      gets(v[i].Nome);
      fflush(stdin);
      printf("Cognome %d:",i+1);
      gets(v[i].Cognome);
      fflush(stdin);
      printf("Voto %d:",i+1);
      scanf("%d",&v[i].Voto);
      fflush(stdin);
      i++;
   }

   if(v[i-1].Voto==0 && (i-1)!=0){
      i--;
   }

   for(j=0;j<i;j++){
      media=media+v[j].Voto;
   }

   return (media/i);
}