#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 3

int main()
{   
    while (1)
    {
        printf("%d\n",((1<<rand()%9+0)*rand()%2+0));
    }
    
}
