/*37> emulare la funzione strcpy char by char*/

#include<string.h>
#include<stdio.h>
#define DIM 80

void my_strcpy(char [],char []);

int main(){
	char s1[DIM],s2[DIM];
	printf("stringa: ");
	gets(s1);
	fflush(stdin);
	my_strcpy(s1,s2);
	return 0;
}

void my_strcpy(char s1[DIM], char s2[DIM]){
	int i;
	for(i=0;i<strlen(s1);i++){
		s2[i]=s1[i];
	}
	s2[i]='\0';
	puts(s2);
}
