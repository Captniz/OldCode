/*43> Data una stringa s contare quante cifre ci sono.*/
#include<string.h>
#include<stdio.h>
#define DIM 80
int main(){
	char s[DIM],i;
	int c;
	c=0;
	printf("inserisci una stringa: ");
	gets(s);
	fflush(stdin);
	for(i=0;i<strlen(s);i++){
		if(s[i]>=48 && s[i]<=57){
			c++;
		}
	}
	printf("n di cifre = %d",c);
	return 0;
}

