#include<stdio.h>
#include<string.h>

#define DIM 50
#define DIMHALF 3

int main(){

    char subs[DIMHALF+1];
    char s[DIM];
    int i,flag;
    i=0;
    flag=0;

    printf("Stringa:\n");
    gets(s);
    fflush(stdin);

    printf("SubStringa:\n");
    gets(subs);
    fflush(stdin);

    while((i < (strlen(s)-2)) || !flag){
        if (s[i]==subs[0]){
            if (s[i+1]==subs[1]){
                if (s[i+2]==subs[2]){
                    flag = i;
                }
            }
        }
        i++;
    }

    putchar('s');

    if(flag){
        for ( i = flag; i < strlen(s); i++){
            s[i]=s[i+3];
        }
        s[strlen(s)]='\0';

        printf("Stringa tagliata:\n");
        puts(s);
        
    }else{
        printf("Substringa non trovata\n");
    }
    
    


    return 0;
}
