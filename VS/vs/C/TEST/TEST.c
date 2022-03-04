#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int main(){
    
    char a[80], *ar;

    printf("a:");
    gets(a);

    ar = (char *) malloc((strlen(a)+1) * sizeof(char));

    puts(a);

    return 0;
}
*/

int main(){
    
    char *ar[80];

    printf("a:");
    gets(ar);

    ar = (char *) malloc((strlen(ar)+1) * sizeof(char));

    puts(a);
    printf("%d\n",sizeof(ar));
    return 0;
}
