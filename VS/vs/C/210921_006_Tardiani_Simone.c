//210921_006_Tardiani_Simone.c
/*Inserire dei numeri a piacere (0 to esc).
Visualizzare il primo max e il secondo max*/
#include<stdio.h>

int main()
{
    int n,max,max2;
    n=0;
    max=0;
    max2=0;

    printf("Numero?:");
    scanf("%d",&max);
    fflush(stdin);

    printf("Numero?:");
    scanf("%d",&max2);
    fflush(stdin);

    do
    {
        if (n>max)
        {
            max2=max;
            max=n;
        }else{
            if (n>max2)
            {
                max2=n;
            }
        }

        printf("Numero?:");
        scanf("%d",&n);

    }while(n!=0);
    
    printf("%d ",max);
    printf("%d",max2);

    return 0;
}
