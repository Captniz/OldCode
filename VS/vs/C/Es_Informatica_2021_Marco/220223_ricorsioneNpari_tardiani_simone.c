#include<stdio.h>

int Npari(int a);

int main(){
    int a=0;

    printf("Numero:");
    scanf("%d",&a);
    printf("%d\n",Npari(a));

    return 0;
}

int Npari(int a){
    if(a==0){
        return a;
    }else{
        return a*2+Npari(a-1);
    }
}