#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{   
    char c, str[]="effe";
    FILE* in = fopen("Input.txt", "r");
    FILE* out = fopen("Output.txt", "w");

    c=fgetc(in);

    while(c!=EOF){
        if (c=='X'){
            fputs(str, out);
        }
        c=fgetc(in);
    }

    printf("FINE");

    fclose(in);
    fclose(out);
}
