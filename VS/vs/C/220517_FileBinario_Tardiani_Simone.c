#include<stdio.h>
#include<stdlib.h>
#define DIM 2

int main(){
    int n1,n2,sum,nums[2];
    n1=10;
    n2=15;
    sum=0;

    FILE* fp;
    fp=fopen("Output.dat","rb+");

    fwrite(&n1,sizeof(int),1,fp);
    fwrite(&n2,sizeof(int),1,fp);

    fseek(fp,0,SEEK_SET);
    fread(nums,sizeof(int),2,fp);

    sum=nums[0]+nums[1];

    fwrite(&sum,sizeof(int),1,fp);
    sum=0;

    fseek(fp,-1,SEEK_CUR);
    fread(&sum,sizeof(int),1,fp);

    printf("%d",sum);

    fclose(fp);
    return 0;
}