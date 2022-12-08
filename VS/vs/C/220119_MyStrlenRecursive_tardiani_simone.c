#include<stdio.h>
#include<string.h>

int Mystrlen(char s[80], int ctr);

int main(){
    
    char s[80];
    printf("Stringa:");
    gets(s);

    printf("\nLunghezza:%d",Mystrlen(s, 0));

    return 0;
}

 int Mystrlen(char s[80], int ctr){
    
    if(s[ctr]=='\0'){
        return ctr;
    }else{
        ctr++;
        Mystrlen(s,ctr);
    }
} 