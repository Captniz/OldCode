//211113_034_tardiani_simone.c
/*034> Inserire esternamente una stringa.
Restituire con una funzione le vocali.
--------
int vocali(char [])
*/


#include<stdio.h>
#include<string.h>

int vocali(char []);

int main()
{
    char s[80];

    printf("Stringa?:");
    gets(s);
    fflush(stdin);
    printf("\nCi sono %d vocali",vocali(&s[0]));
    return 0;
}
 
int vocali (char s[]){

    int i,c;
    i=0;
    c=0;

    for(i=0; i<strlen(s); i++){
        switch (s[i])
        {
        case 'a':
            c++;
            break;
        
        case 'e':
            c++;
            break;
        
        case 'i':
            c++;
            break;
        
        case 'o':
            c++;
            break;
        
        case 'u':
            c++;
            break;
        
        case 'A':
            c++;
            break;
        
        case 'E':
            c++;
            break;
        
        case 'I':
            c++;
            break;
        
        case 'O':
            c++;
            break;
        
        case 'U':
            c++;
            break;
            
        default:
            break;
        }
    }
    return c;
} 