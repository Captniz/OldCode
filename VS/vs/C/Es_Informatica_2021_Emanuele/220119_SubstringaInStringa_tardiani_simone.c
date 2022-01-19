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
    
    for ( i = 0; i < 50-2; i++){
        flag=1;
        if(s[i]==subs[0]){
            for ( j = 1; j < 3; j++){
                if (s[i+j]!=subs[j]){
                    flag=0;
                }
            }

            if (flag){
                for ( j = s[i+3]; j < 50; j++){
                    box=s[j-3];
                    s[j-3]=s[j];
                    s[j]=box;
                }
                i=51;
            }
        }    
    }
    
    puts(s);

    return 0;

}
