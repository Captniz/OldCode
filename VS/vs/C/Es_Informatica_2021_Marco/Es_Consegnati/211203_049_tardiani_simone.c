#include<stdio.h>
#include<string.h>

#define DIM 5
#define L 80

int confronta(char s[DIM][L]);

int main(){

    int i=0;
    char s[DIM][L];

    for ( i = 0; i < DIM; i++){
        printf("Stringa %d:",i+1);
        gets(s[i]);
    }

    printf("%d",confronta(s));

}

int confronta(char s[DIM][L]){

    int i,j,ctr,tot;
    i=0;
    j=0;
    ctr=1;
    tot=0;

    for ( i = 0; i < DIM; i++){

        if (strcmp(s[i],"\0")!=0){

            for (j = i+1; j < DIM; j++){
                if (strcmp(s[i],s[j])==0){
                    ctr++;
                    strcpy(s[j],"\0");
                }
            } 

            if (ctr != 1){
                tot=tot+ctr;
            }
            
            ctr=1;
        }
    }

    return tot;
}