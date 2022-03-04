#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 80

int main(){

    int i,j,box;
    i=0;
    j=0;
    box=0;
    char a[80], *p_a;

    printf("Str:");
    gets(a);
    fflush(stdin);
    puts(a);

    while(a[i] != '\0'){
        if (a[i]>=48 && a[i]<=57){
            for ( j = i+1; a[j]!='\0'; j++){
                box=a[j];
                a[j]=a[j-1];
                a[j-1]=box;
            }
            a[strlen(a)-1]='\0';
        }else{
            i++;
        }
    };

    p_a = malloc(strlen(a) * sizeof(char));

    for ( i = 0; i < (strlen(a)+1); i++){
        p_a[i]=a[i];
    }
    
    puts(p_a);

    return 0;
}
