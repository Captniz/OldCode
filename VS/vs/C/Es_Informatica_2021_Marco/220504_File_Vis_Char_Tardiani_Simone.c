// Aprire un file ASCII e leggere e visualizzare i primi 10 gruppi di caratteri separati da blank e newline.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 10

int main(){

    //char buf[DIM];
    //int n=0;
    FILE* in = fopen("Input.txt", "r");
    FILE* out = fopen("Output.txt","w");
    char next[3] = " \n\0";
    int i=0;
    char buf[80];

    while(i<DIM || fscanf(in, "%s",&buf)){
        fscanf(in, "%s",&buf);
        fprintf(out, "%s",buf);
        fprintf(out, "%s",next);
        i++;
    }
    
    /*
    do{
        n=fread(buf,sizeof(char),DIM,in);
        fwrite(buf,sizeof(char),n,out);
        fprintf(out, "%s",next);
    }while(n==DIM);
    */

    fclose(out);
    fclose(in);
}
