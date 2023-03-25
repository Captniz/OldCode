#include<stdio.h>

void rettangolo(int row, int col);

int main(){

    rettangolo(1,1);
    return 0;
}

void rettangolo(int row, int col){

    int i,j;
    i=0;
    j=0;

    for ( i = 0; i < col; i++){
        putchar('*');
    }

    putchar('\n');

    for ( i = 0; i < row -2; i++){
        putchar('*');
        for ( j = 0; j < col-2; j++){
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    
    for ( i = 0; i < col; i++){
        putchar('*');
    }
}