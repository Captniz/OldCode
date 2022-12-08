//211103_Funzioni_e_address_tardiani_simone.c
//scrivere una funzione che stampi tutti i valori pari da un num N inserito in input a 0

#include<stdio.h>

void InNum(int *a);
void PrintEven(int a);

int main()
{
    int n=0;
    InNum(&n);
    PrintEven(n);
    getchar();
    return 0;
}

void InNum(int *a){
    do{
    printf("Numero:");
    scanf("%d",a);
    }while(*a<=0);
}

void PrintEven(int a){
    int i=0;

    for(i=0;i<=a;i++){

        if(i%2==0){
            printf("%d ",i);
        }
    }
}