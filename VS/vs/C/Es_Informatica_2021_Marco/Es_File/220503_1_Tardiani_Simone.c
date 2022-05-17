#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 30

int main(){
    char c;
    char buf[30];
    char path[80];
    FILE* in;
    
    do{
        printf("Percorso FILE di sistema: ");
        gets(path); 
        in = fopen(path,"r");     //"C://Windows/Lenovo/ImController/Data/NOTICE_IMCService.txt"
    }while(in==NULL);

    while((c=fgetc(in))!=EOF){
        putchar(c);
    }

    fclose(in);

    return 0;
}
