//210922_Es_array_B.c
//Stampare la somma dei numeri di un array

//loading contestuale
#include<stdio.h>

int main(){

 	int v[]={1,2,3,4,5,6,7,8,9,10},i=0,s=0;
	srand(time(NULL));

    for(i=0; (i<sizeof(v)/sizeof(int)); i++){
		printf("%d ",v[i]);
		s+=v[i];
	}
	printf("\n\n%d ", s);
    return 0;
}