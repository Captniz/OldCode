/*42> emulare la funzione strlen char by char*/
#include<stdio.h>
#include<string.h>
#define DIM 80
int my_strlen(char []);
int main()
{
	char s1[DIM];
	printf("inserire stringa: ");
	gets(s1);
	fflush(stdin);
	printf("la lunghezza della stringa inserita e': %d",my_strlen(s1));
	return 0;
}
int my_strlen(char s1[DIM]){
	int i;
	i=0;
	while(s1[i]!='\0'){
		i++;
	}
	return i;
}
