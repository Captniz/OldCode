#include<stdio.h>
#include<string.h>
#define DIM 80

void MyStrncpy(char s1[DIM], char s2[DIM], int n);

int main()
{
    int n;
    char s1[DIM],s2[DIM];

    MyStrncpy(s1,s2, n);
    puts(s1);
    return 0;
}

void MyStrncpy(char s1[DIM], char s2[DIM], int n) {

    int i;
    i=0;

    for ( i = 0; i < n; i++)
    {
        s1[i]=s2[i];
    }
    s1[n]='\0';

}
