#include<stdio.h>
#include<string.h>

int main(){
    
    char s[80];
    int ctr,i,c;
    i=0;
    c=0;
    ctr=0;

    for ( i = 0; i < 80; i++){
        s[i]='\0';
    }
    

    printf("Stringa:");
    gets(s);

    printf("Chiave:");
    scanf("%d",&c);

    for ( i = 0; s[i] != '\0'; i++){
        //97
        ctr=(s[i]-96+c)%26;
        s[i]=s[i]+c-(26*ctr);
    }
    
    puts(s);

    return 0;
}
