//210917_001_Tardiani_Simone.c
//calcola l'A del rettangolo
#include <stdio.h>
int main()
{
    int b,h,A;
    
    printf("I byte di un int sono: %d\n",sizeof(b));
    
    printf("Base rettangolo?: ");
    scanf("%d",&b);

    fflush(stdin);

    printf("Altezza rettangolo?: ");
    scanf("%d",&h);

    A=b*h;

    printf("L'Area del rettangolo e': %d",A);    
    
    return 0;
}