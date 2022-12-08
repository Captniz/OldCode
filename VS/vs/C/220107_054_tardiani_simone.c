//220107_054_tardiani_simone.c
/*54> data una stringa s caricata contestualmente (contenente solo lettere e spazi per ipotesi)
eliminare gli spazi e caricare in una seconda stringa s2
convertire s2 tutto in minuscole
ordinare s2 in modo crescente
visualizzare s2

es: s="vADo al maRe"
s2="vADoalmaRe"
s2="vadoalmare"
s2="aaadelmorv"*/

#include<stdio.h>

int main(){
    
    char s[80]="Bella ciao ", s2[80]; 
    int box,j,i,ctrSpazi,ctrciclo;
    i=0;
    j=0;
    ctrciclo=0;
    box=0;
    ctrSpazi=0;

    for ( i = 0; s[i] != '\0'; i++){
        if (s[i]!=' '){
            s2[i-ctrSpazi]=s[i];
        }else{
            ctrSpazi++;
        }
    }
    s2[i-ctrSpazi]='\0';

    for ( i = 0; s2[i] != '\0'; i++){
        if (s2[i]>=65 && s2[i]<=90){
            s2[i]=s2[i]+32;
        }
    }

    for ( i = ctrciclo; s2[i+1] != '\0'  ; i++){
        for ( j = i+1; s2[j]!='\0' ; j++){
            if (s2[i]>s2[j]){
                box=s2[i];
                s2[i]=s2[j];
                s2[j]=box;    
            }
        }
        ctrciclo++;
    }
    
    printf("%s",s2);

    return 0;
}
