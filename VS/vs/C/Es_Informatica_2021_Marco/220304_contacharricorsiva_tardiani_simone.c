#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define DIM 80

int count_char(char *str, char c);

int main(){
    int c;
    char str[DIM];

    printf("Stringa:");
    gets(str);
    fflush(stdin);

    printf("\nChar:");
    c = getchar();
    fflush(stdin);

    printf("Char %c in stringa %s: %d",c,str,count_char(str, c));

    return 0;
}

int count_char(char *str, char c){

    if (*str == '\0'){
        return 0;
    }
    
    if (*str ==  c){
        str=str+1;
        return 1+count_char(str, c);
    }else{
        str=str+1;
        return count_char(str, c);
    }
    
}