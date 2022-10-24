/*1> calcola l'area del rettangolo*/
#include <stdio.h>
int main()
{
    int b,h,area;
    printf("I byte di un int sono: %d\n",sizeof(b));
	printf("Base rettangolo?: ");
    scanf("%d",&b);
    fflush(stdin);
    printf("Altezza rettangolo?: ");
    scanf("%d",&h);
    fflush(stdin);
    area=b*h;
    printf("L'Area del rettangolo e': %d",area);    
    return 0;
}
