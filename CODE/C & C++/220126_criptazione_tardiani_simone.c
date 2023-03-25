#include<stdio.h>
#include<string.h>

int main(){
    
    char s[80];
    int i,c;
    i=0;
    c=0;

    for ( i = 0; i < 80; i++){
        s[i]='\0';
    }

    printf("Stringa:\n");
    gets(s);

    printf("Chiave:");
    scanf("%d",&c);

    c=c-(26*(c/26));

    for ( i = 0; s[i] != '\0'; i++){
        //97
        s[i]=s[i]+c;

        if (s[i]>122){
            s[i]=s[i]-26;
        }
    }
    
    puts(s);

    return 0;
}
