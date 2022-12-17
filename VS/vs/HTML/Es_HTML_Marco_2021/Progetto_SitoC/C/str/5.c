/*31&gt; emulare la funzione:
strlen(s)     Resituisce la lunghezza di s
--------------
l=lunghezza(s) */
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#define DIM 80
int MyStrlen(char []);
int main()
{
    char s1[DIM];
    printf("inserire una stringa: ");
    gets(s1);
    fflush(stdin);
    printf("lunghezza: %d",MyStrlen(s1));
    return 0;
}
int MyStrlen(char s1[DIM]){
    int i;
    i=0;
    while(s1[i]!='\0'){
        i++;
    }
    return i;
}
