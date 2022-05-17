#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "F:\Rep_1\VS\vs\C\MyLibs\Essentials.c"
#define DIM 100

int main(){
    char buf[DIM];
    int n;
    int i;
    FILE* in = fopen("Input.old", "r");
    FILE* out = fopen("Output.txt", "w");
    if (in == NULL){
        printf("File non trovati o memoria di massa piena\n");
        return 1;
    }
    while(fgets(buf,DIM,in) != NULL){
        buf[0]-=('a'-'A');
        buf[strlen(buf)]='\0';
        fputs(buf,out);
    }
    
    fclose(in);
    printf("Fine");
    return 0;
}