//210918_005_Tardiani_Simone.c
/*Dato un numero, contare quanti suoi divisori sono potenze di 2.

Esempio: 16
2 4 8 16 		4
Esempio: 25
(nessuno) 		0*/
#include<stdio.h>
#define Potenza 2

int main()
{
    unsigned int n,c,i,k;
    c=0;

    printf("Numero?:");
    scanf("%d",&n);
    fflush(stdin);

    for ( i = 1; i <= n; i++)
    {
        if (n%i==0)
        {
            k=1;
            while (k<=i)
            {
                k=k*Potenza;
                if (k==i)
                {
                    printf("%d ",k);
                    c++;
                }
            }
        }
    }

    printf("\nSomma dei divisori potenze di 2: %d",c);
    return 0;
}