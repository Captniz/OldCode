#include<stdio.h>
#define DIM 10

int main(){
	
	int n,i;
	n=0;
	i=0;
	char s[DIM];
	
	for(i=0;i<DIM;i++){
		s[i]=0;
	}
	
	printf("Stringa di 10 char:");
	scanf("%s",s);
	fflush(stdin);
	
	do{
		printf("Numero:");
		scanf("%d",&n);
		fflush(stdin);
	}while(n>=DIM);
	
	n--;
	for(i=n;i<DIM;i++){
		printf("%c",s[i]);
	}
	
	return 0;
}
