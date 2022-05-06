#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 30

int main(){
    int n=0;
    char buf[30];
    char path[80];
    FILE* out = fopen("Output.txt","w");
    FILE* in;
    
    do{
        printf("Percorso FILE: ");
        gets(path); 
        in = fopen(path,"r");     //"C://Windows/Lenovo/ImController/Data/NOTICE_IMCService.txt"
    }while(in==NULL);

    do{
        n=fread(buf,sizeof(char),DIM,in);
        fwrite(buf,sizeof(char),n,out);
    } while (n==DIM);

    fclose(in);
    fclose(out);

    return 0;
}
