#include<stdio.h>

int main(){
    int n,i,som,j;
    n=0;
    i=0;
    som=1;
    j=0;

    do{
        printf("dim. array:");
        scanf("%d", &n);
        while(getchar()!='\n');
    } while (n<=0);
    int v[n];
    for ( i = 0; i < n; i++){
        printf("Numero?:");
        scanf("%d",&v[i]);
    }
    for ( i = 0; som != 0; i++){
        som=0;
        for ( j = 0; j < n; j++){
            if (v[j]!=0){
                printf("*");
                v[j]--;
                som++;
            }else{
                printf(" ");
            }       
        }
        printf("\n");
    }
    return 0;
}