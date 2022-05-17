//210717_003_Tardiani_Simone.c
/*Dati due numeri "m" e "n", visualizzare, contare e sommare i numeri che sono divisori di entrambi.

Esempio con m=20, n=30 
1 2 5 10 conteggio 4, somma 18*/
#include<stdio.h>

int main()
{
	//unsigned serve ad avere solo numeri positivi e in quantita' superiore
    unsigned int m,n,c,s,i;
    c=0;
    s=0;
    
    printf("1 Numero:");
    scanf("%d",&n);
    fflush(stdin);

    printf("2 Numero:");
    scanf("%d",&m);
    fflush(stdin);

    for (i=1;(i<=n) && (i<=m); i++) //risolvere invece col minimo tra m e n
    {
        if ((n%i==0) && (m%i==0))
        {
            printf("%d ",i);
            c++;  //c=c+1
            s+=i; //s=s+i
        }
    }
    
    printf("\nSomma:%d",s);
    printf("\nConteggio:%d",c);
    return 0;
}