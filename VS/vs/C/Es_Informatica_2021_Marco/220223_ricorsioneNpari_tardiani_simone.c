#include<stdio.h>

int Npari(int a,int i,int sum);

int main(){
    int a=0;

    printf("Numero:");
    scanf("%d",&a);
    printf("%d\n",Npari(a,0,0));

    return 0;
}

int Npari(int a,int i,int sum){
    i++;

    if ( i%2==0){
        a--;
        sum+=i;
    }

    if(a==0){
        return sum;
    }else{
        return Npari(a,i,sum);
    }
}