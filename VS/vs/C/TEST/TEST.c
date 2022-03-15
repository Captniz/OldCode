#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//! Indirizzo Puntatore => Puntatore => Indirizzo => Valore
//! & = Indirizzo
//! * = Valore

int funz (int *a, int b);

int main(){
    int a,b,v[10]={0,1,2,3,4,5,6,7,8,9};
    a=0;
    b=0;
    
    int *p_b;
    p_b = v;

    // &a = 45678456788
    funz(&a,b);
    printf("%d %d\n",a,b);
    printf("%d %d",*v,*p_b);
}

int funz(int *c, int d){
    //! Indirizzo Puntatore => Puntatore => Indirizzo => Valore
    //! & = Indirizzo
    //! * = Valore

    // c => &a = 45678456788 
    // *c => *(&a) => a 

    *c=*c+100;
    d++;

    return 0;
}