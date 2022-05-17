#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 10

int main(){
    FILE* in = fopen("Input.txt", "r");
    FILE* out = fopen("Output.txt","w");
    char next[3] = " \n\0";
    int i=0;
    char buf[80];

    while(i<DIM && (fscanf(in, "%s",&buf)!=EOF)){
        fprintf(out, "%s",buf);
        fprintf(out, "%s",next);
        i++;
    }

    fclose(out);
    fclose(in);
}
