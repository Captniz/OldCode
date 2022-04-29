#include<stdio.h>
#include<stdlib.h>
int rico(int num, int result);

int main(){
   int num,result;
   printf("Inserisci un numero: ");
   scanf("%d",&num);
   printf("\n%d",rico(num,0));
   
   return 0;
}

int rico(int num, int result){
   if(num!=0){
      result = result*10 + num%10;
      return rico((num/10),result);
   }

   return result;
}