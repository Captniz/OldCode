#include<stdio.h>
#include<string.h>

int main(){

    char subs[3];
    char s[50];
    int i,j;
    j=0;
    i=0;
    int flag = 1;
    int box=0;

    printf("Stringa:\n");
    gets(s);

    printf("SubStringa:\n");
    gets(subs);
    
    for ( i = 0; s[i] != '\0'; i++){
        flag=1;
        while (flag && j<strlen(subs)){
            if (s[i+j]!=subs[j]){
                flag=0;
            }
            j++;
        }
        
        if (flag){
            // for ( j = i+strlen(subs); s[j]!='\0' ; j++){
            //     s[j-strlen(subs)]=s[j];
            // }  
            // s[j-strlen(subs)]='\0';
            // puts(s);
            printf("pos:%d\n",i);
            return 0;
        }
    }
    
    printf("stringa non trovata\n");
    return 0;
}
