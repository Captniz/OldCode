/*1> Scrivere solo la funzione:
<void maiuscolo(char [ ]);<
che trasforma tutte le minuscole in maiuscolo.
(vietato usare la libreria <string.h>)
(ipotizzando una stringa di tutte minuscole - 2 punti)
es: sonostanco ---> SONOSTANCO
(ipotizzando una stringa qualsiasi - 3 p unti)
es: Oggi67 SOno *!Sta NCo -> OGGI67 SONO *!STA NCO
*/

#include<stdio.h>

void maiuscolo(char c[80]);

void maiuscolo(char c[80]){

    int i=0;

    for ( i = 0; c[i]!='\0'; i++){
        if (c[i]>=97 && c[i]<=122){
            c[i]=c[i]-32;
        }
    }
}