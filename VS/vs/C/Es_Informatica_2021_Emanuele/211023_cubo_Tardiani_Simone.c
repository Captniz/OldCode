//211023_cubo_Tardiani_Simone.c

#include <stdio.h>
int cubo(int a);
int main(){
    int n;
    printf("Numero: ");
    scanf("%d",&n);
    while(getchar()!='\n');
    printf("%d",cubo(n));
    return 0;
}

int cubo(int a){
    int cubo;
    cubo=a*a*a;
    return cubo;
}