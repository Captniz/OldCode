#include<stdio.h>

int main()
{
    int i,a;
    a=0;
    i=0;
    for ( i = 32; i < 255; i++)
    {
        printf("%d.%c\n",i,i);
        putchar('\n');
    }
    
    while (1)
    {
        printf("Cerca:");
        scanf("%d",&a);
        printf("%d.%c\n\n",a,a);
    }
    
    return 0;
}
