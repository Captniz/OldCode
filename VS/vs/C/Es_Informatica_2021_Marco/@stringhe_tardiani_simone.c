#include<stdio.h>
#include<string.h>

int main()
{
    int i=0;
    char s[] = "Io pippo";
    char ss[] = " Tu topolino";
    char voc[80];
    int vocc =0;
    int consc =0;
    char cons[80];
    char s1[80];
    //----- inverti stringa
    for ( i = 1; i <= strlen(s) ; i++){
        s1[i-1]=s[strlen(s)-i];
    }

    s1[strlen(s)]='\0';
    puts(s1);
    printf("\n"); 
    //----- copia stringa
    strcpy(s1,s);
    puts(s1);
    printf("\n");
    //----- concatena stringa
    strcpy(s1,s);
    for ( i = 0; i <= strlen(ss); i++){
        s1[strlen(s)+i]=ss[i];
    }
    s1[strlen(s)+strlen(ss)]='\0';
    puts(s1); 
    //----- separa vocali cons
    for ( i = 0; i <= strlen(s); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I'|| s[i] == 'O' || s[i] == 'U' ){
            voc[vocc]=s[i];
            vocc++;
        }else
        {
            cons[consc]=s[i];
            consc++;
        }
    }
    printf("\n");
    cons[consc]='\0';
    puts(cons);
    voc[vocc]='\0';
    puts(voc);

    return 0;
}