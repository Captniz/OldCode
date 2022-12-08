#include<stdio.h>

int main()
{
    int n;
    n=0;

    printf("Numero?:");
    scanf("%d",&n);

    switch (n)
    {
    case 1:
        printf("lunedi");
        break;
    case 2:
        printf("martedi");
        break;
    case 3:
        printf("mercoledi");
        break;
    case 4:
        printf("giovedi");
        break;
    case 5:
        printf("venerdi");
        break;
    case 6:
        printf("sabato");
        break;
    case 7:
        printf("domenica");
        break;
    default:
        printf("il giorno di una settimana fa");
        break;
    }
    return 0;
}
