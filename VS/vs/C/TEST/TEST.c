#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 3

int main(int argc, char const *argv[]){
   
   int i=0;

   FILE* out=fopen("test_output.txt","r+");

   fseek(out,3,SEEK_SET);

   fputc('c',out);

   fclose(out);

   return 0;
}
