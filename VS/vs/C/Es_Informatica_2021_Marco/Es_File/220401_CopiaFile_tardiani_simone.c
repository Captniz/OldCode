#include<stdio.h>
#include<stdlib.h>
#define DIM 100

int main(){
    char buf[DIM];
    int n;
    FILE* in = fopen("Input.txt", "r");
    FILE* out = fopen("Output.txt", "w");

    if (in == NULL || out == NULL){
        printf("File non trovati o memoria di massa piena\n");
        return 1;
    }
    do{ 
        n = fread(buf,sizeof(char),DIM,in);
        fwrite(buf,sizeof(char),n,out);
    }while(n==100);
    
    fclose(in);
    fclose(out);

    printf("Fine\n");
    return 0;
}
