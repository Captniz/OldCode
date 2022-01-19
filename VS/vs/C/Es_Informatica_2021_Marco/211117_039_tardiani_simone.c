#include<stdio.h>
#include<string.h>
#define DIM 80

int MyStrcmp(char s1[DIM], char s2[DIM]);

int main()
{
    char s1[DIM],s2[DIM];

    printf("%d",MyStrcmp(s1,s2));
    return 0;
}

int MyStrcmp(char s1[DIM], char s2[DIM]) {

    int i,flag,len;
    i=0;
    len=0;
    flag=0;

    if (strlen(s1)<strlen(s2)){
        return -1;
    }else if (strlen(s1)>strlen(s2)){
        return 1;      
    }
    
    for ( i = 0; i <= strlen(s1); i++){
        if (s1[i]==s2[i]){
            flag=0;
        }else if (s1[i]<s2[i]){
            flag=-1;
            break;
        }else{
            flag=1;
            break;
        }
    }
    
    return flag;
}
