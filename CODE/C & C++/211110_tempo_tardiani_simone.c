#include<stdio.h>

int tempo();

int main(){
    if (tempo()>tempo()){
        printf("Il primo orario è maggiore del secondo");
    }else{
        printf("Il secondo orario è maggiore del primo");
    }
    return 0;
}

int tempo(){
    int o,m,s;
    o=0;
    m=0;
    s=0;

    do{
    printf("ore?:");
    scanf("%d",&o);
    fflush(stdin);
    }while(o<0);

    do{
    printf("minuti?:");
    scanf("%d",&m);
    fflush(stdin);
    }while(m<0);

    do{
    printf("secondi?:");
    scanf("%d",&s);
    fflush(stdin);
    }while(s<0);

    s=s+(m*60)+((o*60)*60);

    printf("Secondi totali:%d\n\n",s);
    return s;
}