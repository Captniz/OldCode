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

    int *p_v, v[10]={0,1,2,3,4,5,6,7,8,9};
    p_v=v;
    printf("%d\n",*p_v);
    return 0;
}
