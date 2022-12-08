#include<stdio.h>
#include<string.h>

void assegnazione(int *a);
void som(int *a, int b);
void sot(int *a, int b);
void per(int *a, int b);
void div(int *a, int b);

int main(){
    
    int a,b;
    char op;

    assegnazione(&a);
    assegnazione(&b);
    op=getchar();

    switch (op){
    case '+':
        som(&a,b);
        printf("Risultato:%d",a);
        break;
    
    case '-':
        sot(&a,b);
        printf("Risultato:%d",a);
        break;

    case '*':
        per(&a,b);
        printf("Risultato:%d",a);
        break;

    case '/':
        div(&a,b);
        printf("Risultato:%d",a);
        break;

    default:
        printf("Undefined");
        break;
    }
    return 0;
}

void som(int *a, int b){
    *a=*a+b;
}
void sot(int *a, int b){
    *a=*a-b;
}
void per(int *a, int b){
    *a=*a*b;
}
void div(int *a, int b){
    *a=*a/b;
}
void assegnazione(int *a){
    printf("\nNumero?:");
    scanf("%d",a);
    fflush(stdin);
}