#include<stdio.h>
#include<string.h>

typedef char caratteri;
typedef int bool;

#define DIM 5

int main(){
    
    int i=0,j=0;
    caratteri v[DIM][80], s[80];
    bool flag=1;

    for ( i = 0; i < DIM; i++){
        printf("Stringa %d:",i+1);
        gets(v[i]);
    }

    printf("\nStringa da cercare:");
    gets(s);

    while(s != "\0"){
        //cerca stringhe
        for ( i = 0; i < DIM; i++){
            flag=1;
            if (strlen(s)==strlen(v[i])){
                
                for ( j = 0; s[j]!= '\0'; j++){
                    if (s[j]!=v[i][j]){
                        flag=0;
                    }
                }

                if (flag==1){
                    printf("%s trovata in posizione %d",s,i);
                    i=DIM+1;
                }
            }
            
        } 

        if (flag!=1){
            printf("%s non trovata",s);
        }

        printf("\nStringa da cercare:");
        gets(s);
    }

    return 0;
}
