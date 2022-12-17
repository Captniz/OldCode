/*28&gt; Emulare la funzione:
strcpy(s1, s2)   Copia s2 in s1
visualizzare le 2 stringhe.*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#define DIM 80
void MyStrcpy(char [], char []);
int main(){
    char s1[DIM],s2[DIM];
    printf("inserire una stringa: ");
    gets(s2);
    fflush(stdin);
    MyStrcpy(s1,s2);
    puts(s1);
    return 0;
}
void MyStrcpy(char s1[DIM], char s2[DIM]) {
    int i;
    for(i=0;i&lt;strlen(s2);i++){
        s1[i]=s2[i];
    }
    s1[i]='\0';
}
