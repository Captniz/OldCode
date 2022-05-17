#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 30

int main(){
   char n;
   FILE*  out; 
   out= fopen("test_output.txt", "r+"); 
/*    
   printf("%d\n",ftell(out));

   fread(&n,sizeof(char),1,out);
   while (n!='\n'){
      putchar('x');
      fread(&n,sizeof(char),1,out);
   }
   
   printf("\n%d",ftell(out)); */

   while (!feof(out)){
      fread(&n,sizeof(char),1,out);
      putchar('x');
   }

   fclose(out);
   return 0;
                
}
