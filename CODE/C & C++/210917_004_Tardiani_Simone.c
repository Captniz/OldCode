//210717_004_Tardiani_Simone.c
/*Dato un numero, contare quanti divisori pari e quanti divisori dispari ha.
Esempio: 16
Dispari: 1 			1
Pari: 2 4 8 16 		4*/
#include<stdio.h>

int main()
{
    int n;
    int DivisoriPari=0;
    int DivisoriDispari=0;

    printf("Numero?:");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {

        if (n%i==0)
        {

            if (i%2==0)
            {
                printf("\n%d e' pari",i);
                DivisoriPari++;
            }else
            {
                printf("\n%d e' dispari",i);
                DivisoriDispari++;
            }

        }

    }

    printf("\nDivisori pari:%d",DivisoriPari);
    printf("\nDivisori dispari:%d",DivisoriDispari);

    return 0;
}

