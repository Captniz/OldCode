#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{   
    char a;
    FILE* in = fopen("test_input.txt", "r");
    FILE* out = fopen("test_output.txt", "w");

    a =fgetc(in);
    fputc(a,out);
    putchar(a);

    printf("\nfine\n");

    fclose(in);
    fclose(out);
    return 0;
}
