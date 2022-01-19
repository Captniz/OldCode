#include <stdio.h>

int main(){

    int i;
    float n;
    i=0;
    n=0;

    printf("Numero:");
    scanf("%f",&n);
    while(getchar()!='\n');

    if(n<1){ 
        for(i=0;n<1;i--){ 
            n=n*10;
        }
    }else{

        for(i=0;n>10 || n<-10;++i){
            n=n/10;
        }
    }

    if(n<=5 || n<-5){
        i++;
    }

    printf("N. scientfica: %f*10^%d\n",n,i);
    printf("Ordine di grandezza: %d",i);
}