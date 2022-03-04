/*Consegna:
carica una str di 15 char random tra 'a' e 'z', poi conta quante sono le seq di char uguali
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define DIM 16

void randomchar(char v[DIM]);
int contaseq(char v[DIM]);

int main(){
                 //debug:
    char str[DIM]/*="aabbccccddsnpaa\0"*/;
    srand(time(NULL));

    randomchar(str);
    printf("%s : %d",str,contaseq(str));

    return 0;
}

void randomchar(char v[DIM]){

    int i=0;

    for ( i = 0; i < DIM; i++){
        v[i]=rand()%26+97;
    }

    v[DIM-1]='\0';
}

int contaseq(char v[DIM]){

    int i,j,ctr,flag;
    j=0;
    i=1;
    ctr=0;
    flag=1;

    while (i<DIM){
        flag=1;
        if (v[i-1]==v[i]){
            ctr++;
            while (flag){
                if (v[i+1]!=v[i]){
                    flag=0;
                }
                i++;
            }
        }
        i++;
    }

    return ctr;
    
}