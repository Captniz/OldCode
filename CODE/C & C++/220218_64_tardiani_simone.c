#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
#define L 80

void spacing();

int main(){
    char q = '\0';

    while (1){

        printf("0 -> Exit\nn -> ordina le stringhe per nome in modo crescente\nd -> ordina le stringhe per lunghezza in modo crescente \nv -> ordina le stringhe contenenti piu' vocali in modo crescente \nOpt:");
        q=getchar();
        fflush(stdin);

        switch (q){
        case '0':
            return 0;
            break;
        
        case 'n':
            
            break;

        case 'd':
            
            break;

        case 'v':
            
            break;

        default:
            spacing();
            printf("!!Err:Opzione errata!!\n\n");
            break;
        }
    }
    

    return 0;
}

void spacing(){
    int i=0;

    for ( i = 0; i < 50; i++){
        putchar('\n');
    }
    
}

