//211112_032_tardiani_simone.c
/*32> data una stringa s1, copiare in una stringa s2 mettendo le vocali alla fine (sia MAIUSCOLE che minuscole! - ovviamente la lunghezza di s2 è uguale a quella di s1)
es: "Mio nonno" -> "M nnniooo"*/

#include<stdio.h>
#include<string.h>
#define DIM 80

int main()
{
    int i=0;
    char s1[DIM] = "";
    char s2[DIM] = "";
    char voc[DIM] = "";
    char cons[DIM] = "";
    int vocc=0;
    int consc=0;

   for ( i = 0; s1[i]!='\0'; i++)
    {
        if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I'|| s1[i] == 'O' || s1[i] == 'U' ){
            voc[vocc]=s1[i];
            vocc++;
        }else{
            cons[consc]=s1[i];
            consc++;
        }
    }
    strcpy(s2,cons);
    strcat(s2,voc);

    puts(s2);

    return 0;
}

