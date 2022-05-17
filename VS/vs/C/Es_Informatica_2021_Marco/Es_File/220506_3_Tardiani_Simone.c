#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 80

int main(){
    char buf[80];
    FILE* in = fopen("Input.txt", "r");

    fgets(buf, (DIM-1), in);
    fflush(stdin);
    printf("%s", buf);
    
    fseek(in, 0, SEEK_SET);

    fgets(buf, (DIM-1), in);
    fflush(stdin);
    printf("\n%s", buf);

    fclose(in);
}