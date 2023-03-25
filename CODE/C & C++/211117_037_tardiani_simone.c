#include<stdio.h>
#include<string.h>
#define DIM 80

void MyStrcpy(char s1[DIM], char s2[DIM]);

int main()
{
    int n;
    char s1[DIM],s2[DIM];

    MyStrcpy(s1,s2);
    puts(s1);
    return 0;
}

void MyStrcpy(char s1[DIM], char s2[DIM]) {

    int i;
    i=0;

    for ( i = 0; s2[i] != '\0'; i++)
    {
        s1[i]=s2[i];
    }
    s1[i]='\0';

}
