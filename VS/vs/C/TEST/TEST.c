#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 5

int main(){
   int pos,ctr,i;
   char c,space;
   pos=0;
   ctr=0;
   FILE*fp;

   fp=fopen("test_output.txt","r+");

   if(fp==NULL){
      printf("Error opening file\n");
      exit(1);
   }

   while (fread(&c,sizeof(char),1,fp)!=0){
      pos = ftell(fp);
      pos=pos-1;
      if (c=='/'){
         ctr++;
         while (fread(&c,sizeof(char),1,fp)!=0){
            fseek(fp,-2,SEEK_CUR);
            fwrite(&c,sizeof(char),1,fp);
            fseek(fp,0,SEEK_CUR);
            fseek(fp,1,SEEK_CUR);
         }
         fseek(fp,pos,SEEK_SET);
      }
   }

   space=' ';
   fseek(fp,-ctr,SEEK_END);
   for ( i = 0; i < ctr; i++){
      fwrite(&space,sizeof(char),1,fp);
      fseek(fp,0,SEEK_CUR);
   }

   fclose(fp);
   return 0;
}

/*   int n;
   int nums[DIM] = {1,2,3,1,5};
   FILE*fp;
   fp=fopen("test_output.dat","wb");

   fwrite(nums,sizeof(int),DIM,fp);
   fseek(fp,0,SEEK_CUR);

   fclose(fp);
   fp=fopen("test_output.dat","rb");

   while (fread(&n,sizeof(int),1,fp)!=0){
      printf("%d\n",n);
   }

   fclose(fp);
   fp=fopen("test_output.dat","rb+");

   while (fread(&n,sizeof(int),1,fp)!=0){
      if (n==1){
         fseek(fp,((-1)*(sizeof(int))),SEEK_CUR);
         n=9;
         fwrite(&n,sizeof(int),1,fp);
         fseek(fp,0,SEEK_CUR);
      }
   }

   printf("\n\n");

   fclose(fp);
   fp=fopen("test_output.dat","rb");

   while (fread(&n,sizeof(int),1,fp)!=0){
      printf("%d\n",n);
   } 

   fclose(fp);
   return 0;   */