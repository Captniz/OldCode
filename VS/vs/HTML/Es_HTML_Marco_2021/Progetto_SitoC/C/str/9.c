/*35> Scrivere una funzione che calcoli una qualunque potenza maggiore o uguale a zero.
long int potenza(int , int);
*/
#include<stdio.h>
long int potenza(int, int);
int main(){
	int a,b;
	printf("inserire la base: ");
	scanf("%d",&a);
	fflush(stdin);
	do{
		printf("inserire l'esponente: ");
		scanf("%d",&b);
		fflush(stdin);
	}while(b<0);
	if(a!=0 && b!=0){
		printf("la potenza e': %li",potenza(a,b));
	}else{
		printf("non definito");
	}
	return 0;
}
long int potenza(int a, int b){
	long int r;
	int i;
	r=1;
	for(i=0;i<b;i++){
		r=r*a;
	}
	return r;
}
